/*
 * SPI_Private.h
 *
 * Created: 9/1/2023 11:38:35 AM
 *  Author: Lenovo
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

//====================================================================
//						SPI Base Address
//====================================================================

#define SPCR		(*(volatile uint8_t *)0x2D)
#define SPSR		(*(volatile uint8_t *)0x2E)
#define SPDR		(*(volatile uint8_t *)0x2F)

//====================================================================
//					Configuration Reference
//====================================================================

//--------------------------------------------
// SPI Control Register – SPCR
//--------------------------------------------

/* SPIE: SPI Interrupt Enable */
#define SPIE_DS					0
#define SPIE_EN					1

/* SPE: SPI Enable */
#define SPI_DS					0
#define SPI_EN					1

/* DORD: Data Order */
#define DORD_MSB				0
#define DORD_LSB				1

/* MSTR: Master/Slave Select */
#define MSTR_SLAVE				0
#define MSTR_MASTER				1

/* CPOL: Clock Polarity */
/* CPHA: Clock Phase */
#define CLK_LEADING_SAMPLE_RISING_TRAILING_SETUP_FALLING		0
#define CLK_LEADING_SETUP_RISING_TRAILING_SAMPLE_FALLING		1
#define CLK_LEADING_SAMPLE_FALLING_TRAILING_SETUP_RISING		2
#define CLK_LEADING_SETUP_FALLING_TRAILING_SAMPLE_RISING		3

/* SPR1, SPR0: SPI Clock Rate Select 1 and 0 */
#define SPR_PRES_4_PRES2X_2		0
#define SPR_PRES_16_PRES2X_8	1
#define SPR_PRES_64_PRES2X_32	2
#define SPR_PRES_128_PRES2X_64	3

/* SPI2X: Double SPI Speed Bit*/
#define SPR2X_DS				0
#define SPR2X_EN				1

//--------------------------------------------
//				 SPCR Bits
//--------------------------------------------
#define SPCR_SPIE				7
#define SPCR_SPE				6
#define SPCR_DORD				5
#define SPCR_MSTR				4
#define SPCR_CPOL				3
#define SPCR_CPHA				2
#define SPCR_SPR1				1
#define SPCR_SPR0				0

//--------------------------------------------
//				 SPSR Bits
//--------------------------------------------
#define SPSR_SPIF				7
#define SPSR_WCOL				6
#define SPSR_SPI2X				0

//--------------------------------------------
//				 SPDR Bits
//--------------------------------------------
#define SPDR_MSB				7
#define SPDR_LSB				7


#endif /* SPI_PRIVATE_H_ */