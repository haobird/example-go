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
	ID       string `json:"id"`
	Email    string `json:"email"`
	Password string `json:"password"`
	// Metadata   Metadata `json:"metadata"`
	CreateTime time.Time
}

type UserPage struct {
	PageMetadata
	Users []User
}

type UserRepository interface {
	// 保存一个 返回 索引
	Save(ctx context.Context, u User) (User, error)
	// 保存多个 返回 对象列表
	SaveMany(ctx context.Context, us ...User) (int64, error)
	// 更新 指定索引的一个 对象
	// Update(ctx context.Context, u User) error

	// UpdateMany(ctx context.Context, )
	// 通过 email 获取 一个 用户
	// RetrieveByEmail(ctx context.Context, email string) (User, error)
	// 通过ID 获取 一个 用户
	RetrieveByID(ctx context.Context, id string) (User, error)
	RetrieveByEmail(ctx context.Context, id string) (User, error)
	RetrieveByIDs(ctx context.Context, ids []string) ([]User, error)
	// 过滤条件下 获取 所有
	RetrieveAll(ctx context.Context, clause map[string]interface{}) ([]User, error)
	// 通过 ID 获取 所有
	// RetrieveAllByIDs(ctx context.Context, ids []string) ([]User, error)
	// 过滤条件下 获取分页数据
	// RetrievePage(ctx context.Context, pm PageMetadata, clause map[string]interface{}) (UserPage, error)
	// 过滤条件下 删除所有数据 并返回 删除 数量
	// Remove(ctx context.Context, clause map[string]interface{}) (int64, error)
	// 通过ID 删除 用户
	// RemoveByID(ctx context.Context, id string) error
}
