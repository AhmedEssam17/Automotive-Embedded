/*
 * RCC.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Lenovo
 */
#include "std_types.h"

#include "RCC_Config.h"
#include "RCC.h"
#include "RCC_Private.h"

void RCC_init(void){

	//--------------------------------
	// Clock Control Register (RCC_CR)
	//--------------------------------
	RCC->CR |= (PLL_ON | CSS_ON | HSE_BYP | HSI_ON);

	//--------------------------------
	// Clock Configuration Register (RCC_CFGR)
	//--------------------------------
	RCC->CFGR |= (MCO | USB_PRE | PPRE2 | PPRE1 | HPRE | SW);
}

void RCC_enableClock(uint8_t BusID, uint16_t peripheralID){

	switch(BusID){
	case RCC_AHB:
		RCC->AHBENR |= (1 << peripheralID);
		break;
	case RCC_APB2:
		RCC->APB2ENR |= (1 << peripheralID);
		break;
	case RCC_APB1:
		RCC->APB1ENR |= (1 << peripheralID);
		break;
	}
}

void RCC_disableClock(uint8_t BusID, uint16_t peripheralID){

	switch(BusID){
	case RCC_AHB:
		RCC->AHBENR &= ~(1 << peripheralID);
		break;
	case RCC_APB2:
		RCC->APB2ENR &= ~(1 << peripheralID);
		break;
	case RCC_APB1:
		RCC->APB1ENR &= ~(1 << peripheralID);
		break;
	}
}


