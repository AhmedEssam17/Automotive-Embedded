/*
 * UART_Interface.h
 *
 * Created: 8/31/2023 12:29:16 PM
 *  Author: Lenovo
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "std_types.h"

void UART_init(void);

void UART_TransmitByte(uint8_t data);
uint8_t UART_RecieveByte(void);

uint8_t UART_getUDRValue(void);
void UART_setBaudRate(uint32_t baudRate);

void UART_TransmitString(const uint8_t *data);
void UART_RecieveString(uint8_t *data);

void UART_RegisterCallBack(uint8_t UART_Interrupt, void (*fptr)(uint8_t));

#endif /* UART_INTERFACE_H_ */