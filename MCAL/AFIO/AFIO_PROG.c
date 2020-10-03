/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : AFIO DRIVER                      */
/*   DATE        : 16 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/



/****************************************/
/* 			     Directives 			*/
/****************************************/
#include "../include/LIB/LIB.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/AFIO/AFIO_INT.h"
#include "../include/MCAL/AFIO/AFIO_PRIV.h"
#include "../include/MCAL/AFIO/AFIO_CONF.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include"../include/MCAL/RCC/RCC_INT.h"
#include"../include/MCAL/RCC/RCC_PRIV.h"

void AFIO_voidInit(void)
{
	RCC_vidSetPeripheralclock(APB2,AFIOEN,ON);
}

void AFIO_voidSetEXTIConfig(u8 Copy_u8LineNum, u8 Copy_u8PortName)
{
	u8 Local_u8RegIndex = 0;
	u8 Local_u8Port = 0;
	if(Copy_u8LineNum <= 3)
	{
		Local_u8RegIndex = 0;
	}
	else if(Copy_u8LineNum <= 7)
	{
		Local_u8RegIndex = 1;
		Copy_u8LineNum -=4;
	}
	else if(Copy_u8LineNum <= 11)
	{
		Local_u8RegIndex = 2;
		Copy_u8LineNum -= 8;
	}
	else if(Copy_u8LineNum <= 15)
	{
		Local_u8RegIndex = 3;
		Copy_u8LineNum -= 12;
	}
	else
	{
		/*An error to be displayed*/
	}

	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			Local_u8Port = 0b0000;
			break;
		case GPIO_PORTB:
			Local_u8Port = 0b0001;
			break;
		case GPIO_PORTC:
			Local_u8Port = 0b0010;
			break;
		default:
			/*An error to be displayed*/
			break;
	}

	/* Reset the register before any logical operations */
	AFIO -> EXTICR[Local_u8RegIndex] &=~((0b1111) << (Copy_u8LineNum * 4));
	AFIO -> EXTICR[Local_u8RegIndex] |= ((Local_u8Port) << (Copy_u8LineNum * 4));

}
