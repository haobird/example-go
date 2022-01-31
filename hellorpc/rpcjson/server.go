package main

import (
	"log"
	"net"
	"net/rpc"
	"net/rpc/jsonrpc"
)

type Echo int

func (t *Echo) Hi(args string, reply *string) error {
	*reply = "echo:" + args
	return nil
}

func main() {
	lis, err := net.Listen("tcp", ":1234")
	if err != nil {
		log.Fatal(err)
	}
	defer lis.Close()

	srv := rpc.NewServer()
	if err := srv.RegisterName("Echo", new(Echo)); err != nil {
		log.Fatal(err)
	}

	for {
		conn, err := lis.Accept()
		if err != nil {
			log.Fatalf("lis.Accept(): %v\n", err)
		}
		go srv.ServeCodec(jsonrpc.NewServerCodec(conn))
	}
}
