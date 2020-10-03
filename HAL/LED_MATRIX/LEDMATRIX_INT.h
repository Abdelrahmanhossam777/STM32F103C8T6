/*********************************************************************/
/*   AUTHOR      : Abdelrahman Hossam               			     */
/*   Description : Led Matrix DRIVER                				 */
/*   DATE        : 14 SEP 2020 					                     */
/*   VERSION     : V01 											     */
/*                 V02 Serial to Parallel communication function     */
/*********************************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _HAL_LED_MATRIX_INT_H
#define _HAL_LED_MATRIX_INT_H

/******************************************************************************/
/*Function: LEDMAT_voidInit		                          					  */
/*I/P Parameters: Void                		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the Led Matrix pins to output push-pull	          */
/******************************************************************************/
void LEDMAT_voidInit(void);

/******************************************************************************/
/*Function: LEDMAT_voidDisplayFrame                        					  */
/*I/P Parameters: Pointer to array     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Display a frame on the led matrix				          */
/******************************************************************************/
void LEDMAT_voidDisplayFrame(u8 *Copy_u8Frame);

/******************************************************************************/
/*Function: LEDMAT_voidRowCall	                        					  */
/*I/P Parameters: Pointer to array     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Display a frame on Rows	     				          */
/******************************************************************************/
void LEDMAT_voidRowCall(u8 copy_u8Data);

/******************************************************************************/
/*Function: LEDMAT_voidDisableAllCol                       					  */
/*I/P Parameters: Void			     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Disable all the columns	     				          */
/******************************************************************************/
void LEDMAT_voidDisableAllCol(void);

/******************************************************************************/
/*Function: LEDMAT_voidEnableCol                         					  */
/*I/P Parameters: u8 copy_u8PinNum, u8 copy_u8PortNum						  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Enable one the columns	     		     		          */
/******************************************************************************/
void LEDMAT_voidEnableCol(u8 copy_u8PinNum, u8 copy_u8PortNum);

/******************************************************************************/
/*Function: LEDMAT_voidDisplayFrameSTP                     					  */
/*I/P Parameters: Pointer to array     		  								  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Display a frame on the led matrix						  */
/* using serial to parallel communication							          */
/******************************************************************************/
void LEDMAT_voidDisplayFrameSTP(u8 *Copy_u8Frame);
#endif
