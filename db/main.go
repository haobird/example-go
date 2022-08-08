package main

import (
	"context"
	"fmt"
	"hellodb/mysql"
	"hellodb/mysqlx"
	"log"

	"github.com/davecgh/go-spew/spew"
	"github.com/jmoiron/sqlx"
)

var (
	dns = ""
	db  *sqlx.DB
)

func main() {
	fmt.Println("dtss")
	url := fmt.Sprintf("%s:%s@tcp(%s)/%s?charset=utf8&parseTime=true", "root", "example", "localhost:3306", "app")
	fmt.Println(url)
	var err error
	if db, err = mysql.Connect(url); err != nil {
		log.Fatalf("Could not setup test DB connection: %s", err)
	}

	id := "81847894-bf90-4695-a2f0-91630ec624e3"
	id = "222"

	userRepo := mysqlx.NewUserRepository(db)
	u, err := userRepo.RetrieveByID(context.Background(), id)
	fmt.Println(err)
	spew.Dump(u)

}
