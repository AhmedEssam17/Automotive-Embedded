/*
 * Drivers.c
 *
 * Created: 8/24/2023 10:24:22 AM
 * Author : Lenovo
 */ 

#include "ADC.h"
#include "LCD.h"
#include <stdlib.h>

uint16_t ADC_Data;
ADC_Config_t ADC_Config;
char buffer[10];
const uint8_t *LCD_Data = "ADC Value = ";

void ADC_Callback(void){
	if(ADC_Config.ADC_Result_Presentation == ADC_Result_Presentation_RIGHT){
		ADC_Data = (ADCL | ((ADCH & (0x03)) << 8));
	}
	else{
		ADC_Data = ((ADCL & (0xC0)) >> 6) | (ADCH << 2);
	}
	
	CLEAR_BIT(ADCSRA, 4);
}

int main(void)
{
	
	ADC_Config_t ADC_Config;
	
	ADC_Config.ADC_MODE = ADC_MODE_SINGLE_CONVERSION;
	ADC_Config.ADC_PRESCALER = ADC_PRESCALER_128;
	ADC_Config.ADC_Result_Presentation = ADC_Result_Presentation_RIGHT;
	ADC_Config.ADC_VREF = ADC_VREF_AVCC;
	ADC_Config.IRQ_Enable = ADC_IRQ_ENABLE;
	ADC_Config.P_CallBack = ADC_Callback;
	ADC_init(&ADC_Config);
	
	DIO_SetPinDir(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	LCD_init();
	LCD_ClearScreen();
	
    /* Replace with your application code */
    while (1) 
    {
		ADC_ReadData(ADC1, &ADC_Data, Polling_DISABLE);
		LCD_WriteString(LCD_Data);
		itoa(ADC_Data, buffer, 10); 
		LCD_WriteString(buffer);
		_delay_ms(1000);
		LCD_ClearScreen();
    }
}

