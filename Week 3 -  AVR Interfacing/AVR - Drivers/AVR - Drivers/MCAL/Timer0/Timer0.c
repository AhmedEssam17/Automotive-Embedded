/*
 * Timer0.c
 *
 * Created: 8/25/2023 10:03:45 AM
 *  Author: Lenovo
 */ 

#include "Timer0.h"

void (*GP_IRQ_CallBack)(void) = NULL;

TIMER0_Config_t Global_TIMER0_Config;

void TIMER0_init(TIMER0_Config_t* TIMER0_Config){
	
	Global_TIMER0_Config = *TIMER0_Config;
	
	//-----------------------------
	//1) Set Timer Mode (TCCR0 >> WGM01)
	//-----------------------------
	TCCR0 |= TIMER0_Config->Timer_Mode;
	if (TIMER0_Config->Timer_Mode != TIMER0_MODE_CTC &&
		TIMER0_Config->Timer_Mode != TIMER0_MODE_NORMAL){
		SET_BIT(OCR0,DIO_PIN3);    //Configure OC0 (PINB3) as Output
	}
	
	//-----------------------------
	//2) Set Clock Source (TCCR0 >> CS00)
	//-----------------------------
	TCCR0 |= TIMER0_Config->Clock_Source;
	if (TIMER0_Config->Clock_Source == TIMER0_EXTERNAL_RISING_EDGE &&
		TIMER0_Config->Clock_Source == TIMER0_EXTERNAL_FALLING_EDGE){
		SET_BIT(OCR0,DIO_PIN0);  //Configure T0 (PINB0) as Input
	}
	
	//-----------------------------
	//3) Enable Or Disable IRQ (TIMSK >> TOIE0/OCIE0)
	//-----------------------------
	TIMSK |= TIMER0_Config->IRQ_Enable;
	if (TIMER0_Config->IRQ_Enable != TIMER0_IRQ_ENABLE_NONE){
		sei();
	}
	
	//-----------------------------
	//4) Set Initial Value (TCCR0 >> WGM01)
	//-----------------------------
	TCNT0 = TIMER0_Config->Initial_Value;
	
	//-----------------------------
	//5) Call back ISR function
	//-----------------------------
	GP_IRQ_CallBack = TIMER0_Config->P_CallBack;
	
	//-----------------------------
	//6) Toggle OC0
	//-----------------------------
	TCCR0 |= 1<<4;
}

void TIMER0_deinit(void)
{
	TCCR0 &= ~(0b111<<0);
}

void TIMER0_getCounterValue(uint8_t* ticks){
	*ticks = TCNT0;
}

void TIMER0_setCompareValue(uint8_t ticks){
	OCR0 = ticks;
}

ISR(TIMER0_OVF_vect)
{
	//GP_IRQ_CallBack();
}

ISR(TIMER0_COMP_vect)
{
	GP_IRQ_CallBack();
}

