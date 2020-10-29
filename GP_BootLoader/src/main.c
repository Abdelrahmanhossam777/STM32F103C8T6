
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
#include"../include/MCAL/CAN/CAN_INIT.h"
#include"../include/MCAL/CAN/CAN_PRIV.h"
/****************************************************/
/* 				   CAN Directives 					*/
/****************************************************/
#include"../include/MCAL/CAN/CAN_INIT.h"
#include"../include/MCAL/CAN/CAN_CONF.h"
#include"../include/MCAL/CAN/CAN_PRIV.h"


/* Declare a variable */
u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void func(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08002000;

	addr_to_call = *(Function_t*)(0x08002004);
	addr_to_call();
}

void main(void)
{
	u8 Local_u8RecStatus;
	/*RCC Initialize to work on 8 Mega external Crystal*/
	RCC_vidClkInit();
	RCC_vidSetClkStatus(HSI_Enable,ON);
	RCC_vidSetClkStatus(HSE_Enable,OFF);
	/* SYSTICK Timer Configuration  */
	SYSTICk_ErrorStatusConfig();
	/* Enable the Rcc for the GPIOA */
	GPIO_ErrorStatusIntialization(IOPA);
	/* Enable the Rcc and init for the USART */
	USART1_voidInit();
	/*	Enable clock for Flash interface peripheral	*/
	RCC_vidSetPeripheralclock(AHB,FLITFEN,ON);


	/*	Set GPIO Pins*/
	GPIO_ErrorStatusSetPinMode(PIN9,GPIO_PORTA,Output50_AFPushPull);  // Tx => output 50MHz AFPP
	GPIO_ErrorStatusSetPinMode(PIN10,GPIO_PORTA,Input_Floating);     // Rx => Input floating


	/* Start Timer to count for 15sec	*/
	SYSTICK_voidSetIntervalSingle (15000000,func);

	while(u8TimeOutFlag == 0)
	{
		Local_u8RecStatus = USART1_u8Receive( &(u8RecBuffer[u8RecCounter]) );
		if (Local_u8RecStatus == 1)
			{
				SYSTICK_voidStopInterval();
				if(u8RecBuffer[u8RecCounter] == '\n')
			{
				if (u8BLWriteReq == 1)
				{
					MFPEC_voidEraseAppArea();
					u8BLWriteReq = 0;
				}
				/* Parse */
				MBL_voidParseRecord(u8RecBuffer);
				USART1_voidTransmit("ok");
				u8RecCounter = 0;
			}
			else
			{
				u8RecCounter++ ;
			}

				SYSTICK_voidSetIntervalSingle(15000000,func);
		}
		else
		{
			/*	Nothing to do	*/
		}
	}
}
