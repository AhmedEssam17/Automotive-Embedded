/*
 * DIO.h
 *
 * Created: 8/18/2023 9:19:25 AM
 *  Author: Lenovo
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "BitMath.h"

#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

#define DIO_PIN_INPUT	0
#define DIO_PIN_OUTPUT	1

#define DIO_PIN_LOW		0
#define DIO_PIN_HIGH	1

#define DIO_PORT_HIGH	0xFF
#define DIO_PORT_LOW	0x00

void DIO_SetPortDir(uint8_t PORTx, uint8_t dir);
void DIO_SetPinDir(uint8_t PORTx, uint8_t PINx, uint8_t dir);

void DIO_SetPortVal(uint8_t PORTx, uint8_t value);
void DIO_SetPinVal(uint8_t PORTx, uint8_t PINx, uint8_t value);

void DIO_ReadPort(uint8_t PORTx, uint8_t* value);
uint8_t DIO_ReadPin(uint8_t PORTx, uint8_t PINx);

void DIO_TogglePin(uint8_t PORTx, uint8_t PINx);

#endif /* DIO_H_ */