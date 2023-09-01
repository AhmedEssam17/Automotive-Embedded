/*
 * AVR - SPI.c
 *
 * Created: 9/1/2023 10:51:53 AM
 * Author : Lenovo
 */ 

#include "SPI_Interface.h"
#include "DIO.h"

uint8_t x = 0;

int main(void)
{
	
	SPI_init();
	
	DIO_SetPinDir(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTA, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	
    while (1) 
    {
		x = SPI_Transceive('X');
		if(x == 'X'){
			DIO_SetPinVal(DIO_PORTA, DIO_PIN6, DIO_PIN_LOW);
			DIO_SetPinVal(DIO_PORTA, DIO_PIN5, DIO_PIN_HIGH);
		}
		else{
			DIO_SetPinVal(DIO_PORTA, DIO_PIN5, DIO_PIN_LOW);
			DIO_SetPinVal(DIO_PORTA, DIO_PIN6, DIO_PIN_HIGH);
		}
    }
}

