package y2t

import (
	"encoding/json"
	"errors"
	"fmt"
	"log"
	"net/http"
	"time"

	"github.com/go-resty/resty/v2"
	"github.com/langbox/logger"
)

const (
	ContentType = "application/json;charset=UTF-8"
	BaseURI     = "https://icop.y2t.com/os"
)

var (
	headers = map[string]string{
		"User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.57 Safari/537.36 OPR/40.0.2308.15 (Edition beta)",
	}
)

// 查询 单号 是否存在
func PoSearch(po string) (Order, error) {
	headers["Content-Type"] = ContentType
	headers["Origin"] = origin_url
	headers["Referer"] = posearch_referer_url

	url := BaseURI + posearch_url
	jsonStr := `{
		"parameter": {
            "controlWord": "I",
            "orderNo": "%s"
        }
	}`
	body := fmt.Sprintf(jsonStr, po)

	client := resty.New()
	request := client.R()
	request = request.EnableTrace()
	request = request.SetHeaders(headers)
	request = request.SetBody(body)
	request = request.SetHeaders(headers)
	resp, err := request.Post(url)
	// fmt.Println("err:", err)
	// spew.Dump(resp)

	logger.Infof("[%s] 获取PO信息 err: %v, 结果: %s", Mod_PoSearch, err, resp)

	var info Order
	if err != nil {
		return info, err
	}

	var result Result
	err = json.Unmarshal(resp.Body(), &result)
	if err != nil {
		return info, err
	}

	if result.Status != "1" {
		return info, errors.New(result.ErrorMsg)
	}

	var infos []Order
	buf, _ := json.Marshal(result.Data)
	err = json.Unmarshal(buf, &infos)
	if err != nil {
		return info, err
	}
	info = infos[0]
	return info, nil
}

// 获取 最新 预约时间 （一般是传入当前时间查询近15天的的预约时间）
func GetLatestRevByPo(data Order, date string, flag bool) ([]Reservation, error) {
	var infos []Reservation

	// 组合 referer url
	referer := CreateReservationReferer(data)

	// 组合 请求 参数
	headers["Content-Type"] = ContentType
	headers["Origin"] = origin_url
	headers["Referer"] = referer

	if date == "" {
		date = time.Now().Format("2006-01-02")
	}

	// 获取 可以 预约的 日期
	url := BaseURI + potimeres_url
	jsonStr := `{
        "parameter": {
            "startDate": "%s",
            "controlWord": "I",
            "officeCode": "%s",
            "customerCode": "%s"
        }
    }`
	body := fmt.Sprintf(jsonStr, date, data.OfficeCode, data.AgentConsigneeCode)

	client := resty.New()
	request := client.R()
	request = request.EnableTrace()
	request = request.SetHeaders(headers)
	request = request.SetBody(body)
	resp, err := request.Post(url)

	// logger.Infof("[%s] 获取可预约日期 err: %v, 结果: %s", Mod_GetLatestRevByPo, err, resp)

	var result Result
	err = json.Unmarshal(resp.Body(), &result)
	if err != nil {
		logger.Errorf("[%s] 解析 响应数据错误 err:%v", Mod_GetLatestRevByPo, err)
		return infos, err
	}

	if result.Status != "0" {
		logger.Errorf("[%s] 获得响应结果错误提示 :%v", Mod_GetLatestRevByPo, result.ErrorMsg)
		return infos, err
	}

	buf, _ := json.Marshal(result.Data)
	err = json.Unmarshal(buf, &infos)
	if err != nil {
		logger.Errorf("[%s] 获得响应结果 解析数据错误 :%v", Mod_GetLatestRevByPo, result.ErrorMsg)
		return infos, err
	}

	// 判断 是否有 可预约的日期
	if len(infos) < 1 {
		logger.Errorf("[%s] 获得响应结果 没有可预约的时间段", Mod_GetLatestRevByPo)
		return infos, err
	}

	// 是否继续获取剩余数量
	if !flag {
		return infos, err
	}

	// 获取 剩余的 仓库 数量
	url = BaseURI + potimeresnum_url
	payload := map[string]interface{}{
		"reservationNumList": result.Data,
	}
	buf, err = json.Marshal(payload)
	if err != nil {
		logger.Errorf("[%s] 生成 获取剩余可预约数量的 方法错误: %v", Mod_GetLatestRevByPo, err)
		return infos, err
	}

	request = request.SetBody(string(buf))
	resp, err = request.Post(url)

	// logger.Infof("[%s] 获取可预约数量 err: %v, 结果: %s", Mod_GetLatestRevByPo, err, resp)
	return infos, err
}

// 提交 预约 订单
func SaveReservation() {

}

// 生成
func CreateReservationReferer(data Order) string {
	url := BaseURI + tourists_reservation_url
	buf, _ := json.Marshal(data)
	var values map[string]string
	json.Unmarshal(buf, &values)

	return combineURL(url, values)
}

// 合并 参数 和 URL
func combineURL(url string, values map[string]string) string {
	req, err := http.NewRequest("GET", url, nil)
	if err != nil {
		log.Fatalf("Error Occurred. %+v", err)
	}

	q := req.URL.Query()
	for key, val := range values {
		q.Add(key, val)
	}
	req.URL.RawQuery = q.Encode()

	str := req.URL.String()

	fmt.Println(str)

	return str
}

// 发起请求 和响应
func Request(url string, body interface{}, headers map[string]string) (interface{}, error) {
	client := resty.New()
	request := client.R()
	request = request.EnableTrace()
	request = request.SetHeaders(headers)
	request = request.SetBody(body)
	resp, err := request.Post(url)

	logger.Infof("[Request] 获取请求 err: %v, 结果: %s", err, resp)

	var result Result
	err = json.Unmarshal(resp.Body(), &result)
	if err != nil {
		logger.Errorf("[%s] 解析 响应数据错误 err:%v", Mod_GetLatestRevByPo, err)
		return "", err
	}

	if result.Status != "0" && result.Status != "1" {
		logger.Errorf("[%s] 获得响应结果错误提示 :%v", Mod_GetLatestRevByPo, result.ErrorMsg)
		return "", err
	}

	return result.Data, nil

}
