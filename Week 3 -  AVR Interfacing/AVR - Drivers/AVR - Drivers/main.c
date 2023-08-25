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
uint8_t numCounter = 0;
uint8_t watchdogCounter = 0;
uint8_t watchdogFlag = 0;
TIMER0_Config_t TIMER0_Config;
char buffer[10];

void Timer0_Callback(void){
	if(Timer_Counter < 250){
		Timer_Counter++;
	}
	if(Timer_Counter == 250){
		numCounter++;
		Timer_Counter = 0;
	}
	if(numCounter == 10){
		numCounter = 0;
		watchdogCounter++;
	}
	if(watchdogCounter == 6){
		watchdogFlag++;
	}
}

int main(void)
{
	
	LCD_init();
	LCD_ClearScreen();
	
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	
	
	TIMER0_Config.Timer_Mode = TIMER0_MODE_NORMAL;
	TIMER0_Config.Clock_Source = TIMER0_PRESCALER_256;
	TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_TOIE0;
	TIMER0_Config.Initial_Value = 6;
	TIMER0_Config.P_CallBack = Timer0_Callback;
	
	TIMER0_init(&TIMER0_Config);

    while (1) 
    {
		if(watchdogFlag)
		{
			TIMER0_deinit();			
		}
		itoa(numCounter, buffer, 10);
		LCD_WriteString(buffer);
		LCD_Position(2,0);
		itoa(watchdogCounter, buffer, 10);
		LCD_WriteString(buffer);
		LCD_ClearScreen();
    }
}

