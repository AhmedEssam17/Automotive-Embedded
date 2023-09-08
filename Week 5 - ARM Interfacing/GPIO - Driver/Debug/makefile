################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include RCC/subdir.mk
-include GPIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GPIO\ -\ Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GPIO\ -\ Driver.list \

OBJCOPY_HEX += \
GPIO\ -\ Driver.hex \

OBJCOPY_BIN += \
GPIO\ -\ Driver.bin \


# All Target
all: GPIO\ -\ Driver.elf secondary-outputs

# Tool invocations
GPIO\ -\ Driver.elf: $(OBJS) $(USER_OBJS) E:\Embedded\ Systems\ Diploma\Automotive\ Embedded\Week\ 5\ -\ ARM\ Interfacing\GPIO\ -\ Driver\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "GPIO - Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\Embedded Systems Diploma\Automotive Embedded\Week 5 - ARM Interfacing\GPIO - Driver\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GPIO - Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GPIO\ -\ Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GPIO - Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

GPIO\ -\ Driver.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "GPIO - Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

GPIO\ -\ Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "GPIO - Driver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
