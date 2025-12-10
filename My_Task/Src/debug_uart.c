#include "main.h"
#include "usart.h"

void SendBytes(uint8_t *data, uint8_t len)
{
	if(data == NULL || len == 0) return;  // 增加参数校验
	HAL_UART_Transmit(&huart1, data, len, HAL_MAX_DELAY);  // 使用正确的串口句柄
}

