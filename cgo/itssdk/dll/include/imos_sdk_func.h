/*******************************************************************************
 Copyright (c) 2013,  Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_sdk_func.h
  Project Code: MW_SDK
   Module Name: SDK
  Date Created: 2012-01-14
        Author: c00510 
   Description: ���ļ�������sdk��صĴ����롢�ꡢö�١��ṹ�塢�����ӿ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  2012-01-14

*******************************************************************************/
#ifndef __IMOS_SDK_FUNC_H__
#define __IMOS_SDK_FUNC_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#if 0
#endif
/*********************************** �������� **************************************************
SDK Info
***************************************************************************************/
/** @defgroup groupSDKInfo SDK��־����Ϣ
*   SDK��־��¼�Ͱ汾��Ϣ
*   @{
*/
/**
 * ��ȡSDK�汾�� \n
 * @param [OUT]pucVersion     �汾�ţ�����: IMOS_MW_SDK_CLIENT_VERSION_LEN
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * @note 
 * -     �������豣ָ֤����ָ����ڴ泤�Ȳ�С��: IMOS_MW_SDK_CLIENT_VERSION_LEN
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetSDKVersion(OUT UCHAR *pucVersion);

/**
 * ����SDK��־��Ϣ \n
 * @param [IN] ulLogLevel  ��־���𣬲μ�: IMOS_SDK_LOG_CLOSE ��
 * @param [IN] pcLogPath   ����·��
 * @param [IN] ulLogSize   ��־��С
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_LOG_CLOSE                  ��־�ѹر�
 * @note 
 * -     1����־����ĺ��壬ʵ�ʼ�¼���и������ü������־��Ϣ����������Ϊ: IMOS_SDK_LOG_INFO��
 * -     2����־����·����ָ����·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ���
 * -     3��SDKĬ����־�ļ����� "IMOS_MW_SDK00.log", Ĭ�ϵ�����־�ļ���СΪ1.5M�������ô�Сʱ����������־�ļ�����Ϊ"IMOS_MW_SDK01.log", �����¼�¼��ԭ�ļ��С�
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetLog(IN ULONG ulLogLevel, 
                                         IN CHAR *pcLogPath, 
                                         IN ULONG ulLogSize);
                                         
/** @defgroup groupDeviceStatus ��ȡ�豸״̬
*   ��ȡ�豸״̬�ӿ�
*   @{
*/
/**
 * ��ȡ״̬���� \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulChannel          ͨ����
 * @param [IN] ulCmdType          ״̬��������, �μ�: IMOS_MW_STATUS_KEEPALIVE ��
 * @param [INOUT] pStatusInfo     ״̬��Ϣ, �μ���״̬�������͵� ˵��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * @note 
 * - ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetDeviceStatus(IN CHAR *pcUserID,
                                                  IN ULONG ulChannel,
                                                  IN ULONG ulCmdType, 
                                                  INOUT VOID *pStatusInfo);

/**
 * ϵͳ���� \n
 * @param [IN] pcUserID    �û���Ϣ��ʶ
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Reboot(IN CHAR *pcUserID);

/*************************************************************************************
SDK Init
***************************************************************************************/
/** @defgroup groupSDKInit SDK��ʼ����ע��
*   SDK��ʼ������ϸ�ĵ���������ϵ��μ�SDK˵���ĵ�����ģ�������ʼ���ӿں���սӿڡ�
*   @{
*/
/**
 * SDK��ʼ�� \n
 * @param [IN] ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_CREATE_THREAD_FAIL         �����߳�ʧ��
 * -             #ERR_SDK_XP_INIT_FAILED             ��������ʼ��ʧ��
 * -             #ERR_SDK_REINIT                     SDK �Ѿ���ʼ��
 * -             #ERR_SDK_COMMON_NO_MEMORY           ���治��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Initiate(VOID);

/**
 * SDK��Դ�ͷ� \n
 * @param [IN] �� 
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * @note ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Cleanup(VOID);
/** @} */ /* end of SDKInit Module */


/*************************************************************************************
Status Report
***************************************************************************************/
/** @defgroup groupStatusReport ����״̬�ϱ��ص�����
*   �����豸�����е�״̬���쳣��Ϣ�Ĵ�����
*   @{
*/
/**
 * SDK״̬�ϱ��ص����� \n
 * @param [IN] pcUserID          �û�ID, ��ʾ��ǰ�ϱ�״̬���û�
 * @param [IN] ulReportType      ��Ϣ�����쳣��Ϣ���ͣ��μ� IMOS_MW_STATUS_KEEPALIVE ��
 * @param [IN] pParam            �����Ϣ���쳣��Ϣ���ݵĻ�����ָ��
 * @return ULONG
 * @note 
 * -     1���û���Ҫȷ���ûص��������췵��
 * -     2�������ڸûص�������ֱ�ӵ��ò��������κνӿں�����
 * -     3������pParam��ָ�Ļ������д�ŵ����ݵ���������Ϣ�����쳣��Ϣ���Ͷ������û���Ҫ������Ϣ�����쳣��Ϣ���Ͷ���������ת��
 */
typedef VOID (STDCALL* IMOS_MW_STATUS_REPORT_CALLBACK_PF)(IN CHAR *pcUserID,
                                                          IN ULONG ulReportType, 
                                                          IN VOID *pParam);
/**
 * ����״̬�ϱ��ص����� \n
 * @param [IN] pfStatusReportCB       SDK״̬�ϱ��ص������ĺ���ָ��
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * @note 
 * -     1���û���Ҫȷ���ûص��������췵�ء�
 * -     2�������ڸûص�������ֱ�ӵ��ò�����SDK���κνӿں�����
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetStatusCallback(IN IMOS_MW_STATUS_REPORT_CALLBACK_PF pfStatusReportCBFun);

/*************************************************************************************
User Login
***************************************************************************************/
/** @defgroup groupUserLogin �û���¼
*   SDK�û���¼���ǳ�
*   @{
*/
/**
 * �û���¼ \n
 * @param [IN]  pcUserName        �û�����ĵ�¼��������Ϊ IMOS_MW_USER_NAME_LEN
 * @param [IN]  pcPassword        �û���������룬����Ϊ IMOS_MW_USER_PASSWORD_LEN
 * @param [IN]  pcServerIP        Ŀ���ն˵�IP��ַ������Ϊ IMOS_MW_IPADDR_LEN
 * @param [IN]  usServerPort      Ŀ���ն˵Ķ˿ںţ���Ϊ0��������ڲ�����
 * @param [OUT] pcUserID          �û�ID������Ϊ IMOS_MW_RES_CODE_LEN
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       ��������Ƿ�
 * -             #ERR_SDK_NOTINIT                    �豸SDKδ��ʼ��
 * -             #ERR_SDK_USERFULL                   �豸�û�����
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_USER_PASSWD_INVALID        �û��������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note
 * -     1���ýӿ����ڵ�¼IPC�豸
 * -     2��pcUserID �û���ʶ������Ψһ�ԣ��������豸�Ĳ�������Ҫͨ����IDʵ��
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Login(IN CHAR *pcUserName,
                                        IN CHAR *pcPassword,
                                        IN CHAR *pcServerIP,
                                        IN USHORT usServerPort,
                                        OUT CHAR *pcUserID);

IMOS_EXPORT ULONG STDCALL IMOS_MW_LoginReconnect(IN CHAR *pcUserName,
					   IN CHAR *pcPassword,
					   IN CHAR *pcServerIP,
					   IN USHORT usServerPort,
					   OUT CHAR *pcUserID);


/**
 * �û�ע�� \n
 * @param [IN]  pcUserID      �û�ID
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       ��������Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note
 * -     ����������û�ID���ǵ�¼ʱ��ȡ���ġ�
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Logout(IN CHAR *pcUserID);
 

/*************************************************************************************
Device Config
***************************************************************************************/
/** @defgroup groupDeviceConfig ��������
*   ��������
*   @{
*/
/**
 * ��ȡ�豸������Ϣ \n
 * @param [IN] pcUserID           �û�ID
 * @param [IN] ulCmdType          �������ͣ��μ�: IMOS_MW_SYSTEM_TIME_INFO ��
 * @param [IN] ulChannel          ͨ����
 * @param [INOUT] pulBufferLen    �������ݵĻ�������С
 * @param [INOUT] pConfigDataBuf  �����������Ļ�����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_NOENOUGH_BUF               �����С����
 * @note
 * -     1������ ulChannel ���ڸ������������в�ͬ�ĺ��壬���������ֲ���Ҫ�ò���������Ϊ��Чֵ(0xFFFF)��
 * -     2������ pulBufferLen ���ʱ��ʾ��Ż�ȡ�����õĻ�������С�����α�ʾʵ�ʻ�ȡ��������Ҫ�Ļ�������С��
 *          ���ڲ��ֳ��ȿɱ�����������λ�������С��������Ҫ���ݳ������»�ȡ���á�
 * -     3������ pConfigDataBuf ��ʾ��Ż�ȡ�����õ�ָ�룬���Ӧ�Ľṹ����μ��������ֵ�˵�������в��ֲ����Ļ�ȡ����Ҫ����ָ��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_GetConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            INOUT ULONG *pulBufferLen,
                                            INOUT VOID *pConfigDataBuf);

/**
 * �����豸������Ϣ \n
 * @param [IN] pcUserID              �û�ID
 * @param [IN] ulCmdType             �������ͣ��μ�: IMOS_MW_SYSTEM_TIME_INFO ��
 * @param [IN] ulChannel             ͨ����
 * @param [IN] ulBufferLen           �������ݵĻ�������С
 * @param [IN] pConfigDataBuf        �����������Ļ�����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * @note
 * -     1������ ulChannel ���ڸ������������в�ͬ�ĺ��壬���������ֲ���Ҫ�ò���������Ϊ��Чֵ(0xFFFF)��
 * -     2������ pulBufferLen ��ʾ��Ŵ����õ����û�������С��
 * -     3������ pConfigDataBuf ��ʾ����������õ�ָ�룬���Ӧ�Ľṹ����μ��������ֵ�˵�������в��ֲ��������ã���Ҫ����ָ��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            IN ULONG ulBufferLen,
                                            IN VOID *pConfigDataBuf);

/**
 * ɾ���豸������Ϣ \n
 * @param [IN] pcUserID              �û�ID
 * @param [IN] ulCmdType             �������ͣ��μ�: IMOS_MW_INFO_OSD_CFG ��
 * @param [IN] ulChannel             ͨ����
 * @param [IN] ulBufferLen           �������ݵĻ�������С
 * @param [IN] pConfigDataBuf        �����������Ļ�����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * @note
 * -     1������ ulChannel ���ڸ������������в�ͬ�ĺ��壬���������ֲ���Ҫ�ò���������Ϊ��Чֵ(0xFFFF)��
 * -     2������ pulBufferLen ��ʾ��Ŵ����õ����û�������С��
 * -     3������ pConfigDataBuf ��ʾ����������õ�ָ�룬���Ӧ�Ľṹ����μ��������ֵ�˵�������в��ֲ�����ɾ������Ҫ����ָ��������
 * -     4��֧��ɾ���������У�����OSD���ã��ڸ�OSD���á��˶�����������á��澯��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_DelConfig(IN CHAR *pcUserID,
                                            IN ULONG ulCmdType,
                                            IN ULONG ulChannel,
                                            IN ULONG ulBufferLen,
                                            IN VOID *pConfigDataBuf);
                                            
/***************************************************************************************/
/**
 * TCP �������ݻص����� \n
 * @param [IN] pcUserID           �û���Ϣ��ʶ
 * @param [IN] pstAlarmInfo       �¼���Ϣ(���¼����͡�ʱ�䡢��Դ)
 * @return ULONG
 * @note ��
 */
typedef ULONG (STDCALL* IMOS_MW_STREAMDATA_CALLBACK_PF)(IN ULONG ulStreamHandle, 
                                                        IN CHAR *pcStreamBuf,
                                                        IN INT lBufLen);   
                                                                                                            
/**
* ��ȡ��Ƭ���ص�,�ṹ��ʽ�� \n
* @param [IN] const IMOS_MW_UNIVIEW_PROTOCOL_HEADER_S *pstUniviewData   ��Ƭ��Ϣ
* @param [IN] const CHAR* DeviceIP          �豸IP (���������յ�����Ƭ��Դ)
* @return �ޡ�
* @note �������ĵ��Զ�Ϊutf8��ʽ
* -    
*/
typedef VOID (STDCALL* IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF)(IN const IMOS_MW_MULTI_UNIVIEW_PROTOCOL_HEADER_S *pstUniviewData, 
                                                            IN const ULONG ulStreamHandle);

/**
* ��ȡ��Ƭ���ص�(XML��ʽ)�� \n
* @param [IN] const ULONG ulXmlLen, XML����
* @param [IN] const CHAR *pcPicXmlInfo ��Ƭ�����Ϣ, ��XML��ʽ�ṩ
* @param [IN] const IMOS_MW_PIC_INFO_S *pstPicData ��Ƭ����
* @param [IN] const ULONG ulStreamHandle �����
* @return �ޡ�
* @note
* -    
*/
typedef VOID (STDCALL* IMOS_MW_PIC_XML_UPLOAD_PF)(IN const ULONG ulXmlLen,
                                                  IN const CHAR *pcPicXmlInfo,
                                                  IN const IMOS_MW_PIC_INFO_S *pstPicData, 
                                                  IN const ULONG ulStreamHandle);
                                                  
/**
 * ����(����)ý���� \n
 * @param [IN] pcUserID              �û�ID
 * @param [IN] ulChannel             ͨ����, ����չ
 * @param [IN] ulStreamID            ��ID, �μ� IMOS_MW_STREAM_ID_MAIN ��
 * @param [IN] ulTransMode           ������ģʽ���μ� IMOS_MW_TRANSFER_MODE_RTP_UDP ��
 * @param [IN] pcIpAddress           �������ն�IP��ַ, 
 * @param [IN] usPort                �������ն˶˿�, ���˿�Ϊ0, ����SDK�ڲ�������ն˿�
 * @param [IN] bKeepAlive            �������־�����������ڵ���������ʱ���� BOOL_FALSE
 * @param [OUT] pulStreamHandle      �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������  
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ����ʧ��
 * -             #ERR_SDK_SOCKET_LSN_FAIL            ����Socketʧ��
 * -             #ERR_SDK_XP_PORT_ALLOC_FAILED       ��ȡ��������Դʧ��
 * -             #ERR_SDK_DEVICE_STREAM_FULL         �豸������
 * -             #ERR_SDK_XP_START_STREAM_FAILED     ý��������ʧ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -     1���������ն�IP��ַ��Ϊ: ""�� NULL, �� "0.0.0.0" ����ʾ����ip, ���ն˶�ipΪ����ʱ�ɲ�ָ���˿ں�(��0)
 * -     2������IPC�豸ʵ�����Ľ���
 * -     3����ȡ��������������ں��������Ĵ���
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StartMediaStream(IN CHAR *pcUserID,
                                                   IN ULONG ulChannel,
                                                   IN ULONG ulStreamID,
                                                   IN ULONG ulTransMode,
                                                   IN CHAR *pcIpAddress,
                                                   IN USHORT usPort,
                                                   IN BOOL_T bKeepAlive,
                                                   OUT ULONG *pulStreamHandle);


IMOS_EXPORT ULONG STDCALL IMOS_MW_StartMediaStreamReconnect(IN CHAR *pcUserID,
									   IN ULONG ulChannel,
									   IN ULONG ulStreamID,
									   IN ULONG ulTransMode,
									   IN CHAR *pcIpAddress,
									   IN USHORT usPort,
									   IN BOOL_T bKeepAlive,
									   OUT ULONG *pulStreamHandle);


/**
 * ������Ƭ�����ݻص����� \n
 * @param [IN] pcUserID      �û���Ϣ��ʶ
 * @param [IN] bReTran       �Ƿ��ش� 0 ���ش� 1 �ش�
 * @param [IN] pcReTranIP    �ش��������ն�IP��ַ;���ش����,""
 * @param [IN] IMOS_MW_TMS_PIC_UPLOAD_PF pfnPicDataCBFun ��Ƭ�ϴ��ص�
 * @param [OUT] ULONG ulStreamHandle �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * @note 1: ���øú���ʵ�������������ûص������ͨ�����õĻص������ϱ���Ƭ�����ƣ�Υ�µ���Ϣ��
 *       2: ��������ش�, ���Ϊ��SDKʱ��ͼƬ���浽SD��, ����SDK��ὫSD������Ƭ�ϱ���
 * -
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPicStreamDataCallback(IN CHAR *pcUserID,
                                               IN BOOL_T bReTran, 
                                               IN CHAR *pcReTranIP,
                                               IN IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF pfnPicDataCBFun, 
                                               OUT ULONG *pulStreamHandle);

/**
 * ɾ��(ֹͣ)ý���� \n
 * @param [IN] pcUserID         �û�ID
 * @param [IN] ulStreamHandle   ���������ʶһ����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMAND_SEND_FAIL          ��Ϣ����ʧ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * @note 
 * -     ����IPC�豸ʵ������ɾ����������� IMOS_MW_StartMediaStream ��ȡ����
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_StopMediaStream(IN CHAR *pcUserID,
                                                  IN ULONG ulStreamHandle);

/**
 * ������Ƶ���ݻص����� \n
 * @param [IN] pfnStreamData    TCP�����ص�����
 * @param [IN] ulStreamHandle   ���������ʶһ����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMAND_SEND_FAIL          ��Ϣ����ʧ��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * @note 
 * -     ����IPC�豸ʵ������ɾ����������� IMOS_MW_StartMediaStream ��ȡ����
 *
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetStreamDataCallBack(IN IMOS_MW_STREAMDATA_CALLBACK_PF pfnStreamData,
                                                        IN ULONG ulStreamHandle);
                                                        
/**
 * ���ù�����Ƭ�ϴ��ص�(���ڶ��û�) \n
 * @param [IN] IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF pfnPicDataCBFun ��Ƭ�ϴ��ص�
 * @param [IN] ULONG ulStreamHandle �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_MultiUser_SetPicDataCallback(IN IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF pfnPicDataCBFun, IN ULONG ulStreamHandle);

/**
 * ���ö�����Ƭ�ϴ��ص�����Ƭ��Ϣ��XML��ʽ�ϴ� \n
 * @param [IN] IMOS_MW_PIC_XML_UPLOAD_PF pfnPicDataCBFun ��Ƭ�ϴ��ص�
 * @param [IN] IN ULONG ulStreamHandle �����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_DEVICE_STREAM_NONEXIST     �豸��������
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetPicDataAndXmlInfoCallback(IN IMOS_MW_PIC_XML_UPLOAD_PF pfnPicDataCBFun, 
                                                               IN ULONG ulStreamHandle);

/** @defgroup groupCameraCapture �ֶ�ǰ��ץ��
*   �ֶ�ǰ��ץ��
*   @{
*/
/**
 * �ֶ�ǰ��ץ�� \n
 * @param [IN] pcUserID             �û�ID
 * @param [IN] ulChannel            ͨ����
 * @param [INOUT] pulPicBuffSize    ����ץ��ͼƬ�Ļ�������С
 * @param [OUT] pcPicBuffer         ����ץ��ͼƬ�Ļ�����
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_USERNONEXIST               �û��Ƿ�
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * @note
 * -     1��pulPicBuffSize ���ʱ����ʾ �û�����Ļ�������С������Ϊʵ�ʵ�ͼƬ���軺������С
 * -     2������ֵΪ "����Ļ���������" ʱ���û�����ݳ����е��ļ�ʵ�ʻ�������С���·����㹻�����
 * -        ���µ��øýӿڻ�ȡ��ץ�ĵ���Ƭ
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_Capture(IN CHAR *pcUserID,
                                          IN ULONG ulChannel,
                                          INOUT ULONG *pulPicBuffSize,
                                          OUT CHAR *pcPicBuffer);
/**
 * ��������� \n
 * @param [IN] pcUserID         �û�ID
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note 
 * -     
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_SetOutputSwitchStatusCfg(IN CHAR *pcUserID);                                                       

/**
 * ʵ�����ݴ�SDK͸������ \n
 * @param [IN] pcUserID      �û���Ϣ��ʶ
 * @param [IN] pcDataBuffer        �������ݻ���(���256 BYTE)
 * @param [IN] ulDataNum           �������ݳ���(���256 BYTE)
 * @param [IN] ulComIndex         ���ں����� (1----4)  (���ݽ���͸��ͨ������ port����Ϊ 1025,1026,1027,1028)
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * @note ��
 * -
 */
ULONG STDCALL IMOS_MW_SendDataToCom(IN CHAR *pcUserID, IN CHAR *pcDataBuffer, IN LONG ulDataNum, IN ULONG ulComIndex);

/**
 * ����ڰ������ļ� \n
 * @param [IN] pcUserID         �û���Ϣ��ʶ
 * @param [IN] ulWhiteBlackType �ڰ��������� �ο�IMOS_MW_GATE_WHITE
 * @param [IN] pcFile           �������ļ�(������·��)
 * @return ULONG���������½����   
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMON_FAIL_STAT           ��ȡ�ļ�ʧ��
 * -             #ERR_SDK_INVALID_CONFIGFILE         �����ļ��Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note
 * -     1������ָ��·���µİ������ļ�(������·��)���ļ���������Ϊwhiteblacklist.csv
 * -     2��·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ���
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ImportWhiteBlackListFile(IN CHAR *pcUserID, IN CHAR *pcFile);

/**
 * �����ڰ������ļ� \n
 * @param [IN] pcUserID         �û���Ϣ��ʶ
 * @param [IN] ulWhiteBlackType �ڰ��������� �ο�IMOS_MW_GATE_WHITE
 * @param [IN] pcFile           �������ļ�(������·��)
 * @return ULONG���������½����
 * -             #ERR_COMMON_SUCCEED                 �ɹ�
 * -             #ERR_SDK_COMMON_FAIL                ����ʧ��
 * -             #ERR_SDK_COMMON_INVALID_PARAM       �����Ƿ�
 * -             #ERR_SDK_USERNONEXIST               �û�������
 * -             #ERR_SDK_COMMON_FAIL_STAT           ��ȡ�ļ�ʧ��
 * -             #ERR_SDK_INVALID_CONFIGFILE         �����ļ��Ƿ�
 * -             #ERR_SDK_COMMON_NO_MEMORY           ϵͳ�ڴ治��
 * -             #ERR_SDK_COMMAND_TIMEOUT            ����ʱ
 * @note
 * -     1������ָ��·���µİ������ļ�(������·��)���ļ���������Ϊwhiteblacklist.csv
 * -     2��·�����ȺͲ���ϵͳ�йأ�sdk�������ƣ�windowsĬ��·������С�ڵ���256�ֽڣ������ļ������ڣ���
 */
IMOS_EXPORT ULONG STDCALL IMOS_MW_ExportWhiteBlackListFile(IN CHAR *pcUserID, IN CHAR *pcFile);

/**
* ��ȡ�������״̬ \n
* @param [IN]  lpUserID   �û���¼���
* @param [IN]  pbStatus   �豸����״̬ TRUE��ʾ����,FALSE��ʾʧ��
* @return TRUE��ʾ�ɹ�,������ʾʧ��
* @note 20190528-new
*/
IMOS_EXPORT BOOL_T STDCALL IMOS_MW_GetOnlineStatus(IN CHAR *pcUserID, OUT BOOL_T *pbStatus);

/**
 * ���Ʊ����ʽUTF-8 \n
 * @param [OUT] bEnable     �Ƿ����� 0 GBK 1 UTF-8 (Ĭ��UTF-8)
 * @return BOOL���������½����
 * -             #TRUE                �ɹ�
 * -             #FALSE               ʧ��
 */
//NO
IMOS_EXPORT BOOL_T STDCALL IMOS_MW_EnableCarplate(IN ULONG bEnable);

#ifdef  __cplusplus
}
#endif

#endif /*end of __IMOS_SDK_FUNC_H__*/

