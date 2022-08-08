package main

import "fmt"

type Person struct {
	Name string
	Age  int
}

func main() {
	fmt.Println("ddd")
	p1 := Person{Name: "John", Age: 30}
	p2 := Person{Name: "Jane", Age: 25}

	list := []*Person{&p1, &p2}
}
