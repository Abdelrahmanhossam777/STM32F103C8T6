/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : RGB DRIVER                       */
/*   DATE        : 4 SEP 2020                       */
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
/* 				  KEYPAD Directives 				*/
/****************************************************/
#include"../include/HAL/RGBLed/RGB_INT.h"
#include"../include/HAL/RGBLed/RGB_CONF.h"

void RGB_voidInit(void)
{
	GPIO_ErrorStatusSetPinMode(RGB_Red,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(RGB_Green,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(RGB_Blue,Output2_PushPull);
}

void RGB_VoidON(u8 copy_u8Color)
{
	switch (copy_u8Color) {
		case RED:
					GPIO_ErrorStatusSetPinValue(RGB_Blue,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Green,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Red,High);
					break;
		case BLUE:
					GPIO_ErrorStatusSetPinValue(RGB_Red,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Green,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Blue,High);
					break;
		case GREEN:
					GPIO_ErrorStatusSetPinValue(RGB_Red,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Blue,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Green,High);
					break;
		default:
			break;
	}
}

void RGB_VoidONRED(void)
{

					GPIO_ErrorStatusSetPinValue(RGB_Blue,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Green,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Red,High);
}
void RGB_VoidONBlue(void)
{

					GPIO_ErrorStatusSetPinValue(RGB_Blue,High);
					GPIO_ErrorStatusSetPinValue(RGB_Green,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Red,Low);
}
void RGB_VoidONGreen(void)
{

					GPIO_ErrorStatusSetPinValue(RGB_Blue,Low);
					GPIO_ErrorStatusSetPinValue(RGB_Green,High);
					GPIO_ErrorStatusSetPinValue(RGB_Red,Low);
}
void RGB_VoidOFF(void)
{

	GPIO_ErrorStatusSetPinValue(RGB_Blue,Low);
	GPIO_ErrorStatusSetPinValue(RGB_Green,Low);
	GPIO_ErrorStatusSetPinValue(RGB_Red,Low);

}
