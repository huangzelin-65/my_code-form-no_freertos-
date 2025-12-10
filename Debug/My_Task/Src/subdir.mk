################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
../My_Task/Src/debug_uart.c \
../My_Task/Src/gui.c \
../My_Task/Src/lcd.c \
../My_Task/Src/my_delay.c \
../My_Task/Src/usart1_logprintf.c 

OBJS += \
./My_Task/Src/debug_uart.o \
./My_Task/Src/gui.o \
./My_Task/Src/lcd.o \
./My_Task/Src/my_delay.o \
./My_Task/Src/usart1_logprintf.o 

C_DEPS += \
./My_Task/Src/debug_uart.d \
./My_Task/Src/gui.d \
./My_Task/Src/lcd.d \
./My_Task/Src/my_delay.d \
./My_Task/Src/usart1_logprintf.d 


# 每个子目录必须为构建它所贡献的源提供规则
My_Task/Src/%.o My_Task/Src/%.su My_Task/Src/%.cyclo: ../My_Task/Src/%.c My_Task/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/STM32/my_code_form/My_Task/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-My_Task-2f-Src

clean-My_Task-2f-Src:
	-$(RM) ./My_Task/Src/debug_uart.cyclo ./My_Task/Src/debug_uart.d ./My_Task/Src/debug_uart.o ./My_Task/Src/debug_uart.su ./My_Task/Src/gui.cyclo ./My_Task/Src/gui.d ./My_Task/Src/gui.o ./My_Task/Src/gui.su ./My_Task/Src/lcd.cyclo ./My_Task/Src/lcd.d ./My_Task/Src/lcd.o ./My_Task/Src/lcd.su ./My_Task/Src/my_delay.cyclo ./My_Task/Src/my_delay.d ./My_Task/Src/my_delay.o ./My_Task/Src/my_delay.su ./My_Task/Src/usart1_logprintf.cyclo ./My_Task/Src/usart1_logprintf.d ./My_Task/Src/usart1_logprintf.o ./My_Task/Src/usart1_logprintf.su

.PHONY: clean-My_Task-2f-Src

