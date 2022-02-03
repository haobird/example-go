package user

import "context"

type PageMetadata struct {
	Total  int64
	Offset int64
	Limit  int64
	Dir    string
	Name   string
}

type Metadata map[string]interface{}

type User struct {
	ID       string
	Email    string
	Password string
	Metadata Metadata
}

type UserPage struct {
	PageMetadata
	Users []User
}

type UserRepository interface {
	Save(ctx context.Context, u User) (string, error)

	// SaveMany(ctx context.Context, us ...User) ([]User, error)

	// Update(ctx context.Context, u User) error

	// RetrieveByEmail(ctx context.Context, email string) (User, error)

	// RetrieveByID(ctx context.Context, id string) (User, error)

	// RetrieveAllByIDs(ctx context.Context, ids []string) ([]User, error)

	// RetrievePage(ctx context.Context, pm PageMetadata, params map[string]interface{}) (UserPage, error)

	Remove(ctx context.Context, id string) error
}
