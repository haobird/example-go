package main

import (
	"fmt"
	"helloresty/y2t"
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
	refer := y2t.CreateReservationReferer(order)
	fmt.Println(refer)
}
