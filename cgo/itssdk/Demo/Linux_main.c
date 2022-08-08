#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/stat.h> 
#include <sys/types.h> 

#include "imos_sdk_def.h"  //SDK�궨��ͷ�ļ�
#include "imos_sdk_pub.h"  //SDK�ṹ�嶨��ͷ�ļ�
#include "imos_sdk_func.h" //SDK�ӿڶ���ͷ�ļ�

#define EAT_INBUFF {\
    int c;\
    do{\
        c = getchar();\
        printf("eat %d\n",c);\
    }while(c != '\n' && c != EOF);\
}

typedef struct tagStartMediaInfo    
    {                   
        CHAR szUserID[128];         
        ULONG ulCaptureStreamHandle;     
        }STARTMEDIA_INFO_S;


BOOL_T gbLogin = BOOL_FALSE;
IMOS_MW_SYSTEM_TIME_INFO_S gstTime = {0};
unsigned char szTemp[92]= {0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
                           0x00, 0x00, 0xfe, 0x02, 0x42, 0x00, 0xa3, 0x06, 0x02, 0x28, 0x00, 0x00, 0x01, 0x39, 0x00, 0x00,
                           0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
                           0x02, 0x02, 0x01, 0x00, 0x00, 0x0a, 0x1e, 0x00, 0x00, 0x00, 0xd5, 0xe3, 0x41, 0x35, 0x32, 0x39,
                           0x33, 0x5b, 0x02, 0x5c, 0x6e, 0xbd, 0xd8, 0xd6, 0xb9, 0xc8, 0xd5, 0xc6, 0xda, 0x5c, 0x6e, 0x32,
                           0x30, 0x31, 0x38, 0x2d, 0x30, 0x37, 0x2d, 0x32, 0x38, 0xdc, 0x2d, 0x5a};

LONG IMOS_snprintf(INOUT CHAR *pcBuf, IN SIZE_T ulMaxlen, IN const CHAR *pcFormat, ...)
{
    LONG lRet = 0;
    va_list stParalist;

    /* ���ն������ */
    va_start(stParalist, pcFormat);

    /* ����ACEϵͳ���� */
    lRet = (LONG) vsnprintf(pcBuf, (size_t) ulMaxlen, pcFormat, stParalist);

    /* �ͷŲ�����Դ */
    va_end(stParalist);

    return lRet;
}


//Demo������Ϣ�ϱ��ص��ӿ�ʵ��
VOID GetPictureCB(IMOS_MW_MULTI_UNIVIEW_PROTOCOL_HEADER_S *pstUniviewData, ULONG ulStreamHandle)
{
    ULONG i = 0;
    FILE *pFile = NULL;
    CHAR szNameBuf[64] = {0};
    
	printf("\nStreamHandle: %lu, Capture time: %s, Carplate:%s.\n", ulStreamHandle, pstUniviewData->szPassTime, pstUniviewData->szCarPlate);
   
    for (i = 0; i < pstUniviewData->ulPicNumber; i++)
    {
        IMOS_snprintf(szNameBuf, sizeof(szNameBuf), "./sdcard/%s_%d.jpeg", pstUniviewData->szPassTime, i);
        pFile = fopen(szNameBuf, "w");
        printf("Save path:%s,PicLen:%lu, PData:%p.\n", szNameBuf, pstUniviewData->aulDataLen[i], pstUniviewData->apcData[i]);
        if (NULL != pFile)
        {
            fwrite(pstUniviewData->apcData[i], 1, pstUniviewData->aulDataLen[i], pFile);
            fclose(pFile);
        }
    }

    return;
}

//Demo״̬�ϱ��ӿ�ʵ��
void StatusReportCallBackFunEx(CHAR *pcUserID, ULONG ulReportType, VOID *pParam)
{  
    /*set status report callback function*/
    CHAR szTmp[128] = {0};
   	LONG lLen = 0;
    LONG lRet = 0;
    
    lRet = mkdir("./sdcard", 0755);

    sprintf(szTmp, "%s/ParkingInfo.txt", "./sdcard");
    
    switch (ulReportType)
    {
        case IMOS_MW_STATUS_KEEPALIVE://�豸����״̬��ʶ:0
        {
            /*keepalive*/
            printf("Device Outline, pcUserID:%s.\n", pcUserID);
           // gbLogin = BOOL_FALSE;
            break;
        }
        case IMOS_MW_STATUS_RLOGIN://�豸�ڲ������ɹ�״̬��ʶ:1
        {
            /*keepalive*/
            printf("Device Reconnet online, pcUserID:%s.\n", pcUserID);
           // gbLogin = BOOL_FALSE;
            break;
        }
        case IMOS_MW_STATUS_PLAYER_MEDIA_PROCESS://�豸����״̬��ʶ:201
	    {
            /*XP*/
            printf("Device OutPicStream, pcUserID:%s.\n", pcUserID);
            break;
        }
      
        case IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT://��λ״̬�ϱ���ʶ(��):160
        {
            printf("Device Park Status Report.\n");
            
          	IMOS_MW_PARK_STATUS_S *pstParkStatus = (IMOS_MW_PARK_STATUS_S *)pParam;
            FILE *fp =fopen(szTmp,"a+");
            /* ��������λ */
			if ((0 == pstParkStatus->lParkingLotStatus) && ((pstParkStatus->lParkID <= 3) && (pstParkStatus->lParkID > 0)))
			{
				
				lLen = sprintf(szTmp, "��λ:%lu    ʱ��:%s  ����:%s ʻ��\r\n",
					          pstParkStatus->lParkID,
					          pstParkStatus->szSampleTime,
							  pstParkStatus->szCarPlate);
				fwrite(szTmp,1,lLen, fp);
			}

			/* ����ʻ�복λ */
			if ((1 == pstParkStatus->lParkingLotStatus) && ((pstParkStatus->lParkID <= 3) && (pstParkStatus->lParkID > 0)))
			{
				
				lLen = sprintf(szTmp, "��λ:%lu    ʱ��:%s    ����:%s ʻ��\r\n",
					          pstParkStatus->lParkID,
					          pstParkStatus->szSampleTime,
							  pstParkStatus->szCarPlate);
				fwrite(szTmp,1,lLen, fp);
			}

			/* �糵λ�澯 */
			if ((1 == pstParkStatus->lParkingLotStatus) && ((pstParkStatus->lParkID <= 3) && (pstParkStatus->lParkID > 0)) && (1 == pstParkStatus->lCrossAlarm))
			{
				
				lLen = sprintf(szTmp, "��λ:%lu    ʱ��:%s  ����:%s �糵λ\r\n",
					          pstParkStatus->lParkID,
					          pstParkStatus->szSampleTime,
							  pstParkStatus->szCarPlate);
				fwrite(szTmp,1,lLen, fp);
			}

		    fclose(fp);
			break;
        }

        case IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT_EX://��λ״̬�ϱ���ʶ(��):164
        {
            printf("Device Park Status ReportEx.\n");
            
            IMOS_MW_PARK_STATUS_EX_S *stParkStatusEx = (IMOS_MW_PARK_STATUS_EX_S *)pParam;
			sprintf(szTmp, "%s\\ParkingInfo.txt", szTmp);

			FILE *fp =fopen(szTmp,"a+");

			/* ��������λ */
			if ((0 == stParkStatusEx->stParkStatus.lParkingLotStatus) && ((stParkStatusEx->stParkStatus.lParkID <= 3) && (stParkStatusEx->stParkStatus.lParkID > 0)))
			{
                
			 lLen = sprintf(szTmp, "��λ:%lu    ʱ��:%s  ����:%s ʻ��\r\n",
						stParkStatusEx->stParkStatus.lParkID,
						stParkStatusEx->stParkStatus.szSampleTime,
						stParkStatusEx->stParkStatus.szCarPlate);
					fwrite(szTmp,1,lLen, fp);
			}

			/* ����ʻ�복λ */
			if ((1 == stParkStatusEx->stParkStatus.lParkingLotStatus) && ((stParkStatusEx->stParkStatus.lParkID <= 3) && (stParkStatusEx->stParkStatus.lParkID > 0)))
			{
              lLen = sprintf(szTmp, "��λ:%lu    ʱ��:%s    ����:%s ʻ��\r\n",
						stParkStatusEx->stParkStatus.lParkID,
						stParkStatusEx->stParkStatus.szSampleTime,
						stParkStatusEx->stParkStatus.szCarPlate);
					fwrite(szTmp,1,lLen, fp);
			}

			/* �糵λ�澯 */
			if ((1 == stParkStatusEx->stParkStatus.lParkingLotStatus) && ((stParkStatusEx->stParkStatus.lParkID <= 3) && (stParkStatusEx->stParkStatus.lParkID > 0)) && (1 == stParkStatusEx->stParkStatus.lCrossAlarm))
			{
              lLen = sprintf(szTmp, "��λ:%lu    ʱ��:%s  ����:%s �糵λ\r\n",
						stParkStatusEx->stParkStatus.lParkID,
						stParkStatusEx->stParkStatus.szSampleTime,
						stParkStatusEx->stParkStatus.szCarPlate);
					fwrite(szTmp,1,lLen, fp);
			}
			fclose(fp);
			break;
        }
        
        default:
	    {	
            break;
        }
    }
    
    return;
}

//Demo�˵���ʾ
VOID showMenu()
{
    printf("\n\n");
    printf("*****************************************************************************\n");
    printf("*-1: quit.                                                                  *\n");
    printf("*00: Show menu.                                                             *\n");
    printf("*01: Show device's basic info.                                              *\n");
    printf("*02: Device reboot.                                                         *\n");
    printf("*03: Start jpeg media stream1 new.                                          *\n");
    printf("*04: Start jpeg media stream2 old.                                          *\n");
    printf("*05: Start jpeg media stream Pic Server.                                    *\n");
    printf("*06: Stop jpeg media stream.                                                *\n");
    printf("*07: Manual capture.                                                        *\n");
    printf("*08: Export black&white list file.                                          *\n"); 
    printf("*09: Import black&white list file.                                          *\n");
    printf("*10: Get device's system time.                                              *\n");
    printf("*11: Set device's system time.                                              *\n");
    printf("*12: Set CarPlate GBK or UTF.                                               *\n");
    printf("*13: Get device's Online.                                                   *\n");
    printf("*14: Multi-Device Login&StartStream.                                        *\n");
    printf("*15: Get Osd style.                                                         *\n");
    printf("*16: Set Osd style.                                                         *\n");
    printf("*17: Get Osd Info.                                                          *\n");
    printf("*18: Set Osd Info.                                                          *\n");
    printf("*****************************************************************************\n");        
    printf("please chose:\n");
}

//Demo��ȡ�û���¼��Ϣ
ULONG getLoginInfo(CHAR *pcDeviceIP, CHAR *pcUserName, CHAR *pcPassword)
{
    printf("Please input device IP:\n");
    if (EOF == scanf("%s", pcDeviceIP))
    {
        printf("scanf error.\n");
        return 1;
    }

    printf("Please input user name:\n");
    if (EOF == scanf("%s", pcUserName))
    {
        printf("scanf error.\n");
        return 1;
    }

    printf("Please input password:\n");
    if (EOF == scanf("%s", pcPassword))
    {
        printf("scanf error.\n");
        return 1;
    }

    printf("Device IP: %s, User name: %s, Password: %s.\n", pcDeviceIP, pcUserName, pcPassword);

    return ERR_COMMON_SUCCEED;
}


/***************���豸��¼��Ϣ*******************/
typedef struct tagLoginfo       
    {                    
        CHAR szDeviceIp[128];       //�豸IP
        CHAR szAdmin[128];          //��¼�û���   
        CHAR szPassWard[128];       //��¼����
        CHAR szUserID[128];         //�û�ID(��¼�ɹ��󷵻�)
        ULONG ulCaptureStreamHandle; //�����(����ʱ���룬�ɹ�ʱ����)
        BOOL_T bLogined;             //��¼��ʶ(BOOL_TRUE:��¼�ɹ���BOOL_FLASE:��¼ʧ�ܻ�δ��¼)
        BOOL_T bPicStreamed;         //������ʶ(BOOL_TRUE:�����ɹ���BOOL_FLASE:����ʧ�ܻ�δ����)
     }LOGIN_INFO_S;

INT iDevNum = 0;                     //���豸����
LOGIN_INFO_S stuLoginInfo[7] = {0};  

/****************���豸��¼�߳�******************/
int STDCALL ServerLoginThread(void* pUser)
{
  ULONG ulRet = ERR_COMMON_SUCCEED;
  INT iCount = 0;
  int i = 0;

  while(1)
  {
    if(iDevNum == iCount)
   {
     return 0;
   }

   for(i = 0; i < iDevNum; i++)
   {
    if(stuLoginInfo[i].bLogined == BOOL_FALSE)
    {
      ulRet = IMOS_MW_Login(stuLoginInfo[i].szAdmin,stuLoginInfo[i].szPassWard, stuLoginInfo[i].szDeviceIp, 0, stuLoginInfo[i].szUserID);
                   
      if(ERR_COMMON_SUCCEED != ulRet)
      {
        printf("Login Fail DeviceIp[%s],Index[%d]\n", stuLoginInfo[i].szDeviceIp,i);
      }
      else
      {
        printf("Login succeed DeviceIp[%s],Index[%d]\n", stuLoginInfo[i].szDeviceIp,i);
        stuLoginInfo[i].bLogined = BOOL_TRUE;
        iCount++;
      }
     } 
   }  
   
   }
}

/*****************���豸�����߳�**************************/
int STDCALL ServerStartMideaThread(void* pUser)
{
 
 ULONG ulRet = ERR_COMMON_SUCCEED;
 INT iCount = 0;
 int i = 0;
 
 while(1)
 {
  if(iDevNum == iCount)
  {
    return 0;
  }

  for(i = 0; i < iDevNum; i++)
  {
    if(stuLoginInfo[i].bPicStreamed == BOOL_FALSE && stuLoginInfo[i].bLogined == BOOL_TRUE)
    {
        ulRet = IMOS_MW_SetPicStreamDataCallback(stuLoginInfo[i].szUserID, 0, "", (IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF)GetPictureCB, &(stuLoginInfo[i].ulCaptureStreamHandle));
        if(ERR_COMMON_SUCCEED != ulRet)
        {
          printf("SetPicStream Fail DeviceIp[%s]\n", stuLoginInfo[i].szDeviceIp);
        }
        else
        {
          printf("SetPicStream Succeed DeviceIp[%s]\n", stuLoginInfo[i].szDeviceIp);
          stuLoginInfo[i].bPicStreamed = BOOL_TRUE;
          iCount++;
        }
    }
  }
 }
     
}

/*OSD���û�ȡ:����μ��ṹ��IMOS_MW_OSD_STYLE_CFG_S*/
ULONG GetOsdStyleCfg(CHAR *pcUserID)
{
    ULONG ulRet = ERR_COMMON_SUCCEED;
    ULONG ulStyleCfgsSize;
    IMOS_MW_OSD_STYLE_CFG_S *stuStyleCfgs = NULL;
    stuStyleCfgs = malloc(sizeof(IMOS_MW_OSD_STYLE_CFG_S));
    ulStyleCfgsSize = sizeof(IMOS_MW_OSD_STYLE_CFG_S);
    ulRet = IMOS_MW_GetConfig(pcUserID,IMOS_MW_OSD_STYLE_CFG,0,&ulStyleCfgsSize,(VOID *)stuStyleCfgs);
    stuStyleCfgs = (IMOS_MW_OSD_STYLE_CFG_S*)stuStyleCfgs;
    if (ERR_COMMON_SUCCEED != ulRet)
    {
      printf("Get OSD Style Fail!\n"); 
      return 1;
    }
    else
    {
        //OSD������ʽ
       if(stuStyleCfgs->ulFontStyle == IMOS_MW_OSD_FONT_STYLE_BACKGROUND)
       {
          printf("OSD Style Font:BACKGROUND\n");  
       }
       else if(stuStyleCfgs->ulFontStyle == IMOS_MW_OSD_FONT_STYLE_STROKES)
       {
          printf("OSD Style Font:STROKES\n");  
       }
       else if(stuStyleCfgs->ulFontStyle == IMOS_MW_OSD_FONT_STYLE_HOLLOW)
       {
          printf("OSD Style Font:HOLLOW\n");  
       }
       else if(stuStyleCfgs->ulFontStyle == IMOS_MW_OSD_FONT_STYLE_NORMAL)
       {
          printf("OSD Style Font:NORMAL\n");  
       }

       //OSD�����С
       if(stuStyleCfgs->ulFontSize == IMOS_MW_OSD_FONT_SIZE_LARGE)
       {
          printf("OSD Style FontSize:LARGE \n");  
       }
       else if(stuStyleCfgs->ulFontSize == IMOS_MW_OSD_FONT_SIZE_MIDDLE)
       {
          printf("OSD Style FontSize:MIDDLE \n");  
       }
       else if(stuStyleCfgs->ulFontSize == IMOS_MW_OSD_FONT_SIZE_SMALL)
       {
          printf("OSD Style FontSize:SMALL \n");  
       }

       //OSD��ɫ
       if(stuStyleCfgs->ulColor == IMOS_MW_OSD_COLOR_WHITE)
       {
          printf("OSD Style color:WHITE \n");  
       }
       else if(stuStyleCfgs->ulColor == IMOS_MW_OSD_COLOR_RED)
       {
          printf("OSD Style color:RED \n");  
       }
       else if(stuStyleCfgs->ulColor == IMOS_MW_OSD_COLOR_YELLOW)
       {
          printf("OSD Style color:YELLOW \n");  
       }
       else if(stuStyleCfgs->ulColor == IMOS_MW_OSD_COLOR_BLUE)
       {
          printf("OSD Style color:BLUE \n");  
       }
       else if(stuStyleCfgs->ulColor == IMOS_MW_OSD_COLOR_BLACK)
       {
          printf("OSD Style color:BLACK \n");  
       }
       else if(stuStyleCfgs->ulColor == IMOS_MW_OSD_COLOR_GREEN)
       {
          printf("OSD Style color:GREEN \n");  
       }
       else if(stuStyleCfgs->ulColor == IMOS_MW_OSD_COLOR_PURPLE)
       {
          printf("OSD Style color:PURPLE \n");  
       }
    }
    return 0;
}

/*OSD�����·�:����μ��ṹ��IMOS_MW_OSD_STYLE_CFG_S*/
ULONG SetOsdStyleCfg(CHAR *pcUserID)
{
   ULONG ulRet = ERR_COMMON_SUCCEED;
   IMOS_MW_OSD_STYLE_CFG_S stuStyleCfgs;
   ULONG ulStyleCfgsSize = sizeof(IMOS_MW_OSD_STYLE_CFG_S);

   //����:͸����(��͸��)�������С(��)�����ڸ�ʽ(XXXX-XX-XX ������)
   //������ʽ(����)��������ɫ(��)�����ڸ�ʽ(XXXX-XX-XX ������)��ʱ���ʽ
   stuStyleCfgs.ulAlpha = IMOS_MW_OSD_ALPHA_NO;
   stuStyleCfgs.ulFontSize = IMOS_MW_OSD_FONT_SIZE_MIDDLE;
   stuStyleCfgs.ulDateFormat = IMOS_MW_DATE_FORMAT_YYYYMMDD;
   stuStyleCfgs.ulFontStyle = IMOS_MW_OSD_FONT_STYLE_NORMAL;
   stuStyleCfgs.ulColor = IMOS_MW_OSD_COLOR_BLACK;
   stuStyleCfgs.ulFontType = IMOS_MW_OSD_FONT_TYPE_STANDARD;
   stuStyleCfgs.ulTimeFormat = IMOS_MW_TIME_FORMAT_HHMMSS;
   
   ulRet = IMOS_MW_SetConfig(pcUserID,IMOS_MW_OSD_STYLE_CFG,0,ulStyleCfgsSize,&stuStyleCfgs);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
	  printf("Set OSD Style Fail!\n"); 
      return 1;	
	}
    printf("Set OSD Style Succeed!\n"); 
  
    return 0;
}

/*OSD�����·�:����μ��ṹ��IMOS_MW_INFO_OSD_CFG_S*/
ULONG GetOsdInfoCfg(CHAR *pcUserID)
{
   ULONG ulRet = ERR_COMMON_SUCCEED;
   ULONG ulInfoCfgsSize;
   IMOS_MW_INFO_OSD_CFG_S *stuInfoOsdCfgs = NULL;
   stuInfoOsdCfgs = malloc(sizeof(IMOS_MW_INFO_OSD_CFG_S));
   ulInfoCfgsSize = sizeof(IMOS_MW_INFO_OSD_CFG_S); 

   ulRet = IMOS_MW_GetConfig(pcUserID,IMOS_MW_OSD_STYLE_CFG,0,&ulInfoCfgsSize,(VOID *)stuInfoOsdCfgs);
   if (ERR_COMMON_SUCCEED != ulRet)
	{
        printf("Get OSD Info Fail!\n"); 
	    return 1;		
	}
   printf("Get OSD Info Succeed!\n"); 
  
   return 0;
}

/*OSD�����·�:����μ��ṹ��IMOS_MW_INFO_OSD_CFG_S*/
ULONG SetOsdInfoCfg(CHAR *pcUserID)
{
   ULONG ulRet = ERR_COMMON_SUCCEED;
   ULONG ulTestLen = 0;
   CHAR szValue[IMOS_MW_OSD_INFO_LEN + 4] = {0};
   IMOS_MW_INFO_OSD_CFG_S stuInfoOsdCfgs;

   memset(&stuInfoOsdCfgs,0,sizeof(IMOS_MW_INFO_OSD_CFG_S));

   //��������1��
   stuInfoOsdCfgs.ulAreaNum = 1;

   //����ID��ʹ��(��ͬ����Ӧ���費ͬID)
   stuInfoOsdCfgs.astInfoOSD[0].ulIndex = 0;
   stuInfoOsdCfgs.astInfoOSD[0].bEnable = 1;

   //������������
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stBotRight.ulX = 100;
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stBotRight.ulY = 100;
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stTopLeft.ulX = 0;
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stTopLeft.ulY = 0;

   ulTestLen = sizeof(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[0].szValue);
   
   //ע����Ҫ�����Լ������ݣ���Ҫ��������������ulInfoType����ΪIMOS_MW_OSD_INFO_TYPE_USERDEF���Զ��壩��
   //ע��ṹ������ַ�������ΪUTF-8��ʽ������Ӱ��������ַ���Ԥ��ת��ΪUTF-8

    printf("Please input Osd Test:\n");
    if (EOF == scanf("%s", szValue))
    {
        printf("scanf error.\n");
        return 1;
    }

   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[0].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[0].szValue,szValue,ulTestLen);
  
   #if 0
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[0].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[0].szValue,"Test-One",ulTestLen);
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[1].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[1].szValue,"Test-Two",ulTestLen);
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[2].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[2].szValue,"Test-Three",ulTestLen);
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[3].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[3].szValue,"Test-Four",ulTestLen);
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[4].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[4].szValue,"Test-Five",ulTestLen);
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[5].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[5].szValue,"Test-Six",ulTestLen);
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[6].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[6].szValue,"Test-Seven",ulTestLen);
   stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[7].ulInfoType = IMOS_MW_OSD_INFO_TYPE_USERDEF;
   strncpy(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[7].szValue,"Test-Eight",ulTestLen);
   #endif

   
   ULONG ulRealBuff = sizeof(IMOS_MW_INFO_OSD_CFG_S);
   if (stuInfoOsdCfgs.ulAreaNum > 1)
   {
       ulRealBuff += (stuInfoOsdCfgs.ulAreaNum - 1) * sizeof(IMOS_MW_INFO_OSD_S);
   }
    
   ulRet = IMOS_MW_SetConfig(pcUserID,IMOS_MW_INFO_OSD_CFG,0,ulRealBuff,&stuInfoOsdCfgs);
   if (ERR_COMMON_SUCCEED != ulRet)
	{
        printf("Set OSD Info Fail!\n"); 	
		return 1;	
	}

   printf("Set OSD Info Succeed!\n"); 
   return 0;

}


//Demo������
int main(int argc, char *argv[])
{  
    LONG lRet = 0;
    ULONG ulRet = 0;
    INT lChoice = 0;
    ULONG ulCaptureStreamHandle = 0xffffffff;
    CHAR szUserID[128] = {0};
    UCHAR szSDKVersion[IMOS_MW_SDK_CLIENT_VERSION_LEN] = {0};
    CHAR szDeviceIP[IMOS_MW_IPADDR_LEN] = {0};
    CHAR szUserName[IMOS_MW_USER_NAME_LEN] = {0};
    CHAR szPassword[64] = {0};
    BOOL_T bRet = BOOL_FALSE;
    BOOL_T bEnable = BOOL_FALSE;

    /*SDK��ʼ��:ֻ���ʼ��һ��*/
    ulRet = IMOS_MW_Initiate();   
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("Initiate failed, return value: %lu.\n", ulRet);	
        return 0;
    }
    else
    {
        printf("Initiate succeed.\n");
    }

    /* ����Ŀ¼����log��ѡ */
    lRet = mkdir("./sdcard", 0755);
    
    /*SDK��ȡ�汾��*/
    ulRet = IMOS_MW_GetSDKVersion(szSDKVersion);
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_GetSDKVersion failed, return value: %lu.\n", ulRet);	
        return 0;
    }
    else
    {
        printf("IMOS_MW_GetSDKVersion succeed, SDK Version: %s.\n", szSDKVersion);
    }

    /*SDK������־*/
    ulRet = IMOS_MW_SetLog(IMOS_SDK_LOG_DEBUG, "./", 5*100);
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_SetLog failed, return value: %lu.\n", ulRet);	
    }
    else
    {
        printf("IMOS_MW_SetLog succeed.\n");
    }

    /* SDK����״̬�ϱ��ص� StatusReportCallBackFunEx
       ��λ״̬�ϱ�(164)
       ���������쳣(0)(SDK�ڲ�ʵ���������ⲿ���������������)
       ��Ƭ�������쳣(201) (SDK�ڲ�ʵ���������ⲿ���������������)*/
    ulRet = IMOS_MW_SetStatusCallback((IMOS_MW_STATUS_REPORT_CALLBACK_PF)StatusReportCallBackFunEx);
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_SetStatusCallback failed, return value: %lu.\n", ulRet); 
    }
    else
    {
        printf("IMOS_MW_SetStatusCallback succeed.\n");
    }
    /*Demo��ȡ�豸��¼��Ϣ*/
    ulRet = getLoginInfo(szDeviceIP, szUserName, szPassword);
    if(ERR_COMMON_SUCCEED != ulRet)  
    {       
       printf("Get login info failed.\n");
       return 0;
    }
    /*SDK�豸��¼,�ⲿ�˿�80(SDK�����豸�˿�80��81��554)*/
    ulRet = IMOS_MW_Login(szUserName, szPassword, szDeviceIP, 80, szUserID);   
    if(ERR_COMMON_SUCCEED != ulRet)  
    {       
       printf("IMOS_MW_Login failed, return value: %lu.\n", ulRet);
       return 0;
    }    
    else   
    {      
       printf("Login succeed, device IP: %s.\n", szDeviceIP); 
       gbLogin = BOOL_TRUE;   
    }
    /*Demo��ʾ�˵�*/
    showMenu();
    while (lChoice != -1)
    {
        if (EOF == scanf("%d", &lChoice))
        {
            printf("scanf error lChoice[%d]!\n", lChoice);
            break;
        }
  
        if (BOOL_TRUE == gbLogin)
        {
            switch(lChoice)
            {
                case 0://Demo�˵���ʾ
                {
                    showMenu();
                    break;
                }

                case 1://SDK��ȡ�豸������Ϣ
                {
                    IMOS_MW_BASIC_DEVICE_INFO_S stBasicInfo;
                    memset(&stBasicInfo, 0, sizeof(stBasicInfo));
                    ulRet = IMOS_MW_GetDeviceStatus(szUserID, 0, IMOS_MW_STATUS_BASIC_INFO, (void *)&stBasicInfo);
                    if(ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("GetDeviceStatus Error[%lu]\n", ulRet);
                        break; 
                    }
                    printf("Manufacturer:%s\n", stBasicInfo.szManufacturer);
                    printf("Model and configuration:%s\n", stBasicInfo.szDeviceModel);
                    printf("Firmware version:%s\n", stBasicInfo.szFirmwareVersion);
                    printf("Hardware version:%s\n", stBasicInfo.szHardwareID);
                    printf("Uboot versionUBOOT:%s\n", stBasicInfo.szUbootVersion);
                    printf("Serial number:%s\n", stBasicInfo.szSerialNumber);
                    printf("MAC address:%s\n", stBasicInfo.szDeviceMAC);
                    printf("PCB version:%s\n", stBasicInfo.szPCBVersion);                                      

                    break;
                }
                
                case 2://SDK�豸����
                {
                    ulRet = IMOS_MW_Reboot(szUserID);
                    if(ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Reboot failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Reboot succeed.\n");
                    }
                    
                    break;
                }
                
                case 3://SDK������Ƭ��(�Ƕ���������ʽ SDK�ڲ��˿�53000-53999):�½ӿ� ��ʽһ(����+���ûص�(IMOS_MW_GetPicture))
                {
                    ulRet = IMOS_MW_SetPicStreamDataCallback(szUserID, 0, "", (IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF)GetPictureCB, &ulCaptureStreamHandle);
                    if(ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Start jpeg media stream1, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Start jpeg media stream1 succeed handle[%lu].\n",ulCaptureStreamHandle);
                    }
 
                    break;
                }
                
                case 4://SDK������Ƭ��(�Ƕ���������ʽ SDK�ڲ��˿�53000-53999):�ɽӿ� ��ʽ��(����+���ûص�(IMOS_MW_GetPicture))
                {
                   ulRet = IMOS_MW_StartMediaStream(szUserID, 0, IMOS_MW_STREAM_ID_AUX, IMOS_MW_TRANSFER_MODE_UNIVIEW1_TCP, "", 0, 1, &ulCaptureStreamHandle);                    
                   if(ERR_COMMON_SUCCEED != ulRet)                   
                    {                       
                       printf("Start jpeg media stream2 Error[%lu].\n", ulRet);      
                       break;                   
                    }                   
                   printf("Start jpeg media stream2 succed handle[%lu].\n", ulCaptureStreamHandle); 
                   IMOS_MW_MultiUser_SetPicDataCallback((IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF)GetPictureCB, ulCaptureStreamHandle);
                   break;              
                 }
                
                case 5://SDK������Ƭ��(����������ʽ SDK�ڲ��˿�5196):�ɽӿ� ��ʽ��(����+���ûص�(GetPictureCB))
                {
                    CHAR szLocalIP[IMOS_MW_IPADDR_LEN] = {0};

                    printf("Please input local computer's IP:\n");
                    if (EOF == scanf("%s", szLocalIP))
                    {
                        printf("scanf error.\n");
                        break;
                    }
                    else
                    {
                        printf("Local IP: %s.\n", szLocalIP);
                    }
                    
                    ulRet = IMOS_MW_SetPicStreamDataCallback(szUserID, 1, szLocalIP, (IMOS_MW_TMS_MULTIUSER_PIC_UPLOAD_PF)GetPictureCB, &ulCaptureStreamHandle);
                    if(ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Start jpeg media stream Pic Server failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Start jpeg media stream with continuous transmission succeed.\n");
                    }
 
                    break;
                }
                
                case 6://SDKֹͣ��Ƭ��
                {
                    ulRet = IMOS_MW_StopMediaStream(szUserID, ulCaptureStreamHandle);
                    if(ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("\nStop jpeg MediaStream failed, streamHandle: %lu, return value: %lu.\n", ulCaptureStreamHandle, ulRet);
                    }
                    else
                    {
                        printf("\nStop jpeg MediaStream succeed, streamHandle: %lu.\n", ulCaptureStreamHandle);
                    }
                    
                    break;
                }
                
                case 7://SDK�ֶ�ץ�ģ���������ͨ�������ص�(IMOS_MW_GetPicture)�����ϱ�
                {
                    ulRet = IMOS_MW_Capture(szUserID, 0, NULL, NULL);
                    if(ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Manual capture failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Manual capture succeed.\n");
                    }
                    
                    break;
                }

                case 8://SDK�����ڰ������ļ�(�ļ�������ΪGateBlacklist.csv(������)��GateWhitelist.csv(������))
                {
                    
                    ulRet = IMOS_MW_ExportWhiteBlackListFile(szUserID, "./BlackWhiteList/GateBlacklist.csv");
                    if (ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Export black list failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Export black list succeed.\n");
                    }
                
                    ulRet = IMOS_MW_ExportWhiteBlackListFile(szUserID, "./BlackWhiteList/GateWhitelist.csv");
                    if (ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Export white list failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Export white list succeed.\n");
                    }
                     
                    break;
                }
                
                case 9://SDK����ڰ������ļ�(�ļ�������ΪGateBlacklist.csv(������)��GateWhitelist.csv(������))
                {
                    ulRet = IMOS_MW_ImportWhiteBlackListFile(szUserID, "./BlackWhiteList/GateBlacklist.csv");
                    if (ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Import black list failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Import black list succeed.\n");
                    }
                     
                    ulRet = IMOS_MW_ImportWhiteBlackListFile(szUserID, "./BlackWhiteList/GateWhitelist.csv");
                    if (ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Import white list failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Import white list succeed.\n");
                    }
                        
                     break;
                }

                case 10://SDK��ȡ�豸ϵͳʱ��
                {
                    ULONG ullen = sizeof(gstTime);      
   
                    ulRet = IMOS_MW_GetConfig(szUserID, IMOS_MW_SYSTEM_TIME_INFO, 0, &ullen, &gstTime);
                    if (ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Get device's system time failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        printf("Get device's system time succeed, Time zone:%ld, System time:%hu-%hu-%hu %hu:%hu:%hu\n", gstTime.lTimeZone,
                               gstTime.stLocalTime.usYear, gstTime.stLocalTime.usMonth, gstTime.stLocalTime.usMonthDay, gstTime.stLocalTime.usHour,
                               gstTime.stLocalTime.usMinute, gstTime.stLocalTime.usSecond);
                    }

                    break;
                }

                case 11://SDK�����豸ϵͳʱ��
                {
                    ULONG ullen = sizeof(gstTime);
                    gstTime.stLocalTime.usHour += 1;
                    
                    ulRet = IMOS_MW_SetConfig(szUserID, IMOS_MW_SYSTEM_TIME_INFO, 0, ullen, &gstTime);
                    if (ERR_COMMON_SUCCEED != ulRet)
                    {
                        printf("Set device's system time failed, return value: %lu.\n", ulRet);
                    }
                    else
                    {
                        IMOS_MW_GetConfig(szUserID, IMOS_MW_SYSTEM_TIME_INFO, 0, &ullen, &gstTime);
                        printf("Set device's system time succeed, Time zone:%ld, System time:%hu-%hu-%hu %hu:%hu:%hu.\n", gstTime.lTimeZone,
                               gstTime.stLocalTime.usYear, gstTime.stLocalTime.usMonth, gstTime.stLocalTime.usMonthDay, gstTime.stLocalTime.usHour,
                               gstTime.stLocalTime.usMinute, gstTime.stLocalTime.usSecond);
                    }

                    break;
                }
                
                case 12://SDK���ó�����Ϣ�����ʽ(Ĭ��:UTF-8)
                {
                    printf("EnableCarplate UTF:1,GBK:0\n");
                   if (EOF == scanf("%d", &lChoice))
                    {
                      printf("scanf UTF or GBK:[%d]!\n", lChoice);
                      break;
                    }

                   bRet = IMOS_MW_EnableCarplate(lChoice);
                   if(BOOL_TRUE == bRet)                   
                    {   
                        if(0 == bEnable)
                        {
                          printf("EnableCarplate GBK succeed!\n");
                        }
                        else
                        {
                          printf("EnableCarplate UTF succeed!\n");
                        }
                    
                       break;                   
                    } 
                   else
                   {
                      printf("EnableCarplate fail!\n");
                   }
                   break;              
                 } 
                case 13://SDK������ȡ�豸����״̬(bStatus:����:1,����:0)
                 {
                    BOOL_T bStatus = BOOL_FALSE;
                    bRet = IMOS_MW_GetOnlineStatus(szUserID, &bStatus);
                    if(BOOL_TRUE== bRet)
                    {
                      if(BOOL_TRUE == bStatus)
                      {
                        printf("Device Online!\n");
                      }
                      else
                      {
                        printf("Device Outline!\n");
                      }
                    }
                    else
                    {
                       printf("GetOnlineStatus Fail!\n");
                    }
                    break; 
                 }
                case 14: //���豸��¼����
                 {
                     //�����豸����
                     iDevNum = 7;   
                     //�豸��¼��Ϣ¼��
                     strcpy(stuLoginInfo[0].szDeviceIp,"192.174.1.148");
                     strcpy(stuLoginInfo[0].szAdmin,"admin");
                     strcpy(stuLoginInfo[0].szPassWard,"admin_123");
      
                     strcpy(stuLoginInfo[1].szDeviceIp,"192.174.1.177");
                     strcpy(stuLoginInfo[1].szAdmin,"admin");
                     strcpy(stuLoginInfo[1].szPassWard,"admin_123");
     
                     strcpy(stuLoginInfo[2].szDeviceIp,"192.174.1.171");
                     strcpy(stuLoginInfo[2].szAdmin,"admin");
                     strcpy(stuLoginInfo[2].szPassWard,"admin_123");
   
                     strcpy(stuLoginInfo[3].szDeviceIp,"192.174.1.172");
                     strcpy(stuLoginInfo[3].szAdmin,"admin");
                     strcpy(stuLoginInfo[3].szPassWard,"admin_123");
   
                     strcpy(stuLoginInfo[4].szDeviceIp,"192.174.1.173");
                     strcpy(stuLoginInfo[4].szAdmin,"admin");
                     strcpy(stuLoginInfo[4].szPassWard,"admin_123");
   
                     strcpy(stuLoginInfo[5].szDeviceIp,"192.174.1.184");
                     strcpy(stuLoginInfo[5].szAdmin,"admin");
                     strcpy(stuLoginInfo[5].szPassWard,"admin_123");
   
                     strcpy(stuLoginInfo[6].szDeviceIp,"192.174.1.153");
                     strcpy(stuLoginInfo[6].szAdmin,"admin");
                     strcpy(stuLoginInfo[6].szPassWard,"admin_123");

                     //������¼�������߳�(�����߳��ڷֱ���������豸�ĵ�¼����������)�߳�����=2 
                     //�����豸��ɵ�¼�������߳��˳�,�ܹ���֤��¼ʧ���豸�ܹ�������¼��
                     lRet =IMOS_SDK_thr_create((VOID *)ServerLoginThread, NULL, 0, 0, NULL, NULL);
                     if (lRet < 0)
                      {
                        printf("ServerLoginThread fail IP:%s\n");     
                      }
                      else
                      {
                        printf("ServerLoginThread Succeed\n"); 
                      }

                     lRet =IMOS_SDK_thr_create((VOID *)ServerStartMideaThread, NULL, 0, 0, NULL, NULL);
                     if (lRet < 0)
                     {
                       printf("IStartMideaThread fail\n");     
                     }

                     break;
                 }
                case 15://��ȡOSD������ʽ
                    {
                       ulRet = GetOsdStyleCfg(szUserID);
                       break;
                     }
                case 16://����OSD������ʽ
                    {
                       ulRet = SetOsdStyleCfg(szUserID);
                       break;
                    }
                case 17://��ȡOSD����
                    {
                       ulRet = GetOsdInfoCfg(szUserID);
                       break;
                    }
                case 18://����OSD����
                    {
                       ulRet = SetOsdInfoCfg(szUserID);
                       break;
                    }
                default:
                {
                    break; 
                }
            }
        }
    }

    //SDK�豸�ǳ�(���¼���ö�Ӧ)
    ulRet = IMOS_MW_Logout(szUserID);
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_Logout failed, return value: %lu.\n", ulRet);
    }
    else
    {
        printf("IMOS_MW_Logout succeed.\n");
    }
    //SDK����ʼ��(���ʼ�����ö�Ӧ)
    ulRet = IMOS_MW_Cleanup();
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_Cleanup failed, return value: %lu.\n", ulRet);
    }
    else
    {
        printf("IMOS_MW_Cleanup succeed.\n");
    }
    
    return 0;
}
