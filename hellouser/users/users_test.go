package users_test

import (
	"fmt"
	"math/rand"
	"testing"

	"github.com/haobird/learngo/hellouser/users"
	"github.com/stretchr/testify/assert"
)

const (
	email    = "user@example.com"
	password = "password"

	maxLocalLen  = 64
	maxDomainLen = 255
	maxTLDLen    = 24
)

var letters = "abcdefghijklmnopqrstuvwxyz"

func randomString(n int) string {
	b := make([]byte, n)
	for i := range b {
		b[i] = letters[rand.Intn(len(letters))]
	}
	return string(b)
}

func TestValidate(t *testing.T) {
	cases := map[string]struct {
		user users.User
		err  error
	}{
		"validate user with valid data":                 {},
		"validate user with valid domain and subdomain": {},
		"validate user with invalid subdomain":          {},
		"validate user with invalid domain":             {},
		"validate user with empty email":                {},
		"validate user with invalid email":              {},
	}

	for desc, tc := range cases {
		err := tc.user.Validate()
		assert.True(t, errors.Contains(err, tc.err), fmt.Sprintf("%s: expected %s got %s\n", desc, tc.err, err))
	}
}
