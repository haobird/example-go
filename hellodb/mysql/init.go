package mysql

import "database/sql"

func Connect(dsn string) (*sql.DB, error) {
	db, err := sql.Open("mysql", dsn)
	if err != nil {
		return nil, err
	}

	setupDB(db)

	// 验证连接
	if err := db.Ping(); err != nil {
		return nil, err
	}

	// 执行数据库初始化
	migrateDB(db)

	return db, nil
}

// 执行 数据库配置
func setupDB(db *sql.DB) {
	// 用于设置最大打开的连接数，默认值为0表示不限制.设置最大的连接数，可以避免并发太高导致连接mysql出现too many connections的错误。
	db.SetMaxOpenConns(50)
	// 用于设置数据库最大闲置连接数.设置闲置的连接数则当开启的一个连接使用完成后可以放在池里等候下一次使用。
	db.SetMaxIdleConns(10)
	//设置数据库限制一个连接使用的最大时长，默认值为0,表示不限制
	db.SetConnMaxLifetime(100)
}

// 数据库 数据初始化
func migrateDB(db *sql.DB) error {

	return nil
}
