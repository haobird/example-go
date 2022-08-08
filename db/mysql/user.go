package mysql

import (
	"context"
	"encoding/json"
	"fmt"
	"hellodb/user"
	"strings"

	"github.com/VividCortex/mysqlerr"
	"github.com/go-sql-driver/mysql"
	"github.com/imdario/mergo"

	"github.com/mainflux/mainflux/pkg/errors"
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

var _ user.UserRepository = (*userRepository)(nil)

type userRepository struct {
	db Database
}

func NewUserRepository(db Database) user.UserRepository {
	return &userRepository{
		db: db,
	}
}

func (ur userRepository) Save(ctx context.Context, u user.User) (user.User, error) {
	q := `INSERT INTO users (email, password, id, metadata) VALUES (:email, :password, :id, :metadata)`
	if u.ID == "" || u.Email == "" {
		return u, user.ErrMalformedEntity
	}

	dbu, err := toDBUser(u)
	if err != nil {
		return u, errors.Wrap(errSaveUserDB, err)
	}

	ret, err := ur.db.NamedExecContext(ctx, q, dbu)
	if err != nil {
		// make sure err is a mysql.MySQLError.
		errMySQL, ok := err.(*mysql.MySQLError)
		if ok {
			switch errMySQL.Number {
			case mysqlerr.ER_DUP_ENTRY: // Error 1062: Duplicate entry '%s' for key %d
				return u, errors.Wrap(user.ErrConflict, err)
			}
		}
		return u, errors.Wrap(errSaveUserDB, err)
	}

	theID, err := ret.LastInsertId() // 新插入数据的id
	if err != nil {
		fmt.Printf("get lastinsert ID failed, err:%v\n", err)
		return u, err
	}
	// 记录入库id
	fmt.Printf("insert success, the id is %d.\n", theID)

	// id := dbu.ID
	return u, nil
}

func (ur userRepository) SaveMany(ctx context.Context, us ...user.User) ([]user.User, error) {
	return nil, nil
}

func (ur userRepository) Update(ctx context.Context, u user.User) error {
	return nil
}

func (ur userRepository) RetrieveAll(ctx context.Context, clause map[string]interface{}) ([]user.User, error) {
	return nil, nil
}

func (ur userRepository) RetrieveByID(ctx context.Context, id string) (user.User, error) {
	return user.User{}, nil
}

func (ur userRepository) RetrieveAllByIDs(ctx context.Context, ids []string) ([]user.User, error) {
	return nil, nil
}

func (ur userRepository) RetrievePage(ctx context.Context, pm user.PageMetadata, conditions map[string]interface{}) (user.UserPage, error) {
	var query []string
	var emq string
	limit := pm.Limit
	offset := pm.Offset

	cs, cp, err := createConditionQuery("", conditions)
	fmt.Println("err:", err)
	if cs != "" {
		query = append(query, cs)
	}

	if len(query) > 0 {
		emq = fmt.Sprintf(" WHERE %s", strings.Join(query, " AND "))
	}

	q := fmt.Sprintf(`SELECT id, email, metadata FROM users %s ORDER BY email LIMIT :limit OFFSET :offset;`, emq)
	params := map[string]interface{}{
		"limit":  limit,
		"offset": offset,
	}

	mergo.Merge(&params, cp)

	rows, err := ur.db.NamedQueryContext(ctx, q, params)
	if err != nil {
		return user.UserPage{}, errors.Wrap(errSelectDb, err)
	}
	defer rows.Close()

	var items []user.User
	for rows.Next() {
		dbusr := dbUser{}
		if err := rows.StructScan(&dbusr); err != nil {
			return user.UserPage{}, errors.Wrap(errSelectDb, err)
		}

		u, err := toUser(dbusr)
		if err != nil {
			return user.UserPage{}, err
		}

		items = append(items, u)
	}

	cq := fmt.Sprintf(`SELECT COUNT(*) FROM users %s;`, emq)

	total, err := total(ctx, ur.db, cq, params)

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

func (ur userRepository) Remove(ctx context.Context, clause map[string]interface{}) (int64, error) {
	return 0, nil
}

func (ur userRepository) RemoveByID(ctx context.Context, id string) error {
	return nil
}

func page(ctx context.Context, db Database, query string, params interface{}) ([]user.User, error) {
	var items []user.User
	rows, err := db.NamedQueryContext(ctx, query, params)
	if err != nil {
		return items, err
	}
	defer rows.Close()

	for rows.Next() {
		dbusr := dbUser{}
		if err := rows.StructScan(&dbusr); err != nil {
			return items, err
		}

		u, err := toUser(dbusr)
		if err != nil {
			return items, err
		}

		items = append(items, u)
	}
	return items, nil
}

func total(ctx context.Context, db Database, query string, params interface{}) (int64, error) {
	rows, err := db.NamedQueryContext(ctx, query, params)
	if err != nil {
		return 0, err
	}
	defer rows.Close()

	total := int64(0)
	if rows.Next() {
		if err := rows.Scan(&total); err != nil {
			return 0, err
		}
	}
	return total, nil
}

type dbUser struct {
	ID       string `db:"id"`
	Email    string `db:"email"`
	Password string `db:"password"`
	Metadata []byte `db:"metadata"`
}

func toDBUser(u user.User) (dbUser, error) {
	data := []byte("{}")

	if len(u.Metadata) > 0 {
		b, err := json.Marshal(u.Metadata)
		if err != nil {
			return dbUser{}, errors.Wrap(errMarshal, err)
		}
		data = b
	}
	return dbUser{
		ID:       u.ID,
		Email:    u.Email,
		Password: u.Password,
		Metadata: data,
	}, nil

}

func toUser(dbu dbUser) (user.User, error) {
	var metadata map[string]interface{}

	if dbu.Metadata != nil {
		if err := json.Unmarshal([]byte(dbu.Metadata), &metadata); err != nil {
			return user.User{}, errors.Wrap(errUnmarshal, err)
		}
	}

	return user.User{
		ID:       dbu.ID,
		Email:    dbu.Email,
		Password: dbu.Password,
		Metadata: metadata,
	}, nil
}

func createConditionQuery(entity string, params map[string]interface{}) (string, map[string]interface{}, error) {
	var args map[string]interface{}
	var query []string

	args = make(map[string]interface{})
	// 组合判断 基于字段的特殊参数
	for field, val := range params {
		switch field {
		case "email":
			param := fmt.Sprintf(`%%%s%%`, val.(string))
			qs := "email LIKE :email"
			query = append(query, qs)
			args["email"] = param
		case "startTime":
			param := val.(string)
			qs := "DATE_FORMAT(create_time,'%Y-%m-%d') > :startTime"
			query = append(query, qs)
			args["startTime"] = param
		case "ids":
			userIDs := val.([]string)
			qs := fmt.Sprintf("id IN ('%s')", strings.Join(userIDs, "','"))
			query = append(query, qs)
		}
	}

	emq := fmt.Sprintf("%s%s", entity, strings.Join(query, " AND "))
	fmt.Printf("createConditionQuery:%s\n", emq)
	return emq, args, nil
}

func createEmailQuery(entity string, email string) (string, string, error) {
	if email == "" {
		return "", "", nil
	}

	param := fmt.Sprintf(`%%%s%%`, email)
	query := fmt.Sprintf("%semail LIKE :email", entity)
	return query, param, nil
}

func createMetadataQuery(entity string, um user.Metadata) (string, []byte, error) {
	if len(um) == 0 {
		return "", nil, nil
	}

	param, err := json.Marshal(um)
	if err != nil {
		return "", nil, err
	}

	query := fmt.Sprintf("%smetadata @> :metadata", entity)
	return query, param, nil
}
