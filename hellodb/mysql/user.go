package mysql

import (
	"context"
	"encoding/json"
	"fmt"
	"hellodb/user"

	"github.com/pkg/errors"
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

func (ur userRepository) Save(ctx context.Context, u user.User) (string, error) {
	q := `INSERT INTO users (email, password, id, metadata) VALUES (:email, :password, :id, :metadata) RETURNING id`
	if u.ID == "" || u.Email == "" {
		return "", user.ErrMalformedEntity
	}

	dbu, err := toDBUser(u)
	if err != nil {
		return "", errors.Wrap(errSaveUserDB, "ddd")
	}

	row, err := ur.db.NamedQueryContext(ctx, q, dbu)
	// if err != nil {
	// 	pqErr, ok := err.(*pq.Error)
	// 	if ok {
	// 		switch pqErr.Code.Name() {
	// 		case errInvalid, errTruncation:
	// 			return "", errors.Wrap(user.ErrMalformedEntity, err)
	// 		case errDuplicate:
	// 			return "", errors.Wrap(user.ErrConflict, err)
	// 		}
	// 	}
	// 	return "", errors.Wrap(errSaveUserDB, err)
	// }

	defer row.Close()
	row.Next()
	var id string
	if err := row.Scan(&id); err != nil {
		return "", err
	}
	return id, nil
}

func (ur userRepository) Remove(ctx context.Context, id string) error {
	return nil
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
			return dbUser{}, errors.Wrap(errMarshal, "ddd")
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
			return user.User{}, errors.Wrap(errUnmarshal, "ddd")
		}
	}

	return user.User{
		ID:       dbu.ID,
		Email:    dbu.Email,
		Password: dbu.Password,
		Metadata: metadata,
	}, nil
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
