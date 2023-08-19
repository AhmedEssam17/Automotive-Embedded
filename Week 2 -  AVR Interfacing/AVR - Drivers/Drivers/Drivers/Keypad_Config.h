/*
 * Keypad_Config.h
 *
 * Created: 8/18/2023 2:51:38 PM
 *  Author: Lenovo
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO.h"

#define KEYPAD_ROW_PORT		DIO_PORTC
#define KEYPAD_COL_PORT		DIO_PORTD

#define KEYPAD_COL0			DIO_PIN7
#define KEYPAD_COL1			DIO_PIN6
#define KEYPAD_COL2			DIO_PIN5
#define KEYPAD_COL3			DIO_PIN3

#define KEYPAD_ROW0			DIO_PIN5
#define KEYPAD_ROW1			DIO_PIN4
#define KEYPAD_ROW2			DIO_PIN3
#define KEYPAD_ROW3			DIO_PIN2

#endif /* KEYPAD_CONFIG_H_ */