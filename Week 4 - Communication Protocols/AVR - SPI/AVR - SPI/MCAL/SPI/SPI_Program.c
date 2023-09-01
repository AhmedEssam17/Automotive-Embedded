/*
 * SPI_Program.c
 *
 * Created: 9/1/2023 11:38:21 AM
 *  Author: Lenovo
 */ 

#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"

static void (*SPI_CallBack)(void);

void SPI_init(){
	
	//--------------------------------------------
	// SPI Control Register – SPCR
	//--------------------------------------------
	uint8_t SPCR_Config = 0;
	
	/* SPIE: SPI Interrupt Enable */
#if SPIE == SPIE_EN
	SET_BIT(SPCR_Config, SPCR_SPIE);
#elif SPIE == SPIE_DS
	CLEAR_BIT(SPCR_Config, SPCR_SPIE);
#endif

	/* SPIE: SPI Interrupt Enable */
#if SPE == SPI_EN
	SET_BIT(SPCR_Config, SPCR_SPE);
#elif SPE == SPI_DS
	CLEAR_BIT(SPCR_Config, SPCR_SPE);
#endif	

	/* DORD: Data Order */
#if DORD == DORD_LSB
	SET_BIT(SPCR_Config, SPCR_DORD);
#elif DORD == DORD_MSB
	CLEAR_BIT(SPCR_Config, SPCR_DORD);
#endif

	/* MSTR: Master/Slave Select */
#if MSTR == MSTR_MASTER
	SET_BIT(SPCR_Config, SPCR_MSTR);
#elif MSTR == MSTR_SLAVE
	CLEAR_BIT(SPCR_Config, SPCR_MSTR);
#endif

	/* CPOL: Clock Polarity */
	/* CPHA: Clock Phase */	
	SPCR_Config &= ~(0b11<<SPCR_CPHA);
	SPCR_Config |= (CLK_POL_PHA<<SPCR_CPHA);
	
	/* SPI2X: Double SPI Speed Bit*/
#if SPR2X == SPR2X_EN
	SET_BIT(SPSR, SPSR_SPI2X);
#elif SPR2X == SPR2X_DS
	CLEAR_BIT(SPSR, SPSR_SPI2X);
#endif

	/* SPR1, SPR0: SPI Clock Rate Select 1 and 0 */
	SPCR_Config &= ~(0b11<<SPCR_SPR0);
	SPCR_Config |= SPR;
	
	SPCR = SPCR_Config;
}

uint8_t SPI_Transceive(uint8_t data){
	
	SPDR = data;
	
	while(!READ_BIT(SPSR, SPSR_SPIF));
	
	return SPDR;
}

void SPI_setCallBack(void(*fptr)(void)){
	SPI_CallBack = fptr;
}

void __vector_12(void) __attribute((signal));
void __vector_12(void)
{
	if(SPI_CallBack != NULL)
	{
		SPI_CallBack();
	}
}

