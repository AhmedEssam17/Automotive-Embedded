/*
 * NVIC.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Lenovo
 */
#include "std_types.h"

#include "NVIC.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"

void NVIC_init(){
	/* Set Number of Group and Sub Group */
	SCB_AIRCR = SCB_AIRCR_GROUPING;
}

void NVIC_EnableInterrupt(uint8_t interruptNumber){

	/* If the user wants to enable interrupt in ISER0 register */
	if(interruptNumber <= NVIC_INTERRUPT_INDEX_31)
	{
		/* Enable Interrupt */
		NVIC_ISER0 = (1 << interruptNumber);
	}

	/* If the user wants to enable interrupt in ISER1 register */
	else if(interruptNumber <= NVIC_INTERRUPT_INDEX_59)
	{
		/* Subtract interrupt index from 32 for mapping */
		interruptNumber -= 32;

		/* Enable Interrupt */
		NVIC_ISER1 = (1 << interruptNumber);
	}
}

void NVIC_DisableInterrupt(uint8_t interruptNumber){

	/* If the user wants to disable interrupt in ISER0 register */
	if(interruptNumber <= NVIC_INTERRUPT_INDEX_31)
	{
		/* Disable Interrupt */
		NVIC_ICER0 = (1 << interruptNumber);
	}

	/* If the user wants to disable interrupt in ISER1 register */
	else if(interruptNumber <= NVIC_INTERRUPT_INDEX_59)
	{
		/* Subtract interrupt index from 32 for mapping */
		interruptNumber -= 32;

		/* Disable Interrupt */
		NVIC_ICER1 = (1 << interruptNumber);
	}
}

void NVIC_SetPendingFlag(uint8_t interruptNumber){

	/* If the user wants to Set pending flag in ISPR0 register */
	if(interruptNumber <= NVIC_INTERRUPT_INDEX_31)
	{
		/* Set Pending Flag */
		NVIC_ISPR0 = (1 << interruptNumber);
	}

	/* If the user wants to Set pending flag in ISPR1 register */
	else if(interruptNumber <= NVIC_INTERRUPT_INDEX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		interruptNumber -= 32;

		/* Set Pending Flag */
		NVIC_ISPR1 = (1 << interruptNumber);
	}
}

void NVIC_ClearPendingFlag(uint8_t interruptNumber){

	/* If the user wants to clear pending flag in ICPR0 register */
	if(interruptNumber <= NVIC_INTERRUPT_INDEX_31)
	{
		/* Clear Pending Flag */
		NVIC_ICPR0 = (1 << interruptNumber);
	}

	/* If the user wants to clear pending flag in ICPR1 register */
	else if(interruptNumber <= NVIC_INTERRUPT_INDEX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		interruptNumber -= 32;

		/* Clear Pending Flag */
		NVIC_ICPR1 = (1 << interruptNumber);
	}
}

void NVIC_GetActiveFlag(uint8_t interruptNumber , uint8_t* result){

	/* If the user wants to Get Active Flag in IABR0 register */
	if(interruptNumber <= NVIC_INTERRUPT_INDEX_31)
	{
		/* Get Active Flag */
		*result = (NVIC_IABR0 >> interruptNumber) & (0x01);
	}

	/* If the user wants to Get Active Flag in IABR1 register */
	else if(interruptNumber <= NVIC_INTERRUPT_INDEX_59)
	{
		/* Subtract interrupt indx from 32 for mapping */
		interruptNumber -= 32;

		/* Get Active Flag */
		*result = (NVIC_IABR1 >> interruptNumber) & (0x01);
	}
}

void NVIC_SetPriority(int8_t interruptID , uint8_t GroupPriority , uint8_t SubPriority){

	/* Initialize local variable with group and sub group value(4 bits) */
	uint8_t priority = SubPriority | (GroupPriority << (SCB_AIRCR_GROUPING - 0x05FA0300) / 256);

	/* External Peripheral has priority >= 0 */
	if(interruptID >= 0)
	{
		/* Set interrupt priority with 4 bits value (group and sub group) and shifted left by 4 For MSB (LSB is Reserved)*/
		NVIC_IPR[interruptID] = priority << 4;
	}
}



