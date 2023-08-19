
/*
 * LCD_Config.h
 *
 * Created: 8/18/2023 10:20:45 AM
 *  Author: Lenovo
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "DIO.h"

//====================================================================
//						PORT Configuration
//====================================================================
#define LCD_8BIT_CMD	DIO_PORTA
#define LCD_8BIT_DATA	DIO_PORTB

#define LCD_4BIT_CMD	DIO_PORTA
#define LCD_4BIT_DATA	DIO_PORTB

//====================================================================
//						PIN Configuration
//====================================================================
#define LCD_RS			DIO_PIN3
#define LCD_RW			DIO_PIN1
#define LCD_EN			DIO_PIN2

#define LCD_D4			DIO_PIN0
#define LCD_D5			DIO_PIN1
#define LCD_D6			DIO_PIN2
#define LCD_D7			DIO_PIN4

//====================================================================
//						Command Configuration
//====================================================================
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

#endif /* LCD_CONFIG_H_ */