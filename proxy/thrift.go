package main

import (
	"context"
	"fmt"
	"log"
	"time"

	"github.com/apache/thrift/lib/go/thrift"
	"github.com/haobird/learngo/hellothrift/message"
	"golang.org/x/net/proxy"
)

func main() {
	dialer, err := proxy.SOCKS5("tcp", "127.0.0.1:10800", nil, proxy.Direct)
	if err != nil {
		log.Fatalf("Socks5 dialer initialization failed: %v", err)
	}

	conn, err := dialer.Dial("tcp", "127.0.0.1:8085")
	if err != nil {
		log.Fatalf("conn dialer initialization failed: %v", err)
	}

	tfconf := &thrift.TConfiguration{
		ConnectTimeout: 5 * time.Minute,
		SocketTimeout:  5 * time.Minute,
	}

	tSocket := thrift.NewTSocketFromConnConf(conn, tfconf)

	// 创建 数据 传输方式 工厂
	transportFactory := thrift.NewTFramedTransportFactory(thrift.NewTTransportFactory())
	//
	transport, _ := transportFactory.GetTransport(tSocket)
	// 创建 传输协议 工厂
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()

	client := message.NewFormatDataClientFactory(transport, protocolFactory)

	// if err := transport.Open(); err != nil {
	// 	log.Fatalln("Error opening:")
	// }
	defer transport.Close()

	ctx := context.Background()
	data := message.Data{Text: "hello, world!"}
	d, err := client.DoFormat(ctx, &data)
	fmt.Println(d.Text)
}
