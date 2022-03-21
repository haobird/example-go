package y2t

var (
	posearch_result  = `{"data":[{"officeCode":"SZWLC","officeCodeName":"平湖物流中心（深圳）","submitOrderUuid":"e443db4e-e4a8-4bca-9623-b42b3eb86dac","agentConsigneeCode":"11142","agentConsigneeDesc":"世纪冠航（项目）","aux1":null,"aux1Name":null,"tractorType":null,"tractorTypeName":null,"functionary":"张三","functionaryName":null,"deliveryType":"卸车入库","unloadPort":"P2984","unloadPortName":null,"telNo":"0755-12345677","transactionStatus":"Active","transactionType":"SIN","recVer":"2","siInputTime":null,"voucherSubmitTime":null,"cutVgmTime":null,"getCtnTime":null,"transFlow":null,"transDirection":null,"transDirectionName":null,"transWorkDemand":null,"deliveryRemark":null,"orderNo":"FBA603G58004SZ1","ownerCode":null,"ownerDesc":null,"submitDate":"2021-10-12 11:13:27","cutDate":null,"vesselName":null,"voyage":null,"submitOrderNo":"B211046577","countryCode":"A001","countryCodeName":null,"transportNeeds":"0","sensitiveGoods":null,"containerNo":null,"containerType":null,"containerCode":null,"workDemand":null,"shipCode":null,"remark":null,"aux3":null,"tractorNo":null,"aux5":"Pending","loadingCode":null,"flow":"SZWLC","flowName":null,"deliveryDate":"2021-10-26 12:00:00","goodsTypePage":"6","isForecast":"1","chargeDesc":"CA","orderUuid":null,"mobile":null,"sealNo":null,"tareWeight":null,"cargoControlCode":null,"direction":"深圳外运仓","directionName":null,"notifyCode":null,"trailingTeam":null,"controlWord":"0000000000000600000Y","workWord":null,"notifyDesc":null,"notifyAddress":null,"notifyTel":null,"notifyTelType":null,"consigneeId":"EIN+22-2833075","notifyCode_desc":null,"consigneeName":"Amazon FBA (Fulfillment by Amazon)","consigneeAddress":"410 Terry Ave. North, Seattle, WA 98109-5210","consigneeTel":"804.762.6568","consigneeTypeId":"TE"}],"status":"1","errorMsg":null,"error":null,"pagingInfo":null}`
	latestrev_resutl = `{"data":[{"forecastSetupUuid":"7e499bc6-f319-4007-94b4-e8a965cc7fc9","forecastDate":"2022-02-09","startDate":"2022-02-09 08:00:00","endDate":"2022-02-09 12:59:00","status":null,"num":null,"officeCode":"SZWLC"}],"status":"0","errorMsg":null,"error":null,"pagingInfo":null}`
)

var (
	ForecastSetupModel = `{
		"forecastSetupUuid": "e3dec50f-8a51-4083-a06f-df85ea3e3dde",
		"forecastDate": "2022-02-10",
		"startDate": "2022-02-10 08:00:00",
		"endDate": "2022-02-10 12:59:00",
		"officeCode": "SZWLC",
		"num": "",
		"status": ""
	}`

	PoDetailData = `{
		"officeCode": "SZWLC",
		"forecastOrderModel": {
			"forecastOrderUuid": "f3e912b5-a9f2-441c-a2ca-c7d990021ed9",
			"forecastNo": "21772494",
			"forecastType": "YY",
			"forecastDate": "2021-10-16",
			"fsStartEndDate": "2021-10-16 00:00-07:59",
			"forecastTel": "13539008577",
			"status": "Active",
			"containerType": null,
			"orderCount": null,
			"forecastPerson": null,
			"officeCode": "SZWLC",
			"officeCodeName": "平湖物流中心（深圳）",
			"customerCode": "11142",
			"recVer": "0",
			"remark": null,
			"tractorNo": "粤BG512L",
			"isTractor": null,
			"tractorType": "柜车",
			"tractorWeight": null,
			"carboardNo": null,
			"carboardWeight": null,
			"goodsWeight": null,
			"containerNo": null,
			"tareWeight": null,
			"nuclearReleaseNo": null,
			"modifier": null,
			"controlWord": "I0000000000000000000"
		},
		"forecastOrderDetailModels": [
			{
				"submitOrderUuid": "e443db4e-e4a8-4bca-9623-b42b3eb86dac",
				"orderNo": "FBA603G58004SZ1",
				"submitOrderNo": "B211046577",
				"officeCode": null,
				"forecastOrderUuid": "f3e912b5-a9f2-441c-a2ca-c7d990021ed9",
				"cfrDetailUuid": "8ce45a06-2c7f-4276-8911-033bdb194590",
				"forecastSetupUuid": "ea4045fe-1a7f-4cd3-ba14-1c66773ad59e",
				"recVer": "1",
				"isForecast": null,
				"flow": null,
				"submitOrderNoUuid": null,
				"officeName": null,
				"controlWord": "I0030000000000000000"
			}
		],
		"forecastSetupModel": null,
		"forecastOrderUuid": null,
		"forecastNo": null,
		"forecastType": null,
		"forecastDate": null,
		"fsStartEndDate": null,
		"forecastTel": null,
		"status": null,
		"containerType": null,
		"orderCount": null,
		"forecastPerson": null,
		"recVer": null,
		"remark": null,
		"tractorNo": null,
		"isTractor": null,
		"officeName": null,
		"officeCodeName": "平湖物流中心（深圳）",
		"tractorType": null,
		"tractorWeight": null,
		"carboardNo": null,
		"carboardWeight": null,
		"goodsWeight": null,
		"containerNo": null,
		"tareWeight": null,
		"nuclearReleaseNo": null
	}`

	SaveParams = `{
		"forecastOrderDetailModels": [
			{
				"cfrDetailUuid": "8ce45a06-2c7f-4276-8911-033bdb194590",
				"controlWord": "I0030000000000000000",
				"flow": null,
				"forecastOrderUuid": "f3e912b5-a9f2-441c-a2ca-c7d990021ed9",
				"forecastSetupUuid": "ea4045fe-1a7f-4cd3-ba14-1c66773ad59e",
				"isForecast": null,
				"officeCode": null,
				"officeName": null,
				"orderNo": "FBA603G58004SZ1",
				"recVer": "1",
				"submitOrderNo": "B211046577",
				"submitOrderNoUuid": null,
				"submitOrderUuid": "e443db4e-e4a8-4bca-9623-b42b3eb86dac"
			}
		],
		"forecastOrderModel": {
			"carboardNo": null,
			"carboardWeight": null,
			"containerNo": null,
			"containerType": null,
			"controlWord": "I0000000000000000000",
			"customerCode": "11142",
			"forecastDate": "2021-10-16",
			"forecastNo": "21772494",
			"forecastOrderUuid": "f3e912b5-a9f2-441c-a2ca-c7d990021ed9",
			"forecastPerson": null,
			"forecastTel": "13539008577",
			"forecastType": "YY",
			"fsStartEndDate": "2021-10-16 00:00-07:59",
			"goodsWeight": null,
			"isTractor": null,
			"modifier": null,
			"nuclearReleaseNo": null,
			"officeCode": "SZWLC",
			"officeCodeName": "平湖物流中心（深圳）",
			"orderCount": null,
			"recVer": "0",
			"remark": null,
			"status": "Active",
			"tareWeight": null,
			"tractorNo": "粤BG512L",
			"tractorType": "柜车",
			"tractorWeight": null
		},
		"forecastSetupModel": {
			"forecastSetupUuid": "e3dec50f-8a51-4083-a06f-df85ea3e3dde",
			"forecastDate": "2022-02-10",
			"startDate": "2022-02-10 08:00:00",
			"endDate": "2022-02-10 12:59:00",
			"officeCode": "SZWLC",
			"num": "",
			"status": ""
		}
	}`
)
