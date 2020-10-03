/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DAC DRIVER                       */
/*   DATE        : 4 SEP 2020                       */
/*   VERSION     : V01                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_DAC_INT_H_
#define HAL_DAC_INT_H_

/******************************************************************************/
/*Function: DAC_voidInit			                       					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the pin to Output Pushpull		     		          */
/******************************************************************************/
void DAC_voidInit ();

/******************************************************************************/
/*Function: DAC_voidOutput			                       					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the pin to Values of the signal     		          */
/******************************************************************************/
void DAC_voidOutput();


#endif
