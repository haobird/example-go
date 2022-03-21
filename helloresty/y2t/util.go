package y2t

import (
	"encoding/json"
	"errors"
	"fmt"

	"github.com/go-resty/resty/v2"
	"github.com/langbox/logger"
)

type MsgResult struct {
	Code      int    `json:"code"`
	Message   string `json:"message"`
	Timestamp int    `json:"timestamp"`
}

// 通知
func PushMsg(uid, title, content string) error {
	// uid := "q2QTksYhGyYm7A7UDVnTaY"
	prev := "https://api.day.app"
	path := fmt.Sprintf("%s/%s/%s/%s", prev, uid, title, content)
	logger.Infof("通知消息 %s", path)
	resp, err := resty.New().R().EnableTrace().Get(path)
	if err != nil {
		// logger.Errorf("发送消息错误%v", err)
		return err
	}

	var result MsgResult
	json.Unmarshal([]byte(resp.Body()), &result)

	if result.Code != 200 {
		return errors.New(result.Message)
	}

	return nil
}

func IsValueInList(value string, list []string) bool {
	for _, v := range list {
		if v == value {
			return true
		}
	}
	return false
}
