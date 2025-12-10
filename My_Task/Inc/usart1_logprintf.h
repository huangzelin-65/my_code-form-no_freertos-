#ifndef USART1_LOGPRINTF_H
#define USART1_LOGPRINTF_H

#include <string.h>
#include "stdio.h"
#include "usart.h"  // 关联CubeIDE自动生成的串口头文件（获取huart1句柄）

// 可选配置开关（无需修改参数，自适应CubeIDE配置）
#define DEBUG_ENABLE        1        // 1=开启打印，0=关闭（调试完直接设0）
#define USE_SHORT_FILENAME  1        // 1=仅显示文件名（如"main.c"），0=显示全路径

// 简化文件名（自动兼容Windows/Linux路径分隔符）
#if USE_SHORT_FILENAME
#define __FILE_SHORT__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : \
                       (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__))
#else
#define __FILE_SHORT__ __FILE__
#endif
//
// 核心调用宏：仅打印「文件名 | 函数名 : 行号」（USART1固定输出）
#if DEBUG_ENABLE
#define LOG()  do { \
	printf("[%s | %s : %d]\r\n", __FILE_SHORT__, __FUNCTION__, __LINE__);\
    uint8_t test_data[] = "test\r\n"; \
    HAL_UART_Transmit(&huart1, test_data, sizeof(test_data)-1, 10); \
} while(0)
#else
#define LOG()  // 关闭时为空，不生成任何代码
#endif

#endif // USART1_LOGPRINTF_H
