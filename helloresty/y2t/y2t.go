package y2t

import (
	"encoding/json"
	"errors"
	"fmt"
	"log"
	"net/http"

	"github.com/davecgh/go-spew/spew"
	"github.com/go-resty/resty/v2"
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

	spew.Dump(url)
	fmt.Println(body)

	client := resty.New()
	request := client.R()
	request = request.EnableTrace()
	request = request.SetHeaders(headers)
	request = request.SetBody(body)
	request = request.SetHeaders(headers)
	resp, err := request.Post(url)
	fmt.Println("err:", err)
	spew.Dump(resp)

	var info Order
	if err != nil {
		return info, err
	}

	var result PoSearchResult
	err = json.Unmarshal(resp.Body(), &result)
	if err != nil {
		return info, err
	}

	if result.Status != "1" {
		return info, errors.New(result.ErrorMsg)
	}
	info = result.Data[0]
	return info, nil
}

// 获取 最新 预约时间
func getLatestRevByPo(data Order) {
	// queryURL := "/reservation/pages/tourists-reservation.html"

	// 组合 referer url

	// 组合 请求 参数

	// 获取 可以 预约的 日期

	// 获取 剩余的 仓库 数量
}

// 提交 预约 订单

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

// 生成
func CreateReservationReferer(data Order) string {
	url := BaseURI + tourists_reservation_url
	buf, _ := json.Marshal(data)
	var values map[string]string
	json.Unmarshal(buf, &values)

	return combineURL(url, values)
}
