/*
 * AVR - Drivers.c
 *
 * Created: 8/25/2023 9:09:53 AM
 * Author : Lenovo
 */ 

#include "Timer0.h"

TIMER0_Config_t TIMER0_Config;

int main(void)
{
	
	DIO_SetPinDir(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTA, DIO_PIN5, DIO_PIN_INPUT);
	
	TIMER0_Config.Timer_Mode = TIMER0_MODE_Fast_PWM_Noninverting;
	TIMER0_Config.Clock_Source = TIMER0_PRESCALER_64;
	TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_NONE;
	TIMER0_Config.Initial_Value = 0;
	TIMER0_Config.P_CallBack = NULL;
	
	TIMER0_init(&TIMER0_Config);
	
    while (1) 
    {
		PWM_varyingDutyCycle();
    }
}

