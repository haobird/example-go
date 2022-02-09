package main

import (
	"helloresty/y2t"
	"strings"

	"github.com/langbox/logger"
)

var (
	po = "FBA603G58004SZ1"

	order = y2t.Order{
		OrderNo:            "FBA603G58004SZ1",
		SubmitOrderNo:      "B211046577",
		SubmitOrderUuid:    "e443db4e-e4a8-4bca-9623-b42b3eb86dac",
		OfficeCode:         "SZWLC",
		OfficeCodeName:     "平湖物流中心（深圳）",
		AgentConsigneeCode: "11142",
	}
)

func main() {
	// 获取 po 搜索结果
	// data, err := y2t.PoSearch(po)
	// logger.Infof("posearch result err: %v, data: %v", err, data)
	// 组合 refer
	// refer := y2t.CreateReservationReferer(order)
	// fmt.Println(refer)
	// y2t.GetLatestRevByPo(order, "2022-02-09", true)

	// 提交 订单

	// 发送消息
	// y2t.PushMsg("hah", "ddd")

	start()

}

func start() {
	// 如果获取 订单信息 三次，则 直接打印 通知错误

	// 获取 po 搜索结果
	data, err := y2t.PoSearch(po)
	logger.Infof("posearch result err: %v, data: %v", err, data)
	if err != nil {
		logger.Fatalf("未获取到该PO：%s的信息", po)
	}

	// 获取到 PO信息后， 定时 获取 数据， 直到 获得结果，进行通知并退出
	err = update(data)
	if err != nil {
		logger.Errorf("update err: %v", err)
	}

	// for {
	// 	select {
	// 	case <-time.After(time.Minute * time.Duration(10)):
	// 		err := update(data)
	// 		if err != nil {
	// 			logger.Errorf("update err: %w", err)
	// 		}
	// 	}
	// }

}

// 刷新
func update(data y2t.Order) error {
	// 查询 可预约的数据
	arr, err := y2t.GetLatestRevByPo(data, "", false)
	if err != nil {
		return nil
	}

	if len(arr) < 1 {
		logger.Info("未查询到可预约数据")
		return nil
	}

	// 组合 文案提示
	var dateArr []string
	for _, val := range arr {
		dateArr = append(dateArr, val.ForecastDate)
	}

	// 发送提示
	err = y2t.PushMsg("可预约提示", strings.Join(dateArr, ","))

	return err
}
