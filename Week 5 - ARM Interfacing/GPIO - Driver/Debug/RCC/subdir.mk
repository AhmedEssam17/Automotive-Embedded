################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RCC/RCC.c 

OBJS += \
./RCC/RCC.o 

C_DEPS += \
./RCC/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
RCC/RCC.o: ../RCC/RCC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"E:/Embedded Systems Diploma/Automotive Embedded/Week 5 - ARM Interfacing/GPIO - Driver/RCC/inc" -I"E:/Embedded Systems Diploma/Automotive Embedded/Week 5 - ARM Interfacing/GPIO - Driver/GPIO/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RCC/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

