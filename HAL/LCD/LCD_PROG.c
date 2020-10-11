/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : LCD DRIVER                       */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/

/*********************************************************************************************************************************/


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include"../include/MCAL/RCC/RCC_INT.h"
#include"../include/MCAL/RCC/RCC_PRIV.h"
#include"../include/HAL/LCD/LCD_INT.h"
#include"../include/HAL/LCD/LCD_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_INT.h"

/*********************************************************************************************************************************/

extern void LCD_voidSend_Command (u8 copy_u8Command)
{
	/***********************************/
	/*      Set PORT A & D output      */
	/***********************************/
//	DIO_voidSetPortDirection (LCD_Data_PORT,DIO_OUTPUT);
//	DIO_voidSetPortDirection (LCD_CNT_PORT,DIO_OUTPUT);

	GPIO_ErrorStatusSetPinValue(LCD_u8RS,Low);
	GPIO_ErrorStatusSetPinValue(LCD_u8RW,Low);

	GPIO_ErrorStatusSetPortDiffValues(PIN3,PIN10,LCD_Data_PORT,copy_u8Command);

	GPIO_ErrorStatusSetPinValue(LCD_u8EN,High);
	SYSTICK_voidSetBusyWait(2000);
	GPIO_ErrorStatusSetPinValue(LCD_u8EN,Low);
}


extern void LCD_voidIntialization (void)
{
	/* Wait more than 30 ms */
	//_delay_ms(35);

	/***********************************/
	/* Set PORT A for LCD pins output  */
	/***********************************/

GPIO_ErrorStatusSetPortMode(PIN0,PIN10,LCD_Data_PORT,Output2_PushPull);

	/***********************************/
	/*           Function Set          */
	/***********************************/
	LCD_voidSend_Command(0b00111100);//0->1

	/* Wait more than 30 us */
	_delay_ms(1);

	/***********************************/
	/*     Display off/on control      */
	/***********************************/
	LCD_voidSend_Command(0b00001111);

	/* Wait more than 39 us */
	_delay_ms(1);

	/***********************************/
	/*         Display Clear           */
	/***********************************/
	LCD_voidSend_Command(0b00000001);

	/* Wait more than 1.39 us */
	_delay_ms(1);

	/***********************************/
	/*         Display Clear           */
	/***********************************/

	//LCD_voidSend_Command(0x06);
	/* Wait more than 1.39 ms */
	//_delay_ms(20);


}

extern void LCD_voidSend_Data (u8 copy_u8data)
{

	GPIO_ErrorStatusSetPinValue(LCD_u8RW,Low);
	GPIO_ErrorStatusSetPinValue(LCD_u8RS,High);

	GPIO_ErrorStatusSetPortDiffValues(PIN3,PIN10,LCD_Data_PORT,copy_u8data);

	GPIO_ErrorStatusSetPinValue(LCD_u8EN,High);
	SYSTICK_voidSetBusyWait(2000);
	GPIO_ErrorStatusSetPinValue(LCD_u8EN,Low);
}

void LCD_voidSend_String (char *copy_ptrString)
{
	while ( *copy_ptrString > 0 )
	{
		LCD_voidSend_Data (*copy_ptrString++);
	}
}


extern void LCD_voidSend_4bitCommand (u8 copy_u8Command)
{

		GPIO_ErrorStatusSetPinValue(LCD_u8RW,Low);
		GPIO_ErrorStatusSetPinValue(LCD_u8RS,Low);

		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_0,GET_BIT(copy_u8Command,4));
		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_1,GET_BIT(copy_u8Command,5));
		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_2,GET_BIT(copy_u8Command,6));
		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_3,GET_BIT(copy_u8Command,7));


		GPIO_ErrorStatusSetPinValue(LCD_u8EN,High);
		SYSTICK_voidSetBusyWait(2000);
		GPIO_ErrorStatusSetPinValue(LCD_u8EN,Low);
		/*///////////////////////////////////////////////////////////////////////////////////*/
		SYSTICK_voidSetBusyWait(200000);
		GPIO_ErrorStatusSetPinValue(LCD_u8RW,Low);
		GPIO_ErrorStatusSetPinValue(LCD_u8RS,Low);

		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_0,GET_BIT(copy_u8Command,0));
		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_1,GET_BIT(copy_u8Command,1));
		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_2,GET_BIT(copy_u8Command,2));
		GPIO_ErrorStatusSetPinValue(LCD_u8DATA_3,GET_BIT(copy_u8Command,3));


		GPIO_ErrorStatusSetPinValue(LCD_u8EN,High);
		SYSTICK_voidSetBusyWait(2000);
		GPIO_ErrorStatusSetPinValue(LCD_u8EN,Low);
}

extern void LCD_4bitIntialization (void)
{
	GPIO_ErrorStatusSetPortMode(PIN0,PIN6,LCD_Data_PORT,Output2_PushPull);

	SYSTICK_voidSetBusyWait(20000);

		LCD_voidSend_4bitCommand(0x33);
		LCD_voidSend_4bitCommand(0x32);	/* Send for 4 bit initialization of LCD  */
		LCD_voidSend_4bitCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
		LCD_voidSend_4bitCommand(0x0c);	/* Display on cursor off */
		LCD_voidSend_4bitCommand(0x06);	/* Increment cursor (shift cursor to right) */
		LCD_voidSend_4bitCommand(0x01);	/* Clear display screen */
}


extern void LCD_voidSend_4bitData (u8 copy_u8data)
{
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_0,GET_BIT(copy_u8data,4));
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_1,GET_BIT(copy_u8data,5));
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_2,GET_BIT(copy_u8data,6));
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_3,GET_BIT(copy_u8data,7));
	GPIO_ErrorStatusSetPinValue(LCD_u8RS,High);
	GPIO_ErrorStatusSetPinValue(LCD_u8EN,High);
	SYSTICK_voidSetBusyWait(2000);
	GPIO_ErrorStatusSetPinValue(LCD_u8EN,Low);
	SYSTICK_voidSetBusyWait(200000);
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_0,GET_BIT(copy_u8data,0));
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_1,GET_BIT(copy_u8data,1));
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_2,GET_BIT(copy_u8data,2));
	GPIO_ErrorStatusSetPinValue(LCD_u8DATA_3,GET_BIT(copy_u8data,3));
	//DIO_voidSetPinValue(LCD_CNT_PORT,LCD_u8RS,DIO_HIGH);
	GPIO_ErrorStatusSetPinValue(LCD_u8EN,High);
	SYSTICK_voidSetBusyWait(2000);
	GPIO_ErrorStatusSetPinValue(LCD_u8EN,Low);
}


void LCD_voidSend_4bitString (char *copy_ptrString)
{
	while ( *copy_ptrString > 0 )
	{
		LCD_voidSend_4bitData (*copy_ptrString++);
	}
}

extern void LCD_void4bitDisplayNumber(u32 x)
{
	u32 y = 1;
	if (x == 0)
	{
		LCD_voidSend_4bitData('0');
	}
	if (x < 0) {
		LCD_voidSend_4bitData('-');
		x *= -1;
	}
	while (x != 0) {
		y = ((y * 10) + (x % 10));
		x = (x / 10);
	}
	while (y != 1) {
		LCD_voidSend_4bitData((y % 10) + 48);
		y = (y / 10);
	}
}


void LCD_voidGoToPos(u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	LCD_voidSend_Command(0b10000000);
		if(Copy_u8RowNum==1)
		{
			if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
			{LCD_voidSend_Command(127+Copy_u8ColNum);}
		}
		else if (Copy_u8RowNum==2)
		{
			if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
			{LCD_voidSend_Command(191+Copy_u8ColNum);}
		}
}
void LCD_void4bitGoToPos(u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	LCD_voidSend_4bitCommand(0b10000000);
			if(Copy_u8RowNum==1)
			{
				if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
				{LCD_voidSend_4bitCommand(127+Copy_u8ColNum);}
			}
			else if (Copy_u8RowNum==2)
			{
				if (Copy_u8ColNum>0 && Copy_u8ColNum <=16)
				{LCD_voidSend_4bitCommand(191+Copy_u8ColNum);}
			}
}
