package main

import (
	"encoding/base64"
	"encoding/json"
	"fmt"

	"go.uber.org/zap"
)

type MyStruct struct {
	Name string
	Age  int
	Data []byte
}

var logger *zap.Logger

func main() {
	logger = zap.NewExample()
	defer logger.Sync()
	// logger.Info("hello world")

	buf := []byte("some data")
	fmt.Println(buf)

	data := MyStruct{
		Name: "John",
		Age:  30,
		Data: buf,
	}

	// logger.Info("data", zap.Reflect("data", data))
	logger.Info("heloo", zap.Any("data", data))

	str := base64.StdEncoding.EncodeToString(buf)
	fmt.Println(str)
	buf2, err := base64.StdEncoding.DecodeString(str)
	fmt.Println(buf2, err)

	buf3, err := json.Marshal(data)
	fmt.Println(string(buf3), err)
}
