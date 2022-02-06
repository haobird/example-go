package postgres

import (
	"github.com/jmoiron/sqlx"
	_ "github.com/lib/pq" // required for SQL access
	migrate "github.com/rubenv/sql-migrate"
)

func Connect(dsn string) (*sqlx.DB, error) {
	db, err := sqlx.Open("postgres", dsn)
	if err != nil {
		return nil, err
	}

	setupDB(db)

	// 验证连接
	if err := db.Ping(); err != nil {
		return nil, err
	}

	// 执行数据库初始化
	if err := migrateDB(db); err != nil {
		return nil, err
	}
	return db, nil
}

// 执行 数据库配置
func setupDB(db *sqlx.DB) {
	// 用于设置最大打开的连接数，默认值为0表示不限制.设置最大的连接数，可以避免并发太高导致连接mysql出现too many connections的错误。
	db.SetMaxOpenConns(50)
	// 用于设置数据库最大闲置连接数.设置闲置的连接数则当开启的一个连接使用完成后可以放在池里等候下一次使用。
	db.SetMaxIdleConns(10)
	//设置数据库限制一个连接使用的最大时长，默认值为0,表示不限制
	db.SetConnMaxLifetime(100)
}

// 数据库 数据初始化
func migrateDB(db *sqlx.DB) error {
	migrations := &migrate.MemoryMigrationSource{
		Migrations: []*migrate.Migration{
			{
				Id: "users_1",
				Up: []string{
					`CREATE TABLE IF NOT EXISTS users (
					 email    VARCHAR(254) PRIMARY KEY,
					 password CHAR(60)     NOT  NULL,
					 create_time timestamp default current_timestamp
					)`,
				},
				Down: []string{"DROP TABLE users"},
			},
			{
				Id: "users_2",
				Up: []string{
					`ALTER TABLE IF EXISTS users ADD COLUMN IF NOT EXISTS metadata JSONB`,
				},
			},
			{
				Id: "users_3",
				Up: []string{
					`CREATE EXTENSION IF NOT EXISTS "pgcrypto";
					 ALTER TABLE IF EXISTS users ADD COLUMN IF NOT EXISTS
					 id UUID NOT NULL DEFAULT gen_random_uuid()`,
				},
			},
			{
				Id: "users_4",
				Up: []string{
					`ALTER TABLE IF EXISTS users DROP CONSTRAINT users_pkey`,
					`ALTER TABLE IF EXISTS users ADD CONSTRAINT users_email_key UNIQUE (email)`,
					`ALTER TABLE IF EXISTS users ADD PRIMARY KEY (id)`,
				},
			},
		},
	}

	_, err := migrate.Exec(db.DB, "postgres", migrations, migrate.Up)
	return err
}
