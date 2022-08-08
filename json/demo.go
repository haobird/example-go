package main

import (
	"encoding/json"
	"fmt"
)

type Person struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

func main() {
	p := Person{
		Name: "a",
		Age:  18,
	}

	buf, _ := json.Marshal(p)
	str := string(buf)
	fmt.Println(buf)
	fmt.Println(str)
	fmt.Println("len : ", len(str))
	for k, i := range buf {
		fmt.Println(k, "--", i, "--", string(i))
	}

}
