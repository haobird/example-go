package mysqlx

import (
	"context"
	"fmt"
	"hellodb/user"
	"strings"

	"github.com/jmoiron/sqlx"
)

type userRepository struct {
	db *sqlx.DB
}

func NewUserRepository(db *sqlx.DB) user.UserRepository {
	udb := db.Unsafe()
	return &userRepository{
		db: udb,
	}
}

func (r userRepository) Save(ctx context.Context, u user.User) (dbu user.User, err error) {
	query := `INSERT INTO users (id, email, password) VALUES (:id, :email, :password)`
	row, err := r.db.NamedQueryContext(ctx, query, u)
	defer row.Close()
	row.Next()

	err = row.Scan(&dbu)
	return
}

func (r userRepository) SaveMany(ctx context.Context, us ...user.User) (int64, error) {
	query := `INSERT INTO users (id, email, password) VALUES (:id, :email, :password)`
	res, err := r.db.NamedExecContext(ctx, query, us)
	if err != nil {
		return 0, err
	}
	count, err := res.RowsAffected()
	fmt.Println(count)
	return count, err
}

func (r userRepository) RetrieveByID(ctx context.Context, id string) (user.User, error) {
	var err error
	query := `SELECT * FROM users WHERE id = ? limit 1;`

	var u user.User
	err = r.db.QueryRowxContext(ctx, query, id).StructScan(&u)
	return u, err
}

func (r userRepository) RetrieveByEmail(ctx context.Context, email string) (u user.User, err error) {
	query := `SELECT * FROM users WHERE _id = ? and email = ?  limit 1;`
	_id := 1
	err = r.db.QueryRowxContext(ctx, query, _id, email).StructScan(&u)
	return
}

func (r userRepository) RetrieveByIDs(ctx context.Context, ids []string) (items []user.User, err error) {
	query := `SELECT * FROM users WHERE id in (:ids) and create_time < :time ;`

	arg := map[string]interface{}{
		"ids":  ids,
		"time": "2022-03-31 07:31:52",
	}
	query, args, err := sqlx.Named(query, arg)
	query, args, err = sqlx.In(query, args...)
	query = r.db.Rebind(query)
	rows, err := r.db.Queryx(query, args...)

	if err != nil {
		return
	}
	defer rows.Close()

	for rows.Next() {
		var item user.User
		if err = rows.StructScan(&item); err != nil {
			return
		}
		items = append(items, item)
	}

	return items, err
}

func (r userRepository) RetrieveAll(ctx context.Context, clause map[string]interface{}) (items []user.User, err error) {
	query := `SELECT * FROM users WHERE id in (:ids) and create_time < :time ;`

	arg := map[string]interface{}{
		"time": "2022-03-31 07:31:52",
	}
	if val, ok := clause["ids"]; ok {
		ids := val.([]string)
		arg["ids"] = "'" + strings.Join(ids, "','") + "'"
	}

	arg["ids"] = "'81847894-bf90-4695-a2f0-91630ec624e3','bf90'"

	fmt.Println(arg)
	rows, err := r.db.NamedQueryContext(ctx, query, arg)
	if err != nil {
		return
	}
	defer rows.Close()

	for rows.Next() {
		var item user.User
		if err = rows.StructScan(&item); err != nil {
			return
		}
		items = append(items, item)
	}

	return items, err
}

func (r userRepository) RetrievePage(ctx context.Context, clause map[string]interface{}) (items []user.User, err error) {
	return
}

func total(ctx context.Context, db *sqlx.DB, query string, params interface{}) (int64, error) {
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
