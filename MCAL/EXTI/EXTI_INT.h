/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 30 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXTI_INT_H
#define __EXTI_INT_H

/******************************************************************************/
/*Function: EXTI_voidInit				                         			  */
/*I/P Parameters: void			            								  */
/*Returns:it returns void		                            				  */
/*Desc:This Function initialize the EXTI depending on the pre-configuration   */
/******************************************************************************/
void EXTI_voidInit(void);
/******************************************************************************/
/*Function: EXTI_voidSetSignalLatch		                         			  */
/*I/P Parameters: u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode				  */
/*Returns:it returns void		                            				  */
/*Desc:This Function initialize the EXTI depending on the inputs 			  */
/******************************************************************************/
void EXTI_voidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode);
/******************************************************************************/
/*Function: EXTI_voidEnableEXTI		                         				  */
/*I/P Parameters: u8 copy_u8EXTILine, 										  */
/*Returns:it returns void		                            				  */
/*Desc:This Function Enables the EXTI Line						 			  */
/******************************************************************************/
void EXTI_voidEnableEXTI (u8 copy_u8EXTILine);
/******************************************************************************/
/*Function: EXTI_voidDisableEXTI	                         				  */
/*I/P Parameters: u8 copy_u8EXTILine, 										  */
/*Returns:it returns void		                            				  */
/*Desc:This Function Disables the EXTI Line						 			  */
/******************************************************************************/
void EXTI_voidDisableEXTI (u8 copy_u8EXTILine);

void EXTI_voidSoftwareTrigger (u8 copy_u8EXTILine);

void EXTI_voidSetCallBack (void (*ptr) (void), u8 copy_u8INTSource);

#endif /* __EXTI_INT_H */
