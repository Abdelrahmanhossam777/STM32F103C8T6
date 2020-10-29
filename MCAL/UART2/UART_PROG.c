/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : UART DRIVER                      */
/*   DATE        : 20 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include"../include/MCAL/UART/UART_INT.h"
#include"../include/MCAL/UART/UART_PRIV.h"
#include"../include/MCAL/UART/UART_CONF.h"
#include "../include/MCAL/RCC/RCC_CONF.h"
#include "../include/MCAL/RCC/RCC_INT.h"
#include "../include/MCAL/RCC/RCC_PRIV.h"

void (*USART1_CallBack)(void);

void USART1_voidInit(void)
{
	RCC_vidSetPeripheralclock(APB2,USARTEN,ON);
	/*	baud rate = 9600		*/
	USART1 -> BRR =  0x45; //0x341;

	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */

	USART1 -> SR = 0;						/* Clearing status register */
}

void USART1_voidTransmit(u8 Copy_u8PDataArr[])
{
	/*Transmit the Array*/
	u8 Local_u8i = 0;
	/*Check for the NULL Character*/
	while(Copy_u8PDataArr[Local_u8i] != '\0')
	{
		USART1 -> DR = Copy_u8PDataArr[Local_u8i];
		/*polling on the TC (Transmission Complete) flag in SR*/
		while((GET_BIT((USART1 -> SR),6)) == 0);
		Local_u8i++;
	}
}

u8 USART1_u8Receive(u8 * Copy_u8PDataReceived)
{
	u8 Local_u8ReceiveState = 0;
	/*polling on the RXNE (Receive Complete) flag in SR*/
	if((GET_BIT(USART1 -> SR,5)) == 1)
	{
		/*	Set the ReceiveState variable to be 1*/
		Local_u8ReceiveState = 1;
		/*Return the first 8-bit from the DR and store it in the Address of the Passed variable*/
		*Copy_u8PDataReceived = (0xFF & (USART1 -> DR));
	}
	return Local_u8ReceiveState;
}

void USART1_VidClearFlags( void ){

	/* Clear all flags */
	USART1 -> SR = 0;

}

void USART1_VidSetCallBack( void (*ptr) (void) ){

	USART1_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	USART1_CallBack();

}

void USART1_VidSendCharSync ( u8 Copy_u8Char ){

	USART1 -> DR = Copy_u8Char ;

	while( GET_BIT( USART1 -> SR , 6 ) == 0 );

	CLR_BIT( USART1 -> SR , 6 );

}

void USART1_VidSendStringSynch ( u8 * Copy_ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while ( Copy_ptrString[ LOC_u8Iterator ] != '\0' ){

		USART1_VidSendCharSync( Copy_ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator++ ;

	}

}

u8 USART1_u8ReadDataRegister ( void ){

	return ( USART1 -> DR );

}
