/*
 * UART_Private.h
 *
 * Created: 8/31/2023 12:19:15 PM
 *  Author: Lenovo
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

//====================================================================
//						UART Base Address
//====================================================================

#define UDR		(*(volatile uint8_t *)0x2C)
#define UCSRA	(*(volatile uint8_t *)0x2B)
#define UCSRB	(*(volatile uint8_t *)0x2A)
#define UBRRL	(*(volatile uint8_t *)0x29)
#define UBRRH	(*(volatile uint8_t *)0x40)
#define UCSRC	(*(volatile uint8_t *)0x40)

//====================================================================
//					Configuration Reference
//====================================================================

//--------------------------------------------
// USART Control and Status Register B – UCSRB
//--------------------------------------------
	
/*  RXCIE: RX Complete Interrupt Enable */
#define RXCI_DS					0
#define RXCI_EN					1

/*  TXCIE: TX Complete Interrupt Enable */
#define TXCI_DS					0
#define TXCI_EN					1

/*  UDRIE: USART Data Register Empty Interrupt Enable */
#define UDRI_DS					0
#define UDRI_EN					1

/*  RXEN: Receiver Enable */
#define RX_DS					0
#define RX_EN					1

/*  TXEN: Transmitter Enable */
#define TX_DS					0
#define TX_EN					1

//--------------------------------------------
// USART Control and Status Register C – UCSRC
//--------------------------------------------

/*  URSEL: Register Select */
#define URSEL_UBRRH				0
#define URSEL_UCSRC				1

/*  UMSEL: USART Mode Select */
#define UMSEL_Async				0
#define UMSEL_Sync				1

/*  UPM1:0: Parity Mode */
#define UPM_DS					0
#define UPM_EVEN				2
#define UPM_ODD					3

/*  USBS: Stop Bit Select */
#define USBS_1BIT				0
#define USBS_2BIT				1

/*  UCSZ1:0: Character Size */
#define UCSZ_5BIT				0
#define UCSZ_6BIT				1
#define UCSZ_7BIT				2
#define UCSZ_8BIT				3
#define UCSZ_9BIT				7

/*	UCSRA bits */
#define UCSRA_RXC				7
#define UCSRA_TXC				6
#define UCSRA_UDRE				5
#define UCSRA_FE				4
#define UCSRA_DOR				3
#define UCSRA_PE				2
#define UCSRA_U2X				1
#define UCSRA_MPCM				0

/*	UCSRB bits */
#define UCSRB_RXCIE				7
#define UCSRB_TXCIE				6
#define UCSRB_UDRIE				5
#define UCSRB_RXEN				4
#define UCSRB_TXEN				3
#define UCSRB_UCSZ2				2
#define UCSRB_RXB8				1
#define UCSRB_TXB8				0

/* UCSRC bits */
#define UCSRC_URSEL				7
#define UCSRC_UMSEL				6
#define UCSRC_UPM1				5
#define UCSRC_UPM0				4
#define UCSRC_USBS				3
#define UCSRC_UCSZ1				2
#define UCSRC_UCSZ0				1
#define UCSRC_UCPOL				0

#endif /* UART_PRIVATE_H_ */