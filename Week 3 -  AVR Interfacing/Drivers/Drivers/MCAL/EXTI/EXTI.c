/*
 * EXTI.c
 *
 * Created: 8/19/2023 10:13:25 AM
 *  Author: Lenovo
 */ 

#include "EXTI.h"

void Global_IRQ_init(void){
	
	#if	GLOBAL_IRQ == GLOBAL_IRQ_Enable
	SET_BIT(SREG, 7);
	#elif GLOBAL_IRQ == GLOBAL_IRQ_Disable
	CLEAR_BIT(SREG, 7);
	#endif
}

void EXTI_init(EXTI_Config_t *EXTI_Config){
	
	Global_IRQ_init();
	
	//External Interrupt Request X Enable
	SET_BIT(GICR, EXTI_Config->IRQ_EN);
	
	if(EXTI_Config->IRQ_Source == EXTI0){
		MCUCR |= ((EXTI_Config->Trigger) << 0);
	}
	else if(EXTI_Config->IRQ_Source == EXTI1){
		MCUCR |= ((EXTI_Config->Trigger) << 2);
	}
	else if(EXTI_Config->IRQ_Source == EXTI2){
		MCUCSR |= ((EXTI_Config->Trigger) << 6);
	}
}
