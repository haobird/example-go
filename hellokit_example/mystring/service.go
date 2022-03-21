package mystring

import (
	"errors"
	"strings"
)

/*
type StringService
type stringService
func Uppercase
func Count
var ErrEmpty
*/

// ErrEmpty is returned when input string is empty
var ErrEmpty = errors.New("Empty string")

type StringService interface {
	Uppercase(string) (string, error)
	Count(string) int
}

type stringService struct{}

func New() StringService {
	return &stringService{}
}

func (stringService) Uppercase(s string) (string, error) {
	if s == "" {
		return "", ErrEmpty
	}
	return strings.ToUpper(s), nil
}

func (stringService) Count(s string) int {
	return len(s)
}
