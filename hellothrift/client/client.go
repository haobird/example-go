package main

import (
	"fmt"
	"log"
	"net"

	"github.com/apache/thrift/lib/go/thrift"
	"github.com/haobird/learngo/hellothrift/message"
)

const (
	HOST = "localhost"
	PORT = "8085"
)

func main() {
	tSocket, err := thrift.NewTSocket(net.JoinHostPort(HOST, PORT))
	if err != nil {
		log.Fatalln("tSocket error:", err)
	}

	// 创建 数据 传输方式 工厂
	transportFactory := thrift.NewTFramedTransportFactory(thrift.NewTTransportFactory())
	//
	transport := transportFactory.GetTransport(tSocket)
	// 创建 传输协议 工厂
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()

	client := message.NewFormatDataClientFactory(transport, protocolFactory)

	if err := transport.Open(); err != nil {
		log.Fatalln("Error opening:", HOST+":"+PORT)
	}
	defer transport.Close()

	data := message.Data{Text: "hello, world!"}
	d, err := client.DoFormat(&data)
	fmt.Println(d.Text)
}
