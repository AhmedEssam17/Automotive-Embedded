/*
 * DIO_Private.h
 *
 * Created: 9/1/2023 2:51:40 PM
 *  Author: Lenovo
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

//====================================================================
//						DIO Base Address
//====================================================================

// PORTA
#define PORTA	(*(volatile uint8_t *)0x3B)
#define DDRA	(*(volatile uint8_t *)0x3A)
#define PINA	(*(volatile uint8_t *)0x39)

// PORTB
#define PORTB	(*(volatile uint8_t *)0x38)
#define DDRB	(*(volatile uint8_t *)0x37)
#define PINB	(*(volatile uint8_t *)0x36)

// PORTC
#define PORTC	(*(volatile uint8_t *)0x35)
#define DDRC	(*(volatile uint8_t *)0x34)
#define PINC	(*(volatile uint8_t *)0x33)

// PORTD
#define PORTD	(*(volatile uint8_t *)0x32)
#define DDRD	(*(volatile uint8_t *)0x31)
#define PIND	(*(volatile uint8_t *)0x30)


#endif /* DIO_PRIVATE_H_ */