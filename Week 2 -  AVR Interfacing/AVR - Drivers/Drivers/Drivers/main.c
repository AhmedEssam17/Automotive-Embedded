/*
 * Drivers.c
 *
 * Created: 8/18/2023 9:18:25 AM
 * Author : Lenovo
 */ 

#include "DIO.h"
//#include <avr/io.h>
#include "LCD.h"
#include "Keypad.h"



int main(void)
{
	uint8_t key_pressed;
	//DDRB = 1<<7;
	
    LCD_init();
	Keypad_init();
	LCD_ClearScreen();
	//LCD_WriteChar('x');
    //const uint8_t *str = "Ahmed Essam ElDin   ElShafie";
    //LCD_WriteString(str);
	
    while (1) 
    {
		key_pressed = Keypad_getkey();
		switch(key_pressed){
			case '?':
			LCD_ClearScreen();
			break;
			default:
			LCD_WriteChar(key_pressed);
			break;
		}
    }
}

