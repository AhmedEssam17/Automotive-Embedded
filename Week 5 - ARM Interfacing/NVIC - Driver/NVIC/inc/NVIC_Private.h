/*
 * NVIC_Private.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Lenovo
 */

#ifndef INC_NVIC_PRIVATE_H_
#define INC_NVIC_PRIVATE_H_

//====================================================================
//				Base addresses for NVIC Registers
//====================================================================
#define	NVIC_ISER0					*((uint32_t*)0xE000E100)	 			/* Enable External interrupts from 0 to 31    */
#define NVIC_ISER1					*((uint32_t*)0xE000E104)				/* Enable External interrupts from 32 to 63   */

#define	NVIC_ICER0					*((uint32_t*)0xE000E180)	 			/* Disable External interrupts from 0 to 31   */
#define NVIC_ICER1					*((uint32_t*)0xE000E184)				/* Disable External interrupts from 32 to 63  */

#define NVIC_ISPR0              	*((uint32_t*)0xE000E200)				/* Set pending flag from 0  to 31             */
#define NVIC_ISPR1              	*((uint32_t*)0xE000E204)				/* Set pending flag from 32 to 63             */

#define NVIC_ICPR0              	*((uint32_t*)0xE000E280)				/* Clear pending flag from 32 to 63           */
#define NVIC_ICPR1              	*((uint32_t*)0xE000E284)				/* Clear pending flag from 32 to 63           */

#define NVIC_IABR0					*((volatile uint32_t*)0xE000E300) 		/* to check active bit register status from  0  to 31 */
#define NVIC_IABR1					*((volatile uint32_t*)0xE000E300)		/* to check active bit register status from  32 to 63 */

#define NVIC_IPR				 	((uint8_t *)0xE000E400)              	/* Set priority of interrupts */

//====================================================================
//				Base addresses for SCB Registers
//====================================================================
#define SCB_AIRCR			   		*((uint32_t *)0xE000ED0C)				/* Choose Group and Sub Group Mode */

//====================================================================
//							Macros Definition
//====================================================================
#define NVIC_INTERRUPT_INDEX_31		31
#define NVIC_INTERRUPT_INDEX_59		59

#endif /* INC_NVIC_PRIVATE_H_ */
