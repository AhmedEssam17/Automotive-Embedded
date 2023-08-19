/*
 * LCD.c
 *
 * Created: 8/18/2023 10:13:30 AM
 *  Author: Lenovo
 */ 

#include "LCD.h"

void LCD_Kick(){
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(50);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_LOW);
}

void LCD_Position(uint8_t line, uint8_t position){
	if (line == 1)
	{
		if (position < 20 && position >= 0)
		{
			LCD_WriteCommand(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 20 && position >= 0)
		{
			LCD_WriteCommand(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_init(void){

	DIO_SetPinDir(LCD_4BIT_CMD, LCD_RS, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD, LCD_RW, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD, LCD_EN, DIO_PIN_OUTPUT);
	DIO_SetPortDir(LCD_4BIT_DATA, DIO_PORT_HIGH);
	
	_delay_ms(20);
	
	LCD_WriteCommand(LCD_FUNCTION_4BIT_2LINES);
	LCD_WriteCommand(LCD_ENTRY_MODE);
	LCD_WriteCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WriteCommand(LCD_DISP_ON_CURSOR_BLINK);
	
	LCD_ClearScreen();
}

void LCD_WriteCommand(uint8_t command){
	
	uint8_t Bit4 = 0;
	
	//LCD_Kick();
	
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_RS, DIO_PIN_LOW);
	//DIO_SetPinVal(LCD_4BIT_CMD, LCD_RW, DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_LOW);
	
	PORTB = ((command >> 4) & 0x07) | (PORTB & 0xF8);
	
	Bit4 = READ_BIT(command, 7);
	
	if(Bit4){
		SET_BIT(PORTB, LCD_D7);
	}
	else{
		CLEAR_BIT(PORTB, LCD_D7);
	}
	
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_RS, DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(50);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_LOW);
	
	PORTB = (command & 0x07) | (PORTB & 0xF8);
	
	Bit4 = READ_BIT(command, 3);
	
	if(Bit4){
		SET_BIT(PORTB, LCD_D7);
	}
	else{
		CLEAR_BIT(PORTB, LCD_D7);
	}
	
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_RS, DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(50);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_LOW);
}

void LCD_WriteChar(uint8_t character){
	
	uint8_t Bit4 = 0;
	
	//LCD_Kick();
	
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_RS, DIO_PIN_HIGH);
	//DIO_SetPinVal(LCD_4BIT_CMD, LCD_RW, DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_LOW);
	
	PORTB = ((character >> 4) & 0x07) | (PORTB & 0xF8);
	
	Bit4 = READ_BIT(character, 7);
	
	if(Bit4){
		SET_BIT(PORTB, LCD_D7);
	}
	else{
		CLEAR_BIT(PORTB, LCD_D7);
	}
	
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(50);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_LOW);
	
	PORTB = (character & 0x07) | (PORTB & 0xF8);
	
	Bit4 = READ_BIT(character, 3);
	
	if(Bit4){
		SET_BIT(PORTB, LCD_D7);
	}
	else{
		CLEAR_BIT(PORTB, LCD_D7);
	}
	
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_HIGH);
	_delay_ms(50);
	DIO_SetPinVal(LCD_4BIT_CMD, LCD_EN, DIO_PIN_LOW);
}

void LCD_WriteString(const uint8_t* str){
	
	int count = 0;
	while (*str != '\0'){
		count++;
		LCD_WriteChar(*str++);
		if (count == 20)
		{
			LCD_Position(2,0);
		}
		else if (count == 40)
		{
			LCD_ClearScreen();
			LCD_Position(1,0);
			count = 0;
		}
	}
}

void LCD_ClearScreen(void){
	LCD_WriteCommand(LCD_CLEAR_SCREEN);
}
