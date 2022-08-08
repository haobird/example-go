package main

import (
	"context"
	"fmt"
	"hellosql/mysq"
	"hellosql/user"
	"sync"

	"github.com/davecgh/go-spew/spew"
	"github.com/elgris/sqrl"
	_ "github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
)

var (
	dsn = fmt.Sprintf("%s:%s@tcp(%s)/%s?charset=utf8&parseTime=true", "root", "example", "localhost:3306", "app")
)

// 两个问题：
// 读取 数据的问题
// 读取 分页的问题
// 四种形式：
// 查询操作：1. 查询单个  2. 查询多个 3. 查询多个，分页 4. 查询多个，分页，排序
// 添加操作
// 更新操作
// 删除操作

func main() {
	println("Hello, World!")
	err := mytest()
	fmt.Println(err)
	// build2()

	sync.Map{}
}

func build2() {
	conditions := sqrl.Select().From("users")
	query, args, err := conditions.ToSql()

	fmt.Printf("sql: %+v, args: %+v, err: %s", query, args, err)

	// users := []user.User{
	// 	{ID: "1", Email: "22", Password: "123"},
	// 	{ID: "2", Email: "23", Password: "12133"},
	// }

	conditions2 := sqrl.Select("count(*)").From("users")
	query, args, err = conditions2.ToSql()

	fmt.Printf("sql: %+v, args: %+v, err: %s", query, args, err)

	insert := sqrl.Insert("users").Columns("id", "email", "password")

	query, args, err = insert.ToSql()
	fmt.Printf("sql: %+v, args: %+v, err: %s", query, args, err)

}
func build() {
	users := sqrl.Select("*").From("users").Where("id = ?", 1)
	active := users.Where(sqrl.Eq{"deleted_at": nil}).Where("sex=?", 1).Where(sqrl.Eq{"username": []string{"moe", "larry", "curly", "shemp"}})
	active = active.Offset(0).Limit(0)
	query, args, err := active.ToSql()

	fmt.Printf("sql: %+v, args: %+v, err: %s", query, args, err)

	// stooges := sqrl.Where(sqrl.Eq{"username": []string{"moe", "larry", "curly", "shemp"}})
	// three_stooges := stooges.Limit(3)
}

func mytest() error {
	db, err := sqlx.Open("mysql", dsn)
	if err != nil {
		return err
	}

	defer db.Close()
	// 验证连接
	if err := db.Ping(); err != nil {
		return err
	}

	id := "81847894-bf90-4695-a2f0-91630ec624e3"
	id = "bf90"

	params := map[string]interface{}{
		"id": id,
	}

	page := user.Page{
		Offset: 0,
		Limit:  1,
		Order:  "id",
	}

	userRepo := mysq.NewUserRepository(db)
	u, err := userRepo.RetrievePage(context.Background(), page, params)
	fmt.Println(err)
	spew.Dump(u)

	return nil

}
