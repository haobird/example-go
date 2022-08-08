package user

import (
	"context"
	"time"
)

type Page struct {
	Total  int64
	Offset int64
	Limit  int64
	Dir    string
	Order  string
}

type User struct {
	ID       string `json:"id"`
	Email    string `json:"email"`
	Password string `json:"password"`
	// Metadata   Metadata `json:"metadata"`
	CreateTime time.Time
}

type UserPage struct {
	Page
	Items []User
}

type UserRepository interface {
	Save(ctx context.Context, u User) (User, error)
	SaveMany(ctx context.Context, us ...User) (int64, error)

	RetrieveAll(ctx context.Context, clause map[string]interface{}) ([]User, error)

	RetrievePage(ctx context.Context, pm Page, clause map[string]interface{}) (UserPage, error)
}
