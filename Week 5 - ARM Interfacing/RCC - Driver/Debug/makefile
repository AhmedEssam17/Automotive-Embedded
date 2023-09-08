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
RCC\ -\ Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
RCC\ -\ Driver.list \

OBJCOPY_BIN += \
RCC\ -\ Driver.bin \


# All Target
all: RCC\ -\ Driver.elf secondary-outputs

# Tool invocations
RCC\ -\ Driver.elf: $(OBJS) $(USER_OBJS) E:\Embedded\ Systems\ Diploma\Automotive\ Embedded\Week\ 5\ -\ ARM\ Interfacing\RCC\ -\ Driver\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "RCC - Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\Embedded Systems Diploma\Automotive Embedded\Week 5 - ARM Interfacing\RCC - Driver\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="RCC - Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

RCC\ -\ Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "RCC - Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

RCC\ -\ Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "RCC - Driver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
