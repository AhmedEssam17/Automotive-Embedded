/*
 * I2C_Private.h
 *
 * Created: 9/2/2023 9:52:22 AM
 *  Author: Lenovo
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

//====================================================================
//						I2C Base Address
//====================================================================

#define TWDR		(*(volatile uint8_t *)0x23)
#define TWAR		(*(volatile uint8_t *)0x22)
#define TWSR		(*(volatile uint8_t *)0x21)
#define TWBR		(*(volatile uint8_t *)0x20)

//====================================================================
//					Configuration Reference
//====================================================================


//--------------------------------------------
// TWI Control Register – TWCR
//--------------------------------------------

/* TWEA: TWI Enable Acknowledge Bit */
#define TWEA_DS				0
#define TWEA_EN				1


//--------------------------------------------
//				 TWCR Bits
//--------------------------------------------
#define TWCR_TWINT			7
#define TWCR_TWEA			6
#define TWCR_TWSTA			5
#define TWCR_TWSTO			4
#define TWCR_TWWC			3
#define TWCR_TWEN			2
#define TWCR_TWIE			0

//--------------------------------------------
//				 TWSR Bits
//--------------------------------------------
#define TWSR_TWPS7			7
#define TWSR_TWPS6			6
#define TWSR_TWPS5			5
#define TWSR_TWPS4			4
#define TWSR_TWPS3			3
#define TWSR_TWPS1			1
#define TWSR_TWPS0			0

//--------------------------------------------
//				 TWDR Bits
//--------------------------------------------
#define TWDR_TWD7			7
#define TWDR_TWD6			6
#define TWDR_TWD5			5
#define TWDR_TWD4			4
#define TWDR_TWD3			3
#define TWDR_TWD2			2
#define TWDR_TWD1			1
#define TWDR_TWD0			0

//--------------------------------------------
//				 TWAR Bits
//--------------------------------------------
#define TWAR_TWA6			7
#define TWAR_TWA5			6
#define TWAR_TWA4			5
#define TWAR_TWA3			4
#define TWAR_TWA2			3
#define TWAR_TWA1			2
#define TWAR_TWA0			1
#define TWAR_TWGCE			0

//====================================================================
//						 Addresses
//====================================================================

#define START_ACK                0x08 /* start has been sent */
#define REP_START_ACK            0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */

#endif /* I2C_PRIVATE_H_ */