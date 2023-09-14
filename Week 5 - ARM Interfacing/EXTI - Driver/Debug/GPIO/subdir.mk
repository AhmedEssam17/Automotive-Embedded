################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/GPIO.c 

OBJS += \
./GPIO/GPIO.o 

C_DEPS += \
./GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/GPIO.o: ../GPIO/GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/RCC/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/GPIO/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/EXTI/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/NVIC/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GPIO/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

