#Linux 版本SDK编译脚本

#定义交叉编译器（本版本适用于 NVR、DVR）
#CROSS_TOOL_PREFIX = /opt/hisi-linux/x86-arm/arm-hisiv200-linux/target/bin/arm-hisiv200-linux-
#CROSS_TOOL_PREFIX = /opt/arm-2009q1/bin/arm-none-linux-gnueabi-
#CROSS_TOOL_PREFIX = /opt/arm-2009q1/bin/arm-none-linux-gnueabi-
#CROSS_TOOL_PREFIX = /home/g00774/dh/usr/bin/x86_64-redhat-linux-gcc
#CROSS_TOOL_PREFIX = /home/l02773/arm-2011.03/bin/arm-none-linux-gnueabi-
#CROSS_TOOL_PREFIX = /home/l02773/freescale/usr/local/gcc-4.1.78-eglibc-2.5.78-1/powerpc-e300c3-linux-gnu/bin/powerpc-e300c3-linux-gnu-
#定义编译工具
CC      = $(CROSS_TOOL_PREFIX)gcc 
AR      = $(CROSS_TOOL_PREFIX)ar 
RANLIB  = $(CROSS_TOOL_PREFIX)ranlib 
LD      = $(CROSS_TOOL_PREFIX)ld 
STRIP   = $(CROSS_TOOL_PREFIX)strip 
OBJCOPY = $(CROSS_TOOL_PREFIX)objcopy 
NASM    = $(CROSS_TOOL_PREFIX)nasm

#定义工程根目录
CURR_MOD_DIR = $(CURDIR) 
PROJECT_DIR = $(CURDIR)/../../..

#定义本模块编译需要用到的扩展编译选项
EXTRA_CFLAGS    = -I ./../include  \
                  -I ./../../../include      \
                  -I ./  \
                  -I $(PROJECT_DIR)/MWareServer/src/sdk/sdkserver \
				  


EXTRA_LDFLAGS   = -L $(CURDIR)/../lib -pthread  -L$(CURDIR)/../lib -lrt  -L$(CURDIR)/../dll -lmw_sdk_bp

#定义SDK Client 各个模块目录所在位置
INCLUDE = $(PROJECT_DIR)/include 
SDK_CLIENT_DIR = $(PROJECT_DIR)/utility/sdkclient 
SDK_IMOS_DIR = $(SDK_CLIENT_DIR)/imos_mw_sdk_client 
SDK_IPC_DIR = $(SDK_CLIENT_DIR)/mw_ipc_client 
SDK_BP_DIR = $(SDK_CLIENT_DIR)/mw_sdk_bp 
SDK_INCLUDE = $(SDK_CLIENT_DIR)/include

#定义OBJ文件存放路径
OBJ_DIR = $(PROJECT_DIR)/utility/sdkclient/dll

#定义编译选项
DEBUG_COMPILE_FLAGS= -Wall -O0 -g 
RELEASE_COMPILE_FLAGS= -Wall -O2 
SHARED = -shared -fPIC  -o


TARGET = Demo 

TARGET_OBJ = Linux_main.o

all:$(TARGET)

.PHONY:all

$(TARGET) : $(TARGET_OBJ)
	$(CC) -o Demo Linux_main.o -L ./ libimos_mw_sdk.so libmw_sdk_player.so libmw_sdk_rm.so  libmw_sdk_ipc.so libmw_sdk_bp.so *.so -lpthread -lm -lrt -Wl,-rpath=:./
Linux_main.o : Linux_main.c 
	$(CC) -c  $(DEBUG_COMPILE_FLAGS) Linux_main.c
	 
clean: 
	@rm -f *.o Demo
	@echo "Clean successful"
