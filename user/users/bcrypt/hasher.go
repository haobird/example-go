package bcrypt

import (
	"errors"

	"github.com/haobird/learngo/hellouser/users"
	"golang.org/x/crypto/bcrypt"
)

const cost int = 10

var (
	errHashPassword    = errors.New("Generate hash from password failed")
	errComparePassword = errors.New("Compare hash and password failed")
)

type bcryptHasher struct{}

func New() users.Hasher {
	return &bcryptHasher{}
}

func (bh *bcryptHasher) Hash(pwd string) (string, error) {
	hash, err := bcrypt.GenerateFromPassword([]byte(pwd), cost)
	if err != nil {
		return "", errHashPassword
	}
	return string(hash), nil
}

func (bh *bcryptHasher) Compare(plain, hashed string) error {
	err := bcrypt.CompareHashAndPassword([]byte(hashed), []byte(plain))
	if err != nil {
		return errComparePassword
	}
	return nil
}
