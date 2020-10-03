/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : IR DRIVER                        */
/*   DATE        : 4 SEP 2020                       */
/*   VERSION     : V01                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_IR_INT_H_
#define HAL_IR_INT_H_

/******************************************************************************/
/*Function: IR_voidInit			                         					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the pin to input floating 		     		          */
/******************************************************************************/
void IR_voidInit(void);

/******************************************************************************/
/*Function: IR_voidGetFrame		                         					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function is the EXTI callback to get the frame			          */
/******************************************************************************/
void IR_voidGetFrame(void);

/******************************************************************************/
/*Function: IR_voidTakeAction	                         					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function reads the frame and take action depending on it	      */
/******************************************************************************/
void IR_voidTakeAction(void);

/*****************************************************************************/
/*Function: IR_VoidRespond 	                         					     */
/*I/P Parameters: copy_u8Button											     */
/*Returns:it returns Void	                                				 */
/*Desc:This Function to respond to the button press				             */
/*****************************************************************************/
void IR_VoidRespond (u8 copy_u8Button);

#endif
