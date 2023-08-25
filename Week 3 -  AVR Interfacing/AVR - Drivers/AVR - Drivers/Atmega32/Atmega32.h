/*
 * Atmega32.h
 *
 * Created: 8/18/2023 9:29:06 AM
 *  Author: Lenovo
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include <stdlib.h>
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


//====================================================================
//						EXTI Base Address
//====================================================================

#define SREG	(*(volatile uint8_t *)0x5F)
#define GICR	(*(volatile uint8_t *)0x5B)
#define GIFR	(*(volatile uint8_t *)0x5A)
#define MCUCR	(*(volatile uint8_t *)0x55)
#define MCUCSR	(*(volatile uint8_t *)0x54)


//====================================================================
//						ADC Base Address
//====================================================================

#define ADMUX	(*(volatile uint8_t *)0x27)
#define ADCSRA	(*(volatile uint8_t *)0x26)
#define ADCH	(*(volatile uint8_t *)0x25)
#define ADCL	(*(volatile uint8_t *)0x24)
#define SFIOR	(*(volatile uint8_t *)0x50)


//====================================================================
//						Timer0 Base Address
//====================================================================

#define TCCR0	(*(volatile uint8_t *)0x53)
#define OCR0	(*(volatile uint8_t *)0x5C)
#define TCNT0	(*(volatile uint8_t *)0x52)
#define TIMSK	(*(volatile uint8_t *)0x59)


#endif /* ATMEGA32_H_ */