#ifndef __LCD_H__
#define __LCD_H__

#include "stdint.h"
#include "main.h"  // 包含HAL库和GPIO定义

// 设置横屏/竖屏显示：0/1=竖屏，2/3=横屏
#define USE_HORIZONTAL 2

// 根据屏幕方向定义分辨率
#if USE_HORIZONTAL == 0 || USE_HORIZONTAL == 1
#define LCD_W 80
#define LCD_H 160
#else
#define LCD_W 160
#define LCD_H 80
#endif

// GPIO操作宏（HAL库）
#define LCD_DC_DATA_MODE() HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET)
#define LCD_DC_CMD_MODE()  HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET)

#define LCD_RST_START() HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET)
#define LCD_RST_END()   HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET)

#define LCD_CS_ENABLE()  HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET)
#define LCD_CS_DISABLE() HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET)

#define LCD_BL_ENABLE()  HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_RESET)
#define LCD_BL_DISABLE() HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET)

// 函数声明补充（裸机环境需完整声明）
void LCD_Init(void);
void LCD_WR_DATA(uint16_t dat);
void LCD_WR_DATA8(uint8_t dat);  // 补充8位数据写入声明
void LCD_WR_REG(uint8_t dat);    // 补充命令写入声明
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_Writ_Bus(uint8_t dat);  // 补充SPI总线写入声明（可选，若需外部调用）

// 可选：添加常用显示函数声明（如清屏、画点）
void LCD_Clear(uint16_t color);
void LCD_DrawPoint(uint16_t x, uint16_t y, uint16_t color);
void LCD_Driver_Init(void);

#endif
