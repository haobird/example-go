package main

import (
	"hellolog/logger"
)

func main() {
	// cfg := &logger.Cfg{
	// 	Level:        "DEBUG",           // 日志输出级别
	// 	File:         "log/chassis.log", // 日志文件路径
	// 	RotatePolicy: "size",            // 切割策略： size/daily/time
	// 	RotateTime:   24,                // 分割日期(单位 小时)
	// 	RotateSize:   100,               // 分割大小(单位 M)
	// 	MaxBackup:    7,                 // 备份文件数目
	// 	MaxAge:       30,                // 文件有效期(单位 天)
	// 	FormatText:   false,             // 日志格式
	// 	FormatColor:  false,             // 强制彩色
	// 	FormatReport: false,             // 是否显示 calling method
	// }

	// log, err := logger.InitWithConfig(cfg)
	// fmt.Println(err)
	// helper.Print("jj")
	// logger.Logger.Info("ddd")
	// log.Debugf("hello %s", "log")
	// log.Errorf("ddd%d", 11)
	// logrus.Info("ddd")
	logger.Debug("ddd")
}
