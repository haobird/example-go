package postgres_test

import (
	"fmt"
	"log"
	"os"
	"testing"

	"hellodb/postgres"

	_ "github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
)

var db *sqlx.DB

func TestMain(m *testing.M) {
	port := "5432"
	url := fmt.Sprintf("host=localhost port=%s user=postgres dbname=app password=example sslmode=disable", port)

	var err error
	if db, err = postgres.Connect(url); err != nil {
		log.Fatalf("Could not setup test DB connection: %s", err)
	}

	code := m.Run()

	os.Exit(code)
}
