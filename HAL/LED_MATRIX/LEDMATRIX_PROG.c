/*********************************************************************/
/*   AUTHOR      : Abdelrahman Hossam               			     */
/*   Description : Led Matrix DRIVER                				 */
/*   DATE        : 14 SEP 2020 					                     */
/*   VERSION     : V01 											     */
/*                 V02 Serial to Parallel communication function     */
/*********************************************************************/


/****************************************/
/* 			     Directives 			*/
/****************************************/

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/RCC/RCC_INT.h"
#include "../include/MCAL/RCC/RCC_PRIV.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include "../include/HAL/LED_MATRIX/LEDMATRIX_INT.h"
#include "../include/HAL/LED_MATRIX/LEDMATRIX_PRIV.h"
#include "../include/HAL/LED_MATRIX/LEDMATRIX_CONF.h"
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



/******************************************************************************/
/*Function: LEDMAT_voidInit		                          					  */
/*I/P Parameters: Void                		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the Led Matrix pins to output push-pull	          */
/******************************************************************************/
void LEDMAT_voidInit(void)
{
	/* Set all the rows to output push pull 2 mega hertz */
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_0,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_1,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_2,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_3,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_4,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_5,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_6,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_ROW_7,Output2_PushPull);

	/* Set all the Columns to output push pull 2 mega hertz */
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_0,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_1,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_2,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_3,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_4,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_5,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_6,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(LEDMAT_COL_7,Output2_PushPull);
}

/******************************************************************************/
/*Function: LEDMAT_voidDisplayFrame                        					  */
/*I/P Parameters: Pointer to array     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Display a frame on the led matrix				          */
/******************************************************************************/
void LEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	/* Column 0 and Row 0 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[0]);
	LEDMAT_voidEnableCol(LEDMAT_COL_0);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 1 and Row 1 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[1]);
	LEDMAT_voidEnableCol(LEDMAT_COL_1);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 2 and Row 2 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[2]);
	LEDMAT_voidEnableCol(LEDMAT_COL_2);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 3 and Row 3 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[3]);
	LEDMAT_voidEnableCol(LEDMAT_COL_3);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 4 and Row 4 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[4]);
	LEDMAT_voidEnableCol(LEDMAT_COL_4);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 5 and Row 5 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[5]);
	LEDMAT_voidEnableCol(LEDMAT_COL_5);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 6 and Row 6 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[6]);
	LEDMAT_voidEnableCol(LEDMAT_COL_6);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 7 and Row 7 Configuration */
	LEDMAT_voidDisableAllCol();
	LEDMAT_voidRowCall(Copy_u8Frame[7]);
	LEDMAT_voidEnableCol(LEDMAT_COL_7);
	SYSTICK_voidSetBusyWait(2000);


}

/******************************************************************************/
/*Function: LEDMAT_voidRowCall	                        					  */
/*I/P Parameters: Pointer to array     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Display a frame on Rows	     				          */
/******************************************************************************/
void LEDMAT_voidRowCall(u8 copy_u8Data)
{
	/* View data on each row depending on corresponding bit from the given data */
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_0,GET_BIT(copy_u8Data,0));
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_1,GET_BIT(copy_u8Data,1));
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_2,GET_BIT(copy_u8Data,2));
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_3,GET_BIT(copy_u8Data,3));
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_4,GET_BIT(copy_u8Data,4));
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_5,GET_BIT(copy_u8Data,5));
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_6,GET_BIT(copy_u8Data,6));
	GPIO_ErrorStatusSetPinValue(LEDMAT_ROW_7,GET_BIT(copy_u8Data,7));
//	GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,GPIO_PORTA,copy_u8Data);

}

/******************************************************************************/
/*Function: LEDMAT_voidDisableAllCol                       					  */
/*I/P Parameters: Void			     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Disable all the columns	     				          */
/******************************************************************************/
void LEDMAT_voidDisableAllCol(void)
{
	    /* Set all columns to high to disable them */
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_0,High);
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_1,High);
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_2,High);
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_3,High);
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_4,High);
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_5,High);
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_6,High);
		GPIO_ErrorStatusSetPinValue(LEDMAT_COL_7,High);

}

/******************************************************************************/
/*Function: LEDMAT_voidEnableCol                         					  */
/*I/P Parameters: u8 copy_u8PinNum, u8 copy_u8PortNum						  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Enable one the columns	     		     		          */
/******************************************************************************/
void LEDMAT_voidEnableCol (u8 copy_u8PinNum, u8 copy_u8PortNum)
{
	    /* Enable a column by sitting low to one */
		GPIO_ErrorStatusSetPinValue(copy_u8PinNum, copy_u8PortNum,Low);
}


/******************************************************************************/
/*Function: LEDMAT_voidDisplayFrameSTP                     					  */
/*I/P Parameters: Pointer to array     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Display a frame on the led matrix						  */
/* using serial to parallel communication							          */
/******************************************************************************/
void LEDMAT_voidDisplayFrameSTP(u8 *Copy_u8Frame)
{
	/* Column 0 and Row 0 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[0]);
	STP_voidSendSynchronus(((0b11111110)<<8)|Copy_u8Frame[0]);
	SYSTICK_voidSetBusyWait(2000);

	/* Column 1 and Row 1 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[1]);
	STP_voidSendSynchronus(((0b11111101)<<8)|Copy_u8Frame[1]);
	SYSTICK_voidSetBusyWait(2000);

	/* Column 2 and Row 2 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[2]);
	STP_voidSendSynchronus(((0b11111011)<<8)|Copy_u8Frame[2]);
	SYSTICK_voidSetBusyWait(2000);

	/* Column 3 and Row 3 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[3]);
	STP_voidSendSynchronus(((0b11110111)<<8)|Copy_u8Frame[3]);
	SYSTICK_voidSetBusyWait(2000);

	/* Column 4 and Row 4 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[4]);
	STP_voidSendSynchronus(((0b11101111)<<8)|Copy_u8Frame[4]);
	SYSTICK_voidSetBusyWait(2000);

	/* Column 5 and Row 5 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[5]);
	STP_voidSendSynchronus(((0b11011111)<<8)|Copy_u8Frame[5]);
	SYSTICK_voidSetBusyWait(2000);
	/* Column 6 and Row 6 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[6]);
	STP_voidSendSynchronus(((0b10111111)<<8)|Copy_u8Frame[6]);
	SYSTICK_voidSetBusyWait(2000);

	/* Column 7 and Row 7 Configuration */
	STP_voidSendSynchronus(((0xFF)<<8)|Copy_u8Frame[7]);
	STP_voidSendSynchronus(((0b01111111)<<8)|Copy_u8Frame[7]);
	SYSTICK_voidSetBusyWait(2000);


}
/*
for(u8 i=0; i<34;i++)
		  {
			  for (u32 x=0 ; x<15;x++)
			  LEDMAT_voidDisplayFrame(data+i);
		  }
u8 data[41]={0,0,0,0,0,0,0, 254, 146, 146, 146, 108, 0, 0, 254, 146, 146, 146, 0, 0, 254, 130, 130, 130, 124, 0, 0, 124, 130, 130, 130, 124, 0,0,0,0,0,0,0,0,0,0,0};
*/
