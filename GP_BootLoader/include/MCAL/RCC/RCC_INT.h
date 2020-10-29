/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : RCC DRIVER                       */
/*   DATE        : 15 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_RCC_INT_H
#define _MCAL_RCC_INT_H
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/LIB.h"


/******************************************************************************/
/*Function: RCC_vidSetClkSource                          					  */
/*I/P Parameters: copy_u32Source            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Set the Clock source for my micro-controller	          */
/******************************************************************************/
ErrorStatus RCC_vidSetClkSource (u32 copy_u32Source);

/******************************************************************************/
/*Function: RCC_vidSetPeripheralclock                     					  */
/*I/P Parameters: copy_u8Bus , copy_u32peripheral , copy_u8State  			  */
/*Returns:it returns Error Status                              				  */
/*Desc:This Function to enable or disable the clock for a peripheral 	      */
/******************************************************************************/
ErrorStatus RCC_vidSetPeripheralclock (u8 copy_u8Bus, u32 copy_u32peripheral, u8 copy_u8State);

/******************************************************************************/
/*Function: RCC_vidSetClkStatus                     						  */
/*I/P Parameters: copy_u32Source , copy_u8State  							  */
/*Returns:it returns Error Status                              				  */
/*Desc:This Function to enable or disable the clock Source	        	      */
/******************************************************************************/
ErrorStatus RCC_vidSetClkStatus (u32 copy_u32Source, u8 copy_u8State);

/******************************************************************************/
/*Function: RCC_vidClkInit		                     						  */
/*I/P Parameters: nothing						 							  */
/*Returns:it returns Error Status                             				  */
/*Desc:This Function to enable The Clock due to pre-configurations	   	      */
/******************************************************************************/
ErrorStatus RCC_vidClkInit(void);

#endif /* __RCC_INT_H */
