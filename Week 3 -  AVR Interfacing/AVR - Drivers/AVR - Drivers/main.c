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
}

int main(void)
{
	
	DIO_SetPinDir(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
	
	TIMER0_Config.Timer_Mode = TIMER0_MODE_CTC;
	TIMER0_Config.Clock_Source = TIMER0_PRESCALER_64;
	TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_OCIE0;
	TIMER0_Config.Initial_Value = 0;
	TIMER0_Config.P_CallBack = Timer0_Callback;
	
	TIMER0_init(&TIMER0_Config);
	TIMER0_setCompareValue(62);
	

    while (1) 
    {
		
    }
}

