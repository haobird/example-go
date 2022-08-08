package users

import (
	"context"
	"errors"
	"regexp"
)

// define errors
var (
	ErrConflict = errors.New("email already taken")

	ErrNotFound = errors.New("non-existent entity")

	ErrMalformedEntity = errors.New("malformed entity specification")

	ErrPasswordFormat = errors.New("password does not meet the requirements")

	ErrUnauthorizedAccess = errors.New("missing or invalid credentials provided")
)

// Service specifies an API that must be fullfiled by the domain service implementation.
type Service interface {
	Register(ctx context.Context, user User) (string, error)

	ViewUser(ctx context.Context, token, id string) (User, error)

	ListUsers(ctx context.Context, token string, offset, limit uint64, email string, meta Metadata) (UserPage, error)

	UpdateUser(ctx context.Context, token string, user User) error
}

// PageMetadata contains page metadata that helps navigation
type PageMetadata struct {
	Total  uint64
	Offset uint64
	Limit  uint64
	Name   string
}

type UserPage struct {
	PageMetadata
	Users []User
}

type usersService struct {
	users     UserRepository
	hasher    Hasher
	email     Emailer
	passRegex *regexp.Regexp
}

func New(users UserRepository, hasher Hasher, e Emailer, passRegex *regexp.Regexp) Service {
	return &usersService{
		users:     users,
		hasher:    hasher,
		email:     e,
		passRegex: passRegex,
	}
}

func (svc usersService) Register(ctx context.Context, user User) (string, error) {
	if err := user.Validate(); err != nil {
		return "", err
	}
	if !svc.passRegex.MatchString(user.Password) {
		return "", ErrPasswordFormat
	}
	hash, err := svc.hasher.Hash(user.Password)
	if err != nil {
		return "", ErrMalformedEntity
	}
	user.Password = hash
	uid, err := svc.users.Save(ctx, user)
	if err != nil {
		return "", err
	}
	return uid, nil
}

func (svc usersService) ViewUser(ctx context.Context, token, id string) (User, error) {
	dbUser, err := svc.users.RetrieveByID(ctx, id)
	if err != nil {
		return User{}, ErrUnauthorizedAccess
	}
	return User{
		ID:       id,
		Email:    dbUser.Email,
		Password: "",
		Metadata: dbUser.Metadata,
	}, nil
}

func (svc usersService) ListUsers(ctx context.Context, token string, offset, limit uint64, email string, m Metadata) (UserPage, error) {
	return svc.users.RetrieveAll(ctx, offset, limit, nil, email, m)
}

func (svc usersService) UpdateUser(ctx context.Context, token string, u User) error {
	user := User{
		Metadata: u.Metadata,
	}
	return svc.users.UpdateUser(ctx, user)
}
