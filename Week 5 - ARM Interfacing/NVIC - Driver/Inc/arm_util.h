/*
 * arm_util.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Lenovo
 */

#ifndef ARM_UTIL_H_
#define ARM_UTIL_H_

#define delay_ms(n) \
	do{ \
		uint32_t i = 500 * n; \
		while(i--){asm("nop");} \
	}while(0)

#endif /* ARM_UTIL_H_ */
