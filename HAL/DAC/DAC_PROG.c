/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DAC DRIVER                       */
/*   DATE        : 4 SEP 2020                       */
/*   VERSION     : V01                              */
/****************************************************/


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_INT.h"
#include "../include/HAL/DAC/DAC_INT.h"
#include "../include/HAL/DAC/DAC_CONF.h"
#include"../include/SONG/amar.h"

/******************************************************************************/
/*Function: DAC_voidInit			                       					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the pin to Output Pushpull		     		          */
/******************************************************************************/
void DAC_voidInit ()
{
	GPIO_ErrorStatusSetPinMode(DAC_BIT0,Output2_PushPull );
	GPIO_ErrorStatusSetPinMode(DAC_BIT1,Output2_PushPull );
	GPIO_ErrorStatusSetPinMode(DAC_BIT2,Output2_PushPull );
	GPIO_ErrorStatusSetPinMode(DAC_BIT3,Output2_PushPull );
	GPIO_ErrorStatusSetPinMode(DAC_BIT4,Output2_PushPull );
	GPIO_ErrorStatusSetPinMode(DAC_BIT5,Output2_PushPull );
	GPIO_ErrorStatusSetPinMode(DAC_BIT6,Output2_PushPull );
	GPIO_ErrorStatusSetPinMode(DAC_BIT7,Output2_PushPull );
}

volatile u16 DACCounter= 0;

/******************************************************************************/
/*Function: DAC_voidOutput			                       					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the pin to Values of the signal     		          */
/******************************************************************************/
void DAC_voidOutput()
{
	GPIO_ErrorStatusSetPinValue(DAC_BIT0,GET_BIT(amaren_raw[DACCounter],0));
	GPIO_ErrorStatusSetPinValue(DAC_BIT1,GET_BIT(amaren_raw[DACCounter],1));
	GPIO_ErrorStatusSetPinValue(DAC_BIT2,GET_BIT(amaren_raw[DACCounter],2));
	GPIO_ErrorStatusSetPinValue(DAC_BIT3,GET_BIT(amaren_raw[DACCounter],3));
	GPIO_ErrorStatusSetPinValue(DAC_BIT4,GET_BIT(amaren_raw[DACCounter],4));
	GPIO_ErrorStatusSetPinValue(DAC_BIT5,GET_BIT(amaren_raw[DACCounter],5));
	GPIO_ErrorStatusSetPinValue(DAC_BIT6,GET_BIT(amaren_raw[DACCounter],6));
	GPIO_ErrorStatusSetPinValue(DAC_BIT7,GET_BIT(amaren_raw[DACCounter],7));
	//GPIOA->GPIO_ODR=amaren_raw[DACCounter];
	DACCounter++;
	if (DACCounter==37152)
	{DACCounter=0;}
}
