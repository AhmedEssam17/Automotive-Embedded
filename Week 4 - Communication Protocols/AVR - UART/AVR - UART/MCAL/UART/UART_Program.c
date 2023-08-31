/*
 * UART_Program.c
 *
 * Created: 8/31/2023 12:29:51 PM
 *  Author: Lenovo
 */ 

#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"

#include "BitMath.h"
#include "std_types.h"

static void (*UART_RX_COMPLETE_CallBack)(uint8_t) = NULL;
static void (*UART_TX_COMPLETE_CallBack)(uint8_t) = NULL;

void UART_init(void){
	
	//--------------------------------------------
	// USART Control and Status Register B – UCSRB
	//--------------------------------------------
	
	/* RXCIE: RX Complete Interrupt Enable */
#if RXCIE == RXCI_DS
	CLEAR_BIT(UCSRB, UCSRB_RXCIE);
#elif RXCIE == RXCI_EN
	SET_BIT(UCSRB, UCSRB_RXCIE);
#endif

	/* TXCIE: TX Complete Interrupt Enable */
#if TXCIE == TXCI_DS
	CLEAR_BIT(UCSRB, UCSRB_TXCIE);
#elif TXCIE == TXCI_EN
	SET_BIT(UCSRB, UCSRB_TXCIE);
#endif

	/* UDRIE: USART Data Register Empty Interrupt Enable */
#if UDRIE == UDRI_DS
	CLEAR_BIT(UCSRB, UCSRB_UDRIE);
#elif UDRIE == UDRI_EN
	SET_BIT(UCSRB, UCSRB_UDRIE);
#endif

	/* RXEN: Receiver Enable */
#if RXEN == RX_EN
	CLEAR_BIT(UCSRB, UCSRB_RXEN);
#elif RXEN == RX_DS
	SET_BIT(UCSRB, UCSRB_RXEN);
#endif

	/* TXEN: Transmitter Enable */
#if TXEN == TX_EN
	CLEAR_BIT(UCSRB, UCSRB_TXEN);
#elif TXEN == TX_DS
	SET_BIT(UCSRB, UCSRB_TXEN);
#endif

	//--------------------------------------------
	// USART Control and Status Register C – UCSRC
	//--------------------------------------------

	/* Initialize UCSRC_Config */
	uint8_t UCSRC_Config = 0;
	
	/* URSEL: Register Select */
	SET_BIT(UCSRC_Config, UCSRC_URSEL);

	/* UMSEL: USART Mode Select */
#if UMSEL == UMSEL_Async
	CLEAR_BIT(UCSRC_Config, UCSRC_UMSEL);
#elif UMSEL == UMSEL_Sync
	SET_BIT(UCSRC_Config, UCSRC_UMSEL);
#endif

	/* UPM1:0: Parity Mode */
	UCSRC_Config &= ~(0b11 << UCSRC_UPM0);
	UCSRC_Config |= (UPM << UCSRC_UPM0);

	/* USBS: Stop Bit Select */
#if USBS == USBS_1BIT
	CLEAR_BIT(UCSRC_Config, UCSRC_USBS);
#elif UMSEL == USBS_2BIT
	SET_BIT(UCSRC_Config, UCSRC_USBS);
#endif

	/* UCSZ1:0: Character Size */
#if UCSZ == UCSZ_9BIT
	SET_BIT(UCSRB, UCSRB_UCSZ2);
	SET_BIT(UCSRC_Config, UCSRC_UCSZ1);
	SET_BIT(UCSRC_Config, UCSRC_UCSZ0);
#else
	CLEAR_BIT(UCSRC_Config, UCSRB_UCSZ2);
	UCSRC_Config &= ~(0b11 << UCSRC_UCSZ0);
	UCSRC_Config |= (UCSZ << UCSRC_UCSZ0);
#endif
	
	/* Set UCSRC = UCSRC_Config */
	UCSRC = UCSRC_Config;
}

void UART_TransmitByte(uint8_t data){
	while(READ_BIT(UCSRA, UCSRA_UDRE) == 0);
	UDR = data;
}

uint8_t UART_RecieveByte(void){
	while(READ_BIT(UCSRA, UCSRA_RXC) == 0);
	return UDR;
}

uint8_t UART_getUDRValue(void){
	return UDR;
}

void UART_setBaudRate(uint32_t baudRate){
	uint32_t BR = 8000000 / baudRate;
	BR /= 16;
	BR -= 1;
	if(BR < 255){
		UBRRL = (uint8_t)(BR);
	}
	else{
		UBRRL = (uint8_t)(BR);
		UBRRH = 0x0F & (BR >> 8);
	}
}

void UART_TransmitString(const uint8_t *data){
	while(*data != '\0'){
		UART_TransmitByte(*data);
		data++;
	}
}

void UART_RecieveString(uint8_t *data){
	do{
		*data = UART_RecieveByte();
		data++;
	}
	while((*(data - 1) != '\r'));
	*(data - 1) = '\0';
}

void UART_RegisterCallBack(uint8_t UART_Interrupt, void (*fptr)(uint8_t)){
	switch(UART_Interrupt){
		case 0:
			UART_RX_COMPLETE_CallBack = fptr;
			break;
		case 1:
			UART_TX_COMPLETE_CallBack = fptr;
			break;
	}
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void){
	if(UART_RX_COMPLETE_CallBack != NULL){
		UART_RX_COMPLETE_CallBack(UDR);
	}
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void){
	if(UART_TX_COMPLETE_CallBack != NULL){
		UART_TX_COMPLETE_CallBack(UDR);
	}
}

