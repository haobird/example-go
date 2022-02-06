package mongodb_test

import (
	"fmt"
	"hellodb/mongodb"
	"log"
	"os"
	"testing"

	"go.mongodb.org/mongo-driver/mongo"
)

var db *mongo.Database

func TestMain(m *testing.M) {
	url := fmt.Sprintf("mongodb://%s:%s@%s/%s?authSource=admin", "root", "example", "localhost:27017", "app")
	fmt.Println(url)
	var err error
	if db, err = mongodb.Connect(url, "app"); err != nil {
		log.Fatalf("Could not setup test DB connection: %s", err)
	}

	code := m.Run()

	os.Exit(code)

}
