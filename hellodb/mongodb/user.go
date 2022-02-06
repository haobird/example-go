package mongodb

import (
	"context"
	"fmt"
	"hellodb/user"
	"time"

	"github.com/davecgh/go-spew/spew"
	"github.com/mainflux/mainflux/pkg/errors"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

const (
	errInvalid    = "invalid_text_representation"
	errTruncation = "string_data_right_truncation"
	errDuplicate  = "unique_violation"
)

var (
	errSaveUserDB       = errors.New("Save user to DB failed")
	errUpdateDB         = errors.New("Update user email to DB failed")
	errSelectDb         = errors.New("Select from DB failed")
	errUpdateUserDB     = errors.New("Update user metadata to DB failed")
	errRetrieveDB       = errors.New("Retreiving from DB failed")
	errUpdatePasswordDB = errors.New("Update password to DB failed")
	errMarshal          = errors.New("Failed to marshal metadata")
	errUnmarshal        = errors.New("Failed to unmarshal metadata")
)

const (
	userCollection string = "user"
)

var _ user.UserRepository = (*userRepository)(nil)

type userRepository struct {
	db *mongo.Database
}

func NewUserRepository(db *mongo.Database) user.UserRepository {
	return &userRepository{
		db: db,
	}
}

func (ur userRepository) Save(ctx context.Context, u user.User) (string, error) {
	coll := ur.db.Collection(userCollection)
	fmt.Println("id:", u.ID)

	var err error
	dbu, err := toDBUser(u)
	if err != nil {
		return "", errors.Wrap(errSaveUserDB, err)
	}

	if _, err := coll.InsertOne(ctx, dbu); err != nil {
		return "", err
	}
	return u.ID, nil
}

func (ur userRepository) Update(ctx context.Context, id string, u user.User) error {
	coll := ur.db.Collection(userCollection)

	id = u.ID
	fmt.Println("id:", u.ID)

	dbu, err := toDBUser(u)
	if err != nil {
		return errors.Wrap(errSaveUserDB, err)
	}

	opts := options.FindOneAndUpdate().SetUpsert(true)
	filter := bson.M{"id": id}

	update := bson.M{"$set": dbu}

	var updatedDocument bson.M
	err = coll.FindOneAndUpdate(context.Background(), filter, update, opts).Decode(&updatedDocument)
	fmt.Printf("id: %s, err: %s \n", id, err)
	if err != nil {
		if err == mongo.ErrNoDocuments {
			return nil
		}
		return err
	}

	return nil
}

func (ur userRepository) RetrievePage(ctx context.Context, pm user.PageMetadata, clause map[string]interface{}) (user.UserPage, error) {
	coll := ur.db.Collection(userCollection)

	offset := pm.Offset
	limit := pm.Limit
	order := pm.Order
	dir := pm.Dir

	findOptions := options.Find()
	findOptions.SetSkip(offset)
	findOptions.SetLimit(pm.Limit)
	oq := getOrderQuery(order)
	dq := getDirQuery(dir)
	findOptions.SetSort(bson.M{oq: dq})

	filter := createFilterQuery(clause)

	cur, err := coll.Find(ctx, filter, findOptions)
	if err != nil {
		return user.UserPage{}, err
	}

	defer cur.Close(ctx)
	var items []user.User
	for cur.Next(ctx) {
		dbusr := dbUser{}
		if err := cur.Decode(&dbusr); err != nil {
			return user.UserPage{}, errors.Wrap(errSelectDb, err)
		}
		u, err := toUser(dbusr)
		if err != nil {
			return user.UserPage{}, err
		}
		items = append(items, u)
	}

	if err := cur.Err(); err != nil {
		return user.UserPage{}, err
	}

	total, err := coll.CountDocuments(ctx, filter)
	if err != nil {
		return user.UserPage{}, errors.Wrap(errSelectDb, err)
	}

	page := user.UserPage{
		Users: items,
		PageMetadata: user.PageMetadata{
			Total:  total,
			Offset: offset,
			Limit:  limit,
		},
	}

	return page, nil

}

type dbUser struct {
	ID         string      `bson:"id"`
	Email      string      `bson:"email"`
	Password   string      `bson:"password"`
	Metadata   interface{} `bson:"metadata"`
	CreateTime time.Time   `bson:"create_time,omitempty"` // 添加时间
}

func toDBUser(u user.User) (dbUser, error) {
	data := u.Metadata
	return dbUser{
		ID:         u.ID,
		Email:      u.Email,
		Password:   u.Password,
		Metadata:   data,
		CreateTime: time.Now(),
	}, nil

}

func toUser(dbu dbUser) (user.User, error) {
	var metadata map[string]interface{}

	spew.Dump(dbu)

	if dbu.Metadata != nil {
		bsonBytes, _ := bson.Marshal(dbu.Metadata)
		if err := bson.Unmarshal(bsonBytes, &metadata); err != nil {
			return user.User{}, errors.Wrap(errUnmarshal, err)
		}
	}

	return user.User{
		ID:         dbu.ID,
		Email:      dbu.Email,
		Password:   dbu.Password,
		Metadata:   metadata,
		CreateTime: dbu.CreateTime,
	}, nil
}

func createFilterQuery(conditions map[string]interface{}) interface{} {
	filter := bson.M{}
	if val, ok := conditions["email"]; ok {
		// temp := bson.M{"email": }
		filter["email"] = bson.D{{"$regex", val}}
	}

	if val, ok := conditions["ids"]; ok {
		filter["id"] = bson.M{"$in": val}
	}

	if val, ok := conditions["total_length"]; ok {
		filter["metadata.total_length"] = val
	}

	if val, ok := conditions["startTime"]; ok {
		t, _ := time.Parse(layoutISO, val.(string))
		filter["create_time"] = bson.D{
			{"$gte", t},
		}
	}

	if val, ok := conditions["endTime"]; ok {
		filter["create_time"] = bson.D{
			{"$lte", val},
		}
	}

	val1, ok1 := conditions["startTime"]
	val2, ok2 := conditions["endTime"]
	if ok1 && ok2 {
		filter["create_time"] = bson.D{
			{"$gte", val1},
			{"$lte", val2},
		}
	}
	spew.Dump(filter)

	return filter
}
