package main

import (
	"errors"
	"fmt"
	"time"
)

func main() {
	var code int = 0
	var err error
	ch := make(chan string, 1)

	go fetch(ch)

	select {
	case msg := <-ch:
		fmt.Println("data from channel ", msg)
		err = errors.New(msg)
	// 如果把这个注释掉，则会阻塞 deadlock
	case <-time.After(10 * time.Second):
		fmt.Println("TimeOut")
		err = errors.New("响应超时TimeOut")
		code = 3
	}
	fmt.Printf("code: %d, err: %s", code, err)
}

func fetch(ch chan<- string) {
	// do stuff
}
