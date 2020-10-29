
/****************************************************/
/* 				Library Directives 					*/
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
/****************************************************/
/* 			  	 RCC Directives 					*/
/****************************************************/
#include"../include/MCAL/RCC/RCC_INT.h"
#include"../include/MCAL/RCC/RCC_PRIV.h"
/****************************************************/
/* 				 SYSTICK Directives 				*/
/****************************************************/
#include"../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_INT.h"
/****************************************************/
/* 				  GPIO Directives 					*/
/****************************************************/
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
/****************************************************/
/* 				   USART Directives 		    	*/
/****************************************************/
#include"../include/MCAL/UART/UART_INT.h"
#include"../include/MCAL/UART/UART_PRIV.h"
#include"../include/MCAL/UART/UART_CONF.h"
/****************************************************/
/* 				   CAN Directives 					*/
/****************************************************/
#include"../include/MCAL/NVIC/NVIC_INT.h"
#include"../include/MCAL/NVIC/NVIC_PRIV.h"

#include"../include/HAL/ESP8266/ESP8266_INTERFACE.h"


void main(void)
{
	/* Create Variable To Receive Data From Server */
	u8 LOC_u8Data = 0;

	RCC_vidClkInit();
	/* SYSTICK Timer Configuration  */
	SYSTICk_ErrorStatusConfig();
	/* Enable the Rcc for the GPIOA */
	GPIO_ErrorStatusIntialization(IOPA);
	/* Enable the INT for the USART 1 */
	NVIC_ErrorStatusEnable(USART1_INT);
	/* Enable the Rcc and init for the USART */
	USART1_voidInit();
	/*	Set GPIO Pins*/
	GPIO_ErrorStatusSetPinMode(PIN9,GPIO_PORTA,Output50_AFPushPull);  // Tx => output 50MHz AFPP
	GPIO_ErrorStatusSetPinMode(PIN10,GPIO_PORTA,Input_Floating);     // Rx => Input floating
	GPIO_ErrorStatusSetPinMode(PIN0,GPIO_PORTA,Output2_PushPull);

	/* Setting ESP8266 Mode */
	ESP8266_VidInit();
	/* Connecting To WIFI Network */
	ESP8266_VidConnectToWiFi( (u8 *)"wifi Name" , (u8 *)"Password" );

	while(1)
	{

		/* Connecting To yrabiot3.freevar.com */
		ESP8266_VidConnectToSrvTcp( (u8 *)"162.253.155.226" , (u8 *)"80" );

		/* Connecting To yrabiot3.freevar.com */
		LOC_u8Data = ESP8266_u8ReceiveHttpReq( (u8 *)"abdelrahman.freevar.com/status.txt" , (u8 *)"42" );

		/* We Receive ASCII So We Will Subtract 48 From Data Come */
		MGPIO_VidSetPinValue( GPIOA , PIN0 , LOC_u8Data - 48 );

	}


}
