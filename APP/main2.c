
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
/****************************************************/
/* 				   LCD Directives 					*/
/****************************************************/
#include"../include/HAL/LCD/LCD_INT.h"
#include"../include/HAL/LCD/LCD_CONF.h"

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


/*
  GPIO_ErrorStatusSetPinMode(PIN0,GPIO_PORTA,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(PIN1,GPIO_PORTA,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(PIN2,GPIO_PORTA,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(PIN3,GPIO_PORTA,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(PIN4,GPIO_PORTA,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(PIN5,GPIO_PORTA,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(PIN9,GPIO_PORTA,Output2_AFPushPull);
	GPIO_ErrorStatusSetPinMode(PIN10,GPIO_PORTA,Input_Floating);
	    CAN_voidInit();
		CAN_Msg x;
		CAN_voidCreateMessage(1,88,0,1,CAN_MSG_Standard_Format,CAN_MSG_DataFrame,CAN_TSR_TME0,&x);
		// SYSTICK_voidSetBusyWait(1000000);



*/		CAN_voidInit();
		u16 x=0;
        SYSTICK_voidSetBusyWait(1000000);
        LCD_void4bitIntialization();


	    while (1)
	    {
		  //LCD_voidSend_String("Welcome");
		//  LCD_voidSend_4bitString("Welcome");


	    	MCAN_voidReceiveData(&x);
	    	LCD_void4bitDisplayNumber(x);
	    	SYSTICK_voidSetBusyWait(1000000);
	    				    u8 error=0;
	    				    error= ((GET_BIT(CAN->ESR,6)<<2) | (GET_BIT(CAN->ESR,5)<<1) | GET_BIT(CAN->ESR,4));


	    				    LCD_void4bitGoToPos(2,0);
	    				    if (error == 0)
	    				    {
	    				    	LCD_voidSend_4bitString("No Error");
	    				    }
	    				    else if (error ==1)
	    				    {
	    				    	LCD_voidSend_4bitString("Stuff Error");
	    				    }
	    				    else if (error ==2)
	    				    {
	    				       	LCD_voidSend_4bitString("Form Error");
	    				    }
	    				    else if (error ==3)
	    				    {
	    				       	LCD_voidSend_4bitString("Acknowledgment Error");
	    				    }
	    				    else if (error ==4)
	    				    {
	    				       	LCD_voidSend_4bitString("Bit recessive Error");
	    				    }
	    				    else if (error ==5)
	    				    {
	    				       	LCD_voidSend_4bitString("Bit dominant Error");
	    				    }
	    				    else if (error == 6)
	    				    {
	    				    	LCD_voidSend_4bitString("crc Error");
	    				    }
	    				    else if (error == 7)
	    				    {
	    				    	LCD_voidSend_4bitString("Set by software");
	    				    }


	    				    if (GET_BIT(CAN->ESR,0))
	    				    LCD_voidSend_4bitString("EWGF");
	    				    if (GET_BIT(CAN->ESR,1))
	    				    LCD_voidSend_4bitString("EPVF");
	    				    if (GET_BIT(CAN->ESR,2))
	    				    LCD_voidSend_4bitString("BOFF");
/*

	    	CAN_voidSendMessage(&x);

	    		    u8 error=0;
	    			error= ((GET_BIT(CAN->ESR,6)<<2) | (GET_BIT(CAN->ESR,5)<<1) | GET_BIT(CAN->ESR,4));



	    				    if (error == 0)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,Low);
	    				    }
	    				    else if (error ==1)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,Low);
	    				    }
	    				    else if (error ==2)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,Low);
	    				    }
	    				    else if (error ==3)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,Low);
	    				    }
	    				    else if (error ==4)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,High);
	    				    }
	    				    else if (error ==5)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,High);
	    				    }
	    				    else if (error == 6)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,Low);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,High);
	    				    }
	    				    else if (error == 7)
	    				    {
	    				    	GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,High);
	    				    	GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,High);
	    				    }
	    				    LCD_void4bitGoToPos(2,0);

	    				    if (GET_BIT(CAN->ESR,0))
	    				    	GPIO_ErrorStatusSetPinValue(PIN5,GPIO_PORTA,High);

	    				    if (GET_BIT(CAN->ESR,2))
	    				    	GPIO_ErrorStatusSetPinValue(PIN4,GPIO_PORTA,High);
*/
	    }
}




