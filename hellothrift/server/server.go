package main

import (
	"fmt"
	"log"
	"strings"

	"github.com/apache/thrift/lib/go/thrift"
	"github.com/haobird/learngo/hellothrift/message"
)

type FormatDataImpl struct{}

func (fdi *FormatDataImpl) DoFormat(data *message.Data) (r *message.Data, err error) {
	var rData message.Data
	rData.Text = strings.ToUpper(data.Text)
	return &rData, nil
}

type MsgImpl struct{}

func (mi *MsgImpl) Query(req *message.Req) (*message.Resp, error) {
	var resp message.Resp
	resp.Code = 0
	resp.Message = strings.ToUpper(req.Query)
	return &resp, nil
}

const (
	HOST = "0.0.0.0"
	PORT = "8085"
)

func main() {
	// 创建 业务 代码
	handler := &FormatDataImpl{}
	// 注入 服务端 处理 输入输出 服务
	processor := message.NewFormatDataProcessor(handler)
	// 建立 监听服务端口
	serverTransport, err := thrift.NewTServerSocket(HOST + ":" + PORT)
	if err != nil {
		log.Fatalln("Error:", err)
	}

	// 创建 数据传输方式 工厂
	transportFactory := thrift.NewTFramedTransportFactory(thrift.NewTTransportFactory())
	// 创建 传输协议 工厂
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()

	// 创建 服务
	server := thrift.NewTSimpleServer4(processor, serverTransport, transportFactory, protocolFactory)

	fmt.Println("Running at:", HOST+":"+PORT)
	server.Serve()

}
