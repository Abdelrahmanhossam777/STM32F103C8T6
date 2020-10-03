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

void USART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0')
	{
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
		i++;
	}
	/* Clear all flags */
		USART1 -> SR = 0;
}

u8 USART1_u8Receive(void)
{
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);
}
/******************************************************************************************************/

/*************************************************************************************************/
void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		USART1_voidTransmit("ATE0\r\n");
		Local_u8Result = voidEspValidateCmd();
	}

	Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Set station mode */
		USART1_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result = voidEspValidateCmd();
	}
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
void ESP_Connect(void)
{
	u8 Local_u8Result = 0;
	while(Local_u8Result == 0)
		{
			/* Set station mode */
			USART1_voidTransmit("AT+CWJAP_CUR=\"OrangeDSL-Abdelrahman\",\"ABDELRAHMAN@797_hoossam\"\r\n");
			Local_u8Result = voidEspValidateCmd();
		}
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
u8 ESP_GetData(void)
{
	u8 Local_u8Result = 0;
	while(Local_u8Result == 0)
		{
			/* Set station mode */
			USART1_voidTransmit("AT+CIPSTART=\"TCP\",\"162.253.155.226:80\"\r\n");
			Local_u8Result = voidEspValidateCmd();
		}
	 Local_u8Result = 0;
	while(Local_u8Result == 0)
		{
			/* Set station mode */
			USART1_voidTransmit("AT+CIPSEND=42\r\n");
			Local_u8Result = voidEspValidateCmd();
		}
	USART1_voidTransmit("GET http://abdelrahman.freevar.com/status.txt\r\n");
	return voidEspValidateCmd2();
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
u8 USART1_u8Receive2(void)
{
	u16 timeout=0;
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0)
	{
		timeout++;
		if (timeout==10000)

		{
			Loc_u8ReceivedData=255;
			break;
		}
	}
	if(Loc_u8ReceivedData==0)
	Loc_u8ReceivedData = USART1 -> DR;

	return (Loc_u8ReceivedData);
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
u8 voidEspValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;

	while (Dummy != 255)
	{
		Dummy = USART1_u8Receive2();
		Local_u8Response[i] = Dummy;
		i++;
	}

	/* Check if Ok */
	if ((Local_u8Response[0] == 'O' && Local_u8Response[1] == 'K') || (Local_u8Response[0] == 'o' && Local_u8Response[1] == 'k'))
	{
		Result = 1;
	}

	return Result;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
u8 voidEspValidateCmd2(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;

	while (Dummy != 255)
	{
		Dummy = USART1_u8Receive2();
		Local_u8Response[i] = Dummy;
		i++;
	}

	/* Check if Ok */
	if (Local_u8Response[7] == '1')
	{
		Result = 1;
	}

	return Result;
}
