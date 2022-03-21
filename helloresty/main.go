package main

import (
	"errors"
	"fmt"
	"helloresty/y2t"
	"strings"
	"time"

	"github.com/langbox/logger"
	"github.com/spf13/viper"
)

var (
	po1 = "FBA603G74750SZ1"

	order = y2t.Order{
		OrderNo:            "FBA603G58004SZ1",
		SubmitOrderNo:      "B211046577",
		SubmitOrderUuid:    "e443db4e-e4a8-4bca-9623-b42b3eb86dac",
		OfficeCode:         "SZWLC",
		OfficeCodeName:     "平湖物流中心（深圳）",
		AgentConsigneeCode: "11142",
	}

	headers = map[string]string{
		"User-Agent":   "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.57 Safari/537.36 OPR/40.0.2308.15 (Edition beta)",
		"Content-Type": "application/json;charset=UTF-8",
	}
)

var (
	confPath   = "config.yaml"
	autoSubmit = 0
	interval   = 5
	proxy      = ""
	po         = "FBA603G58004SZ1"
	dates      = []string{}
	uid        = "q2QTksYhGyYm7A7UDVnTaY"
)

func main() {
	// 加载日志文件
	viper.SetConfigFile(confPath) // 如果指定了配置文件，则解析指定的配置文件
	viper.AutomaticEnv()          // 读取匹配的环境变量
	viper.SetEnvPrefix("APP")     // 读取环境变量的前缀为APISERVER
	replacer := strings.NewReplacer(".", "_")
	viper.SetEnvKeyReplacer(replacer)
	if err := viper.ReadInConfig(); err != nil { // viper解析配置文件
		panic(fmt.Errorf("Fatal error config file: %w \n", err))
	}

	// 设置日志
	logger.InitWithConfig(&logger.Cfg{
		Level:      viper.GetString("log.level"),
		Writers:    viper.GetString("log.writers"),
		File:       viper.GetString("log.file"),
		FormatText: true,
	})

	// 配置更新
	dates = viper.GetStringSlice("book.assign_dates")
	// po = viper.GetString("book.po")
	// fmt.Println(po)
	autoSubmit = viper.GetInt("book.auto_submit")
	uid = viper.GetString("notify.uid")
	// 根据 配置 提示
	str := "你选择了,"
	strArr := []string{}
	strArr = append(strArr, fmt.Sprintf("po: %s", po))
	strArr = append(strArr, fmt.Sprintf("%d 分钟查询一次", interval))
	if autoSubmit == 0 {
		strArr = append(strArr, "不自动提交预约")
	} else {
		strArr = append(strArr, "自动提交预约")
	}
	strArr = append(strArr, fmt.Sprintf("自动提交日期为 %d个, %v", len(dates), dates))

	logger.Info(str, strings.Join(strArr, ";"))

	start()
}

func start() {
	// 如果获取 订单信息 三次，则 直接打印 通知错误

	// 获取 po 搜索结果
	data, err := y2t.PoSearch(po)
	logger.Debugf("posearch result err: %v, data: %v", err, data)
	if err != nil {
		logger.Fatalf("未获取到该PO：%s的信息", po)
	}

	// 获取到 PO信息后， 定时 获取 数据， 直到 获得结果，进行通知并退出
	err = update(data)
	if err != nil {
		logger.Errorf("update err: %v", err)
	}

	for {
		select {
		case <-time.After(time.Minute * time.Duration(10)):
			err := update(data)
			if err != nil {
				logger.Errorf("update err: %w, %d分钟后再次刷新", err, interval)
			}
		}
	}

}

// 刷新
func update(order y2t.Order) error {
	// 查询 可预约的数据
	arr, err := y2t.GetLatestRevByPo(order, "", false)
	if err != nil {
		return nil
	}

	if len(arr) < 1 {
		logger.Info("未查询到可预约数据,等待再次刷新")
		return nil
	}

	// 组合 文案提示
	dateFlag := false
	dateKey := 0
	var dateArr []string
	for key, val := range arr {
		date := val.ForecastDate
		if !dateFlag && y2t.IsValueInList(date, dates) {
			dateFlag = true
			dateKey = key
		}
		dateArr = append(dateArr, date)
	}

	// 预约提示
	noticeStr := fmt.Sprintf("可预约日期：%v", strings.Join(dateArr, ","))
	noticeStrExt := ""
	if dateFlag {
		noticeStrExt = fmt.Sprintf("自动提交日期为:%s; ", arr[dateKey].ForecastDate)
	} else if len(dates) > 0 {
		autoSubmit = 0
		noticeStrExt = fmt.Sprintf("未匹配到指定日期; 当前%s", noticeStr)
		return errors.New(noticeStrExt)
	} else {
		noticeStrExt = fmt.Sprintf("未指定日期，默认提交日期:%s; ", arr[dateKey].ForecastDate)
	}
	noticeStr = noticeStrExt + noticeStr

	// 发送提示
	err = y2t.PushMsg(uid, "预约提示", noticeStr)

	if autoSubmit == 0 {
		logger.Fatal("自动提交关闭，因此不会自动预约")
		return nil
	}

	// 自动提交
	// 获取 订单详情
	detail, err := y2t.PoDetail(order)
	logger.Debugf("[PoDetail]获取信息详情 err:%v, 结果: %v\n", err, detail)
	if err != nil {
		return err
	}

	// 判断是否已经预约，如果已经预约，则直接 通知并 退出
	if y2t.HasSaved(detail.ForecastOrderModel) {
		str := fmt.Sprintf("该%s已经被预约的", order.OrderNo)
		y2t.PushMsg(uid, "预约提示", str)
		logger.Fatal(str)
	}

	// 提交 预约
	err = y2t.SaveReservation(order, detail, arr[dateKey])
	if err == nil {
		// 提示 预约成功
		y2t.PushMsg(uid, "预约提示", "预约成功")
	}

	return err
}
