/*
 * EXTI.h
 *
 * Created: 8/19/2023 10:12:51 AM
 *  Author: Lenovo
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include <avr/interrupt.h>
#include "EXTI_Config.h"
#include "DIO.h"

//====================================================================
//						Configuration Structure
//====================================================================

typedef struct{
	uint8_t		IRQ_Source;					//Specifies the source of Interrupt based on @ref EXTIX_define
	uint8_t		Trigger;					//Specifies Rising/Falling/Both based on @ref EXTI_Trigger_define
	uint8_t		IRQ_EN;						//Enable and Disable EXIT based on @ref EXTIX_Enable_define
	uint8_t		Flag_Clear;					//Specifies EXTIxGPIO Mapping based on @ref EXTIX_Clear_Flag
}EXTI_Config_t;

//extern EXTI_Config_t *EXTI_Config;
//====================================================================
//								APIs
//====================================================================

void Global_IRQ_init(void);
void EXTI_init(EXTI_Config_t *EXTI_Config);

#endif /* EXTI_H_ */