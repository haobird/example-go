package main

import (
	"fmt"
	"strings"

	"github.com/davecgh/go-spew/spew"
	"github.com/thoas/go-funk"
)

type Foo struct {
	ID        int
	FirstName string `tag_name:"tag 1"`
	LastName  string `tag_name:"tag 2"`
	Age       int    `tag_name:"tag 3"`
}

func (f Foo) TableName() string {
	return "foo"
}

var (
	f = &Foo{
		ID:        1,
		FirstName: "Foo",
		LastName:  "Bar",
		Age:       30,
	}
)

func main() {
	flag := funk.Contains([]string{"foo", "bar"}, "bar")
	fmt.Printf("%v\n", flag)
	spew.Dump(flag)

	// 交集
	result := funk.Intersect([]int{1, 2, 3}, []int{2, 3, 4})
	fmt.Printf("%v\n", result)

	// 差集
	result1, result2 := funk.Difference([]int{1, 2, 3}, []int{2, 3, 4})
	fmt.Printf("%v, %v\n", result1, result2)

	// 获取索引
	result3 := funk.IndexOf([]int{1, 2, 3}, 2)
	fmt.Printf("%v\n", result3)

	// 根据某个字段获取数组
	// f := &Foo{
	// 	ID:        1,
	// 	FirstName: "Gilles",
	// 	LastName:  "Fabio",
	// 	Age:       70,
	// }

	// b := &Foo{
	// 	ID:        2,
	// 	FirstName: "Florent",
	// 	LastName:  "Messa",
	// 	Age:       80,
	// }

	// results := []*Foo{f, b}

	// mapping := funk.ToMap(results, "ID") // map[int]*Foo{1: f, 2: b}
	// spew.Dump(mapping)

	f := Foo{
		ID:        1,
		FirstName: "Gilles",
		LastName:  "Fabio",
		Age:       70,
	}

	b := Foo{
		ID:        2,
		FirstName: "Florent",
		LastName:  "Messa",
		Age:       80,
	}

	mapping := funk.ToSet([]Foo{f, b}) // map[Foo]stuct{}{f: struct{}{}, b: struct{}{}}
	spew.Dump(mapping)

	mapping = funk.ToSet([5]int{1, 1, 2, 2, 4}) // map[int]struct{}{1: struct{}{}, 2: struct{}{}}
	spew.Dump(mapping)

	// filter
	r := funk.Filter([]int{1, 2, 3, 4}, func(x int) bool {
		return x%2 == 0
	}) // []int{2, 4}
	spew.Dump(r)

	r = funk.Filter([]string{"hello", "lodash", "myname"}, func(x string) bool {
		return strings.Contains(x, "lo")
	}) // []int{2, 4}
	spew.Dump(r)

	//
	p := funk.Reduce([]int{1, 2, 3, 4}, '+', float64(2)) // 10
	spew.Dump(p)

	q := funk.Find([]int{1, 3, 4}, func(x int) bool {
		return x%2 == 0
	}) // 2
	spew.Dump(q)

	s := funk.Values(map[string]int{"one": 1, "two": 2, "three": 2}) // []int{1, 2, 3}
	spew.Dump(s)

}
