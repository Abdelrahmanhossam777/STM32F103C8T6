/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : STP DRIVER                       */
/*   DATE        : 14 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* 				Library Directives 					*/
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* 				  GPIO Directives 					*/
/****************************************************/
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"

/****************************************************/
/* 				 SYSTICK Directives 				*/
/****************************************************/
#include"../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_INT.h"

/****************************************************/
/* 				   STP Directives	 				*/
/****************************************************/
#include"../include/HAL/Serial_To_Parallel/STP_INT.h"
#include"../include/HAL/Serial_To_Parallel/STP_PRIV.h"
#include"../include/HAL/Serial_To_Parallel/STP_CONF.h"



void STP_voidSendSynchronus (u16 copy_u8DataToSend)
{
	s8 Local_s8COUNTER;
	u16 Local_u8Bit;
	for (Local_s8COUNTER=15;Local_s8COUNTER>=0;Local_s8COUNTER--)
	{
		Local_u8Bit= GET_BIT(copy_u8DataToSend,Local_s8COUNTER );
		GPIO_ErrorStatusSetPinValue(STP_SerialData,Local_u8Bit);

		GPIO_ErrorStatusSetPinValue(STP_ShiftClock,High);
		SYSTICK_voidSetBusyWait(1);
		GPIO_ErrorStatusSetPinValue(STP_ShiftClock,Low);
		SYSTICK_voidSetBusyWait(1);
	}
	    GPIO_ErrorStatusSetPinValue(STP_StoreClock,High);
	    SYSTICK_voidSetBusyWait(1);
		GPIO_ErrorStatusSetPinValue(STP_StoreClock,Low);
		SYSTICK_voidSetBusyWait(1);
}
