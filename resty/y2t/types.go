package y2t

var (
	find_order_num_url       = "/Reservation/findOrderNum.do"
	posearch1_url            = "/Reservation/poSearch1.do"
	get_reservation_url      = ""
	tourists_reservation_url = "/reservation/pages/tourists-reservation.html"
	origin_url               = "https://icop.y2t.com"
	posearch_referer_url     = "https://icop.y2t.com/os/reservation/pages/tourists-login.html"
	potimeres_url            = "/Reservation/poTimeRes1.do"
	potimeresnum_url         = "/Reservation/poTimeResNum1.do"
	reservation_save_url     = "/Reservation/save1.do"
)

var (
	Mod_GetLatestRevByPo = "GetLatestRevByPo"
	Mod_PoSearch         = "PoSearch"
)

type Result struct {
	Data       interface{}
	Status     string
	ErrorMsg   string
	Error      interface{}
	PagingInfo interface{}
}

// 订单信息
type Order struct {
	OrderNo            string `json:"orderNo"`
	SubmitOrderNo      string `json:"submitOrderNo"`
	SubmitOrderUuid    string `json:"submitOrderUuid"`
	OfficeCode         string `json:"officeCode"`
	OfficeCodeName     string `json:"officeCodeName"`
	AgentConsigneeCode string `json:"agentConsigneeCode"`
}

type Detail struct {
	ForecastOrderDetailModels []ForecastOrderDetail `json:"forecastOrderDetailModels"`
	ForecastOrderModel        ForecastOrder         `json:"forecastOrderModel"`
}

type ForecastOrder map[string]string

type ForecastOrderDetail map[string]string

type Reservation struct {
	ForecastSetupUuid string `json:"forecastSetupUuid"`
	ForecastDate      string `json:"forecastDate"`
	StartDate         string `json:"startDate"`
	EndDate           string `json:"endDate"`
	OfficeCode        string `json:"officeCode"`
	Num               string `json:"num"`
	Status            string `json:"status"`
}
