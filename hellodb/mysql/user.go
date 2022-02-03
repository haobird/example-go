package mysql

import (
	"context"
	"hellodb/user"

	"github.com/haobird/learngo/hellouser/users"
	"github.com/lib/pq"
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
	if user.ID == "" || user.Email == "" {
		return "", users.ErrMalformedEntity
	}

	dbu, err := toDBUser(user)
	if err != nil {
		return "", errors.Wrap(errSaveUserDB, err)
	}

	row, err := ur.db.NamedQueryContext(ctx, q, dbu)
	if err != nil {
		pqErr, ok := err.(*pq.Error)
		if ok {
			switch pqErr.Code.Name() {
			case errInvalid, errTruncation:
				return "", errors.Wrap(users.ErrMalformedEntity, err)
			case errDuplicate:
				return "", errors.Wrap(users.ErrConflict, err)
			}
		}
		return "", errors.Wrap(errSaveUserDB, err)
	}

	defer row.Close()
	row.Next()
	var id string
	if err := row.Scan(&id); err != nil {
		return "", err
	}
	return id, nil
}
