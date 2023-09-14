/*
 * NVIC.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Lenovo
 */

#ifndef INC_NVIC_H_
#define INC_NVIC_H_

//====================================================================
//					 NVIC Function Parameters
//====================================================================

#define NVIC_EXTI0					6
#define NVIC_EXTI1					7
#define NVIC_EXTI2					8
#define NVIC_EXTI3					9
#define NVIC_EXTI4					10

#define NVIC_GROUP0					0
#define NVIC_GROUP1					1
#define NVIC_GROUP2					2
#define NVIC_GROUP3					3
#define NVIC_GROUP4					4
#define NVIC_GROUP5					5
#define NVIC_GROUP6					6
#define NVIC_GROUP7					7
#define NVIC_GROUP8					8
#define NVIC_GROUP9					9
#define NVIC_GROUP10				10
#define NVIC_GROUP11				11
#define NVIC_GROUP12				12
#define NVIC_GROUP13				13
#define NVIC_GROUP14				14
#define NVIC_GROUP15				15

#define NVIC_SUB_GROUP0             0
#define NVIC_SUB_GROUP1             1
#define NVIC_SUB_GROUP2             2
#define NVIC_SUB_GROUP3             3
#define NVIC_SUB_GROUP4             4
#define NVIC_SUB_GROUP5             5
#define NVIC_SUB_GROUP6             6
#define NVIC_SUB_GROUP7             7
#define NVIC_SUB_GROUP8             8
#define NVIC_SUB_GROUP9             9
#define NVIC_SUB_GROUP10            10
#define NVIC_SUB_GROUP11            11
#define NVIC_SUB_GROUP12            12
#define NVIC_SUB_GROUP13            13
#define NVIC_SUB_GROUP14            14
#define NVIC_SUB_GROUP15            15

#define NVIC_GROUP_4_SUB_0			0x05FA0300  // 4 bits for group
#define NVIC_GROUP_3_SUB_1			0x05FA0400  // 3 bits for group and 1 bit for sub
#define NVIC_GROUP_2_SUB_2			0x05FA0500  // 2 bits for group and 2 bit for sub
#define NVIC_GROUP_1_SUB_3			0x05FA0600  // 1 bits for group and 3 bit for sub
#define NVIC_GROUP_0_SUB_4			0x05FA0700  // 0 group and 4 bits for sub

//====================================================================
//					 Functions Prototype
//====================================================================

void NVIC_init();

void NVIC_EnableInterrupt(uint8_t interruptNumber);

void NVIC_DisableInterrupt(uint8_t interruptNumber);

void NVIC_SetPendingFlag(uint8_t interruptNumber);

void NVIC_ClearPendingFlag(uint8_t interruptNumber);

void NVIC_GetActiveFlag(uint8_t interruptNumber , uint8_t* result);

void NVIC_SetPriority(int8_t interruptID , uint8_t GroupPriority , uint8_t SubPriority);


#endif /* INC_NVIC_H_ */
