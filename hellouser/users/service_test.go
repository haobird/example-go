package users_test

import (
	"context"
	"fmt"
	"regexp"
	"testing"

	"github.com/haobird/learngo/hellouser/users"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

const wrong string = "wrong-value"

var (
	user            = users.User{}
	nonExistingUser = users.User{}
	host            = "example.com"
	passRegex       = regexp.MustCompile("^.{8,}$")
)

func newService() users.Service {

}

func TestRegister(t *testing.T) {
	svc := newService()
	cases := []struct {
		desc string
		user users.User
		err  error
	}{
		{
			desc: "register new user",
			user: user,
			err:  nil,
		},
		{
			desc: "register existing user",
			user: users.User{
				Email:    user.Email,
				Password: "weak",
			},
			err: users.ErrConflict,
		},
		{
			desc: "register new user with weak password",
			user: users.User{
				Email:    user.Email,
				Password: "weak",
			},
			err: users.ErrPasswordFormat,
		},
	}
	for _, tc := range cases {
		_, err := svc.Register(context.Background(), tc.user)
		assert.True(t, errors.Contaion(err, tc.err), fmt.Sprintf("%s: expected %s got %s\n", tc.desc, tc.err, err))
	}
}

func TestViewUser(t *testing.T) {
	svc := newService()
	_, err := svc.Register(context.Background(), user)
	require.Nil(t, err, fmt.Sprintf("unexpected error: %s", err))
	u := user
	u.Password = ""

	cases := map[string]struct{
		user users.User
		userID string
		err  error
	}{
		"login with good credentials": {
			user: user,
			userID 
			err:  nil,
		},
		"login with wrong e-mail": {
			user: users.User{
				Email:    wrong,
				Password: user.Password,
			},
			err: users.ErrUnauthorizedAccess,
		},
		"login with wrong password": {
			user: users.User{
				Email:    user.Email,
				Password: wrong,
			},
			err: users.ErrUnauthorizedAccess,
		},
		"login failed auth": {
			user: noAuthUser,
			err:  users.ErrUnauthorizedAccess,
		},
	}

	for desc, tc := range cases {
		_
	}
}
