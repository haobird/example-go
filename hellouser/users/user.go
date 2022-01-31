package users

import (
	"context"
	"regexp"
)

const (
	MAX_LOCAL_LEN  = 64
	MAX_DOMAIN_LEN = 255
	MAX_TLD_LEN    = 24

	AT_SEPARATOR  = "@"
	DOT_SEPARATOR = "."
)

var (
	userRegexp    = regexp.MustCompile("^[a-zA-Z0-9!#$%&'*+/=?^_`{|}~.-]+$")
	hostRegexp    = regexp.MustCompile("^[^\\s]+\\.[^\\s]+$")
	userDotRegexp = regexp.MustCompile("(^[.]{1})|([.]{1}$)|([.]{2,})")
)

// Metadata to be used for thing or channel for customized describing of particular thing or channel.
type Metadata map[string]interface{}

// User represents a user account. Each user is identified given its email and password.
type User struct {
	ID       string
	Email    string
	Password string
	Metadata Metadata
}

func (u User) Validate() error {
	if !isEmail(u.Email) {
		return ErrMalformedEntity
	}
	return nil
}

type UserRepository interface {
	Save(ctx context.Context, u User) (string, error)

	UpdateUser(ctx context.Context, u User) error

	RetrieveByEmail(ctx context.Context, email string) (User, error)

	RetrieveByID(ctx context.Context, id string) (User, error)

	RetrieveAll(ctx context.Context, offset, limit uint64, userIDs []string, email string, m Metadata) (UserPage, error)

	UpdatePassword(ctx context.Context, email, password string) error
}

func isEmail(email string) bool {
	return true
}
