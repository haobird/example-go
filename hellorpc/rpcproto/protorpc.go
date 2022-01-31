package rpcproto

import (
	"bytes"
	"encoding/json"
	"io"
	"log"
	"net"
)

type serverRequest struct {
	Method string           `json:"method"`
	Params *json.RawMessage `json:"params"`
	Id     *json.RawMessage `json:"id"`
}

type serverResponse struct {
	Id     *json.RawMessage `json:"id"`
	Result interface{}      `json:"result"`
	Error  interface{}      `json:"error"`
}

type Protorpc struct {
	Service interface{}
}

func (p Protorpc) handleConn(conn net.Conn) {
	defer conn.Close()

	var buf bytes.Buffer

	_, err := io.Copy(&buf, conn)
	if err != nil {
		// Error handler
		log.Fatalf("handleConn: %v\n", err)
		return
	}

}

func (p Protorpc) handle(buf []byte) {
	// 解码内容

	// 执行 call
}

func ListenAndService(addr string, s interface{}) {
	lis, err := net.Listen("tcp", addr)
	if err != nil {
		log.Fatal(err)
	}
	defer lis.Close()

	proto := Protorpc{Service: s}

	for {
		conn, err := lis.Accept()
		if err != nil {
			log.Fatalf("lis.Accept(): %v\n", err)
		}
		go proto.handleConn(conn)
	}
}
