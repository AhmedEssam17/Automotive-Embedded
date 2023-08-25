/*
 * EXTI_Config.h
 *
 * Created: 8/19/2023 10:55:09 AM
 *  Author: Lenovo
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


//====================================================================
//						Macros Configuration Reference
//====================================================================

//-----------------------------
//@ref GLOBAL_IRQ_define (SREG)
//-----------------------------

#define GLOBAL_IRQ_Enable				1
#define GLOBAL_IRQ_Disable				0
#define GLOBAL_IRQ						GLOBAL_IRQ_Enable

//-----------------------------
//@ref EXTIX_define
//-----------------------------

#define EXTI0							0
#define EXTI1							1
#define EXTI2							2

//-----------------------------
//@ref EXTI_Trigger_define (MCUCR)
//-----------------------------

#define EXTI_Trigger_LowLevel			0
#define EXTI_Trigger_RisingAndFalling	1
#define EXTI_Trigger_Falling			2
#define EXTI_Trigger_Rising				3

//-----------------------------
//@ref EXTI_Trigger_define (MCUCSR)
//-----------------------------

#define EXTI2_Trigger_Falling			0
#define EXTI2_Trigger_Rising			1

//-----------------------------
//@ref EXTIX_Enable_define (GICR)
//-----------------------------

#define EXTI0_Enable					6
#define EXTI1_Enable					7
#define EXTI2_Enable					5

//-----------------------------
//@ref EXTIX_Clear_Flag (GIFR)
//-----------------------------

#define EXTI0_Clear_Flag				6
#define EXTI1_Clear_Flag				7
#define EXTI2_Clear_Flag				5


#endif /* EXTI_CONFIG_H_ */