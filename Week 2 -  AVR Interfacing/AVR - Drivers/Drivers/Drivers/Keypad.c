/*
 * Keypad.c
 *
 * Created: 8/18/2023 2:51:49 PM
 *  Author: Lenovo
 */ 

#include "Keypad.h"

#define  COL_INIT    0
#define  COL_FINAL   3

#define  ROW_INIT    4
#define  ROW_FINAL   7

const uint8_t keypadValue[4][4] = {{'1','2','3','4'},
									{'5','6','7','8'},
									{'9','A','B','C'},
									{'D','E','F','?'}};

void Keypad_init(){
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL0, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL1, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL2, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_COL_PORT, KEYPAD_COL3, DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW0, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW1, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW2, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_ROW_PORT, KEYPAD_ROW3, DIO_PIN_INPUT);
	
	DIO_SetPinVal(KEYPAD_COL_PORT, KEYPAD_COL0, DIO_PIN_HIGH);
	DIO_SetPinVal(KEYPAD_COL_PORT, KEYPAD_COL1, DIO_PIN_HIGH);
	DIO_SetPinVal(KEYPAD_COL_PORT, KEYPAD_COL2, DIO_PIN_HIGH);
	DIO_SetPinVal(KEYPAD_COL_PORT, KEYPAD_COL3, DIO_PIN_HIGH);
}

uint8_t Keypad_getkey(){
	
	uint8_t col_Loc = 0;
	uint8_t row_Loc = 0;
	
	uint8_t value = 0;
	uint8_t temp = 0;
	
	for(col_Loc = COL_INIT ; col_Loc <= COL_FINAL ; col_Loc++)
	{
		//Activate the column
		DIO_SetPinVal(KEYPAD_COL_PORT , col_Loc , DIO_PIN_LOW);
		
		for(row_Loc = ROW_INIT ; row_Loc <= ROW_FINAL ; row_Loc++)
		{
			
			temp = DIO_ReadPin(KEYPAD_ROW_PORT , row_Loc);
			
			//wait until the switch is releases
			if(!temp)
			{
				value =  keypadValue[row_Loc - ROW_INIT][col_Loc - COL_INIT];
				
				while(!temp)
				{
					temp = DIO_ReadPin(KEYPAD_ROW_PORT , row_Loc);
					//PORTB ^= 1<<7;
					//_delay_ms(1000);
				}
				
				//Delay to avoid bouncing , bouncing occurs in mechanical switches and can cause one switch press to be detected as multiple presses
				_delay_ms(10);
			}
			
		}
		//deactivate column again
		DIO_SetPinVal(KEYPAD_COL_PORT , col_Loc , DIO_PIN_HIGH);
		
	}
	
	//PORTB &= ~(1<<7);
	return value ;
}