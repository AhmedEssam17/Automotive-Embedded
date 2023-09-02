/*
 * EEPROM_Program.c
 *
 * Created: 9/2/2023 3:01:48 PM
 *  Author: Lenovo
 */ 

#include "std_types.h"
#include <util/delay.h>
#define F_CPU 16000000UL

#include "I2C_Interface.h"

#include "EEPROM_Interface.h"
#include "EEPROM_Config.h"
#include "EEPROM_Private.h"

void EEPROM_sendDataByte(uint16_t locationAddress, uint8_t data)
{
	uint8_t localAddressPacket;

	localAddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8_t)(locationAddress >>8);

	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	/*Send start condition*/
	I2C_SendStartCondition();

	/*Send the address packet*/
	I2C_SendSlaveAddressWithWrite(localAddressPacket);

	/*Send the rest 8bits of the location address*/
	I2C_MasterWriteDataByte((uint8_t)locationAddress);

	/*Send the data byte to the memory location*/
	I2C_MasterWriteDataByte(data);

	/*Send stop condition*/
	I2C_SendStopCondition();

	/*Delay until the write cycle is finished*/
	_delay_ms(10);
}

uint8_t EEPROM_readDataByte(uint16_t locationAddress)
{
	uint8_t localAddressPacket, data;

	localAddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8_t)(locationAddress >>8);

	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	/*Send start condition*/
	I2C_SendStartCondition();

	/*Send the address packet with write request*/
	I2C_SendSlaveAddressWithWrite(localAddressPacket);

	/*Send the rest 8bits of the location address*/
	I2C_MasterWriteDataByte((uint8_t)locationAddress);

	/*Send repeated start to change write request into read request*/
	I2C_SendRepeatedStart();

	/*Send the address packet with read request*/
	I2C_SendSlaveAddressWithRead(localAddressPacket);
	
	/*Get the data from memory*/
	I2C_MasterReadDataByte(&data);

	/*send the stop condition*/
	I2C_SendStopCondition();

	return data;
}


