package simujson

import (
	"bytes"
	"encoding/json"
	"io"
	"log"
	"net"
	"reflect"
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

type ProtoServer struct {
	Service interface{}
}

func (p ProtoServer) handleConn(conn net.Conn) {
	defer conn.Close()

	var buf bytes.Buffer

	_, err := io.Copy(&buf, conn)
	if err != nil {
		// Error handler
		log.Fatalf("handleConn: %v\n", err)
		return
	}

}

func (p ProtoServer) handle(buf []byte) {
	// 解码格式
	var req serverRequest
	err := json.Unmarshal(buf, &req)
	if err != nil {
		// Error handler
		log.Fatalf("handle: %v\n", err)
		return
	}

	method := req.Method

	// 处理调用
	getType := reflect.TypeOf(p.Service)
	met, ok := getType.MethodByName(method)
	if !ok {
		panic("method not exist.")
	}
	met.Func.Call([]reflect.Value{reflect.ValueOf(req.Params)})
}

func ListenAndService(addr string, s interface{}) {
	lis, err := net.Listen("tcp", addr)
	if err != nil {
		log.Fatal(err)
	}
	defer lis.Close()
	log.Printf("listen: %v\n", addr)

	proto := ProtoServer{Service: s}

	for {
		conn, err := lis.Accept()
		if err != nil {
			log.Fatalf("lis.Accept(): %v\n", err)
		}
		go proto.handleConn(conn)
	}
}

type ProtoClient struct {
	Conn net.Conn
}

func Dial(addr string) (ProtoClient, error) {
	var client ProtoClient
	conn, err := net.Dial("tcp", addr)
	if err != nil {
		log.Fatalf("lis.Accept(): %v\n", err)
		return client, err
	}
	client = ProtoClient{Conn: conn}
	return client, err
}

func (p ProtoClient) Call(serviceMethod string, args interface{}, reply interface{}) error {
	var request = serverRequest{
		Method: serviceMethod,
		Params: args,
		Id:     0,
	}
}
