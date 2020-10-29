################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BL_program.c \
../src/FPEC_program.c \
../src/GPIO_PROG.c \
../src/RCC_PROG.c \
../src/SYSTICK_PROG.c \
../src/UART_PROG.c \
../src/main.c 

OBJS += \
./src/BL_program.o \
./src/FPEC_program.o \
./src/GPIO_PROG.o \
./src/RCC_PROG.o \
./src/SYSTICK_PROG.o \
./src/UART_PROG.o \
./src/main.o 

C_DEPS += \
./src/BL_program.d \
./src/FPEC_program.d \
./src/GPIO_PROG.d \
./src/RCC_PROG.d \
./src/SYSTICK_PROG.d \
./src/UART_PROG.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


