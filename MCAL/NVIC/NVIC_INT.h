/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : NVIC DRIVER                      */
/*   DATE        : 19 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_NVIC_INT_H_
#define MCAL_NVIC_INT_H_

/******************************************************************************/
/*Function: NVIC_ErrorStatusEnable                          				  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Enables the interrupt depending in its ID	    	      */
/******************************************************************************/
ErrorStatus NVIC_ErrorStatusEnable(u8 copy_u8IntID);

/******************************************************************************/
/*Function: NVIC_ErrorStatusDisable                          				  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Disables the interrupt depending in its ID	    	      */
/******************************************************************************/
ErrorStatus NVIC_ErrorStatusDisable(u8 copy_u8IntID);

/******************************************************************************/
/*Function: NVIC_ErrorStatusSetPending                          			  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function set the pending flag of the interrupt depending in its ID*/
/******************************************************************************/
ErrorStatus NVIC_ErrorStatusSetPending(u8 copy_u8IntID);

/******************************************************************************/
/*Function: NVIC_ErrorStatusGetStatus                          				  */
/*I/P Parameters: Interrupt ID	            								  */
/*Returns:it returns u8			                            				  */
/*Desc:This Function To Read the INT status									  */
/******************************************************************************/
/*	0: Interrupt not active      1: Interrupt active						  */
/******************************************************************************/
u8 NVIC_ErrorStatusGetStatus(u8 copy_u8IntID);

/******************************************************************************/
/*Function: NVIC_ErrorSetPriorityOption                        				  */
/*I/P Parameters: void			            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function Enables the interrupt priority depending on configuration*/
/******************************************************************************/
ErrorStatus NVIC_ErrorSetPriorityOption(void);


/******************************************************************************/
/*Function: NVIC_ErrorSetPriorityEnable                        				  */
/*I/P Parameters: u8 copy_u8GroupPriority,u8 copy_u8SubPriority, 			  */
/* 				  u8 copy_u8InterryptNumber									  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function sets the interrupt priority							  */
/******************************************************************************/
ErrorStatus NVIC_ErrorSetPriorityEnable(u8 copy_u8GroupPriority,u8 copy_u8SubPriority, u8 copy_u8InterryptNumber);

/* End of the file guard */
#endif /* MCAL_NVIC_INT_H_ */
