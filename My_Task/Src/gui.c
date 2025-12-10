#include <stdint.h>
#include "lcd.h"
#include "spi.h"       // 确保LCD底层SPI函数可调用（若lcd.h已包含可省略）
#include "zifu8x16.h"  // 字模库
#include "main.h"

// 画点函数
void GUI_Point(uint8_t x, uint16_t y, uint16_t color)
{
    // 边界检查（避免越界）
    if(x >= LCD_W || y >= LCD_H) return;
    LCD_Address_Set(x, y, x, y);
    LCD_WR_DATA(color);
}

// 显示单个字符（支持缩放）
void GUI_sprintf_char(uint8_t x, uint16_t y, uint8_t value, uint8_t size, uint16_t dcolor, uint16_t bgcolor, uint8_t mode)
{
    uint8_t i, j;
    uint8_t *temp = (uint8_t *)zifu816;
    uint16_t pixel_x, pixel_y;

    // 过滤不可显示字符（ASCII 32~127）
    if(value < 32 || value > 127) return;
    temp += (value - 32) * 16; // 定位字符字模首地址

    // 设置显示区域（根据缩放尺寸）
    if(mode == 0) // 8x16字符模式
        LCD_Address_Set(x, y, x + 8*size - 1, y + 16*size - 1);
    else // 16x8字符模式（横屏）
        LCD_Address_Set(x, y, x + 16*size - 1, y + 8*size - 1);

    // 逐行逐列绘制字符（支持缩放）
    for(j = 0; j < 16; j++) // 字符高度16行
    {
        for(pixel_y = 0; pixel_y < size; pixel_y++) // 缩放行
        {
            for(i = 0; i < 8; i++) // 字符宽度8列
            {
                for(pixel_x = 0; pixel_x < size; pixel_x++) // 缩放列
                {
                    if((*temp & (1 << (7 - i))) != 0)
                        LCD_WR_DATA(dcolor); // 字符颜色
                    else
                        LCD_WR_DATA(bgcolor); // 背景颜色
                }
            }
            temp++; // 下一行字模
        }
    }
}

// 显示字符串
void GUI_sprintf_string(uint8_t x1, uint16_t y1, uint8_t *str, int16_t len, uint8_t size, uint16_t dcolor, uint16_t bgcolor)
{
    uint8_t char_width = 8 * size; // 单个字符显示宽度（含缩放）

    while(*str && len-- > 0)
    {
        if(*str >= 0x20 && *str < 0x80) // 仅显示可打印ASCII字符
        {
            GUI_sprintf_char(x1, y1, *str, size, dcolor, bgcolor, 0);
            x1 += char_width; // 移动到下一个字符位置
            str++;
        }
        else
        {
            str++; // 跳过不支持的字符
        }
    }
}

// 清屏函数（修正行列循环顺序）
void LCD_Clear(uint16_t color)
{
    uint32_t i;
    uint32_t total_pixels = (uint32_t)LCD_W * LCD_H; // 总像素数

    LCD_Address_Set(0, 0, LCD_W - 1, LCD_H - 1);
    // 批量填充颜色（优化效率）
    for(i = 0; i < total_pixels; i++)
    {
        LCD_WR_DATA(color);
    }
}
