/*
 * UART_Config.h
 *
 * Created: 8/31/2023 12:28:54 PM
 *  Author: Lenovo
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*
 * USART Control and Status Register B – UCSRB - RX Complete Interrupt Enable
 * RXCI_EN -> Enable interrupt on the RXC Flag
 * RXCI_DS -> Disable interrupt on the RXC Flag			
 */
#define RXCIE			RXCI_EN

/*
 * USART Control and Status Register B – UCSRB - TX Complete Interrupt Enable
 * TXCI_EN -> Enable interrupt on the TXC Flag
 * TXCI_DS -> Disable interrupt on the TXC Flag			
 */
#define TXCIE			TXCI_DS

/*
 * USART Control and Status Register B – UCSRB - USART Data Register Empty Interrupt Enable
 * UDRI_EN -> Enable interrupt on the UDRE Flag
 * UDRI_DS -> Disable interrupt on the UDRE Flag			
 */
#define UDRIE			UDRI_DS

/*
 * USART Control and Status Register B – UCSRB - Receiver Enable
 * RX_EN -> Enable the USART Receiver
 * RX_DS -> Disable the USART Receiver						
 */
#define RXEN			RX_EN

/*
 * USART Control and Status Register B – UCSRB - Transmitter Enable
 * TX_EN -> Enable the USART Transmitter
 * TX_DS -> Disable the USART Transmitter					
 */
#define TXEN			TX_EN

/*
 * USART Control and Status Register C – UCSRC - USART Mode Select
 * USART_Asynch -> Asynchronous Operation
 * USART_Synch  -> Synchronous Operation					
 */
#define UMSEL			UMSEL_Async

/*
 * USART Control and Status Register C – UCSRC - Parity Mode
 * PM_DS 	-> 	Disabled
 * PM_EVEN	->	Enabled, Even Parity
 * PM_ODD	->	Enabled, Odd Parity							
 */
#define	UPM				UPM_DS

/*
 * USART Control and Status Register C – UCSRC - Stop Bit Select
 * SB_1BIT	->	stop bit 1-bit
 * SB_2BIT	->	stop bit 2-bit								
 */
#define USBS			USBS_1BIT

/*
 * USART Control and Status Register B,C – UCSRB,UCSRC - Character Size
 * UCSZ_5BIT ->	DATA Character Size 5-bit
 * UCSZ_6BIT ->	DATA Character Size 6-bit
 * UCSZ_7BIT ->	DATA Character Size 7-bit
 * UCSZ_8BIT ->	DATA Character Size 8-bit
 * UCSZ_9BIT ->	DATA Character Size 9-bit								
 */
#define UCSZ			UCSZ_8BIT

#endif /* UART_CONFIG_H_ */