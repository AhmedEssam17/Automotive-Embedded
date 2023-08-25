/*
 * AVR - Drivers.c
 *
 * Created: 8/25/2023 9:09:53 AM
 * Author : Lenovo
 */ 

#include "Timer0.h"
#include "LCD.h"
#include <stdlib.h>

uint32_t Timer_Counter = 0;
TIMER0_Config_t TIMER0_Config;


void Timer0_Callback(void){
	if(Timer_Counter < 125){
		Timer_Counter++;
	}
}

int main(void)
{
	
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTA, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTA, DIO_PIN6, DIO_PIN_OUTPUT);
	
	SET_BIT(PORTA, DIO_PIN4);
	SET_BIT(PORTA, DIO_PIN6);
	
	TIMER0_Config.Timer_Mode = TIMER0_MODE_CTC;
	TIMER0_Config.Clock_Source = TIMER0_PRESCALER_256;
	TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_OCIE0;
	TIMER0_Config.Initial_Value = 0;
	TIMER0_Config.P_CallBack = Timer0_Callback;
	TIMER0_init(&TIMER0_Config);
	
	TIMER0_setCompareValue(250);

    while (1) 
    {
		if(Timer_Counter == 125)
		{
			TOGGLE_BIT(PORTB, DIO_PIN7);
			TOGGLE_BIT(PORTA, DIO_PIN4);
			TOGGLE_BIT(PORTA, DIO_PIN5);
			TOGGLE_BIT(PORTA, DIO_PIN6);
			Timer_Counter = 0;
		}
    }
}

