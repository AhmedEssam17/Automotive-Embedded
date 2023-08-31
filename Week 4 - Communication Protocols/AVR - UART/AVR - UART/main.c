/*
 * AVR - UART.c
 *
 * Created: 8/31/2023 12:17:24 PM
 * Author : Lenovo
 */ 

#include "BitMath.h"
#include "std_types.h"
#include "UART_Interface.h"
#include "Global_Interrupt.h"

volatile uint8_t buffer[10];
volatile uint8_t UART_flag = 0;

void UART_CallBack(uint8_t data){
	
	static uint32_t bufferIndex = 0;
	buffer[bufferIndex] = data;
	
	if(bufferIndex == (sizeof(buffer) / sizeof(buffer[0]) - 1) || 
	   buffer[bufferIndex] == '\r' || 
	   buffer[bufferIndex] == '\n' ){
		buffer[bufferIndex] = '\0';
		bufferIndex = 0;
		UART_flag = 1;
	}
	else{
		bufferIndex++;
	}
}

int main(void)
{
    UART_init();
	UART_setBaudRate(9600);
	UART_RegisterCallBack(0, UART_CallBack);
	Global_Interrupt_Enable();
    while (1) 
    {
		if(UART_flag == 1){
			UART_flag = 0;
			UART_TransmitString(buffer);
			UART_TransmitByte('\r');
			UART_TransmitByte('\n');
		}
    }
}

