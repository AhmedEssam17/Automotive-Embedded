################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c8tx.s 

OBJS += \
./Startup/startup_stm32f103c8tx.o 

S_DEPS += \
./Startup/startup_stm32f103c8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c8tx.o: ../Startup/startup_stm32f103c8tx.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/NVIC/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/GPIO/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/RCC/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/EXTI/inc" -I"C:/Users/Lenovo/STM32CubeIDE/workspace_1.4.0/EXTI - Driver/Inc" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

