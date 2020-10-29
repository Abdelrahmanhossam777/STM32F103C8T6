/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : NVIC DRIVER                      */
/*   DATE        : 22 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/****************************************/
/* 			     Directives 			*/
/****************************************/
#include "../include/LIB/LIB.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include"../include/MCAL/NVIC/NVIC_INT.h"
#include"../include/MCAL/NVIC/NVIC_PRIV.h"

/******************************************************************************/
/*Function: NVIC_ErrorStatusEnable                          				  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Enables the interrupt depending in its ID	    	      */
/******************************************************************************/
ErrorStatus NVIC_ErrorStatusEnable(u8 copy_u8IntID)
{
	 ErrorStatus LocalErrorStatus= NotOk ;
	 /* Input Validation */
	 if (copy_u8IntID < 0 || copy_u8IntID > 59)
	 {
		 return LocalErrorStatus;
	 }
	 /* Calculation of the Register number based on INT */
	 u8 Local_u8RegisterNum=copy_u8IntID / 32;
	 /* Calculation of the BIT number based on INT */
	 u8 Local_u8BitNum=copy_u8IntID % 32;
	 /* Atomic Access to the set enable register to enable the required INT */
	 NVIC_ISER[Local_u8RegisterNum] = 1 << Local_u8BitNum;
	 /* Update the Error Status */
	 LocalErrorStatus=OK;
	 /* Return the control to the caller function */
	 return LocalErrorStatus;
}


/******************************************************************************/
/*Function: NVIC_ErrorStatusDisable                          				  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Disables the interrupt depending in its ID	    	      */
/******************************************************************************/
ErrorStatus NVIC_ErrorStatusDisable(u8 copy_u8IntID)
{
	 ErrorStatus LocalErrorStatus= NotOk ;
	 /* Input Validation */
	 if (copy_u8IntID < 0 || copy_u8IntID > 59)
	 {
		 return LocalErrorStatus;
	 }
	 /* Calculation of the Register number based on INT */
	 u8 Local_u8RegisterNum=copy_u8IntID / 32;
	 /* Calculation of the BIT number based on INT */
	 u8 Local_u8BitNum=copy_u8IntID % 32;
	 /* Atomic Access to the set disable register to enable the required INT */
	 NVIC_ICER[Local_u8RegisterNum] = 1 << Local_u8BitNum;
	 /* Update the Error Status */
	 LocalErrorStatus=OK;
	 /* Return the control to the caller function */
	 return LocalErrorStatus;
}

/******************************************************************************/
/*Function: NVIC_ErrorStatusSetPending                          			  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function set the pending flag of the interrupt depending in its ID*/
/******************************************************************************/
ErrorStatus NVIC_ErrorStatusSetPending(u8 copy_u8IntID)
{
	 ErrorStatus LocalErrorStatus= NotOk ;
	 /* Input Validation */
	 if (copy_u8IntID < 0 || copy_u8IntID > 59)
	 {
		 return LocalErrorStatus;
	 }
	 /* Calculation of the Register number based on INT */
	 u8 Local_u8RegisterNum=copy_u8IntID / 32;
	 /* Calculation of the BIT number based on INT */
	 u8 Local_u8BitNum=copy_u8IntID % 32;
	 /* Atomic Access to set pending of the required INT */
	 NVIC_ISPR[Local_u8RegisterNum] = 1 << Local_u8BitNum;
	 /* Update the Error Status */
	 LocalErrorStatus=OK;
	 /* Return the control to the caller function */
	 return LocalErrorStatus;
}

/******************************************************************************/
/*Function: NVIC_ErrorStatusClrPending                          			  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Clr the pending flag of the interrupt depending in its ID*/
/******************************************************************************/
ErrorStatus NVIC_ErrorStatusClrPending(u8 copy_u8IntID)
{
	 ErrorStatus LocalErrorStatus= NotOk ;
	 /* Input Validation */
	 if (copy_u8IntID < 0 || copy_u8IntID > 59)
	 {
		 return LocalErrorStatus;
	 }
	 /* Calculation of the Register number based on INT */
	 u8 Local_u8RegisterNum=copy_u8IntID / 32;
	 /* Calculation of the BIT number based on INT */
	 u8 Local_u8BitNum=copy_u8IntID % 32;
	 /* Atomic Access to Clear pending of the required INT */
	 NVIC_ICPR[Local_u8RegisterNum] = 1 << Local_u8BitNum;
	 /* Update the Error Status */
	 LocalErrorStatus=OK;
	 /* Return the control to the caller function */
	 return LocalErrorStatus;
}

/******************************************************************************/
/*Function: NVIC_ErrorStatusGetStatus                          				  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns u8			                            				  */
/*Desc:This Function To Read the INT status									  */
/******************************************************************************/
/*	0: Interrupt not active      1: Interrupt active						  */
/******************************************************************************/
u8 NVIC_ErrorStatusGetStatus(u8 copy_u8IntID)
{
	 u8 Local_u8IntStatus;
	 /* Calculation of the Register number based on INT */
	 u8 Local_u8RegisterNum=copy_u8IntID / 32;
	 /* Calculation of the BIT number based on INT */
	 u8 Local_u8BitNum=copy_u8IntID % 32;
	 /* Reading the status of the Interrupt */
	 Local_u8IntStatus = GET_BIT(NVIC_IABR[Local_u8RegisterNum],Local_u8BitNum);
	 /* Return the control to the caller function */
	 return Local_u8IntStatus;
}

/******************************************************************************/
/*Function: NVIC_ErrorSetPriorityOption                        				  */
/*I/P Parameters: void			            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Enables the interrupt priority depending on configuration*/
/******************************************************************************/
ErrorStatus NVIC_ErrorSetPriorityOption(void)
{
	 ErrorStatus LocalErrorStatus= NotOk ;
	 /* Updating the Application interrupt and reset control register (SCB_AIRCR) with the value in Pre-Configuration */
	 SCB_AIRCR = PriorityOption;
	 /* Updating the Error Status  */
	 LocalErrorStatus= OK;
	 /* Return the control to the caller function */
	 return LocalErrorStatus;
}


/******************************************************************************/
/*Function: NVIC_ErrorSetPriorityEnable                        				  */
/*I/P Parameters: u8 copy_u8GroupPriority,u8 copy_u8SubPriority, 			  */
/* 				  u8 copy_u8InterryptNumber									  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function sets the interrupt priority							  */
/******************************************************************************/
/* Note that as we pre-configured the group has 2 bits i/p must be from 0 to 3*/
/* and the sub has also 2 bits i/p must be from 0 to 3 */
ErrorStatus NVIC_ErrorSetPriorityEnable(u8 copy_u8GroupPriority,u8 copy_u8SubPriority, u8 copy_u8InterryptNumber)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/* Setting the priority of the Interrupt */
	NVIC_IPR[copy_u8InterryptNumber]=(((copy_u8GroupPriority<<2)|copy_u8SubPriority)<<4);
	/* Updating the Error Status  */
	LocalErrorStatus= OK;
	/* Return the control to the caller function */
	return LocalErrorStatus;
}
