#include "usart1_logprintf.h"
/*
 * 调用函数LOG()可打印文件名称，函数名称，函数行数
 *
 */
// GCC newlib-nano库适配：标准流配置（必须保留）
struct __FILE {
    int handle;
};
FILE __stdout;  // 绑定标准输出到串口（printf依赖）

// GCC要求：printf → _write → fputc（核心链路，必须保留）
int _write(int file, char *ptr, int len) {
    (void)file;  // 忽略文件句柄，仅用串口输出
    for (int i = 0; i < len; i++) {
        fputc(ptr[i], &__stdout);  // 逐字符调用fputc发送
    }
    return len;  // 返回发送长度，满足newlib-nano要求
}

// 串口发送实现（必须保留，已验证正常）
int fputc(int ch, FILE *f) {
#if DEBUG_ENABLE
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 10);  // 超时10ms
#endif
    return ch;
}
