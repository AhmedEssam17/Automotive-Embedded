/*
 * SPI_Interface.h
 *
 * Created: 9/1/2023 11:39:01 AM
 *  Author: Lenovo
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "BitMath.h"
#include "std_types.h"

void SPI_init();

uint8_t SPI_Transceive(uint8_t data);

void SPI_setCallBack(void(*fptr)(void));

#endif /* SPI_INTERFACE_H_ */