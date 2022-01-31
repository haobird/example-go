/*******************************************************************************
 Copyright (c) 2008-2009, Hangzhou H3C Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_pub.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 2012-01-14
        Author:  
   Description: ���ļ�������sdk��ص�ö�١��ṹ��

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  2012-01-14

*******************************************************************************/
#ifndef __IMOS_SDK_PUB_H__
#define __IMOS_SDK_PUB_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

/**
 * @struct tagMwPoint
 * @brief ������
 * @attention ��
 */
typedef struct tagMwPoint
{
    ULONG ulX;        /**< ������ */
    ULONG ulY;        /**< ������ */
}IMOS_MW_POINT_S;

/**
 * @struct tagMwPoint
 * @brief ������ṹ
 * @attention ��
 */
typedef struct tagMwLine
{
    IMOS_MW_POINT_S stHead;       /**< ͷ���� */
    IMOS_MW_POINT_S stTail;       /**< β���� */
}IMOS_MW_LINE_S;

/**
 * @struct tagMwRectangle
 * @brief ���ο�����ṹ
 * @attention ��
 */
typedef struct tagMwRectangle
{
    IMOS_MW_POINT_S stTopLeft;       /**< ���Ͻ����� */
    IMOS_MW_POINT_S stBotRight;      /**< ���½����� */
}IMOS_MW_RECTANGLE_S;

/**
 * @struct tagMwQuadrangle
 * @brief �ķ��ο�����ṹ
 * @attention ��
 */
typedef struct tagMwQuadrangle
{
    IMOS_MW_POINT_S stTopLeft;       /**< ���Ͻ����� */
    IMOS_MW_POINT_S stTopRight;      /**< ���Ͻ����� */
    IMOS_MW_POINT_S stBotLeft;       /**< ���½����� */
    IMOS_MW_POINT_S stBotRight;      /**< ���½����� */
}IMOS_MW_QUADRANGLE_S;

/**
* @struct tagMwAddr
* @brief ��ַ�ṹ
* @attention 
*/
typedef struct tagMwAddr
{
    CHAR szIPAddr[IMOS_MW_IPADDR_LEN];       /**< IP��ַ */
    USHORT usPort;                           /**< �˿� */
    USHORT usReserve;                        /**< ���� */
}IMOS_MW_ADDR_S;

#if 0
#endif 
/******************************* ϵͳ���豸ά����ؽṹ ***********************************/
/**
 * @struct tagMwPlayerStatus
 * @brief ������״̬
 * @attention ��
 */ 
typedef struct tagMwPlayerStatus
{
    ULONG ulStreamHandle;           /**< ����� */
    ULONG ulErrCode;                /**< ������ */
}IMOS_MW_PLAYER_STATUS_S;


/**
 * @struct tagMwTime
 * @brief ʱ����Ϣ
 * @attention 
 */
typedef struct tagMwTime
{
    USHORT usYear;           /**< �꣬��ǰ��������2009��ʱ����ֵΪ2009�� */
    USHORT usMonth;          /**< �£���ǰ�·ݣ�1��12�� */
    USHORT usMonthDay;       /**< �գ�ÿ�µļ��ţ�1��31�� */
    USHORT usHour;           /**< ʱ����ǰСʱ����0��23�� */
    USHORT usMinute;         /**< �֣���ǰ��������0��59�� */
    USHORT usSecond;         /**< �룬��ǰ������0��60�� */
    USHORT usWeekday;        /**< �ܼ���ÿ�ܵ����ڼ���0��6����0 ��Ӧ���գ�1-6 ��Ӧ��һ �� ���� �� ��δʹ�� */
    USHORT usReserve;        /**< ���� */
}IMOS_MW_TIME_S;

/**
 * @struct tagMwSystemTimeInfo
 * @brief ϵͳ(����)ʱ��
 * @attention  lTimeZoneΪ ����ʱ������ʱ���Ĳ���� ����ʱ��UTC+8,����д 8
 */
typedef struct tagMwSystemTimeInfo
{
    LONG lTimeZone;                   /**< ����ϵͳʱ��, -12��12����Ӧ�ͱ�׼ʱ���ƫ�� */
    IMOS_MW_TIME_S stLocalTime;       /**< ����ʱ�� */
}IMOS_MW_SYSTEM_TIME_INFO_S;
/**
 * @struct tagMwUserInfo
 * @brief �û���Ϣ
 * @attention ɾ���û���Ϣʱ��ֻ�贫���û�������
 */
typedef struct tagMwUserInfo
{
    CHAR szUserName[IMOS_MW_USER_NAME_LEN + 4];           /**< �û��� */
    CHAR szPassword[IMOS_MW_USER_PASSWORD_LEN + 4];       /**< �û����� */
    ULONG ulLevel;                                        /**< �û�����, �μ�: IMOS_MW_USERLEVEL_ADMINISTRATOR �� */
}IMOS_MW_USER_INFO_S;


/**
 * @struct tagMwBasicDeviceInfo
 * @brief �豸������Ϣ
 * @attention ��
 */
typedef struct tagMwBasicDeviceInfo
{
    CHAR szManufacturer[IMOS_MW_VERSION_LEN];      /**< ���� */  
    CHAR szDeviceModel[IMOS_MW_VERSION_LEN];       /**< �豸���� */  
    CHAR szSerialNumber[IMOS_MW_VERSION_LEN];      /**< �豸���к� */  
    CHAR szDeviceMAC[IMOS_MW_VERSION_LEN];         /**< �豸MAC��ַ */
    CHAR szFirmwareVersion[IMOS_MW_VERSION_LEN];   /**< ����汾, program �汾 */  
    CHAR szHardwareID[IMOS_MW_VERSION_LEN];        /**< Ӳ����ʶ */  
    CHAR szPCBVersion[IMOS_MW_VERSION_LEN];        /**< PCB�汾 */  
    CHAR szUbootVersion[IMOS_MW_VERSION_LEN];      /**< UBOOT�����汾 */ 
}IMOS_MW_BASIC_DEVICE_INFO_S;

/**
* @struct tagMwSyslogServer
* @brief ��־������IP��ַ�Ͷ˿�
* @attention ��
*/
typedef struct tagMwSyslogServerInfo
{
    BOOL_T bEnable;                           /**< ʹ����־���� */
    CHAR szSyslogIP[IMOS_MW_IPADDR_LEN];      /**< ��־������IP��ַ */
    USHORT usPort;                            /**< ��־�����˿ں� */
    USHORT usReserve;                         /**< �����ֶΣ��ݲ�ʹ�� */
}IMOS_MW_SYSLOG_SERVER_INFO_S;

#if 0
#endif
/******************************* ������Ϣ ***********************************/
/**
 * @struct tagMwPPPoE
 * @brief PPPoE����
 * @attention ��
 */
typedef struct tagMwPPPoE
{
    CHAR szUserName[IMOS_MW_PPPOE_USERNAME_LEN + 4];     /**< PPPoE�˺� */
    CHAR szPassword[IMOS_MW_PPPOE_PASSWORD_LEN + 4];     /**< PPPoE���� */
}IMOS_MW_PPPOE_S;

/**
 * @struct tagMwUNPCfg
 * @brief UNP����
 * @attention 
 */
typedef struct tagMwUNPCfg
{
    BOOL_T bEnable;                                    /**< UNP�Ƿ�ʹ�� */
    CHAR szAddress[IMOS_MW_IPADDR_LEN];                /**< UNP server ��ַ */
    BOOL_T bIdentify;                                  /**< �Ƿ��Ȩ */
    CHAR szUserName[IMOS_MW_UNP_USERNAME_LEN + 4];     /**< UNP�ʺ� */
    CHAR szPassword[IMOS_MW_UNP_PASSWORD_LEN + 4];     /**< UNP���� */
}IMOS_MW_UNP_CFG_S;
 
/**
 * @struct tagMwNetworkInterfaceCfg
 * @brief ������Ϣ
 * @attention 
 */
typedef struct tagMwNetworkInterfaceCfg
{
    ULONG ulIPGetType;                          /**< IP��ȡ��ʽ, �μ�: IMOS_MW_IP_GET_TYPE_STATIC �� */ 
    IMOS_MW_PPPOE_S stPPPoE;                    /**< PPPoE���� */
    ULONG ulMTULen;                             /**< MTU����, IP��ȡ��ʽΪPPPoEʱ�ò�����Ч */
    CHAR szIpAddress[IMOS_MW_IPADDR_LEN];       /**< IP��ַ */
    CHAR szIpNetmask[IMOS_MW_IPADDR_LEN];       /**< �������� */
    CHAR szIpGateway[IMOS_MW_IPADDR_LEN];       /**< ���� */
    ULONG ulWorkMode;                           /**< ���ڹ���ģʽ, �μ�: IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION �� */
}IMOS_MW_NETWORK_INTERFACE_CFG_S;

/**
 * @struct tagMwNetworkInterfaceInfo
 * @brief ����״̬��Ϣ
 * @attention 
 */
typedef struct tagMwNetworkInterfaceInfo
{
    CHAR szIpAddress[IMOS_MW_IPADDR_LEN];       /**< IP��ַ */
    CHAR szIpNetmask[IMOS_MW_IPADDR_LEN];       /**< �������� */
    CHAR szIpGateway[IMOS_MW_IPADDR_LEN];       /**< ���� */
    ULONG ulType;                               /**< Ŀǰʹ�����ڵ����ͣ��μ�: IMOS_MW_PORT_MODE_ELECTRONIC �� */
    ULONG ulWorkMode;                           /**< ���ڵ�ǰ����ģʽ, �μ�: IMOS_MW_ETH_WORKMODE_AUTO_NEGOTIATION �� */
}IMOS_MW_NETWORK_INTERFACE_INFO_S;

#if 0
#endif

/*************************** ͼ����ؽṹ ****************************************/
/**
 * @struct tagMwSharpness
 * @brief ��Ȳ��� 
 * @attention
 */
typedef struct tagMwSharpness
{
    ULONG ulMode;              /**< ���ģʽ, �μ�: IMOS_MW_SHARPNESS_AUTO �� */
    ULONG ulSharpness;         /**< ���ֵ */
}IMOS_MW_SHARPNESS_S;

/**
 * @struct tagMwDenoise
 * @brief ͼ���� 
 * @attention ��
 */
typedef struct tagMwDenoise
{
    ULONG ul2DLevel;           /**< 2D����ȼ� */
    ULONG ul3DLevel;           /**< 3D����ȼ� */
}IMOS_MW_DENOISE_S;

/**
 * @struct tagMwWhiteBalance
 * @brief ��ƽ����� 
 * @attention
 */
typedef struct tagMwWhiteBalance
{
    ULONG ulMode;                           /**< ��ƽ��ģʽ, �μ�: IMOS_MW_WB_AUTO �� */
    LONG lBlueOffset;                       /**< ��ɫƫ���� */
    LONG lRedOffset;                        /**< ��ɫƫ���� */
}IMOS_MW_WHITE_BALANCE_S;

/**
 * @struct tagMwImageEnhance
 * @brief ͼ����ǿ���� 
 * @attention 
 */
typedef struct tagMwImageEnhance
{
    ULONG ulBrightness;                     /**< ���� */
    ULONG ulContrast;                       /**< �Աȶ� */
    ULONG ulSaturation;                     /**< ���Ͷ� */
    ULONG ulHue;                            /**< ɫ�� */
    IMOS_MW_SHARPNESS_S stSharpness;        /**< ��Ȳ��� */
    IMOS_MW_DENOISE_S stDenoise;            /**< ������� */
    ULONG ulMirrorMode;                     /**< ����ģʽ, �μ�: IMOS_MW_MIRROR_MODE_NONE �� */
}IMOS_MW_IMAGE_ENHANCE_S;

/**
 * @struct tagMwFocus
 * @brief �Խ����� 
 * @attention 
 */
typedef struct tagMwFocus
{
    ULONG ulFocusMode;                       /**< �Խ�ģʽ, �μ�: IMOS_MW_FOCUS_AUTO �� */
    ULONG ulAutoFocusSense;                  /**< �Զ��Խ������� */
    ULONG ulManualFocusMinDistance;          /**< ��С�Խ����룬�ֶ��Խ�, ��λ: ���� */
}IMOS_MW_FOCUS_S;


/**
 * @struct tagMwWhiteBalanceCfg
 * @brief ��ƽ���������
 * @attention 
 */
typedef struct tagMwWhiteBalanceCfg
{
    ULONG ulImageType;                         /**< ͼ������, �μ�: IMOS_MW_IMAGE_TYPE_VIDEO �� */
    IMOS_MW_WHITE_BALANCE_S stWhiteBalance;    /**< ��ƽ����� */
}IMOS_MW_WHITE_BALANCE_CFG_S;

/**
 * @struct tagMwImageEnhanceCfg
 * @brief ͼ����ǿ��������
 * @attention 
 */
typedef struct tagMwImageEnhanceCfg
{
    ULONG ulImageType;                         /**< ͼ������, �μ�: IMOS_MW_IMAGE_TYPE_VIDEO �� */
    IMOS_MW_IMAGE_ENHANCE_S stImageEnhance;    /**< ͼ����ǿ���� */
}IMOS_MW_IMAGE_ENHANCE_CFG_S;

/**
 * @struct tagMwImageEnhanceCfg
 * @brief �Խ���������
 * @attention 
 */
typedef struct tagMwFocusCfg
{
    ULONG ulImageType;                         /**< ͼ������, �μ�: IMOS_MW_IMAGE_TYPE_VIDEO �� */
    IMOS_MW_FOCUS_S stFocus;                   /**< �Խ����� */
}IMOS_MW_FOCUS_CFG_S;

/**
 * @struct tagMwConditionCfgEx
 * @brief ���� ��������
 * @attention
 */
typedef struct tagMwConditionCfgEx
{
    ULONG ulType;              /**< �����������ͣ��μ�: IMOS_MW_CONDITION_ILLUMINATION �� */
    LONG lParam1;              /**< ��������1 */
    LONG lParam2;              /**< ��������2 */
    LONG lParam3;              /**< ��������3 */
}IMOS_MW_CONDITION_CFG_EX_S;

#if 0
#endif
/*************************** OSD ��ؽṹ ****************************************/
/**
 * @struct tagMwOSDInfoParam
 * @brief OSD ��������
 * @attention ��
 */
typedef struct tagMwOSDInfoParam
{
    ULONG ulInfoType;                              /**< �����������ͣ��ο�: IMOS_MW_OSD_INFO_TYPE_UNUSED �� */
    CHAR szValue[IMOS_MW_OSD_INFO_LEN + 4];        /**< �Զ��� OSD ���� */ 
}IMOS_MW_OSD_INFO_PARAM_S;

/**
* @struct tagMwOSDInfoConf
* @brief ����OSD ����
* @attention ��
*/
typedef struct tagMwOSDInfoConf
{
    ULONG ulIndex;                                                       /**< ��������ID */
    BOOL_T bEnable;                                                      /**< ʹ�ܿ��� */ 
    IMOS_MW_OSD_INFO_PARAM_S astInfoParam[IMOS_MW_INFO_OSD_LINE_MAX];    /**< �������� */  
    IMOS_MW_RECTANGLE_S stArea;                                          /**< �������� */
}IMOS_MW_INFO_OSD_S;

/**
* @struct tagMwInfoOSDCfg
* @brief ����OSD ����
* @attention ɾ��������ʱ��ֻ��ָ����ɾ�������ID
*/
typedef struct tagMwInfoOSDCfg
{
    ULONG ulAreaNum;                        /**< ����������� */
    IMOS_MW_INFO_OSD_S astInfoOSD[1];       /**< ����OSD ���ã�����������Ϊ: IMOS_MW_INFO_OSD_MAX_NUM */
}IMOS_MW_INFO_OSD_CFG_S;

/**
* @struct tagMwOSDStyleCfg
* @brief ����OSD ��ʽ
* @attention ��
*/
typedef struct tagMwOSDStyleCfg
{
    ULONG ulFontStyle;     /**< ������ʽ, �μ�: IMOS_MW_OSD_FONT_STYLE_NORMAL �� */
    ULONG ulFontSize;      /**< �����С, �μ�: IMOS_MW_OSD_FONT_SIZE_LARGE �� */
    ULONG ulFontType;      /**< ����, �ݲ�֧������ */
    ULONG ulColor;         /**< ��ɫ, �μ�: IMOS_MW_OSD_COLOR_WHITE �� */
    ULONG ulAlpha;         /**< ͸����, �μ�: IMOS_MW_OSD_ALPHA_NO �� */
    ULONG ulTimeFormat;    /**< ʱ���ʽ, �μ�: IMOS_MW_TIME_FORMAT_HHMMSS �� */
    ULONG ulDateFormat;    /**< ���ڸ�ʽ, �μ�: IMOS_MW_DATE_FORMAT_YYYYMMDD �� */
}IMOS_MW_OSD_STYLE_CFG_S;

#if 0
#endif
/******************************* ý������ؽṹ ***********************************/
/**
 * @struct tagMwResolution
 * @brief �ֱ���
 * @attention 
 */
typedef struct tagMwResolution
{
    ULONG ulWidth;           /**< ����λ: ���� */
    ULONG ulHeight;          /**< �ߣ���λ: ���� */
}IMOS_MW_RESOLUTION_S;

/**
 * @struct tagMwVideoInModeCfg
 * @brief �ɼ���ʽ
 * @attention 
 */
typedef struct tagMwVideoInModeCfg
{
    IMOS_MW_RESOLUTION_S stResolution;    /**< �ɼ��ֱ��� */ 
    ULONG ulFrameRate;                    /**< �ɼ�֡�� */
}IMOS_MW_VIDEOIN_MODE_CFG_S;

/**
 * @struct tagMwVideoStreamConf
 * @brief ��Ƶ�������
 * @attention 
 */
typedef struct tagMwVideoStreamConf
{
    BOOL_T bIsEnable;                              /**< ����/�رձ��� 0-�ر� 1-���� */
    ULONG ulEncodeFmt;                             /**< �����ʽ���μ�: IMOS_MW_STREAM_FORMAT_MPEG1 �� */
    IMOS_MW_RESOLUTION_S stResolution;             /**< ����ֱ��� */ 
    ULONG ulBitRate;                               /**< ���� */
    ULONG ulFrameRate;                             /**< ֡�� */ 
    ULONG ulGopType;                               /**< gop�ṹ����, �ο�: IMOS_MW_GOP_TYPE_IP �� */  
    ULONG ulIInterval;                             /**< I֡��� */
    ULONG ulEncMode;                               /**< ����ģʽ���μ�: IMOS_MW_ENCODE_MODE_CBR �� */ 
    ULONG ulQuality;                               /**< ����ѹ������ */
    ULONG ulSmoothValue;                           /**< ����ƽ�� */                            
}IMOS_MW_VIDEO_STREAM_CONF_S;

/**
 * @struct tagMwVideoEncoderCfg
 * @brief ��Ƶ�����������
 * @attention ��ȡָ�����ı������ʱ����Ҫ������ID
 */
typedef struct tagMwVideoEncoderCfg
{
    ULONG ulStreamID;                              /**< ��ID, �μ�: IMOS_MW_STREAM_ID_MAIN �� */
    IMOS_MW_VIDEO_STREAM_CONF_S stVideoStreamCfg;  /**< ��Ƶ������� */
}IMOS_MW_VIDEO_ENCODER_CFG_S;

/**
 * @enum tagMwMediaStreamInfo
 * @brief ý������Ϣ
 * @attention ��
 */
typedef struct tagMwMediaStreamInfo
{
    ULONG ulStreamHandle;                         /**< ����� */
    ULONG ulStreamID;                             /**< ��ID, �μ�: IMOS_MW_STREAM_ID_MAIN �� */
    ULONG ulTransMode;                            /**< ����ģʽ���μ�: IMOS_MW_TRANSFER_MODE_RTP_UDP �� */
    CHAR szIPAddr[IMOS_MW_IPADDR_LEN];            /**< ��Ŀ��IP��ַ */
    USHORT usPort;                                /**< ��Ŀ�Ķ˿� */
    USHORT usReserved;                            /**< ���� */
    ULONG ulMediaType;                            /**< ý������, �μ�: IMOS_MW_MEDIA_VIDEO �� */
    CHAR szUser[IMOS_MW_NAME_LEN];                /**< �������� */
}IMOS_MW_VIDEO_STREAM_INFO_S;

/**
* @struct tagMwVideoParam
* @brief ��Ƶ�������
* @attention ��
*/
typedef struct tagMwVideoParam
{
    ULONG ulFrameRate;       /**< ֡��, ��λ: fps */
    ULONG ulBitRate;         /**< ����, ��λ: bps */
    ULONG ulRecvPktNum;      /**< �ѽ��յ����� */
    ULONG ulLostPktNum;      /**< �������� */
    ULONG ulAllFrameNum;     /**< ֡���� */
    ULONG ulLostFrameNum;    /**< ������֡�� */
}IMOS_MW_VIDEO_PARAM_S;

#if 0
#endif
/******************************* �洢(����)��ؽṹ ***********************************/
/**
* @struct tagMwLocalPicStor
* @brief ����SD��ץ�Ĵ洢������Ϣ
* @attention 
*/
typedef struct tagMwLocalPicStor
{   
    ULONG ulAllocPercent;                       /**< ���������ٷֱȣ���λ %��Ĭ��0, �����ݲ�ʹ�ã����治��ʾ */ 
    ULONG ulAllocMemory;                        /**< ��������, ��λ: MB */
    ULONG ulSpareMemory;                        /**< ʣ������, ��λ: MB */             
    ULONG ulCurrentFileNum;                     /**< ��ǰ�ļ����� */                  
    ULONG ulSpareFileNum;                       /**< ʣ��ɴ��ļ����� */    
    ULONG ulStorPolicy;                         /**< �洢���� �μ�: IMOS_MW_STOR_POLICY_XXX */
    ULONG ulStorMode;                           /**< SD���洢ģʽ �μ�: IMOS_MW_LOCAL_STOR_XXX */
}IMOS_MW_LOCAL_PIC_STORCFG_S;

/**
* @struct tagMwLocalVideoStor
* @brief ����SD����Ƶ�洢������Ϣ
* @attention 
*/
typedef struct tagMwLocalVideoStor
{   
    ULONG ulAllocPercent;                       /**< ���������ٷֱȣ���λ %��Ĭ��0, �����ݲ�ʹ�ã����治��ʾ */ 
    ULONG ulAllocMemory;                        /**< ��������, ��λ: MB */
    ULONG ulPlanStreamID;                       /**< �ƻ��� ��ID */
    ULONG ulManualStreamID;                     /**< �ֶ��� ��ID */
    ULONG ulEventStreamID;                      /**< �¼��� ��ID */
    ULONG ulStorPolicy;                         /**< �洢���� �μ�: IMOS_MW_STOR_POLICY_XXX */
    ULONG ulStorMode;                           /**< SD���洢ģʽ �μ�: IMOS_MW_LOCAL_STOR_XXX */
}IMOS_MW_LOCAL_VIDEO_STORCFG_S;

/**
* @struct tagMwLocalStorInfo
* @brief ����SD ���洢
* @attention 
*/
typedef struct tagMwLocalStorInfo
{       
    ULONG ulTotalMemory;                             /**< ���ش洢��������SD��������, ��λ: MB */
    IMOS_MW_LOCAL_PIC_STORCFG_S stPicStorCfg;        /**< SD��ץ��ͼƬ�洢���� */  
    IMOS_MW_LOCAL_VIDEO_STORCFG_S stVideoStorCfg;    /**< SD����Ƶ�洢���� */  
}IMOS_MW_LOCAL_STOR_INFO_S;

/**
* @struct tagMwLocalStorPicInfo
* @brief SD ���ļ���Ϣ
* @attention 
*/
typedef struct tagMwStorLocalPicInfo
{
     CHAR stFile[IMOS_MW_NAME_LEN];          /**< �ļ�ID, �����ļ�ID ���Ȳ����� IMOS_MW_FILE_NAME_LEN */
     IMOS_MW_TIME_S stTime;                  /**< ʱ��(������ʱ����) */
     CHAR szPictureInfo[IMOS_MW_NAME_LEN];   /**< ���ƺ�(����) */
}IMOS_MW_STOR_LOCAL_PIC_INFO_S;

/**
* @struct tagMwStorLocalVideo
* @brief ����SD �� ¼���ļ�
* @attention ��
*/
typedef struct tagMwStorLocalVideo
{
    CHAR szFile[IMOS_MW_FILE_NAME_LEN];      /**< ¼���ļ�ID */ 
    ULONG ulFileSize;                        /**< ¼���ļ���С */ 
    IMOS_MW_TIME_S stSartTime;               /**< ¼���ļ���ʼʱ�� */ 
    IMOS_MW_TIME_S stEndTime;                /**< ¼���ļ�����ʱ�� */ 
}IMOS_MW_STOR_LOCAL_VIDEO_S;

/**
* @struct tagMwStorPathInfo
* @brief �洢·��
* @attention ��
*/
typedef struct tagMwStorPathInfo
{
    CHAR szName[IMOS_MW_DEFAULT_PATH_LEN];       /**< Ŀ¼/�ļ� ������ */
    ULONG ulDirType;                             /**< ·������: Ŀ¼/�ļ�, �μ�: IMOS_MW_STOR_PATH_DIR �� */
    ULONG ulStorFileType;                        /**< �ļ�����: ��Ƭ/¼��, �μ�: IMOS_MW_STOR_FILE_TYPE_VIDEO �� */
}IMOS_MW_STOR_PATH_INFO_S;

#if 0
#endif
/******************************* ��������ؽṹ ***********************************/
/**
* @struct tagMwPhotoServerCfg
* @brief ��Ƭ���շ���������
* @attention 
*/
typedef struct tagMwPhotoServerCfg
{
    ULONG ulProtocol;                                               /**< ͨ��Э������ */
    CHAR szCameraID[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];              /**< ������ */
    CHAR szTollgateID[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];            /**< ���ڱ�� */
    CHAR szDrivewayID[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];            /**< ��·��� */
    CHAR szDirectionID[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];           /**< ������ */
    CHAR szDeviceID[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];              /**< �豸��� */
    CHAR szPassword[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];              /**< ƽ̨�������� */
    CHAR szUserName[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];              /**< ����ƽ̨�û��� */
    CHAR szServerPassword[IMOS_MW_PHOTOSERVER_CODE_LEN + 4];        /**< ����ƽ̨���� */
    IMOS_MW_ADDR_S stServerAddr;                                    /**< ��Ƭ��������ַ */
}IMOS_MW_PHOTO_SERVER_CFG_S;


/**
 * @struct tagMwUniviewMultiProtocolHeader
 * @brief ����Э����Ϣͷ,������Ƭ
 * @attention ����ӿ�
 */
typedef struct tagMwUniviewMultiProtocolHeader
{
    CHAR *apcData[IMOS_MW_TRAFFIC_PIC_MAX_NUM];                                         /**< ����ָ�� */
    ULONG aulDataLen[IMOS_MW_TRAFFIC_PIC_MAX_NUM];                                      /**< ���ݳ��� */
    ULONG aulPicType[IMOS_MW_TRAFFIC_PIC_MAX_NUM];                                      /**< ��Ƭ����, ����:IMOS_MW_IMAGE_VEHICLE */
    CHAR acPassTime[IMOS_MW_TRAFFIC_PIC_MAX_NUM][IMOS_MW_UNIVIEW_MAX_TIME_LEN];         /**< ����ʱ�� */
    ULONG ulPicNumber;                                                                  /**< ��Ƭ���� */

    /* �豸��Ϣ */ 
    LONG lApplicationType;                                        /**< Ӧ������:��Ӧ��ز�Ʒ */ 
    CHAR szCamID[IMOS_MW_DEV_ID_MAX_LEN];                         /**< �豸���:�ɼ��豸ͳһ��Ż򿨿��������, ����Ϊ�� */ 
    CHAR szTollgateID[IMOS_MW_DEV_ID_MAX_LEN];                    /**< ���ڱ��:��������Ϣ�Ŀ��ڴ��� */ 
    CHAR szTollgateName[IMOS_MW_TOLLGATE_NAME_MAX_LEN];           /**< ��������:��ѡ�ֶ� */ 
    
    ULONG ulCameraType;                                        /**< ������� 0 ȫ�� 1���� */ 
    ULONG ulRecordID;                                          /**<������Ϣ���:��1��ʼ�Զ�����(ת�����ַ���Ҫ�󲻳���16�ֽ�) */ 

    /* ʱ�䡢�ص���Ϣ */ 
    CHAR szPassTime[IMOS_MW_UNIVIEW_MAX_TIME_LEN];               /**< ����ʱ��:YYYYMMDDHHMMSS, ʱ�䰴24Сʱ�� */ 
    CHAR szPlaceName[IMOS_MW_PLACE_NAME_MAX_LEN];                /**< �ص����� */ 

    LONG lLaneID;                /**< �������:��1��ʼ, ������ʻ�������󳵵�Ϊ1����������˳���� */ 
    LONG lLaneType;             /**< ��������:0-����������1-�ǻ������� */ 

    /**< ������:1-������ 2-���� 3-���� 4-������ 
       5-���������� 6-�������� 7-���������� 8-�����򶫱� */ 
    LONG lDirection; 
    CHAR szDirectionName[IMOS_MW_DIRECTION_NAME_MAX_LEN];       /**< ��������:��ѡ�ֶ� */ 
    
    /* ������Ϣ */ 
    CHAR szCarPlate[IMOS_MW_CAR_PLATE_MAX_LEN];              /**< ���ƺ���:�����Զ�ʶ�����"-"��ʾ */ 
    ULONG aulLPRRect[4];                                     /**< ��������:XL=a[0], YL=a[1], XR=a[2], YR=a[3] */ 
    LONG lPlateType;                                         /**< ��������:��GA24.7���� */   
    LONG lPlateColor;                                        /**< ������ɫ:0-��ɫ1-��ɫ 2-��ɫ 3-��ɫ 4-���� */ 
    LONG lPlateNumber;                                       /**< �������� */   
    
    /**< ����һ��: 
       0-��ͷ�ͳ�β���ƺ��벻һ�� 
       1-��ͷ�ͳ�β���ƺ�����ȫһ�� 
       2-��ͷ���ƺ����޷��Զ�ʶ�� 
       3-��β���ƺ����޷��Զ�ʶ�� 
       4-��ͷ�ͳ�β���ƺ�����޷��Զ�ʶ�� */ 
    LONG lPlateCoincide;     
    CHAR szRearVehiclePlateID[IMOS_MW_CAR_PLATE_MAX_LEN];   /**< β�����ƺ���:����س�����β���ƺ��룬������β�����ƺ��벻ȫ�������Զ�ʶ�����"-"��ʾ */ 
    LONG lRearPlateColor;                                   /**< β��������ɫ: 0-��ɫ1-��ɫ 2-��ɫ 3-��ɫ 4-���� */ 
    LONG lRearPlateType;                                    /**< β����������: ��GA24.7����; ����1������ 2���侯 3������ 4��˫�� 5������ */ 

    /**< ������Ϣ */     
    ULONG aulVehicleXY[4];                                 /**< ��������:XL=a[0], YL=a[1], XR=a[2], YR=a[3] */ 
    CHAR szVehicleBrand[IMOS_MW_CAR_VEHICLE_BRAND_LEN];    /**< �������Ʊ���(���б���) ���ǵ��ֽڶ��붨�峤��Ϊ4��ʵ��ʹ�ó���Ϊ2 */ 
    LONG lVehicleBody;                                     /**< �������ͱ���(���б���) */ 
    LONG lVehicleType;                                     /**< �������� 0-δ֪��1-С�ͳ� 2-���ͳ� 3-���ͳ� 4-���� */ 
    LONG lVehicleLength;                                   /**< ��������(������Ϊ��λ) */ 
    LONG lVehicleColorDept;                                /**< ������ɫ��ǳ:0-δ֪��1-ǳ��2-�� */ 
    /**< ������ɫ: 
       A���ף�B���ң�C���ƣ�D���ۣ�E���죬F���ϣ�G���̣�H������ 
       I���أ�J���ڣ�K���ȣ�L���࣬M������N�����ף�Z������(!) */ 
    CHAR cVehicleColor;            /* ������ɫ */ 

    /* ʶ��ע:�����UCHAR����CHAR */ 
    UCHAR ucPlateScore;            /**< �˴�ʶ���У����Ƶ����Ŷȣ�100��� */ 
    UCHAR ucRearPlateScore;        /**< β���������Ŷȣ�100��� */ 
    UCHAR ucPicType;               /**< 0:ʵʱ��Ƭ��1:��ʷ��Ƭ */ 
    LONG lIdentifyStatus;          /**< ʶ��״̬:0��ʶ��ɹ� 1�����ɹ� 2��������(!)  3-��ʾ��Ҫƽ̨ʶ�� */ 
    LONG lIdentifyTime;            /**< ʶ��ʱ��, ��λ���� */       
    LONG lDressColor;              /**< ����������ɫ(!) */     
    LONG lDealTag;                 /**< ������:0-��ʼ״̬δУ�� 1-��У�Ժͱ��� 2-��Ч��Ϣ 3-�Ѵ���ͱ���(!) */ 

    /* ���� */ 
    LONG lVehicleSpeed;            /**< �����ٶ�: ��λkm/h, -1-�޲��ٹ��� */ 
    LONG lLimitedSpeed;            /**< ִ������: ��������, ��λkm/h */ 
    LONG lMarkedSpeed;             /**< ��ʶ���� */     
    LONG lDriveStatus;             /**< ��ʻ״̬:0-���� 1-���ɻ�GA408.1���� */ 

    /**< �����Ϣ */ 
    LONG lRedLightTime;                                   /**< ���ʱ�� */ 
    CHAR szRedLightStartTime[IMOS_MW_UNIVIEW_MAX_TIME_LEN];  /**< ��ƿ�ʼʱ��:YYYYMMDDHHMMSS, ��ȷ������, ʱ�䰴24Сʱ�� */ 
    CHAR szRedLightEndTime[IMOS_MW_UNIVIEW_MAX_TIME_LEN];    /**< ��ƽ���ʱ��:YYYYMMDDHHMMSS, ��ȷ������, ʱ�䰴24Сʱ�� */   
}IMOS_MW_MULTI_UNIVIEW_PROTOCOL_HEADER_S;

/******************************************************************************
��ʶ��IMOS_MW_ONE_PIC_INFO_S
���ͣ��ṹ��
Ŀ�ģ�������Ƭ��Ϣ
���壺
******************************************************************************/ 
typedef struct tagMwOnePicInfo
{
    VOID *pPicData;                         /* ͼ������:1-������ͼ 2-���Ʋ�ɫСͼ 3-���ƶ�ֵ��ͼ */
    ULONG ulPicLen;                         /* ͼƬ���� */
}IMOS_MW_SINGLE_PIC_INFO_S;

/**
 * @struct tagMwPicData
 * @brief  ��Ƭ����
 * @attention ����ӿ�
 */
typedef struct tagMwPicData
{
    ULONG ulPicNum;                                                    /* ��Ƭ���� */
    IMOS_MW_SINGLE_PIC_INFO_S astPicInfo[IMOS_MW_TRAFFIC_PIC_MAX_NUM];    /* ��Ƭ��Ϣ */
}IMOS_MW_PIC_INFO_S;

/**
 * @struct tagMwDeviceRunInfo
 * @brief �豸����״̬ (ϵͳ����ʱ�䣬�豸�¶ȣ�CPUʹ���ʣ��ڴ�ʹ����)
 * @attention ��
 */
typedef struct tagMwDeviceRunInfo
{
    ULONG ulRunTime;                 /**< �豸����ʱ�� */
    LONG lDeviceTemperature;         /**< �豸�¶� */
    ULONG ulCPUUtilization;          /**< CPUʹ���� */
    ULONG ulMemUtilization;          /**< �ڴ�ʹ���� */
}IMOS_MW_DEVICE_RUN_INFO_S;

/**
 * @struct tagMwTransPortCfg
 * @brief ͸��ͨ������
 * @attention
 */
typedef struct tagMwTransPortCfg
{
    ULONG ulSerialID;               /**< ����ID (���������������) */
    ULONG ulEnable;                 /**< ʹ��͸��ͨ��: 0 ������, 1 ���� */
    ULONG ulTransMode;              /**< ����ģʽ���ݲ�֧�֣�������չ: UDP/TCP �� */
    IMOS_MW_ADDR_S stPeerAddr;      /**< Զ�˵�ַ */
    IMOS_MW_ADDR_S stLocalAddr;     /**< ���˵�ַ */
}IMOS_MW_TRANSPORT_CFG_S;

/**
* @struct tagMwSingTransPortCfg
* @brief ��͸��ͨ������
* @attention
*/
typedef struct tagMwSingTransPortCfg
{
    ULONG ulChannelID;                             /**< ͸��ͨ���� */   
    IMOS_MW_TRANSPORT_CFG_S stTransPortCfg;        /**< ͸��ͨ������ */
}IMOS_MW_SING_TRANSPORT_CFG_S;

/**
* @struct tagMwMultiTransPortCfg
* @brief ��͸��ͨ������
* @attention
*/
typedef struct tagMwMultiTransPortCfg
{
    ULONG ulTransPortNum;                                                           /**< ͸��ͨ���� */   
    IMOS_MW_SING_TRANSPORT_CFG_S astSingTransPortCfg[IMOS_MW_SERIAL_MAX_NUM];       /**< ��͸��ͨ������ */
}IMOS_MW_MULTI_TRANSPORT_CFG_S;

/**
 * @struct tagMwTrParam
 * @brief ��ͨ�������
 * @attention
 */
typedef struct tagMwTrParam
{
    ULONG ulLaneID;                  /**< ������� */
    ULONG ulTrafficFlow;             /**< �������� */
    ULONG ulAveSpeed;                /**< ƽ���ٶȣ���λ:ǧ��/Сʱ */
    FLOAT fAveHeadTime;              /**< ƽ����ͷʱ�࣬��λ:�� */
    FLOAT fAveTimOcupyRat;           /**< ƽ������ʱ��ռ����,����λ:X100% */
    FLOAT fAveHeadSpac;              /**< ƽ����ͷ��࣬��λ:�� */
    FLOAT fVehQueueLen;              /**< �������г��ȣ���λ:�� */
    FLOAT fAveSpaOcupyRat;           /**< ƽ�������ռ�ռ����,����λ:X100% */
    ULONG ulWayStat;                 /**< ����ͨ��״̬����Ϊ����ȼ�����:ӵ�£�ͨ���� */
    ULONG aulCarTypeCount[IMOS_MW_CAR_TYPE_NUM];      /**< ���ֳ������͵ĳ����� 0-11�ֱ����γ���SUV���������С������
                                                           �аͳ�����ͳ�������������ͳ������ͳ���С�ͳ���Ħ�г��������� */ 
    ULONG aulLPRColorCount[IMOS_MW_LPR_COLOR_NUM];    /**< ���ֳ������͵ĳ����� 0-4 ���ơ����ơ����ơ����ơ����� */
    ULONG aulSpeedCarCount[IMOS_MW_CAR_SPEED_NUM];    /**< ������ͳ�� 0 �����٣�1�������  δʵ�� */
    ULONG ulVehicles;                                 /**< ͨ���������� �� δʵ�� */
    ULONG ulVehicleLength;                            /**< �������� ��λ:���� δʵ�� */
    ULONG ulDensity;                                  /**< �����ܶ� ÿ����ĳ���������λ��/km δʵ�� */
    ULONG ulVolume;                                   /**< ��ͨ�� ��/��λʱ�� δʵ�� */
    ULONG ulFlowRate;                                 /**< ���� ��/Сʱ δʵ�� */
    ULONG ulBackOfQueue;                              /**< ����ʱ�� �� δʵ�� */
    ULONG ulDelay;                                    /**< ���� �� δʵ�� */
}IMOS_MW_TRAFFIC_PARA_S;

/**
 * @struct tagMwTrParamRes
 * @brief ����������ͨ�������
 * @attention
 */
typedef struct tagMwTrParamRes
{
    CHAR szStartTime[IMOS_MW_UNIVIEW_MAX_TIME_LEN];                     /* ��ʼʱ�� YYYYMMDDhhmmss*/
    ULONG ulDriveWayNum;                                                /* ʵ�����õĳ����� */    
    IMOS_MW_TRAFFIC_PARA_S astTrParaRslt[IMOS_MW_DRIVEWAY_NUM_MAX];     /* ��������ͨ����������� */
}IMOS_MW_TRAFFIC_PARA_RSLT_S;

/**
 * @enum tagMwEpTgVehicleStat
 * @brief ��������״̬
 * @attention
 */
typedef enum tagMwEpTgVehicleStat
{
    VEHICLE_STAT_INVALID          = -1,          /* ����״̬δ�仯 */
    VEHICLE_STAT_NONE             = 0,           /* ������ʼ״̬ */
    VEHICLE_STAT_IN_LINE          = 1,           /* ����������� */
}IMOS_MW_TRAFFIC_VEHICLE_STAT_E;

/**
 * @struct tagMwVehicleState
 * @brief ����������������״̬
 * @attention
 */
typedef struct tagMwVehicleState
{
    ULONG ulDriveWayNum;                                                         /* ʵ�����õĳ����� */
    CHAR szStatPassTime[IMOS_MW_UNIVIEW_MAX_TIME_LEN];                           /* ͨ��ʱ�� YYYYMMDDHHMMSSMMM */
    IMOS_MW_TRAFFIC_VEHICLE_STAT_E aenVehicleState[IMOS_MW_DRIVEWAY_NUM_MAX];    /* ��������������״̬ */
    ULONG aulDriveWayCode[IMOS_MW_DRIVEWAY_NUM_MAX];                             /* ������������ */
}IMOS_MW_VEHICLE_STATE_S;

/**
* @struct tagMwParkStatus
* @brief ��λ״̬��Ϣ
* @attention
*/
typedef struct tagMwParkStatus
{
    CHAR szCamID[IMOS_MW_DEV_ID_MAX_LEN];                   /**< ������ */
    LONG lParkID;                                           /**< ��λ��� */
    CHAR szSampleTime[IMOS_MW_UNIVIEW_MAX_TIME_LEN];        /**< ����ʱ��:YYYYMMDDHHMMSS, ʱ�䰴24Сʱ�� */
    CHAR cReserved[2];                                      /**< �����ֶ� �ֽڶ����� */
    LONG lParkingLotStatus;                                 /**< ��λ״̬��0�޳���1�г���2ʶ���쳣 */
    CHAR szCarPlate[IMOS_MW_CAR_PLATE_MAX_LEN];             /**< ���ƺ���:�����Զ�ʶ�����"-"��ʾ����λ�޳�ʱ���Ը��ֶ� */
    LONG lLEDStatus;                                        /**< ��λָʾ��״̬ 0Ϩ��1������2������˸��3������˸ */
    LONG lLEDColor;                                         /**< ��λָʾ����ɫ 1��ɫ��2��ɫ��3��ɫ */
    LONG lCrossAlarm;                                       /**< �糵λ�澯 0δ�糵λ��1�糵λ */
}IMOS_MW_PARK_STATUS_S;

/**
* @struct tagMwParkStatusEx
* @brief ��λ״̬��Ϣ(NEW-��չ)
* @attention
*/
typedef struct tagMwParkStatusEx
{
    CHAR szAreaDesc[IMOS_MW_NAME_LEN];                      /**< ��λ�������� */
    CHAR szCustomSpaceDescID[IMOS_MW_NAME_LEN];             /**< �Զ��峵λ�� */             
    IMOS_MW_PARK_STATUS_S stParkStatus;                     /**< ��λ״̬��Ϣ */
    CHAR cReserved[32];                                    /**< �����ֶ� ���ڽӿ���չ */
}IMOS_MW_PARK_STATUS_EX_S;


/**
 * @struct tagMwDayNight
 * @brief ��ҹģʽ����
 * @attention
 */
typedef struct tagMwDayNight
{
    ULONG ulMode;              /**< ��ҹģʽ, �μ�: IMOS_MW_DAYNIGHT_AUTO �� */
    ULONG ulSensitivity;       /**< �л������� */
}IMOS_MW_DAYNIGHT_S;

/**
 * @struct tagMwMetering
 * @brief ������
 * @attention
 */
typedef struct tagMwMetering
{
    ULONG ulMode;                  /**< ���ģʽ, �μ�: IMOS_MW_METERING_CENTER �� */
    IMOS_MW_RECTANGLE_S stArea;    /**< ������� */
    ULONG ulRefBrightness;         /**< �ο����� */
    ULONG ulHoldTime;              /**< ����ʱ�� */
}IMOS_MW_METERING_S;

/**
 * @struct tagMwImgWDR
 * @brief ��̬����
 * @attention
 */
typedef struct tagMwImgWDR
{
    ULONG ulMode;              /**< ��̬ģʽ, �μ�: IMOS_MW_WDR_DISABLE �� */
    ULONG ulExpRatio;          /**< �ع���ʣ��ݲ�֧�� */
    ULONG ulOnSense;           /**< ��̬���������� */
    ULONG ulOffSense;          /**< ��̬�ر������� */
    BOOL_T bAntiFlicker;       /**< ��̬�������� */
}MW_WDR_S;

/**
 * @struct tagMwSlowShutter
 * @brief ������
 * @attention ��
 */
typedef struct tagMwSlowShutter
{
    BOOL_T bEnable;                         /**< ������ʹ���� */
    ULONG ulMaxSlowShutter;                 /**< ���������� */
}IMOS_MW_SLOW_SHUTTER_S;

/**
 * @struct tagMwCustomExposure
 * @brief �Զ����ع����
 * @attention ��
 */
typedef struct tagMwCustomExposure
{
    ULONG ulMaxIris;                        /**< ����Ȧ, ��λ: fֵ*100 */
    ULONG ulMinIris;                        /**< ��С��Ȧ, ��λ: fֵ*100 */
    ULONG ulSlowShutter;                    /**< �������� */
    ULONG ulFastShutter;                    /**< ������ */
    ULONG ulMaxGain;                        /**< �������, ��λ: db */
    ULONG ulMinGain;                        /**< ��С����, ��λ: db */
}IMOS_MW_CUSTOM_EXPOSURE_S;

/**
 * @struct tagMwImgExposure
 * @brief �ع����
 * @attention
 */
typedef struct tagMwImgExposure
{
    ULONG ulMode;                                /**< �ع�ģʽ, �μ�: IMOS_MW_EXPOSURE_AUTO �� */
    LONG lExpCompensate;                         /**< �عⲹ�� */
    ULONG ulIris;                                /**< ��Ȧֵ, ��λ: fֵ*100 */
    ULONG ulShutter;                             /**< ����ֵ */
    ULONG ulGain;                                /**< ����, ��λ: db */
    IMOS_MW_CUSTOM_EXPOSURE_S stCustomExposure;  /**< �Զ����ع���� */
    IMOS_MW_SLOW_SHUTTER_S stSlowShutter;        /**< �����Ų��� */
    MW_WDR_S stWDR;                              /**< ��̬���� */
    IMOS_MW_METERING_S stMetering;               /**< ������ */
    IMOS_MW_DAYNIGHT_S stDayNight;               /**< ��ҹ���� */
}IMOS_MW_EXPOSURE_S;

/**
 * @struct tagMwDriveExpandSerialParam
 * @brief �������ںŲ���
 * @attention ��
 */

typedef struct tagMwDriveExpandSerialParam
{
    ULONG aulSerialID[4];                                   /**< ���ں� */
}IMOS_MW_DRIVE_EXPAND_SERIAL_PARAM_S;

/**
 * @struct tagMwTimeSectionCfg
 * @brief �ƻ�ʱ�������
 * @attention
 * -         ʱ���ַ�����ʽ: ��ʱ��������м�ʹ��":"�Ÿ���, �� 00:01:59 ��ʾ 0��1��59��
 */
typedef struct tagMwTimeSectionCfg
{
    CHAR szStartTime[12];  /**< ��ʼʱ�� */
    CHAR szEndTime[12];    /**< ����ʱ�� */
}IMOS_MW_TIME_SECTION_S;

/**
 * @struct tagMwVehicleDrvCfg
 * @brief ������ʻ��������
 * @attention
 */
typedef struct tagMwVehicleDrvCfg
{
    ULONG ulDrivingDirection;                      /**< ������ʻ���򣬲μ�: IMOS_MW_DRIVING_DIRECTION_COME �� */
    IMOS_MW_TIME_SECTION_S stTimeSection;          /**< ��ʻ������Чʱ��� */
}IMOS_MW_VEHICLE_DRV_CFG_S;

/**
 * @struct tagMwDriveExpandParam
 * @brief ������չ����
 * @attention ��
 */
typedef struct tagMwDriveExpandParam
{
    IMOS_MW_VEHICLE_DRV_CFG_S astDrvCfg[4];      /**< ������ʻ�������� */
}IMOS_MW_DRIVE_EXPAND_PARAM_S;

/**
 * @struct tagMwSingSpeedLimit
 * @brief ���ٷ�Ĭ������
 * @attention
 */
 typedef struct tagMwSingSpeedLimit
{
    ULONG ulLimitSpeed;                                     /**< ����ֵ */
    IMOS_MW_TIME_SECTION_S stTimeSection;                   /**< ����ʹ��ʱ���*/
}IMOS_MW_SINGEL_SPEED_LIMIT_S;

/**
 * @struct tagMwWaySpeedLimit
 * @brief �ֳ�������
 * @attention
 */
typedef struct tagMwWaySpeedLimit 
{
    ULONG ulDrivewaySpeedLimit;                                                     /**< Ĭ�ϳ�������ֵ */
    ULONG ulDrivewayMinSpeedLimit;                                                  /**< Ĭ�ϳ����������ֵ��������ٲ���Ҫ��ʱ������ */
    IMOS_MW_SINGEL_SPEED_LIMIT_S astWaySpeedLimit[6];      /**< ���䳵������ֵ */
}IMOS_MW_WAY_SPEED_LIMIT_S;

/**
 * @struct tagMwCarSpeedLimit
 * @brief �ֳ�������
 * @attention
 */
typedef struct tagMwCarSpeedLimit
{
    ULONG ulVehicleType;                                                            /**< ����, �μ�: IMOS_MW_VEHICLETYPE_SMALL �� */
    ULONG ulMinSpeedLimit;                                                          /**< Ĭ���������ֵ��������ٲ���Ҫ��ʱ������ */
    ULONG ulSpeed;                                                                  /**< Ĭ�ϵ�ǰ��������ֵ */
    IMOS_MW_SINGEL_SPEED_LIMIT_S astCarSpeedLimit[6];      /**< ���䵱ǰ��������ֵ */
}IMOS_MW_CAR_SPEED_LIMIT_S;

/**
 * @struct tagMwSpeedLimitUnion
 * @brief ���ٲ���
 * @attention
 */
union tagMwSpeedLimitUnion
{
    IMOS_MW_WAY_SPEED_LIMIT_S stWaySpeedLimit;                                      /**< ���������� */
    IMOS_MW_CAR_SPEED_LIMIT_S astVehicleTypeSpeedLimit[8];    /**< ����������Ϣ */
};

/**
 * @struct tagMwDriveWayType
 * @brief ������ʻ����
 * @attention
 */
typedef struct tagMwDriveWayType
{
    ULONG ulWayType;                                                        /**< ������ʻ���ͣ��μ�IMOS_MW_DRIVING_TYPE_STRAIGHT */
    IMOS_MW_TIME_SECTION_S stTimeSection;                                   /**< ������ʻ����ʹ��ʱ���*/
}IMOS_MW_DRIVE_WAY_TYPE_S;

/**
 * @struct tagMwSingDrivewayExpandCfg
 * @brief ����������չ����
 * @attention ��
 */
 typedef struct tagMwSingleWayExpandCfg
{
    ULONG ulDriDirection;                                                            /**< Ĭ�ϳ�����ʻ���򣬲μ�IMOS_MW_DRIVING_DIRECTION_COME */
    IMOS_MW_VEHICLE_DRV_CFG_S astDriDirection[6];           /**< �������ó�����ʻ���� */
    ULONG ulDriWayType;                                                              /**< Ĭ�ϳ�����ʻ���ͣ��μ�: IMOS_MW_DRIVING_TYPE_STRAIGHT �� */
    IMOS_MW_DRIVE_WAY_TYPE_S astDrivWayType[6];             /**< �������ó�����ʻ���� */
    ULONG ulExeSpeedAdjustFactor;                                                    /**< ִ������ */
    ULONG ulSpeedLimitMode;                                                          /**< ��������ģʽ, �μ�: IMOS_MW_SPEEDLIMIT_MODE_DRIVEWAY �� */
    int __unionReserve;                                                              /**< ����(soap��Ҫ���ֶ���ȷ��ʹ��UNION���ĸ�) */
    union tagMwSpeedLimitUnion unDriveWaySpeedLimit;                                 /**< ��������ֵ���� */
}IMOS_MW_SING_DRIV_WAY_EXP_CFG_S;

/**
 * @struct tagMwDrivewayExpandCfg
 * @brief ������չ����
 * @attention ��
 */
typedef struct tagMwDrivewayExpandCfg
{
    IMOS_MW_DRIVE_EXPAND_PARAM_S astDrivewayExpandParam[4];  /**< ������չ���� */
    IMOS_MW_DRIVE_EXPAND_SERIAL_PARAM_S stDrivewayExpandSerialParam;                   /**< ���ںŲ��� */
    IMOS_MW_SING_DRIV_WAY_EXP_CFG_S astSingDrivWayExpCfg[4]; /**< ������չ���ò��� */
    ULONG aulPPort[4];                                       /**< ���������ö�Ӧ��Ͳ���P�� */
}IMOS_MW_DRIVEWAY_EXPAND_CFG_S;

/**
* @struct tagMwIdentifyArea
* @brief ʶ������
* @attention
*/
typedef struct tagMwIdentifyArea
{
    ULONG ulAreaID;                         /**< ����ID, ȫF������Ч����  */
    IMOS_MW_QUADRANGLE_S stIdentifyArea;    /**< ʶ���������� */
}IMOS_MW_IDENTIFY_AREA_S;

typedef struct tagMwPlateIdentifyCfg
{
    USHORT usMinLprWidthPix;                                            /**< ��С���Ƽ����--������Ϊ��λ */
    USHORT usMaxLprWidthPix;                                            /**< ����Ƽ����--������Ϊ��λ */
    ULONG ulAreaNum;                                                    /**< ʶ��������� */
    IMOS_MW_IDENTIFY_AREA_S astIdentifyArea[4];  /**< ʶ������ */
    BOOL_T bNorthKoreaPlate;                                            /**< �Ƿ�֧�ֳ��ʳ��� */
    BOOL_T bAgroPlate;                                                  /**< �Ƿ�֧��ũ�ó��� */
    BOOL_T bVehicleLogo;                                                /**< �Ƿ�֧�ֳ���ʶ�� */
    BOOL_T bVehicleColor;                                               /**< �Ƿ�֧�ֳ�����ɫʶ�� */
    UCHAR ucDefaultProvince;                                            /**< ����ȱʡ���� */
    UCHAR ucDefaultLetter;                                              /**< ����ȱʡ��ĸ */
    UCHAR aucReserve[2];                                                /**< ����:aucReserve[0] bitλ
                                                                              0λ:���ƽ���(0����أ�1����)��3λ:��ʶ��,4λ:�������⹦��ʹ��, 
                                                                              5λ��ȫ�����, 6λ:���ͼ��,7λʹ�ݳ��� */
                                                                        /**< ����:aucReserve[1] �������Ƿ�Ϊ"��Ƶ�������"ҳ���·���
                                                                             BOOL_TRUE:"��Ƶ�������"ҳ���·� */
    ULONG ulSpecialPlate;                                               /**< ���⳵�� �μ�:IMOS_MW_PLATE_WG */
    CHAR szFilterPlateString[128];      /**< ������չ����ֶΣ���/�ָ� */
    ULONG ulPlateParam;                                                 /**< ֧�ֳ���ʶ���������λ����:0x01֧����ͷ��ʶ��,���ܰ�λ */
    ULONG ulCheckRepeatTime;                                            /**< �ظ����ƹ���ʱ��,��λ �� */
    ULONG ulNewPlateParam;                                              /**< �µĳ���ʶ���������λ������bitλ0����أ�1����
                                                                             0λ:Ħ�г�ʶ��1λ:����������ʹ�� */                                                                               
    ULONG ulMultiPlateIdentifyMode;                                     /**< ���ڳ���ڶ�֡ʶ��ģʽ, �μ�:IMOS_MW_TG_MULTI_IDENTIFY_MODE_NO   */                                                                          
}IMOS_MW_PLATE_IDENTIFY_CFG_S;

/**
 * @struct tagMwTriggerLine
 * @brief ��������Ϣ
 * @attention
 */
typedef struct tagMwTriggerLine
{
    ULONG ulLineID;                         /**< ������ID */
    BOOL_T bEnable;                         /**< �Ƿ�ʹ�� */
    ULONG ulLineType;                       /**< ���������ͣ��μ�: IMOS_MW_TRIGGER_LINE_DEFAULT1 �� */
    ULONG ulTriggerDelay;                   /**< ��ʱ���� */
    IMOS_MW_LINE_S stLine;                  /**< ������λ�� */
}IMOS_MW_TRIGGERLINE_S;

/**
 * @struct tagMwTriggerLineCfg
 * @brief ����������
 * @attention
 */
typedef struct tagMwTriggerLineCfg
{
    ULONG ulLineNum;                                                    /**< ���������� */
    IMOS_MW_TRIGGERLINE_S astTriggerLine[IMOS_MW_TRIGGER_LINE_NUM];     /**< ���������� */
}IMOS_MW_TRIGGERLINE_CFG_S;

/**
 * @struct tagMwDrivewayLine
 * @brief ������
 * @attention
 */
typedef struct tagMwDrivewayLine
{
    ULONG ulLineID;                           /**< ������ID */
    BOOL_T bEnable;                           /**< �������Ƿ����� */
    ULONG ulLineType;                         /**< ����������, �μ�: IMOS_MW_DRIVEWAY_LINE_SOLID_WHITE �� */
    BOOL_T bEnableCoverDetect;                /**< �Ƿ�����ѹ�߼�� */
    BOOL_T bDetectOverline;                   /**< �Ƿ�����Խ�߼�� */
    FLOAT fSensitivity;                       /**< ѹ�߼�������ȣ�˵��: ���ƿ�� * ѹ�߼�������� = ������ */
    IMOS_MW_LINE_S stLine;                    /**< λ������ */
}IMOS_MW_DRIVEWAY_LINE_S;

/**
 * @struct tagMwDrivewayLineCfg
 * @brief ��������Ϣ
 * @attention
 */
typedef struct tagMwDrivewayLineCfg
{
    ULONG ulLineNum;                                                             /**< ��������Ŀ */
    IMOS_MW_DRIVEWAY_LINE_S astDrivewayLine[9];      /**< ���������� */
}IMOS_MW_DRIVEWAYLINE_CFG_S;

/**
 * @union tagMwListMatchRule
 * @brief ����ƥ�����
 * @attention 
 */
typedef struct tagMwListMatchRule
{
    ULONG ulMatchMode;             /* ƥ��ģʽ 0 ģ��ƥ�䣬1 ��ȷƥ��*/
    ULONG ulLetterFuzzyMatchLevel;  /* ��ĸ����ģ��ƥ��ȼ�,�ȼ�:0.1.2; ��ulMatchModeΪ0��Ч */
    BOOL_T bChineseIgnored;         /* �Ƿ���Ժ���ƥ��; ��ulMatchModeΪ0��Ч */
}IMOS_MW_LIST_MATCH_RULE_CFG;

/**
* @struct tagMwGateWhiteList
* @brief ����ڰ���������
* @attention
*/
typedef struct tagMwGateWhiteList
{
    BOOL_T bEnabled;       /* �Ƿ�ʹ������ */
    IMOS_MW_LIST_MATCH_RULE_CFG stMatchRule;    /* ƥ����� */
}IMOS_MW_GATE_WHITE_LIST_CFG_S;

/**
* @struct tagMwGateBlackList
* @brief ����ں���������
* @attention
*/

typedef struct tagMwGateBLACKList
{
    BOOL_T bEnabled;       /* �Ƿ�ʹ������ */
    BOOL_T bLinkSwitch;    /* �Ƿ����������� */  
    ULONG ulLinkSwitchID;       /* ����������ID */
    IMOS_MW_LIST_MATCH_RULE_CFG stMatchRule;    /* ƥ����� */
}IMOS_MW_GATE_BLACK_LIST_CFG_S;

/**
 *@union tagMwReleaseStrategyCfg
 *@brief ���в���
 *@attention
 */
typedef struct tagMwReleaseStrategyCfg
{    
    ULONG ulCtrlMode;                             /* ����ģʽ  0:����������ģʽ; 1:���߿���ģʽ; 2:�������ƿ�բ */
    ULONG ulReleaseTactics;                       /* ����������ģʽ,ȡֵ: 0  ���г������� 1 �������������� 2 �Ǻ������������� */ 
    BOOL_T bUnidentifiedRelease;                  /* δʶ�����Ƿ���� */
    ULONG ulOutputSwitchID;                       /* ���п����� */
}IMOS_MW_RELEASE_STRATEGY_CFG_S;

#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_PUB_H__*/




