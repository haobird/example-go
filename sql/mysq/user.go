package mysq

import (
	"context"
	"errors"
	"fmt"
	"hellosql/user"

	"github.com/VividCortex/mysqlerr"
	"github.com/elgris/sqrl"
	"github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
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
	db *sqlx.DB
}

func NewUserRepository(db *sqlx.DB) user.UserRepository {
	udb := db.Unsafe()
	return &userRepository{
		db: udb,
	}
}

func (ur userRepository) SaveMany(ctx context.Context, u user.User) (user.User, error) {
	active := sqrl.Insert("users").Columns("id", "email", "password").Values(u.ID, u.Email, u.Password)
	query, args, err := active.ToSql()
	fmt.Printf("query:%s, args: %+v, err: %s \n", query, args, err)
	if err != nil {
		return u, err
	}

	ret, err := ur.db.ExecContext(ctx, query, args...)
	if err != nil {
		// make sure err is a mysql.MySQLError.
		errMySQL, ok := err.(*mysql.MySQLError)
		if ok {
			switch errMySQL.Number {
			case mysqlerr.ER_DUP_ENTRY: // Error 1062: Duplicate entry '%s' for key %d
				return u, err
			}
		}
		return u, err
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

func (ur userRepository) SaveMany(ctx context.Context, us ...user.User) (int64, error) {
	if len(us) == 0 {
		return 0, user.ErrMalformedEntity
	}

	q := `INSERT INTO users (email, password, id, metadata) VALUES (:email, :password, :id, :metadata)`
	res, err := ur.db.NamedExecContext(ctx, q, us)
	if err != nil {
		return 0, errors.Wrap(errSaveUserDB, err)
	}

	return res.RowsAffected(), nil
}

func (ur userRepository) RetrieveAll(ctx context.Context, clause map[string]interface{}) ([]user.User, error) {
	var dbus []user.User

	dataActive := sqrl.Select("*").From("users")
	// where
	// order
	// limit
	dataActive = dataActive.Where(clause)
	dataActive = dataActive.OrderBy("id")
	query, args, err := dataActive.ToSql()
	if err != nil {
		return dbus, err
	}

	fmt.Printf("query:%s, args: %+v\n", query, args)
	err = ur.db.Select(&dbus, query, args...)
	if err != nil {
		return dbus, err
	}

	return dbus, nil
}

func (ur userRepository) RetrievePage(ctx context.Context, pm user.Page, conditions map[string]interface{}) (user.UserPage, error) {
	var dbusp user.UserPage
	var dbus []user.User
	var total int64

	dataActive := sqrl.Select("*").From("users")
	err := ur.buildCondition(dataActive, conditions)
	if err != nil {
		return dbusp, err
	}

	dataActive = dataActive.Limit(uint64(pm.Limit)).Offset(uint64(pm.Offset)).OrderBy(pm.Order)
	query, args, err := dataActive.ToSql()
	fmt.Printf("query:%s, args: %+v, err: %s \n", query, args, err)
	if err != nil {
		return dbusp, err
	}

	err = ur.db.Select(&dbus, query, args...)
	if err != nil {
		return dbusp, err
	}

	totalActive := sqrl.Select("count(*)").From("users")
	err = ur.buildCondition(totalActive, conditions)
	if err != nil {
		return dbusp, err
	}
	query, args, err = totalActive.ToSql()
	fmt.Printf("query:%s, args: %+v, err: %s \n", query, args, err)
	if err != nil {
		return dbusp, err
	}
	err = ur.db.Get(&total, query, args...)
	if err != nil {
		return dbusp, err
	}
	dbusp.Total = total
	dbusp.Items = dbus
	return dbusp, nil

}

func (ur userRepository) list(ctx context.Context, query string, params interface{}) ([]user.User, error) {
	var items []user.User
	rows, err := ur.db.NamedQueryContext(ctx, query, params)
	if err != nil {
		return items, err
	}
	defer rows.Close()

	for rows.Next() {
		dbusr := user.User{}
		if err := rows.StructScan(&dbusr); err != nil {
			return items, err
		}
		items = append(items, dbusr)
	}
	return items, nil
}

func (ur userRepository) total(ctx context.Context, query string, args interface{}) (int64, error) {
	rows, err := ur.db.NamedQueryContext(ctx, query, args)
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

// 两个步骤：
// 1. 根据条件获取数据
// 2. 根据数据计算分页信息

func (ur userRepository) buildCondition(builder *sqrl.SelectBuilder, clause map[string]interface{}) error {
	for field, val := range clause {
		switch field {
		case "id":
			builder = builder.Where("id = ?", val)
		case "ids":
			builder = builder.Where(sqrl.Eq{"id": val})
		case "email":
			builder = builder.Where(sqrl.Eq{"email": val})
		case "startTime":
			builder = builder.Where(sqrl.Gt{"create_time": val})
		}
	}
	return nil
}
