
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
/* 				   NVIC Directives 					*/
/****************************************************/
#include"../include/MCAL/NVIC/NVIC_PRIV.h"
#include"../include/MCAL/NVIC/NVIC_INT.h"
/****************************************************/
/* 				   USART Directives 		    	*/
/****************************************************/
#include"../include/MCAL/UART/UART_INT.h"
#include"../include/MCAL/UART/UART_PRIV.h"
#include"../include/MCAL/UART/UART_CONF.h"
/****************************************************/
/* 				   EXTI Directives 					*/
/****************************************************/
#include"../include/MCAL/EXTI/EXTI_INT.h"
#include"../include/MCAL/EXTI/EXTI_PRIV.h"
#include"../include/MCAL/EXTI/EXTI_CONF.h"
/****************************************************/
/* 				   SPI Directives 					*/
/****************************************************/
#include "../include/MCAL/SPI/SPI_INT.h"
#include "../include/MCAL/SPI/SPI_PRIV.h"
#include "../include/MCAL/SPI/SPI_CONF.h"
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
/****************************************************/
/* 			      OS Directives 					*/
/****************************************************/
#include "../include/SERVICES/OS_INT.h"
#include "../include/SERVICES/OS_CONF.h"
#include "../include/SERVICES/OS_PRIV.h"
/****************************************************/
/* 				7Segmant Directives 				*/
/****************************************************/
#include "../include/HAL/SEGMANT/Segmant_INT.h"
#include "../include/HAL/SEGMANT/Segmant_PRIV.h"
/****************************************************/
/* 				  KEYPAD Directives 				*/
/****************************************************/
#include"../include/HAL/KEYPAD/KEYPAD_INT.h"
#include"../include/HAL/KEYPAD/KEYPAD_PRIV.h"

/****************************************************/
/* 				 Led Matrix Directives 				*/
/****************************************************/
#include"../include/HAL/LED_MATRIX/LEDMATRIX_INT.h"
#include"../include/HAL/LED_MATRIX/LEDMATRIX_PRIV.h"
#include"../include/HAL/LED_MATRIX/LEDMATRIX_CONF.h"

/****************************************************/
/* 				 Led Matrix Directives 				*/
/****************************************************/
#include"../include/HAL/RGBLed/RGB_INT.h"
#include"../include/HAL/RGBLed/RGB_CONF.h"

/****************************************************/
/* 				    IR Directives 					*/
/****************************************************/
#include"../include/HAL/IR/IR_INT.h"
#include"../include/HAL/IR/IR_CONF.h"

/****************************************************/
/* 				    DAC Directives 					*/
/****************************************************/
#include "../include/HAL/DAC/DAC_INT.h"
#include "../include/HAL/DAC/DAC_CONF.h"

/****************************************************/
/* 				   STP Directives	 				*/
/****************************************************/
#include"../include/HAL/Serial_To_Parallel/STP_INT.h"
#include"../include/HAL/Serial_To_Parallel/STP_PRIV.h"
#include"../include/HAL/Serial_To_Parallel/STP_CONF.h"
/****************************************************/
/* 				   TFT Directives 					*/
/****************************************************/
#include "../include/HAL/TFT/TFT_INT.h"
#include "../include/HAL/TFT/TFT_PRIV.h"
#include "../include/HAL/TFT/TFT_CONF.h"


//#include "image.h"
/*
//u8 data[41]={0,0,0,0,0,0,0, 254, 146, 146, 146, 108, 0, 0, 254, 146, 146, 146, 0, 0, 254, 130, 130, 130, 124, 0, 0, 124, 130, 130, 130, 124, 0,0,0,0,0,0,0,0,0,0,0};
u8 doaa[41]={0,0,0,0,0,0,0,0, 254, 130, 130, 130, 124, 0, 0, 124, 130, 130, 130, 124, 0, 0, 252, 18, 18, 18, 252, 0, 0, 252, 18, 18, 18, 252, 0,0,0,0,0,0,0,0,0,0,0};
u8 Shaza[41]={0,0,0,0,0,0,0,0, 76, 146, 146, 146, 100, 0, 0, 254, 16, 16, 16, 254, 0, 0, 252, 18, 18, 18, 252, 0, 0, 194, 162, 146, 138, 134, 0, 0, 252, 18, 18, 252, 0,0,0,0,0,0,0,0,0,0,0};
u8 Rawan[53]={0,0,0,0,0,0,0,0,254, 18, 18, 18, 236, 0, 0, 252, 18, 18, 18, 252, 0, 0, 252, 64, 32, 64, 252, 0, 0, 252, 18, 18, 18, 252, 0, 0, 254, 28, 56, 112, 254, 0, 0,0,0,0,0,0,0,0,0,0,0};
*/
int main ()
{

		/*RCC Initialize to work on 8 Mega external Crystal*/
	    RCC_vidClkInit();
	    /* SYSTICK Timer Configuration  */
	    SYSTICk_ErrorStatusConfig();
	    /* Enable the Rcc for the GPIOA */
		GPIO_ErrorStatusIntialization(IOPA);
		/* Enable the Rcc for the GPIOB */
//		GPIO_ErrorStatusIntialization(IOPB);
		/* Enable the Rcc for the GPIOC */
//		GPIO_ErrorStatusIntialization(IOPC);
		/* Enable the AFIO */
//		AFIO_voidInit();
		/* Enable the IR pins and set it to Input floating */
//		IR_voidInit();
		/* Set the Callback for the EXTI0 */
//   	EXTI_voidSetCallBack(IR_voidGetFrame,EXTI0_CallBack);
		/* Initialize the EXTI0 on pin A0 */
//		EXTI_voidInit();
		/* Enable the NVIC peripheral for the EXTI0 */
//	    NVIC_ErrorStatusEnable(EXTI0);
		/* Initialize the Led Matrix Pins */
//		LEDMAT_voidInit();
		/* Initialize the RGB Led Pins */
//		RGB_voidInit();
		/* Initialize the DAC Pins */
//   	DAC_voidInit();
//		GPIO_ErrorStatusSetPinMode(PIN9,GPIO_PORTA,Output2_PushPull);
//		GPIO_ErrorStatusSetPinMode(PIN10,GPIO_PORTA,Input_Pull);
//		USART1_voidInit();
//		TFT_voidInitPins();
//		SPI1_voidInit();
//		TFT_voidinit();
		//TFT_voidDisplayImage(image2);
//		TFT_voidDisplayColor(0x0000);
//		u8 harr[7][5]={
//				{1,0,0,0,1},
//				{1,0,0,0,1},
//				{1,0,0,0,1},
//				{1,1,1,1,1},
//				{1,0,0,0,1},
//				{1,0,0,0,1},
//				{1,0,0,0,1},
//
//		};
//		u8 harr2[35]={1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1};
//		TFT_voidDrawChar(15,70,0xFFFF,harr);
//		//Da 7arf El A
//		u8 A[] = {0x7E, 0x09 , 0x09 , 0x09 , 0x7E } ;
//		u8 S[] = {0x4E, 0x49 , 0x49 , 0x49 , 0x71 } ;
//		HTFT_voidDisplayChar(A,0,0,0xFFFF);
//		HTFT_voidDisplayChar(S,6,0,0xFFFF);
//		TFT_voidDrawRectangle(15,70,30,90,0xFFFF);
	/*	GPIO_ErrorStatusSetPinMode(PIN0,GPIO_PORTA,Output2_PushPull);
		GPIO_ErrorStatusSetPinMode(PIN1,GPIO_PORTA,Output2_PushPull);
		GPIO_ErrorStatusSetPinMode(PIN2,GPIO_PORTA,Output2_PushPull);
		u8 data[41]={0,0,0,0,0,0,0, 254, 146, 146, 146, 108, 0, 0, 254, 146, 146, 146, 0, 0, 254, 130, 130, 130, 124, 0, 0, 124, 130, 130, 130, 124, 0,0,0,0,0,0,0,0,0,0,0};
*/
		// Infinite loop
//
	/*
	    GPIO_ErrorStatusSetPinMode(PIN0,GPIO_PORTA,Output2_PushPull);
	    GPIO_ErrorStatusSetPinMode(PIN1,GPIO_PORTA,Output2_PushPull);
	    GPIO_ErrorStatusSetPinMode(PIN2,GPIO_PORTA,Output2_PushPull);
	    GPIO_ErrorStatusSetPinMode(PIN3,GPIO_PORTA,Output2_PushPull);
	    GPIO_ErrorStatusSetPinMode(PIN4,GPIO_PORTA,Output2_PushPull);
		CAN_voidCreateMessage(1,255,0,1,CAN_MSG_Standard_Format,CAN_MSG_DataFrame,CAN_TSR_TME0,&x);
	    CAN_voidInit();
	    CAN_voidSendMessage(&x);
*/
		CAN_Msg x;
	    GPIO_ErrorStatusSetPinMode(PIN0,GPIO_PORTA,Output2_PushPull);
	    CAN_voidInit();
	    CAN_voidReadMessage(&x);
	    if (x.Data[0]==255)
	    	GPIO_ErrorStatusSetPinValue(PIN0,GPIO_PORTA,High);
	  while (1)
	    {

	/*	  CAN_voidSendMessage(CAN_TxMsg);
		  GPIO_ErrorStatusSetPinValue(PIN0,GPIO_PORTA,High);
		  SYSTICK_voidSetBusyWait(2000000);*/

		  CAN_voidReadMessage(&x);
		  if (x.Data[0]==255)
		  GPIO_ErrorStatusSetPinValue(PIN0,GPIO_PORTA,High);

		  /*for(u8 i=0; i<34;i++)
		  		  {
		  			  for (u32 x=0 ; x<15;x++)
		  			  LEDMAT_voidDisplayFrameSTP(data+i);
		  		  }*/
		 // TFT_voidDisplayImage(image);
		  //SYSTICK_voidSetBusyWait(4000000);
		  //TFT_voidDisplayImage(image2);
	    }
}




