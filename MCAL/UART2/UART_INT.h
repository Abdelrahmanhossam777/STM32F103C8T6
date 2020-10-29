/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : UART DRIVER                      */
/*   DATE        : 20 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_UART_INT_H
#define _MCAL_UART_INT_H

/* Defining Macros */

#define USART_U8_8_BIT_WORD					0
#define USART_U8_9_BIT_WORD					1

#define USART_U8_PARITY_DISABLED			0
#define USART_U8_PARITY_ENABLED				1

#define USART_U8_EVEN_PARITY				0
#define USART_U8_ODD_PARITY					1

#define USART_U8_PE_DISABLED				0
#define USART_U8_PE_ENABLED					1


/*******************/

void USART1_voidInit(void);

void USART1_voidTransmit(u8 arr[]);

u8 USART1_u8Receive(u8 * Copy_u8PDataReceived);

void USART1_VidClearFlags( void );

void USART1_VidSetCallBack( void (*ptr) (void) );

void USART1_VidSendStringSynch ( u8 * Copy_ptrString );

void USART1_VidSendCharSync ( u8 Copy_u8Char );

#endif
