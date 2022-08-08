package mysqlx_test

import (
	"context"
	"fmt"
	"hellodb/mysqlx"
	"hellodb/user"
	"log"
	"os"
	"testing"

	"github.com/davecgh/go-spew/spew"
	"github.com/jmoiron/sqlx"
	"github.com/mainflux/mainflux/pkg/uuid"
	"github.com/stretchr/testify/require"
)

var idProvider = uuid.New()
var db *sqlx.DB

func TestMain(m *testing.M) {
	url := fmt.Sprintf("%s:%s@tcp(%s)/%s?charset=utf8&parseTime=true", "root", "example", "localhost:3306", "app")
	fmt.Println(url)
	var err error
	if db, err = mysqlx.Connect(url); err != nil {
		log.Fatalf("Could not setup test DB connection: %s", err)
	}

	code := m.Run()

	os.Exit(code)

}

func TestSave(t *testing.T) {
	uid, err := idProvider.ID()
	email := fmt.Sprintf("%s@example.com", uid)

	require.Nil(t, err, fmt.Sprintf("unexpected error: %s", err))

	info := user.User{
		ID:       uid,
		Email:    email,
		Password: "pass",
	}

	userRepo := mysqlx.NewUserRepository(db)
	u, err := userRepo.Save(context.Background(), info)
	fmt.Println(err)
	spew.Dump(u)
}

func TestSaveMany(t *testing.T) {
	num := 3

	items := make([]user.User, 0)
	for i := 0; i < num; i++ {
		uid, _ := idProvider.ID()
		email := fmt.Sprintf("%s@example.com", uid)
		info := user.User{
			ID:       uid,
			Email:    email,
			Password: "pass",
		}
		items = append(items, info)
	}

	userRepo := mysqlx.NewUserRepository(db)
	total, err := userRepo.SaveMany(context.Background(), items...)
	fmt.Println(err)
	spew.Dump(total)
}

func TestRetrieveByID(t *testing.T) {
	id := "81847894-bf90-4695-a2f0-91630ec624e3"
	// id = "222"

	//

	userRepo := mysqlx.NewUserRepository(db)
	u, err := userRepo.RetrieveByID(context.Background(), id)
	fmt.Println(err)
	spew.Dump(u)
}

func TestRetrieveByEmail(t *testing.T) {
	userRepo := mysqlx.NewUserRepository(db)
	email := "81847894-bf90-4695-a2f0-91630ec624e3@example.com"
	u, err := userRepo.RetrieveByEmail(context.Background(), email)
	fmt.Println(err)
	spew.Dump(u)

}

func TestRetrieveByIDs(t *testing.T) {
	userRepo := mysqlx.NewUserRepository(db)
	ids := []string{"81847894-bf90-4695-a2f0-91630ec624e3", "bf90"}
	us, err := userRepo.RetrieveByIDs(context.Background(), ids)
	fmt.Println(err)
	spew.Dump(us)

}

func TestRetrieveAll(t *testing.T) {
	userRepo := mysqlx.NewUserRepository(db)
	// ids := []string{"81847894-bf90-4695-a2f0-91630ec624e3", "bf90"}
	clause := map[string]interface{}{
		// "ids": ids,
	}
	us, err := userRepo.RetrieveAll(context.Background(), clause)
	fmt.Println(err)
	spew.Dump(us)

}
