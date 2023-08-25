/*
 * Timer0.h
 *
 * Created: 8/25/2023 10:04:53 AM
 *  Author: Lenovo
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "DIO.h"
#include "Atmega32.h"
#include "EXTI.h"

//====================================================================
//						Configuration Structure
//====================================================================
typedef struct
{
	uint8_t Timer_Mode;					// Specifies Timer Mode (Normal mode or CTC)											>> @ref TIMER0_MODE_DEFINE
	uint8_t Clock_Source;				// Specifies Timer Clock Source (External / Internal)									>> @ref TIMER0_CLOCK_SOURCE_DEFINE
	uint8_t IRQ_Enable;					// Enable or Disable IRQ																>> @ref TIMER0_IRQ_ENABLE_DEFINE
	uint8_t Initial_Value;				// Set the Initial Tick Value
	void (*P_CallBack)(void);			// Set the C Function which will be called once IRQ Happens
}TIMER0_Config_t;


//====================================================================
//						Macros Configuration Reference
//====================================================================

//-----------------------------
//@ref TIMER0_MODE_DEFINE (TCCR0 >> WGM01)
//-----------------------------
#define TIMER0_MODE_NORMAL									(uint8_t)(0x0<<3)
#define TIMER0_MODE_CTC										(uint8_t)(0x1<<3)
#define TIMER0_MODE_Fast_PWM_Inverting				     	(uint8_t)(0xF<<3)
#define TIMER0_MODE_Fast_PWM_Noninverting		   			(uint8_t)(0xD<<3)
#define TIMER0_MODE_Phase_Correct_PWM_Set_DC      	   		(uint8_t)(0x5<<3)
#define TIMER0_MODE_Phase_Correct_PWM_Set_UC      	   		(uint8_t)(0x7<<3)

//-----------------------------
//@ref TIMER0_CLOCK_SOURCE_DEFINE (TCCR0 >> CS00)
//-----------------------------
#define TIMER0_PRESCALER_NONE								(uint8_t)(0b001<<0)
#define TIMER0_PRESCALER_8									(uint8_t)(0b010<<0)
#define TIMER0_PRESCALER_64									(uint8_t)(0b011<<0)
#define TIMER0_PRESCALER_256								(uint8_t)(0b100<<0)
#define TIMER0_PRESCALER_1024								(uint8_t)(0b101<<0)
#define TIMER0_EXTERNAL_FALLING_EDGE						(uint8_t)(0b110<<0)
#define TIMER0_EXTERNAL_RISING_EDGE							(uint8_t)(0b111<<0)

//-----------------------------
//@ref TIMER0_IRQ_ENABLE_DEFINE (TIMSK >> TOIE0/OCIE0)
//-----------------------------
#define TIMER0_IRQ_ENABLE_NONE								((uint8_t)(0))
#define TIMER0_IRQ_ENABLE_TOIE0								((uint8_t)(1<<0))
#define TIMER0_IRQ_ENABLE_OCIE0								((uint8_t)(1<<1))

//====================================================================
//								APIs
//====================================================================

void TIMER0_init(TIMER0_Config_t* TIMER0_Config);
void TIMER0_getCounterValue(uint8_t* ticks);
void TIMER0_setCompareValue(uint8_t  ticks);


#endif /* TIMER0_H_ */