package mysql_test

import (
	"fmt"
	"hellodb/mysql"
	"log"
	"os"
	"testing"

	_ "github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
)

var db *sqlx.DB

func TestMain(m *testing.M) {
	url := fmt.Sprintf("%s:%s@tcp(%s)/%s?charset=utf8&parseTime=true", "root", "example", "localhost:3306", "app")
	fmt.Println(url)
	var err error
	if db, err = mysql.Connect(url); err != nil {
		log.Fatalf("Could not setup test DB connection: %s", err)
	}

	code := m.Run()

	os.Exit(code)

}
