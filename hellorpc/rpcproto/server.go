package main

import "github.com/haobird/learngo/hellorpc/simujson"

type Echo int

func (t *Echo) Hi(args string, reply *string) error {
	*reply = "echo:" + args
	return nil
}

func main() {
	simujson.ListenAndService(":1234", new(Echo))
}
