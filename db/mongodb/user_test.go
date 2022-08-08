package mongodb_test

import (
	"context"
	"encoding/json"
	"fmt"
	"hellodb/mongodb"
	"hellodb/user"
	"testing"

	"github.com/davecgh/go-spew/spew"
	"github.com/mainflux/mainflux/pkg/uuid"
	"github.com/stretchr/testify/require"
)

var idProvider = uuid.New()

func TestUserSave(t *testing.T) {
	uid, err := idProvider.ID()
	email := fmt.Sprintf("%s@example.com", uid)

	require.Nil(t, err, fmt.Sprintf("unexpected error: %s", err))

	str := `
	{
		"id": "eeeee",
		"email": "123@example.com",
		"password": "pass",
		"metadata": {
			"command": "btzn.light.v1.set_properties",
			"delay_time": 0,
			"did": "proxy.320200431.00050003",
			"total_length": 0,
			"value": [
				{
					"piid": 1,
					"siid": 2,
					"value": false
				}
			]
		}
	}
	`

	var myuser user.User
	err = json.Unmarshal([]byte(str), &myuser)
	if err != nil {
		fmt.Println(err)
		return
	}

	spew.Dump(myuser)

	myuser.ID = uid
	myuser.Email = email

	repo := mongodb.NewUserRepository(db)

	_, err = repo.Save(context.Background(), myuser)
	fmt.Println(err)

}

func TestUserUpdate(t *testing.T) {
	uid, err := idProvider.ID()
	email := fmt.Sprintf("%s@example.com", uid)

	require.Nil(t, err, fmt.Sprintf("unexpected error: %s", err))

	str := `
	{
		"id": "eeeee",
		"email": "12@example.com",
		"password": "pass",
		"metadata": {
			"command": "btzn.light.v1.set_properties",
			"delay_time": 0,
			"did": "proxy.320200431.00050003",
			"total_length": 0,
			"value": [
				{
					"piid": 1,
					"siid": 2,
					"value": false
				}
			]
		}
	}
	`

	var myuser user.User
	err = json.Unmarshal([]byte(str), &myuser)
	if err != nil {
		fmt.Println(err)
		return
	}

	// spew.Dump(myuser)

	fmt.Println(uid, ":", email)

	// myuser.ID = uid
	// myuser.Email = email

	repo := mongodb.NewUserRepository(db)

	err = repo.Update(context.Background(), "", myuser)
	fmt.Println(err)

}

func TestRetrievePage(t *testing.T) {
	userRepo := mongodb.NewUserRepository(db)
	// metaNum := int64(2)
	// var nUsers = int64(10)

	// meta := user.Metadata{
	// 	"admin": "true",
	// }

	// wrongMeta := user.Metadata{
	// 	"wrong": "true",
	// }

	email := ""
	// meta := user.Metadata{}
	// ids := []string{"4ec45074-cc10-42ed-a5d1-fff9d04d8a1f"}
	offset := int64(0)
	limit := int64(10)

	// page, err := userRepo.RetrievePage(context.Background(), offset, limit, ids, email, meta)
	pm := user.PageMetadata{
		Limit:  limit,
		Offset: offset,
	}
	conditions := map[string]interface{}{
		"email":     email,
		"startTime": "2022-02-06T14:55:57.814Z",
		// "total_length": 1,
		// "ids":          ids,
	}
	page, err := userRepo.RetrievePage(context.Background(), pm, conditions)
	size := int64(len(page.Users))

	fmt.Println("err: ", err)
	fmt.Println("size: ", size)
	fmt.Print(page)

}
