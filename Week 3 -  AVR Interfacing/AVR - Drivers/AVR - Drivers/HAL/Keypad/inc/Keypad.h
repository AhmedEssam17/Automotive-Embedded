/*
 * Keypad.h
 *
 * Created: 8/18/2023 2:51:21 PM
 *  Author: Lenovo
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdint.h>
#include "Keypad_Config.h"
#include "Atmega32.h"
#include "BitMath.h"
#define F_CPU	16000000UL
#include <util/delay.h>

void Keypad_init();
uint8_t Keypad_getkey();

#endif /* KEYPAD_H_ */