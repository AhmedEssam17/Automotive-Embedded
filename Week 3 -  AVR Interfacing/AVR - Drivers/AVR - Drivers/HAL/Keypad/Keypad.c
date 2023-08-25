/*
 * Keypad.c
 *
 * Created: 8/18/2023 2:51:49 PM
 *  Author: Lenovo
 */ 

#include "Keypad.h"


#define  COL_INIT    7
#define  COL_FINAL   3

#define  ROW_INIT    5
#define  ROW_FINAL   2


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

uint8_t Keypad_getkey(void)
{
	uint8_t Col_Loc = 0;
	uint8_t Row_Loc = 0;
	
	uint8_t Value = 0;
	uint8_t Temp = 0;
	
	for(Col_Loc = COL_INIT ; Col_Loc >= COL_FINAL ; Col_Loc--)
	{
		//Activate the column
		if (Col_Loc == 4)
		{
			continue;
		}
		DIO_SetPinVal(KEYPAD_COL_PORT , Col_Loc , DIO_PIN_LOW);
		
		for(Row_Loc = ROW_INIT ; Row_Loc >= ROW_FINAL ; Row_Loc--)
		{
			
			Temp = DIO_ReadPin(KEYPAD_ROW_PORT , Row_Loc);
			
			//wait until the switch is releases
			if(!Temp)
			{
				//for accessing column 4 only
				if(Col_Loc == 3)
				{
					Value =  keypadValue[(Row_Loc - ROW_INIT) * -1 ][  (  (Col_Loc - COL_INIT)  * -1)-1 ];
				}
				
				else
				{
					Value =  keypadValue[(Row_Loc - ROW_INIT) * -1 ][  (  (Col_Loc - COL_INIT)  * -1) ];
				}
				
				
				while(!Temp)
				{
					Temp = DIO_ReadPin(KEYPAD_ROW_PORT , Row_Loc);
				}
				
				//Delay to avoid bouncing , bouncing occurs in mechanical switches and can cause one switch press to be detected as multiple presses
				_delay_ms(10);
			}
			
		}
		//deactivate column again
		DIO_SetPinVal(KEYPAD_COL_PORT , Col_Loc , DIO_PIN_HIGH);
	}
	
	return Value ;
}

