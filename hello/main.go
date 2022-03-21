package main

import "github.com/davecgh/go-spew/spew"

type Person struct {
	Id     int64
	Name   string
	Age    int
	Online bool
}

func main() {
	list := map[int64]Person{
		11: {
			Id:   11,
			Name: "张三",
			Age:  20,
		},
		2: {
			Id:   2,
			Name: "李四",
			Age:  18,
		},
		1: {
			Id:   1,
			Name: "test",
			Age:  18,
		},
	}

	res := map[int64]Person{
		11: {
			Id:     11,
			Name:   "张三",
			Age:    20,
			Online: true,
		},
		2: {
			Id:     2,
			Name:   "李四",
			Age:    18,
			Online: false,
		},
		3: {
			Id:     3,
			Name:   "hhh",
			Age:    18,
			Online: false,
		},
	}

	newStatus := make(map[int64]int64)

	// 循环 res
	for _, val := range res {
		if local, ok := list[val.Id]; ok {
			delete(list, val.Id)
			if val.Online {
				newStatus[local.Id] = 0
			} else {
				newStatus[local.Id] = 1
			}
		}
	}

	spew.Dump(list)
}
