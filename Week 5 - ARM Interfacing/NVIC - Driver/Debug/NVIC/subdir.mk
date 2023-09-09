################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NVIC/NVIC.c 

OBJS += \
./NVIC/NVIC.o 

C_DEPS += \
./NVIC/NVIC.d 


# Each subdirectory must supply rules for building sources it contributes
NVIC/NVIC.o: ../NVIC/NVIC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/NVIC - Driver/NVIC/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"NVIC/NVIC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

