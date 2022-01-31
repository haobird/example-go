#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/stat.h> 
#include <sys/types.h> 

#include "imos_sdk_def.h"  //SDK宏定义头文件
#include "imos_sdk_pub.h"  //SDK结构体定义头文件
#include "imos_sdk_func.h" //SDK接口定义头文件

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

    /* 接收多个参数 */
    va_start(stParalist, pcFormat);

    /* 调用ACE系统函数 */
    lRet = (LONG) vsnprintf(pcBuf, (size_t) ulMaxlen, pcFormat, stParalist);

    /* 释放参数资源 */
    va_end(stParalist);

    return lRet;
}


//Demo过车信息上报回调接口实现
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

//Demo状态上报接口实现
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
        case IMOS_MW_STATUS_KEEPALIVE://设备离线状态标识:0
        {
            /*keepalive*/
            printf("Device Outline, pcUserID:%s.\n", pcUserID);
           // gbLogin = BOOL_FALSE;
            break;
        }
        case IMOS_MW_STATUS_RLOGIN://设备内部重连成功状态标识:1
        {
            /*keepalive*/
            printf("Device Reconnet online, pcUserID:%s.\n", pcUserID);
           // gbLogin = BOOL_FALSE;
            break;
        }
        case IMOS_MW_STATUS_PLAYER_MEDIA_PROCESS://设备断流状态标识:201
	    {
            /*XP*/
            printf("Device OutPicStream, pcUserID:%s.\n", pcUserID);
            break;
        }
      
        case IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT://车位状态上报标识(旧):160
        {
            printf("Device Park Status Report.\n");
            
          	IMOS_MW_PARK_STATUS_S *pstParkStatus = (IMOS_MW_PARK_STATUS_S *)pParam;
            FILE *fp =fopen(szTmp,"a+");
            /* 车辆出车位 */
			if ((0 == pstParkStatus->lParkingLotStatus) && ((pstParkStatus->lParkID <= 3) && (pstParkStatus->lParkID > 0)))
			{
				
				lLen = sprintf(szTmp, "车位:%lu    时间:%s  车牌:%s 驶出\r\n",
					          pstParkStatus->lParkID,
					          pstParkStatus->szSampleTime,
							  pstParkStatus->szCarPlate);
				fwrite(szTmp,1,lLen, fp);
			}

			/* 车辆驶入车位 */
			if ((1 == pstParkStatus->lParkingLotStatus) && ((pstParkStatus->lParkID <= 3) && (pstParkStatus->lParkID > 0)))
			{
				
				lLen = sprintf(szTmp, "车位:%lu    时间:%s    车牌:%s 驶入\r\n",
					          pstParkStatus->lParkID,
					          pstParkStatus->szSampleTime,
							  pstParkStatus->szCarPlate);
				fwrite(szTmp,1,lLen, fp);
			}

			/* 跨车位告警 */
			if ((1 == pstParkStatus->lParkingLotStatus) && ((pstParkStatus->lParkID <= 3) && (pstParkStatus->lParkID > 0)) && (1 == pstParkStatus->lCrossAlarm))
			{
				
				lLen = sprintf(szTmp, "车位:%lu    时间:%s  车牌:%s 跨车位\r\n",
					          pstParkStatus->lParkID,
					          pstParkStatus->szSampleTime,
							  pstParkStatus->szCarPlate);
				fwrite(szTmp,1,lLen, fp);
			}

		    fclose(fp);
			break;
        }

        case IMOS_MW_STATUS_IVA_PARK_STATUS_REPORT_EX://车位状态上报标识(新):164
        {
            printf("Device Park Status ReportEx.\n");
            
            IMOS_MW_PARK_STATUS_EX_S *stParkStatusEx = (IMOS_MW_PARK_STATUS_EX_S *)pParam;
			sprintf(szTmp, "%s\\ParkingInfo.txt", szTmp);

			FILE *fp =fopen(szTmp,"a+");

			/* 车辆出车位 */
			if ((0 == stParkStatusEx->stParkStatus.lParkingLotStatus) && ((stParkStatusEx->stParkStatus.lParkID <= 3) && (stParkStatusEx->stParkStatus.lParkID > 0)))
			{
                
			 lLen = sprintf(szTmp, "车位:%lu    时间:%s  车牌:%s 驶出\r\n",
						stParkStatusEx->stParkStatus.lParkID,
						stParkStatusEx->stParkStatus.szSampleTime,
						stParkStatusEx->stParkStatus.szCarPlate);
					fwrite(szTmp,1,lLen, fp);
			}

			/* 车辆驶入车位 */
			if ((1 == stParkStatusEx->stParkStatus.lParkingLotStatus) && ((stParkStatusEx->stParkStatus.lParkID <= 3) && (stParkStatusEx->stParkStatus.lParkID > 0)))
			{
              lLen = sprintf(szTmp, "车位:%lu    时间:%s    车牌:%s 驶入\r\n",
						stParkStatusEx->stParkStatus.lParkID,
						stParkStatusEx->stParkStatus.szSampleTime,
						stParkStatusEx->stParkStatus.szCarPlate);
					fwrite(szTmp,1,lLen, fp);
			}

			/* 跨车位告警 */
			if ((1 == stParkStatusEx->stParkStatus.lParkingLotStatus) && ((stParkStatusEx->stParkStatus.lParkID <= 3) && (stParkStatusEx->stParkStatus.lParkID > 0)) && (1 == stParkStatusEx->stParkStatus.lCrossAlarm))
			{
              lLen = sprintf(szTmp, "车位:%lu    时间:%s  车牌:%s 跨车位\r\n",
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

//Demo菜单显示
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

//Demo获取用户登录信息
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


/***************多设备登录信息*******************/
typedef struct tagLoginfo       
    {                    
        CHAR szDeviceIp[128];       //设备IP
        CHAR szAdmin[128];          //登录用户名   
        CHAR szPassWard[128];       //登录密码
        CHAR szUserID[128];         //用户ID(登录成功后返回)
        ULONG ulCaptureStreamHandle; //流句柄(启流时传入，成功时返回)
        BOOL_T bLogined;             //登录标识(BOOL_TRUE:登录成功，BOOL_FLASE:登录失败或未登录)
        BOOL_T bPicStreamed;         //启流标识(BOOL_TRUE:启流成功，BOOL_FLASE:启流失败或未启流)
     }LOGIN_INFO_S;

INT iDevNum = 0;                     //多设备数量
LOGIN_INFO_S stuLoginInfo[7] = {0};  

/****************多设备登录线程******************/
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

/*****************多设备启流线程**************************/
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

/*OSD配置获取:具体参见结构体IMOS_MW_OSD_STYLE_CFG_S*/
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
        //OSD字体样式
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

       //OSD字体大小
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

       //OSD颜色
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

/*OSD配置下发:具体参见结构体IMOS_MW_OSD_STYLE_CFG_S*/
ULONG SetOsdStyleCfg(CHAR *pcUserID)
{
   ULONG ulRet = ERR_COMMON_SUCCEED;
   IMOS_MW_OSD_STYLE_CFG_S stuStyleCfgs;
   ULONG ulStyleCfgsSize = sizeof(IMOS_MW_OSD_STYLE_CFG_S);

   //例如:透明度(不透明)、字体大小(中)、日期格式(XXXX-XX-XX 年月日)
   //字体样式(正常)、字体颜色(黑)、日期格式(XXXX-XX-XX 年月日)、时间格式
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

/*OSD内容下发:具体参见结构体IMOS_MW_INFO_OSD_CFG_S*/
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

/*OSD内容下发:具体参见结构体IMOS_MW_INFO_OSD_CFG_S*/
ULONG SetOsdInfoCfg(CHAR *pcUserID)
{
   ULONG ulRet = ERR_COMMON_SUCCEED;
   ULONG ulTestLen = 0;
   CHAR szValue[IMOS_MW_OSD_INFO_LEN + 4] = {0};
   IMOS_MW_INFO_OSD_CFG_S stuInfoOsdCfgs;

   memset(&stuInfoOsdCfgs,0,sizeof(IMOS_MW_INFO_OSD_CFG_S));

   //叠加区域1个
   stuInfoOsdCfgs.ulAreaNum = 1;

   //区域ID和使能(不同区域应赋予不同ID)
   stuInfoOsdCfgs.astInfoOSD[0].ulIndex = 0;
   stuInfoOsdCfgs.astInfoOSD[0].bEnable = 1;

   //叠加区域坐标
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stBotRight.ulX = 100;
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stBotRight.ulY = 100;
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stTopLeft.ulX = 0;
   stuInfoOsdCfgs.astInfoOSD[0].stArea.stTopLeft.ulY = 0;

   ulTestLen = sizeof(stuInfoOsdCfgs.astInfoOSD[0].astInfoParam[0].szValue);
   
   //注意若要叠加自己的内容，需要将叠加内容类型ulInfoType设置为IMOS_MW_OSD_INFO_TYPE_USERDEF（自定义）；
   //注意结构体叠加字符内容需为UTF-8格式，如叠加包含汉字字符请预先转换为UTF-8

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


//Demo主函数
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

    /*SDK初始化:只需初始化一次*/
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

    /* 创建目录设置log可选 */
    lRet = mkdir("./sdcard", 0755);
    
    /*SDK获取版本号*/
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

    /*SDK设置日志*/
    ulRet = IMOS_MW_SetLog(IMOS_SDK_LOG_DEBUG, "./", 5*100);
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_SetLog failed, return value: %lu.\n", ulRet);	
    }
    else
    {
        printf("IMOS_MW_SetLog succeed.\n");
    }

    /* SDK设置状态上报回调 StatusReportCallBackFunEx
       车位状态上报(164)
       网络连接异常(0)(SDK内部实现重连，外部无需进行重连操作)
       照片流连接异常(201) (SDK内部实现重连，外部无需进行重连操作)*/
    ulRet = IMOS_MW_SetStatusCallback((IMOS_MW_STATUS_REPORT_CALLBACK_PF)StatusReportCallBackFunEx);
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_SetStatusCallback failed, return value: %lu.\n", ulRet); 
    }
    else
    {
        printf("IMOS_MW_SetStatusCallback succeed.\n");
    }
    /*Demo获取设备登录信息*/
    ulRet = getLoginInfo(szDeviceIP, szUserName, szPassword);
    if(ERR_COMMON_SUCCEED != ulRet)  
    {       
       printf("Get login info failed.\n");
       return 0;
    }
    /*SDK设备登录,外部端口80(SDK访问设备端口80、81、554)*/
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
    /*Demo显示菜单*/
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
                case 0://Demo菜单显示
                {
                    showMenu();
                    break;
                }

                case 1://SDK获取设备基本信息
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
                
                case 2://SDK设备重启
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
                
                case 3://SDK开启照片流(非断网续传方式 SDK内部端口53000-53999):新接口 方式一(启流+设置回调(IMOS_MW_GetPicture))
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
                
                case 4://SDK开启照片流(非断网续传方式 SDK内部端口53000-53999):旧接口 方式二(启流+设置回调(IMOS_MW_GetPicture))
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
                
                case 5://SDK开启照片流(断网续传方式 SDK内部端口5196):旧接口 方式二(启流+设置回调(GetPictureCB))
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
                
                case 6://SDK停止照片流
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
                
                case 7://SDK手动抓拍，过车数据通过启流回调(IMOS_MW_GetPicture)主动上报
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

                case 8://SDK导出黑白名单文件(文件名必须为GateBlacklist.csv(黑名单)、GateWhitelist.csv(白名单))
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
                
                case 9://SDK导入黑白名单文件(文件名必须为GateBlacklist.csv(黑名单)、GateWhitelist.csv(白名单))
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

                case 10://SDK获取设备系统时间
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

                case 11://SDK设置设备系统时间
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
                
                case 12://SDK设置车牌信息编码格式(默认:UTF-8)
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
                case 13://SDK主动获取设备在线状态(bStatus:在线:1,离线:0)
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
                case 14: //多设备登录启流
                 {
                     //接入设备数量
                     iDevNum = 7;   
                     //设备登录信息录入
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

                     //开启登录、启流线程(两个线程内分别进行所有设备的登录和启流操作)线程数量=2 
                     //所有设备完成登录启流后线程退出,能够保证登录失败设备能够继续登录。
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
                case 15://获取OSD配置样式
                    {
                       ulRet = GetOsdStyleCfg(szUserID);
                       break;
                     }
                case 16://设置OSD配置样式
                    {
                       ulRet = SetOsdStyleCfg(szUserID);
                       break;
                    }
                case 17://获取OSD内容
                    {
                       ulRet = GetOsdInfoCfg(szUserID);
                       break;
                    }
                case 18://设置OSD内容
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

    //SDK设备登出(与登录调用对应)
    ulRet = IMOS_MW_Logout(szUserID);
    if(ERR_COMMON_SUCCEED != ulRet)
    {
        printf("IMOS_MW_Logout failed, return value: %lu.\n", ulRet);
    }
    else
    {
        printf("IMOS_MW_Logout succeed.\n");
    }
    //SDK反初始化(与初始化调用对应)
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
