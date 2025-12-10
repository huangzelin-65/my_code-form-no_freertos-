#ifndef __GUI_H__
#define __GUI_H__

#include <stdint.h>

/*定义常用颜色码*/
#define Red      0xf800	//红
#define Yellow   0xffe0	//黄
#define Green    0x07e0	//绿
#define Cyan     0x07ff	//青
#define Blue     0x001f	//蓝
#define Purple   0xf81f	//紫
#define Black    0x0000	//黑
#define White    0xffff	//白
#define Gray     0x7bef	//灰
#define Blue1    0xa5ff //淡蓝
#define Blue2	 0x7cdf
#define Purple1  0x8a9e //淡紫
#define Green1   0x0410 //墨绿
#define Green2   0x2616
#define Blue3	 0x751E
#define Purple2  0xcd9e //淡紫
#define Red2	 0XF260	//淡红
#define Red3	 0X8000	//棕红
#define window   0XDED7


void LCD_Clear(uint16_t color);
void GUI_sprintf_string(uint8_t x1,uint16_t y1,uint8_t *str, int16_t len, uint8_t size, uint16_t dcolor,uint16_t bgcolor);

#endif
