package user

import (
	"context"
	"time"
)

type PageMetadata struct {
	Total  int64
	Offset int64
	Limit  int64
	Dir    string
	Order  string
}

type Metadata map[string]interface{}

type User struct {
	ID         string   `json:"id"`
	Email      string   `json:"email"`
	Password   string   `json:"password"`
	Metadata   Metadata `json:"metadata"`
	CreateTime time.Time
}

type UserPage struct {
	PageMetadata
	Users []User
}

type UserRepository interface {
	Save(ctx context.Context, u User) (string, error)

	// SaveMany(ctx context.Context, us ...User) ([]User, error)

	Update(ctx context.Context, id string, u User) error

	// RetrieveByEmail(ctx context.Context, email string) (User, error)

	// RetrieveByID(ctx context.Context, id string) (User, error)

	// RetrieveAllByIDs(ctx context.Context, ids []string) ([]User, error)

	// RetrieveAllByCondition(ctx context.Context, params map[string]interface{}) ([]User, error)

	RetrievePage(ctx context.Context, pm PageMetadata, clause map[string]interface{}) (UserPage, error)

	// RetrieveAll retrieves all users for given array of userIDs.
	// RetrievePage(ctx context.Context, offset, limit int64, order, dir string, filter map[string]interface{}) (UserPage, error)

	// Remove(ctx context.Context, id string) error
}
