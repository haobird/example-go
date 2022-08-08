package itssdk

/*
#cgo CFLAGS: -I./dll/include
#cgo LDFLAGS: -L${SRCDIR}/dll/dll -limos_mw_sdk -lmw_sdk_bp -lmw_sdk_ipc -lmw_sdk_player -lmw_sdk_rm

#include "imos_sdk_def.h"  //SDK宏定义头文件
#include "imos_sdk_pub.h"  //SDK结构体定义头文件
#include "imos_sdk_func.h" //SDK接口定义头文件
#include <stdlib.h>
#include <string.h>

VOID STDCALL* CGO_IMOS_MW_STATUS_REPORT_CALLBACK(IN CHAR *pcUserID, IN ULONG ulReportType,IN VOID *pParam);
VOID STDCALL* CGO_IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD(IN IMOS_MW_MULTI_UNIVIEW_PROTOCOL_HEADER_S *pstUniviewData, IN ULONG ulStreamHandle);
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"
)

const LogPath string = "/data/log/parking_sdk_uniview"
const LogSize int32 = 2048

//export CGO_IMOS_MW_STATUS_REPORT_CALLBACK
func CGO_IMOS_MW_STATUS_REPORT_CALLBACK(pcUserID *C.CHAR, ulReportType C.ULONG, pParam unsafe.Pointer) unsafe.Pointer {
	// 异常的时候进行回调
	fmt.Println("===========CGO_IMOS_MW_STATUS_REPORT_CALLBACK-start=========")
	var state *uint32
	state = (*uint32)(pParam)
	fmt.Println("===========CGO_IMOS_MW_STATUS_REPORT_CALLBACK-start=========")
	userIdByte := make([]byte, 48)
	userId := strings.ReplaceAll(string(userIdByte), "\u0000", "")
	fmt.Println("===========CGO_IMOS_MW_STATUS_REPORT_CALLBACK-UserId=========", userId)
	fmt.Println("===========CGO_IMOS_MW_STATUS_REPORT_CALLBACK-pParam=========", state)
	// 更新状态

	return nil
}

//export CGO_IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD
func CGO_IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD(pstUniviewData *C.IMOS_MW_MULTI_UNIVIEW_PROTOCOL_HEADER_S, ulStreamHandle C.ULONG) unsafe.Pointer {
	return nil
}

type SdkUniview struct {
	UserName       string
	Password       string
	ServerIP       string
	ServerPort     uint16
	DeviceID       string
	IsRetran       int32 // 是否重传 0 不重传 1 重传
	RetranIP       string
	UserID         string
	UlStreamHandle uint64 // 流句柄

}

// 启动
func (s *SdkUniview) Run() error {
	_ = s.Initiate()
	_ = s.SetStatusCallback()
	_ = s.SetLog()
	// _ = s.Login()
	_ = s.SetPicStreamDataCallback()
	// 开始播放
	//startPlayResult := C.IMOS_MW_StartPlay()
	return nil
}

// Initiate sdk 初始化
func (s *SdkUniview) Initiate() int {
	fmt.Println("===========sdk_uniview-Init-start=========")
	res := C.IMOS_MW_Initiate()
	if res == C.ERR_COMMON_SUCCEED {
		fmt.Println("=====sdk_uniview-Init-success ")
		return int(C.ERR_COMMON_SUCCEED)
	} else {
		fmt.Println("=====sdk_uniview-Init-fail", res)
		return int(res)
	}
}

// 设置sdk回调函数
func (s *SdkUniview) SetStatusCallback() int {
	fmt.Println("===========sdk_uniview-SetStatusCallback-start=========")
	res := C.IMOS_MW_SetStatusCallback(C.IMOS_MW_STATUS_REPORT_CALLBACK_PF(C.CGO_IMOS_MW_STATUS_REPORT_CALLBACK))
	if res == C.ERR_COMMON_SUCCEED {
		fmt.Println("=====sdk_uniview-SetStatusCallback-success ")
		return int(C.ERR_COMMON_SUCCEED)
	} else {
		fmt.Println("=====sdk_uniview-SetStatusCallback-fail", res)
		return int(res)
	}

}

// 设置sdk日志
func (s *SdkUniview) SetLog() int {
	fmt.Println("===========sdk_uniview-Log-start=========")
	logPath := C.CString(LogPath)
	logSize := C.ulong(LogSize)

	defer C.free(unsafe.Pointer(logPath))

	res := C.IMOS_MW_SetLog(C.IMOS_SDK_LOG_DEBUG, logPath, logSize)

	if res == C.ERR_COMMON_SUCCEED {
		fmt.Println("=====sdk_uniview-Log-success")
		return int(C.ERR_COMMON_SUCCEED)
	} else {
		fmt.Println("=====sdk_uniview-Log-fail", res)
		return int(res)
	}
}

// 登录
func (s *SdkUniview) Login() int {
	fmt.Println("===========sdk_uniview-login=========")
	userName := C.CString(s.UserName)
	password := C.CString(s.Password)
	serverIP := C.CString(s.ServerIP)
	serverPort := C.ushort(s.ServerPort)
	defer C.free(unsafe.Pointer(userName))
	defer C.free(unsafe.Pointer(password))
	defer C.free(unsafe.Pointer(serverIP))

	userIdByte := make([]byte, 48)
	res := C.IMOS_MW_Login(userName, password, serverIP, serverPort, (*C.char)(unsafe.Pointer(&userIdByte[0])))
	if res == C.ERR_COMMON_SUCCEED {
		fmt.Println("=====sdk_uniview-login-success")
	} else {
		fmt.Println("=====sdk_uniview-login-fail", res)
		return int(res)
	}

	s.UserID = strings.ReplaceAll(string(userIdByte), "\u0000", "")
	fmt.Println("=====sdk_uniview-login-userId" + s.UserID)
	return int(C.ERR_COMMON_SUCCEED)

}

// 回调地址
func (s *SdkUniview) SetPicStreamDataCallback() int {
	fmt.Println("===========sdk_uniview_Callback=========")

	userId := C.CString(s.UserID)
	isReTran := C.ulong(s.IsRetran)
	callbackIP := C.CString(s.RetranIP)

	defer C.free(unsafe.Pointer(userId))
	//defer C.free(unsafe.Pointer(isReTran))
	defer C.free(unsafe.Pointer(callbackIP))

	var ulStreamHandle C.ulong
	res := C.IMOS_MW_SetPicStreamDataCallback(
		userId,
		isReTran,
		callbackIP,
		C.IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF(C.CGO_IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD),
		&ulStreamHandle,
	)

	if res == C.ERR_COMMON_SUCCEED {

		fmt.Println("=====sdk_uniview-callbackResult-success")
		s.UlStreamHandle = uint64(ulStreamHandle)
		fmt.Println("=====sdk_uniview-callbackResult-Handle", s.UlStreamHandle)

		return 0
	} else {
		fmt.Println("=====sdk_uniview-login-fail", int(res))
		return int(res)
	}

}

// 车辆抓拍信息
type SdkUniviewResponse struct {
	BigPic           string
	SmallPic         string
	PassTime         int64
	PlateType        int64
	PlateColor       int64
	PlateNumber      string
	VehicleType      int64
	VehicleColer     string
	VehicleSpeed     int64
	VehicleBrand     string
	VehicleDirection int64
	PlaceName        string
	LaneID           int64
	LaneType         int64
	CamID            string
	TollgateID       string
	IdentifyStatus   int64
}

//Init 初始化函数
func Init() {

	// 查询数据库所有宇视sdk对接设备
	sdkUniview := &SdkUniview{
		UserName:   "123",
		Password:   "ddd",
		ServerIP:   "192.168.1.13",
		ServerPort: uint16(80),
		DeviceID:   "1233",
		IsRetran:   1,
		RetranIP:   "122",
	}
	_ = sdkUniview.Run()

}
