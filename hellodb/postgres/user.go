package postgres

import (
	"context"
	"database/sql"
	"encoding/json"
	"fmt"
	"hellodb/user"
	"strings"

	"github.com/imdario/mergo"
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

func (r userRepository) Save(ctx context.Context, u user.User) (user.User, error) {
	q := `INSERT INTO users (email, password, id, metadata) VALUES (:email, :password, :id, :metadata) RETURNING id`
	if u.ID == "" || u.Email == "" {
		return u, user.ErrMalformedEntity
	}

	dbu, err := toDBUser(u)
	if err != nil {
		return u, errors.Wrap(err, user.ErrCreateEntity.Error())
	}

	row, err := r.db.NamedQueryContext(ctx, q, dbu)
	if err != nil {
		pqErr, ok := err.(*pq.Error)
		if ok {
			switch pqErr.Code.Name() {
			case errInvalid, errTruncation:
				return u, errors.Wrap(err, user.ErrMalformedEntity.Error())
			case errDuplicate:
				return u, errors.Wrap(err, user.ErrConflict.Error())
			}
		}
		return u, errors.Wrap(err, user.ErrCreateEntity.Error())
	}

	defer row.Close()
	row.Next()
	var id string
	if err := row.Scan(&id); err != nil {
		return u, err
	}
	return u, nil
}

func (r userRepository) SaveMany(ctx context.Context, ths ...user.User) ([]user.User, error) {
	var items []user.User
	tx, err := r.db.BeginTxx(ctx, nil)

	if err != nil {
		return items, errors.Wrap(err, "create entity failed")
	}

	q := `INSERT INTO users (email, password, id, metadata) VALUES (:email, :password, :id, :metadata);`
	for _, t := range ths {
		dbt, err := toDBUser(t)
		if err != nil {
			return items, errors.Wrap(err, "create entity failed")
		}

		if _, err := tx.NamedExecContext(ctx, q, dbt); err != nil {
			tx.Rollback()
			pqErr, ok := err.(*pq.Error)
			if ok {
				switch pqErr.Code.Name() {
				case errInvalid, errTruncation:
					return items, errors.Wrap(err, "malformed entity specification")
				case errDuplicate:
					return items, errors.Wrap(err, "entity already exists")
				}
			}

			return items, errors.Wrap(err, "create entity failed")
		}
	}

	if err = tx.Commit(); err != nil {
		return items, errors.Wrap(err, "create entity failed")
	}

	return ths, nil
}

func (r userRepository) Update(ctx context.Context, t user.User) error {
	q := `UPDATE users SET password = :password, metadata = :metadata WHERE email = :email AND id = :id;`

	dbt, err := toDBUser(t)
	if err != nil {
		return errors.Wrap(err, "update entity failed")
	}

	res, errdb := r.db.NamedExecContext(ctx, q, dbt)
	if errdb != nil {
		pqErr, ok := errdb.(*pq.Error)
		if ok {
			switch pqErr.Code.Name() {
			case errInvalid, errTruncation:
				return errors.Wrap(errdb, "malformed entity specification")
			}
		}

		return errors.Wrap(err, "update entity failed")
	}

	cnt, errdb := res.RowsAffected()
	if errdb != nil {
		return errors.Wrap(err, "update entity failed")
	}

	if cnt == 0 {
		return errors.New("non-existent entity")
	}

	return nil
}

func (r userRepository) RetrieveByID(ctx context.Context, id string) (user.User, error) {
	var item user.User

	q := `SELECT email, password, metadata FROM users WHERE id = $1;`

	dbt := dbUser{
		ID: id,
	}

	if err := r.db.QueryRowxContext(ctx, q, id).StructScan(&dbt); err != nil {
		pqErr, ok := err.(*pq.Error)
		if err == sql.ErrNoRows || ok && errInvalid == pqErr.Code.Name() {
			return item, errors.Wrap(err, user.ErrNotFound.Error())
		}
		return item, errors.Wrap(err, user.ErrSelectEntity.Error())
	}

	return toUser(dbt)
}

func (r userRepository) RetrieveAll(ctx context.Context, conditions map[string]interface{}) ([]user.User, error) {
	var items []user.User

	q, p, err := createConditionQuery(conditions)
	if err != nil {
		return items, errors.Wrap(err, user.ErrSelectEntity.Error())
	}

	query := fmt.Sprintf(`SELECT id, name, key, metadata FROM users WHERE %s;`, q)
	rows, err := r.db.NamedQueryContext(ctx, query, p)
	if err != nil {
		return items, errors.Wrap(err, user.ErrSelectEntity.Error())
	}
	defer rows.Close()

	for rows.Next() {
		dbt := dbUser{}
		if err := rows.StructScan(&dbt); err != nil {
			return items, errors.Wrap(err, user.ErrSelectEntity.Error())
		}

		th, err := toUser(dbt)
		if err != nil {
			return items, errors.Wrap(err, user.ErrViewEntity.Error())
		}

		items = append(items, th)
	}

	return items, nil

}

func (r userRepository) RetrieveAllByIDs(ctx context.Context, ids []string) ([]user.User, error) {
	var items []user.User
	if len(ids) == 0 {
		return items, nil
	}

	idq := fmt.Sprintf("WHERE id IN ('%s') ", strings.Join(ids, "','"))

	q := fmt.Sprintf(`SELECT id,  email, password, metadata  FROM users
					   %s;`, idq)

	params := map[string]interface{}{}

	rows, err := r.db.NamedQueryContext(ctx, q, params)
	if err != nil {
		return items, errors.Wrap(err, user.ErrSelectEntity.Error())
	}
	defer rows.Close()

	for rows.Next() {
		dbt := dbUser{}
		if err := rows.StructScan(&dbt); err != nil {
			return items, errors.Wrap(err, user.ErrSelectEntity.Error())
		}

		th, err := toUser(dbt)
		if err != nil {
			return items, errors.Wrap(err, user.ErrViewEntity.Error())
		}

		items = append(items, th)
	}

	return items, nil
}

func (ur userRepository) RetrievePage(ctx context.Context, pm user.PageMetadata, conditions map[string]interface{}) (user.UserPage, error) {
	var page user.UserPage
	var query []string
	var emq string
	limit := pm.Limit
	offset := pm.Offset

	cs, cp, err := createConditionQuery(conditions)
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
		return page, errors.Wrap(err, user.ErrSelectEntity.Error())
	}
	defer rows.Close()

	var items []user.User
	for rows.Next() {
		dbusr := dbUser{}
		if err := rows.StructScan(&dbusr); err != nil {
			return page, errors.Wrap(err, user.ErrSelectEntity.Error())
		}

		u, err := toUser(dbusr)
		if err != nil {
			return page, errors.Wrap(err, user.ErrViewEntity.Error())
		}

		items = append(items, u)
	}

	cq := fmt.Sprintf(`SELECT COUNT(*) FROM users %s;`, emq)

	total, err := total(ctx, ur.db, cq, params)

	if err != nil {
		return page, errors.Wrap(err, user.ErrSelectEntity.Error())
	}

	return user.UserPage{
		Users: items,
		PageMetadata: user.PageMetadata{
			Total:  total,
			Offset: offset,
			Limit:  limit,
		},
	}, nil

}

func (ur userRepository) Remove(ctx context.Context, conditions map[string]interface{}) (int64, error) {
	q, p, err := createConditionQuery(conditions)
	if err != nil {
		return 0, errors.Wrap(err, user.ErrSelectEntity.Error())
	}

	query := fmt.Sprintf(`DELETE FROM users WHERE %s;`, q)
	result, err := ur.db.NamedExecContext(ctx, query, p)
	if err != nil {
		return 0, errors.Wrap(err, user.ErrRemoveEntity.Error())
	}

	affectedRows, err := result.RowsAffected()
	if err != nil {
		return 0, errors.Wrap(err, user.ErrRemoveEntity.Error())
	}

	return affectedRows, nil

}

func (ur userRepository) RemoveByID(ctx context.Context, id string) error {
	dbth := dbUser{
		ID: id,
	}
	q := `DELETE FROM users WHERE id = :id;`
	if _, err := ur.db.NamedExecContext(ctx, q, dbth); err != nil {
		return errors.Wrap(err, user.ErrRemoveEntity.Error())
	}
	return nil
}

func list(ctx context.Context, db Database, query string, params interface{}) ([]user.User, error) {
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
			return dbUser{}, errors.Wrap(err, user.ErrMalformedEntity.Error())
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
			return user.User{}, errors.Wrap(err, user.ErrMalformedEntity.Error())
		}
	}

	return user.User{
		ID:       dbu.ID,
		Email:    dbu.Email,
		Password: dbu.Password,
		Metadata: metadata,
	}, nil
}

func createConditionQuery(params map[string]interface{}) (string, map[string]interface{}, error) {
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
			// qs := "DATE_FORMAT(create_time,'%Y-%m-%d') > :startTime"
			qs := "to_date(cast(create_time as TEXT),'YYYY-MM-DD') > :startTime"
			query = append(query, qs)
			args["startTime"] = param
		case "ids":
			userIDs := val.([]string)
			qs := fmt.Sprintf("id IN ('%s')", strings.Join(userIDs, "','"))
			query = append(query, qs)
		}
	}

	emq := fmt.Sprintf("%s", strings.Join(query, " AND "))
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
