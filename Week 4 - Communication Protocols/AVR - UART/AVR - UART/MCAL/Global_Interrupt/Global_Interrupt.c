/*
 * Global_Interrupt.c
 *
 * Created: 8/31/2023 10:57:37 PM
 *  Author: Lenovo
 */ 

#include "Global_Interrupt.h"

void Global_Interrupt_Enable(){
	SET_BIT(SREG, 7);
}

void Global_Interrupt_Disable(){
	CLEAR_BIT(SREG, 7);
}

