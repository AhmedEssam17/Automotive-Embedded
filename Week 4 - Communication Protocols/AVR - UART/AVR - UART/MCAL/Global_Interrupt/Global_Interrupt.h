/*
 * Global_Interrupt.h
 *
 * Created: 8/31/2023 10:57:18 PM
 *  Author: Lenovo
 */ 


#ifndef GLOBAL_INTERRUPT_H_
#define GLOBAL_INTERRUPT_H_

#include "BitMath.h"
#include "std_types.h"

#define SREG	(*(volatile uint8_t *)0x5F)

void Global_Interrupt_Enable();
void Global_Interrupt_Disable();

#endif /* GLOBAL_INTERRUPT_H_ */