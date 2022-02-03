package main

import (
	"context"
	"fmt"
	"log"
	"net"
	"time"

	"github.com/apache/thrift/lib/go/thrift"
	"github.com/haobird/learngo/hellothrift/miot_share"
	"github.com/haobird/learngo/hellothrift/miot_user_scene"
	"github.com/haobird/learngo/hellothrift/xiaoai_skill"
)

const (
	HOST = "10.38.160.40"
	PORT = "26060"
)

func main() {
	test()
}

func test() {
	tSocket, err := thrift.NewTSocket(net.JoinHostPort("10.38.167.69", "8118"))
	if err != nil {
		log.Fatalln("tSocket error:", err)
	}

	// 创建 数据 传输方式 工厂
	transportFactory := thrift.NewTFramedTransportFactory(thrift.NewTTransportFactory())
	// transportFactory := thrift.NewTBufferedTransportFactory(8192)
	// 创建 传输协议 工厂
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()
	//
	transport, _ := transportFactory.GetTransport(tSocket)
	if err := transport.Open(); err != nil {
		log.Fatalln("Error opening:", HOST+":"+PORT)
	}
	defer transport.Close()

	client := xiaoai_skill.NewPersonalizeServiceClientFactory(transport, protocolFactory)

	ctx := context.Background()
	res, err := client.GetSkillsForBiz(ctx, 2202005434, "", "", 0, 0)
	fmt.Printf("%+v", res)
	fmt.Println(err)

}

func testNew() {
	conf := &thrift.TConfiguration{
		ConnectTimeout: time.Second,
		SocketTimeout:  time.Second,

		MaxFrameSize: 1024 * 1024 * 256,

		TBinaryStrictRead:  thrift.BoolPtr(true),
		TBinaryStrictWrite: thrift.BoolPtr(true),
	}

	tSocket := thrift.NewTSocketConf(net.JoinHostPort(HOST, PORT), conf)
	transportFactory := thrift.NewTFramedTransportFactoryConf(thrift.NewTTransportFactory(), conf)
	protocolFactory := thrift.NewTBinaryProtocolFactoryConf(conf)

	transport, _ := transportFactory.GetTransport(tSocket)

	client := miot_user_scene.NewUserSceneServiceClientFactory(transport, protocolFactory)
	if err := transport.Open(); err != nil {
		log.Fatalln("Error opening:", HOST+":"+PORT)
	}
	defer transport.Close()

	data := miot_user_scene.NewSceneListReq()
	header := miot_share.NewMiotCommonReqHeader()
	traceId := fmt.Sprintf("tob_rpc_%d", time.Now().UnixNano()/1e6)
	header.ClientName = "tob_test"
	header.TraceId = traceId

	data.Header = header
	data.UID = 2202005434
	stID := int64(30)

	data.StID = &stID
	data.Limit = 10000

	ctx := context.Background()
	res, err := client.GetUserSceneList(ctx, data)
	fmt.Printf("%+v", res)
	fmt.Println(err)

}

func testOld() {
	tSocket, err := thrift.NewTSocket(net.JoinHostPort(HOST, PORT))
	if err != nil {
		log.Fatalln("tSocket error:", err)
	}

	// 创建 数据 传输方式 工厂
	// transportFactory := thrift.NewTFramedTransportFactory(thrift.NewTTransportFactory())
	transportFactory := thrift.NewTBufferedTransportFactory(8192)
	//
	transport, _ := transportFactory.GetTransport(tSocket)
	// 创建 传输协议 工厂
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()

	client := miot_user_scene.NewUserSceneServiceClientFactory(transport, protocolFactory)
	if err := transport.Open(); err != nil {
		log.Fatalln("Error opening:", HOST+":"+PORT)
	}
	defer transport.Close()

	data := miot_user_scene.NewSceneListReq()
	header := miot_share.NewMiotCommonReqHeader()
	traceId := fmt.Sprintf("tob_rpc_%d", time.Now().UnixNano()/1e6)
	header.ClientName = "tob_test"
	header.TraceId = traceId

	data.Header = header
	data.UID = 2202005434
	stID := int64(30)

	data.StID = &stID
	data.Limit = 10000

	ctx := context.Background()
	res, err := client.GetUserSceneList(ctx, data)
	fmt.Printf("%+v", res)
	fmt.Println(err)
}
