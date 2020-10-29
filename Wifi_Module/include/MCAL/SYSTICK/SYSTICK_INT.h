/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SYSTICK DRIVER                   */
/*   DATE        : 27 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTICK_INT_H
#define __SYSTICK_INT_H



/******************************************************************************/
/*Function: SYSTICk_ErrorStatusConfig                          				  */
/*I/P Parameters: no thing		            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function control SYSTICK Timer depend on pre-configurations	      */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusConfig ();

/******************************************************************************/
/*Function: SYSTICk_ErrorStatusEnable                     					  */
/*I/P Parameters: void			            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function enables the SYSTICK Timer						          */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusEnable ();


/******************************************************************************/
/*Function: SYSTICk_ErrorStatusDisable                     					  */
/*I/P Parameters: void			            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function disables the SYSTICK Timer						          */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusDisable ();

/******************************************************************************/
/*Function: SYSTICk_ErrorStatusPreLoad                          			  */
/*I/P Parameters: copy_u32PreloadValue		            					  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function control SYSTICK Timer Preload						      */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusPreLoad (u32 copy_u32PreloadValue);

/******************************************************************************/
/*Function: delay_ms					                          			  */
/*I/P Parameters: copy_u32Time				            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:This Function makes a delay for number of m sec up to 16 sec		      */
/******************************************************************************/
void delay_ms (u32 copy_u32Time);

/******************************************************************************/
/*Function: SYSTICK_voidSetBusyWait		                          			  */
/*I/P Parameters: copy_u32Ticks				            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes a delay for number of ticks(This holds the processor)		      */
/******************************************************************************/
void SYSTICK_voidSetBusyWait (u32 copy_u32Ticks);

/******************************************************************************/
/*Function: SYSTICK_voidStopInterval		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes This function stops the periodic events of the SYSTICK timer     */
/******************************************************************************/
void SYSTICK_voidStopInterval(void);

/******************************************************************************/
/*Function: SYSTICK_voidSetIntervalPeriodic	                       			  */
/*I/P Parameters: copy_u32Ticks				            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes Async function fires an interrupt after specific time 		      */
/******************************************************************************/
void SYSTICK_voidSetIntervalPeriodic  ( u32 copy_u32Ticks, void (*Copy_ptr)(void) );

/******************************************************************************/
/*Function: SYSTICK_voidStopInterval		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes This function stops the periodic events of the SYSTICK timer     */
/******************************************************************************/
//void SYSTICK_voidStopInterval(void);


#endif /* __SYSTICK_INT_H */
