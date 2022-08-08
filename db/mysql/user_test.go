package mysql_test

import (
	"context"
	"fmt"
	"hellodb/mysql"
	"hellodb/user"
	"testing"

	"github.com/mainflux/mainflux/pkg/errors"
	"github.com/mainflux/mainflux/pkg/uuid"

	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

var idProvider = uuid.New()

func TestUserSave(t *testing.T) {
	uid, err := idProvider.ID()
	email := fmt.Sprintf("%s@example.com", uid)

	require.Nil(t, err, fmt.Sprintf("unexpected error: %s", err))

	cases := []struct {
		desc string
		user user.User
		err  error
	}{
		{
			desc: "new user",
			user: user.User{
				ID:       uid,
				Email:    email,
				Password: "pass",
			},
			err: nil,
		},
		{
			desc: "duplicate user",
			user: user.User{
				ID:       uid,
				Email:    email,
				Password: "pass",
			},
			err: user.ErrConflict,
		},
	}

	dbMiddleware := mysql.NewDatabase(db)

	repo := mysql.NewUserRepository(dbMiddleware)

	for _, tc := range cases {
		_, err := repo.Save(context.Background(), tc.user)
		assert.True(t, errors.Contains(err, tc.err), fmt.Sprintf("%s: expected %s got %s\n", tc.desc, tc.err, err))
	}
}

func TestRetrievePage(t *testing.T) {
	dbMiddleware := mysql.NewDatabase(db)
	userRepo := mysql.NewUserRepository(dbMiddleware)
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
	ids := []string{"5b8a6a03-0abb-41a9-8db0-687f11813c63"}
	offset := int64(0)
	limit := int64(10)

	// page, err := userRepo.RetrievePage(context.Background(), offset, limit, ids, email, meta)
	pm := user.PageMetadata{
		Limit:  limit,
		Offset: offset,
	}
	conditions := map[string]interface{}{
		"email":     email,
		"startTime": "2022-02-05",
		"ids":       ids,
	}
	page, err := userRepo.RetrievePage(context.Background(), pm, conditions)
	size := int64(len(page.Users))

	fmt.Println("err: ", err)
	fmt.Println("size: ", size)
	fmt.Print(page)

}
