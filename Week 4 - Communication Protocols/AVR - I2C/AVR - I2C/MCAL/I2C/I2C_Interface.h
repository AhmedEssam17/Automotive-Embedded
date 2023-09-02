/*
 * I2C_Interface.h
 *
 * Created: 9/2/2023 9:52:50 AM
 *  Author: Lenovo
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "BitMath.h"
#include "std_types.h"


typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
}I2C_ErrorStatus;

/*Set master address to 0 if master will not be addressed*/
void I2C_initMaster(uint8_t address);

void I2C_initSlave(uint8_t address);

I2C_ErrorStatus I2C_SendStartCondition(void);

I2C_ErrorStatus I2C_SendRepeatedStart(void);

I2C_ErrorStatus I2C_SendSlaveAddressWithWrite(uint8_t slaveAddress);

I2C_ErrorStatus I2C_SendSlaveAddressWithRead(uint8_t slaveAddress);

I2C_ErrorStatus I2C_MasterWriteDataByte(uint8_t data);

I2C_ErrorStatus I2C_MasterReadDataByte(uint8_t* data);

void I2C_SendStopCondition(void);


#endif /* I2C_INTERFACE_H_ */