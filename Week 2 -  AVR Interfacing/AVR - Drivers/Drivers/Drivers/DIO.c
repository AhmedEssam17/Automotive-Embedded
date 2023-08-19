/*
 * DIO.c
 *
 * Created: 8/18/2023 9:19:35 AM
 *  Author: Lenovo
 */ 
#include "DIO.h"
#include "Atmega32.h"
#include "BitMath.h"


void DIO_SetPortDir(uint8_t PORTx, uint8_t dir){
	
	switch(PORTx){
		case DIO_PORTA:
		DDRA = dir;
		break;
		
		case DIO_PORTB:
		DDRB = dir;
		break;
		
		case DIO_PORTC:
		DDRC = dir;
		break;
		
		case DIO_PORTD:
		DDRD = dir;
		break;
		
		default:
		break;
	}
}

void DIO_SetPinDir(uint8_t PORTx, uint8_t PINx, uint8_t dir){
	
	if(dir){
		switch(PORTx){
			case DIO_PORTA:
			SET_BIT(DDRA, PINx);
			break;
			
			case DIO_PORTB:
			SET_BIT(DDRB, PINx);
			break;
			
			case DIO_PORTC:
			SET_BIT(DDRC, PINx);
			break;
			
			case DIO_PORTD:
			SET_BIT(DDRD, PINx);
			break;
			
			default:
			break;
		}
	}
	else{
		switch(PORTx){
			case DIO_PORTA:
			CLEAR_BIT(DDRA, PINx);
			break;
			
			case DIO_PORTB:
			CLEAR_BIT(DDRB, PINx);
			break;
			
			case DIO_PORTC:
			CLEAR_BIT(DDRC, PINx);
			break;
			
			case DIO_PORTD:
			CLEAR_BIT(DDRD, PINx);
			break;
			
			default:
			break;
		}
	}
}

void DIO_SetPortVal(uint8_t PORTx, uint8_t value){
	
	switch(PORTx){
		case DIO_PORTA:
		PORTA = value;
		break;
		
		case DIO_PORTB:
		PORTB = value;
		break;
		
		case DIO_PORTC:
		PORTC = value;
		break;
		
		case DIO_PORTD:
		PORTD = value;
		break;
		
		default:
		break;
	}
}

void DIO_SetPinVal(uint8_t PORTx, uint8_t PINx, uint8_t value){
	
	if(value){
		switch(PORTx){
			case DIO_PORTA:
			SET_BIT(PORTA, PINx);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB, PINx);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC, PINx);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD, PINx);
			break;
			
			default:
			break;
		}
	}
	else{
		switch(PORTx){
			case DIO_PORTA:
			CLEAR_BIT(PORTA, PINx);
			break;
			
			case DIO_PORTB:
			CLEAR_BIT(PORTB, PINx);
			break;
			
			case DIO_PORTC:
			CLEAR_BIT(PORTC, PINx);
			break;
			
			case DIO_PORTD:
			CLEAR_BIT(PORTD, PINx);
			break;
			
			default:
			break;
		}
	}
}

void DIO_ReadPort(uint8_t PORTx, uint8_t* value){
	
	switch(PORTx){
		case DIO_PORTA:
		*value = PINA;
		break;
		
		case DIO_PORTB:
		*value = PINA;
		break;
		
		case DIO_PORTC:
		*value = PINA;
		break;
		
		case DIO_PORTD:
		*value = PINA;
		break;
		
		default:
		break;
	}
}

uint8_t DIO_ReadPin(uint8_t PORTx, uint8_t PINx){
	uint8_t value = 0;
	
	switch(PORTx){
		case DIO_PORTA:
		value = READ_BIT(PORTA, PINx);
		break;
		
		case DIO_PORTB:
		value = READ_BIT(PORTB, PINx);
		break;
		
		case DIO_PORTC:
		value = READ_BIT(PORTC, PINx);
		break;
		
		case DIO_PORTD:
		value = READ_BIT(PORTD, PINx);
		break;
		
		default:
		break;
	}
	
	return value;
}

void DIO_TogglePin(uint8_t PORTx, uint8_t PINx){
	
	switch(PORTx){
		case DIO_PORTA:
		TOGGLE_BIT(PORTA, PINx);
		break;
		
		case DIO_PORTB:
		TOGGLE_BIT(PORTB, PINx);
		break;
		
		case DIO_PORTC:
		TOGGLE_BIT(PORTC, PINx);
		break;
		
		case DIO_PORTD:
		TOGGLE_BIT(PORTD, PINx);
		break;
		
		default:
		break;
	}
}