/*
 * LCD.h
 *
 * Created: 8/18/2023 10:13:17 AM
 *  Author: Lenovo
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Config.h"
#include "Atmega32.h"
#include "BitMath.h"
#define F_CPU	16000000UL
#include <util/delay.h>



void LCD_init(void);
void LCD_WriteCommand(uint8_t command);
void LCD_WriteChar(uint8_t character);
void LCD_WriteString(const uint8_t* str);
void LCD_ClearScreen(void);

#endif /* LCD_H_ */