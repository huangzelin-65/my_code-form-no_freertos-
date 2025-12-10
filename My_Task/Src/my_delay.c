#include "main.h"


/**
 * @brief  微秒级简易延时（需根据系统时钟校准）
 * @param  us: 延时微秒数（72MHz系统时钟下，参数范围0~1000000）
 * @note   72MHz时钟下，1个循环约5个指令周期，需根据实际调整系数
 */
void my_delay_us(uint32_t us)
{
    // 计算循环次数：SystemCoreClock=72MHz → 1us=72个时钟周期 → 约14个循环（72/5≈14）
    uint32_t cycles = us * (SystemCoreClock / 1000000) / 5;
    while (cycles--)
    {
        __NOP(); // 空指令，占用1个时钟周期
    }
}

/**
 * @brief  毫秒级简易延时（基于微秒延时实现）
 * @param  ms: 延时毫秒数
 */
void my_delay_ms(uint32_t ms)
{
    while (ms--)
    {
        my_delay_us(1000); // 每次延时1000μs=1ms
    }
}
