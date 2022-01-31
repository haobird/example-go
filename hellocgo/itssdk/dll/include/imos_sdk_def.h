/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_def.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 2012-01-14
        Author:  
   Description: ���ļ�������sdk��صĴ����롢��

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
����ѡ��
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

/* ������׼����Լ�� */
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
ͨ���������Ͷ���
*******************************************************************************/
/** @brief 8λ�з������� */
#ifndef CHAR
typedef char CHAR;
#endif

/** @brief 8λ�޷������� */
#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

/** @brief 16λ�з������� */
#ifndef SHORT
typedef short SHORT;
#endif

/** @brief 16λ�޷������� */
typedef unsigned short USHORT;

/** @brief 32λ�з������� */
typedef long LONG;

/** @brief 32λ�޷������� */
typedef unsigned long ULONG;

/** @brief �з������� */
typedef int INT;

/** @brief �޷������� */
typedef unsigned int UINT;

/** @brief 64λ�з������� */
#if defined (_MSC_VER)
typedef __int64 DLONG;
#else
typedef long long DLONG;
#endif

/** @brief 64λ�޷������� */
#if defined (_MSC_VER)
typedef unsigned __int64 DULONG;
#else
typedef unsigned long long DULONG;
#endif

/** @brief ˫������������ */
typedef double DOUBLE;

/** @brief ������������ */
typedef float FLOAT;

/** @brief ������ */
typedef unsigned long BOOL_T;

/** @brief ��ʾ������������ */
typedef unsigned long SIZE_T;

/** @brief ��ʾʱ���������� */
typedef long TIME_T;

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;

/** @brief VOID�� */
#define VOID                            void

/** @brief ��ʾͨ�þ������ */
typedef VOID* HANDLE;

/** @brief IMOS ID �������� */
typedef DULONG IMOS_ID;

/** @brief ͨ�þ������ IMOS_HANDLE */
#ifndef IMOS_HANDLE
#if defined (WIN32)
typedef HANDLE IMOS_HANDLE;
#else
typedef int IMOS_HANDLE;
#endif
#endif

/** @brief �����������Ͷ��� */
#define IN
#define OUT
#define INOUT

/** @brief IMOS��̹淶����ֵ */
#define BOOL_TRUE                       ((BOOL_T) 1)
#define BOOL_FALSE                      ((BOOL_T) 0)

#ifndef NULL
#define NULL (void *)0
#endif


#if 0
#endif
/*******************************************************************************
SDK ������/״̬��
*******************************************************************************/
/* ͨ�óɹ� */
#define ERR_COMMON_SUCCEED                       0x000000      /**< ִ�гɹ� */

/*********************** SDK ״̬�붨��(257 - 356) *****************************/
#define ERR_SDK_LOG_CLOSE                        257            /**< SDK ��־�ر� */
#define ERR_SDK_DEVICE_STREAM_FULL               259            /**< �豸������ */
#define ERR_SDK_DEVICE_STREAM_CLOSED             260            /**< �豸���ѹر� */
#define ERR_SDK_DEVICE_STREAM_NONEXIST           261            /**< �豸�������� */
#define ERR_SDK_USER_PASSWORD_CHANGE             262            /**< �û������޸� */
#define ERR_SDK_USER_DELETED                     263            /**< �û���ɾ�� */

/*********************** SDK �����붨��(357 - 506) *****************************/
#define ERR_SDK_COMMON_FAIL                      357            /**< ����ʧ�� */
#define ERR_SDK_COMMON_INVALID_PARAM             358            /**< ��������Ƿ� */
#define ERR_SDK_COMMON_NO_MEMORY                 359            /**< ϵͳ�ڴ治�� */
#define ERR_SDK_COMMON_SYS_FAIL                  360            /**< ϵͳͨ�ô���Q: ��δʹ�� */
#define ERR_SDK_COMMON_FAIL_STAT                 361            /**< ��ȡ�ļ���Ŀ¼��״̬ʧ�� */
#define ERR_SDK_COMMON_FILE_NONEXIST             362            /**< �ļ������� */
#define ERR_SDK_COMMON_NOTSUPPORT                363            /**< �ӿڲ�֧�� */

#define ERR_SDK_USER_NOT_AUTHORIZED              457            /**< �û�δ��Ȩ */
#define ERR_SDK_USERFULL                         458            /**< �û����� */
#define ERR_SDK_USERNONEXIST                     459            /**< �û������� */
#define ERR_SDK_USER_PASSWD_INVALID              460            /**< �û�������� */
#define ERR_SDK_USER_KEEPALIVEFAIL               461            /**< SDK����ʧ�� */
#define ERR_SDK_NOTINIT                          462            /**< SDKδ��ʼ�� */
#define ERR_SDK_REINIT                           463            /**< SDK�ѳ�ʼ�� */

#define ERR_SDK_CREATE_THREAD_FAIL               466            /**< �����߳�ʧ�� */
#define ERR_SDK_NOENOUGH_BUF                     467            /**< ������̫С: �����豸���ݵĻ����� */
#define ERR_SDK_SOCKET_LSN_FAIL                  468            /**< ����socket listenʧ�� */
#define ERR_SDK_SUBSCRIBE_FULL                   470            /**< ���û���������, �豸���û����������Ĵ����벻�ܷ��� */
#define ERR_SDK_COMMAND_SEND_FAIL                471            /**< ������ʧ�� */
#define ERR_SDK_COMMAND_TIMEOUT                  472            /**< ����ʱ */
#define ERR_SDK_UPDATE_NOTADMIN                  473            /**< ��admin�û��޷����� */
#define ERR_SDK_UPDATE_INVALID                   474            /**< ���� δ��ʼ */
#define ERR_SDK_UPDATE_INPROCESS                 475            /**< ���� ������ */
#define ERR_SDK_UPDATE_NOMEMORY                  476            /**< ���� �ڴ�ռ䲻�� */
#define ERR_SDK_UPDATE_FILE_OPEN_ERR             477            /**< ���� �򿪾����ļ����� */
#define ERR_SDK_UPDATE_DEVICE_ERR                478            /**< ���� FLASH���� */
#define ERR_SDK_UPDATE_BUSY                      479            /**< ����ͬʱ���ض���������� */
#define ERR_SDK_UPDATE_FAIL_TIMEOUT              480            /**< ������ʱ */

#define ERR_SDK_IP_CONFLICT                      486            /**< IP��ַ��ͻ */
#define ERR_SDK_NETWORKMODE_NOTSUPPORT           487            /**< ����ģʽ��֧�� */


/*********************** SDK ҵ��ģ������붨��(507-656) *******************/
/* �豸ά�����(507 - 556) */
#define ERR_SDK_INVALID_CONFIGFILE               507            /**< �����ļ���Ч */
#define ERR_SDK_IVA_WORK_MODE_NOT_SUPPORT        508            /**< ����ģʽ��֧���ֶ�ץ�� */
#define ERR_SDK_IVA_MANUAL_SNAP_PTZ_MOVING       509            /**< ��̨�˶���,�ֶ�ץ��������Ч */
#define ERR_SDK_EXCEED_CONFIG_FULL               510            /**< Smart�������ó������ֵ */

/* ý�����(557 - 606) */
#define ERR_SDK_BIAUDIO_AUDIOBCAST_FULL          557            /**< ����ҵ������ */
#define ERR_SDK_STOR_RESOURCE_NOTINIT            558            /**< �洢��Դδ���� */
#define ERR_SDK_MEDIA_ENCODELIMITED              559            /**< ������������ */

/* ��̨���(607 - 656) */
#define ERR_SDK_PTZ_TRACK_ISUSED                 612            /**< �켣��ʹ�ã��޷�ɾ��*/
#define ERR_SDK_PTZ_SERIALMODE_MISMATCH          614            /**< ����ģʽ��ƥ��*/
#define ERR_SDK_PTZ_TRACK_NOT_EXIST              618            /**< �켣������*/
#define ERR_SDK_PTZ_MODE_CRUISE_FULL             626            /**< ģʽ·���켣��������� */


/*********************** SDK �����������붨��(657 - 756) ****************************/
#define ERR_SDK_XP_INIT_FAILED                   657            /**< ��������ʼ��ʧ�� */
#define ERR_SDK_XP_PORT_ALLOC_FAILED             658            /**< ������ͨ������ʧ�� */
#define ERR_SDK_XP_PORT_NOT_EXIST                659            /**< ������ͨ�������� */
#define ERR_SDK_XP_START_STREAM_FAILED           660            /**< ����������ʧ�� */
#define ERR_SDK_XP_START_PLAY_FAILED             662            /**< ��ʼ����ʧ�� */
#define ERR_SDK_XP_FILE_PLAY_FINISHED            669            /**< �ļ��Ѳ����� */
#define ERR_SDK_XP_DISK_CAPACITY_WARN            670            /**< Ӳ��ʣ��ռ������ֵ */
#define ERR_SDK_XP_DISK_CAPACITY_NOT_ENOUGH      671            /**< Ӳ��ʣ��ռ䲻�� */
#define ERR_SDK_XP_NO_PICTURE_TO_SNATCH          672            /**< û�н������ͼƬ�ɹ�ץ�� */
#define ERR_SDK_XP_SERIES_SNATCH_FAILED          673            /**< ����ץ�Ĺ�����ץ��ʧ�� */
#define ERR_SDK_XP_WRITE_FILE_FAILED             674            /**< д�ļ�����ʧ�� */
#define ERR_SDK_XP_FILE_DESTROY                  675            /**< �ļ����� */
#define ERR_SDK_XP_NOT_SUPPORT_MEDIA_ENCODE_TYPE 676            /**< ý������ʽ��֧��¼����� */
#define ERR_SDK_XP_PROCESS_MEDIA_DATA_FAILED     677            /**< ý�����ݴ���ʧ�� */
#define ERR_SDK_XP_RECV_DATA_FAILED              678            /**< ���������ɽ�������ʧ�� */
#define ERR_SDK_XP_MEDIA_RESOLUTION_CHANGE       679            /**< ý�����ֱ��ʷ����仯 */
#define ERR_SDK_XP_VOICE_RUNNING_ERROR           680            /**< �����Խ���㲥�����г��� */
#define ERR_SDK_XP_AUDIO_DEVICE_UNRIPE           682            /**< ��Ƶ�豸δ׼���� */

/**@brief ¼��ָ��ϱ����� */
#define ERR_SDK_PLAYER_RECORDSTATE_MANUAL        683       /**< �ֶ�ֹͣ */
#define ERR_SDK_PLAYER_RECORDSTATE_SUBSECTION    684       /**< ������ָ� */
#define ERR_SDK_PLAYER_RECORDSTATE_CAPACITYLIMIT 685       /**< �������Ƶ��� */


/*********************** MA  �ͻ��˴����붨��(757 -/) ****************************/
#define ERR_SDK_MA_SUCCEED                       757            /**< MA �ɹ� */
#define ERR_SDK_MA_FAIL                          758            /**< MA ʧ�� */
#define ERR_SDK_MA_INVALID_PARAM                 759            /**< MA �������� */
#define ERR_SDK_MA_MALLOC_FAIL                   760            /**< MA mallocʧ�� */
#define ERR_SDK_MA_LESS_MEMORY                   761            /**< MA �ڴ治�� */
#define ERR_SDK_MA_SOAP_ERROR                    762            /**< MA soap���� */
#define ERR_SDK_MA_NET_FAILED                    763            /**< MA �������Ӵ��� */
#define ERR_SDK_MA_USR_LOGIN                     764            /**< MA �û��Ѿ���¼ */
#define ERR_SDK_MA_AUTHORIZE_FAIL                765            /**< MA ��Ȩʧ�� */
#define ERR_SDK_MA_INVALID_IP                    766            /**< MA ��ЧIP */
#define ERR_SDK_MA_SRC_MISS                      767            /**< MA �洢Դδ�ҵ� */
#define ERR_SDK_MA_NO_STOR_CHANNEL               768            /**< MA �޿���洢ͨ��, Q: ��δʹ��? */
#define ERR_SDK_MA_NO_STOR_NODE                  769            /**< MA �޿���洢�ڵ�, Q: ��δʹ��?  */
#define ERR_SDK_MA_TASK_FULL                     770            /**< MA ������ */
#define ERR_SDK_MA_INIT_DONE                     771            /**< MA ģ���Ѿ���ʼ��, Q: ���������ֱ�ӷ��سɹ���������? */
#define ERR_SDK_MA_FULL_STOP                     772            /**< MA ��ֹͣ, Q: ��δʹ��?  */
#define ERR_SDK_MA_STREAM_BUSY                   773            /**< MA ����æ, Q: ��δʹ��?  */
#define ERR_SDK_MA_WR_ERROR                      774            /**< MA ��дʧ��, Q: ��δʹ��?  */
#define ERR_SDK_MA_EZR_UNAVAILABLE               775            /**< MA EZR������ */
#define ERR_SDK_MA_SERVICE_DOWN                  776            /**< MA EZR������ֹͣ */
#define ERR_SDK_MA_SERVICE_RUNNING               777            /**< MA EZR���������� */
#define ERR_SDK_MA_PORT_CONFLICT                 778            /**< MA EZR�˿ڳ�ͻ */


/*******************************************************************************
SDK �궨�� 
*******************************************************************************/
#if 0
#endif
/**************************************** �豸״̬��� ***************************************/
/**@brief �豸״̬���� */
#define IMOS_MW_STATUS_KEEPALIVE                   0            /**< SDK���״̬��Ϊ: ERR_SDK_USER_KEEPALIVEFAIL */
#define IMOS_MW_STATUS_RLOGIN                      1          /**< SDK�����ɹ���״̬��Ϊ: IMOS_MW_STATUS_RLOGIN */
#define IMOS_MW_STATUS_UPDATE                      1            /**< ���������״̬��Ϊ: ERR_SDK_UPDATE_INVALID �� */
#define IMOS_MW_STATUS_DETECTED_ACTIVITY           2            /**< �˶���������˶����� ��Ӧ����:IMOS_MW_MOTION_ACTIVITY_INFO_S */
#define IMOS_MW_STATUS_USERINFO_CHANGE             3            /**< �û���Ϣ�޸�, ״̬��Ϊ: ERR_SDK_USER_PASSWORD_CHANGE �� */ 
#define IMOS_MW_STATUS_VOLUME_INFO                 4            /**< ������Ϣ�� ��Ӧ����:IMOS_MW_VOLUME_INFO_S */
    
#define IMOS_MW_STATUS_MANAGE_SERVER_ONLINE        50           /**< ���������������״̬����Ӧ����BOOL_T: ON:1  OFF:0 */                  
#define IMOS_MW_STATUS_PHOTO_SERVER_ONLINE         51           /**< ��Ƭ������������״̬����Ӧ����BOOL_T: ON:1  OFF:0 */     
#define IMOS_MW_STATUS_BASIC_INFO                  52           /**< �豸������Ϣ����Ӧ��������: IMOS_MW_BASIC_DEVICE_INFO_S */              
#define IMOS_MW_STATUS_RUN_INFO                    53           /**< �豸����״̬����Ӧ��������: IMOS_MW_DEVICE_RUN_INFO_S */  
#define IMOS_MW_STATUS_NETWORK_CHANGE              54           /**< �������ý����״̬��Ϊ: ERR_SDK_IP_CONFLICT �� */
#define IMOS_MW_STATUS_WIFI_SCANNING_INFO          55           /**< WiFiɨ����Ϣ  ��Ӧ��������: IMOS_MW_WIFI_SCANNING_INFO_S */ 
#define IMOS_MW_STATUS_WIFI_LINK_STATUS            56           /**< WiFi����״̬  ��Ӧ��������: IMOS_MW_WIFI_LINK_STATUS_S */
#define IMOS_MW_STATUS_NETWORK_INTERFACE           57           /**< ��ǰ����״̬����Ӧ��������: IMOS_MW_NETWORK_INTERFACE_INFO_S */    

#define IMOS_MW_STATUS_STOR_MEMORY_CARD_FORMAT     90           /**< ���ش洢�豸��ʽ��״̬�� ״̬��Ϊ: ERR_COMMON_SUCCEED�� */  
#define IMOS_MW_STATUS_STOR_NAS_MOUNT              91           /**< NAS����״̬ ״̬��Ϊ: ERR_COMMON_SUCCEED�� */  

#define IMOS_MW_STATUS_PTZ                         100          /**< ��̨״̬����Ӧ��������: IMOS_MW_PTZ_STATUS_S */                        
#define IMOS_MW_STATUS_PTZ_ABS_POSITION            101          /**< ��̨����λ�ã���Ӧ��������: IMOS_MW_PTZ_ABSPOSITION_S */                    
#define IMOS_MW_STATUS_PTZ_ABS_ZOOM                102          /**< ��̨����ZOOM��������Ӧ��������: IMOS_MW_PTZ_ABSZOOM_S */  
#define IMOS_MW_STATUS_SNOWMODE                    103          /**< ��ѩģʽ״̬ ��Ӧ��������: ULONG: ON:1  OFF:0 */ 
#define IMOS_MW_STATUS_PTZ_PRESET                  104          /**< ��̨Ԥ��λִ��״̬ ��Ӧ��������: ULONG: OK:1  NOK:0 */ 
    
#define IMOS_MW_STATUS_SCENE_CURRENT               120          /**< �����Զ��л��ĵ�ǰ����ID, ��Ӧ��������: ULONG */
    
#define IMOS_MW_STATUS_OSD_3DCOVER                 131          /**< 3D��Ƶ�ڸ�OSDλ�ã���Ӧ����: IMOS_MW_OSD_3DCOVER_POSITION_S */   
#define IMOS_MW_STATUS_SERIALINPUTDATA             131
    
#define IMOS_MW_STATUS_RADAR                       150          /**< �״�״̬  ��Ӧ����: IMOS_MW_RADAR_XXX */                           
#define IMOS_MW_STATUS_COIL                        151          /**< ��Ȧ״̬  ��Ϣ����Ϊ: IMOS_MW_COIL_STATE_S �����飬֧�� 8��*/          
#define IMOS_MW_STATUS_POLARIZER                   152          /**< ƫ��״̬  ��Ӧ����: IMOS_MW_POLARIZER_STATUS_XXX */                     
#define IMOS_MW_STATUS_LED_STROBE                  153          /**< LED��״̬  ��Ӧ����: IMOS_MW_LED_STROBE_STATUS_XXX */ 
#define IMOS_MW_STATUS_ND_FILTER                   154          /**< ND�˾�״̬  ��Ӧ����: IMOS_MW_POLARIZER_STATUS_INUSE */
#define IMOS_MW_STATUS_TRAFFICLIGHT                155          /**< �źŵ�ʵʱ����״̬  ��Ӧ����: IMOS_MW_TRAFFICLIGHT_STATUS_XXX */

#define IMOS_MW_STATUS_SD                          156          /**< SD��״̬  ��Ӧ����: IMOS_MW_SD_STATUS_NOEXIST */
#define IMOS_MW_STATUS_CAPTURE                     157          /**< ץ���ϱ� ��Ӧ����:IMOS_MW_CAPTURE_AUTO_TYPE */

#define IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT      160          /**< ��λ״̬�ϱ� ��Ӧ����:IMOS_MW_PARK_STATUS_S */
#define IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT_EX   164          /**< ��λ״̬�ϱ���չ ��Ӧ����:IMOS_MW_PARK_STATUS_EX_S */

#define IMOS_MW_STATUS_TRAFFIC_PARAM_REPORT        169          /**< ��ͨ�����ϱ� ��Ӧ����:IMOS_MW_TRAFFIC_PARA_RSLT_S */
#define IMOS_MW_STATUS_VEHICLE_PARAM_REPORT        170          /**< ��������״̬�ϱ� ��Ӧ����:IMOS_MW_VEHICLE_STATE_S */

#define IMOS_MW_STATUS_PLAYER_RECORD_VIDEO         200          /**< ����¼��������ϱ�������Ϣ����Ϣ���ݼ�: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_MEDIA_PROCESS        201          /**< ��Ƶý�崦������е��ϱ�������Ϣ����Ϣ���ݼ�: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_SERIES_SNATCH        202          /**< ����ץ�Ĺ������ϱ�������Ϣ����Ϣ���ݼ�: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_MEDIA_VOICE          203          /**< ����ҵ��������ϱ�������Ϣ����Ϣ���ݼ�: IMOS_MW_PLAYER_STATUS_S */
#define IMOS_MW_STATUS_PLAYER_RECORD_VIDEOEX       204          /**< ����¼����չ��¼��ָ�������ϱ�������Ϣ����Ϣ���ݼ�: IMOS_MW_PALYER_RECORDSTATUS_S */
    
/**@brief �豸����ģʽ */
#define IMOS_MW_DEVICE_WORK_MODE_TOLLGATE          0             /**< ���� */
#define IMOS_MW_DEVICE_WORK_MODE_ELEC_POLICE       1             /**< �羯 */
    
/**@brief ��̨״̬ */
#define IMOS_MW_PTZ_STATUS_IDLE                    0             /**< ����״̬ */
#define IMOS_MW_PTZ_STATUS_USER_CTRL               1             /**< �û����� */
#define IMOS_MW_PTZ_STATUS_AUTO_CRUISE             2             /**< �Զ�Ѳ�� ulStatusPara1=�켣ID */
#define IMOS_MW_PTZ_STATUS_MANUAL_CRUISE           3             /**< �ֶ�Ѳ�� ulStatusPara1=�켣ID */
#define IMOS_MW_PTZ_STATUS_TRACK_RECORD            4             /**< �켣¼�� ulStatusPara1=�켣ID */
#define IMOS_MW_PTZ_STATUS_IVA_PLAN                5             /**< ���ܼƻ�ִ�й����� */

/**@brief �״�״̬ */
#define IMOS_MW_RADAR_STATUS_DISCONNECT            0             /**< �״�δ���� */
#define IMOS_MW_RADAR_STATUS_CONNECT               1             /**< �״����� */
    
/**@brief ��Ȧ״̬ */
#define IMOS_MW_COIL_STATUS_DISCONNECT             0             /**< ��Ȧ�Ͽ� */
#define IMOS_MW_COIL_STATUS_CONNECT                1             /**< ��Ȧ���� */
#define IMOS_MW_COIL_STATUS_UNUSE                  2             /**< ��Ȧδʹ�� */
    
/**@brief ƫ��״̬ */
#define IMOS_MW_POLARIZER_STATUS_INUSE             0             /**< ����ʹ�� */
#define IMOS_MW_POLARIZER_STATUS_UNUSE             1             /**< δʹ�� */
#define IMOS_MW_POLARIZER_STATUS_DOWNING           2             /**< �����½� */
#define IMOS_MW_POLARIZER_STATUS_UPING             3             /**< �������� */
#define IMOS_MW_POLARIZER_STATUS_UNKNOWN           4             /**< �쳣 */
#define IMOS_MW_POLARIZER_STATUS_SWITCHING         5             /**< �л��� */

/**@brief ��ͨ�Ƽ����ʵʱ����״̬ */
#define IMOS_MW_TRAFFICLIGHT_STATUS_OFFLINE        0             /**< ���� */
#define IMOS_MW_TRAFFICLIGHT_STATUS_ONLINE         1             /**< ���� */
#define IMOS_MW_TRAFFIClIGHT_STATUS_UNUSED         2             /**< δʹ�� */

/**@brief LED��״̬ */
#define IMOS_MW_LED_STROBE_STATUS_ON               0              /**< �� */
#define IMOS_MW_LED_STROBE_STATUS_OFF              1              /**< �ر� */

/**@brief SD��״̬ */
#define IMOS_MW_SD_STATUS_NOEXIST                  0             /**< ������ */
#define IMOS_MW_SD_STATUS_FAULT                    1             /**< ���� */
#define IMOS_MW_SD_STATUS_CHECKING                 2             /**< ����� */
#define IMOS_MW_SD_STATUS_NORMAL                   3             /**< ���� */

/**@brief ����������ģʽ */
#define IMOS_MW_MANAGE_SERVER_PROTOCOL_IMOS         0             /**< ����Э��ΪIMOS */
#define IMOS_MW_MANAGE_SERVER_PROTOCOL_GB           1             /**< ����Э��ΪGB */
#define IMOS_MW_MANAGE_SERVER_PROTOCOL_NONE         2             /**< ����Э��Ϊ�� */

/**@brief ץ����Ƭ���� */
#define IMOS_MW_CAPTURE_AUTO_TYPE                   0             /**< �Զ�ץ�ģ���������ץ�ġ����ߴ��� */
#define IMOS_MW_CAPTURE_MANUAL_TYPE                 1             /**< �ֶ�ץ�� */

/**@brief ��ͨ�����������ϱ������������� */ 
#define IMOS_MW_CAR_TYPE_NUM                         12           /**< ����������Ŀ */
#define IMOS_MW_LPR_COLOR_NUM                        5            /**< ������ɫ��Ŀ */
#define IMOS_MW_CAR_SPEED_NUM                        2            /**< ������Ŀ */

#if 0
#endif
/*************************************** ������� ********************************************/
/**@brief ���ò��������� */
/* ϵͳ����:  �汾���� ������ģʽ�����油¼ */
#define IMOS_MW_SYSTEM_TIME_INFO            0          /**< ��ȡ/���� ϵͳʱ��(��ʱ����Ϣ)����Ӧ�ṹ����: IMOS_MW_SYSTEM_TIME_INFO_S */
#define IMOS_MW_SYSLOG_SERVER_INFO          1          /**< ��ȡ/���� syslog��������Ϣ����Ӧ�ṹ����: IMOS_MW_SYSLOG_SERVER_INFO_S */ 
#define IMOS_MW_MANAGE_SERVER_CFG           3          /**< ��ȡ/���� ������������ã���Ӧ�ṹ����: IMOS_MW_MANAGE_SERVER_CFG_S */
#define IMOS_MW_DEVICE_INSATLLATION_INFO    5          /**< ��ȡ/���� �豸��װ��Ϣ���μ�: IMOS_MW_DEVICE_INSATLLATION_INFO_S */
#define IMOS_MW_BM_SERVER_CFG               6          /**< ��ȡ/���� BM���������ã���Ӧ�ṹ����: IMOS_MW_BM_SERVER_CFG_S */
#define IMOS_MW_DEVICE_NAME_CFG             7          /**< ��ȡ/���� �豸�������ã���Ӧ�ṹ����: IMOS_MW_DEVICE_NAME_CFG_S */
#define IMOS_MW_NTP_SERVER_CFG              8          /**< ��ȡ/���� NTP���������ã���Ӧ�ṹ����: IMOS_MW_NTP_SERVER_CFG_S  */
#define IMOS_MW_DCOUT_CFG                   9          /**< ��ȡ/���� ��Դ������ã���Ӧ�ṹ����: IMOS_MW_DCOUT_CFG_S */

/* ���ڡ����ڡ�͸��ͨ�� */
#define IMOS_MW_SERIAL_CFG                  10         /**< ��ȡ/���� �������ã���Ӧ�ṹ����: IMOS_MW_SERIAL_CFG_S */
#define IMOS_MW_TRANSPORT_CFG               11         /**< ��ȡ/���� ͸��ͨ�����ã���Ӧ�ṹ����: IMOS_MW_TRANSPORT_CFG_S */
#define IMOS_MW_NETWORK_INTERFACE_CFG       12         /**< ��ȡ/���� �������ã���Ӧ�ṹ����: IMOS_MW_NETWORK_INTERFACE_CFG_S */
#define IMOS_MW_UNP_CFG                     13         /**< ��ȡ/���� UNP���ã���Ӧ�ṹ����: IMOS_MW_UNP_CFG_S */ 
#define IMOS_MW_WIFI_CFG                    14         /**< ��ȡ/���� WiFi�������� ��Ӧ�ṹ����: IMOS_MW_WIFI_CFG_S */

#define IMOS_MW_MULTI_TRANSPORT_CFG         2005      /**< ��ȡ/���� ��͸��ͨ�����ã���Ӧ�ṹ����: IMOS_MW_MULTI_TRANSPORT_CFG_S */      

/* ͼ��������� */
#define IMOS_MW_EXPOSURE_CFG                20         /**< ��ȡ/���� �ع��������Ӧ�ṹ����: IMOS_MW_EXPOSURE_CFG_S */
#define IMOS_MW_EXPOSURE_CFG_VIDEO          507        /**< ��ȡ/���� �ع���Ƶ��������Ӧ�ṹ����: IMOS_MW_EXPOSURE_CFG_VIDEO */
#define IMOS_MW_EXPOSURE_CFG_IMAGE          508        /**< ��ȡ/���� �ع�ͼ���������Ӧ�ṹ����: IMOS_MW_EXPOSURE_CFG_IMAGE */

#define IMOS_MW_WHITE_BALANCE_CFG           21         /**< ��ȡ/���� ��ƽ���������Ӧ�ṹ����: IMOS_MW_WHITE_BALANCE_CFG_S */
#define IMOS_MW_IMAGE_ENHANCE_CFG           22         /**< ��ȡ/���� ͼ����ǿ��������Ӧ�ṹ����: IMOS_MW_IMAGE_ENHANCE_CFG_S */
#define IMOS_MW_FOCUS_CFG                   23         /**< ��ȡ/���� �Խ���������Ӧ�ṹ����: IMOS_MW_FOCUS_CFG_S */
#define IMOS_MW_IMAGE_MISC_CFG              24         /**< ��ȡ/���� ͼ�������������Ӧ�ṹ����: IMOS_MW_IMAGE_MISC_CFG_S */
#define IMOS_MW_SCENEID_INUSE               26         /**< ��ȡ/���� ��ǰ����ID����Ӧ����: ULONG */
#define IMOS_MW_CONDITION_INFO              27         /**< ��ȡ  ��ǰ������������Ӧ����: IMOS_MW_CONDITION_INFO_S */
#define IMOS_MW_IR_CTRL_CFG                 28         /**< ��ȡ/���� ������Ʋ�������Ӧ�ṹ����: IMOS_MW_IR_CTRL_CFG_S */
#define IMOS_MW_SCENE_CFG_EX                29         /**< ��ȡ/���� ������չ�������ã���Ӧ��ṹ����: IMOS_MW_SCENE_CFG_EX_S */
#define IMOS_MW_SCENE_CFG_EX2               201        /**< ��ȡ/���� ������չ�������ã���Ӧ��ṹ����: IMOS_MW_SCENE_CFG_EX2_S */
#define IMOS_MW_DEFAULT_SCENE               202        /**< ��ȡ/���� Ĭ�ϳ���ID����Ӧ����: ULONG */
#define IMOS_MW_VIEW_MODE                   203        /**< ��ȡ/���� �����ӽ�ģʽ���ã���Ӧ����: ULONG */
#define IMOS_MW_LIGHT_MODE                  204        /**< ��ȡ/���� �����ģʽ����Ӧ����: IMOS_MW_LIGHT_MODE_S */
#define IMOS_MW_SEND_MODE                   206        /**< ��ȡ/���� ��������ģʽ���ã���Ӧ����: ULONG */


/* ��Ƶ���롢��Ƶ����������OSD��ROI */
#define IMOS_MW_VIDEOIN_MODE_CFG            30         /**< ��ȡ/���� ��Ƶ������ʽ����Ӧ�ṹ����: IMOS_MW_VIDEOIN_MODE_CFG_S */
#define IMOS_MW_VIDEO_ENCODER_CFG           31         /**< ��ȡ/���� ��Ƶ����������ã���Ӧ�ṹ����:IMOS_MW_VIDEO_ENCODER_CFG_S */
#define IMOS_MW_AUDIO_IN_CFG                32         /**< ��ȡ/���� ��Ƶ����������ã���Ӧ�ṹ����:IMOS_MW_AUDIO_IN_CFG_S */
#define IMOS_MW_AUDIO_OUT_CFG               33         /**< ��ȡ/���� ��Ƶ����������ã���Ӧ�ṹ����:IMOS_MW_AUDIO_OUT_CFG_S */
#define IMOS_MW_ROI_CFG                     34         /**< ��ȡ/���� ROI ���ã���Ӧ�ṹ����: IMOS_MW_ROI_S */
#define IMOS_MW_OSD_STYLE_CFG               35         /**< ��ȡ/���� ����OSD��ʽ���ã���Ӧ�ṹ����: IMOS_MW_OSD_STYLE_CFG_S */
#define IMOS_MW_OSD_STYLE_EX_CFG            205        /**< ��ȡ/���� ������չOSD��ʽ���ã���Ӧ�ṹ����: IMOS_MW_OSD_STYLE_EX_CFG_S */
#define IMOS_MW_INFO_OSD_CFG                36         /**< ��ȡ/����/ɾ�� ����OSD���ã���Ӧ�ṹ����: IMOS_MW_INFO_OSD_CFG_S */
#define IMOS_MW_COVER_OSD_CFG               37         /**< ��ȡ/����/ɾ�� �ڸ�OSD���ã���Ӧ�ṹ����: IMOS_MW_COVER_OSD_CFG_S */
#define IMOS_MW_SUB_OSD_CFG                 38         /**< ��ȡ/���� ����OSD���ã���Ӧ�ṹ����: IMOS_MW_SUB_OSD_CFG_S */
#define IMOS_MW_AUTO_SEND_STREAM_CFG        39         /**< ��ȡ/���� ��ý�屣������ ��Ӧ�ṹ����: IMOS_MW_AUTOSEND_STREAM_CFG_S */

    
/* �澯�������: �˶���⡢�ڵ���⡢������⡢�¶ȡ����뿪��������������������������������ƻ� */
#define IMOS_MW_ALARM_LINK_CFG              40         /**< ��ȡ/���� �澯�������ã���Ӧ�ṹ����: IMOS_MW_ALARM_LINK_CFG_S */
#define IMOS_MW_ALARM_MOVE_DETECT_CFG       41         /**< ��ȡ/���� �˶����������Ϣ����Ӧ�ṹ����: IMOS_MW_VIDEO_MOTION_CFG_S */ 
#define IMOS_MW_ALARM_TEMPERATURE_CFG       42         /**< ��ȡ/���� �¶�������Ϣ����Ӧ�ṹ����: IMOS_MW_TEMPERATURE_CFG_S */ 
#define IMOS_MW_ALARM_INPUT_SWITCH_CFG      43         /**< ��ȡ/���� ���뿪������Ϣ����Ӧ�ṹ����: IMOS_MW_INPUT_SWITCH_CFG_S */ 
#define IMOS_MW_ALARM_OUTPUT_SWITCH_CFG     44         /**< ��ȡ/���� �����������Ϣ����Ӧ�ṹ����: IMOS_MW_OUTPUT_SWITCH_CFG_S */ 
#define IMOS_MW_ALARM_DEFEND_CFG            45         /**< ��ȡ/���� �����ƻ����ã���Ӧ�ṹ����: IMOS_MW_DEFEND_PLAN_CFG_S */
#define IMOS_MW_ALARM_AUDIO_DETECT_CFG      46         /**< ��ȡ/���� �������������Ϣ����Ӧ�ṹ����: IMOS_MW_AUDIO_DETECT_CFG_S */ 
#define IMOS_MW_ALARM_TAMPER_DETECT_CFG     47         /**< ��ȡ/���� �ڵ����������Ϣ����Ӧ�ṹ����: IMOS_MW_TAMPER_DETECT_CFG_S */ 
    
/* ��̨���: ��̨���á�Ԥ��λ�б�Ѳ���ƻ�(�ܡ�����)��Ѳ��·�ߡ�����Ŵ�������� */
#define IMOS_MW_PTZ_CFG                     50         /**< ��ȡ/���� ��̨������Ϣ����Ӧ�ṹ����Ϊ: IMOS_MW_PTZ_CFG_S */
#define IMOS_MW_PTZ_PRESET_CFG              51         /**< ��ȡ      Ԥ��λ��Ϣ����Ӧ�ṹ����: IMOS_MW_PRESET_CFG_S */    
#define IMOS_MW_PTZ_GUARD_PRESET_CFG        52         /**< ��ȡ/���� ����λ��Ϣ����Ӧ�ṹ����: IMOS_MW_GUARD_PRESET_CFG_S */
#define IMOS_MW_PTZ_TRACK_CFG               53         /**< ��ȡ      Ѳ���켣���ã���Ӧ�ṹ����: IMOS_MW_CRUISE_TRACK_CFG_S */
#define IMOS_MW_PTZ_CRUISE_PLAN_CFG         54         /**< ��ȡ/���� ��̨Ѳ���ƻ�������Ϣ����Ӧ�ṹ����: IMOS_MW_CRUISE_PLAN_CFG_S */
#define IMOS_MW_PTZ_PHYPARAM_CFG            55         /**< ��ȡ/���� ��̨�����������(��ͨ������Ŵ����)  ��Ӧ�ṹ����: IMOS_MW_PTZ_PHYPARAM_CFG_S */
#define IMOS_MW_PTZ_DIRECTION_CFG           56         /**< ����      ��̨��λ��Ϣ ��Ӧ�ṹ����Ϊ: ULONG  �μ�: IMOS_MW_PTZ_DIRECTION_E */
    
/* �������: �������á��������� */
#define IMOS_MW_PHOTO_SERVER_CFG            61         /**< ��ȡ/���� ��Ƭ���շ�������Ϣ����Ӧ�ṹ����: IMOS_MW_PHOTO_SERVER_CFG_S */
#define IMOS_MW_FLASH_LIGHT_CFG             62         /**< ��ȡ/���� ��������ã���Ӧ�ṹ����: IMOS_MW_FLASH_LIGHT_CFG_S */
#define IMOS_MW_VEHICLE_DETECTOR_CFG        63         /**< ��ȡ/���� ���������ã���Ӧ�ṹ����: IMOS_MW_VEHICLE_DETECTOR_CFG_S */
#define IMOS_MW_RADAR_CFG                   64         /**< ��ȡ/���� �״����ã���Ӧ�ṹ����: IMOS_MW_RADAR_CFG_S */
#define IMOS_MW_CAMERA_CAPTURE_CFG          65         /**< ��ȡ/���� ץ�����ã���Ӧ�ṹ����: IMOS_MW_CAMERA_CAPTURE_CFG_S */
#define IMOS_MW_VIDEO_DETECT_CFG            66         /**< ��ȡ/���� ��Ƶ������ã���Ӧ�ṹ����: IMOS_MW_VIDEO_DETECT_CFG_S */
#define IMOS_MW_PLATE_IDENTIFY_CFG          67         /**< ��ȡ/���� ����ʶ�����ã���Ӧ�ṹ����: IMOS_MW_PLATE_IDENTIFY_CFG_S */
#define IMOS_MW_DRIVEWAY_CFG                68         /**< ��ȡ/���� �������ã���Ӧ�ṹ����: IMOS_MW_DRIVEWAY_CFG_S */
#define IMOS_MW_SUBDEVICE_SWITCH_CFG        69         /**< ��ȡ/���� ���迪�����ã���Ӧ�ṹ����: IMOS_MW_SUBDEVICE_SWITCH_CFG_S */
#define IMOS_MW_LASER_CFG                   70         /**< ��ȡ/���� �������ã���Ӧ�ṹ����: IMOS_MW_LASER_CFG_S */
#define IMOS_MW_CAPTURE_FORMAT_CFG          71         /**< ��ȡ/���� ץ��ͼƬ�������ã���Ӧ�ṹ����: IMOS_MW_CAPTURE_FORMAT_CFG_S */
#define IMOS_MW_POLARIZER_CFG               72         /**< ��ȡ/���� ƫ�����ã���Ӧ�ṹ����: IMOS_MW_POLARIZER_CFG_S */
#define IMOS_MW_ND_FILTER_CFG               73         /**< ��ȡ/���� ND�˾����ã���Ӧ�ṹ����: IMOS_MW_ND_FILTER_CFG_S */

/* �羯���: ��ƵԴ���á��������á�Υ������ */
#define IMOS_MW_CAMERA_BASIC_CFG            101        /**< ��ȡ/���� �������������, ��Ӧ�ṹ����: IMOS_MW_CAMERA_BASIC_CFG_S */ 
#define IMOS_MW_EP_VIDEODETECT_CFG          102        /**< ��ȡ/���� ��Ƶ������ã���Ӧ�ṹ����: IMOS_MW_EP_VIDEODETECT_CFG_S */
#define IMOS_MW_EP_DRIVEWAY_CFG             103        /**< ��ȡ/���� �������ã���Ӧ�ṹ����: IMOS_MW_EP_DRIVEWAY_CFG_S */
#define IMOS_MW_DETECTAREA_CFG              104        /**< ��ȡ/���� �����������, ��Ӧ�ṹ����: IMOS_MW_DETECTAREA_CFG_S */ 
#define IMOS_MW_TRIGGERLINE_CFG             105        /**< ��ȡ/���� ����������, ��Ӧ�ṹ����: IMOS_MW_TRIGGERLINE_CFG_S */ 
#define IMOS_MW_DRIVEWAYLINE_CFG            106        /**< ��ȡ/���� ����������, ��Ӧ�ṹ����: IMOS_MW_DRIVEWAYLINE_CFG_S */
#define IMOS_MW_TRAFFICLIGHT_CFG            107        /**< ��ȡ/���� ���̵�����, ��Ӧ�ṹ����: IMOS_MW_TRAFFICLIGHT_CFG_S */ 
#define IMOS_MW_VEHICLETRACK_CFG            108        /**< ��ȡ/���� ������������, ��Ӧ�ṹ����: IMOS_MW_VEHICLETRACK_CFG_S */
#define IMOS_MW_TOLLGATE_CFG                109        /**< ��ȡ/���� ����ץ������, ��Ӧ�ṹ����: IMOS_MW_TOLLGATE_CFG_S */
#define IMOS_MW_PECCANCY_CAPTURE_CFG        110        /**< ��ȡ/���� Υ��ץ������, ��Ӧ�ṹ����: IMOS_MW_PECCANCY_CAPTURE_CFG_S */
#define IMOS_MW_CAPTURE_IMGPROC_CFG         111        /**< ��ȡ/���� Υ��ץ��ͼƬ��������, ��Ӧ�ṹ����: IMOS_MW_CAPTURE_IMGPROC_CFG_S */
#define IMOS_MW_TRAFFICLIGHT_INTENSIFY_CFG  112        /**< ��ȡ/���� ���̵Ƽ�ǿ����, ��Ӧ�ṹ����: IMOS_MW_TRAFFICLIGHT_INTENSIFY_S */

/* �洢���: �洢���� */
#define IMOS_MW_LOCAL_STOR_INFO             150         /**< ��ȡ/���� ���ش洢��Ϣ����Ӧ�ṹ����: IMOS_MW_LOCAL_STOR_INFO_S */
#define IMOS_MW_STOR_NAS_CFG                151         /**< ��ȡ/���� �洢������Ϣ���μ���IMOS_MW_NAS_STOR_CFG_S */      

/* ���������:�������� */
#define IMOS_MW_IVA_ENABLE                  300       /**< ��ȡ/���� ����ҵ��ʹ�ܱ�־����Ӧ�ṹ����: BOOL_T */
#define IMOS_MW_IVA_MODE_CFG                301       /**< ��ȡ/���� ����ҵ��ģʽ���ã���Ӧ�ṹ����: ULONG */
#define IMOS_MW_IVA_SCENE_CFG               302       /**< ��ȡ/���� ���ܳ�����Ϣ����Ӧ�ṹ����: IMOS_MW_IVA_SCENE_S */
#define IMOS_MW_IVA_RULE_CFG                303       /**< ��ȡ/���� ���ܹ�����Ϣ����Ӧ�ṹ����: IMOS_MW_IVA_RULE_S */
#define IMOS_MW_IVA_ILLEGAL_CFG             304       /**< ��ȡ/���� ����Υ�����ã���Ӧ�ṹ����: IMOS_MW_IVA_ILLEGAL_CFG_S */
#define IMOS_MW_IVA_SCENE_CRUISE_PLAN       305       /**< ��ȡ/���� ���ܳ���Ѳ���ƻ�����Ӧ�ṹ����: IMOS_MW_IVA_SCENE_CRUISE_PLAN_S */
#define IMOS_MW_IVA_LP_CHECK_CFG            306       /**< ��ȡ/���� ����һ���Լ��ʹ�ܱ�־����Ӧ�ṹ����: IMOS_MW_IVA_LP_CHECK_S */
#define IMOS_MW_IVA_CHECK_REPEAT            307       /**< ��ȡ/���� �ظ����ƹ���ʱ�䣬��Ӧ�ṹ�嶨��: ULONG */
 
/* ��������(�����û�����) */
#define IMOS_MW_DEBUG_CFG                   500       /**< ��ȡ/���� �������ã���Ӧ�ṹ����: IMOS_MW_DEBUG_CFG_S*/
#define IMOS_MW_LOW_DELAY_CFG               501       /**< ��ȡ/���� ����ʱģʽ��������Ӧ�ṹ����: ULONG */
#define IMOS_MW_AUTO_TRACK_CFG              502       /**< ��ȡ/���� �Զ��������ã�����͸�����豸����ע������ */
#define IMOS_MW_DEBUG_SERAIL                503       /**< ��ȡ/���� ���ڵ������ã���Ӧ�ṹ����: IMOS_MW_TRANSPORT_CFG_S */
#define IMOS_MW_SANSUO_CHECK_CFG            504       /**< ��ȡ/���� �����ͼ����ã���Ӧ�ṹ����: ULONG */
#define IMOS_MW_SCENE_CFG                   25        /**< ��ȡ/���� �����������ã���Ӧ��ṹ����: IMOS_MW_SCENE_CFG_S */
#define IMOS_MW_HCM_LOW_DELAY_CFG           505       /**< ��ȡ/���� ��о����ʱģʽ��������Ӧ�ṹ����: ULONG */
#define IMOS_MW_DRIVEWAY_EXPAND_CFG         506       /**< ��ȡ/���� ������չ���ã���Ӧ�ṹ����: IMOS_MW_DRIVEWAY_EXPAND_CFG_S */

#define IMOS_MW_RELEASE_STRATEGY_CFG        600       /**< ��ȡ/���� �ڰ��������в��ԣ���Ӧ�ṹ����: IMOS_MW_RELEASE_STRATEGY_CFG_S */
#define IMOS_MW_WHITE_LIST_CFG              601       /**< ��ȡ/���� ����ڰ��������ã���Ӧ�ṹ����: IMOS_MW_GATE_WHITE_LIST_CFG_S */
#define IMOS_MW_BLACK_LIST_CFG              602       /**< ��ȡ/���� ����ں��������ã����ýṹ����: IMOS_MW_GATE_BLACK_LIST_CFG_S*/

#if 0
#endif
/*************************************** �豸ά����� ********************************************/
/*@brief ͨ��CODE����*/
#define IMOS_MW_CODE_LEN                    48   

/*@brief ͨ�������ַ������� */
#define IMOS_MW_NAME_LEN                    64     

/*@brief �ļ������ַ������� */
#define IMOS_MW_FILE_NAME_LEN               IMOS_MW_NAME_LEN    

/*@brief ��Դ������Ϣ�ַ������� */
#define IMOS_MW_RES_CODE_LEN                IMOS_MW_CODE_LEN

/*@brief ϵͳĬ��·������ */
#define IMOS_MW_DEFAULT_PATH_LEN            256

/*@brief SDK �ͻ��˰汾�ų��� */
#define IMOS_MW_SDK_CLIENT_VERSION_LEN      32

/*@brief IP��ַ��Ϣ�ַ������� 
  * IPV4: "192.168.0.102"
  * IPV6: "A1:0:8:100:200:0:0:321A"
  * ����: "AS_server_hangzhou" */
#define IMOS_MW_IPADDR_LEN                  64  

/*@brief ע��VMʱ�豸ID ����  */
#define IMOS_MW_DEVICE_ID_LEN               48
/*@brief ע�������������� ����  */
#define IMOS_MW_MANAGE_SERVER_PASSWD_LEN    16

/*@brief SNMP ����������  */
#define IMOS_MW_COMMUNITY_LEN               32


/*@brief ʱ�� ��ʽ */
#define IMOS_MW_TIME_FORMAT_HHMMSS          0        /**< XX:XX:XX �������й���������Ӣ����*/
#define IMOS_MW_TIME_FORMAT_HHMMSS_PM       1        /**< XX:XX:XX p.m. �����ڳ�����������������������*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS_PM     2        /**< XX:XX:XX PM �����ڳ�Ӣ�������Ӣ�����*/
#define IMOS_MW_TIME_FORMAT_PM_HHMMSS       3        /**< PM XX:XX:XX ����������(�¼���)*/
#define IMOS_MW_TIME_FORMAT_HH_MM_SS        4        /**< ���� XX:XX:XX ����������(̨��)*/

/*@brief ���� ��ʽ */
#define IMOS_MW_DATE_FORMAT_YYYYMMDD        0        /**< XXXX-XX-XX ������ */
#define IMOS_MW_DATE_FORMAT_MMDDYYYY        1        /**< XX-XX-XXXX ������ */
#define IMOS_MW_DATE_FORMAT_YYYY_MM_DD      2        /**< XXXX��XX��XX�� */
#define IMOS_MW_DATE_FORMAT_MM_DD_YYYY      3        /**< XX��XX��XXXX�� */
#define IMOS_MW_DATE_FORMAT_YYYY_MM_DD_XX   4        /**< XXXX��XX��XX�� ����X */

/*@brief �汾��Ϣ���� */
#define IMOS_MW_VERSION_LEN                 256 

/*@brief �û�����󳤶� */
#define IMOS_MW_USER_NAME_LEN               32   

/*@brief �û�������󳤶� */
#define IMOS_MW_USER_PASSWORD_LEN           32  

/**@brief �û����� */
#define IMOS_MW_USERLEVEL_ADMINISTRATOR     0        /**< ����Ա */
#define IMOS_MW_USERLEVEL_OPERATOR          1        /**< ����Ա */
#define IMOS_MW_USERLEVEL_USER              2        /**< ��ͨ�û� */
#define IMOS_MW_USERLEVEL_ANONYMOUS         3        /**< �����û� */
#define IMOS_MW_USERLEVEL_EXTENDED          4        /**< ��չ�û� */

/**@brief �豸�������� */
#define IMOS_MW_CAP_FUNC                    0        /**< ҵ������ */
#define IMOS_MW_CAP_IMAGE                   1        /**< ͼ������ */
#define IMOS_MW_CAP_HARDWARE                2        /**< Ӳ������ */
#define IMOS_MW_CAP_ENCODE                  3        /**< �������� */
#define IMOS_MW_CAP_NETWORK                 4        /**< �������� */
#define IMOS_MW_CAP_OSD                     5        /**< OSD���� */
#define IMOS_MW_CAP_INTELLIGENT             6        /**< �������� */
#define IMOS_MW_CAP_SERIAL                  7        /**< �������� */

/**@brief �������� */
#define IMOS_MW_PARAM_TYPE_OPTICS_VIDEO     0        /**< ��Ƶ��ͼ����� */
#define IMOS_MW_PARAM_TYPE_OPTICS_PICTURE   1        /**< ��Ƭ��ͼ����� */
#define IMOS_MW_PARAM_TYPE_PECCANCY         2        /**< Υ��Ĭ�ϲ��� */

/**@brief ��־���� */
#define IMOS_SDK_LOG_CLOSE                  0        /**< �ر���־ */
#define IMOS_SDK_LOG_DEBUG                  1        /**< debug���� */
#define IMOS_SDK_LOG_INFO                   2        /**< info���� */
#define IMOS_SDK_LOG_WARN                   3        /**< warn���� */
#define IMOS_SDK_LOG_ERROR                  4        /**< error���� */
#define IMOS_SDK_LOG_FATAL                  5        /**< fatal���� */

/**@brief �ƻ�״̬ */
#define IMOS_MW_PLAN_TYPE_MOVE_DETECT       0        /**< �˶����ƻ� */
#define IMOS_MW_PLAN_TYPE_INPUT_SWITCH      1        /**< ����������ƻ� */
#define IMOS_MW_PLAN_TYPE_CRUISE            2        /**< Ѳ���ƻ� */
#define IMOS_MW_PLAN_TYPE_STOR              3        /**< �洢�ƻ� */
#define IMOS_MW_PLAN_TYPE_SCENE_SWITCH      4        /**< �����л� */
#define IMOS_MW_PLAN_TYPE_AUDIO_DETECT      5        /**< �������ƻ� */
#define IMOS_MW_PLAN_TYPE_TAMPER_DETECT     6        /**< �ڵ����ƻ� */

#if 0
#endif
/**************************************** ������� ***************************************/
/**@brief �������� */
#define IMOS_MW_SERIAL_TYPE_RS232                    1             /**< rs232 */
#define IMOS_MW_SERIAL_TYPE_RS422                    2             /**< rs422 */
#define IMOS_MW_SERIAL_TYPE_RS485                    3             /**< rs485 */

/**@brief ����ģʽ */
#define IMOS_MW_SERIAL_MODE_PTZ                      1             /**< ��̨���� */
#define IMOS_MW_SERIAL_MODE_TRANS                    2             /**< ͸��ͨ�� */
#define IMOS_MW_SERIAL_MODE_CONSOLE                  3             /**< ����̨ */
#define IMOS_MW_SERIAL_MODE_COMMON                   4             /**< ͨ�ô��� */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_H       5             /**< ������ H, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_S       6             /**< ������ S, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_RADAR_C                  7             /**< �״� C, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_LASER                    8             /**< ����, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_CASEALARM                9             /**< ����澯 */  
#define IMOS_MW_SERIAL_MODE_TRAFFICLIGHT_S           10            /**< ����źż���� S */  
#define IMOS_MW_SERIAL_MODE_RADAR_A                  11            /**< �״� A, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_OSD                      12            /**< OSD���� */
#define IMOS_MW_SERIAL_MODE_RADAR_H                  13            /**< �״� H, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_Q       14            /**< ������ Q, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_RADAR_C_CONTROLLER       15            /**< �״� C������, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_LOCAL_PTZ_CTRL           16            /**< ������̨���� */
#define IMOS_MW_SERIAL_MODE_RFID                     17            /**< RFID, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_VEHICLE_DETECTOR_U       18            /**< ������ U, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_TRAFFICLIGHT_U           19            /**< ����źż���� U */
#define IMOS_MW_SERIAL_MODE_RADAR_W                  20            /**< �״� W, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_MODE_RADAR_Z                  21            /**< �״� Z, ʹ��ģʽ�μ�: IMOS_MW_SUBDEVICE_XXX */
#define IMOS_MW_SERIAL_SWITCHVALUE_TO_485            22            /**< ���迪����ת485 */
#define IMOS_MW_SERIAL_MODE_COUNT                    22            /**< ����ģʽ������ */ 

/*************************************** ������� ********************************************/
/*@brief PPPoE�û�������  */
#define IMOS_MW_PPPOE_USERNAME_LEN               32  

/*@brief PPPoE���볤�� */
#define IMOS_MW_PPPOE_PASSWORD_LEN               32

/*@brief UNP�û�������  */
#define IMOS_MW_UNP_USERNAME_LEN                 32  

/*@brief UNP���볤�� */
#define IMOS_MW_UNP_PASSWORD_LEN                 32

/*@brief WIFI SSID���� */
#define IMOS_MW_WIFI_SSID_LEN                    44

/*@brief WIFI KEY���� */
#define IMOS_MW_WIFI_KEY_LEN                     44

/* һ��ɨ�����֧�ֵ������������ */
#define IMOS_MW_WIFI_NETWORK_MAX_COUNT           40


/**@brief IP��ȡ��ʽ */
#define IMOS_MW_IP_GET_TYPE_STATIC               0        /**< ��̬��ȡ */
#define IMOS_MW_IP_GET_TYPE_PPPOE                1        /**< pppoe���� */
#define IMOS_MW_IP_GET_TYPE_DHCP                 2        /**< DHCP���� */

/**@brief �������� */
#define IMOS_MW_PORT_MODE_ELECTRONIC             0        /**< ��� */
#define IMOS_MW_PORT_MODE_FIBER                  1        /**< ��� */
#define IMOS_MW_PORT_MODE_EPON                   2        /**< EPON */
#define IMOS_MW_PORT_MODE_LRE                    3        /**< LRE��� */

/**@brief ���ڹ���ģʽ */
#define IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION    0    /**< ��Э�� */
#define IMOS_MW_ETH_WORKMODE_10M_FULL            1    /**< 10M FULL */
#define IMOS_MW_ETH_WORKMODE_10M_HALF            2    /**< 10M HALF */
#define IMOS_MW_ETH_WORKMODE_100M_FULL           3    /**< 100M FULL */
#define IMOS_MW_ETH_WORKMODE_100M_HALF           4    /**< 100M HALF */
#define IMOS_MW_ETH_WORKMODE_1000M_FULL          5    /**< 1000M FULL */

/**@brief WiFi��֤��ʽ */
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

/**@brief WiFi���ܷ�ʽ */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_NONE          0   /**< NONE */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_WEP           1   /**< WEP */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_TKIP          2   /**< TKIP */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_AES           3   /**< AES */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_TKIPAES       4   /**< TKIPAES */
#define  IMOS_MW_WIFI_ENCRYPT_TYPE_UNKNOW        5   /**< UNKNOW */

/**@brief WiFi����ģʽ */
#define IMOS_MW_WIFI_NETWORK_TYPE_INFRA          0    /**< InfraStructure */
#define IMOS_MW_WIFI_NETWORK_TYPE_ADHOC          1    /**< AdHoc */

/**@brief WiFi����ģʽ */
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
/*************************************** ͼ����� ********************************************/
/**@brief ͼ������ */
#define IMOS_MW_IMAGE_TYPE_VIDEO                0       /**< ��Ƶͼ�� */
#define IMOS_MW_IMAGE_TYPE_CAPTURE              1       /**< ץ��ͼ�� */
#define IMOS_MW_IMAGE_TYPE_COUNT                2       /**< ͼ�����͸��� */

/**@brief ��ƽ��ģʽ */
#define IMOS_MW_WB_AUTO                         0       /**< �Զ���ƽ�� */
#define IMOS_MW_WB_FINETUNE                     1       /**< ΢����ƽ�� */
#define IMOS_MW_WB_INDOOR                       2       /**< ���ڰ�ƽ�� */
#define IMOS_MW_WB_OUTDOOR                      3       /**< �����ƽ�� */
#define IMOS_MW_WB_AUTO_MERCURY                 4       /**< �Զ�ˮ���ư�ƽ�� */ 
#define IMOS_MW_WB_FINETUNE_NIGHT               5       /**< ҹ��΢����ƽ��  */

/**@brief �Խ�ģʽ */
#define IMOS_MW_FOCUS_AUTO                      0       /**< �Զ��Խ� */
#define IMOS_MW_FOCUS_MANUAL                    1       /**< �ֶ��Խ� */
#define IMOS_MW_FOCUS_PUSH                      2       /**< һ���Խ� */
#define IMOS_MW_FOCUS_PUSH_NIGHTINFRARED        3       /**< һ���Խ�(ҹ�����) */

/**@brief ����ֵ��λ */
#define IMOS_MW_SHUTTER_UNIT_MICSEC             0       /**< ΢�� */
#define IMOS_MW_SHUTTER_UNIT_DENOMINATOR        1       /**< ��ĸ��ʾ������λ: 1/�� */

/**@brief �ع�ģʽ */
#define IMOS_MW_EXPOSURE_AUTO                   0       /**< �Զ��ع� */
#define IMOS_MW_EXPOSURE_CUSTOM                 1       /**< �Զ����ع� */
#define IMOS_MW_EXPOSURE_SHUTTER                2       /**< �������� */
#define IMOS_MW_EXPOSURE_IRIS                   3       /**< ��Ȧ���� */
#define IMOS_MW_EXPOSURE_GAIN                   4       /**< �������� */
#define IMOS_MW_EXPOSURE_INDOOR_50HZ            5       /**< ����50HZ */
#define IMOS_MW_EXPOSURE_INDOOR_60HZ            6       /**< ����60HZ */
#define IMOS_MW_EXPOSURE_MANUAL                 7       /**< �ֶ��ع� */

/**@brief ��̬ģʽ */
#define IMOS_MW_WDR_DISABLE                     0       /**< �ر� */
#define IMOS_MW_WDR_ENABLE                      1       /**< ���� */
#define IMOS_MW_WDR_AUTO                        2       /**< �Զ� */

/**@brief ���ģʽ */
#define IMOS_MW_METERING_CENTER                 0       /**< ����Ȩ�� */
#define IMOS_MW_METERING_AREA                   1       /**< ������Ȩ�� */
#define IMOS_MW_METERING_HME                    2       /**< ǿ������ */
#define IMOS_MW_METERING_VEHICLE                3       /**< ������� */

/**@brief ��ҹģʽ */
#define IMOS_MW_DAYNIGHT_AUTO                   0       /**< �Զ�ģʽ */
#define IMOS_MW_DAYNIGHT_COLOR                  1       /**< ��ɫ */
#define IMOS_MW_DAYNIGHT_BW                     2       /**< �ڰ� */

/**@brief ���ģʽ */
#define IMOS_MW_SHARPNESS_AUTO                  0       /**< �Զ�ģʽ */
#define IMOS_MW_SHARPNESS_MANUAL                1       /**< �ֶ�ģʽ */

/**@brief ����ģʽ */
#define IMOS_MW_MIRROR_MODE_NONE                0       /**< ����ģʽ */
#define IMOS_MW_MIRROR_MODE_FLIP                1       /**< ��ֱ��ת */
#define IMOS_MW_MIRROR_MODE_MIRROR              2       /**< ˮƽ��ת */
#define IMOS_MW_MIRROR_MODE_FLIP_MIRROR         3       /**< ��ֱˮƽͬʱ��ת */
#define IMOS_MW_MIRROR_MODE_ROTATE_CLOCKWISE    4       /**< ˳ʱ����ת90�� */

/**@brief �������ģʽ */
#define IMOS_MW_IR_CTRL_OVERALL                 0       /**< ȫ�ּ���Զ����� */
#define IMOS_MW_IR_CTRL_EXTREME                 1       /**< ���������Զ����� */
#define IMOS_MW_IR_CTRL_PRESET                  2       /**< IrԤ�ÿ���-��·ģʽ */
#define IMOS_MW_IR_CTRL_MANUAL                  3       /**< Ir�ֶ����� */
#define IMOS_MW_IR_CTRL_PRESET_YARD             4       /**< IrԤ�ÿ���-԰��ģʽ */

/**@brief ��չ�������������� */
#define IMOS_MW_CONDITION_MAX_NUM               4       

/**@brief ������������ */
#define IMOS_MW_CONDITION_ILLUMINATION          0       /**< �����ն� */
#define IMOS_MW_CONDITION_TILT_ANGLE            1       /**< ��̨��б�Ƕ� */

/**@brief ������������ */
#define IMOS_MW_IPC_SCENE_TYPE_CUSTOM              0     /* �Զ��� */
#define IMOS_MW_IPC_SCENE_TYPE_INDOOR              1     /* ���� */
#define IMOS_MW_IPC_SCENE_TYPE_COMMON              2     /* ͨ�� */
#define IMOS_MW_IPC_SCENE_TYPE_PLATE               3     /* ���� */
#define IMOS_MW_IPC_SCENE_TYPE_STARLIGHT           4     /* �ǹ� */
#define IMOS_MW_IPC_SCENE_TYPE_OBJECTIVE           5     /* �͹� */
#define IMOS_MW_IPC_SCENE_TYPE_HIGHSENSITIVE       6     /* �߸й� */  
#define IMOS_MW_IPC_SCENE_TYPE_LIGHTINHIBITION     7     /* ǿ������ */  

/**@brief ������������(����) */
#define IMOS_MW_HTS_SCENE_TYPE_NORMAL               50     /* ��ͨ */
#define IMOS_MW_HTS_SCENE_TYPE_WEAKBACKLIGHTING     51     /* ����� */
#define IMOS_MW_HTS_SCENE_TYPE_INTENSEBACKLIGHTING  52     /* ǿ��� */
#define IMOS_MW_HTS_SCENE_TYPE_WEAKFRONTLIGHTING    53     /* ��˳�� */
#define IMOS_MW_HTS_SCENE_TYPE_INTENSEFRONTLIGHTING 54     /* ǿ˳�� */
#define IMOS_MW_HTS_SCENE_TYPE_OBJECTIVE            55     /* �͹� */

/**@brief ����ģʽ */
#define IMOS_MW_LIGHT_MODE_NONE                    0     /**< �޲���� */
#define IMOS_MW_LIGHT_MODE_WHITE                   1     /**< �׹��ģʽ */
#define IMOS_MW_LIGHT_MODE_IR                      2     /**< �����ģʽ */            

#if 0
#endif
/*************************************** OSD��� ********************************************/
/*@brief OSD �������ݵĳ��� */
#define IMOS_MW_OSD_INFO_LEN                      60    

/*@brief ���� OSD ������ */
#define IMOS_MW_INFO_OSD_MAX_NUM                  3   

/*@brief OSD ��������������� */
#define IMOS_MW_INFO_OSD_LINE_MAX                 8

/*@brief �ڸ� OSD ������ */
#define IMOS_MW_COVER_OSD_MAX_NUM                 8 

/*@brief ������������ */
#define IMOS_MW_OSD_INFO_TYPE_UNUSED              0    /* ��ʹ�� */
#define IMOS_MW_OSD_INFO_TYPE_USERDEF             1    /* �Զ��� */
#define IMOS_MW_OSD_INFO_TYPE_DATETIME            2    /* ʱ������ */
#define IMOS_MW_OSD_INFO_TYPE_PTZOPER             3    /* ��̨������ */
#define IMOS_MW_OSD_INFO_TYPE_PTZCOORDINATS       4    /* ��̨���� */
#define IMOS_MW_OSD_INFO_TYPE_CRUISEINFO          5    /* Ѳ����Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_ZOOMINFO            6    /* �䱶��Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_PRESETINFO          7    /* Ԥ��λ��Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_ALARMINFO           8    /* ������Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_ENCODEINFO          9    /* ������Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_SERIALMSG           10   /* ������Ϣ */
#define IMOS_MW_OSD_INFO_TYPE_PTZDIRECTION        11   /* ��̨��λ��Ϣ */   

/*@brief ���� OSD ���� */
#define IMOS_MW_OSD_PIC_TIME                      0     /**< ץ����Ƭ ʱ��OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_SPEED             1     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_PIC_LIMITED_SPEED             2     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_PIC_PECCANCY_TYPE             3     /**< ץ����Ƭ Υ������OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_COLOR             4     /**< ץ����Ƭ ������ɫOSD */
#define IMOS_MW_OSD_PIC_VEHICLE_LOGO              5     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_TYPE              6     /**< ץ����Ƭ ����OSD */
#define IMOS_MW_OSD_PIC_DRIVINGTYPE               7     /**< ץ����Ƭ ������ʻ����OSD */
#define IMOS_MW_OSD_PIC_VEHICLE_PLATE             8     /**< ץ����Ƭ ����(����������ɫ) */
#define IMOS_MW_OSD_PIC_VEHICLE_WAYID             9     /**< ץ����Ƭ ������ */
#define IMOS_MW_OSD_PIC_VEHICLE_CAMERAID          10    /**< ץ����Ƭ �����ID */
#define IMOS_MW_OSD_PIC_VEHICLE_DIRECTION         11    /**< ץ����Ƭ ���� */
#define IMOS_MW_OSD_PIC_VEHICLE_CAP_DIRECTION     12    /**< ץ����Ƭ ץ�ķ��� */
#define IMOS_MW_OSD_PIC_VEHICLE_VERIFY            13    /**< ץ����Ƭ ��α�� */
#define IMOS_MW_OSD_PIC_VEHICLE_NAME              14    /**< ץ����Ƭ ���������� */
#define IMOS_MW_OSD_PIC_VEHICLE_SPEED_PERCENT     15    /**< ץ����Ƭ ���ٰٷֱ�OSD */ 
#define IMOS_MW_OSD_MJPEG_VEHICLE_CAP_DIRECTION   16    /**< MJPEG ��ʻ���� */ 
#define IMOS_MW_OSD_MJPEG_VEHICLE_ROAD_MESSAGE    17    /**< MJPEG ·����Ϣ */
#define IMOS_MW_OSD_MJPEG_VEHICLE_TIME            18    /**< MJPEG ʱ�� */
#define IMOS_MW_OSD_PIC_TIME_MILISEC              19    /**< ץ����Ƭ ����ʱ��OSD > */
#define IMOS_MW_OSD_MLPEG_VEHICLE_TIME_MILISEC    20    /**< MJPEGʱ�� ����ʱ��OSD > */
#define IMOS_MW_OSD_TYPE_BUTT                     21    /**< ֧�ֵ�ץ��OSD���� */

/*@brief OSD ������ʽ */
#define IMOS_MW_OSD_FONT_STYLE_BACKGROUND         0    /**< ���� */
#define IMOS_MW_OSD_FONT_STYLE_STROKES            1    /**< ��� */ 
#define IMOS_MW_OSD_FONT_STYLE_HOLLOW             2    /**< ���� */
#define IMOS_MW_OSD_FONT_STYLE_NORMAL             3    /**< ���� */

/*@brief OSD ���� */
#define IMOS_MW_OSD_FONT_TYPE_ADVANCE             0    /**< ��ǿ(Ĭ��) */
#define IMOS_MW_OSD_FONT_TYPE_STANDARD            1    /**< ��׼ */

/*@brief OSD ���� */
#define IMOS_MW_OSD_FONT_ALIGN_LEFT              0   /**< ����� */
#define IMOS_MW_OSD_FONT_ALIGN_RIGHT             1   /**< �Ҷ��� */

/*@brief OSD �����С */
#define IMOS_MW_OSD_FONT_SIZE_LARGE               0    /**< �� */
#define IMOS_MW_OSD_FONT_SIZE_MIDDLE              1    /**< �� */
#define IMOS_MW_OSD_FONT_SIZE_SMALL               2    /**< С */

/*@brief OSD ��ɫ */
#define IMOS_MW_OSD_COLOR_WHITE                   0    /**< �� */
#define IMOS_MW_OSD_COLOR_RED                     1    /**< �� */
#define IMOS_MW_OSD_COLOR_YELLOW                  2    /**< �� */
#define IMOS_MW_OSD_COLOR_BLUE                    3    /**< �� */
#define IMOS_MW_OSD_COLOR_BLACK                   4    /**< �� */
#define IMOS_MW_OSD_COLOR_GREEN                   5    /**< �� */
#define IMOS_MW_OSD_COLOR_PURPLE                  6    /**< �� */

/*@brief OSD ͸���� */
#define IMOS_MW_OSD_ALPHA_NO                      0    /**< ��͸�� */
#define IMOS_MW_OSD_ALPHA_SEMI                    1    /**< ��͸�� */
#define IMOS_MW_OSD_ALPHA_ALL                     2    /**< ȫ͸�� */

#define IMOS_MW_COM_OSD_MAX_LEN 644

#if 0
#endif
/*************************************** ý������� ********************************************/
/**@brief ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_RTP_UDP           0        /**< UDP��RTP ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_RTP_TCP           1        /**< TCP��RTP ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW1_TCP      2        /**< TCP��Uniview1 ����ģʽ */        
#define IMOS_MW_TRANSFER_MODE_TS_TCP            3        /**< TCP��TS ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_TS_UDP            4        /**< UDP��TS ����ģʽ */
#define IMOS_MW_TRANSFER_MODE_HTTP              5        /**< ����RTP/RTSP/HTTP/TCP���ط�ʽ */
#define IMOS_MW_TRANSFER_MODE_UNIVIEW2_TCP      6        /**< TCP��Uniview2 ����ģʽ */  
#define IMOS_MW_TRANSFER_MODE_LOCAL_IMAGE       7        /**< ������Ƭ���� ����ģʽ */  
#define IMOS_MW_TRANSFER_MODE_EZR_TMS           8        /**< TCP��Uniview2 ����ģʽ EZRʹ�� */
#define IMOS_MW_TRANSFER_MODE_TMS_IMAGE         9        /**< TMS��Ƭģʽ ����ģʽ */



/**@brief ��ID */
#define IMOS_MW_STREAM_ID_MAIN                  0        /**< ���� */
#define IMOS_MW_STREAM_ID_AUX                   1        /**< ���� */
#define IMOS_MW_STREAM_ID_THIRD                 2        /**< ���� */
#define IMOS_MW_STREAM_ID_FOUTH                 3        /**< ���� */

/**@brief ý�������� */
#define IMOS_MW_MEDIA_VIDEO                     0       /**< ʵ���� */
#define IMOS_MW_MEDIA_VOICE_TALK                1       /**< �����Խ� */
#define IMOS_MW_MEDIA_VOICE_BROADCAST           2       /**< �����㲥 */

/**@brief �������� */
#define IMOS_MW_STREAM_TYPE_TS                  0       /**<  TS  */
#define IMOS_MW_STREAM_TYPE_H3C_ES              1       /**<  H3C ES RTP  */
#define IMOS_MW_STREAM_TYPE_PS                  2       /**<  PS  */
#define IMOS_MW_STREAM_TYPE_UNIVIEW             6       /**< ���ӿ��ڵ羯Э�� */

/**@brief ��������ģʽ */
#define IMOS_MW_CONNECT_TYPE_UDP                0       /**<  UDP  */
#define IMOS_MW_CONNECT_TYPE_TCP                1       /**<  TCP  */
#define IMOS_MW_CONNECT_TYPE_RTP                2       /**<  RTP  */
#define IMOS_MW_CONNECT_TYPE_RTP_NO_RTCP        3       /**< RTP no rtcp*/
#define IMOS_MW_CONNECT_TYPE_AUTO               4       /**< ����Ӧ */
#define IMOS_MW_CONNECT_TYPE_HTTP               5       /**< RTP/RTSP/HTTP/TCP ���ط�ʽ */

/**@brief GOPģʽ */
#define IMOS_MW_GOP_TYPE_IP                     0       /**< IP */
#define IMOS_MW_GOP_TYPE_IBP                    1       /**< IBP */
#define IMOS_MW_GOP_TYPE_IBBP                   2       /**< IBBP */
#define IMOS_MW_GOP_TYPE_I                      3       /**< I */

/**@brief ����ģʽ */
#define IMOS_MW_ENCODE_MODE_CBR                 0       /**< CBR��ʽ */
#define IMOS_MW_ENCODE_MODE_VBR                 1       /**< VBR��ʽ */

/**@brief ��Ƶ�����ʽ */
#define IMOS_MW_STREAM_FORMAT_MPEG1             0       /**< MPEG1 */
#define IMOS_MW_STREAM_FORMAT_MPEG2             1       /**< MPEG2 */
#define IMOS_MW_STREAM_FORMAT_MPEG4             2       /**< MPEG4 */
#define IMOS_MW_STREAM_FORMAT_MJPEG             3       /**< MJPEG */
#define IMOS_MW_STREAM_FORMAT_H263              4       /**< H263 */
#define IMOS_MW_STREAM_FORMAT_H263PLUS          5       /**< H263+ */
#define IMOS_MW_STREAM_FORMAT_H264              6       /**< H.264 */
#define IMOS_MW_STREAM_FORMAT_AUTO              7       /**< ����Ӧ(����) */
#define IMOS_MW_STREAM_FORMAT_MPEG4_DS          8       /**< MPEG4-ds */
#define IMOS_MW_STREAM_FORMAT_MPEG2_DS          9       /**< MPEG2-ds */ 
#define IMOS_MW_STREAM_FORMAT_MPEG4_2           10      /**< MPEG4 ���� */    
#define IMOS_MW_STREAM_FORMAT_H264_2            11      /**< H264 ���� */   
#define IMOS_MW_STREAM_FORMAT_JPEG              12      /**< JPEG */ 

/**@brief ��Ƶ�����ʽ */
#define IMOS_MW_AUDIO_ENCODE_MPEG1_LAYER2       0       /**< MPEG1_LAYER2 */
#define IMOS_MW_AUDIO_ENCODE_G711A              1       /**< G.711A */
#define IMOS_MW_AUDIO_ENCODE_G711U              2       /**< G.711U */
#define IMOS_MW_AUDIO_ENCODE_ADPCM              3       /**< ADPCM */
#define IMOS_MW_AUDIO_ENCODE_OGG                4       /**< OGG */
#define IMOS_MW_AUDIO_ENCODE_AUTO               5       /**< �Զ� */
#define IMOS_MW_AUDIO_ENCODE_AAC                6       /**< AAC */

/**@brief ������� */
#define IMOS_MW_AUDIO_VOLUME_REDUCE_8           1 
#define IMOS_MW_AUDIO_VOLUME_REDUCE_4           2
#define IMOS_MW_AUDIO_VOLUME_REDUCE_2           3
#define IMOS_MW_AUDIO_VOLUME_ZOOM_1             4
#define IMOS_MW_AUDIO_VOLUME_ZOOM_2             5
#define IMOS_MW_AUDIO_VOLUME_ZOOM_4             6
#define IMOS_MW_AUDIO_VOLUME_ZOOM_8             7

/**@brief ������ */
#define IMOS_MW_AUDIO_SAMPLING_8000             0 
#define IMOS_MW_AUDIO_SAMPLING_16000            1
#define IMOS_MW_AUDIO_SAMPLING_22050            2
#define IMOS_MW_AUDIO_SAMPLING_24000            3
#define IMOS_MW_AUDIO_SAMPLING_32000            4
#define IMOS_MW_AUDIO_SAMPLING_44100            5
#define IMOS_MW_AUDIO_SAMPLING_48000            6
#define IMOS_MW_AUDIO_SAMPLING_96000            7

/**@brief ��Ƶͨ�� */
#define IMOS_MW_AUDIO_CHANNEL_STEREO            0        /**< ������ */
#define IMOS_MW_AUDIO_CHANNEL_L                 1        /**< ������ */
#define IMOS_MW_AUDIO_CHANNEL_R                 2        /**< ������ */
#define IMOS_MW_AUDIO_CHANNEL_MONO              3        /**< ������ */

/**@brief ��Ƶ��������λ�� */
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_8       8
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_16      16
#define IMOS_MW_AUDIO_QUANTIZATION_BITS_32      32

/**@brief ����Э�� */
#define IMOS_MW_PROTOCOL_UDP                    0       /**< UDPЭ�� */
#define IMOS_MW_PROTOCOL_TCP                    1       /**< TCPЭ��*/

#define IMOS_MW_AUTO_SEND_MAX_NUM               4       /**< ��������Զ��������� */


#if 0
#endif
/**************************************** �澯������� ***************************************/
/*@brief �����澯���������������� */ 
#define IMOS_MW_ACT_PARAM_NUM                           5   

/*@brief �˶�������������� */ 
#define IMOS_MW_MOTION_DETECT_AREA_MAX                  4  

/*@brief �����˶��������� */ 
#define IMOS_MW_DETECTED_ACTIVITY_MAX                   60  

/*@brief �ڵ�������������� */ 
#define IMOS_MW_TAMPER_DETECT_AREA_MAX                  1  

/*@brief �����û�֧�ֵ�����ĸ�����ֵ��ȷ��! */ 
#define IMOS_MW_USER_SUBSCRIBE_NUM_MAX                  2

/*@brief ���������������Ч���� */
#define IMOS_MW_SWITCH_NAME_LEN                         60

/*@brief һ������ȡ30֡��������Ϣ */ 
#define IMOS_MW_VOLUME_INFO_FRAME_MAX                   30 

/**@brief �澯���� */
#define IMOS_MW_ALARM_TYPE_SYSTEM                       0x10000        /**< �豸��澯 */
#define IMOS_MW_ALARM_TYPE_STOR                         0x20000        /**< �洢��澯 */ 
#define IMOS_MW_ALARM_TYPE_EVENT                        0x40000        /**< �¼���澯 */
#define IMOS_MW_ALARM_TYPE_BUTT                         0xFFFFFFFF    /**< ��Чֵ���澯����ʱ��ʾͬʱ�����������͵ĸ澯 */

/**@brief �澯�������� */
#define IMOS_MW_ALARM_SYSTEM_HIGH_TEMPERATURE           0x10001        /**< ���¸澯 */
#define IMOS_MW_ALARM_SYSTEM_LOW_TEMPERATURE            0x10002        /**< ���¸澯 */
#define IMOS_MW_ALARM_SYSTEM_TEMPERATURE_RESUME         0x10003        /**< �¶ȸ澯�ָ� */

#define IMOS_MW_ALARM_STOR_FULL_PRE                     0x20010        /**< �洢�������澯 */
#define IMOS_MW_ALARM_STOR_FULL                         0x20011        /**< ���洢�澯 */
#define IMOS_MW_ALARM_STOR_FAILED                       0x20012        /**< �洢��дʧ�ܸ澯 */
#define IMOS_MW_ALARM_STOR_FAILED_RESUME                0x20013        /**< �洢��дʧ�ܸ澯�ָ� */
#define IMOS_MW_ALARM_STOR_USB_FAILED                   0x20014        /**< ǰ�˻���ʧ�ܸ澯 */
#define IMOS_MW_ALARM_STOR_USB_FAILED_RESUME            0x20015        /**< ǰ�˻���ʧ�ܸ澯�ָ� */
#define IMOS_MW_ALARM_STOR_STOPPED                      0x20016        /**< �洢ֹͣ�澯 */
#define IMOS_MW_ALARM_EXT_STOR_FULL_PRE                 0x20017        /**< �ⲿ�洢�������澯 */
#define IMOS_MW_ALARM_EXT_STOR_FULL                     0x20018        /**< �ⲿ�洢���洢�澯 */
#define IMOS_MW_ALARM_EXT_STOR_FAILED                   0x20019        /**< �ⲿ�洢ʧ�ܸ澯 */
#define IMOS_MW_ALARM_EXT_STOR_FAILED_RESUME            0x20020        /**< �ⲿ�洢ʧ�ܸ澯�ָ� */

#define IMOS_MW_ALARM_EVENT_DEVICE_ONLINE               0x40001        /**< �豸���߸澯 */
#define IMOS_MW_ALARM_EVENT_DEVICE_OFFLINE              0x40002        /**< �豸���߸澯 */
#define IMOS_MW_ALARM_EVENT_VIDEO_LOST                  0x40003        /**< ��Ƶ��ʧ�澯 */
#define IMOS_MW_ALARM_EVENT_VIDEO_LOST_RESUME           0x40004        /**< ��Ƶ��ʧ�澯�ָ� */
#define IMOS_MW_ALARM_EVENT_MOVE_DETECT                 0x40005        /**< �˶����澯 */
#define IMOS_MW_ALARM_EVENT_MOVE_DETECT_RESUME          0x40006        /**< �˶����澯�ָ� */
#define IMOS_MW_ALARM_EVENT_MASK_DETECT                 0x40007        /**< �ڵ����澯 */
#define IMOS_MW_ALARM_EVENT_MASK_DETECT_RESUME          0x40008        /**< �ڵ����澯�ָ� */
#define IMOS_MW_ALARM_EVENT_INPUT_SWITCH                0x40009        /**< ���뿪�����澯 */
#define IMOS_MW_ALARM_EVENT_INPUT_SWITCH_RESUME         0x4000A        /**< ���뿪�����澯�ָ� */
#define IMOS_MW_ALARM_EVENT_AUDIO_DETECT                0x4000F        /**< �������澯 */
#define IMOS_MW_ALARM_EVENT_AUDIO_DETECT_RESUME         0x40010        /**< �������澯�ָ� */

/**@brief �澯�������� */
#define IMOS_MW_ACT_CMD_PRESET                          0               /**< ����Ԥ��λ, ��Ӧ����: Ԥ��λID */
#define IMOS_MW_ACT_CMD_OUTSWITCH                       1               /**< �������������, ��Ӧ����: ������ID */
#define IMOS_MW_ACT_CMD_STOR                            2               /**< �����洢, �ݲ�֧�� */
#define IMOS_MW_ACT_CMD_LED                             3               /**< ����ָʾ��, �ݲ�֧�� */
#define IMOS_MW_ACT_CMD_BUZZER                          4               /**< �������������ݲ�֧�� */  
#define IMOS_MW_ACT_CMD_STOR_TO_VM                      5               /**< �������Ĵ洢 */
#define IMOS_MW_ACT_CMD_OSD                             100             /**< ����OSD���ݲ�֧��  */   
#define IMOS_MW_ACT_CMD_CAPTURE                         101             /**< ����ץ��, ����Ҫ���� */  
#define IMOS_MW_ACT_CMD_START_USBSTOR                   102             /**< �����������ش洢 */  
#define IMOS_MW_ACT_CMD_STOP_USBSTOR                    103             /**< ����ֹͣ���ش洢 */  

/**@brief ������ģʽ */
#define IMOS_MW_SWITCH_MODE_OPEN                        1               /**< ���� */
#define IMOS_MW_SWITCH_MODE_CLOSE                       2               /**< ���� */

/**@brief ����������� */
#define IMOS_MW_AUDIO_DETECT_TYPE_RISE                  0               /**< ���� */
#define IMOS_MW_AUDIO_DETECT_TYPE_FALL                  1               /**< ���� */
#define IMOS_MW_AUDIO_DETECT_TYPE_MUTATION              2               /**< ͻ�� */
#define IMOS_MW_AUDIO_DETECT_TYPE_LIMIT                 3               /**< ���� */  

/**@brief  Υ����澯�ϱ����� */
/* BEGIN: Added by z01232, 2013/10/6  Υ����澯�ϱ� */
#define IMOS_MW_CMD_ALARM_CROSS_LINE                   301                 /**<  ������ ���߸澯 */
#define IMOS_MW_CMD_ALARM_INTROSION_ZONE               302                 /**<  �������ָ澯 */
#define IMOS_MW_CMD_ALARM_ACCESS_ZONE                  303                 /**<  ��������(������) */
#define IMOS_MW_CMD_ALARM_LEAVE_ZONE                   304                 /**<  �뿪����(������) */
#define IMOS_MW_CMD_ALARM_HOVER_ZONE                   305                 /**<  �����ǻ� */
#define IMOS_MW_CMD_ALARM_OVER_FENCE                   306                 /**<  ��ԽΧ��*/
#define IMOS_MW_CMD_ALARM_CARE_ARTICLE                 307                 /**<  ��Ʒ���� */
#define IMOS_MW_CMD_ALARM_REMAIN_ARTICLE               308                 /**<  ��Ʒ����*/
/* END:   Added by z01232, 2013/10/6 */

#if 0
#endif
/**************************************** ��̨Ѳ����� ***************************************/
/*@brief ���켣�����*/
#define IMOS_MW_TRACK_POINT_NUM                64      

/*@brief ��󳡾�����*/
#define IMOS_MW_SCENE_NUM                      4

/*@brief Ԥ��λ������Ϣ��󳤶� */ 
#define IMOS_MW_PTZ_PRESET_NAME                64  

/*@brief ��̨Э�����Ƴ��� */ 
#define IMOS_MW_PTZ_NAME_LEN                   16

/*@brief �ƻ������ĸ�ʱ��Σ�Ѳ���ƻ��������ƻ��� */ 
#define IMOS_MW_TIME_SECTION_NUM               4  

/*@brief �ƻ�����12��ʱ��Σ�Ѳ���ƻ��� */ 
#define IMOS_MW_IVA_TIME_SECTION_NUM           12  

/*@brief ʱ���ַ������� */ 
#define IMOS_MW_TIME_LEN                       12    

/*@brief �����ַ������� */ 
#define IMOS_MW_DAY_LEN                        12   

/*@brief �ܵ����� */
#define IMOS_MW_WEEK_DAY                       7

/*@brief ��չ�ƻ���������� */
#define IMOS_MW_EXPLAN_DAYS                    64

/**@brief ��̨�������� */
#define IMOS_MW_PTZ_CMD_IRISCLOSE              0x0102        /**< ��Ȧ��С */
#define IMOS_MW_PTZ_CMD_IRISOPEN               0x0104        /**< ��Ȧ��� */
#define IMOS_MW_PTZ_CMD_FOCUSNEAR              0x0202        /**< ���۽� */
#define IMOS_MW_PTZ_CMD_FOCUSFAR               0x0204        /**< Զ�۽� */
#define IMOS_MW_PTZ_CMD_ZOOMIN                 0x0302        /**< �Ŵ� */
#define IMOS_MW_PTZ_CMD_ZOOMOUT                0x0304        /**< ��С */
#define IMOS_MW_PTZ_CMD_TILTUP                 0x0402        /**< ��, ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_TILTDOWN               0x0404        /**< ��, ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_PANRIGHT               0x0502        /**< ��, ulPTZCmdPara1 ˮƽ�����ٶ� */
#define IMOS_MW_PTZ_CMD_PANLEFT                0x0504        /**< ��, ulPTZCmdPara1 ˮƽ�����ٶ� */
#define IMOS_MW_PTZ_CMD_LEFTUP                 0x0702        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_LEFTDOWN               0x0704        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_RIGHTUP                0x0802        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */    
#define IMOS_MW_PTZ_CMD_RIGHTDOWN              0x0804        /**< ����, ulPTZCmdPara1 ˮƽ�����ٶ�  ulPTZCmdPara2 ��ֱ�����ٶ� */
#define IMOS_MW_PTZ_CMD_STOP                   0x0901        /**< ֹͣ */
#define IMOS_MW_PTZ_CMD_BRUSHON                0x0A01        /**< ��ˢ�� */
#define IMOS_MW_PTZ_CMD_BRUSHOFF               0x0A02        /**< ��ˢ�� */
#define IMOS_MW_PTZ_CMD_LIGHTON                0x0B01        /**< �ƿ� */
#define IMOS_MW_PTZ_CMD_LIGHTOFF               0x0B02        /**< �ƹ� */
#define IMOS_MW_PTZ_CMD_HEATON                 0x0C01        /**< ���ȿ� */
#define IMOS_MW_PTZ_CMD_HEATOFF                0x0C02        /**< ���ȹ� */
#define IMOS_MW_PTZ_CMD_INFRAREDON             0x0D01        /**< ���⿪ */
#define IMOS_MW_PTZ_CMD_INFRAREDOFF            0x0D02        /**< ����� */
#define IMOS_MW_PTZ_CMD_SNOWCLEAR              0x1301        /**< ��ѩģʽ����, ulPTZCmdPara1 Ϊǿ�� 1-9 */
#define IMOS_MW_PTZ_CMD_SNOWCLEAROFF           0x1302        /**< ��ѩģʽ�ر� */ 

/**@brief ��̨��λ��Ϣ */
#define IMOS_MW_PTZ_DIRECTION_E                 0              /**< ��   */
#define IMOS_MW_PTZ_DIRECTION_SE                1              /**< ���� */
#define IMOS_MW_PTZ_DIRECTION_S                 2              /**< ��   */
#define IMOS_MW_PTZ_DIRECTION_SW                3              /**< ���� */
#define IMOS_MW_PTZ_DIRECTION_W                 4              /**< ��   */
#define IMOS_MW_PTZ_DIRECTION_NW                5              /**< ���� */
#define IMOS_MW_PTZ_DIRECTION_N                 6              /**< ��   */
#define IMOS_MW_PTZ_DIRECTION_NE                7              /**< ���� */

#if 0
#endif
/**************************************** �洢 (����) ��� ***************************************/
/**@brief �洢�ļ����� */
#define IMOS_MW_STOR_FILE_TYPE_VIDEO        0          /**< ¼�� */
#define IMOS_MW_STOR_FILE_TYPE_PICTURE      1          /**< ��Ƭ */
#define IMOS_MW_STOR_FILE_TYPE_ALL          2          /**< �������� */

/**@brief �洢���� */
#define IMOS_MW_STOR_POLICY_FULL_STOP       0          /**< ��ֹͣ */
#define IMOS_MW_STOR_POLICY_FULL_REWRITE    1          /**< ������ */

/**@brief �洢ģʽ(����) */
#define IMOS_MW_LOCAL_STOR_AUTO             0          /**< �Զ� */
#define IMOS_MW_LOCAL_STOR_FOREVER          1          /**< ���� */
#define IMOS_MW_LOCAL_STOR_SAVE             2          /**< �������ϴ�����SD���ϵ��ļ� */
#define IMOS_MW_LOCAL_STOR_START            10         /**< ���� */
#define IMOS_MW_LOCAL_STOR_STOP             11         /**< �ر� */

/**@brief �洢·������(Ŀ¼���ļ�) */
#define IMOS_MW_STOR_PATH_DIR               0          /**< Ŀ¼ */ 
#define IMOS_MW_STOR_PATH_FILE              1          /**< �ļ� */ 

/**@brief �洢���� */
#define IMOS_MW_STOR_TYPE_SD                0        /**< SD�� */
#define IMOS_MW_STOR_TYPE_NAS               1        /**< NAS */               

#if 0
#endif
/**************************************** ������� ***************************************/
/*@brief ������Ȧ������� */
#define IMOS_MW_VIRTUAL_COIL_MAX_NUM                 8    

/*@brief �����ʶ���������  */
#define IMOS_MW_LPR_AREA_MAX_NUM                     4 

/*@brief ��󳵵���Ŀ  */
#define IMOS_MW_VEHICLE_WAY_MAX_NUM                  4 

/*@brief ע����Ƭ���շ���������Ϣ�ַ�������  */
#define IMOS_MW_PHOTOSERVER_CODE_LEN                 32     

/*@brief ����·����Ϣ���� */
#define IMOS_MW_ROAD_INFO_LEN                        100     

/*@brief �����Ȧ���� */
#define IMOS_MW_VEHICLE_DETECT_MAX_NUM               8

/*@brief ��󴮿ڸ��� */
#define IMOS_MW_SERIAL_MAX_NUM                       20

/**@brief ��Ƭ���շ�����ͨ��Э������ */
#define IMOS_MW_PHOTOSERVER_UNVIEW1                  0             /**< ����V1����Ӧ���̣�*/                           
#define IMOS_MW_PHOTOSERVER_UNVIEW2                  1             /**< ����V2����Ӧ��ǰtms��*/                           
#define IMOS_MW_PHOTOSERVER_XC                       2             /**< �ȴ� */
#define IMOS_MW_PHOTOSERVER_QST                      3             /**< Ȫ��ͨ */

/**@brief ����������ģʽ */
#define IMOS_MW_TRRIGER_MODE_PULLINTO                0             /**< �������� */
#define IMOS_MW_TRRIGER_MODE_PULLOUT                 1             /**< �������� */

/**@brief ������Ȧ(����) ���� */
#define IMOS_MW_VIRTUAL_COIL_AUTO                    0             /**< �Զ� */
#define IMOS_MW_VIRTUAL_COIL_ENABLE                  1             /**< ���� */
#define IMOS_MW_VIRTUAL_COIL_DISABLE                 2             /**< ���� */
#define IMOS_MW_VIRTUAL_COIL_WITH_RADAR_SPEED        3             /**< ��Ƶ��⡢�״���� */

/**@brief ���� ����ģʽ */
#define IMOS_MW_TG_MODE_TRAFFIC                      0             /**< ��ͨ��·���� */
#define IMOS_MW_TG_MODE_TRAFFIC_EXPRESSWAY           1             /**< ����·���� */
#define IMOS_MW_TG_MODE_TOLLGATE                     2             /**< ԰������ */
#define IMOS_MW_TG_MODE_MIX                          3             /**< ��Ͽ��� */

/**@brief �״� ����ģʽ */
#define IMOS_MW_RADAR_MODE_CONTINUOUS                0             /**< ����ģʽ */
#define IMOS_MW_RADER_MODE_FRONT_TRIGGER             1             /**< ��ͷ����ģʽ */
#define IMOS_MW_RADER_MODE_REAR_TRIGGER              2             /**< ��β����ģʽ */
#define IMOS_MW_RADER_MODE_DOUBLE_TRIGGER            3             /**< ˫����ģʽ */

/**@brief �״� �������ģʽ */
#define IMOS_MW_RADAR_DIRECTION_NONE_FILTER          0             /**< ������ */
#define IMOS_MW_RADER_DIRECTION_COME                 1             /**< ��������� */
#define IMOS_MW_RADER_DIRECTION_GONE                 2             /**< ���ȥ���� */

/**@brief �״� ���ٸ�ʽ */
#define IMOS_MW_RADAR_SPEED_SINGLE_BYTE              0             /**< ���ֽ� */
#define IMOS_MW_RADAR_SPEED_DOUBLE_BYTE              1             /**< ˫�ֽ� */
#define IMOS_MW_RADAR_SPEED_ASCII_FORMAT             2             /**< ASCII ��ʽ */

/**@brief �������ģʽ */
#define IMOS_MW_LASER_MEASURE_MODE_SIDE_DUAL         0             /**< ����˫����ģʽ */
#define IMOS_MW_LASER_MEASURE_MODE_TOP_DUAL          1             /**< ����˫����ģʽ */
#define IMOS_MW_LASER_MEASURE_MODE_AVERAGE           2             /**< ƽ��ģʽ */
#define IMOS_MW_LASER_MEASURE_MODE_CENTRAL           3             /**< ����ģʽ */
#define IMOS_MW_LASER_MEASURE_MODE_TOP_SINGLE        4             /**< ���õ�����ģʽ */
#define IMOS_MW_LASER_MEASURE_MODE_SIDE_SINGLE       5             /**< ����������ģʽ */
#define IMOS_MW_LASER_MEASURE_MODE_DEMO              6             /**< ��ʾģʽ */

/**@brief ���������ʽ */
#define IMOS_MW_LASER_MEASURE_WAY_MANUAL             0             /**< �ֶ����� */
#define IMOS_MW_LASER_MEASURE_WAY_AUTO               1             /**< �Զ����� */

/**@brief ������־���� */
#define IMOS_MW_LASER_LOG_CLOSE                      0             /**< �ر� */
#define IMOS_MW_LASER_LOG_OPEN                       1             /**< ���� */

/**@brief ��ƽ�������� */
#define IMOS_MW_LASER_LEVER_TRIGGER_CLOSE            0             /**< �ر� */
#define IMOS_MW_LASER_LEVER_TRIGGER_OPEN             1             /**< ���� */

#if 0
#endif
/******************************* ���Ӿ�����ض��� ***********************************/
/**@brief ������������������ֵ */
#define IMOS_MW_CAMERA_NUM_MAX          	     8

/**@brief �������, �羯����δʹ�ã������������޸ĸ�ֵ */
#define IMOS_MW_DIRECTION_NUM_MAX                1

/**@brief ���������ϰ������� */
#define IMOS_MW_DRIVEWAY_VIRTUALCOIL_NUM         2

/**@brief ������������������ */
#define IMOS_MW_DRIVEWAY_LINE_NUM                2

/**@brief ͨ��ʱ��θ��� */
#define IMOS_MW_COMMON_TIMESECTION_NUM           4

/**@brief ר�ó��� ʱ��θ��� */
#define IMOS_MW_DRIVEWAY_TIMESECTION_NUM         4

/**@brief �ٶȵ������ٶȶ������� */
#define IMOS_MW_DRIVEWAY_SPEED_ADJUST_NUM        5

/**@brief ��������� ���������ֵ */
#define IMOS_MW_DRIVEWAY_NUM_MAX                 8

/**@brief ��������� �����������ֵ */
#define IMOS_MW_DRIVEWAY_LINE_NUM_MAX            (IMOS_MW_DRIVEWAY_NUM_MAX + 1)

/**@brief ������򶥵������� */
#define IMOS_MW_DETECTAREA_POINTNUM_MAX          16

/**@brief ��������� ������������� */
#define IMOS_MW_DETECTAREA_NUM_MAX               8

/**@brief ��������� �궨ˮƽ������ */
#define IMOS_MW_HORIZONTAL_LINE_NUM              2

/**@brief ��������� ���������� */
#define IMOS_MW_TRIGGER_LINE_NUM                 16

/**@brief ��������� Υ��ץ�ĵĴ��������� */
#define IMOS_MW_PECCANCY_TRIGGERLINE_NUM         8

/**@brief Υ�����͵������� */
#define IMOS_MW_PECCANCYTYPE_MAX_NUM             32

/**@brief ���̵� ��ɫ���� */
#define IMOS_MW_TRAFFICLIGHT_COLOR_NUM           3

/**@brief �������̵Ƶ����� �Ƹ��������ֵ */
#define IMOS_MW_LIGHT_NUM_MAX                    8    

/**@brief ����������ĺ��̵� ������������ֵ */
#define IMOS_MW_LIGHTGROUP_NUM_MAX               8

/**@brief ����������ĺ��̵� ģ�������� */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NUM_MAX    16

/**@brief ���̵�ģ�����Ƴ��� */
#define  IMOS_MW_TRAFFICLIGHT_TEMPLATE_NAME_LEN  32

/*@brief ͬ����λ������Ŀ  */
#define IMOS_MW_ACSYNC_NUM                        4

/**@brief ���̵���ɫ */
#define IMOS_MW_LIGHT_COLOR_RED                  0 
#define IMOS_MW_LIGHT_COLOR_GREEN                1
#define IMOS_MW_LIGHT_COLOR_YELLOW               2

/**@brief ���� */
#define IMOS_MW_DIRECTION_EASTTOWEST             1                  /**< �Զ����� */
#define IMOS_MW_DIRECTION_WESTTOEAST       	     2                  /**< ������ */
#define IMOS_MW_DIRECTION_SOUTHTONORTH           3                  /**< ������ */
#define IMOS_MW_DIRECTION_NORTHTOSOUTH           4                  /**< �Ա����� */
#define IMOS_MW_DIRECTION_SOUTHEASTTONORTHWEST   5                  /**< ���������� */
#define IMOS_MW_DIRECTION_NORTHWESTTOSOUTHEAST   6                  /**< �������� */
#define IMOS_MW_DIRECTION_NORTHEASTTOSOUTHWEST   7                  /**< ���������� */
#define IMOS_MW_DIRECTION_SOUTHWESTTONORTHEAST   8                  /**< �����򶫱� */

/**@brief ͼƬ��֡���� */
#define IMOS_MW_IMAGE_FIELD_TYPE 		         0                  /**< ������ */
#define IMOS_MW_IMAGE_FRAME_TYPE		         1                  /**< ֡���� */

/**@brief ��ƵԴ���� */
#define IMOS_MW_VIDEOSRC_LOCAL                   0                  /**< ���� */
#define IMOS_MW_VIDEOSRC_JPEG                    1                  /**< JPEG */
#define IMOS_MW_VIDEOSRC_MJPEG                   2	                /**< MJPEG */
#define IMOS_MW_VIDEOSRC_AVI                     3	                /**< AVI */

/**@brief ͼƬ��ת */
#define IMOS_MW_IMAGE_ROTATE_NONE                0                  /**< ����ת */                    
#define IMOS_MW_IMAGE_ROTATE_CLOCKWISE_90        1                  /**< ˳ʱ�� 90��*/  
#define IMOS_MW_IMAGE_ROTATE_ANTICLOCKWISE_90    2                  /**< ��ʱ�� 90��*/ 

/**@brief ͼƬɫ�ʿռ� */
#define IMOS_MW_IMAGE_COLORSPACE_JPG             0                  /**< JPG */                    
#define IMOS_MW_IMAGE_COLORSPACE_RGB             1                  /**< RGB */                    
#define IMOS_MW_IMAGE_COLORSPACE_YUV420          2                  /**< YUV420 */  
#define IMOS_MW_IMAGE_COLORSPACE_YUV422          3                  /**< YUV422 */ 
#define IMOS_MW_IMAGE_COLORSPACE_GRAY            4                  /**< GRAY */ 

/**@brief �������� */
#define IMOS_MW_DRIVEWAYTYPE_NORMAL              0                  /**< ��ͨ���� */
#define IMOS_MW_DRIVEWAYTYPE_SINGLE_LINE         1                  /**< �����߳��� */

/**@brief �������� */
#define IMOS_MW_DRIVEWAYTYPE_GENERAL             0                  /**< ��ͨ���� */
#define IMOS_MW_DRIVEWAYTYPE_BUSONLY             1                  /**< ������ר�ó��� */
#define IMOS_MW_DRIVEWAYTYPE_NOTRUNK             2                  /**< �������복�� */
#define IMOS_MW_DRIVEWAYTYPE_NOVEHICLE           3                  /**< �ǻ������� */

/**@brief ������ʻ���� */
#define IMOS_MW_DRIVING_DIRECTION_COME           0                  /**< ����������ʻ����ͷ�� */
#define IMOS_MW_DRIVING_DIRECTION_GONE           1                  /**< ����������ʻ����β�� */
#define IMOS_MW_DRIVING_DIRECTION_BOTH           3                  /**< ˫�� */

/**@brief ��������ʻ���� (�����) */
#define IMOS_MW_DRIVING_TYPE_STRAIGHT            0x1               /**< ֱ�� */
#define IMOS_MW_DRIVING_TYPE_TURN_LEFT           0x2               /**< ��ת */
#define IMOS_MW_DRIVING_TYPE_TURN_RIGHT          0x4               /**< ��ת */

/**@brief ��ǰ���� �Ƿ���ʻ���� (�����) */
#define IMOS_MW_DRIVING_ILLEGAL_TURNLEFT                0x1               /**< ��ֹ��ת */
#define IMOS_MW_DRIVING_ILLEGAL_TURNRIGHT               0x2               /**< ��ֹ��ת */
#define IMOS_MW_DRIVING_ILLEGAL_DIRECT_STRAIGHT         0x4               /**< ��ֱֹ�� */

/**@brief ����������� */
#define IMOS_MW_DETECTAREA_VEHICLE_DETECT        0               /**< ����������� */
#define IMOS_MW_DETECTAREA_FOLLOW                1               /**< �������� */
#define IMOS_MW_DETECTAREA_LOCKAREA              2               /**< ·��궨���� */

/**@brief �������ģʽ */
#define IMOS_MW_VEHICLE_DETECTMODE_VIDEO         0               /**< ��Ƶ��� */

/**@brief ����ʶ��ģʽ: ��δʹ�� */
#define IMOS_MW_PLATEIDENTIFY_MODE_PICTURE       0               /**< ͼƬʶ�� */

/**@brief ��������ģʽ  */
#define IMOS_MW_SPEEDLIMIT_MODE_DRIVEWAY         0              /**< ���������� */
#define IMOS_MW_SPEEDLIMIT_MODE_VEHICLETYPE      1              /**< ���������� */

/**@brief ���� (�����) */
#define IMOS_MW_VEHICLETYPE_SMALL                0x1               /**< С�ͳ� */
#define IMOS_MW_VEHICLETYPE_LARGE                0x2               /**< ���ͳ� */
#define IMOS_MW_VEHICLETYPE_MOTOR                0x4               /**< Ħ�г� */
#define IMOS_MW_VEHICLETYPE_ENHANCE              0x400            /**< �������ԣ���ǿ�����Ƴ��ļ�⣬���������� */
#define IMOS_MW_VEHICLETYPE_REDUCE               0x800            /**< �������ԣ���������������ܽ��ͼ���� */
#define IMOS_MW_VEHICLETYPE_NUM                  8                 /**< �����������ֵ */

/**@brief ������ ���� */
#define IMOS_MW_TRIGGER_LINE_DEFAULT1            1              /**< ������1 */
#define IMOS_MW_TRIGGER_LINE_STOP                2              /**< ֹͣ�� */
#define IMOS_MW_TRIGGER_LINE_STRAIGHT2           3              /**< ֱ�д�����2 */
#define IMOS_MW_TRIGGER_LINE_STRAIGHT3           4              /**< ֱ�д�����3 */
#define IMOS_MW_TRIGGER_LINE_STRAIGHT_DELAY3     5              /**< ֱ�д�����3# */
#define IMOS_MW_TRIGGER_LINE_TURNLEFT2           6              /**< ��ת������2 */
#define IMOS_MW_TRIGGER_LINE_TURNRIGHT2          7              /**< ��ת������2 */

/**@brief ���̵� ʶ��ʽ */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_TEMPLATE        0     /**< ģ��ʶ�� */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_VIDEO           1     /**< ��Ƶʶ�� */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_SERIAL          2     /**< ������ */
#define IMOS_MW_TRAFFICLIGHT_IDENTIFYMODE_MULTISERIAL     3     /**< �മ�� */

/**@brief ���̵� ���� */
#define IMOS_MW_TRAFFICLIGHT_TYPE_SIMPLE                  0     /**< �򵥵� */
#define IMOS_MW_TRAFFICLIGHT_TYPE_COMPLEX                 1     /**< ���ӵ� */
#define IMOS_MW_TRAFFICLIGHT_TYPE_MIX                     2     /**< ��ϵ� */

/**@brief ���̵� ��ɫ (�����) */
#define IMOS_MW_TRAFFICLIGHT_COLOR_RED                    0x1     /**< ��� */
#define IMOS_MW_TRAFFICLIGHT_COLOR_YELLOW                 0x2     /**< �Ƶ� */
#define IMOS_MW_TRAFFICLIGHT_COLOR_GREEN                  0x4     /**< �̵� */

/**@brief ���̵� ��״ */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_ROUND                  0     /**< Բ�� */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_ARROW                  1     /**< ��ͷ */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_BAR                    2     /**< ���� */
#define IMOS_MW_TRAFFICLIGHT_SHAPE_OTHER                  4     /**< ���� */


/**@brief ���̵� IO�˿� */
#define IMOS_MW_TRAFFICLIGHT_IO_NONE     		          0     /**< �� */
#define IMOS_MW_TRAFFICLIGHT_IO_SERIAL1                   1     /**< ����1 */
#define IMOS_MW_TRAFFICLIGHT_IO_SERIAL2                   2     /**< ����2 */   

/**@brief ���̵� ָʾ���� (�����) */
#define IMOS_MW_TRAFFICLIGHT_DIRECT_LEFT                  0x1     /**< ��ת */
#define IMOS_MW_TRAFFICLIGHT_DIRECT_RIGHT                 0x2     /**< ��ת */
#define IMOS_MW_TRAFFICLIGHT_DIRECT_STRAIGHT              0x4     /**< ֱ�� */

/**@brief ���̵� ���з��� */
#define IMOS_MW_TRAFFICLIGHT_ARRANGE_HORIZATIONAL         0     /**< ���� */
#define IMOS_MW_TRAFFICLIGHT_ARRANGE_VERTICAL             1     /**< ���� */

/**@brief ����� ���ģʽ */
#define IMOS_MW_RUNREDLIGHT_DETECTMODE_GENERAL            0     /**< ��ͨģʽ */
#define IMOS_MW_RUNREDLIGHT_DETECTMODE_3LINE              1     /**< 3��ģʽ */

/**@brief Υ�¼�¼����ģʽ */
#define IMOS_MW_MULTI_BREAKRULE_RECORD_EACH               0     /**< ÿ��Υ�¾���������Υ�¼�¼ */
#define IMOS_MW_MULTI_BREAKRULE_RECORD_HIGHEST            1     /**< ������������ȼ�Υ�µ�Υ�¼�¼ */

/**@brief ���������� */
#define IMOS_MW_DRIVEWAY_LINE_SOLID_WHITE                        0     /**< ��ʵ�� */
#define IMOS_MW_DRIVEWAY_LINE_SOLID_YELLOW                       1     /**< ��ʵ�� */
#define IMOS_MW_DRIVEWAY_LINE_2SOLID_YELLOW                      2     /**< ˫��ʵ�� */
#define IMOS_MW_DRIVEWAY_LINE_L_REALLINE_R_BROKENLINE            3     /**< ˫����ʵ������ */
#define IMOS_MW_DRIVEWAY_LINE_L_BROKENLINE_R_REALLINE            4     /**< ˫��������ʵ�� */
#define IMOS_MW_DRIVEWAY_LINE_L_REALLINE_R_BROKENLINE_WHITE      5     /**< ˫����ʵ������ */
#define IMOS_MW_DRIVEWAY_LINE_L_BROKENLINE_R_REALLINE_WHITE      6     /**< ˫��������ʵ�� */
#define IMOS_MW_DRIVEWAY_LINE_OTHER                              7     /**< ���� */

/**@brief ����Υ������ (�����) */
#define IMOS_MW_VEHICLE_PECCANCY_NONE                     0x0        /**< û��Υ�� */
#define IMOS_MW_VEHICLE_PECCANCY_RUNREDLIGHT              0x1        /**< ����� */
#define IMOS_MW_VEHICLE_PECCANCY_PRESSLINE                0x2        /**< ѹ�� */
#define IMOS_MW_VEHICLE_PECCANCY_OVERLINE                 0x4        /**< Խ��(Υ�±��) */
#define IMOS_MW_VEHICLE_PECCANCY_ILLEGAL_DRIVEWAY         0x8        /**< δ��������ʻ */
#define IMOS_MW_VEHICLE_PECCANCY_TURNLEFT                 0x10       /**< Υ����ת */
#define IMOS_MW_VEHICLE_PECCANCY_TURNRIGHT                0x20       /**< Υ����ת */
#define IMOS_MW_VEHICLE_PECCANCY_CONVERSE                 0x40       /**< ���� */
#define IMOS_MW_VEHICLE_PECCANCY_OVERSPEED                0x80       /**< ���� */
#define IMOS_MW_VEHICLE_PECCANCY_LOWSPEED                 0x100      /**< ���� */
#define IMOS_MW_VEHICLE_PECCANCY_RESTRICT_ODD_EVEN        0x200      /**< ��˫������ */
#define IMOS_MW_VEHICLE_PECCANCY_SPECAIL_DRIVEWAY         0x400      /**< ר�ó��� */
#define IMOS_MW_VEHICLE_PECCANCY_ILLEGALPARK              0x800      /**< Υ��ͣ�� */
#define IMOS_MW_VEHICLE_PECCANCY_DIRECT_STRAIGHT          0x1000     /**< Υ��ֱ�� */ 
#define IMOS_MW_VEHICLE_PECCANCY_BACK_CAR                 0x2000     /**< Υ������ */ 
#define IMOS_MW_VEHICLE_PECCANCY_OVER50PERCENTSPEED       0x4000     /**< ����50% */
#define IMOS_MW_VEHICLE_PECCANCY_PRESS_2SOLID_YELLOW      0x8000     /**< ѹ˫���� */
#define IMOS_MW_VEHICLE_PECCANCY_PRESS_SOLID_YELLOW       0x10000    /**< ѹ������ */
#define IMOS_MW_VEHICLE_PECCANCY_PRESS_STOP_LINE          0x20000    /**< ѹͣ���� */
#define IMOS_MW_VEHICLE_PECCANCY_OVER20PERCENTSPEED       0x40000    /**< ����20% */
#define IMOS_MW_VEHICLE_PECCANCY_OVER100PERCENTSPEED      0x80000    /**< ����100% */
#define IMOS_MW_VEHICLEPECCANCY_TYPE_NUM                  20          /**< ����Υ�����͸��� */

/**@brief ͼƬ�ϳ�ģʽ */
#define IMOS_MW_IMAGE_COMPOSITE_MODE_NONE                 0          /**< ���ϳ� */
#define IMOS_MW_IMAGE_COMPOSITE_MODE_LEFTRIGHT            1          /**< ����ͼƬ: һ��һ�� */

/**@brief ����ͼƬ���� */
#define IMOS_MW_IMAGE_MAKE_PLATE_COLOR                    0x1          /**< ���ɳ��Ʋ�ɫСͼ */
#define IMOS_MW_IMAGE_MAKE_PLATE_BINARY                   0x2          /**< ���ɳ��ƶ�ֵ��ͼ */
#define IMOS_MW_IMAGE_MAKE_PLATE_FEATURE                  0x4          /**< ���ɳ�����дͼ */
#define IMOS_MW_IMAGE_MAKE_COMPOSE                        0x8          /**< ������Ƭ�ϳ�ͼ */

/**@brief ͼƬ���� */
#define IMOS_MW_IMAGE_PECCANCY                            0          /**< Υ����ΪͼƬ */
#define IMOS_MW_IMAGE_COMPOSITE                           1          /**< �ϳ�ͼƬ */
#define IMOS_MW_IMAGE_TEMP                                2          /**< ��ʱͼƬ */
#define IMOS_MW_IMAGE_TYPE_NUM                            3          /**< ͼƬ���͸��� */

/**@brief ���̵�ģ������ (�����) */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_STRAIGHT            0x1        /**< ֱ��ͨ�� */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NOSTRAIGHT          0x2        /**< ֱ�н��� */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_TURNLEFT            0x4        /**< ��תͨ�� */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NOTURNLEFT          0x8        /**< ��ת���� */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_TURNRIGHT           0x10       /**< ��תͨ�� */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NOTURNRIGHT         0x20       /**< ��ת���� */

/**@brief ץ����������(�����) */
#define IMOS_MW_CAPTURE_PECCANCY                          0x1          /**< Υ�¼�¼ */                   
#define IMOS_MW_CAPTURE_PECCANCY_PASSVEHICLE              0x2          /**< Υ�¹�����¼ */  
#define IMOS_MW_CAPTURE_NOPECCANCY_PASSVEHICLE            0x4          /**< ��Υ�¹�����¼ */  

/**@brief ������� */
#define IMOS_MW_FULLVIEW_CAMERA                           0            /**< ȫ�� */   
#define IMOS_MW_FEATURE_CAMERA                            1            /**< ��д */   

/**@brief ���л��� */
#define IMOS_MW_PRODUCT_TYPE_TG                           0            /**< ���� */   
#define IMOS_MW_PRODUCT_TYPE_EP                           1            /**< �羯 */   

/**@brief ��Ƭ���� */
#define	IMOS_MW_IMAGE_VEHICLE                             1           /**< ������ͼ */
#define IMOS_MW_IMAGE_PLATE_COLOR                         2           /**< ���Ʋ�ɫСͼ */
#define IMOS_MW_IMAGE_PLATE_BINARY                        3           /**< ���ƶ�ֵ��ͼ */

#if 0
#endif
/**************************************** ���ſ��� ***************************************/
/*@brief ���Ŵ��������� */
#define IMOS_MW_MAX_WND_NUM                      9

/**@brief ����״̬ */
#define IMOS_MW_PLAY_STATUS_16_BACKWARD          0       /**< 16���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_8_BACKWARD           1       /**< 8���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_4_BACKWARD           2       /**< 4���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_2_BACKWARD           3       /**< 2���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_1_BACKWARD           4       /**< �����ٶȺ��˲��� */
#define IMOS_MW_PLAY_STATUS_HALF_BACKWARD        5       /**< 1/2���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_QUARTER_BACKWARD     6       /**< 1/4���ٺ��˲��� */
#define IMOS_MW_PLAY_STATUS_QUARTER_FORWARD      7       /**< 1/4���ٲ��� */
#define IMOS_MW_PLAY_STATUS_HALF_FORWARD         8       /**< 1/2���ٲ��� */
#define IMOS_MW_PLAY_STATUS_1_FORWARD            9       /**< �����ٶ�ǰ������ */
#define IMOS_MW_PLAY_STATUS_2_FORWARD            10      /**< 2����ǰ������ */
#define IMOS_MW_PLAY_STATUS_4_FORWARD            11      /**< 4����ǰ������ */
#define IMOS_MW_PLAY_STATUS_8_FORWARD            12      /**< 8����ǰ������ */
#define IMOS_MW_PLAY_STATUS_16_FORWARD           13      /**< 16����ǰ������ */

/**@brief ý���ļ���ʽ */
#define IMOS_MW_MEDIA_FILE_FORMAT_TS             0       /**< TS��ʽ��ý���ļ� */
#define IMOS_MW_MEDIA_FILE_FORMAT_FLV            1       /**< FLV��ʽ��ý���ļ� */

/**@brief �ָ�¼��ģʽ */
#define IMOS_MW_RECORD_PARTITION_NODE              0       /**< ������¼��ָ�*/
#define IMOS_MW_RECORD_PARTITION_TIME              1       /**< ¼��ʱ��ָ�*/
#define IMOS_MW_RECORD_PARTITION_DISKSPACE         2       /**< ¼�񰴴洢�ռ�ָ�*/

/**@brief ��Ƶ��ʾģʽ */
#define IMOS_MW_RENDER_MODE_D3D                  0       /**< ʹ��D3D�ķ�ʽ������ʾ */
#define IMOS_MW_RENDER_MODE_DDRAW_NORMAL         1       /**< ʹ��Ddraw��Normal��ʾģʽ */

/**@brief ��Ƶ���ظ�ʽ */
#define IMOS_MW_PIXEL_FORMAT_YUV420              0       /**< YUV420��ʽ��� */
#define IMOS_MW_PIXEL_FORMAT_RGB32               1       /**< RGB32��ʽ��� */

/**@brief ͼ�񲥷������� */
#define IMOS_MW_PICTURE_TIME_PRIORITY            0       /**< ʵʱ������ */
#define IMOS_MW_PICTURE_FLUENCY_PRIORITY         1       /**< ���������� */
#define IMOS_MW_PICTURE_AUTO                     2       /**< �Զ� */
#define IMOS_MW_PICTURE_LOWDELAY                 3       /**< ����ʱ */

/**@brief ���Ŵ�����ʾͼ��ı��� */
#define IMOS_MW_RENDER_SCALE_FULL                0       /**< ͼ������������Ŵ��� */
#define IMOS_MW_RENDER_SCALE_PROPORTION          1       /**< ͼ�񰴱�����ʾ */

/**@brief ý����������ʽ */
#define IMOS_MW_MEDIA_DATA_TS                    0       /**< TS��װ���� */
#define IMOS_MW_MEDIA_DATA_ES12                  1       /**< RTP + ��/��Ƶ˽��ͷ��12�ֽڣ� + ES���� */
#define IMOS_MW_MEDIA_DATA_ES12_TIME             2       /**< RTP + ʱ�����8�ֽڣ� + ��/��Ƶ˽��ͷ��12�ֽڣ� + ES���� */
#define IMOS_MW_MEDIA_DATA_RTP_ES                3       /**< RTP + ES���� */
#define IMOS_MW_MEDIA_DATA_HK                    4       /**< �����������ص��ĵ�һ�����Ǻ���40�ֽ�ϵͳͷ */
#define IMOS_MW_MEDIA_DATA_DH                    5       /**< ������ */
#define IMOS_MW_MEDIA_DATA_RM                    6       /**< �����������ص��ĵ�һ����������40�ֽ�ϵͳͷ */
#define IMOS_MW_MEDIA_DATA_TDY_SWALLOW           7       /**< TDY-SWALLOW */
#define IMOS_MW_MEDIA_DATA_DMA_SWALLOW           8       /**< DMA-SWALLOW */

/**@brief �������Ƶ��ʽ */
#define IMOS_MW_WAVE_FORMAT_PCM8M16              0       /**< PCM��8K�����ʣ���������M����16λ���� */
#define IMOS_MW_WAVE_FORMAT_PCM16M16             1       /**< PCM��16K�����ʣ���������M����16λ���� */ 
#define IMOS_MW_WAVE_FORMAT_PCM441M16            2       /**< PCM��44.1K�����ʣ���������M����16λ���� */ 

/**@brief ��Ƶ֡���� */
#define IMOS_MW_VIDEO_FRAME_TYPE_I               0       /**< I֡ */
#define IMOS_MW_VIDEO_FRAME_TYPE_P               1       /**< P֡ */
#define IMOS_MW_VIDEO_FRAME_TYPE_B               2       /**< B֡ */

/**@brief ʱ������� */
#define IMOS_MW_RENDER_TYPE_FRAME_RATE           0       /**< ʹ��֡�����ݽ�����Ƶ��Ⱦ */
#define IMOS_MW_RENDER_TYPE_ABSOLUTE_TIME        1       /**< ʹ�þ���ʱ�����ݽ�����Ƶ��Ⱦ */

/**@brief ���� �Աȶ�ģʽ */
#define IMOS_MW_PICTURE_CONTRAST_MODE_NONE        0      /**< �����жԱȶȵ��ڴ��� */
#define IMOS_MW_PICTURE_CONTRAST_MODE_BRIGHTNESS  1      /**< ����ģʽ */
#define IMOS_MW_PICTURE_CONTRAST_MODE_SOFTNESS    2      /**< ���ģʽ */

/**@brief ͼƬ��ʽ */
#define IMOS_MW_PICTURE_FORMAT_BMP                0      /**< BMP ��ʽ */ 
#define IMOS_MW_PICTURE_FORMAT_JPEG               1      /**< JPEG ��ʽ�������μ�: IMOS_MW_CAPTURE_FORMAT_CFG_S */
#define IMOS_MW_PICTURE_FORMAT_CUSTOM             10     /**< ������ʽ, ����Ҫ�������� */

/*@brief ��Ƭ��˵�����Ϣ���� */
#define IMOS_MW_IMAGE_BACKEND_OSD                 0    /**< ���� OSD���ṹ����: IMOS_MW_IMAGE_OSD_INFO_S */
#define IMOS_MW_IMAGE_BACKEND_RECTANGLE           1    /**< ���� ��Ϣ��, �ṹ����: IMOS_MW_RECTANGLE_S, ���У����굥λ 0.01% */
#define IMOS_MW_IMAGE_BACKEND_OSD_OBJ             2    /**< ����OSD, ��Ŀ����Ϣ��, �ṹ����: IMOS_MW_IMAGE_OSD_WITH_OBJ_S, ��Ϣ�����굥λ 0.01% */


#if 0
#endif
/**************************************** EZR �洢��� ***************************************/
/** @brief ��URI���� */
#define IMOS_MW_STREAM_URI_LEN                     256 

/** @brief EzRecord ������ */
#define IMOS_MW_STOR_DISK_NUM                      26

/** @brief �洢��Ŀ¼������ */
#define IMOS_MW_STOR_DISK_PATH_LEN                 32   /*�� E:*/

/** @brief ��ƵID��Ϣ���� (userid=48 path=32 name=32)=112 ����� 128 */
#define IMOS_MW_STOR_VIDEO_ID_LEN                  128

/* �洢���: �洢Դ���洢�ƻ����˿ڡ�������ͣ���������õ� */
#define IMOS_MW_STOR_SERVICE_STATE                 0             /**< ��ȡ/���� �洢�豸����״̬(��ͣ)  �μ�: IMOS_MW_STOR_SERVICE_XXX */
#define IMOS_MW_STOR_DISK_INFO                     1             /**< ��ȡ �洢�豸������Ϣ  ��Ӧ�ṹ����: IMOS_MW_STOR_DISK_INFO_S */
#define IMOS_MW_STOR_DISK_CFG                      2             /**< ����/ɾ�� �洢�������ã���Ӧ�ṹ����: IMOS_MW_STOR_CFG_DISK_ITEM_S */
#define IMOS_MW_STOR_RESOURCE_INFO                 3             /**< ��ȡ �洢ϵͳ��Դ��Ϣ(ʣ��洢������)����Ӧ�ṹ����: IMOS_MW_STOR_RESOURCE_INFO_S */
#define IMOS_MW_STOR_PORT_INFO                     4             /**< ��ȡ �洢�豸�˿���Ϣ  ��Ӧ�ṹ����: IMOS_MW_STOR_PORT_INFO_S */
#define IMOS_MW_STOR_SOURCE_CFG                    5             /**< ��ȡ/����/ɾ�� �洢Դ���ã���Ӧ�ṹ����: IMOS_MW_STOR_SOURCE_CFG_S(ɾ����IMOS_MW_STOR_SOURCE_INFO_S) */
#define IMOS_MW_STOR_PLAN_CFG                      6             /**< ��ȡ/����/ɾ�� �洢�ƻ�����Ӧ�ṹ����: IMOS_MW_STOR_PLAN_CFG_S(ɾ����IMOS_MW_STOR_SOURCE_INFO_S) */ 
#define IMOS_MW_STOR_PLAN_STATE                    7             /**< ��ȡ/����   �洢�ƻ�״̬����Ӧ�ṹ����: IMOS_MW_STOR_SOURCE_PLANSTATE_S */ 
#define IMOS_MW_STOR_MANUAL_STAT                   8             /**< ��ȡ �ֶ��洢״̬�� ��Ӧ�ṹ����: IMOS_MW_STOR_MANUAL_STORESTATE_S */ 
#define IMOS_MW_STOR_SET_PASSWORD                  9             /**< ���� ���룬 ��Ӧ�ṹ����: IMOS_MW_STOR_SET_PASSWORD_S */
#define IMOS_MW_STOR_NTP_CFG                       10            /**< NTP ���ã���Ӧ�ṹ����: IMOS_MW_STOR_NTP_CFG_S */
#define IMOS_MW_STOR_VIDEO_CHL_CFG                 11            /**< ��ȡ ��Ƶͨ����Ϣ�� ��Ӧ�ṹ����: IMOS_MW_STOR_VIDEO_CHL_CFG_S */ 
#define IMOS_MW_STOR_VIDEO_CHL_NUM                 12            /**< ��ȡ ��Ƶͨ������ ��Ӧ�ṹ����: IMOS_MW_STOR_VIDEO_CHL_NUM_S */ 

/**@brief �洢�ϱ��¼����� */
#define IMOS_MW_STOR_EVENT_DEVICE_OFFLINE          0              /**< EZR�豸����  �޲��� */
#define IMOS_MW_STOR_EVENT_USE_NEW_PORT            1              /**< EZR�豸�˿ڸ���  USHORT */
#define IMOS_MW_STOR_EVENT_SERVICE_CHANGE          2              /**< ����ı� ULON 0��ֹͣ 1������ */
#define IMOS_MW_STOR_EVENT_GOING_FULL              10             /**< �洢�ڴ漴���� IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_FULL_STOP               11             /**< �洢��ֹͣ IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_START             20             /**< �洢���� IMOS_MW_STOR_SOURCE_INFO_S*/
#define IMOS_MW_STOR_EVENT_STORE_STOP              21             /**< �洢ֹͣ IMOS_MW_STOR_SOURCE_INFO_S*/
#define IMOS_MW_STOR_EVENT_STORE_FAILED            22             /**< �洢ʧ�� IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_RECOVER           23             /**< �洢�ָ� IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_PLAN_FAILED       24             /**< �ƻ��洢ʧ�� IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_STORE_PLAN_RECOVER      25             /**< �ƻ��洢�ָ� IMOS_MW_STOR_SOURCE_INFO_S */
#define IMOS_MW_STOR_EVENT_DOWNLOAD_PROCESS        30             /**< ���ؽ��� IMOS_MW_STOR_DOWNLOAD_INFO_S*/
#define IMOS_MW_STOR_EVENT_DOWNLOAD_ERROR          31             /**< ���س��� IMOS_MW_STOR_DOWNLOAD_INFO_S */
#define IMOS_MW_STOR_EVENT_DOWNLOAD_COMPLETE       32             /**< ������� IMOS_MW_STOR_DOWNLOAD_INFO_S */

/**@brief �洢����״̬ */
#define IMOS_MW_STOR_SERVICE_OFF                   0              /**< �洢ҵ��ͣ�� */
#define IMOS_MW_STOR_SERVICE_ON                    1              /**< �洢ҵ������ */

/**@brief �洢�ƻ�״̬ */
#define IMOS_MW_STOR_PLAN_OFF                      0              /**< �洢�ƻ�ͣ�� */
#define IMOS_MW_STOR_PLAN_ON                       1              /**< �洢�ƻ����� */

/**@brief ��Ƶ�洢���� */
#define IMOS_MW_VIDEO_STORE_MANUAL                 0x01           /**< �ֶ��洢 */
#define IMOS_MW_VIDEO_STORE_PLAN                   0x02           /**< �ƻ��洢 */
#define IMOS_MW_VIDEO_STORE_ALARM                  0x04           /**< �澯�洢 */
#define IMOS_MW_VIDEO_STORE_MOTION                 0x08           /**< �ƶ���� */
#define IMOS_MW_VIDEO_STORE_LABEL                  0x10           /**< ��ǩ */

/**@brief ��Ч��Ƶ��ID */
#define IMOS_MW_STOR_INVALID_STREAMID              (~0)           /**< ��Ч��ID */

/**@brief ���̴������ */
#define IMOS_MW_STORE_TYPE_VIDEO                   0              /**< ��Ƶ */
#define IMOS_MW_STORE_TYPE_MAX                     1

#if 0
#endif
/**************************************** ����ҵ����� ***************************************/
/**@brief ���������������� */
#define IMOS_MW_POLYGON_POINT_MAX_NUM         12    

/**@brief ֧�ֵ���󳡾��� */
#define IMOS_MW_IVA_SCENE_MAX_NUM             4

/**@brief ��������֧�ֵ�����ų������� */
#define IMOS_MW_IVA_IGNORE_AREA_MAX_NUM       4

/**@brief ��������֧�ֵ��������� */
#define IMOS_MW_IVA_RULE_OF_SCENE_MAX_NUM     4

/**@brief ֧�ֵ��������� */
#define IMOS_MW_IVA_RULE_MAX_NUM              (IMOS_MW_IVA_SCENE_MAX_NUM * IMOS_MW_IVA_RULE_OF_SCENE_MAX_NUM)

/**@brief Ŀ��ߴ������ */
#define IMOS_MW_IVA_FILTER_SIZE_MAX_NUM       6    

/**@brief ���ʱ궨������� */
#define IMOS_MW_IVA_MAGNIFICATION_MAX_NUM     6

/**@brief Υ����������� */
#define IMOS_MW_IVA_ILLEGAL_TYPE_MAX_NUM      1

/**@brief ����ҵ��ģʽ */
#define IMOS_MW_IVA_MODE_PEA                  0    /**< �ܽ���� */
#define IMOS_MW_IVA_MODE_IE                   1    /**< Υ��ȡ֤ */

/**@brief ���ܳ���Ѳ��ģʽ */
#define IMOS_MW_IVA_SINGLE_SCENE_MODE         0    /**< ������ ����ҵ��ģʽ���� */
#define IMOS_MW_IVA_WEEKDAY_PLAN_MODE         1    /**< �ܼƻ� ����ҵ��ģʽ���� */


/**@brief Ŀ��������� */
#define IMOS_MW_IVA_FILTER_TYPE_W_AND_H       0    /**< ��������Ϊ��͸� */
#define IMOS_MW_IVA_FILTER_TYPE_W_OR_H        1    /**< ��������Ϊ���� */

/**@brief Ŀ��ߴ�������� */
#define IMOS_MW_IVA_FILTER_SIZE_TYPE_NONE     0    /**< �޹��˳ߴ� */
#define IMOS_MW_IVA_FILTER_SIZE_TYPE_SINGLE   1    /**< ���˳ߴ�����Ϊ������ */
#define IMOS_MW_IVA_FILTER_SIZE_TYPE_MULTI    2    /**< ���˳ߴ�����Ϊ�ྰ�� */

/**@brief Ŀ�괥��λ�� */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_CENTER   0x001    /**< ����λ��ΪĿ������ */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_LEFT     0x002    /**< ����λ��ΪĿ�����Ե */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_RIGHT    0x004    /**< ����λ��ΪĿ���ұ�Ե */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_TOP      0x008    /**< ����λ��ΪĿ���ϱ�Ե */
#define IMOS_MW_IVA_TRIGGER_TYPE_OBJ_BOTTOM   0x010    /**< ����λ��ΪĿ���±�Ե */

/**@brief �������� */
#define IMOS_MW_IVA_RULE_TYPE_PICKET_LINE     0x001    /**< ������ */
#define IMOS_MW_IVA_RULE_TYPE_PICKET_AREA     0x002    /**< ����/�뿪����(������) */
#define IMOS_MW_IVA_RULE_TYPE_AREA_STAY       0x004    /**< �������� */
#define IMOS_MW_IVA_RULE_TYPE_OBJECT_STATUS   0x008    /**< ��Ʒ״̬���� */
#define IMOS_MW_IVA_RULE_TYPE_ILLEGAL_PARKING 0x100    /**< Υ��ͣ�� */

/**@brief ���򴥷����� */
#define IMOS_MW_IVA_DIREC_NONE                0     /**< �޷��� */
#define IMOS_MW_IVA_DIREC_DEASIL              1     /**< ������: ˳ʱ�� */
#define IMOS_MW_IVA_DIREC_ANTICLOCKWISE       2     /**< ������: ��ʱ�� */
#define IMOS_MW_IVA_DIREC_ENTRY               3     /**< ����: ���� */
#define IMOS_MW_IVA_DIREC_QUIT                4     /**< ����: �뿪 */
#define IMOS_MW_IVA_OBJECT_ABANDON            5     /**< ��Ʒ״̬: ���� */
#define IMOS_MW_IVA_OBJECT_THEFT              6     /**< ��Ʒ״̬: ��ȡ */

/**@brief Υ������ */
#define IMOS_MW_IVA_ILLEGAL_TYPE_NONE         0     /**< ��Υ�� */
#define IMOS_MW_IVA_ILLEGAL_TYPE_PARKING      1     /**< Υ��ͣ�� */

/* ����һ���Լ�� */
#define IMOS_MW_IVA_LP_CHECK_OFF              0     /**< ����������һ���Լ�� */
#define IMOS_MW_IVA_LP_CHECK_ON               1     /**< ��������һ���Լ�� */

/**@brief ��ʾԪ���ݲ���*/
#define IMOS_MW_IVA_SHOW_RULE                   0x00000001          /**< ��ʾ�����߿�*/
#define IMOS_MW_IVA_SHOW_RESULT_TOUTH_RULE      0x00000002          /**< ��ʾ��������Ŀ���*/
#define IMOS_MW_IVA_SHOW_RESULT_UNTOUTH_RULE    0x00000004          /**< ��ʾδ��������Ŀ���*/


#if 0
#endif
/*************************************** �ڲ�������� ********************************************/
/**@brief �����豸���� */
#define IMOS_MW_TRIGGER_DEVICE_OFF               0        /**< �ر� */  
#define IMOS_MW_TRIGGER_DEVICE_ON                1        /**< ���� */  

/**@brief LED�� */
#define IMOS_MW_LED_STROBE_OFF                   0        /**< LED�� �ر� */  
#define IMOS_MW_LED_STROBE_ON                    1        /**< LED�� ���� */ 
#define IMOS_MW_LED_STROB_AUTO                   2        /**< LED�� �Զ� */ 
#define IMOS_MW_LED_STROB_NIGHT_ON               3        /**< LED�� ҹ�俪�� */ 

/**@brief ƫ�� */
#define IMOS_MW_POLARIZER_OFF                    0        /**< ƫ�� �ر� */  
#define IMOS_MW_POLARIZER_ON                     1        /**< ƫ�� ���� */  
#define IMOS_MW_POLARIZER_AUTO                   2        /**< ƫ�� �Զ� */  

/**@brief ND�˾� */
#define IMOS_MW_ND_FILTER_OFF                    0        /**< ND�˾� �ر� */  
#define IMOS_MW_ND_FILTER_ON                     1        /**< ND�˾� ���� */  
#define IMOS_MW_ND_FILTER_AUTO                   2        /**< ND�˾� �Զ� */  

/**@brief ��о���� */
#define IMOS_MW_SENSOR_CTL_UP                    0
#define IMOS_MW_SENSOR_CTL_DOWN                  1
#define IMOS_MW_SENSOR_CTL_LEFT                  2
#define IMOS_MW_SENSOR_CTL_RIGHT                 3
#define IMOS_MW_SENSOR_CTL_ENTER                 4
#define IMOS_MW_SENSOR_CTL_ON                    5
#define IMOS_MW_SENSOR_CTL_OFF                   6

/**@brief �������� */
#define IMOS_MW_DEBUG_BOARD_TYPE                 0        /**< �����豸���� */
#define IMOS_MW_DEBUG_LENS_TYPE                  1        /**< ���þ�ͷ���� */
#define IMOS_MW_DEBUG_IQ_DEBUG                   2        /**< ���IQ debug��Ϣ */
#define IMOS_MW_DEBUG_SENSOR_OSD_CTL             4        /**< ��о���ƣ��ο�: IMOS_MW_SENSOR_CTL_XXX */
#define IMOS_MW_DEBUG_SENSOR_TYPE                5        /**< ��о���� */
#define IMOS_MW_DEBUG_DAILYREBOOT                6        /**< ÿ�ն�ʱ����,��Ӧ����:IMOS_MW_DEBUG_DAILYREBOOT_CFG_S */
#define IMOS_MW_DEBUG_CAPTURE                    11       /**< �ֶ�ǰ��ץ�ģ���Ӧ����: UCHAR(IA_PIC_FORMAL ��) */
#define IMOS_MW_DEBUG_FLASH_EXPOSURE             12       /**< �ֶ�����������  �ο�IMOS_MW_DEBUG_CAP_EXP_S */ 
#define IMOS_MW_DEBUG_LED_STROBE                 13       /**< �ֶ�����Ƶ���ƣ��ο�: #define IMOS_MW_POLARIZER_XXX */
#define IMOS_MW_DEBUG_POLARIZER                  14       /**< ����ƫ�񾵣���Ӧ����: IMOS_MW_DEBUG_POLARIZER_S */
#define IMOS_MW_DEBUG_COIL_CHECK                 15       /**< �ֶ�������Ȧ��⣬�ο�: #define IMOS_MW_COIL_CHECK_XXX */
#define IMOS_MW_DEBUG_RADAR_CHECK                16       /**< �ֶ������״��⣬�ο�: #define IMOS_MW_RADAR_CHECK_XXX */
#define IMOS_MW_DEBUG_LASER_REBOOT               17       /**< �������� */
#define IMOS_MW_DEBUG_LASER_RESTORE_DEFAULT      18       /**< ����ָ�Ĭ������ */
#define IMOS_MW_DEBUG_CAPTURE_PARA               19       /**< ����ץ������  �ο�IMOS_MW_DEBUG_CAP_EXP_S */
#define IMOS_MW_DEBUG_EP_CFG                     20       /**< ����/�羯���Բ�������(��������Ч) �ο�:IMOS_MW_DEBUG_EP_CFG_S */
#define IMOS_MW_DEBUG_EP_TMP_CFG                 21       /**< ����/�羯���Բ�������(��������Ч) �ο�:IMOS_MW_DEBUG_EP_TMP_CFG_S */
#define IMOS_MW_DEBUG_EP_TG_TYPE_CFG             22       /**< ��ǰ���л��������ڻ��ߵ羯��UCHAR���� */
#define IMOS_MW_DEBUG_PORT_CONFIG_RESUME         23       /**< port.config�ָ�Ĭ������ */
#define IMOS_MW_VAR_FN_DEFOG                     30       /**< �ɱ书������---͸����; ulImageVarPara1:͸��ȼ�(ȡֵ0,1,2,3,4,5)  ulImageVarPara2:͸��������(ȡֵ1-9) */
#define IMOS_MW_VAR_FN_EIS                       31       /**< �ɱ书������---���ӷ�������; ulImageVarPara1:����ʹ�ܷ�(ȡֵ0,1) ulImageVarPara2:����Ƶ��ֵ(��λ:HZ) */
#define IMOS_MW_DEBUG_OSD_UPDATE                 32       /**< OSD ʵʱˢ��ʹ�����ã��ο�IMOS_MW_DEBUG_OSD_UPDATE_S */
#define IMOS_MW_DEBUG_FOCUSVALUE                 34       /**< ��ȡ����������ֵ ��������: ULONG */

#define IMOS_MW_DEBUG_AF_STAT                    40       /**< AF��ʽ�ӿڣ���ȡAF���״̬���ο�IMOS_MW_DEBUG_AF_STAT_S */
#define IMOS_MW_DEBUG_AF_FV                      41       /**< AF��ʽ�ӿڣ���ȡ��ǰͼ��ͬȨ�ص�FVֵ,�ο�IMOS_MW_DEBUG_AF_S */
#define IMOS_MW_DEBUG_AF_GMAP                    42       /**< AF��ʽ�ӿڣ�������־��ӡ��ǰ�������� */
#define IMOS_MW_DEBUG_AF_CALCULATEMAP            43       /**< AF��ʽ�ӿڣ�������־��ӡָ�����0~6000cm�������� */
#define IMOS_MW_DEBUG_AF_FOCUSMODE               44       /**< AF��ʽ�ӿڣ����þ۽�ģʽ���Զ��۽�1��һ���۽�0 */
#define IMOS_MW_DEBUG_AF_DAYNIGHT                45       /**< AF��ʽ�ӿڣ����þ۽�ʱ��ҹ��������0 ҹ��1 */
#define IMOS_MW_DEBUG_AF_FOCUSTYPE               46       /**< AF��ʽ�ӿڣ����þ۽����ͣ�����ģʽ 0 �����۽�ģʽ 1 */
#define IMOS_MW_DEBUG_AF_ZPOS                    47       /**< AF��ʽ�ӿڣ����õ�ǰZOOM���λ��0~2333 */
#define IMOS_MW_DEBUG_AF_FPOS                    48       /**< AF��ʽ�ӿڣ����õ�ǰFOCUS���λ�� 0~9233 */
#define IMOS_MW_DEBUG_AF_PUSH                    49       /**< AF��ʽ�ӿڣ�����һ���۽� */
#define IMOS_MW_DEBUG_AF_ZTMAP                   50       /**< AF��ʽ�ӿڣ����ñ䱶�������� 0~6000cm */
#define IMOS_MW_DEBUG_AF_ZSPEED                  51       /**< AF��ʽ�ӿڣ����õ�ǰZOOM����ٶ� 0~7�� */
#define IMOS_MW_DEBUG_AF_FSPEED                  52       /**< AF��ʽ�ӿڣ����õ�ǰFOCUS����ٶ� 0~7�� */
#define IMOS_MW_DEBUG_AF_IRIS                    53       /**< AF��ʽ�ӿڣ����õ�ǰ��Ȧ��С 0~100 */

/**@brief �ڲ��������� */
#define IMOS_MW_DEBUG_TIME_CHANGE                1025     /**< ʱ����֪ͨ��Ϣ */

/**@brief װ���������� */
#define IMOS_MW_EQUIPMENT_TEST_IRCUTSWITCH       10       /**< װ���������� ���� IRCut���ض�Ӧ���� ULONG: 0��ʾOFF,1��ʾON */ 
#define IMOS_MW_EQUIPMENT_TEST_DEFECTPIXEL       11       /**< װ���������� ��ȡ ��Ӧ���� IMOS_MW_DEFECTPIXEL_INFO */
#define IMOS_MW_EQUIPMENT_TEST_LASERSWITCH       12       /**< װ���������� ���� ���⹦����ͣ�� ��Ӧ���� ULONG: 0��ʾOFF,1��ʾON */ 
#define IMOS_MW_EQUIPMENT_TEST_ASSISTANTFOCUS    13       /**< װ���������� ���� �����۽���ͣ�� ��Ӧ���� ULONG: 0��ʾOFF,1��ʾON */ 
#define IMOS_MW_EQUIPMENT_TEST_FPNCAPTURESWITCH  14       /**< װ���������� ���� Fpn���ݲɼ����أ� ��Ӧ���� ULONG: 0��ʾOFF,1��ʾON */ 
#define IMOS_MW_EQUIPMENT_TEST_FPNCAPTURESTATUS  15       /**< װ���������� ��ȡ Fpn���ݲɼ�״̬�� ��Ӧ���� ULONG: �ɼ����: 1 δ��ɲɼ�: 0*/                  
#define IMOS_MW_EQUIPMENT_TEST_SCENETYPE         16       /**< װ���������� ���� �������ͣ� ��Ӧ���� ULONG:ͨ��:2 �͹�:5 */
#define IMOS_MW_EQUIPMENT_TEST_DOME_IRCTRL       17       /**< װ���������� ������ƺ���ƣ� ��Ӧ����IMOS_MW_DOME_IRCTRL_S;  */
#define IMOS_MW_EQUIPMENT_TEST_FOCUSVALUE        34       /**< װ���������� ��ȡ����������ֵ ��������: ULONG */
#define IMOS_MW_EQUIPMENT_TEST_DEFAULTCFG        19       /**< װ���������� ɾ��ȫ��������Ϣ���ҹر����� ��������: ULONG ������ */

/**@brief ������������ */
#define IMOS_MW_DEBUG_MSG_GET                    0        /**< ��ȡ���� */
#define IMOS_MW_DEBUG_MSG_SET                    1        /**< ���ò��� */
#define IMOS_MW_DEBUG_MSG_DEL                    2        /**< ɾ������ */

/**@brief ������������ */
#define IMOS_MW_TEST_MSG_GET                     0        /**< ��ȡ�������� */
#define IMOS_MW_TEST_MSG_SET                     1        /**< ���ò������� */
#define IMOS_MW_TEST_MSG_DEL                     2        /**< ɾ���������� */

/* �Զ������������XP�ӿڶ��� */

/* "������Ϊ"���� */
#define IMOS_MW_AREA_DIRECTION_IN         0             /**< In */
#define IMOS_MW_AREA_DIRECTION_OUT        1             /**< Out */
#define IMOS_MW_AREA_DIRECTION_ALL        2             /**< ˫�� */
#define IMOS_MW_AREA_DIRECTION_MAX        3
#define IMOS_MW_AREA_DIRECTION_INVALID    0XFFFFFFFF


#if 0
#endif
/**************************************** �ڲ�ʹ�ö��� ***************************************/
/*@brief gsoap����endpoint���� */
#define IMOS_MW_ENDPOINT_LEN                       96  

/*@brief �û���¼���룬���Ŀ�����ܺ��ַ������� */
#define IMOS_MW_PASSWD_ENCRYPT_LEN          64  

#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_NAME       "TrafficLightTemplate.zip"  /**< ���̵�ģ��ѹ�����ļ��� */
#define IMOS_MW_TRAFFICLIGHT_TEMPLATE_PATH       "/config"                   /**< ���̵�ģ��ѹ�������·�� */

/* ������ļ����Ͷ��� */
#define MW_SDK_FILE_TYPE_EP_TRAFFICLIGHT_TEMPLATE    "EP_TrafficLight_Template"  /**< ���̵�ģ�� */
#define MW_SDK_FILE_TYPE_CONFIG_FILE                 "Config_File"               /**< �����ļ�   */
#define MW_SDK_FILE_TYPE_HCMUPGRADE_TYPE             "HCM_Upgrade"               /**< ��о�汾�ļ������ڻ�о���� */
#define MW_SDK_FILE_TYPE_INNER_CFG                   "Inner_Config"              /**< ͸������ */
#define MW_SDK_FILE_TYPE_FONT_FILE                   "Font_File"                 /**< �ֿ��ļ� */
#define MW_SDK_FILE_TYPE_CUSTOMER_FILE               "Customer_File"             /**< �ͻ�logo�ļ� */

/* ͸�������ļ����� (��ҵ��) */
#define MW_SDK_INNER_CFG_AUTOTRACK                   "AutoTrackCfg.txt"          /**< �Զ��������� */

/**************************************** ��Ƭ�ṹ ***************************************/
#define IMOS_MW_TRAFFIC_PIC_MAX_NUM                          8           /**< �����Ƭ�� */
#define IMOS_MW_UNIVIEW_MAX_TIME_LEN                         18          /**< ��Ƭ�ṹʱ����Ϣ��󳤶� */
#define IMOS_MW_PLACE_NAME_MAX_LEN                           256         /**< ��Ƭ�ṹ�ص�������󳤶� */
#define IMOS_MW_CAR_PLATE_MAX_LEN                            32          /**< ���ƺ�����󳤶� */
#define IMOS_MW_DEV_ID_MAX_LEN                               32          /**< �豸�����󳤶� */
#define IMOS_MW_TOLLGATE_NAME_MAX_LEN                        64          /**< �����豸������󳤶� */
#define IMOS_MW_DIRECTION_NAME_MAX_LEN                       64          /**< ����������󳤶� */
#define IMOS_MW_CAR_VEHICLE_BRAND_LEN                        4           /**< ���������󳤶� */


#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_DEF_H__*/

