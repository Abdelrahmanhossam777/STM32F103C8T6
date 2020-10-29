################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ESP8266_PROG.c \
../src/GPIO_PROG.c \
../src/NVIC_PROG.c \
../src/RCC_PROG.c \
../src/SYSTICK_PROG.c \
../src/UART_PROG.c \
../src/main.c 

OBJS += \
./src/ESP8266_PROG.o \
./src/GPIO_PROG.o \
./src/NVIC_PROG.o \
./src/RCC_PROG.o \
./src/SYSTICK_PROG.o \
./src/UART_PROG.o \
./src/main.o 

C_DEPS += \
./src/ESP8266_PROG.d \
./src/GPIO_PROG.d \
./src/NVIC_PROG.d \
./src/RCC_PROG.d \
./src/SYSTICK_PROG.d \
./src/UART_PROG.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


