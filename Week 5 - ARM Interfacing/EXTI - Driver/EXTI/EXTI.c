/*
 * EXTI.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Lenovo
 */

#include "std_types.h"

#include "EXTI.h"
#include "NVIC.h"

//====================================================================
//						Generic Variables
//====================================================================

void (*GP_IRQ_CallBack[16])(void);

//====================================================================
//						Generic Macros
//====================================================================

#define AFIO_GPIOx_Mapping(GPIOx)	(	(GPIOx == GPIOA)?0:\
										(GPIOx == GPIOB)?1:\
										(GPIOx == GPIOC)?2:0	)

//====================================================================
//						Generic Functions
//====================================================================

void NVIC_Enable(uint16_t IRQ){
	NVIC_EnableInterrupt((uint8_t)IRQ);
}

void NVIC_Disable(uint16_t IRQ){
	NVIC_DisableInterrupt((uint8_t)IRQ);
}

void Configure_EXTI(EXTI_PinConfig_t *EXTI_Config){
	//-----------------------------
	//1) Configure GPIO to be AF Input >> Floating Input
	//-----------------------------
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
	GPIO_init(EXTI_Config->EXTI_PIN.GPIOx, &PinConfig);

	//-----------------------------
	//2) Route AFIO to Corresponding EXTI Input Line
	//-----------------------------
	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_InputLineX / 4;
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.EXTI_InputLineX % 4) * 4;

	//Reset then Set AFIO->EXTICR Register
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIOx_Mapping(EXTI_Config->EXTI_PIN.GPIOx) & 0xF) << AFIO_EXTICR_Position);

	//-----------------------------
	//3) Set Rising/Falling Trigger Case
	//-----------------------------
	//Reset then Set EXTI->RTSR and EXTI->FTSR
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineX);
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineX);

	if(EXTI_Config->Trigger == EXTI_Trigger_Rising){
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineX);
	}
	else if(EXTI_Config->Trigger == EXTI_Trigger_Falling){
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineX);
	}
	else if(EXTI_Config->Trigger == EXTI_Trigger_RisingAndFalling){
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineX);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineX);
	}

	//-----------------------------
	//4) Set IRQ CallBack Function
	//-----------------------------
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineX] = EXTI_Config->P_IRQ_CallBack;

	//-----------------------------
	//5) Enable/Disable EXTIxNVIC IRQ Mask
	//-----------------------------
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable){
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineX);
		NVIC_Enable(EXTI_Config->EXTI_PIN.EXTI_InputLineX);
	}
	else if(EXTI_Config->IRQ_EN == EXTI_IRQ_Disable){
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineX);
		NVIC_Disable(EXTI_Config->EXTI_PIN.EXTI_InputLineX);
	}
}

//====================================================================
//						APIs Functions Definitions
//====================================================================

/**================================================================
 * @Fn				-MCAL_EXTI_init
 * @brief 			-Initializes EXTIxGPIO Pin and specify Trigger/Mask Condition and IRQ Callback function
 * 					 Configuration is set based on @ref EXTI_define, @ref EXTI_Trigger_define, @ref EXTI_IRQ_define
 * @param [in]	 	-EXTI_Config
 * @retval 			-NONE
 * Note				-Enable RCC Clock for AFIO & GPIO.
 * 					 STM32F103C6 MCU has GPIO A..E but LQFP48 only has the following:
 * 					 GPIOA & GPIOB Fully included
 * 					 GPIOC & GPIOD Partially included
 * 					 GPIOE not included
 */
void MCAL_EXTI_init(EXTI_PinConfig_t *EXTI_Config){
	Configure_EXTI(EXTI_Config);
}

/**================================================================
 * @Fn				-MCAL_GPIO_update
 * @brief 			-Updates EXTIxGPIO Pin and specify Trigger/Mask Condition and IRQ Callback function
 * 					 Configuration is set based on @ref EXTI_define, @ref EXTI_Trigger_define, @ref EXTI_IRQ_define
 * @param [in]	 	-EXTI_Config
 * @retval 			-NONE
 * Note				-NONE
 */
void MCAL_EXTI_update(EXTI_PinConfig_t *EXTI_Config){
	Configure_EXTI(EXTI_Config);
}

/**================================================================
 * @Fn				-MCAL_EXTI_SW_Trigger
 * @brief 			-Software Interrupt Trigger
 * @param [in]	 	-EXTI_Config
 * @retval 			-NONE
 * Note				-NONE
 */
void MCAL_EXTI_SW_Trigger(EXTI_PinConfig_t *EXTI_Config){
	EXTI->SWIER |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineX);
}

//====================================================================
//							ISR Functions
//====================================================================

void EXTI0_IRQHandler(void){
	EXTI->PR |= (1<<0);
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void){
	EXTI->PR |= (1<<1);
	GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void){
	EXTI->PR |= (1<<2);
	GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void){
	EXTI->PR |= (1<<3);
	GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void){
	EXTI->PR |= (1<<4);
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void){
	if(EXTI->PR & 1<<5){
		EXTI->PR |= (1<<5);
		GP_IRQ_CallBack[5]();
	}
	if(EXTI->PR & 1<<6){
		EXTI->PR |= (1<<6);
		GP_IRQ_CallBack[6]();
	}
	if(EXTI->PR & 1<<7){
		EXTI->PR |= (1<<7);
		GP_IRQ_CallBack[7]();
	}
	if(EXTI->PR & 1<<8){
		EXTI->PR |= (1<<8);
		GP_IRQ_CallBack[8]();
	}
	if(EXTI->PR & 1<<9){
		EXTI->PR |= (1<<9);
		GP_IRQ_CallBack[9]();
	}
}

void EXTI15_10_IRQHandler(void){
	if(EXTI->PR & 1<<10){
		EXTI->PR |= (1<<10);
		GP_IRQ_CallBack[10]();
	}
	if(EXTI->PR & 1<<11){
		EXTI->PR |= (1<<11);
		GP_IRQ_CallBack[11]();
	}
	if(EXTI->PR & 1<<12){
		EXTI->PR |= (1<<12);
		GP_IRQ_CallBack[12]();
	}
	if(EXTI->PR & 1<<13){
		EXTI->PR |= (1<<13);
		GP_IRQ_CallBack[13]();
	}
	if(EXTI->PR & 1<<14){
		EXTI->PR |= (1<<14);
		GP_IRQ_CallBack[14]();
	}
	if(EXTI->PR & 1<<15){
		EXTI->PR |= (1<<15);
		GP_IRQ_CallBack[15]();
	}
}


