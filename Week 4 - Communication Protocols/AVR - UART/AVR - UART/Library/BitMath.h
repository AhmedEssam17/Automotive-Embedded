/*
 * BitMath.h
 *
 * Created: 8/18/2023 9:19:11 AM
 *  Author: Lenovo
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(REG, BIT)		(REG |= (1<<BIT))
#define CLEAR_BIT(REG, BIT)		(REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG, BIT)	(REG ^= (1<<BIT))
#define READ_BIT(REG, BIT)		((REG >> BIT) & (0x01))

#endif /* BITMATH_H_ */