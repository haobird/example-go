package mongodb

import (
	"context"
	"time"

	"github.com/langbox/logger"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

// Connect creates a connection to the MongoDB instance
func Connect(uri, name string) (*mongo.Database, error) {
	// addr := fmt.Sprintf("mongodb://%s:%s", cfg.Host, cfg.Port)
	// credential := options.Credential{
	// 	Username: cfg.User,
	// 	Password: cfg.Pass,
	// }
	// clientOpts := options.Client().ApplyURI(addr).SetAuth(credential)
	opts := options.Client().ApplyURI(uri)
	client, err := mongo.Connect(context.Background(), opts)
	if err != nil {
		// logger.Error(fmt.Sprintf("Failed to connect to database: %s", err))
		return nil, err
	}
	db := client.Database(name)
	// 如果是 增加索引的错误，则忽略不处理
	if err := migrateDB(db); err != nil {
		return nil, err
	}

	return db, nil
}

func migrateDB(db *mongo.Database) error {
	// err := db.CreateCollection(context.TODO(), messageCollection)
	// if err != nil {
	// 	logger.Errorf("Failed to create collection: %s", err)
	// 	return err
	// }
	coll := db.Collection("user")
	opts := options.CreateIndexes().SetMaxTime(10 * time.Second)
	indexView := coll.Indexes()
	models := []mongo.IndexModel{
		{
			Keys:    bson.M{"id": 1},
			Options: options.Index().SetUnique(true),
		},
		{
			Keys: bson.M{"email": 1},
		},
		{
			Keys: bson.M{"metadata": 1},
		},
		{
			Keys: bson.M{"timestamp": 1},
		},
		{
			Keys:    bson.D{{Key: "create_time", Value: 1}},
			Options: options.Index().SetExpireAfterSeconds(180 * 24 * 3600), // 180天自动删除
		},
	}

	names, err := indexView.CreateMany(
		context.Background(),
		models,
		opts,
	)
	logger.Infof("created indexes %v : %v\n", names, err)
	return err
}
