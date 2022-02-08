package y2t

var (
	posearch_url             = "/Reservation/findOrderNum.do"
	get_reservation_url      = ""
	tourists_reservation_url = "/reservation/pages/tourists-reservation.html"
	origin_url               = "https://icop.y2t.com"
	posearch_referer_url     = "https://icop.y2t.com/os/reservation/pages/tourists-login.html"
)

type PoSearchResult struct {
	Data       []Order
	Status     string
	ErrorMsg   string
	Error      interface{}
	PagingInfo interface{}
}

type Order struct {
	OrderNo            string `json:"orderNo"`
	SubmitOrderNo      string `json:"submitOrderNo"`
	SubmitOrderUuid    string `json:"submitOrderUuid"`
	OfficeCode         string `json:"officeCode"`
	OfficeCodeName     string `json:"officeCodeName"`
	AgentConsigneeCode string `json:"agentConsigneeCode"`
}
