/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

/****************************************************/
/* 				Library Directives 					*/
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* 				   USART Directives 		    	*/
/****************************************************/
#include"../include/MCAL/UART/UART_INT.h"
#include"../include/MCAL/UART/UART_PRIV.h"
#include"../include/MCAL/UART/UART_CONF.h"

#include "../include/HAL/ESP8266/ESP8266_INTERFACE.h"

/****************************************************/
/* 				 SYSTICK Directives 				*/
/****************************************************/
#include"../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_INT.h"


u8 volatile Iterator = 0  ;
u8 volatile DataCome[200] ;

void USART_CallBack ( void ){

	/* Receive ESP8266 Response */
	DataCome[ Iterator ] = USART1_u8ReadDataRegister();
	/* ------------------ */
	Iterator++;
	USART1_VidClearFlags();

}

void ESP8266_VidInit ( void ){

	/* Set USART1 CallBack To Receive The Response Of The ESP8266 */
	USART1_VidSetCallBack( USART_CallBack );

	/* Sending AT Command To Check ESP8266 Is Working Or Not  */
	USART1_VidSendStringSynch( (u8 *)"AT\r\n" );

	SYSTICK_voidSetBusyWait( 3000000 );

	/* Clear ESP8266 Buffer */
	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *)"AT+CWMODE=3\r\n" );
	SYSTICK_voidSetBusyWait( 3000000 );

	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *)"AT+CIPMODE=0\r\n" );
	SYSTICK_voidSetBusyWait( 3000000 );

}

void ESP8266_VidConnectToWiFi ( u8 * SSID , u8 * Password ){

	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *) "AT+CWJAP=\"" );
	USART1_VidSendStringSynch( (u8 *) SSID );
	USART1_VidSendStringSynch( (u8 *) "\",\"" );
	USART1_VidSendStringSynch( (u8 *) Password);
	USART1_VidSendStringSynch( (u8 *) "\"\r\n");
	SYSTICK_voidSetBusyWait( 8000000 );
}


void ESP8266_VidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port ){

	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *) "AT+CIPSTART=\"TCP\",\"" );
	USART1_VidSendStringSynch( (u8 *) Copy_u8Domain );
	USART1_VidSendStringSynch( (u8 *) "\"," );
	USART1_VidSendStringSynch( (u8 *) Copy_u8Port );
	USART1_VidSendStringSynch( (u8 *) "\r\n" );
	SYSTICK_voidSetBusyWait( 2000000 );

}

void ESP8266_VidSendHttpReq( u8 * Copy_u8Key , u8 * Copy_u8Data , u8 * Copy_u8Length ){

	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *) "AT+CIPSEND=" );
	USART1_VidSendStringSynch( (u8 *) Copy_u8Length );
	USART1_VidSendStringSynch( (u8 *) "\r\n" );
	SYSTICK_voidSetBusyWait( 4000000 );
	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *) "GET /update?api_key=" );
	USART1_VidSendStringSynch( (u8 *) Copy_u8Key );
	USART1_VidSendStringSynch( (u8 *) "&field1=" );
	USART1_VidSendStringSynch( (u8 *) Copy_u8Data );
	USART1_VidSendStringSynch( (u8 *) "\r\n" );
	SYSTICK_voidSetBusyWait( 2000000 );
}

u8   ESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID , u8 * Copy_u8Length ){

	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *) "AT+CIPSEND=" );
	USART1_VidSendStringSynch( (u8 *) Copy_u8Length );
	USART1_VidSendStringSynch( (u8 *) "\r\n" );
	SYSTICK_voidSetBusyWait( 4000000 );

	ESP8266_VidClearBuffer();

	USART1_VidSendStringSynch( (u8 *) "GET http://" );
	USART1_VidSendStringSynch( (u8 *) Copy_u8ChannelID );
	USART1_VidSendStringSynch( (u8 *) "/value.txt\r\n" );
	SYSTICK_voidSetBusyWait( 2000000 );

	ESP8266_VidConnectToSrvTcp( (u8 *)"162.253.155.226" , (u8 *)"80" );

	/*For yrabiot3.freevar.com ( Value Array Index )*/
	return  DataCome[82] ;

}

void ESP8266_VidClearBuffer ( void ){

	u8 LOC_u8Iterator1 = 0 ;
	Iterator     = 0 ;

	for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 150 ; LOC_u8Iterator1++ ){

		DataCome[ LOC_u8Iterator1 ] = 0 ;

	}

}
