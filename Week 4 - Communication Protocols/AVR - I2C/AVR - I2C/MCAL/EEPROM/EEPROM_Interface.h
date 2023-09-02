/*
 * EEPROM_Interface.h
 *
 * Created: 9/2/2023 3:02:25 PM
 *  Author: Lenovo
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_sendDataByte(uint16_t locationAddress, uint8_t data);

uint8_t EEPROM_readDataByte(uint16_t locationAddress);


#endif /* EEPROM_INTERFACE_H_ */