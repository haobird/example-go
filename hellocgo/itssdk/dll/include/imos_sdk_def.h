/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_def.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 2012-01-14
        Author:  
   Description: 该文件定义了sdk相关的错误码、宏

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  2012-01-14

*******************************************************************************/
#ifndef __IMOS_SDK_DEF_H__
#define __IMOS_SDK_DEF_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#if 0
#endif
/*******************************************************************************
编译选项
*******************************************************************************/
#if defined(WIN32)
    #if defined(IMOS_EXPORTS_DLL)
        #define IMOS_EXPORT  __declspec( dllexport )
    #else
        #if defined(IMOS_AS_STATIC_LIB)
            #define IMOS_EXPORT
        #else
            #define IMOS_EXPORT  __declspec( dllimport )    
        #endif
    #endif
#else
    #define IMOS_EXPORT
#endif

/* 函数标准调用约定 */
#ifdef WIN32
    #define STDCALL         __stdcall
#else
    #ifdef i386
        #define STDCALL         
    #else
        #define STDCALL
    #endif
#endif 

#if 0
#endif
/*******************************************************************************
通用数据类型定义
*******************************************************************************/
/** @brief 8位有符号整型 */
#ifndef CHAR
typedef char CHAR;
#endif

/** @brief 8位无符号整型 */
#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

/** @brief 16位有符号整型 */
#ifndef SHORT
typedef short SHORT;
#endif

/** @brief 16位无符号整型 */
typedef unsigned short USHORT;

/** @brief 32位有符号整型 */
typedef long LONG;

/** @brief 32位无符号整型 */
typedef unsigned long ULONG;

/** @brief 有符号整型 */
typedef int INT;

/** @brief 无符号整型 */
typedef unsigned int UINT;

/** @brief 64位有符号整型 */
#if defined (_MSC_VER)
typedef __int64 DLONG;
#else
typedef long long DLONG;
#endif

/** @brief 64位无符号整型 */
#if defined (_MSC_VER)
typedef unsigned __int64 DULONG;
#else
typedef unsigned long long DULONG;
#endif

/** @brief 双精度数据类型 */
typedef double DOUBLE;

/** @brief 浮点数据类型 */
typedef float FLOAT;

/** @brief 布尔型 */
typedef unsigned long BOOL_T;

/** @brief 表示长度数据类型 */
typedef unsigned long SIZE_T;

/** @brief 表示时间数据类型 */
typedef long TIME_T;

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;

/** @brief VOID型 */
#define VOID                            void

/** @brief 表示通用句柄类型 */
typedef VOID* HANDLE;

/** @brief IMOS ID 数据类型 */
typedef DULONG IMOS_ID;

/** @brief 通用句柄类型 IMOS_HANDLE */
#ifndef IMOS_HANDLE
#if defined (WIN32)
typedef HANDLE IMOS_HANDLE;
#else
typedef int IMOS_HANDLE;
#endif
#endif

/** @brief 函数参数类型定义 */
#define IN
#define OUT
#define INOUT

/** @brief IMOS编程规范布尔值 */
#define BOOL_TRUE                       ((BOOL_T) 1)
#define BOOL_FALSE                      ((BOOL_T) 0)

#ifndef NULL
#define NULL (void *)0
#endif


#if 0
#endif
/*******************************************************************************
SDK 错误码/状态码
*******************************************************************************/
/* 通用成功 */
#define ERR_COMMON_SUCCEED                       0x000000      /**< 执行成功 */

/*********************** SDK 状态码定义(257 - 356) *****************************/
#define ERR_SDK_LOG_CLOSE                        257            /**< SDK 日志关闭 */
#define ERR_SDK_DEVICE_STREAM_FULL               259            /**< 设备流已满 */
#define ERR_SDK_DEVICE_STREAM_CLOSED             260            /**< 设备流已关闭 */
#define ERR_SDK_DEVICE_STREAM_NONEXIST           261            /**< 设备流不存在 */
#define ERR_SDK_USER_PASSWORD_CHANGE             262            /**< 用户密码修改 */
#define ERR_SDK_USER_DELETED                     263            /**< 用户已删除 */

/*********************** SDK 错误码定义(357 - 506) *****************************/
#define ERR_SDK_COMMON_FAIL                      357            /**< 操作失败 */
#define ERR_SDK_COMMON_INVALID_PARAM             358            /**< 输入参数非法 */
#define ERR_SDK_COMMON_NO_MEMORY                 359            /**< 系统内存不足 */
#define ERR_SDK_COMMON_SYS_FAIL                  360            /**< 系统通用错误，Q: 暂未使用 */
#define ERR_SDK_COMMON_FAIL_STAT                 361            /**< 读取文件（目录）状态失败 */
#define ERR_SDK_COMMON_FILE_NONEXIST             362            /**< 文件不存在 */
#define ERR_SDK_COMMON_NOTSUPPORT                363            /**< 接口不支持 */

#define ERR_SDK_USER_NOT_AUTHORIZED              457            /**< 用户未授权 */
#define ERR_SDK_USERFULL                         458            /**< 用户已满 */
#define ERR_SDK_USERNONEXIST                     459            /**< 用户不存在 */
#define ERR_SDK_USER_PASSWD_INVALID              460            /**< 用户密码错误 */
#define ERR_SDK_USER_KEEPALIVEFAIL               461            /**< SDK保活失败 */
#define ERR_SDK_NOTINIT                          462            /**< SDK未初始化 */
#define ERR_SDK_REINIT                           463            /**< SDK已初始化 */

#define ERR_SDK_CREATE_THREAD_FAIL               466            /**< 创建线程失败 */
#define ERR_SDK_NOENOUGH_BUF                     467            /**< 缓冲区太小: 接收设备数据的缓冲区 */
#define ERR_SDK_SOCKET_LSN_FAIL                  468            /**< 创建socket listen失败 */
#define ERR_SDK_SUBSCRIBE_FULL                   470            /**< 本用户订阅已满, 设备侧用户订阅已满的错误码不能返回 */
#define ERR_SDK_COMMAND_SEND_FAIL                471            /**< 请求发送失败 */
#define ERR_SDK_COMMAND_TIMEOUT                  472            /**< 请求超时 */
#define ERR_SDK_UPDATE_NOTADMIN                  473            /**< 非admin用户无法升级 */
#define ERR_SDK_UPDATE_INVALID                   474            /**< 升级 未开始 */
#define ERR_SDK_UPDATE_INPROCESS                 475            /**< 升级 处理中 */
#define ERR_SDK_UPDATE_NOMEMORY                  476            /**< 升级 内存空间不够 */
#define ERR_SDK_UPDATE_FILE_OPEN_ERR             477            /**< 升级 打开镜像文件出错 */
#define ERR_SDK_UPDATE_DEVICE_ERR                478            /**< 升级 FLASH出错 */
#define ERR_SDK_UPDATE_BUSY                      479            /**< 不能同时加载多个升级进程 */
#define ERR_SDK_UPDATE_FAIL_TIMEOUT              480            /**< 升级超时 */

#define ERR_SDK_IP_CONFLICT                      486            /**< IP地址冲突 */
#define ERR_SDK_NETWORKMODE_NOTSUPPORT           487            /**< 网口模式不支持 */


/*********************** SDK 业务模块错误码定义(507-656) *******************/
/* 设备维护相关(507 - 556) */
#define ERR_SDK_INVALID_CONFIGFILE               507            /**< 配置文件无效 */
#define ERR_SDK_IVA_WORK_MODE_NOT_SUPPORT        508            /**< 智能模式不支持手动抓拍 */
#define ERR_SDK_IVA_MANUAL_SNAP_PTZ_MOVING       509            /**< 云台运动中,手动抓拍配置无效 */
#define ERR_SDK_EXCEED_CONFIG_FULL               510            /**< Smart规则配置超过最大值 */

/* 媒体相关(557 - 606) */
#define ERR_SDK_BIAUDIO_AUDIOBCAST_FULL          557            /**< 语音业务已满 */
#define ERR_SDK_STOR_RESOURCE_NOTINIT            558            /**< 存储资源未分配 */
#define ERR_SDK_MEDIA_ENCODELIMITED              559            /**< 编码能力受限 */

/* 云台相关(607 - 656) */
#define ERR_SDK_PTZ_TRACK_ISUSED                 612            /**< 轨迹已使用，无法删除*/
#define ERR_SDK_PTZ_SERIALMODE_MISMATCH          614            /**< 串口模式不匹配*/
#define ERR_SDK_PTZ_TRACK_NOT_EXIST              618            /**< 轨迹不存在*/
#define ERR_SDK_PTZ_MODE_CRUISE_FULL             626            /**< 模式路径轨迹点个数已满 */


/*********************** SDK 播放器错误码定义(657 - 756) ****************************/
#define ERR_SDK_XP_INIT_FAILED                   657            /**< 播放器初始化失败 */
#define ERR_SDK_XP_PORT_ALLOC_FAILED             658            /**< 播放器通道分配失败 */
#define ERR_SDK_XP_PORT_NOT_EXIST                659            /**< 播放器通道不存在 */
#define ERR_SDK_XP_START_STREAM_FAILED           660            /**< 播放器启流失败 */
#define ERR_SDK_XP_START_PLAY_FAILED             662            /**< 开始播放失败 */
#define ERR_SDK_XP_FILE_PLAY_FINISHED            669            /**< 文件已播放完 */
#define ERR_SDK_XP_DISK_CAPACITY_WARN            670            /**< 硬盘剩余空间低于阈值 */
#define ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH      671            /**< 硬盘剩余空间不足 */
#define ERR_SDK_XP_NO_PICTURE_TO_SNATCH          672            /**< 没有解码过的图片可供抓拍 */
#define ERR_SDK_XP_SERIES_SNATCH_FAILED          673            /**< 连续抓拍过程中抓拍失败 */
#define ERR_SDK_XP_WRITE_FILE_FAILED             674            /**< 写文件操作失败 */
#define ERR_SDK_XP_FILE_DESTROY                  675            /**< 文件已损坏 */
#define ERR_SDK_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE 676            /**< 媒体编码格式不支持录像操作 */
#define ERR_SDK_XP_PROCESS_MEDIA_DATA_FAILED     677            /**< 媒体数据处理失败 */
#define ERR_SDK_XP_RECV_DATA_FAILED              678            /**< 网络故障造成接收数据失败 */
#define ERR_SDK_XP_MEDIA_RESOLUTION_CHANGE       679            /**< 媒体流分辨率发生变化 */
#define ERR_SDK_XP_VOICE_RUNNING_ERROR           680            /**< 语音对讲或广播过程中出错 */
#define ERR_SDK_XP_AUDIO_DEVICE_UNRIPE           682            /**< 音频设备未准备好 */

/**@brief 录像分割上报类型 */
#define ERR_SDK_PLAYER_RECORDSTATE_MANUAL        683       /**< 手动停止 */
#define ERR_SDK_PLAYER_RECORDSTATE_SUBSECTION    684       /**< 按规则分割 */
#define ERR_SDK_PLAYER_RECORDSTATE_CAPACITYLIMIT 685       /**< 容量限制到达 */


/*********************** MA  客户端错误码定义(757 -/) ****************************/
#define ERR_SDK_MA_SUCCEED                       757            /**< MA 成功 */
#define ERR_SDK_MA_FAIL                          758            /**< MA 失败 */
#define ERR_SDK_MA_INVALID_PARAM                 759            /**< MA 参数错误 */
#define ERR_SDK_MA_MALLOC_FAIL                   760            /**< MA malloc失败 */
#define ERR_SDK_MA_LESS_MEMORY                   761            /**< MA 内存不够 */
#define ERR_SDK_MA_SOAP_ERROR                    762            /**< MA soap错误 */
#define ERR_SDK_MA_NET_FAILED                    763            /**< MA 网络连接错误 */
#define ERR_SDK_MA_USR_LOGIN                     764            /**< MA 用户已经登录 */
#define ERR_SDK_MA_AUTHORIZE_FAIL                765            /**< MA 授权失败 */
#define ERR_SDK_MA_INVALID_IP                    766            /**< MA 无效IP */
#define ERR_SDK_MA_SRC_MISS                      767            /**< MA 存储源未找到 */
#define ERR_SDK_MA_NO_STOR_CHANNEL               768            /**< MA 无空余存储通道, Q: 暂未使用? */
#define ERR_SDK_MA_NO_STOR_NODE                  769            /**< MA 无空余存储节点, Q: 暂未使用?  */
#define ERR_SDK_MA_TASK_FULL                     770            /**< MA 任务满 */
#define ERR_SDK_MA_INIT_DONE                     771            /**< MA 模块已经初始化, Q: 这种情况下直接返回成功不可以吗? */
#define ERR_SDK_MA_FULL_STOP                     772            /**< MA 满停止, Q: 暂未使用?  */
#define ERR_SDK_MA_STREAM_BUSY                   773            /**< MA 流正忙, Q: 暂未使用?  */
#define ERR_SDK_MA_WR_ERROR                      774            /**< MA 读写失败, Q: 暂未使用?  */
#define ERR_SDK_MA_EZR_UNAVAILABLE               775            /**< MA EZR不可用 */
#define ERR_SDK_MA_SERVICE_DOWN                  776            /**< MA EZR服务已停止 */
#define ERR_SDK_MA_SERVICE_RUNNING               777            /**< MA EZR服务运行中 */
#define ERR_SDK_MA_PORT_CONFLICT                 778            /**< MA EZR端口冲突 */


/*******************************************************************************
SDK 宏定义 
*******************************************************************************/
#if 0
#endif
/**************************************** 设备状态相关 ***************************************/
/**@brief 设备状态类型 */
#define IMOS_MW_STATUS_KEEPALIVE                   0            /**< SDK保活，状态码为: ERR_SDK_USER_KEEPALIVEFAIL */
#define IMOS_MW_STATUS_RLOGIN                      1          /**< SDK重连成功，状态码为: IMOS_MW_STATUS_RLOGIN */
#define IMOS_MW_STATUS_UPDATE                      1            /**< 升级结果，状态码为: ERR_SDK_UPDATE_INVALID 等 */
#define IMOS_MW_STATUS_DETECTED_ACTIVITY           2            /**< 运动检测区域运动量， 对应参数:IMOS_MW_MOTION_ACTIVITY_INFO_S */
#define IMOS_MW_STATUS_USERINFO_CHANGE             3            /**< 用户信息修改, 状态码为: ERR_SDK_USER_PASSWORD_CHANGE 等 */ 
#define IMOS_MW_STATUS_VOLUME_INFO                 4            /**< 音量信息， 对应参数:IMOS_MW_VOLUME_INFO_S */
    
#define IMOS_MW_STATUS_MANAGE_SERVER_ONLINE        50           /**< 管理服务器的连接状态，对应参数BOOL_T: ON:1  OFF:0 */                  
#define IMOS_MW_STATUS_PHOTO_SERVER_ONLINE         51           /**< 照片服务器的连接状态，对应参数BOOL_T: ON:1  OFF:0 */     
#define IMOS_MW_STATUS_BASIC_INFO                  52           /**< 设备基本信息，对应参数类型: IMOS_MW_BASIC_DEVICE_INFO_S */              
#define IMOS_MW_STATUS_RUN_INFO                    53           /**< 设备运行状态，对应参数类型: IMOS_MW_DEVICE_RUN_INFO_S */  
#define IMOS_MW_STATUS_NETWORK_CHANGE              54           /**< 网口配置结果，状态码为: ERR_SDK_IP_CONFLICT 等 */
#define IMOS_MW_STATUS_WIFI_SCANNING_INFO          55           /**< WiFi扫描信息  对应参数类型: IMOS_MW_WIFI_SCANNING_INFO_S */ 
#define IMOS_MW_STATUS_WIFI_LINK_STATUS            56           /**< WiFi连接状态  对应参数类型: IMOS_MW_WIFI_LINK_STATUS_S */
#define IMOS_MW_STATUS_NETWORK_INTERFACE           57           /**< 当前网口状态，对应参数类型: IMOS_MW_NETWORK_INTERFACE_INFO_S */    

#define IMOS_MW_STATUS_STOR_MEMORY_CARD_FORMAT     90           /**< 本地存储设备格式化状态， 状态码为: ERR_COMMON_SUCCEED等 */  
#define IMOS_MW_STATUS_STOR_NAS_MOUNT              91           /**< NAS挂载状态 状态码为: ERR_COMMON_SUCCEED等 */  

#define IMOS_MW_STATUS_PTZ                         100          /**< 云台状态，对应参数类型: IMOS_MW_PTZ_STATUS_S */                        
#define IMOS_MW_STATUS_PTZ_ABS_POSITION            101          /**< 云台绝对位置，对应参数类型: IMOS_MW_PTZ_ABSPOSITION_S */                    
#define IMOS_MW_STATUS_PTZ_ABS_ZOOM                102          /**< 云台绝对ZOOM倍数，对应参数类型: IMOS_MW_PTZ_ABSZOOM_S */  
#define IMOS_MW_STATUS_SNOWMODE                    103          /**< 除雪模式状态 对应参数类型: ULONG: ON:1  OFF:0 */ 
#define IMOS_MW_STATUS_PTZ_PRESET                  104          /**< 云台预置位执行状态 对应参数类型: ULONG: OK:1  NOK:0 */ 
    
#define IMOS_MW_STATUS_SCENE_CURRENT               120          /**< 场景自动切换的当前场景ID, 对应参数类型: ULONG */
    
#define IMOS_MW_STATUS_OSD_3DCOVER                 131          /**< 3D视频遮盖OSD位置，对应参数: IMOS_MW_OSD_3DCOVER_POSITION_S */   
#define IMOS_MW_STATUS_SERIALINPUTDATA             131
    
#define IMOS_MW_STATUS_RADAR                       150          /**< 雷达状态  对应参数: IMOS_MW_RADAR_XXX */                           
#define IMOS_MW_STATUS_COIL                        151          /**< 线圈状态  信息内容为: IMOS_MW_COIL_STATE_S 的数组，支持 8个*/          
#define IMOS_MW_STATUS_POLARIZER                   152          /**< 偏振镜状态  对应参数: IMOS_MW_POLARIZER_STATUS_XXX */                     
#define IMOS_MW_STATUS_LED_STROBE                  153          /**< LED灯状态  对应参数: IMOS_MW_LED_STROBE_STATUS_XXX */ 
#define IMOS_MW_STATUS_ND_FILTER                   154          /**< ND滤镜状态  对应参数: IMOS_MW_POLARIZER_STATUS_INUSE */
#define IMOS_MW_STATUS_TRAFFICLIGHT                155          /**< 信号灯实时在线状态  对应参数: IMOS_MW_TRAFFICLIGHT_STATUS_XXX */

#define IMOS_MW_STATUS_SD                          156          /**< SD卡状态  对应参数: IMOS_MW_SD_STATUS_NOEXIST */
#define IMOS_MW_STATUS_CAPTURE                     157          /**< 抓拍上报 对应参数:IMOS_MW_CAPTURE_AUTO_TYPE */

#define IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT      160          /**< 车位状态上报 对应参数:IMOS_MW_PARK_STATUS_S */
#define IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT_EX   164          /**< 车位状态上报扩展 对应参数:IMOS_MW_PARK_STATUS_EX_S */

#define IMOS_MW_STATUS_TRAFFIC_PARAM_REPORT        169          /**< 交通参数上报 对应参数:IMOS_MW_TRAFFIC_PARA_RSLT_S */
#define IMOS_MW_STATUS_VEHICLE_PARAM_REPORT        170          /**< 车辆进出状态上报 对应参数:IMOS_MW_VEHICLE_STATE_S */

#define IMOS_MW_STATUS_PLAYER_RECORD_VIDEO         200          /**< 本地录像过程中上报运行信息，信息内容见: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_MEDIA_PROCESS        201          /**< 视频媒体处理过程中的上报运行信息，信息内容见: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_SERIES_SNATCH        202          /**< 连续抓拍过程中上报运行信息，信息内容见: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_MEDIA_VOICE          203          /**< 语音业务过程中上报运行信息，信息内容见: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_RECORD_VIDEOEX       204          /**< 本地录像扩展：录像分割过程中上报运行信息，信息内容见: IMOS_MW_PALYER_RECORDSTATUS_S */
    
/**@brief 设备工作模式 */
#define IMOS_MW_DEVICE_WORK_MODE_TOLLGATE          0             /**< 卡口 */
#define IMOS_MW_DEVICE_WORK_MODE_ELEC_POLICE       1             /**< 电警 */
    
/**@brief 云台状态 */
#define IMOS_MW_PTZ_STATUS_IDLE                    0             /**< 空闲状态 */
#define IMOS_MW_PTZ_STATUS_USER_CTRL               1             /**< 用户控制 */
#define IMOS_MW_PTZ_STATUS_AUTO_CRUISE             2             /**< 自动巡航 ulStatusPara1=轨迹ID */
#define IMOS_MW_PTZ_STATUS_MANUAL_CRUISE           3             /**< 手动巡航 ulStatusPara1=轨迹ID */
#define IMOS_MW_PTZ_STATUS_TRACK_RECORD            4             /**< 轨迹录制 ulStatusPara1=轨迹ID */
#define IMOS_MW_PTZ_STATUS_IVA_PLAN                5             /**< 智能计划执行过程中 */

/**@brief 雷达状态 */
#define IMOS_MW_RADAR_STATUS_DISCONNECT            0             /**< 雷达未连接 */
#define IMOS_MW_RADAR_STATUS_CONNECT               1             /**< 雷达连接 */
    
/**@brief 线圈状态 */
#define IMOS_MW_COIL_STATUS_DISCONNECT             0             /**< 线圈断开 */
#define IMOS_MW_COIL_STATUS_CONNECT                1             /**< 线圈连接 */
#define IMOS_MW_COIL_STATUS_UNUSE                  2             /**< 线圈未使用 */
    
/**@brief 偏振镜状态 */
#define IMOS_MW_POLARIZER_STATUS_INUSE             0             /**< 正在使用 */
#define IMOS_MW_POLARIZER_STATUS_UNUSE             1             /**< 未使用 */
#define IMOS_MW_POLARIZER_STATUS_DOWNING           2             /**< 正在下降 */
#define IMOS_MW_POLARIZER_STATUS_UPING             3             /**< 正在上升 */
#define IMOS_MW_POLARIZER_STATUS_UNKNOWN           4             /**< 异常 */
#define IMOS_MW_POLARIZER_STATUS_SWITCHING         5             /**< 切换中 */

/**@brief 交通灯检测器实时在线状态 */
#define IMOS_MW_TRAFFICLIGHT_STATUS_OFFLINE        0             /**< 离线 */
#define IMOS_MW_TRAFFICLIGHT_STATUS_ONLINE         1             /**< 在线 */
#define IMOS_MW_TRAFFIClIGHT_STATUS_UNUSED         2             /**< 未使用 */

/**@brief LED灯状态 */
#define IMOS_MW_LED_STROBE_STATUS_ON               0              /**< 打开 */
#define IMOS_MW_LED_STROBE_STATUS_OFF              1              /**< 关闭 */

/**@brief SD卡状态 */
#define IMOS_MW_SD_STATUS_NOEXIST                  0             /**< 不存在 */
#define IMOS_MW_SD_STATUS_FAULT                    1             /**< 故障 */
#define IMOS_MW_SD_STATUS_CHECKING                 2             /**< 检测中 */
#define IMOS_MW_SD_STATUS_NORMAL                   3             /**< 正常 */

/**@brief 服务器管理模式 */
#define IMOS_MW_MANAGE_SERVER_PROTOCOL_IMOS         0             /**< 管理协议为IMOS */
#define IMOS_MW_MANAGE_SERVER_PROTOCOL_GB           1             /**< 管理协议为GB */
#define IMOS_MW_MANAGE_SERVER_PROTOCOL_NONE         2             /**< 管理协议为无 */

/**@brief 抓拍照片类型 */
#define IMOS_MW_CAPTURE_AUTO_TYPE                   0             /**< 自动抓拍，包括外设抓拍、绊线触发 */
#define IMOS_MW_CAPTURE_MANUAL_TYPE                 1             /**< 手动抓拍 */

/**@brief 交通参数服务器上报车辆特征数量 */ 
#define IMOS_MW_CAR_TYPE_NUM                         12           /**< 车辆类型数目 */
#define IMOS_MW_LPR_COLOR_NUM                        5            /**< 车牌颜色数目 */
#define IMOS_MW_CAR_SPEED_NUM                        2            /**< 车速数目 */

#if 0
#endif
/*************************************** 配置相关 ********************************************/
/**@brief 配置操作命令字 */
/* 系统配置:  版本类型 、管理模式、缓存补录 */
#define IMOS_MW_SYSTEM_TIME_INFO            0          /**< 获取/设置 系统时间(含时区信息)，对应结构定义: IMOS_MW_SYSTEM_TIME_INFO_S */
#define IMOS_MW_SYSLOG_SERVER_INFO          1          /**< 获取/设置 syslog服务器信息，对应结构定义: IMOS_MW_SYSLOG_SERVER_INFO_S */ 
#define IMOS_MW_MANAGE_SERVER_CFG           3          /**< 获取/设置 管理服务器配置，对应结构定义: IMOS_MW_MANAGE_SERVER_CFG_S */
#define IMOS_MW_DEVICE_INSATLLATION_INFO    5          /**< 获取/设置 设备安装信息，参见: IMOS_MW_DEVICE_INSATLLATION_INFO_S */
#define IMOS_MW_BM_SERVER_CFG               6          /**< 获取/设置 BM服务器配置，对应结构定义: IMOS_MW_BM_SERVER_CFG_S */
#define IMOS_MW_DEVICE_NAME_CFG             7          /**< 获取/设置 设备名称配置，对应结构定义: IMOS_MW_DEVICE_NAME_CFG_S */
#define IMOS_MW_NTP_SERVER_CFG              8          /**< 获取/设置 NTP服务器配置，对应结构定义: IMOS_MW_NTP_SERVER_CFG_S  */
#define IMOS_MW_DCOUT_CFG                   9          /**< 获取/设置 电源输出配置，对应结构定义: IMOS_MW_DCOUT_CFG_S */

/* 网口、串口、透明通道 */
#define IMOS_MW_SERIAL_CFG                  10         /**< 获取/设置 串口配置，对应结构定义: IMOS_MW_SERIAL_CFG_S */
#define IMOS_MW_TRANSPORT_CFG               11         /**< 获取/设置 透明通道配置，对应结构定义: IMOS_MW_TRANSPORT_CFG_S */
#define IMOS_MW_NETWORK_INTERFACE_CFG       12         /**< 获取/设置 网口配置，对应结构定义: IMOS_MW_NETWORK_INTERFACE_CFG_S */
#define IMOS_MW_UNP_CFG                     13         /**< 获取/设置 UNP配置，对应结构定义: IMOS_MW_UNP_CFG_S */ 
#define IMOS_MW_WIFI_CFG                    14         /**< 获取/设置 WiFi连接配置 对应结构定义: IMOS_MW_WIFI_CFG_S */

#define IMOS_MW_MULTI_TRANSPORT_CFG         2005      /**< 获取/设置 多透明通道配置，对应结构定义: IMOS_MW_MULTI_TRANSPORT_CFG_S */      

/* 图像参数配置 */
#define IMOS_MW_EXPOSURE_CFG                20         /**< 获取/设置 曝光参数，对应结构定义: IMOS_MW_EXPOSURE_CFG_S */
#define IMOS_MW_EXPOSURE_CFG_VIDEO          507        /**< 获取/设置 曝光视频参数，对应结构定义: IMOS_MW_EXPOSURE_CFG_VIDEO */
#define IMOS_MW_EXPOSURE_CFG_IMAGE          508        /**< 获取/设置 曝光图像参数，对应结构定义: IMOS_MW_EXPOSURE_CFG_IMAGE */

#define IMOS_MW_WHITE_BALANCE_CFG           21         /**< 获取/设置 白平衡参数，对应结构定义: IMOS_MW_WHITE_BALANCE_CFG_S */
#define IMOS_MW_IMAGE_ENHANCE_CFG           22         /**< 获取/设置 图像增强参数，对应结构定义: IMOS_MW_IMAGE_ENHANCE_CFG_S */
#define IMOS_MW_FOCUS_CFG                   23         /**< 获取/设置 对焦参数，对应结构定义: IMOS_MW_FOCUS_CFG_S */
#define IMOS_MW_IMAGE_MISC_CFG              24         /**< 获取/设置 图像杂项参数，对应结构定义: IMOS_MW_IMAGE_MISC_CFG_S */
#define IMOS_MW_SCENEID_INUSE               26         /**< 获取/设置 当前场景ID，对应参数: ULONG */
#define IMOS_MW_CONDITION_INFO              27         /**< 获取  当前环境条件，对应参数: IMOS_MW_CONDITION_INFO_S */
#define IMOS_MW_IR_CTRL_CFG                 28         /**< 获取/设置 红外控制参数，对应结构定义: IMOS_MW_IR_CTRL_CFG_S */
#define IMOS_MW_SCENE_CFG_EX                29         /**< 获取/设置 场景扩展参数配置，对应结结构定义: IMOS_MW_SCENE_CFG_EX_S */
#define IMOS_MW_SCENE_CFG_EX2               201        /**< 获取/设置 场景扩展参数配置，对应结结构定义: IMOS_MW_SCENE_CFG_EX2_S */
#define IMOS_MW_DEFAULT_SCENE               202        /**< 获取/设置 默认场景ID，对应参数: ULONG */
#define IMOS_MW_VIEW_MODE                   203        /**< 获取/设置 半球视角模式配置，对应参数: ULONG */
#define IMOS_MW_LIGHT_MODE                  204        /**< 获取/设置 补光灯模式，对应参数: IMOS_MW_LIGHT_MODE_S */
#define IMOS_MW_SEND_MODE                   206        /**< 获取/设置 码流发送模式配置，对应参数: ULONG */


/* 视频编码、音频编解码参数、OSD、ROI */
#define IMOS_MW_VIDEOIN_MODE_CFG            30         /**< 获取/设置 视频编码制式，对应结构定义: IMOS_MW_VIDEOIN_MODE_CFG_S */
#define IMOS_MW_VIDEO_ENCODER_CFG           31         /**< 获取/设置 视频编码参数配置，对应结构定义:IMOS_MW_VIDEO_ENCODER_CFG_S */
#define IMOS_MW_AUDIO_IN_CFG                32         /**< 获取/设置 音频输入参数配置，对应结构定义:IMOS_MW_AUDIO_IN_CFG_S */
#define IMOS_MW_AUDIO_OUT_CFG               33         /**< 获取/设置 音频输出参数配置，对应结构定义:IMOS_MW_AUDIO_OUT_CFG_S */
#define IMOS_MW_ROI_CFG                     34         /**< 获取/设置 ROI 配置，对应结构定义: IMOS_MW_ROI_S */
#define IMOS_MW_OSD_STYLE_CFG               35         /**< 获取/设置 叠加OSD样式配置，对应结构定义: IMOS_MW_OSD_STYLE_CFG_S */
#define IMOS_MW_OSD_STYLE_EX_CFG            205        /**< 获取/设置 叠加扩展OSD样式配置，对应结构定义: IMOS_MW_OSD_STYLE_EX_CFG_S */
#define IMOS_MW_INFO_OSD_CFG                36         /**< 获取/设置/删除 叠加OSD配置，对应结构定义: IMOS_MW_INFO_OSD_CFG_S */
#define IMOS_MW_COVER_OSD_CFG               37         /**< 获取/设置/删除 遮盖OSD配置，对应结构定义: IMOS_MW_COVER_OSD_CFG_S */
#define IMOS_MW_SUB_OSD_CFG                 38         /**< 获取/设置 其他OSD配置，对应结构定义: IMOS_MW_SUB_OSD_CFG_S */
#define IMOS_MW_AUTO_SEND_STREAM_CFG        39         /**< 获取/设置 流媒体保存配置 对应结构定义: IMOS_MW_AUTOSEND_STREAM_CFG_S */

    
/* 告警相关配置: 运动检测、遮挡检测、声音检测、温度、输入开关量、输出开关量、联动动作、布防计划 */
#define IMOS_MW_ALARM_LINK_CFG              40         /**< 获取/设置 告警联动配置，对应结构定义: IMOS_MW_ALARM_LINK_CFG_S */
#define IMOS_MW_ALARM_MOVE_DETECT_CFG       41         /**< 获取/设置 运动检测配置信息，对应结构定义: IMOS_MW_VIDEO_MOTION_CFG_S */ 
#define IMOS_MW_ALARM_TEMPERATURE_CFG       42         /**< 获取/设置 温度配置信息，对应结构定义: IMOS_MW_TEMPERATURE_CFG_S */ 
#define IMOS_MW_ALARM_INPUT_SWITCH_CFG      43         /**< 获取/设置 输入开关量信息，对应结构定义: IMOS_MW_INPUT_SWITCH_CFG_S */ 
#define IMOS_MW_ALARM_OUTPUT_SWITCH_CFG     44         /**< 获取/设置 输出开关量信息，对应结构定义: IMOS_MW_OUTPUT_SWITCH_CFG_S */ 
#define IMOS_MW_ALARM_DEFEND_CFG            45         /**< 获取/设置 布防计划配置，对应结构定义: IMOS_MW_DEFEND_PLAN_CFG_S */
#define IMOS_MW_ALARM_AUDIO_DETECT_CFG      46         /**< 获取/设置 声音检测配置信息，对应结构定义: IMOS_MW_AUDIO_DETECT_CFG_S */ 
#define IMOS_MW_ALARM_TAMPER_DETECT_CFG     47         /**< 获取/设置 遮挡检测配置信息，对应结构定义: IMOS_MW_TAMPER_DETECT_CFG_S */ 
    
/* 云台相关: 云台配置、预置位列表、巡航计划(周、例外)、巡航路线、拉框放大参数配置 */
#define IMOS_MW_PTZ_CFG                     50         /**< 获取/设置 云台配置信息，对应结构定义为: IMOS_MW_PTZ_CFG_S */
#define IMOS_MW_PTZ_PRESET_CFG              51         /**< 获取      预置位信息，对应结构定义: IMOS_MW_PRESET_CFG_S */    
#define IMOS_MW_PTZ_GUARD_PRESET_CFG        52         /**< 获取/设置 看守位信息，对应结构定义: IMOS_MW_GUARD_PRESET_CFG_S */
#define IMOS_MW_PTZ_TRACK_CFG               53         /**< 获取      巡航轨迹配置，对应结构定义: IMOS_MW_CRUISE_TRACK_CFG_S */
#define IMOS_MW_PTZ_CRUISE_PLAN_CFG         54         /**< 获取/设置 云台巡航计划配置信息，对应结构定义: IMOS_MW_CRUISE_PLAN_CFG_S */
#define IMOS_MW_PTZ_PHYPARAM_CFG            55         /**< 获取/设置 云台物理参数配置(即通用拉框放大参数)  对应结构定义: IMOS_MW_PTZ_PHYPARAM_CFG_S */
#define IMOS_MW_PTZ_DIRECTION_CFG           56         /**< 设置      云台方位信息 对应结构定义为: ULONG  参见: IMOS_MW_PTZ_DIRECTION_E */
    
/* 卡口相关: 基本配置、智能配置 */
#define IMOS_MW_PHOTO_SERVER_CFG            61         /**< 获取/设置 照片接收服务器信息，对应结构定义: IMOS_MW_PHOTO_SERVER_CFG_S */
#define IMOS_MW_FLASH_LIGHT_CFG             62         /**< 获取/设置 闪光灯配置，对应结构定义: IMOS_MW_FLASH_LIGHT_CFG_S */
#define IMOS_MW_VEHICLE_DETECTOR_CFG        63         /**< 获取/设置 车检器配置，对应结构定义: IMOS_MW_VEHICLE_DETECTOR_CFG_S */
#define IMOS_MW_RADAR_CFG                   64         /**< 获取/设置 雷达配置，对应结构定义: IMOS_MW_RADAR_CFG_S */
#define IMOS_MW_CAMERA_CAPTURE_CFG          65         /**< 获取/设置 抓拍配置，对应结构定义: IMOS_MW_CAMERA_CAPTURE_CFG_S */
#define IMOS_MW_VIDEO_DETECT_CFG            66         /**< 获取/设置 视频检测配置，对应结构定义: IMOS_MW_VIDEO_DETECT_CFG_S */
#define IMOS_MW_PLATE_IDENTIFY_CFG          67         /**< 获取/设置 车牌识别配置，对应结构定义: IMOS_MW_PLATE_IDENTIFY_CFG_S */
#define IMOS_MW_DRIVEWAY_CFG                68         /**< 获取/设置 车道配置，对应结构定义: IMOS_MW_DRIVEWAY_CFG_S */
#define IMOS_MW_SUBDEVICE_SWITCH_CFG        69         /**< 获取/设置 外设开关配置，对应结构定义: IMOS_MW_SUBDEVICE_SWITCH_CFG_S */
#define IMOS_MW_LASER_CFG                   70         /**< 获取/设置 激光配置，对应结构定义: IMOS_MW_LASER_CFG_S */
#define IMOS_MW_CAPTURE_FORMAT_CFG          71         /**< 获取/设置 抓拍图片参数配置，对应结构定义: IMOS_MW_CAPTURE_FORMAT_CFG_S */
#define IMOS_MW_POLARIZER_CFG               72         /**< 获取/设置 偏振镜配置，对应结构定义: IMOS_MW_POLARIZER_CFG_S */
#define IMOS_MW_ND_FILTER_CFG               73         /**< 获取/设置 ND滤镜配置，对应结构定义: IMOS_MW_ND_FILTER_CFG_S */

/* 电警相关: 视频源配置、智能配置、违章配置 */
#define IMOS_MW_CAMERA_BASIC_CFG            101        /**< 获取/设置 摄像机基本配置, 对应结构定义: IMOS_MW_CAMERA_BASIC_CFG_S */ 
#define IMOS_MW_EP_VIDEODETECT_CFG          102        /**< 获取/设置 视频检测配置，对应结构定义: IMOS_MW_EP_VIDEODETECT_CFG_S */
#define IMOS_MW_EP_DRIVEWAY_CFG             103        /**< 获取/设置 车道配置，对应结构定义: IMOS_MW_EP_DRIVEWAY_CFG_S */
#define IMOS_MW_DETECTAREA_CFG              104        /**< 获取/设置 检测区域配置, 对应结构定义: IMOS_MW_DETECTAREA_CFG_S */ 
#define IMOS_MW_TRIGGERLINE_CFG             105        /**< 获取/设置 触发线配置, 对应结构定义: IMOS_MW_TRIGGERLINE_CFG_S */ 
#define IMOS_MW_DRIVEWAYLINE_CFG            106        /**< 获取/设置 车道线配置, 对应结构定义: IMOS_MW_DRIVEWAYLINE_CFG_S */
#define IMOS_MW_TRAFFICLIGHT_CFG            107        /**< 获取/设置 红绿灯配置, 对应结构定义: IMOS_MW_TRAFFICLIGHT_CFG_S */ 
#define IMOS_MW_VEHICLETRACK_CFG            108        /**< 获取/设置 车辆跟踪配置, 对应结构定义: IMOS_MW_VEHICLETRACK_CFG_S */
#define IMOS_MW_TOLLGATE_CFG                109        /**< 获取/设置 卡口抓拍配置, 对应结构定义: IMOS_MW_TOLLGATE_CFG_S */
#define IMOS_MW_PECCANCY_CAPTURE_CFG        110        /**< 获取/设置 违章抓拍配置, 对应结构定义: IMOS_MW_PECCANCY_CAPTURE_CFG_S */
#define IMOS_MW_CAPTURE_IMGPROC_CFG         111        /**< 获取/设置 违章抓拍图片处理配置, 对应结构定义: IMOS_MW_CAPTURE_IMGPROC_CFG_S */
#define IMOS_MW_TRAFFICLIGHT_INTENSIFY_CFG  112        /**< 获取/设置 红绿灯加强配置, 对应结构定义: IMOS_MW_TRAFFICLIGHT_INTENSIFY_S */

/* 存储相关: 存储配置 */
#define IMOS_MW_LOCAL_STOR_INFO             150         /**< 获取/设置 本地存储信息，对应结构定义: IMOS_MW_LOCAL_STOR_INFO_S */
#define IMOS_MW_STOR_NAS_CFG                151         /**< 获取/设置 存储类型信息，参见：IMOS_MW_NAS_STOR_CFG_S */      

/* 智能球相关:场景配置 */
#define IMOS_MW_IVA_ENABLE                  300       /**< 获取/设置 智能业务使能标志，对应结构定义: BOOL_T */
#define IMOS_MW_IVA_MODE_CFG                301       /**< 获取/设置 智能业务模式配置，对应结构定义: ULONG */
#define IMOS_MW_IVA_SCENE_CFG               302       /**< 获取/设置 智能场景信息，对应结构定义: IMOS_MW_IVA_SCENE_S */
#define IMOS_MW_IVA_RULE_CFG                303       /**< 获取/设置 智能规则信息，对应结构定义: IMOS_MW_IVA_RULE_S */
#define IMOS_MW_IVA_ILLEGAL_CFG             304       /**< 获取/设置 智能违章配置，对应结构定义: IMOS_MW_IVA_ILLEGAL_CFG_S */
#define IMOS_MW_IVA_SCENE_CRUISE_PLAN       305       /**< 获取/设置 智能场景巡航计划，对应结构定义: IMOS_MW_IVA_SCENE_CRUISE_PLAN_S */
#define IMOS_MW_IVA_LP_CHECK_CFG            306       /**< 获取/设置 车牌一致性检测使能标志，对应结构定义: IMOS_MW_IVA_LP_CHECK_S */
#define IMOS_MW_IVA_CHECK_REPEAT            307       /**< 获取/设置 重复车牌过滤时间，对应结构体定义: ULONG */
 
/* 调试配置(不对用户开放) */
#define IMOS_MW_DEBUG_CFG                   500       /**< 获取/设置 调试配置，对应结构定义: IMOS_MW_DEBUG_CFG_S*/
#define IMOS_MW_LOW_DELAY_CFG               501       /**< 获取/设置 低延时模式参数，对应结构定义: ULONG */
#define IMOS_MW_AUTO_TRACK_CFG              502       /**< 获取/设置 自动跟踪配置，参数透传，设备不关注该配置 */
#define IMOS_MW_DEBUG_SERAIL                503       /**< 获取/设置 串口调试配置，对应结构定义: IMOS_MW_TRANSPORT_CFG_S */
#define IMOS_MW_SANSUO_CHECK_CFG            504       /**< 获取/设置 三所型检配置，对应结构定义: ULONG */
#define IMOS_MW_SCENE_CFG                   25        /**< 获取/设置 场景参数配置，对应结结构定义: IMOS_MW_SCENE_CFG_S */
#define IMOS_MW_HCM_LOW_DELAY_CFG           505       /**< 获取/设置 机芯低延时模式参数，对应结构定义: ULONG */
#define IMOS_MW_DRIVEWAY_EXPAND_CFG         506       /**< 获取/设置 车道扩展配置，对应结构定义: IMOS_MW_DRIVEWAY_EXPAND_CFG_S */

#define IMOS_MW_RELEASE_STRATEGY_CFG        600       /**< 获取/设置 黑白名单放行策略，对应结构定义: IMOS_MW_RELEASE_STRATEGY_CFG_S */
#define IMOS_MW_WHITE_LIST_CFG              601       /**< 获取/设置 出入口白名单配置，对应结构定义: IMOS_MW_GATE_WHITE_LIST_CFG_S */
#define IMOS_MW_BLACK_LIST_CFG              602       /**< 获取/设置 出入口黑名单配置，对用结构定义: IMOS_MW_GATE_BLACK_LIST_CFG_S*/

#if 0
#endif
/*************************************** 设备维护相关 ********************************************/
/*@brief 通用CODE长度*/
#define IMOS_MW_CODE_LEN                    48   

/*@brief 通用名称字符串长度 */
#define IMOS_MW_NAME_LEN                    64     

/*@brief 文件名称字符串长度 */
#define IMOS_MW_FILE_NAME_LEN               IMOS_MW_NAME_LEN    

/*@brief 资源编码信息字符串长度 */
#define IMOS_MW_RES_CODE_LEN                IMOS_MW_CODE_LEN

/*@brief 系统默认路径长度 */
#define IMOS_MW_DEFAULT_PATH_LEN            256

/*@brief SDK 客户端版本号长度 */
#define IMOS_MW_SDK_CLIENT_VERSION_LEN      32

/*@brief IP地址信息字符串长度 
  * IPV4: "192.168.0.102"
  * IPV6: "A1:0:8:100:200:0:0:321A"
  * 域名: "AS_server_hangzhou" */
#define IMOS_MW_IPADDR_LEN                  64  

/*@brief 注册VM时设备ID 长度  */
#define IMOS_MW_DEVICE_ID_LEN               48
/*@brief 注册管理服务器密码 长度  */
#define IMOS_MW_MANAGE_SERVER_PASSWD_LEN    16

/*@brief SNMP 团体名长度  */
#define IMOS_MW_COMMUNITY_LEN               32


/*@brief 时间 格式 */
#define IMOS_MW_TIME_FORMAT_HHMMSS          0        /**< XX:XX:XX 常见于中国，美国，英国等*/
#define IMOS_MW_TIME_FORMAT_HHMMSS_PM       1        /**< XX:XX:XX p.m. 常见于除西班牙以外的西班牙语国家*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS_PM     2        /**< XX:XX:XX PM 常见于除英国以外的英语国家*/
#define IMOS_MW_TIME_FORMAT_PM_HHMMSS       3        /**< PM XX:XX:XX 常见于中文(新加坡)*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS        4        /**< 下午 XX:XX:XX 常见于中文(台湾)*/

/*@brief 日期 格式 */
#define IMOS_MW_DATE_FORMAT_YYYYMMDD        0        /**< XXXX-XX-XX 年月日 */
#define IMOS_MW_DATE_FORMAT_MMDDYYYY        1        /**< XX-XX-XXXX 月日年 */
#define IMOS_MW_DATE_FORMAT_YYYY_MM_DD      2        /**< XXXX年XX月XX日 */
#define IMOS_MW_DATE_FORMAT_MM_DD_YYYY      3        /**< XX月XX日XXXX年 */
#define IMOS_MW_DATE_FORMAT_YYYY_MM_DD_XX   4        /**< XXXX年XX月XX日 星期X */

/*@brief 版本信息长度 */
#define IMOS_MW_VERSION_LEN                 256 

/*@brief 用户名最大长度 */
#define IMOS_MW_USER_NAME_LEN               32   

/*@brief 用户密码最大长度 */
#define IMOS_MW_USER_PASSWORD_LEN           32  

/**@brief 用户级别 */
#define IMOS_MW_USERLEVEL_ADMINISTRATOR     0        /**< 管理员 */
#define IMOS_MW_USERLEVEL_OPERATOR          1        /**< 操作员 */
#define IMOS_MW_USERLEVEL_USER              2        /**< 普通用户 */
#define IMOS_MW_USERLEVEL_ANONYMOUS         3        /**< 匿名用户 */
#define IMOS_MW_USERLEVEL_EXTENDED          4        /**< 扩展用户 */

/**@brief 设备能力类型 */
#define IMOS_MW_CAP_FUNC                    0        /**< 业务能力 */
#define IMOS_MW_CAP_IMAGE                   1        /**< 图像能力 */
#define IMOS_MW_CAP_HARDWARE                2        /**< 硬件能力 */
#define IMOS_MW_CAP_ENCODE                  3        /**< 编码能力 */
#define IMOS_MW_CAP_NETWORK                 4        /**< 网口能力 */
#define IMOS_MW_CAP_OSD                     5        /**< OSD能力 */
#define IMOS_MW_CAP_INTELLIGENT             6        /**< 智能能力 */
#define IMOS_MW_CAP_SERIAL                  7        /**< 串口能力 */

/**@brief 参数类型 */
#define IMOS_MW_PARAM_TYPE_OPTICS_VIDEO     0        /**< 视频的图像参数 */
#define IMOS_MW_PARAM_TYPE_OPTICS_PICTURE   1        /**< 照片的图像参数 */
#define IMOS_MW_PARAM_TYPE_PECCANCY         2        /**< 违章默认参数 */

/**@brief 日志级别 */
#define IMOS_SDK_LOG_CLOSE                  0        /**< 关闭日志 */
#define IMOS_SDK_LOG_DEBUG                  1        /**< debug级别 */
#define IMOS_SDK_LOG_INFO                   2        /**< info级别 */
#define IMOS_SDK_LOG_WARN                   3        /**< warn级别 */
#define IMOS_SDK_LOG_ERROR                  4        /**< error级别 */
#define IMOS_SDK_LOG_FATAL                  5        /**< fatal级别 */

/**@brief 计划状态 */
#define IMOS_MW_PLAN_TYPE_MOVE_DETECT       0        /**< 运动检测计划 */
#define IMOS_MW_PLAN_TYPE_INPUT_SWITCH      1        /**< 开关量输入计划 */
#define IMOS_MW_PLAN_TYPE_CRUISE            2        /**< 巡航计划 */
#define IMOS_MW_PLAN_TYPE_STOR              3        /**< 存储计划 */
#define IMOS_MW_PLAN_TYPE_SCENE_SWITCH      4        /**< 场景切换 */
#define IMOS_MW_PLAN_TYPE_AUDIO_DETECT      5        /**< 声音检测计划 */
#define IMOS_MW_PLAN_TYPE_TAMPER_DETECT     6        /**< 遮挡检测计划 */

#if 0
#endif
/**************************************** 串口相关 ***************************************/
/**@brief 串口类型 */
#define IMOS_MW_SERIAL_TYPE_RS232                    1             /**< rs232 */
#define IMOS_MW_SERIAL_TYPE_RS422                    2             /**< rs422 */
#define IMOS_MW_SERIAL_TYPE_RS485                    3             /**< rs485 */

/**@brief 串口模式 */
#define IMOS_MW_SERIAL_MODE_PTZ                      1             /**< 云台控制 */
#define IMOS_MW_SERIAL_MODE_TRANS                    2             /**< 透明通道 */
#define IMOS_MW_SERIAL_MODE_CONSOLE                  3             /**< 控制台 */
#define IMOS_MW_SERIAL_MODE_COMMON                   4             /**< 通用串口 */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_H       5             /**< 车检器 H, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_S       6             /**< 车检器 S, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_RADAR_C                  7             /**< 雷达 C, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_LASER                    8             /**< 激光, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_CASEALARM                9             /**< 机箱告警 */  
#define IMOS_MW_SERIAL_MODE_TRAFFICLIGHT_S           10            /**< 红灯信号检测器 S */  
#define IMOS_MW_SERIAL_MODE_RADAR_A                  11            /**< 雷达 A, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_OSD                      12            /**< OSD叠加 */
#define IMOS_MW_SERIAL_MODE_RADAR_H                  13            /**< 雷达 H, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_Q       14            /**< 车检器 Q, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_RADAR_C_CONTROLLER       15            /**< 雷达 C控制器, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_LOCAL_PTZ_CTRL           16            /**< 本地云台控制 */
#define IMOS_MW_SERIAL_MODE_RFID                     17            /**< RFID, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_U       18            /**< 车检器 U, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_TRAFFICLIGHT_U           19            /**< 红灯信号检测器 U */
#define IMOS_MW_SERIAL_MODE_RADAR_W                  20            /**< 雷达 W, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_RADAR_Z                  21            /**< 雷达 Z, 使用模式参见: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_SWITCHVALUE_TO_485            22            /**< 外设开关量转485 */
#define IMOS_MW_SERIAL_MODE_COUNT                    22            /**< 串口模式最大个数 */ 

/*************************************** 网口相关 ********************************************/
/*@brief PPPoE用户名长度  */
#define IMOS_MW_PPPOE_USERNAME_LEN               32  

/*@brief PPPoE密码长度 */
#define IMOS_MW_PPPOE_PASSWORD_LEN               32

/*@brief UNP用户名长度  */
#define IMOS_MW_UNP_USERNAME_LEN                 32  

/*@brief UNP密码长度 */
#define IMOS_MW_UNP_PASSWORD_LEN                 32

/*@brief WIFI SSID长度 */
#define IMOS_MW_WIFI_SSID_LEN                    44

/*@brief WIFI KEY长度 */
#define IMOS_MW_WIFI_KEY_LEN                     44

/* 一次扫描最多支持的无线网络个数 */
#define IMOS_MW_WIFI_NETWORK_MAX_COUNT           40


/**@brief IP获取方式 */
#define IMOS_MW_IP_GET_TYPE_STATIC               0        /**< 静态获取 */
#define IMOS_MW_IP_GET_TYPE_PPPOE                1        /**< pppoe分配 */
#define IMOS_MW_IP_GET_TYPE_DHCP                 2        /**< DHCP分配 */

/**@brief 网口类型 */
#define IMOS_MW_PORT_MODE_ELECTRONIC             0        /**< 电口 */
#define IMOS_MW_PORT_MODE_FIBER                  1        /**< 光口 */
#define IMOS_MW_PORT_MODE_EPON                   2        /**< EPON */
#define IMOS_MW_PORT_MODE_LRE                    3        /**< LRE电口 */

/**@brief 网口工作模式 */
#define IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION    0    /**< 自协商 */
#define IMOS_MW_ETH_WORKMODE_10M_FULL            1    /**< 10M FULL */
#define IMOS_MW_ETH_WORKMODE_10M_HALF            2    /**< 10M HALF */
#define IMOS_MW_ETH_WORKMODE_100M_FULL           3    /**< 100M FULL */
#define IMOS_MW_ETH_WORKMODE_100M_HALF           4    /**< 100M HALF */
#define IMOS_MW_ETH_WORKMODE_1000M_FULL          5    /**< 1000M FULL */

/**@brief WiFi认证方式 */
#define  IMOS_MW_WIFI_AUTH_MODE_OPEN             0   /**< OPEN */
#define  IMOS_MW_WIFI_AUTH_MODE_SHARED           1   /**< SHARED */     
#define  IMOS_MW_WIFI_AUTH_MODE_WEPAUTO          2   /**< WEPAUTO */
#define  IMOS_MW_WIFI_AUTH_MODE_WPA              3   /**< WPA */
#define  IMOS_MW_WIFI_AUTH_MODE_WPAPSK           4   /**< WPAPSK */
#define  IMOS_MW_WIFI_AUTH_MODE_WPANONE          5   /**< WPANONE */
#define  IMOS_MW_WIFI_AUTH_MODE_WPA2             6   /**< WPA2 */
#define  IMOS_MW_WIFI_AUTH_MODE_WPA2PSK          7   /**< WPA2PSK */        
#define  IMOS_MW_WIFI_AUTH_MODE_WPA1WPA2         8   /**< WPA1WPA2 */   
#define  IMOS_MW_WIFI_AUTH_MODE_WPA1PSKWPA2PSK   9   /**< WPA1PSKWPA2PSK */
#define  IMOS_MW_WIFI_AUTH_MODE_UNKNOW           10  /**< UNKNOW */

/**@brief WiFi加密方式 */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_NONE          0   /**< NONE */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_WEP           1   /**< WEP */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_TKIP          2   /**< TKIP */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_AES           3   /**< AES */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_TKIPAES       4   /**< TKIPAES */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_UNKNOW        5   /**< UNKNOW */

/**@brief WiFi工作模式 */
#define IMOS_MW_WIFI_NETWORK_TYPE_INFRA          0    /**< InfraStructure */
#define IMOS_MW_WIFI_NETWORK_TYPE_ADHOC          1    /**< AdHoc */

/**@brief WiFi无线模式 */
#define IMOS_MW_WIRELESEE_MODE_LEGACY_11BG_MIXED   0        /**< legacy 11b/g mixed */
#define IMOS_MW_WIRELESEE_MODE_LEGACY_11B_ONLY     1        /**< legacy 11b only */
#define IMOS_MW_WIRELESEE_MODE_LEGACY_11A_ONLY     2        /**< legacy 11a only */
#define IMOS_MW_WIRELESEE_MODE_LEGACY_11G_ONLY     3        /**< legacy 11g only */
#define IMOS_MW_WIRELESEE_MODE_LEGACY_11ABG_MIXED  4        /**< legacy 11a/b/g mixed */
#define IMOS_MW_WIRELESEE_MODE_11N_ONLY            5        /**< 11n only */
#define IMOS_MW_WIRELESEE_MODE_11GN_MIXED          6        /**< 11g/n mixed   */
#define IMOS_MW_WIRELESEE_MODE_11AN_MIXED          7        /**< 11a/n mixed   */
#define IMOS_MW_WIRELESEE_MODE_11ABGN_MIXED        8        /**< 11a/b/g/n mixed */
#define IMOS_MW_WIRELESEE_MODE_11BGN_MIXED         9        /**< 11b/g/n mixed */
#define IMOS_MW_WIRELESEE_MODE_11AGN_MIXED         10       /**< 11a/g/n mixed */


#if 0
#endif
/*************************************** 图像相关 ********************************************/
/**@brief 图像类型 */
#define IMOS_MW_IMAGE_TYPE_VIDEO                0       /**< 视频图像 */
#define IMOS_MW_IMAGE_TYPE_CAPTURE              1       /**< 抓拍图像 */
#define IMOS_MW_IMAGE_TYPE_COUNT                2       /**< 图像类型个数 */

/**@brief 白平衡模式 */
#define IMOS_MW_WB_AUTO                         0       /**< 自动白平衡 */
#define IMOS_MW_WB_FINETUNE                     1       /**< 微调白平衡 */
#define IMOS_MW_WB_INDOOR                       2       /**< 室内白平衡 */
#define IMOS_MW_WB_OUTDOOR                      3       /**< 室外白平衡 */
#define IMOS_MW_WB_AUTO_MERCURY                 4       /**< 自动水银灯白平衡 */ 
#define IMOS_MW_WB_FINETUNE_NIGHT               5       /**< 夜间微调白平衡  */

/**@brief 对焦模式 */
#define IMOS_MW_FOCUS_AUTO                      0       /**< 自动对焦 */
#define IMOS_MW_FOCUS_MANUAL                    1       /**< 手动对焦 */
#define IMOS_MW_FOCUS_PUSH                      2       /**< 一键对焦 */
#define IMOS_MW_FOCUS_PUSH_NIGHTINFRARED        3       /**< 一键对焦(夜间红外) */

/**@brief 快门值单位 */
#define IMOS_MW_SHUTTER_UNIT_MICSEC             0       /**< 微秒 */
#define IMOS_MW_SHUTTER_UNIT_DENOMINATOR        1       /**< 分母表示法，单位: 1/秒 */

/**@brief 曝光模式 */
#define IMOS_MW_EXPOSURE_AUTO                   0       /**< 自动曝光 */
#define IMOS_MW_EXPOSURE_CUSTOM                 1       /**< 自定义曝光 */
#define IMOS_MW_EXPOSURE_SHUTTER                2       /**< 快门优先 */
#define IMOS_MW_EXPOSURE_IRIS                   3       /**< 光圈优先 */
#define IMOS_MW_EXPOSURE_GAIN                   4       /**< 增益优先 */
#define IMOS_MW_EXPOSURE_INDOOR_50HZ            5       /**< 室内50HZ */
#define IMOS_MW_EXPOSURE_INDOOR_60HZ            6       /**< 室内60HZ */
#define IMOS_MW_EXPOSURE_MANUAL                 7       /**< 手动曝光 */

/**@brief 宽动态模式 */
#define IMOS_MW_WDR_DISABLE                     0       /**< 关闭 */
#define IMOS_MW_WDR_ENABLE                      1       /**< 开启 */
#define IMOS_MW_WDR_AUTO                        2       /**< 自动 */

/**@brief 测光模式 */
#define IMOS_MW_METERING_CENTER                 0       /**< 中央权重 */
#define IMOS_MW_METERING_AREA                   1       /**< 区域测光权重 */
#define IMOS_MW_METERING_HME                    2       /**< 强光抑制 */
#define IMOS_MW_METERING_VEHICLE                3       /**< 车辆测光 */

/**@brief 昼夜模式 */
#define IMOS_MW_DAYNIGHT_AUTO                   0       /**< 自动模式 */
#define IMOS_MW_DAYNIGHT_COLOR                  1       /**< 彩色 */
#define IMOS_MW_DAYNIGHT_BW                     2       /**< 黑白 */

/**@brief 锐度模式 */
#define IMOS_MW_SHARPNESS_AUTO                  0       /**< 自动模式 */
#define IMOS_MW_SHARPNESS_MANUAL                1       /**< 手动模式 */

/**@brief 镜像模式 */
#define IMOS_MW_MIRROR_MODE_NONE                0       /**< 正常模式 */
#define IMOS_MW_MIRROR_MODE_FLIP                1       /**< 垂直翻转 */
#define IMOS_MW_MIRROR_MODE_MIRROR              2       /**< 水平翻转 */
#define IMOS_MW_MIRROR_MODE_FLIP_MIRROR         3       /**< 垂直水平同时翻转 */
#define IMOS_MW_MIRROR_MODE_ROTATE_CLOCKWISE    4       /**< 顺时针旋转90度 */

/**@brief 红外控制模式 */
#define IMOS_MW_IR_CTRL_OVERALL                 0       /**< 全局兼顾自动控制 */
#define IMOS_MW_IR_CTRL_EXTREME                 1       /**< 过曝抑制自动控制 */
#define IMOS_MW_IR_CTRL_PRESET                  2       /**< Ir预置控制-道路模式 */
#define IMOS_MW_IR_CTRL_MANUAL                  3       /**< Ir手动控制 */
#define IMOS_MW_IR_CTRL_PRESET_YARD             4       /**< Ir预置控制-园区模式 */

/**@brief 扩展环境条件最大个数 */
#define IMOS_MW_CONDITION_MAX_NUM               4       

/**@brief 环境条件类型 */
#define IMOS_MW_CONDITION_ILLUMINATION          0       /**< 环境照度 */
#define IMOS_MW_CONDITION_TILT_ANGLE            1       /**< 云台倾斜角度 */

/**@brief 场景环境类型 */
#define IMOS_MW_IPC_SCENE_TYPE_CUSTOM              0     /* 自定义 */
#define IMOS_MW_IPC_SCENE_TYPE_INDOOR              1     /* 室内 */
#define IMOS_MW_IPC_SCENE_TYPE_COMMON              2     /* 通用 */
#define IMOS_MW_IPC_SCENE_TYPE_PLATE               3     /* 车牌 */
#define IMOS_MW_IPC_SCENE_TYPE_STARLIGHT           4     /* 星光 */
#define IMOS_MW_IPC_SCENE_TYPE_OBJECTIVE           5     /* 客观 */
#define IMOS_MW_IPC_SCENE_TYPE_HIGHSENSITIVE       6     /* 高感光 */  
#define IMOS_MW_IPC_SCENE_TYPE_LIGHTINHIBITION     7     /* 强光抑制 */  

/**@brief 场景环境类型(卡口) */
#define IMOS_MW_HTS_SCENE_TYPE_NORMAL               50     /* 普通 */
#define IMOS_MW_HTS_SCENE_TYPE_WEAKBACKLIGHTING     51     /* 弱逆光 */
#define IMOS_MW_HTS_SCENE_TYPE_INTENSEBACKLIGHTING  52     /* 强逆光 */
#define IMOS_MW_HTS_SCENE_TYPE_WEAKFRONTLIGHTING    53     /* 弱顺光 */
#define IMOS_MW_HTS_SCENE_TYPE_INTENSEFRONTLIGHTING 54     /* 强顺光 */
#define IMOS_MW_HTS_SCENE_TYPE_OBJECTIVE            55     /* 客观 */

/**@brief 补光模式 */
#define IMOS_MW_LIGHT_MODE_NONE                    0     /**< 无补光灯 */
#define IMOS_MW_LIGHT_MODE_WHITE                   1     /**< 白光灯模式 */
#define IMOS_MW_LIGHT_MODE_IR                      2     /**< 红外灯模式 */            

#if 0
#endif
/*************************************** OSD相关 ********************************************/
/*@brief OSD 叠加内容的长度 */
#define IMOS_MW_OSD_INFO_LEN                      60    

/*@brief 叠加 OSD 最大个数 */
#define IMOS_MW_INFO_OSD_MAX_NUM                  3   

/*@brief OSD 叠加内容最大行数 */
#define IMOS_MW_INFO_OSD_LINE_MAX                 8

/*@brief 遮盖 OSD 最大个数 */
#define IMOS_MW_COVER_OSD_MAX_NUM                 8 

/*@brief 叠加内容类型 */
#define IMOS_MW_OSD_INFO_TYPE_UNUSED              0    /* 不使用 */
#define IMOS_MW_OSD_INFO_TYPE_USERDEF             1    /* 自定义 */
#define IMOS_MW_OSD_INFO_TYPE_DATETIME            2    /* 时间日期 */
#define IMOS_MW_OSD_INFO_TYPE_PTZOPER             3    /* 云台控制者 */
#define IMOS_MW_OSD_INFO_TYPE_PTZCOORDINATS       4    /* 云台坐标 */
#define IMOS_MW_OSD_INFO_TYPE_CRUISEINFO          5    /* 巡航信息 */
#define IMOS_MW_OSD_INFO_TYPE_ZOOMINFO            6    /* 变倍信息 */
#define IMOS_MW_OSD_INFO_TYPE_PRESETINFO          7    /* 预置位信息 */
#define IMOS_MW_OSD_INFO_TYPE_ALARMINFO           8    /* 报警信息 */
#define IMOS_MW_OSD_INFO_TYPE_ENCODEINFO          9    /* 编码信息 */
#define IMOS_MW_OSD_INFO_TYPE_SERIALMSG           10   /* 串口消息 */
#define IMOS_MW_OSD_INFO_TYPE_PTZDIRECTION        11   /* 云台方位信息 */   

/*@brief 其他 OSD 类型 */
#define IMOS_MW_OSD_PIC_TIME                      0     /**< 抓拍照片 时间OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_SPEED             1     /**< 抓拍照片 车速OSD */
#define IMOS_MW_OSD_PIC_LIMITED_SPEED             2     /**< 抓拍照片 限速OSD */
#define IMOS_MW_OSD_PIC_PECCANCY_TYPE             3     /**< 抓拍照片 违章类型OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_COLOR             4     /**< 抓拍照片 车身颜色OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_LOGO              5     /**< 抓拍照片 车标OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_TYPE              6     /**< 抓拍照片 车型OSD */
#define IMOS_MW_OSD_PIC_DRIVINGTYPE               7     /**< 抓拍照片 车道行驶类型OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_PLATE             8     /**< 抓拍照片 车牌(包含车牌颜色) */
#define IMOS_MW_OSD_PIC_VEHICLE_WAYID             9     /**< 抓拍照片 车道号 */
#define IMOS_MW_OSD_PIC_VEHICLE_CAMERAID          10    /**< 抓拍照片 摄像机ID */
#define IMOS_MW_OSD_PIC_VEHICLE_DIRECTION         11    /**< 抓拍照片 方向 */
#define IMOS_MW_OSD_PIC_VEHICLE_CAP_DIRECTION     12    /**< 抓拍照片 抓拍方向 */
#define IMOS_MW_OSD_PIC_VEHICLE_VERIFY            13    /**< 抓拍照片 防伪码 */
#define IMOS_MW_OSD_PIC_VEHICLE_NAME              14    /**< 抓拍照片 配置项名称 */
#define IMOS_MW_OSD_PIC_VEHICLE_SPEED_PERCENT     15    /**< 抓拍照片 超速百分比OSD */ 
#define IMOS_MW_OSD_MJPEG_VEHICLE_CAP_DIRECTION   16    /**< MJPEG 行驶方向 */ 
#define IMOS_MW_OSD_MJPEG_VEHICLE_ROAD_MESSAGE    17    /**< MJPEG 路口信息 */
#define IMOS_MW_OSD_MJPEG_VEHICLE_TIME            18    /**< MJPEG 时间 */
#define IMOS_MW_OSD_PIC_TIME_MILISEC              19    /**< 抓拍照片 毫秒时间OSD > */
#define IMOS_MW_OSD_MLPEG_VEHICLE_TIME_MILISEC    20    /**< MJPEG时间 毫秒时间OSD > */
#define IMOS_MW_OSD_TYPE_BUTT                     21    /**< 支持的抓拍OSD个数 */

/*@brief OSD 字体样式 */
#define IMOS_MW_OSD_FONT_STYLE_BACKGROUND         0    /**< 背景 */
#define IMOS_MW_OSD_FONT_STYLE_STROKES            1    /**< 描边 */ 
#define IMOS_MW_OSD_FONT_STYLE_HOLLOW             2    /**< 空心 */
#define IMOS_MW_OSD_FONT_STYLE_NORMAL             3    /**< 正常 */

/*@brief OSD 字体 */
#define IMOS_MW_OSD_FONT_TYPE_ADVANCE             0    /**< 增强(默认) */
#define IMOS_MW_OSD_FONT_TYPE_STANDARD            1    /**< 标准 */

/*@brief OSD 对齐 */
#define IMOS_MW_OSD_FONT_ALIGN_LEFT              0   /**< 左对齐 */
#define IMOS_MW_OSD_FONT_ALIGN_RIGHT             1   /**< 右对齐 */

/*@brief OSD 字体大小 */
#define IMOS_MW_OSD_FONT_SIZE_LARGE               0    /**< 大 */
#define IMOS_MW_OSD_FONT_SIZE_MIDDLE              1    /**< 中 */
#define IMOS_MW_OSD_FONT_SIZE_SMALL               2    /**< 小 */

/*@brief OSD 颜色 */
#define IMOS_MW_OSD_COLOR_WHITE                   0    /**< 白 */
#define IMOS_MW_OSD_COLOR_RED                     1    /**< 红 */
#define IMOS_MW_OSD_COLOR_YELLOW                  2    /**< 黄 */
#define IMOS_MW_OSD_COLOR_BLUE                    3    /**< 蓝 */
#define IMOS_MW_OSD_COLOR_BLACK                   4    /**< 黑 */
#define IMOS_MW_OSD_COLOR_GREEN                   5    /**< 绿 */
#define IMOS_MW_OSD_COLOR_PURPLE                  6    /**< 紫 */

/*@brief OSD 透明度 */
#define IMOS_MW_OSD_ALPHA_NO                      0    /**< 不透明 */
#define IMOS_MW_OSD_ALPHA_SEMI                    1    /**< 半透明 */
#define IMOS_MW_OSD_ALPHA_ALL                     2    /**< 全透明 */

#define IMOS_MW_COM_OSD_MAX_LEN 644

#if 0
#endif
/*************************************** 媒体流相关 ********************************************/
/**@brief 传输模式 */
#define IMOS_MW_TRANSFER_MODE_RTP_UDP           0        /**< UDP＋RTP 报文模式 */
#define IMOS_MW_TRANSFER_MODE_RTP_TCP           1        /**< TCP＋RTP 报文模式 */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW1_TCP      2        /**< TCP＋Uniview1 报文模式 */        
#define IMOS_MW_TRANSFER_MODE_TS_TCP            3        /**< TCP＋TS 报文模式 */
#define IMOS_MW_TRANSFER_MODE_TS_UDP            4        /**< UDP＋TS 报文模式 */
#define IMOS_MW_TRANSFER_MODE_HTTP              5        /**< 基于RTP/RTSP/HTTP/TCP承载方式 */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW2_TCP      6        /**< TCP＋Uniview2 报文模式 */  
#define IMOS_MW_TRANSFER_MODE_LOCAL_IMAGE       7        /**< 本地照片导入 报文模式 */  
#define IMOS_MW_TRANSFER_MODE_EZR_TMS           8        /**< TCP＋Uniview2 报文模式 EZR使用 */
#define IMOS_MW_TRANSFER_MODE_TMS_IMAGE         9        /**< TMS照片模式 报文模式 */



/**@brief 流ID */
#define IMOS_MW_STREAM_ID_MAIN                  0        /**< 主流 */
#define IMOS_MW_STREAM_ID_AUX                   1        /**< 辅流 */
#define IMOS_MW_STREAM_ID_THIRD                 2        /**< 三流 */
#define IMOS_MW_STREAM_ID_FOUTH                 3        /**< 四流 */

/**@brief 媒体流类型 */
#define IMOS_MW_MEDIA_VIDEO                     0       /**< 实况流 */
#define IMOS_MW_MEDIA_VOICE_TALK                1       /**< 语音对讲 */
#define IMOS_MW_MEDIA_VOICE_BROADCAST           2       /**< 语音广播 */

/**@brief 码流类型 */
#define IMOS_MW_STREAM_TYPE_TS                  0       /**<  TS  */
#define IMOS_MW_STREAM_TYPE_H3C_ES              1       /**<  H3C ES RTP  */
#define IMOS_MW_STREAM_TYPE_PS                  2       /**<  PS  */
#define IMOS_MW_STREAM_TYPE_UNIVIEW             6       /**< 宇视卡口电警协议 */

/**@brief 码流传输模式 */
#define IMOS_MW_CONNECT_TYPE_UDP                0       /**<  UDP  */
#define IMOS_MW_CONNECT_TYPE_TCP                1       /**<  TCP  */
#define IMOS_MW_CONNECT_TYPE_RTP                2       /**<  RTP  */
#define IMOS_MW_CONNECT_TYPE_RTP_NO_RTCP        3       /**< RTP no rtcp*/
#define IMOS_MW_CONNECT_TYPE_AUTO               4       /**< 自适应 */
#define IMOS_MW_CONNECT_TYPE_HTTP               5       /**< RTP/RTSP/HTTP/TCP 承载方式 */

/**@brief GOP模式 */
#define IMOS_MW_GOP_TYPE_IP                     0       /**< IP */
#define IMOS_MW_GOP_TYPE_IBP                    1       /**< IBP */
#define IMOS_MW_GOP_TYPE_IBBP                   2       /**< IBBP */
#define IMOS_MW_GOP_TYPE_I                      3       /**< I */

/**@brief 编码模式 */
#define IMOS_MW_ENCODE_MODE_CBR                 0       /**< CBR方式 */
#define IMOS_MW_ENCODE_MODE_VBR                 1       /**< VBR方式 */

/**@brief 视频编码格式 */
#define IMOS_MW_STREAM_FORMAT_MPEG1             0       /**< MPEG1 */
#define IMOS_MW_STREAM_FORMAT_MPEG2             1       /**< MPEG2 */
#define IMOS_MW_STREAM_FORMAT_MPEG4             2       /**< MPEG4 */
#define IMOS_MW_STREAM_FORMAT_MJPEG             3       /**< MJPEG */
#define IMOS_MW_STREAM_FORMAT_H263              4       /**< H263 */
#define IMOS_MW_STREAM_FORMAT_H263PLUS          5       /**< H263+ */
#define IMOS_MW_STREAM_FORMAT_H264              6       /**< H.264 */
#define IMOS_MW_STREAM_FORMAT_AUTO              7       /**< 自适应(解码) */
#define IMOS_MW_STREAM_FORMAT_MPEG4_DS          8       /**< MPEG4-ds */
#define IMOS_MW_STREAM_FORMAT_MPEG2_DS          9       /**< MPEG2-ds */ 
#define IMOS_MW_STREAM_FORMAT_MPEG4_2           10      /**< MPEG4 辅流 */    
#define IMOS_MW_STREAM_FORMAT_H264_2            11      /**< H264 辅流 */   
#define IMOS_MW_STREAM_FORMAT_JPEG              12      /**< JPEG */ 

/**@brief 音频编码格式 */
#define IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2       0       /**< MPEG1_LAYER2 */
#define IMOS_MW_AUDIO_ENCODE_G711A              1       /**< G.711A */
#define IMOS_MW_AUDIO_ENCODE_G711U              2       /**< G.711U */
#define IMOS_MW_AUDIO_ENCODE_ADPCM              3       /**< ADPCM */
#define IMOS_MW_AUDIO_ENCODE_OGG                4       /**< OGG */
#define IMOS_MW_AUDIO_ENCODE_AUTO               5       /**< 自动 */
#define IMOS_MW_AUDIO_ENCODE_AAC                6       /**< AAC */

/**@brief 输出音量 */
#define IMOS_MW_AUDIO_VOLUME_REDUCE_8           1 
#define IMOS_MW_AUDIO_VOLUME_REDUCE_4           2
#define IMOS_MW_AUDIO_VOLUME_REDUCE_2           3
#define IMOS_MW_AUDIO_VOLUME_ZOOM_1             4
#define IMOS_MW_AUDIO_VOLUME_ZOOM_2             5
#define IMOS_MW_AUDIO_VOLUME_ZOOM_4             6
#define IMOS_MW_AUDIO_VOLUME_ZOOM_8             7

/**@brief 采样率 */
#define IMOS_MW_AUDIO_SAMPLING_8000             0 
#define IMOS_MW_AUDIO_SAMPLING_16000            1
#define IMOS_MW_AUDIO_SAMPLING_22050            2
#define IMOS_MW_AUDIO_SAMPLING_24000            3
#define IMOS_MW_AUDIO_SAMPLING_32000            4
#define IMOS_MW_AUDIO_SAMPLING_44100            5
#define IMOS_MW_AUDIO_SAMPLING_48000            6
#define IMOS_MW_AUDIO_SAMPLING_96000            7

/**@brief 音频通道 */
#define IMOS_MW_AUDIO_CHANNEL_STEREO            0        /**< 立体声 */
#define IMOS_MW_AUDIO_CHANNEL_L                 1        /**< 左声道 */
#define IMOS_MW_AUDIO_CHANNEL_R                 2        /**< 右声道 */
#define IMOS_MW_AUDIO_CHANNEL_MONO              3        /**< 单声道 */

/**@brief 音频编码量化位数 */
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_8       8
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_16      16
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_32      32

/**@brief 网络协议 */
#define IMOS_MW_PROTOCOL_UDP                    0       /**< UDP协议 */
#define IMOS_MW_PROTOCOL_TCP                    1       /**< TCP协议*/

#define IMOS_MW_AUTO_SEND_MAX_NUM               4       /**< 最大重启自动发送流数 */


#if 0
#endif
/**************************************** 告警布防相关 ***************************************/
/*@brief 单个告警，联动动作最大个数 */ 
#define IMOS_MW_ACT_PARAM_NUM                           5   

/*@brief 运动检测区域最大个数 */ 
#define IMOS_MW_MOTION_DETECT_AREA_MAX                  4  

/*@brief 区域运动量最大个数 */ 
#define IMOS_MW_DETECTED_ACTIVITY_MAX                   60  

/*@brief 遮挡检测区域最大个数 */ 
#define IMOS_MW_TAMPER_DETECT_AREA_MAX                  1  

/*@brief 单个用户支持的最大订阅个数，值待确认! */ 
#define IMOS_MW_USER_SUBSCRIBE_NUM_MAX                  2

/*@brief 开关量名称最大有效长度 */
#define IMOS_MW_SWITCH_NAME_LEN                         60

/*@brief 一次最多获取30帧的音量信息 */ 
#define IMOS_MW_VOLUME_INFO_FRAME_MAX                   30 

/**@brief 告警类型 */
#define IMOS_MW_ALARM_TYPE_SYSTEM                       0x10000        /**< 设备类告警 */
#define IMOS_MW_ALARM_TYPE_STOR                         0x20000        /**< 存储类告警 */ 
#define IMOS_MW_ALARM_TYPE_EVENT                        0x40000        /**< 事件类告警 */
#define IMOS_MW_ALARM_TYPE_BUTT                         0xFFFFFFFF    /**< 无效值，告警订阅时表示同时订阅所有类型的告警 */

/**@brief 告警具体类型 */
#define IMOS_MW_ALARM_SYSTEM_HIGH_TEMPERATURE           0x10001        /**< 高温告警 */
#define IMOS_MW_ALARM_SYSTEM_LOW_TEMPERATURE            0x10002        /**< 低温告警 */
#define IMOS_MW_ALARM_SYSTEM_TEMPERATURE_RESUME         0x10003        /**< 温度告警恢复 */

#define IMOS_MW_ALARM_STOR_FULL_PRE                     0x20010        /**< 存储即将满告警 */
#define IMOS_MW_ALARM_STOR_FULL                         0x20011        /**< 满存储告警 */
#define IMOS_MW_ALARM_STOR_FAILED                       0x20012        /**< 存储读写失败告警 */
#define IMOS_MW_ALARM_STOR_FAILED_RESUME                0x20013        /**< 存储读写失败告警恢复 */
#define IMOS_MW_ALARM_STOR_USB_FAILED                   0x20014        /**< 前端缓存失败告警 */
#define IMOS_MW_ALARM_STOR_USB_FAILED_RESUME            0x20015        /**< 前端缓存失败告警恢复 */
#define IMOS_MW_ALARM_STOR_STOPPED                      0x20016        /**< 存储停止告警 */
#define IMOS_MW_ALARM_EXT_STOR_FULL_PRE                 0x20017        /**< 外部存储即将满告警 */
#define IMOS_MW_ALARM_EXT_STOR_FULL                     0x20018        /**< 外部存储满存储告警 */
#define IMOS_MW_ALARM_EXT_STOR_FAILED                   0x20019        /**< 外部存储失败告警 */
#define IMOS_MW_ALARM_EXT_STOR_FAILED_RESUME            0x20020        /**< 外部存储失败告警恢复 */

#define IMOS_MW_ALARM_EVENT_DEVICE_ONLINE               0x40001        /**< 设备上线告警 */
#define IMOS_MW_ALARM_EVENT_DEVICE_OFFLINE              0x40002        /**< 设备下线告警 */
#define IMOS_MW_ALARM_EVENT_VIDEO_LOST                  0x40003        /**< 视频丢失告警 */
#define IMOS_MW_ALARM_EVENT_VIDEO_LOST_RESUME           0x40004        /**< 视频丢失告警恢复 */
#define IMOS_MW_ALARM_EVENT_MOVE_DETECT                 0x40005        /**< 运动检测告警 */
#define IMOS_MW_ALARM_EVENT_MOVE_DETECT_RESUME          0x40006        /**< 运动检测告警恢复 */
#define IMOS_MW_ALARM_EVENT_MASK_DETECT                 0x40007        /**< 遮挡侦测告警 */
#define IMOS_MW_ALARM_EVENT_MASK_DETECT_RESUME          0x40008        /**< 遮挡侦测告警恢复 */
#define IMOS_MW_ALARM_EVENT_INPUT_SWITCH                0x40009        /**< 输入开关量告警 */
#define IMOS_MW_ALARM_EVENT_INPUT_SWITCH_RESUME         0x4000A        /**< 输入开关量告警恢复 */
#define IMOS_MW_ALARM_EVENT_AUDIO_DETECT                0x4000F        /**< 声音检测告警 */
#define IMOS_MW_ALARM_EVENT_AUDIO_DETECT_RESUME         0x40010        /**< 声音检测告警恢复 */

/**@brief 告警联动动作 */
#define IMOS_MW_ACT_CMD_PRESET                          0               /**< 联动预置位, 对应参数: 预置位ID */
#define IMOS_MW_ACT_CMD_OUTSWITCH                       1               /**< 联动开关量输出, 对应参数: 开关量ID */
#define IMOS_MW_ACT_CMD_STOR                            2               /**< 联动存储, 暂不支持 */
#define IMOS_MW_ACT_CMD_LED                             3               /**< 联动指示灯, 暂不支持 */
#define IMOS_MW_ACT_CMD_BUZZER                          4               /**< 联动蜂鸣器，暂不支持 */  
#define IMOS_MW_ACT_CMD_STOR_TO_VM                      5               /**< 联动中心存储 */
#define IMOS_MW_ACT_CMD_OSD                             100             /**< 联动OSD，暂不支持  */   
#define IMOS_MW_ACT_CMD_CAPTURE                         101             /**< 联动抓拍, 不需要参数 */  
#define IMOS_MW_ACT_CMD_START_USBSTOR                   102             /**< 联动启动本地存储 */  
#define IMOS_MW_ACT_CMD_STOP_USBSTOR                    103             /**< 联动停止本地存储 */  

/**@brief 开关量模式 */
#define IMOS_MW_SWITCH_MODE_OPEN                        1               /**< 常开 */
#define IMOS_MW_SWITCH_MODE_CLOSE                       2               /**< 常闭 */

/**@brief 声音检测类型 */
#define IMOS_MW_AUDIO_DETECT_TYPE_RISE                  0               /**< 陡升 */
#define IMOS_MW_AUDIO_DETECT_TYPE_FALL                  1               /**< 陡降 */
#define IMOS_MW_AUDIO_DETECT_TYPE_MUTATION              2               /**< 突变 */
#define IMOS_MW_AUDIO_DETECT_TYPE_LIMIT                 3               /**< 门限 */  

/**@brief  违章球告警上报类型 */
/* BEGIN: Added by z01232, 2013/10/6  违章球告警上报 */
#define IMOS_MW_CMD_ALARM_CROSS_LINE                   301                 /**<  警戒线 伴线告警 */
#define IMOS_MW_CMD_ALARM_INTROSION_ZONE               302                 /**<  区域入侵告警 */
#define IMOS_MW_CMD_ALARM_ACCESS_ZONE                  303                 /**<  进入区域(警戒区) */
#define IMOS_MW_CMD_ALARM_LEAVE_ZONE                   304                 /**<  离开区域(警戒区) */
#define IMOS_MW_CMD_ALARM_HOVER_ZONE                   305                 /**<  区域徘徊 */
#define IMOS_MW_CMD_ALARM_OVER_FENCE                   306                 /**<  翻越围栏*/
#define IMOS_MW_CMD_ALARM_CARE_ARTICLE                 307                 /**<  物品看护 */
#define IMOS_MW_CMD_ALARM_REMAIN_ARTICLE               308                 /**<  物品遗留*/
/* END:   Added by z01232, 2013/10/6 */

#if 0
#endif
/**************************************** 云台巡航相关 ***************************************/
/*@brief 最大轨迹点个数*/
#define IMOS_MW_TRACK_POINT_NUM                64      

/*@brief 最大场景个数*/
#define IMOS_MW_SCENE_NUM                      4

/*@brief 预置位描述信息最大长度 */ 
#define IMOS_MW_PTZ_PRESET_NAME                64  

/*@brief 云台协议名称长度 */ 
#define IMOS_MW_PTZ_NAME_LEN                   16

/*@brief 计划包括四个时间段，巡航计划、布防计划等 */ 
#define IMOS_MW_TIME_SECTION_NUM               4  

/*@brief 计划包括12个时间段，巡航计划等 */ 
#define IMOS_MW_IVA_TIME_SECTION_NUM           12  

/*@brief 时间字符串长度 */ 
#define IMOS_MW_TIME_LEN                       12    

/*@brief 日期字符串长度 */ 
#define IMOS_MW_DAY_LEN                        12   

/*@brief 周的天数 */
#define IMOS_MW_WEEK_DAY                       7

/*@brief 扩展计划的最大天数 */
#define IMOS_MW_EXPLAN_DAYS                    64

/**@brief 云台控制命令 */
#define IMOS_MW_PTZ_CMD_IRISCLOSE              0x0102        /**< 光圈变小 */
#define IMOS_MW_PTZ_CMD_IRISOPEN               0x0104        /**< 光圈变大 */
#define IMOS_MW_PTZ_CMD_FOCUSNEAR              0x0202        /**< 近聚焦 */
#define IMOS_MW_PTZ_CMD_FOCUSFAR               0x0204        /**< 远聚焦 */
#define IMOS_MW_PTZ_CMD_ZOOMIN                 0x0302        /**< 放大 */
#define IMOS_MW_PTZ_CMD_ZOOMOUT                0x0304        /**< 缩小 */
#define IMOS_MW_PTZ_CMD_TILTUP                 0x0402        /**< 上, ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_TILTDOWN               0x0404        /**< 下, ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_PANRIGHT               0x0502        /**< 右, ulPTZCmdPara1 水平方向速度 */
#define IMOS_MW_PTZ_CMD_PANLEFT                0x0504        /**< 左, ulPTZCmdPara1 水平方向速度 */
#define IMOS_MW_PTZ_CMD_LEFTUP                 0x0702        /**< 左上, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_LEFTDOWN               0x0704        /**< 左下, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_RIGHTUP                0x0802        /**< 右上, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */    
#define IMOS_MW_PTZ_CMD_RIGHTDOWN              0x0804        /**< 右下, ulPTZCmdPara1 水平方向速度  ulPTZCmdPara2 垂直方向速度 */
#define IMOS_MW_PTZ_CMD_STOP                   0x0901        /**< 停止 */
#define IMOS_MW_PTZ_CMD_BRUSHON                0x0A01        /**< 雨刷开 */
#define IMOS_MW_PTZ_CMD_BRUSHOFF               0x0A02        /**< 雨刷关 */
#define IMOS_MW_PTZ_CMD_LIGHTON                0x0B01        /**< 灯开 */
#define IMOS_MW_PTZ_CMD_LIGHTOFF               0x0B02        /**< 灯关 */
#define IMOS_MW_PTZ_CMD_HEATON                 0x0C01        /**< 加热开 */
#define IMOS_MW_PTZ_CMD_HEATOFF                0x0C02        /**< 加热关 */
#define IMOS_MW_PTZ_CMD_INFRAREDON             0x0D01        /**< 红外开 */
#define IMOS_MW_PTZ_CMD_INFRAREDOFF            0x0D02        /**< 红外关 */
#define IMOS_MW_PTZ_CMD_SNOWCLEAR              0x1301        /**< 除雪模式启动, ulPTZCmdPara1 为强度 1-9 */
#define IMOS_MW_PTZ_CMD_SNOWCLEAROFF           0x1302        /**< 除雪模式关闭 */ 

/**@brief 云台方位信息 */
#define IMOS_MW_PTZ_DIRECTION_E                 0              /**< 东   */
#define IMOS_MW_PTZ_DIRECTION_SE                1              /**< 东南 */
#define IMOS_MW_PTZ_DIRECTION_S                 2              /**< 南   */
#define IMOS_MW_PTZ_DIRECTION_SW                3              /**< 西南 */
#define IMOS_MW_PTZ_DIRECTION_W                 4              /**< 西   */
#define IMOS_MW_PTZ_DIRECTION_NW                5              /**< 西北 */
#define IMOS_MW_PTZ_DIRECTION_N                 6              /**< 北   */
#define IMOS_MW_PTZ_DIRECTION_NE                7              /**< 东北 */

#if 0
#endif
/**************************************** 存储 (本地) 相关 ***************************************/
/**@brief 存储文件类型 */
#define IMOS_MW_STOR_FILE_TYPE_VIDEO        0          /**< 录像 */
#define IMOS_MW_STOR_FILE_TYPE_PICTURE      1          /**< 照片 */
#define IMOS_MW_STOR_FILE_TYPE_ALL          2          /**< 所有类型 */

/**@brief 存储策略 */
#define IMOS_MW_STOR_POLICY_FULL_STOP       0          /**< 满停止 */
#define IMOS_MW_STOR_POLICY_FULL_REWRITE    1          /**< 满覆盖 */

/**@brief 存储模式(开关) */
#define IMOS_MW_LOCAL_STOR_AUTO             0          /**< 自动 */
#define IMOS_MW_LOCAL_STOR_FOREVER          1          /**< 永存 */
#define IMOS_MW_LOCAL_STOR_SAVE             2          /**< 保留，上传后保留SD卡上的文件 */
#define IMOS_MW_LOCAL_STOR_START            10         /**< 开启 */
#define IMOS_MW_LOCAL_STOR_STOP             11         /**< 关闭 */

/**@brief 存储路径属性(目录、文件) */
#define IMOS_MW_STOR_PATH_DIR               0          /**< 目录 */ 
#define IMOS_MW_STOR_PATH_FILE              1          /**< 文件 */ 

/**@brief 存储类型 */
#define IMOS_MW_STOR_TYPE_SD                0        /**< SD卡 */
#define IMOS_MW_STOR_TYPE_NAS               1        /**< NAS */               

#if 0
#endif
/**************************************** 卡口相关 ***************************************/
/*@brief 虚拟线圈最大条数 */
#define IMOS_MW_VIRTUAL_COIL_MAX_NUM                 8    

/*@brief 最大车牌识别区域个数  */
#define IMOS_MW_LPR_AREA_MAX_NUM                     4 

/*@brief 最大车道数目  */
#define IMOS_MW_VEHICLE_WAY_MAX_NUM                  4 

/*@brief 注册照片接收服务器，信息字符串长度  */
#define IMOS_MW_PHOTOSERVER_CODE_LEN                 32     

/*@brief 卡口路口信息长度 */
#define IMOS_MW_ROAD_INFO_LEN                        100     

/*@brief 最大线圈个数 */
#define IMOS_MW_VEHICLE_DETECT_MAX_NUM               8

/*@brief 最大串口个数 */
#define IMOS_MW_SERIAL_MAX_NUM                       20

/**@brief 照片接收服务器通信协议类型 */
#define IMOS_MW_PHOTOSERVER_UNVIEW1                  0             /**< 宇视V1（对应泓鎏）*/                           
#define IMOS_MW_PHOTOSERVER_UNVIEW2                  1             /**< 宇视V2（对应当前tms）*/                           
#define IMOS_MW_PHOTOSERVER_XC                       2             /**< 先创 */
#define IMOS_MW_PHOTOSERVER_QST                      3             /**< 泉视通 */

/**@brief 车检器触发模式 */
#define IMOS_MW_TRRIGER_MODE_PULLINTO                0             /**< 进车触发 */
#define IMOS_MW_TRRIGER_MODE_PULLOUT                 1             /**< 出车触发 */

/**@brief 虚拟线圈(绊线) 开关 */
#define IMOS_MW_VIRTUAL_COIL_AUTO                    0             /**< 自动 */
#define IMOS_MW_VIRTUAL_COIL_ENABLE                  1             /**< 启用 */
#define IMOS_MW_VIRTUAL_COIL_DISABLE                 2             /**< 禁用 */
#define IMOS_MW_VIRTUAL_COIL_WITH_RADAR_SPEED        3             /**< 视频检测、雷达测速 */

/**@brief 卡口 工作模式 */
#define IMOS_MW_TG_MODE_TRAFFIC                      0             /**< 普通道路卡口 */
#define IMOS_MW_TG_MODE_TRAFFIC_EXPRESSWAY           1             /**< 高速路卡口 */
#define IMOS_MW_TG_MODE_TOLLGATE                     2             /**< 园区卡口 */
#define IMOS_MW_TG_MODE_MIX                          3             /**< 混合卡口 */

/**@brief 雷达 工作模式 */
#define IMOS_MW_RADAR_MODE_CONTINUOUS                0             /**< 连续模式 */
#define IMOS_MW_RADER_MODE_FRONT_TRIGGER             1             /**< 车头触发模式 */
#define IMOS_MW_RADER_MODE_REAR_TRIGGER              2             /**< 车尾触发模式 */
#define IMOS_MW_RADER_MODE_DOUBLE_TRIGGER            3             /**< 双触发模式 */

/**@brief 雷达 方向过滤模式 */
#define IMOS_MW_RADAR_DIRECTION_NONE_FILTER          0             /**< 不过滤 */
#define IMOS_MW_RADER_DIRECTION_COME                 1             /**< 输出来向车速 */
#define IMOS_MW_RADER_DIRECTION_GONE                 2             /**< 输出去向车速 */

/**@brief 雷达 车速格式 */
#define IMOS_MW_RADAR_SPEED_SINGLE_BYTE              0             /**< 单字节 */
#define IMOS_MW_RADAR_SPEED_DOUBLE_BYTE              1             /**< 双字节 */
#define IMOS_MW_RADAR_SPEED_ASCII_FORMAT             2             /**< ASCII 格式 */

/**@brief 激光测量模式 */
#define IMOS_MW_LASER_MEASURE_MODE_SIDE_DUAL         0             /**< 侧立双激光模式 */
#define IMOS_MW_LASER_MEASURE_MODE_TOP_DUAL          1             /**< 顶置双激光模式 */
#define IMOS_MW_LASER_MEASURE_MODE_AVERAGE           2             /**< 平均模式 */
#define IMOS_MW_LASER_MEASURE_MODE_CENTRAL           3             /**< 中央模式 */
#define IMOS_MW_LASER_MEASURE_MODE_TOP_SINGLE        4             /**< 顶置单激光模式 */
#define IMOS_MW_LASER_MEASURE_MODE_SIDE_SINGLE       5             /**< 侧立单激光模式 */
#define IMOS_MW_LASER_MEASURE_MODE_DEMO              6             /**< 演示模式 */

/**@brief 激光测量方式 */
#define IMOS_MW_LASER_MEASURE_WAY_MANUAL             0             /**< 手动测量 */
#define IMOS_MW_LASER_MEASURE_WAY_AUTO               1             /**< 自动测量 */

/**@brief 激光日志开关 */
#define IMOS_MW_LASER_LOG_CLOSE                      0             /**< 关闭 */
#define IMOS_MW_LASER_LOG_OPEN                       1             /**< 开启 */

/**@brief 电平触发开关 */
#define IMOS_MW_LASER_LEVER_TRIGGER_CLOSE            0             /**< 关闭 */
#define IMOS_MW_LASER_LEVER_TRIGGER_OPEN             1             /**< 开启 */

#if 0
#endif
/******************************* 电子警察相关定义 ***********************************/
/**@brief 单方向摄像机个数最大值 */
#define IMOS_MW_CAMERA_NUM_MAX          	     8

/**@brief 最大方向数, 电警上暂未使用，后续按需求修改该值 */
#define IMOS_MW_DIRECTION_NUM_MAX                1

/**@brief 单个车道上绊线条数 */
#define IMOS_MW_DRIVEWAY_VIRTUALCOIL_NUM         2

/**@brief 单个车道车道线条数 */
#define IMOS_MW_DRIVEWAY_LINE_NUM                2

/**@brief 通用时间段个数 */
#define IMOS_MW_COMMON_TIMESECTION_NUM           4

/**@brief 专用车道 时间段个数 */
#define IMOS_MW_DRIVEWAY_TIMESECTION_NUM         4

/**@brief 速度调整的速度段最大个数 */
#define IMOS_MW_DRIVEWAY_SPEED_ADJUST_NUM        5

/**@brief 单个摄像机 车道数最大值 */
#define IMOS_MW_DRIVEWAY_NUM_MAX                 8

/**@brief 单个摄像机 车道线数最大值 */
#define IMOS_MW_DRIVEWAY_LINE_NUM_MAX            (IMOS_MW_DRIVEWAY_NUM_MAX + 1)

/**@brief 检测区域顶点最大个数 */
#define IMOS_MW_DETECTAREA_POINTNUM_MAX          16

/**@brief 单个摄像机 检测区域最大个数 */
#define IMOS_MW_DETECTAREA_NUM_MAX               8

/**@brief 单个摄像机 标定水平线条数 */
#define IMOS_MW_HORIZONTAL_LINE_NUM              2

/**@brief 单个摄像机 触发线条数 */
#define IMOS_MW_TRIGGER_LINE_NUM                 16

/**@brief 单个摄像机 违章抓拍的触发线条数 */
#define IMOS_MW_PECCANCY_TRIGGERLINE_NUM         8

/**@brief 违章类型的最大个数 */
#define IMOS_MW_PECCANCYTYPE_MAX_NUM             32

/**@brief 红绿灯 颜色个数 */
#define IMOS_MW_TRAFFICLIGHT_COLOR_NUM           3

/**@brief 单个红绿灯灯组中 灯个数的最大值 */
#define IMOS_MW_LIGHT_NUM_MAX                    8    

/**@brief 单个摄像机的红绿灯 灯组个数的最大值 */
#define IMOS_MW_LIGHTGROUP_NUM_MAX               8

/**@brief 单个摄像机的红绿灯 模板最大个数 */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NUM_MAX    16

/**@brief 红绿灯模板名称长度 */
#define  IMOS_MW_TRAFFICLIGHT_TEMPLATE_NAME_LEN  32

/*@brief 同步相位配置数目  */
#define IMOS_MW_ACSYNC_NUM                        4

/**@brief 红绿灯颜色 */
#define IMOS_MW_LIGHT_COLOR_RED                  0 
#define IMOS_MW_LIGHT_COLOR_GREEN                1
#define IMOS_MW_LIGHT_COLOR_YELLOW               2

/**@brief 方向 */
#define IMOS_MW_DIRECTION_EASTTOWEST             1                  /**< 自东向西 */
#define IMOS_MW_DIRECTION_WESTTOEAST       	     2                  /**< 自西向东 */
#define IMOS_MW_DIRECTION_SOUTHTONORTH           3                  /**< 自南向北 */
#define IMOS_MW_DIRECTION_NORTHTOSOUTH           4                  /**< 自北向南 */
#define IMOS_MW_DIRECTION_SOUTHEASTTONORTHWEST   5                  /**< 东南向西北 */
#define IMOS_MW_DIRECTION_NORTHWESTTOSOUTHEAST   6                  /**< 西北向东南 */
#define IMOS_MW_DIRECTION_NORTHEASTTOSOUTHWEST   7                  /**< 东北向西南 */
#define IMOS_MW_DIRECTION_SOUTHWESTTONORTHEAST   8                  /**< 西南向东北 */

/**@brief 图片场帧类型 */
#define IMOS_MW_IMAGE_FIELD_TYPE 		         0                  /**< 场类型 */
#define IMOS_MW_IMAGE_FRAME_TYPE		         1                  /**< 帧类型 */

/**@brief 视频源类型 */
#define IMOS_MW_VIDEOSRC_LOCAL                   0                  /**< 本地 */
#define IMOS_MW_VIDEOSRC_JPEG                    1                  /**< JPEG */
#define IMOS_MW_VIDEOSRC_MJPEG                   2	                /**< MJPEG */
#define IMOS_MW_VIDEOSRC_AVI                     3	                /**< AVI */

/**@brief 图片旋转 */
#define IMOS_MW_IMAGE_ROTATE_NONE                0                  /**< 不旋转 */                    
#define IMOS_MW_IMAGE_ROTATE_CLOCKWISE_90        1                  /**< 顺时针 90°*/  
#define IMOS_MW_IMAGE_ROTATE_ANTICLOCKWISE_90    2                  /**< 逆时针 90°*/ 

/**@brief 图片色彩空间 */
#define IMOS_MW_IMAGE_COLORSPACE_JPG             0                  /**< JPG */                    
#define IMOS_MW_IMAGE_COLORSPACE_RGB             1                  /**< RGB */                    
#define IMOS_MW_IMAGE_COLORSPACE_YUV420          2                  /**< YUV420 */  
#define IMOS_MW_IMAGE_COLORSPACE_YUV422          3                  /**< YUV422 */ 
#define IMOS_MW_IMAGE_COLORSPACE_GRAY            4                  /**< GRAY */ 

/**@brief 车道属性 */
#define IMOS_MW_DRIVEWAYTYPE_NORMAL              0                  /**< 普通车道 */
#define IMOS_MW_DRIVEWAYTYPE_SINGLE_LINE         1                  /**< 单行线车道 */

/**@brief 车道类型 */
#define IMOS_MW_DRIVEWAYTYPE_GENERAL             0                  /**< 普通车道 */
#define IMOS_MW_DRIVEWAYTYPE_BUSONLY             1                  /**< 公交车专用车道 */
#define IMOS_MW_DRIVEWAYTYPE_NOTRUNK             2                  /**< 货车禁入车道 */
#define IMOS_MW_DRIVEWAYTYPE_NOVEHICLE           3                  /**< 非机动车道 */

/**@brief 车辆行驶方向 */
#define IMOS_MW_DRIVING_DIRECTION_COME           0                  /**< 由上往下行驶（车头） */
#define IMOS_MW_DRIVING_DIRECTION_GONE           1                  /**< 由下往上行驶（车尾） */
#define IMOS_MW_DRIVING_DIRECTION_BOTH           3                  /**< 双向 */

/**@brief 车道的行驶类型 (可组合) */
#define IMOS_MW_DRIVING_TYPE_STRAIGHT            0x1               /**< 直行 */
#define IMOS_MW_DRIVING_TYPE_TURN_LEFT           0x2               /**< 左转 */
#define IMOS_MW_DRIVING_TYPE_TURN_RIGHT          0x4               /**< 右转 */

/**@brief 当前车道 非法行驶类型 (可组合) */
#define IMOS_MW_DRIVING_ILLEGAL_TURNLEFT                0x1               /**< 禁止左转 */
#define IMOS_MW_DRIVING_ILLEGAL_TURNRIGHT               0x2               /**< 禁止右转 */
#define IMOS_MW_DRIVING_ILLEGAL_DIRECT_STRAIGHT         0x4               /**< 禁止直行 */

/**@brief 检测区域类型 */
#define IMOS_MW_DETECTAREA_VEHICLE_DETECT        0               /**< 车辆检测区域 */
#define IMOS_MW_DETECTAREA_FOLLOW                1               /**< 跟踪区域 */
#define IMOS_MW_DETECTAREA_LOCKAREA              2               /**< 路面标定区域 */

/**@brief 车辆检测模式 */
#define IMOS_MW_VEHICLE_DETECTMODE_VIDEO         0               /**< 视频检测 */

/**@brief 车牌识别模式: 暂未使用 */
#define IMOS_MW_PLATEIDENTIFY_MODE_PICTURE       0               /**< 图片识别 */

/**@brief 车辆限速模式  */
#define IMOS_MW_SPEEDLIMIT_MODE_DRIVEWAY         0              /**< 按车道限速 */
#define IMOS_MW_SPEEDLIMIT_MODE_VEHICLETYPE      1              /**< 按车型限速 */

/**@brief 车型 (可组合) */
#define IMOS_MW_VEHICLETYPE_SMALL                0x1               /**< 小型车 */
#define IMOS_MW_VEHICLETYPE_LARGE                0x2               /**< 大型车 */
#define IMOS_MW_VEHICLETYPE_MOTOR                0x4               /**< 摩托车 */
#define IMOS_MW_VEHICLETYPE_ENHANCE              0x400            /**< 附加属性，增强对无牌车的检测，可能增加误报 */
#define IMOS_MW_VEHICLETYPE_REDUCE               0x800            /**< 附加属性，减少误报输出，可能降低检测率 */
#define IMOS_MW_VEHICLETYPE_NUM                  8                 /**< 车型类型最大值 */

/**@brief 触发线 类型 */
#define IMOS_MW_TRIGGER_LINE_DEFAULT1            1              /**< 触发线1 */
#define IMOS_MW_TRIGGER_LINE_STOP                2              /**< 停止线 */
#define IMOS_MW_TRIGGER_LINE_STRAIGHT2           3              /**< 直行触发线2 */
#define IMOS_MW_TRIGGER_LINE_STRAIGHT3           4              /**< 直行触发线3 */
#define IMOS_MW_TRIGGER_LINE_STRAIGHT_DELAY3     5              /**< 直行触发线3# */
#define IMOS_MW_TRIGGER_LINE_TURNLEFT2           6              /**< 左转触发线2 */
#define IMOS_MW_TRIGGER_LINE_TURNRIGHT2          7              /**< 右转触发线2 */

/**@brief 红绿灯 识别方式 */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_TEMPLATE        0     /**< 模板识别 */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_VIDEO           1     /**< 视频识别 */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_SERIAL          2     /**< 单串口 */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_MULTISERIAL     3     /**< 多串口 */

/**@brief 红绿灯 类型 */
#define IMOS_MW_TRAFFICLIGHT_TYPE_SIMPLE                  0     /**< 简单灯 */
#define IMOS_MW_TRAFFICLIGHT_TYPE_COMPLEX                 1     /**< 复杂灯 */
#define IMOS_MW_TRAFFICLIGHT_TYPE_MIX                     2     /**< 混合灯 */

/**@brief 红绿灯 颜色 (可组合) */
#define IMOS_MW_TRAFFICLIGHT_COLOR_RED                    0x1     /**< 红灯 */
#define IMOS_MW_TRAFFICLIGHT_COLOR_YELLOW                 0x2     /**< 黄灯 */
#define IMOS_MW_TRAFFICLIGHT_COLOR_GREEN                  0x4     /**< 绿灯 */

/**@brief 红绿灯 形状 */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_ROUND                  0     /**< 圆形 */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_ARROW                  1     /**< 箭头 */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_BAR                    2     /**< 条形 */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_OTHER                  4     /**< 其他 */


/**@brief 红绿灯 IO端口 */
#define IMOS_MW_TRAFFICLIGHT_IO_NONE     		          0     /**< 无 */
#define IMOS_MW_TRAFFICLIGHT_IO_SERIAL1                   1     /**< 串口1 */
#define IMOS_MW_TRAFFICLIGHT_IO_SERIAL2                   2     /**< 串口2 */   

/**@brief 红绿灯 指示方向 (可组合) */
#define IMOS_MW_TRAFFICLIGHT_DIRECT_LEFT                  0x1     /**< 左转 */
#define IMOS_MW_TRAFFICLIGHT_DIRECT_RIGHT                 0x2     /**< 右转 */
#define IMOS_MW_TRAFFICLIGHT_DIRECT_STRAIGHT              0x4     /**< 直行 */

/**@brief 红绿灯 排列方向 */
#define IMOS_MW_TRAFFICLIGHT_ARRANGE_HORIZATIONAL         0     /**< 横向 */
#define IMOS_MW_TRAFFICLIGHT_ARRANGE_VERTICAL             1     /**< 纵向 */

/**@brief 闯红灯 检测模式 */
#define IMOS_MW_RUNREDLIGHT_DETECTMODE_GENERAL            0     /**< 普通模式 */
#define IMOS_MW_RUNREDLIGHT_DETECTMODE_3LINE              1     /**< 3线模式 */

/**@brief 违章记录生成模式 */
#define IMOS_MW_MULTI_BREAKRULE_RECORD_EACH               0     /**< 每种违章均单独生成违章记录 */
#define IMOS_MW_MULTI_BREAKRULE_RECORD_HIGHEST            1     /**< 仅生成最高优先级违章的违章记录 */

/**@brief 车道线类型 */
#define IMOS_MW_DRIVEWAY_LINE_SOLID_WHITE                        0     /**< 白实线 */
#define IMOS_MW_DRIVEWAY_LINE_SOLID_YELLOW                       1     /**< 黄实线 */
#define IMOS_MW_DRIVEWAY_LINE_2SOLID_YELLOW                      2     /**< 双黄实线 */
#define IMOS_MW_DRIVEWAY_LINE_L_REALLINE_R_BROKENLINE            3     /**< 双黄左实右虚线 */
#define IMOS_MW_DRIVEWAY_LINE_L_BROKENLINE_R_REALLINE            4     /**< 双黄左虚右实线 */
#define IMOS_MW_DRIVEWAY_LINE_L_REALLINE_R_BROKENLINE_WHITE      5     /**< 双白左实右虚线 */
#define IMOS_MW_DRIVEWAY_LINE_L_BROKENLINE_R_REALLINE_WHITE      6     /**< 双白左虚右实线 */
#define IMOS_MW_DRIVEWAY_LINE_OTHER                              7     /**< 其它 */

/**@brief 车辆违章类型 (可组合) */
#define IMOS_MW_VEHICLE_PECCANCY_NONE                     0x0        /**< 没有违章 */
#define IMOS_MW_VEHICLE_PECCANCY_RUNREDLIGHT              0x1        /**< 闯红灯 */
#define IMOS_MW_VEHICLE_PECCANCY_PRESSLINE                0x2        /**< 压线 */
#define IMOS_MW_VEHICLE_PECCANCY_OVERLINE                 0x4        /**< 越线(违章变道) */
#define IMOS_MW_VEHICLE_PECCANCY_ILLEGAL_DRIVEWAY         0x8        /**< 未按车道行驶 */
#define IMOS_MW_VEHICLE_PECCANCY_TURNLEFT                 0x10       /**< 违章左转 */
#define IMOS_MW_VEHICLE_PECCANCY_TURNRIGHT                0x20       /**< 违章右转 */
#define IMOS_MW_VEHICLE_PECCANCY_CONVERSE                 0x40       /**< 逆行 */
#define IMOS_MW_VEHICLE_PECCANCY_OVERSPEED                0x80       /**< 超速 */
#define IMOS_MW_VEHICLE_PECCANCY_LOWSPEED                 0x100      /**< 慢速 */
#define IMOS_MW_VEHICLE_PECCANCY_RESTRICT_ODD_EVEN        0x200      /**< 单双号限行 */
#define IMOS_MW_VEHICLE_PECCANCY_SPECAIL_DRIVEWAY         0x400      /**< 专用车道 */
#define IMOS_MW_VEHICLE_PECCANCY_ILLEGALPARK              0x800      /**< 违法停车 */
#define IMOS_MW_VEHICLE_PECCANCY_DIRECT_STRAIGHT          0x1000     /**< 违章直行 */ 
#define IMOS_MW_VEHICLE_PECCANCY_BACK_CAR                 0x2000     /**< 违法倒车 */ 
#define IMOS_MW_VEHICLE_PECCANCY_OVER50PERCENTSPEED       0x4000     /**< 超速50% */
#define IMOS_MW_VEHICLE_PECCANCY_PRESS_2SOLID_YELLOW      0x8000     /**< 压双黄线 */
#define IMOS_MW_VEHICLE_PECCANCY_PRESS_SOLID_YELLOW       0x10000    /**< 压单黄线 */
#define IMOS_MW_VEHICLE_PECCANCY_PRESS_STOP_LINE          0x20000    /**< 压停车线 */
#define IMOS_MW_VEHICLE_PECCANCY_OVER20PERCENTSPEED       0x40000    /**< 超速20% */
#define IMOS_MW_VEHICLE_PECCANCY_OVER100PERCENTSPEED      0x80000    /**< 超速100% */
#define IMOS_MW_VEHICLEPECCANCY_TYPE_NUM                  20          /**< 车辆违章类型个数 */

/**@brief 图片合成模式 */
#define IMOS_MW_IMAGE_COMPOSITE_MODE_NONE                 0          /**< 不合成 */
#define IMOS_MW_IMAGE_COMPOSITE_MODE_LEFTRIGHT            1          /**< 两张图片: 一左一右 */

/**@brief 生成图片类型 */
#define IMOS_MW_IMAGE_MAKE_PLATE_COLOR                    0x1          /**< 生成车牌彩色小图 */
#define IMOS_MW_IMAGE_MAKE_PLATE_BINARY                   0x2          /**< 生成车牌二值化图 */
#define IMOS_MW_IMAGE_MAKE_PLATE_FEATURE                  0x4          /**< 生成车牌特写图 */
#define IMOS_MW_IMAGE_MAKE_COMPOSE                        0x8          /**< 生成照片合成图 */

/**@brief 图片类型 */
#define IMOS_MW_IMAGE_PECCANCY                            0          /**< 违法行为图片 */
#define IMOS_MW_IMAGE_COMPOSITE                           1          /**< 合成图片 */
#define IMOS_MW_IMAGE_TEMP                                2          /**< 临时图片 */
#define IMOS_MW_IMAGE_TYPE_NUM                            3          /**< 图片类型个数 */

/**@brief 红绿灯模板类型 (可组合) */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_STRAIGHT            0x1        /**< 直行通行 */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NOSTRAIGHT          0x2        /**< 直行禁行 */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_TURNLEFT            0x4        /**< 左转通行 */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NOTURNLEFT          0x8        /**< 左转禁行 */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_TURNRIGHT           0x10       /**< 右转通行 */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NOTURNRIGHT         0x20       /**< 右转禁行 */

/**@brief 抓拍类型类型(可组合) */
#define IMOS_MW_CAPTURE_PECCANCY                          0x1          /**< 违章记录 */                   
#define IMOS_MW_CAPTURE_PECCANCY_PASSVEHICLE              0x2          /**< 违章过车记录 */  
#define IMOS_MW_CAPTURE_NOPECCANCY_PASSVEHICLE            0x4          /**< 不违章过车记录 */  

/**@brief 相机类型 */
#define IMOS_MW_FULLVIEW_CAMERA                           0            /**< 全景 */   
#define IMOS_MW_FEATURE_CAMERA                            1            /**< 特写 */   

/**@brief 运行环境 */
#define IMOS_MW_PRODUCT_TYPE_TG                           0            /**< 卡口 */   
#define IMOS_MW_PRODUCT_TYPE_EP                           1            /**< 电警 */   

/**@brief 照片类型 */
#define	IMOS_MW_IMAGE_VEHICLE                             1           /**< 车辆大图 */
#define IMOS_MW_IMAGE_PLATE_COLOR                         2           /**< 车牌彩色小图 */
#define IMOS_MW_IMAGE_PLATE_BINARY                        3           /**< 车牌二值化图 */

#if 0
#endif
/**************************************** 播放控制 ***************************************/
/*@brief 播放窗格最大个数 */
#define IMOS_MW_MAX_WND_NUM                      9

/**@brief 播放状态 */
#define IMOS_MW_PLAY_STATUS_16_BACKWARD          0       /**< 16倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_8_BACKWARD           1       /**< 8倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_4_BACKWARD           2       /**< 4倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_2_BACKWARD           3       /**< 2倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_1_BACKWARD           4       /**< 正常速度后退播放 */
#define IMOS_MW_PLAY_STATUS_HALF_BACKWARD        5       /**< 1/2倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_QUARTER_BACKWARD     6       /**< 1/4倍速后退播放 */
#define IMOS_MW_PLAY_STATUS_QUARTER_FORWARD      7       /**< 1/4倍速播放 */
#define IMOS_MW_PLAY_STATUS_HALF_FORWARD         8       /**< 1/2倍速播放 */
#define IMOS_MW_PLAY_STATUS_1_FORWARD            9       /**< 正常速度前进播放 */
#define IMOS_MW_PLAY_STATUS_2_FORWARD            10      /**< 2倍速前进播放 */
#define IMOS_MW_PLAY_STATUS_4_FORWARD            11      /**< 4倍速前进播放 */
#define IMOS_MW_PLAY_STATUS_8_FORWARD            12      /**< 8倍速前进播放 */
#define IMOS_MW_PLAY_STATUS_16_FORWARD           13      /**< 16倍速前进播放 */

/**@brief 媒体文件格式 */
#define IMOS_MW_MEDIA_FILE_FORMAT_TS             0       /**< TS格式的媒体文件 */
#define IMOS_MW_MEDIA_FILE_FORMAT_FLV            1       /**< FLV格式的媒体文件 */

/**@brief 分割录像模式 */
#define IMOS_MW_RECORD_PARTITION_NODE              0       /**< 不进行录像分割*/
#define IMOS_MW_RECORD_PARTITION_TIME              1       /**< 录像按时间分割*/
#define IMOS_MW_RECORD_PARTITION_DISKSPACE         2       /**< 录像按存储空间分割*/

/**@brief 视频显示模式 */
#define IMOS_MW_RENDER_MODE_D3D                  0       /**< 使用D3D的方式进行显示 */
#define IMOS_MW_RENDER_MODE_DDRAW_NORMAL         1       /**< 使用Ddraw的Normal显示模式 */

/**@brief 视频像素格式 */
#define IMOS_MW_PIXEL_FORMAT_YUV420              0       /**< YUV420格式输出 */
#define IMOS_MW_PIXEL_FORMAT_RGB32               1       /**< RGB32格式输出 */

/**@brief 图像播放流畅性 */
#define IMOS_MW_PICTURE_TIME_PRIORITY            0       /**< 实时性优先 */
#define IMOS_MW_PICTURE_FLUENCY_PRIORITY         1       /**< 流畅性优先 */
#define IMOS_MW_PICTURE_AUTO                     2       /**< 自动 */
#define IMOS_MW_PICTURE_LOWDELAY                 3       /**< 低延时 */

/**@brief 播放窗格显示图像的比例 */
#define IMOS_MW_RENDER_SCALE_FULL                0       /**< 图像填充整个播放窗格 */
#define IMOS_MW_RENDER_SCALE_PROPORTION          1       /**< 图像按比例显示 */

/**@brief 媒体数据流格式 */
#define IMOS_MW_MEDIA_DATA_TS                    0       /**< TS封装码流 */
#define IMOS_MW_MEDIA_DATA_ES12                  1       /**< RTP + 音/视频私有头（12字节） + ES码流 */
#define IMOS_MW_MEDIA_DATA_ES12_TIME             2       /**< RTP + 时间戳（8字节） + 音/视频私有头（12字节） + ES码流 */
#define IMOS_MW_MEDIA_DATA_RTP_ES                3       /**< RTP + ES码流 */
#define IMOS_MW_MEDIA_DATA_HK                    4       /**< 海康码流，回调的第一个包是海康40字节系统头 */
#define IMOS_MW_MEDIA_DATA_DH                    5       /**< 大华码流 */
#define IMOS_MW_MEDIA_DATA_RM                    6       /**< 锐明码流，回调的第一个包是锐明40字节系统头 */
#define IMOS_MW_MEDIA_DATA_TDY_SWALLOW           7       /**< TDY-SWALLOW */
#define IMOS_MW_MEDIA_DATA_DMA_SWALLOW           8       /**< DMA-SWALLOW */

/**@brief 解码后音频格式 */
#define IMOS_MW_WAVE_FORMAT_PCM8M16              0       /**< PCM，8K采样率，单声道（M），16位采样 */
#define IMOS_MW_WAVE_FORMAT_PCM16M16             1       /**< PCM，16K采样率，单声道（M），16位采样 */ 
#define IMOS_MW_WAVE_FORMAT_PCM441M16            2       /**< PCM，44.1K采样率，单声道（M），16位采样 */ 

/**@brief 视频帧类型 */
#define IMOS_MW_VIDEO_FRAME_TYPE_I               0       /**< I帧 */
#define IMOS_MW_VIDEO_FRAME_TYPE_P               1       /**< P帧 */
#define IMOS_MW_VIDEO_FRAME_TYPE_B               2       /**< B帧 */

/**@brief 时间戳类型 */
#define IMOS_MW_RENDER_TYPE_FRAME_RATE           0       /**< 使用帧率数据进行视频渲染 */
#define IMOS_MW_RENDER_TYPE_ABSOLUTE_TIME        1       /**< 使用绝对时间数据进行视频渲染 */

/**@brief 解码 对比度模式 */
#define IMOS_MW_PICTURE_CONTRAST_MODE_NONE        0      /**< 不进行对比度调节处理 */
#define IMOS_MW_PICTURE_CONTRAST_MODE_BRIGHTNESS  1      /**< 明亮模式 */
#define IMOS_MW_PICTURE_CONTRAST_MODE_SOFTNESS    2      /**< 柔和模式 */

/**@brief 图片格式 */
#define IMOS_MW_PICTURE_FORMAT_BMP                0      /**< BMP 格式 */ 
#define IMOS_MW_PICTURE_FORMAT_JPEG               1      /**< JPEG 格式，参数参见: IMOS_MW_CAPTURE_FORMAT_CFG_S */
#define IMOS_MW_PICTURE_FORMAT_CUSTOM             10     /**< 随流格式, 不需要其他参数 */

/*@brief 照片后端叠加信息类型 */
#define IMOS_MW_IMAGE_BACKEND_OSD                 0    /**< 叠加 OSD，结构定义: IMOS_MW_IMAGE_OSD_INFO_S */
#define IMOS_MW_IMAGE_BACKEND_RECTANGLE           1    /**< 叠加 信息框, 结构定义: IMOS_MW_RECTANGLE_S, 其中，坐标单位 0.01% */
#define IMOS_MW_IMAGE_BACKEND_OSD_OBJ             2    /**< 叠加OSD, 带目标信息框, 结构定义: IMOS_MW_IMAGE_OSD_WITH_OBJ_S, 信息框坐标单位 0.01% */


#if 0
#endif
/**************************************** EZR 存储相关 ***************************************/
/** @brief 流URI长度 */
#define IMOS_MW_STREAM_URI_LEN                     256 

/** @brief EzRecord 磁盘数 */
#define IMOS_MW_STOR_DISK_NUM                      26

/** @brief 存储根目录名长度 */
#define IMOS_MW_STOR_DISK_PATH_LEN                 32   /*如 E:*/

/** @brief 视频ID信息长度 (userid=48 path=32 name=32)=112 适配成 128 */
#define IMOS_MW_STOR_VIDEO_ID_LEN                  128

/* 存储相关: 存储源、存储计划、端口、服务启停、磁盘配置等 */
#define IMOS_MW_STOR_SERVICE_STATE                 0             /**< 获取/设置 存储设备服务状态(启停)  参见: IMOS_MW_STOR_SERVICE_XXX */
#define IMOS_MW_STOR_DISK_INFO                     1             /**< 获取 存储设备磁盘信息  对应结构定义: IMOS_MW_STOR_DISK_INFO_S */
#define IMOS_MW_STOR_DISK_CFG                      2             /**< 增加/删除 存储磁盘配置，对应结构定义: IMOS_MW_STOR_CFG_DISK_ITEM_S */
#define IMOS_MW_STOR_RESOURCE_INFO                 3             /**< 获取 存储系统资源信息(剩余存储容量等)，对应结构定义: IMOS_MW_STOR_RESOURCE_INFO_S */
#define IMOS_MW_STOR_PORT_INFO                     4             /**< 获取 存储设备端口信息  对应结构定义: IMOS_MW_STOR_PORT_INFO_S */
#define IMOS_MW_STOR_SOURCE_CFG                    5             /**< 获取/设置/删除 存储源配置，对应结构定义: IMOS_MW_STOR_SOURCE_CFG_S(删除用IMOS_MW_STOR_SOURCE_INFO_S) */
#define IMOS_MW_STOR_PLAN_CFG                      6             /**< 获取/设置/删除 存储计划，对应结构定义: IMOS_MW_STOR_PLAN_CFG_S(删除用IMOS_MW_STOR_SOURCE_INFO_S) */ 
#define IMOS_MW_STOR_PLAN_STATE                    7             /**< 获取/设置   存储计划状态，对应结构定义: IMOS_MW_STOR_SOURCE_PLANSTATE_S */ 
#define IMOS_MW_STOR_MANUAL_STAT                   8             /**< 获取 手动存储状态， 对应结构定义: IMOS_MW_STOR_MANUAL_STORESTATE_S */ 
#define IMOS_MW_STOR_SET_PASSWORD                  9             /**< 设置 密码， 对应结构定义: IMOS_MW_STOR_SET_PASSWORD_S */
#define IMOS_MW_STOR_NTP_CFG                       10            /**< NTP 设置，对应结构定义: IMOS_MW_STOR_NTP_CFG_S */
#define IMOS_MW_STOR_VIDEO_CHL_CFG                 11            /**< 获取 视频通道信息， 对应结构定义: IMOS_MW_STOR_VIDEO_CHL_CFG_S */ 
#define IMOS_MW_STOR_VIDEO_CHL_NUM                 12            /**< 获取 视频通道数， 对应结构定义: IMOS_MW_STOR_VIDEO_CHL_NUM_S */ 

/**@brief 存储上报事件类型 */
#define IMOS_MW_STOR_EVENT_DEVICE_OFFLINE          0              /**< EZR设备离线  无参数 */
#define IMOS_MW_STOR_EVENT_USE_NEW_PORT            1              /**< EZR设备端口更改  USHORT */
#define IMOS_MW_STOR_EVENT_SERVICE_CHANGE          2              /**< 服务改变 ULON 0：停止 1：启动 */
#define IMOS_MW_STOR_EVENT_GOING_FULL              10             /**< 存储内存即将满 IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_FULL_STOP               11             /**< 存储满停止 IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_START             20             /**< 存储启动 IMOS_MW_STOR_SOURCE_INFO_S*/
#define IMOS_MW_STOR_EVENT_STORE_STOP              21             /**< 存储停止 IMOS_MW_STOR_SOURCE_INFO_S*/
#define IMOS_MW_STOR_EVENT_STORE_FAILED            22             /**< 存储失败 IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_RECOVER           23             /**< 存储恢复 IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_PLAN_FAILED       24             /**< 计划存储失败 IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_PLAN_RECOVER      25             /**< 计划存储恢复 IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_DOWNLOAD_PROCESS        30             /**< 下载进度 IMOS_MW_STOR_DOWNLOAD_INFO_S*/
#define IMOS_MW_STOR_EVENT_DOWNLOAD_ERROR          31             /**< 下载出错 IMOS_MW_STOR_DOWNLOAD_INFO_S */
#define IMOS_MW_STOR_EVENT_DOWNLOAD_COMPLETE       32             /**< 下载完成 IMOS_MW_STOR_DOWNLOAD_INFO_S */

/**@brief 存储服务状态 */
#define IMOS_MW_STOR_SERVICE_OFF                   0              /**< 存储业务停用 */
#define IMOS_MW_STOR_SERVICE_ON                    1              /**< 存储业务启用 */

/**@brief 存储计划状态 */
#define IMOS_MW_STOR_PLAN_OFF                      0              /**< 存储计划停用 */
#define IMOS_MW_STOR_PLAN_ON                       1              /**< 存储计划启用 */

/**@brief 视频存储类型 */
#define IMOS_MW_VIDEO_STORE_MANUAL                 0x01           /**< 手动存储 */
#define IMOS_MW_VIDEO_STORE_PLAN                   0x02           /**< 计划存储 */
#define IMOS_MW_VIDEO_STORE_ALARM                  0x04           /**< 告警存储 */
#define IMOS_MW_VIDEO_STORE_MOTION                 0x08           /**< 移动侦测 */
#define IMOS_MW_VIDEO_STORE_LABEL                  0x10           /**< 标签 */

/**@brief 无效视频流ID */
#define IMOS_MW_STOR_INVALID_STREAMID              (~0)           /**< 无效流ID */

/**@brief 磁盘存放类型 */
#define IMOS_MW_STORE_TYPE_VIDEO                   0              /**< 视频 */
#define IMOS_MW_STORE_TYPE_MAX                     1

#if 0
#endif
/**************************************** 智能业务相关 ***************************************/
/**@brief 多边形区域的最大点数 */
#define IMOS_MW_POLYGON_POINT_MAX_NUM         12    

/**@brief 支持的最大场景数 */
#define IMOS_MW_IVA_SCENE_MAX_NUM             4

/**@brief 单个场景支持的最大排除区域数 */
#define IMOS_MW_IVA_IGNORE_AREA_MAX_NUM       4

/**@brief 单个场景支持的最大规则数 */
#define IMOS_MW_IVA_RULE_OF_SCENE_MAX_NUM     4

/**@brief 支持的最大规则数 */
#define IMOS_MW_IVA_RULE_MAX_NUM              (IMOS_MW_IVA_SCENE_MAX_NUM * IMOS_MW_IVA_RULE_OF_SCENE_MAX_NUM)

/**@brief 目标尺寸最大数 */
#define IMOS_MW_IVA_FILTER_SIZE_MAX_NUM       6    

/**@brief 倍率标定点最大数 */
#define IMOS_MW_IVA_MAGNIFICATION_MAX_NUM     6

/**@brief 违章类型最大数 */
#define IMOS_MW_IVA_ILLEGAL_TYPE_MAX_NUM      1

/**@brief 智能业务模式 */
#define IMOS_MW_IVA_MODE_PEA                  0    /**< 周界防范 */
#define IMOS_MW_IVA_MODE_IE                   1    /**< 违章取证 */

/**@brief 智能场景巡航模式 */
#define IMOS_MW_IVA_SINGLE_SCENE_MODE         0    /**< 单场景 智能业务模式配置 */
#define IMOS_MW_IVA_WEEKDAY_PLAN_MODE         1    /**< 周计划 智能业务模式配置 */


/**@brief 目标过滤类型 */
#define IMOS_MW_IVA_FILTER_TYPE_W_AND_H       0    /**< 过滤类型为宽和高 */
#define IMOS_MW_IVA_FILTER_TYPE_W_OR_H        1    /**< 过滤类型为宽或高 */

/**@brief 目标尺寸过滤类型 */
#define IMOS_MW_IVA_FILTER_SIZE_TYPE_NONE     0    /**< 无过滤尺寸 */
#define IMOS_MW_IVA_FILTER_SIZE_TYPE_SINGLE   1    /**< 过滤尺寸类型为单景深 */
#define IMOS_MW_IVA_FILTER_SIZE_TYPE_MULTI    2    /**< 过滤尺寸类型为多景深 */

/**@brief 目标触发位置 */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_CENTER   0x001    /**< 触发位置为目标中心 */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_LEFT     0x002    /**< 触发位置为目标左边缘 */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_RIGHT    0x004    /**< 触发位置为目标右边缘 */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_TOP      0x008    /**< 触发位置为目标上边缘 */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_BOTTOM   0x010    /**< 触发位置为目标下边缘 */

/**@brief 规则类型 */
#define IMOS_MW_IVA_RULE_TYPE_PICKET_LINE     0x001    /**< 警戒线 */
#define IMOS_MW_IVA_RULE_TYPE_PICKET_AREA     0x002    /**< 进入/离开区域(警戒区) */
#define IMOS_MW_IVA_RULE_TYPE_AREA_STAY       0x004    /**< 区域入侵 */
#define IMOS_MW_IVA_RULE_TYPE_OBJECT_STATUS   0x008    /**< 物品状态看护 */
#define IMOS_MW_IVA_RULE_TYPE_ILLEGAL_PARKING 0x100    /**< 违章停车 */

/**@brief 规则触发类型 */
#define IMOS_MW_IVA_DIREC_NONE                0     /**< 无方向 */
#define IMOS_MW_IVA_DIREC_DEASIL              1     /**< 警戒线: 顺时针 */
#define IMOS_MW_IVA_DIREC_ANTICLOCKWISE       2     /**< 警戒线: 逆时针 */
#define IMOS_MW_IVA_DIREC_ENTRY               3     /**< 区域: 进入 */
#define IMOS_MW_IVA_DIREC_QUIT                4     /**< 区域: 离开 */
#define IMOS_MW_IVA_OBJECT_ABANDON            5     /**< 物品状态: 遗留 */
#define IMOS_MW_IVA_OBJECT_THEFT              6     /**< 物品状态: 盗取 */

/**@brief 违章类型 */
#define IMOS_MW_IVA_ILLEGAL_TYPE_NONE         0     /**< 无违章 */
#define IMOS_MW_IVA_ILLEGAL_TYPE_PARKING      1     /**< 违章停车 */

/* 车辆一致性检测 */
#define IMOS_MW_IVA_LP_CHECK_OFF              0     /**< 不开启车辆一致性检测 */
#define IMOS_MW_IVA_LP_CHECK_ON               1     /**< 开启车辆一致性检测 */

/**@brief 显示元数据操作*/
#define IMOS_MW_IVA_SHOW_RULE                   0x00000001          /**< 显示规则线框*/
#define IMOS_MW_IVA_SHOW_RESULT_TOUTH_RULE      0x00000002          /**< 显示触发规则目标框*/
#define IMOS_MW_IVA_SHOW_RESULT_UNTOUTH_RULE    0x00000004          /**< 显示未触发规则目标框*/


#if 0
#endif
/*************************************** 内部调试相关 ********************************************/
/**@brief 触发设备开关 */
#define IMOS_MW_TRIGGER_DEVICE_OFF               0        /**< 关闭 */  
#define IMOS_MW_TRIGGER_DEVICE_ON                1        /**< 开启 */  

/**@brief LED灯 */
#define IMOS_MW_LED_STROBE_OFF                   0        /**< LED灯 关闭 */  
#define IMOS_MW_LED_STROBE_ON                    1        /**< LED灯 开启 */ 
#define IMOS_MW_LED_STROB_AUTO                   2        /**< LED灯 自动 */ 
#define IMOS_MW_LED_STROB_NIGHT_ON               3        /**< LED灯 夜间开启 */ 

/**@brief 偏振镜 */
#define IMOS_MW_POLARIZER_OFF                    0        /**< 偏振镜 关闭 */  
#define IMOS_MW_POLARIZER_ON                     1        /**< 偏振镜 开启 */  
#define IMOS_MW_POLARIZER_AUTO                   2        /**< 偏振镜 自动 */  

/**@brief ND滤镜 */
#define IMOS_MW_ND_FILTER_OFF                    0        /**< ND滤镜 关闭 */  
#define IMOS_MW_ND_FILTER_ON                     1        /**< ND滤镜 开启 */  
#define IMOS_MW_ND_FILTER_AUTO                   2        /**< ND滤镜 自动 */  

/**@brief 机芯控制 */
#define IMOS_MW_SENSOR_CTL_UP                    0
#define IMOS_MW_SENSOR_CTL_DOWN                  1
#define IMOS_MW_SENSOR_CTL_LEFT                  2
#define IMOS_MW_SENSOR_CTL_RIGHT                 3
#define IMOS_MW_SENSOR_CTL_ENTER                 4
#define IMOS_MW_SENSOR_CTL_ON                    5
#define IMOS_MW_SENSOR_CTL_OFF                   6

/**@brief 调试命令 */
#define IMOS_MW_DEBUG_BOARD_TYPE                 0        /**< 设置设备类型 */
#define IMOS_MW_DEBUG_LENS_TYPE                  1        /**< 设置镜头类型 */
#define IMOS_MW_DEBUG_IQ_DEBUG                   2        /**< 输出IQ debug信息 */
#define IMOS_MW_DEBUG_SENSOR_OSD_CTL             4        /**< 机芯控制，参考: IMOS_MW_SENSOR_CTL_XXX */
#define IMOS_MW_DEBUG_SENSOR_TYPE                5        /**< 机芯类型 */
#define IMOS_MW_DEBUG_DAILYREBOOT                6        /**< 每日定时重启,对应参数:IMOS_MW_DEBUG_DAILYREBOOT_CFG_S */
#define IMOS_MW_DEBUG_CAPTURE                    11       /**< 手动前端抓拍，对应参数: UCHAR(IA_PIC_FORMAL 等) */
#define IMOS_MW_DEBUG_FLASH_EXPOSURE             12       /**< 手动触发曝闪灯  参考IMOS_MW_DEBUG_CAP_EXP_S */ 
#define IMOS_MW_DEBUG_LED_STROBE                 13       /**< 手动触发频闪灯，参考: #define IMOS_MW_POLARIZER_XXX */
#define IMOS_MW_DEBUG_POLARIZER                  14       /**< 调试偏振镜，对应参数: IMOS_MW_DEBUG_POLARIZER_S */
#define IMOS_MW_DEBUG_COIL_CHECK                 15       /**< 手动触发线圈检测，参考: #define IMOS_MW_COIL_CHECK_XXX */
#define IMOS_MW_DEBUG_RADAR_CHECK                16       /**< 手动触发雷达检测，参考: #define IMOS_MW_RADAR_CHECK_XXX */
#define IMOS_MW_DEBUG_LASER_REBOOT               17       /**< 激光重启 */
#define IMOS_MW_DEBUG_LASER_RESTORE_DEFAULT      18       /**< 激光恢复默认配置 */
#define IMOS_MW_DEBUG_CAPTURE_PARA               19       /**< 调试抓拍设置  参考IMOS_MW_DEBUG_CAP_EXP_S */
#define IMOS_MW_DEBUG_EP_CFG                     20       /**< 卡口/电警调试参数配置(重启仍生效) 参考:IMOS_MW_DEBUG_EP_CFG_S */
#define IMOS_MW_DEBUG_EP_TMP_CFG                 21       /**< 卡口/电警调试参数配置(重启不生效) 参考:IMOS_MW_DEBUG_EP_TMP_CFG_S */
#define IMOS_MW_DEBUG_EP_TG_TYPE_CFG             22       /**< 当前运行环境，卡口或者电警，UCHAR类型 */
#define IMOS_MW_DEBUG_PORT_CONFIG_RESUME         23       /**< port.config恢复默认配置 */
#define IMOS_MW_VAR_FN_DEFOG                     30       /**< 可变功能类型---透雾功能; ulImageVarPara1:透雾等级(取值0,1,2,3,4,5)  ulImageVarPara2:透雾灵敏度(取值1-9) */
#define IMOS_MW_VAR_FN_EIS                       31       /**< 可变功能类型---电子防抖功能; ulImageVarPara1:防抖使能否(取值0,1) ulImageVarPara2:防抖频率值(单位:HZ) */
#define IMOS_MW_DEBUG_OSD_UPDATE                 32       /**< OSD 实时刷新使能配置，参考IMOS_MW_DEBUG_OSD_UPDATE_S */
#define IMOS_MW_DEBUG_FOCUSVALUE                 34       /**< 获取清晰度评价值 参数类型: ULONG */

#define IMOS_MW_DEBUG_AF_STAT                    40       /**< AF调式接口，获取AF相关状态：参考IMOS_MW_DEBUG_AF_STAT_S */
#define IMOS_MW_DEBUG_AF_FV                      41       /**< AF调式接口，获取当前图像不同权重的FV值,参考IMOS_MW_DEBUG_AF_S */
#define IMOS_MW_DEBUG_AF_GMAP                    42       /**< AF调式接口，设置日志打印当前跟随曲线 */
#define IMOS_MW_DEBUG_AF_CALCULATEMAP            43       /**< AF调式接口，设置日志打印指定物距0~6000cm跟随曲线 */
#define IMOS_MW_DEBUG_AF_FOCUSMODE               44       /**< AF调式接口，设置聚焦模式：自动聚焦1或一键聚焦0 */
#define IMOS_MW_DEBUG_AF_DAYNIGHT                45       /**< AF调式接口，设置聚焦时日夜场景白天0 夜间1 */
#define IMOS_MW_DEBUG_AF_FOCUSTYPE               46       /**< AF调式接口，设置聚焦类型：正常模式 0 或慢聚焦模式 1 */
#define IMOS_MW_DEBUG_AF_ZPOS                    47       /**< AF调式接口，设置当前ZOOM电机位置0~2333 */
#define IMOS_MW_DEBUG_AF_FPOS                    48       /**< AF调式接口，设置当前FOCUS电机位置 0~9233 */
#define IMOS_MW_DEBUG_AF_PUSH                    49       /**< AF调式接口，触发一键聚焦 */
#define IMOS_MW_DEBUG_AF_ZTMAP                   50       /**< AF调式接口，设置变倍跟随曲线 0~6000cm */
#define IMOS_MW_DEBUG_AF_ZSPEED                  51       /**< AF调式接口，设置当前ZOOM电机速度 0~7级 */
#define IMOS_MW_DEBUG_AF_FSPEED                  52       /**< AF调式接口，设置当前FOCUS电机速度 0~7级 */
#define IMOS_MW_DEBUG_AF_IRIS                    53       /**< AF调式接口，设置当前光圈大小 0~100 */

/**@brief 内部调试命令 */
#define IMOS_MW_DEBUG_TIME_CHANGE                1025     /**< 时间变更通知消息 */

/**@brief 装备测试命令 */
#define IMOS_MW_EQUIPMENT_TEST_IRCUTSWITCH       10       /**< 装备测试命令 设置 IRCut开关对应参数 ULONG: 0表示OFF,1表示ON */ 
#define IMOS_MW_EQUIPMENT_TEST_DEFECTPIXEL       11       /**< 装备测试命令 获取 对应参数 IMOS_MW_DEFECTPIXEL_INFO */
#define IMOS_MW_EQUIPMENT_TEST_LASERSWITCH       12       /**< 装备测试命令 设置 激光功能启停； 对应参数 ULONG: 0表示OFF,1表示ON */ 
#define IMOS_MW_EQUIPMENT_TEST_ASSISTANTFOCUS    13       /**< 装备测试命令 设置 辅助聚焦启停； 对应参数 ULONG: 0表示OFF,1表示ON */ 
#define IMOS_MW_EQUIPMENT_TEST_FPNCAPTURESWITCH  14       /**< 装备测试命令 设置 Fpn数据采集开关； 对应参数 ULONG: 0表示OFF,1表示ON */ 
#define IMOS_MW_EQUIPMENT_TEST_FPNCAPTURESTATUS  15       /**< 装备测试命令 获取 Fpn数据采集状态； 对应参数 ULONG: 采集完成: 1 未完成采集: 0*/                  
#define IMOS_MW_EQUIPMENT_TEST_SCENETYPE         16       /**< 装备测试命令 设置 场景类型； 对应参数 ULONG:通用:2 客观:5 */
#define IMOS_MW_EQUIPMENT_TEST_DOME_IRCTRL       17       /**< 装备测试命令 球机控制红外灯； 对应参数IMOS_MW_DOME_IRCTRL_S;  */
#define IMOS_MW_EQUIPMENT_TEST_FOCUSVALUE        34       /**< 装备测试命令 获取清晰度评价值 参数类型: ULONG */
#define IMOS_MW_EQUIPMENT_TEST_DEFAULTCFG        19       /**< 装备测试命令 删除全部配置信息并且关闭网口 参数类型: ULONG 无意义 */

/**@brief 调试命令类型 */
#define IMOS_MW_DEBUG_MSG_GET                    0        /**< 获取参数 */
#define IMOS_MW_DEBUG_MSG_SET                    1        /**< 设置参数 */
#define IMOS_MW_DEBUG_MSG_DEL                    2        /**< 删除参数 */

/**@brief 测试命令类型 */
#define IMOS_MW_TEST_MSG_GET                     0        /**< 获取参数命令 */
#define IMOS_MW_TEST_MSG_SET                     1        /**< 设置参数命令 */
#define IMOS_MW_TEST_MSG_DEL                     2        /**< 删除参数命令 */

/* 自动跟踪相关增加XP接口定义 */

/* "区域行为"方向 */
#define IMOS_MW_AREA_DIRECTION_IN         0             /**< In */
#define IMOS_MW_AREA_DIRECTION_OUT        1             /**< Out */
#define IMOS_MW_AREA_DIRECTION_ALL        2             /**< 双向 */
#define IMOS_MW_AREA_DIRECTION_MAX        3
#define IMOS_MW_AREA_DIRECTION_INVALID    0XFFFFFFFF


#if 0
#endif
/**************************************** 内部使用定义 ***************************************/
/*@brief gsoap调用endpoint长度 */
#define IMOS_MW_ENDPOINT_LEN                       96  

/*@brief 用户登录密码，密文口令（加密后）字符串长度 */
#define IMOS_MW_PASSWD_ENCRYPT_LEN          64  

#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NAME       "TrafficLightTemplate.zip"  /**< 红绿灯模板压缩包文件名 */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_PATH       "/config"                   /**< 红绿灯模板压缩包存放路径 */

/* 传输的文件类型定义 */
#define MW_SDK_FILE_TYPE_EP_TRAFFICLIGHT_TEMPLATE    "EP_TrafficLight_Template"  /**< 红绿灯模板 */
#define MW_SDK_FILE_TYPE_CONFIG_FILE                 "Config_File"               /**< 配置文件   */
#define MW_SDK_FILE_TYPE_HCMUPGRADE_TYPE             "HCM_Upgrade"               /**< 机芯版本文件，用于机芯升级 */
#define MW_SDK_FILE_TYPE_INNER_CFG                   "Inner_Config"              /**< 透明配置 */
#define MW_SDK_FILE_TYPE_FONT_FILE                   "Font_File"                 /**< 字库文件 */
#define MW_SDK_FILE_TYPE_CUSTOMER_FILE               "Customer_File"             /**< 客户logo文件 */

/* 透明配置文件名称 (按业务) */
#define MW_SDK_INNER_CFG_AUTOTRACK                   "AutoTrackCfg.txt"          /**< 自动跟踪配置 */

/**************************************** 照片结构 ***************************************/
#define IMOS_MW_TRAFFIC_PIC_MAX_NUM                          8           /**< 最大照片数 */
#define IMOS_MW_UNIVIEW_MAX_TIME_LEN                         18          /**< 照片结构时间信息最大长度 */
#define IMOS_MW_PLACE_NAME_MAX_LEN                           256         /**< 照片结构地点名称最大长度 */
#define IMOS_MW_CAR_PLATE_MAX_LEN                            32          /**< 号牌号码最大长度 */
#define IMOS_MW_DEV_ID_MAX_LEN                               32          /**< 设备编号最大长度 */
#define IMOS_MW_TOLLGATE_NAME_MAX_LEN                        64          /**< 卡口设备名称最大长度 */
#define IMOS_MW_DIRECTION_NAME_MAX_LEN                       64          /**< 方向名称最大长度 */
#define IMOS_MW_CAR_VEHICLE_BRAND_LEN                        4           /**< 车标编码最大长度 */


#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_DEF_H__*/

