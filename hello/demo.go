package main

import (
	"fmt"

	"github.com/langbox/signature"
)

func main() {
	fmt.Println(string(signature.Hash("dd")))
}
