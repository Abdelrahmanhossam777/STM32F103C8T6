/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 30 AGU 2020                      */
/*   VERSION     : V01                              */


/****************************************/
/* 			     Directives 			*/
/****************************************/

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include"../include/MCAL/EXTI/EXTI_INT.h"
#include"../include/MCAL/EXTI/EXTI_PRIV.h"
#include"../include/MCAL/EXTI/EXTI_CONF.h"
#include"../include/MCAL/NVIC/NVIC_PRIV.h"


/******************************************************************************/
/*Function: EXTI_voidInit				                         			  */
/*I/P Parameters: void			            								  */
/*Returns:it returns void		                            				  */
/*Desc:This Function initialize the EXTI depending on the pre-configuration   */
/******************************************************************************/
void EXTI_voidInit(void)
{
    #if   EXTI_LINE == EXTI_LINE0
	SET_BIT(EXTI->EXTI_IMR,EXTI_LINE0);
    #elif EXTI_LINE == EXTI_LINE1
	SET_BIT(EXTI->EXTI_IMR,EXTI_LINE1);
	#elif EXTI_LINE == EXTI_LINE2
	SET_BIT(EXTI->EXTI_IMR,EXTI_LINE2);
    #endif

	#if   EXTI_SenseMode  == FALLING_EDGE
		  SET_BIT(EXTI->EXTI_FTSR,EXTI_LINE);
	#elif EXTI_SenseMode  == RISING_EDGE
		  SET_BIT(EXTI->EXTI_RTSR,EXTI_LINE);
	#elif EXTI_SenseMode  == ON_CHANGE
		  SET_BIT(EXTI->EXTI_FTSR,EXTI_LINE);
		  SET_BIT(EXTI->EXTI_RTSR,EXTI_LINE);
    #endif

}

/******************************************************************************/
/*Function: EXTI_voidSetSignalLatch		                         			  */
/*I/P Parameters: u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode				  */
/*Returns:it returns void		                            				  */
/*Desc:This Function initialize the EXTI depending on the inputs 			  */
/******************************************************************************/
void EXTI_voidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode)
{
	/* Set the corresponding bit of the Interrupt mask register */
	SET_BIT(EXTI->EXTI_IMR,copy_u8EXTILine);
	/* Switching on the sense mode */
	switch (copy_u8EXTISenseMode)
	{
	  case  FALLING_EDGE:
		  	  	  	  	  /* Configuration of the falling edge sense mode */
		  	  	  	  	  SET_BIT(EXTI->EXTI_FTSR,copy_u8EXTILine);
		  	  	  	  	  break;
	  case  RISING_EDGE:
		  	  	  	  	  /* Configuration of the Rising edge sense mode */
		  	  	  	  	  SET_BIT(EXTI->EXTI_RTSR,copy_u8EXTILine);
	  		  	  	  	  break;
	  case  ON_CHANGE:
		  	  	  	  	  /* Configuration of the falling edge sense mode */
		  	  	  	  	  SET_BIT(EXTI->EXTI_FTSR,copy_u8EXTILine);
		  	  	  	  	  /* Configuration of the Rising edge sense mode */
		  	  	  	  	  SET_BIT(EXTI->EXTI_RTSR,copy_u8EXTILine);
	  		  	  	  	  break;

	}
}

/******************************************************************************/
/*Function: EXTI_voidEnableEXTI		                         				  */
/*I/P Parameters: u8 copy_u8EXTILine, 										  */
/*Returns:it returns void		                            				  */
/*Desc:This Function Enables the EXTI Line						 			  */
/******************************************************************************/
void EXTI_voidEnableEXTI (u8 copy_u8EXTILine)
{
	/* Set the corresponding bit of the Interrupt mask register */
	SET_BIT(EXTI->EXTI_IMR,copy_u8EXTILine);
}

/******************************************************************************/
/*Function: EXTI_voidDisableEXTI	                         				  */
/*I/P Parameters: u8 copy_u8EXTILine, 										  */
/*Returns:it returns void		                            				  */
/*Desc:This Function Disables the EXTI Line						 			  */
/******************************************************************************/
void EXTI_voidDisableEXTI (u8 copy_u8EXTILine)
{
	/* Clear the corresponding bit of the Interrupt mask register */
	CLR_BIT(EXTI->EXTI_IMR,copy_u8EXTILine);
}


void EXTI_voidSoftwareTrigger (u8 copy_u8EXTILine)
{
	/* Set the corresponding bit of the Interrupt mask register */
	SET_BIT(EXTI->EXTI_IMR,copy_u8EXTILine);
	/* Clear the corresponding bit of the Pending register register */
	CLR_BIT(EXTI->EXTI_PR,copy_u8EXTILine);

}

void EXTI_voidSetCallBack (void (*ptr) (void), u8 copy_u8INTSource)
{
	ptr_CallBack[copy_u8INTSource]=ptr;
}

EXTI0_IRQHandler(void)
{
	ptr_CallBack [EXTI0_CallBack] ();
	CLR_Pending(0);
}

