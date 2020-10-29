/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : GPIO DRIVER                      */
/*   DATE        : 22 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_INT_H
#define __GPIO_INT_H



/******************************************************************************/
/*Function: GPIO_ErrorStatusIntialization                         			  */
/*I/P Parameters: copy_u8GPIONumber            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function initialize the GPIO using the RCC Enable		          */
/******************************************************************************/
/*Input IOPA , IOPB , IOPC													  */
/******************************************************************************/
ErrorStatus GPIO_ErrorStatusIntialization (u8 copy_u8GPIONumber);

/******************************************************************************/
/*Function: GPIO_ErrorStatusOFF			                         			  */
/*I/P Parameters: copy_u8GPIONumber            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function turn off the GPIO using the RCC Enable		  	          */
/******************************************************************************/
/*Input IOPA , IOPB , IOPC*/
/******************************************************************************/
ErrorStatus GPIO_ErrorStatusOFF (u8 copy_u8GPIONumber);

/**********************************************************************************************/
/*Function: GPIO_ErrorStatusSetPort                          								  */
/*I/P Parameters: copy_PinNumberStart  copy_u8PortNumber					                  */
/*                copy_u8Direction     copy_u8Mode											  */
/*Returns:it returns Error Status                            								  */
/*Desc:This Function Set the GPIO pin direction and mode			         				  */
/**********************************************************************************************/
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTC      							  		      */
/*Direction: Input_Analog, Input_Floating, Input_Pull										  */
/*           Output10_PushPull, Output10_OpenDrain, Output10_AFPushPull, Output10_AFOpenDrain */
/*           Output2_PushPull,  Output2_OpenDrain,  Output2_AFPushPull,  Output2_AFOpenDrain  */
/*           Output50_PushPull, Output50_OpenDrain, Output50_AFPushPull, Output50_AFOpenDrain */
/**********************************************************************************************/
ErrorStatus GPIO_ErrorStatusSetPinMode (u8 copy_u8PinNumber, u8 copy_u8PortNumber ,u8 copy_u8Direction);

/**********************************************************************************************/
/*Function: GPIO_ErrorStatusSetPort                          								  */
/*I/P Parameters: copy_PinNumberStart copy_PinNumberEnd copy_u8PortNumber					  */
/*                copy_u8Direction  copy_u8Mode												  */
/*Returns:it returns Error Status                            								  */
/*Desc:This Function Set the GPIO port direction and mode			         				  */
/**********************************************************************************************/
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTC      							  		      */
/*Direction: Input_Analog, Input_Floating, Input_Pull										  */
/*           Output10_PushPull, Output10_OpenDrain, Output10_AFPushPull, Output10_AFOpenDrain */
/*           Output2_PushPull,  Output2_OpenDrain,  Output2_AFPushPull,  Output2_AFOpenDrain  */
/*           Output50_PushPull, Output50_OpenDrain, Output50_AFPushPull, Output50_AFOpenDrain */
/**********************************************************************************************/
ErrorStatus GPIO_ErrorStatusSetPortMode (u8 copy_u8PinNumberStart, u8 copy_u8PinNumberEnd, u8 copy_u8PortNumber ,u8 copy_u8Direction);

/**********************************************************************************************/
/*Function: GPIO_u32GetPin			                          								  */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns u32		                            				                  */
/*Desc:This Function Set the GPIO pin direction and mode			                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
u8 GPIO_u32GetPin (u8 copy_PinNumber, u8 copy_u8PortNumber);

/**********************************************************************************************/
/*Function: GPIO_ErrorStatusSetPinValue			                          					  */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber	copy_u8Value							  */
/*Returns:it returns ErrorStatus		                            				          */
/*Desc:This Function Set the GPIO pin output value					                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Value High or Low																	  */
ErrorStatus GPIO_ErrorStatusSetPinValue (u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8Value);

/**********************************************************************************************/
/*Function: GPIO_u32SetPinValue			                          						      */
/*I/P Parameters: copy_PinNumber copy_PinNumberEnd   copy_u8PortNumber	copy_u8Value		  */
/*Returns:it returns ErrorStatus		                            				          */
/*Desc:This Function Set the GPIO pin output value					                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Value High or Low																	  */
ErrorStatus GPIO_ErrorStatusSetPortValue (u8 copy_PinNumber,u8 copy_PinNumberEnd, u8 copy_u8PortNumber, u8 copy_u8Value);

/**********************************************************************************************/
/*Function: GPIO_AtomicSet				                          						      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Set the GPIO pin output value using atomic access                        */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
void GPIO_AtomicSet(u8 copy_PinNumber, u8 copy_u8PortNumber);

/**********************************************************************************************/
/*Function: GPIO_AtomicReset				                          					      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Reset the GPIO pin output value using atomic access                      */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
void GPIO_AtomicReset(u8 copy_PinNumber, u8 copy_u8PortNumber);

/**********************************************************************************************/
/*Function: GPIO_vidLockPin  				                          					      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function lock or unlock the GPIO pin from being configured                        */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Statues GPIO_Lock, GPIO_Unlock                                                       */
void GPIO_vidLockPin (u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8Statue);

/**********************************************************************************************/
/*Function: GPIO_ErrorStatusSetPortDiffValues			                          			  */
/*I/P Parameters: copy_PinNumber copy_PinNumberEnd   copy_u8PortNumber	copy_u8Value		  */
/*Returns:it returns ErrorStatus		                            				          */
/*Desc:This Function Set the GPIO port output value					                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Value High or Low																	  */
ErrorStatus GPIO_ErrorStatusSetPortDiffValues (u8 copy_PinNumber,u8 copy_PinNumberEnd, u8 copy_u8PortNumber, u16 copy_u8Value);


#endif /* __GPIO_INT_H */
