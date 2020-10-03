/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : GPIO DRIVER                      */
/*   DATE        : 22 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/****************************************/
/* 			     Directives 			*/
/****************************************/

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/RCC/RCC_INT.h"
#include "../include/MCAL/RCC/RCC_PRIV.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"

// ----------------------------------------------------------------------------

/******************************************************************************/
/*Function: GPIO_ErrorStatusIntialization                         			  */
/*I/P Parameters: copy_u8GPIONumber            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function initialize the GPIO using the RCC Enable		          */
/******************************************************************************/
/*Input IOPA , IOPB , IOPC													  */
/******************************************************************************/
ErrorStatus GPIO_ErrorStatusIntialization (u8 copy_u8GPIONumber)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	LocalErrorStatus=RCC_vidSetPeripheralclock(APB2,copy_u8GPIONumber,ON);
	return LocalErrorStatus;
}

/******************************************************************************/
/*Function: GPIO_ErrorStatusOFF			                         			  */
/*I/P Parameters: copy_u8GPIONumber            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function turn off the GPIO using the RCC Enable					  */
/******************************************************************************/
/*Input IOPA , IOPB , IOPC*/
/******************************************************************************/
ErrorStatus GPIO_ErrorStatusOFF (u8 copy_u8GPIONumber)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/* Enable the GPIO throw the RCC peripheral */
	LocalErrorStatus=RCC_vidSetPeripheralclock(APB2,copy_u8GPIONumber,OFF);
	/*Returning the call to the caller function*/
	return LocalErrorStatus;
}

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
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
ErrorStatus GPIO_ErrorStatusSetPinMode (u8 copy_u8PinNumber, u8 copy_u8PortNumber ,u8 copy_u8Direction)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	/**************************************************************************************/

	if ( (copy_u8PortNumber==GPIO_PORTC && (copy_u8PinNumber < 13 || copy_u8PinNumber > 15) ) ||
				 (copy_u8PortNumber==GPIO_PORTB && (copy_u8PinNumber == 2) ) ||
				 (copy_u8PortNumber==GPIO_PORTA && (copy_u8PinNumber == 13 ||copy_u8PinNumber == 14) ))
	{
		if ( copy_u8PinNumber > 15  )
			{
				LocalErrorStatus= OutOfRange;
			}
	   LocalErrorStatus = OutOfRange;
	}
	else
	{
	/**************************************************************************************/
	/**************************************************************************************/
		/* Switching on the GPIO Ports */
		switch (copy_u8PortNumber) {
			/* GPIOA Port */
			case GPIO_PORTA:
							/* Check on the the pin number */
							if (copy_u8PinNumber < 8)
							{
								/* Clear the corresponding bits for the required pin using the reset mask */
								GPIOA->GPIO_CRL &=~ ( GPIO_ResetMask << (copy_u8PinNumber * 4) );
								/* Set the mode and direction of the required pin */
								GPIOA->GPIO_CRL |=  ( copy_u8Direction << (copy_u8PinNumber * 4) );
								/* Update the error Status */
								LocalErrorStatus=OK;
							}
							else
							{
								/* Subtraction 8 from the pin number for the high register */
								copy_u8PinNumber -= 8;
								/* Clear the corresponding bits for the required pin using the reset mask */
								GPIOA->GPIO_CRH &=~ ( GPIO_ResetMask << (copy_u8PinNumber * 4) );
								/* Set the mode and direction of the required pin */
								GPIOA->GPIO_CRH |=  ( copy_u8Direction << (copy_u8PinNumber * 4) );
								/* Update the error Status */
								LocalErrorStatus=OK;
							}
							break;
			/* GPIOA Port */
			case GPIO_PORTB:
							/* Check on the the pin number */
							if (copy_u8PinNumber < 8)
							{
								/* Clear the corresponding bits for the required pin using the reset mask */
								GPIOB->GPIO_CRL &=~ ( GPIO_ResetMask << (copy_u8PinNumber * 4) );
								/* Set the mode and direction of the required pin */
								GPIOB->GPIO_CRL |=  ( copy_u8Direction << (copy_u8PinNumber * 4) );
								/* Update the error Status */
								LocalErrorStatus=OK;
							}
							else
							{
								/* Subtraction 8 from the pin number for the high register */
								copy_u8PinNumber -= 8;
								/* Clear the corresponding bits for the required pin using the reset mask */
								GPIOB->GPIO_CRH &=~ ( GPIO_ResetMask << (copy_u8PinNumber * 4) );
								/* Set the mode and direction of the required pin */
								GPIOB->GPIO_CRH |=  ( copy_u8Direction << (copy_u8PinNumber * 4) );
								/* Update the error Status */
								LocalErrorStatus=OK;
							}
							break;
			/* GPIOA Port */
			case GPIO_PORTC:
							/* Check on the the pin number */
							if (copy_u8PinNumber < 8)
							{
								/* Clear the corresponding bits for the required pin using the reset mask */
								GPIOC->GPIO_CRL &=~ ( GPIO_ResetMask << (copy_u8PinNumber * 4) );
								/* Set the mode and direction of the required pin */
								GPIOC->GPIO_CRL |=  ( copy_u8Direction << (copy_u8PinNumber * 4) );
								/* Update the error Status */
								LocalErrorStatus=OK;
							}
							else
							{
								/* Subtraction 8 from the pin number for the high register */
								copy_u8PinNumber -= 8;
								/* Clear the corresponding bits for the required pin using the reset mask */
								GPIOC->GPIO_CRH &=~ ( GPIO_ResetMask << (copy_u8PinNumber * 4) );
								/* Set the mode and direction of the required pin */
								GPIOC->GPIO_CRH |=  ( copy_u8Direction << (copy_u8PinNumber * 4) );
								/* Update the error Status */
								LocalErrorStatus=OK;
							}
							break;
			default:
					/* Update the error Status */
				    LocalErrorStatus= NotOk;
				    break;
		 }
	}
	/**************************************************************************************/
	/**************************************************************************************/
	/*Returning the control to the caller function*/
	return LocalErrorStatus;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
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
ErrorStatus GPIO_ErrorStatusSetPortMode (u8 copy_u8PinNumberStart, u8 copy_u8PinNumberEnd, u8 copy_u8PortNumber ,u8 copy_u8Direction)
{
	ErrorStatus LocalErrorStatus= NotOk ;

	for ( ; copy_u8PinNumberStart <= copy_u8PinNumberEnd ; copy_u8PinNumberStart++)
	{

		GPIO_ErrorStatusSetPinMode(copy_u8PinNumberStart,copy_u8PortNumber,copy_u8Direction);
	}
	/**************************************************************************************/
	/**************************************************************************************/
	/*Returning the control to the caller function*/
	return LocalErrorStatus;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/*Function: GPIO_u32GetPin			                          								  */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns u32	                                				                  */
/*Desc:This Function get the GPIO pin value							                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
u8 GPIO_u8GetPin (u8 copy_PinNumber, u8 copy_u8PortNumber)
{
	u8 Local_u8Value;
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	if ( (copy_PinNumber > 15) )
	{
		return OutOfRange;
	}

	/**************************************************************************************/
	/**************************************************************************************/
	/* Switching on the port number */
	switch (copy_u8PortNumber)
	{
		/*Port A configuration to read a value*/
		case GPIO_PORTA:
					/*Reading the value from the IDR*/
					Local_u8Value= GET_BIT( GPIOA-> GPIO_IDR,copy_PinNumber );
					break;
		/*Port B configuration to read a value*/
		case GPIO_PORTB:
					/*Reading the value from the IDR*/
					Local_u8Value= GET_BIT( GPIOB-> GPIO_IDR,copy_PinNumber );
					break;
		/*Port C configuration to read a value*/
		case GPIO_PORTC:
					/*Reading the value from the IDR*/
					Local_u8Value= GET_BIT( GPIOC-> GPIO_IDR,copy_PinNumber );
					break;
		default:
			break;
	}
	/*Returning The required value*/
	return Local_u8Value;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/*Function: GPIO_ErrorStatusSetPinValue			                          				      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber	copy_u8Value							  */
/*Returns:it returns ErrorStatus		                            				          */
/*Desc:This Function Set the GPIO pin output value					                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Value High or Low																	  */
ErrorStatus GPIO_ErrorStatusSetPinValue (u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8Value)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	if ( (copy_PinNumber > 15) )
	{
		return OutOfRange;
	}

	/**************************************************************************************/
	/**************************************************************************************/
	/* Switching on the port number */
	switch (copy_u8PortNumber)
	{
		/* GPIOA */
		case GPIO_PORTA:
						/* Checking on High Signal */
						if (copy_u8Value==High)
						{
							/* Setting the ODR Value */
							GPIOA ->GPIO_ODR |= (1 << copy_PinNumber);
							/* Update the error Status */
							LocalErrorStatus= OK ;
						}
						/* Checking on Low Signal */
						else if (copy_u8Value==Low)
						{
							/* Setting the ODR Value */
							GPIOA ->GPIO_ODR &=~ (1 << copy_PinNumber);
							/* Update the error Status */
							LocalErrorStatus= OK ;
						}
						else
						{
							LocalErrorStatus= NotOk ;
						}
						break;
		/* GPIOB */
		case GPIO_PORTB:
						/* Checking on High Signal */
						if (copy_u8Value==High)
						{
							/* Setting the ODR Value */
							GPIOB ->GPIO_ODR |= (1 << copy_PinNumber);
							/* Update the error Status */
							LocalErrorStatus= OK ;
						}
						/* Checking on Low Signal */
						else if (copy_u8Value==Low)
						{
							/* Setting the ODR Value */
							GPIOB ->GPIO_ODR &=~ (1 << copy_PinNumber);
							/* Update the error Status */
							LocalErrorStatus= OK ;
						}
						else
						{
							/* Update the error Status */
							LocalErrorStatus= NotOk ;
						}
						break;
		/* GPIOC */
		case GPIO_PORTC:
						/* Checking on High Signal */
						if (copy_u8Value==High)
						{
							/* Setting the ODR Value */
							GPIOC ->GPIO_ODR |= (1 << copy_PinNumber);
							LocalErrorStatus= OK ;
						}
						/* Checking on Low Signal */
						else if (copy_u8Value==Low)
						{
							/* Setting the ODR Value */
							GPIOC ->GPIO_ODR &=~ (1 << copy_PinNumber);
							LocalErrorStatus= OK ;
						}
						else
						{
							/* Update the error Status */
							LocalErrorStatus= NotOk ;
						}
						break;
		default:
			/* Update the error Status */
			LocalErrorStatus= NotOk ;
			break;
	}
	/* Return the call to the caller function */
	return LocalErrorStatus;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/*Function: GPIO_u32SetPinValue			                          						      */
/*I/P Parameters: copy_PinNumber copy_PinNumberEnd   copy_u8PortNumber	copy_u8Value		  */
/*Returns:it returns ErrorStatus		                            				          */
/*Desc:This Function Set the GPIO port output value					                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Value High or Low																	  */
ErrorStatus GPIO_ErrorStatusSetPortValue (u8 copy_PinNumber,u8 copy_PinNumberEnd, u8 copy_u8PortNumber, u8 copy_u8Value)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	if ( (copy_PinNumber > 15) || (copy_PinNumberEnd > 15) || (copy_PinNumberEnd <copy_PinNumber))
	{
		return OutOfRange;
	}

	/**************************************************************************************/
	/**************************************************************************************/
	for ( ; copy_PinNumber<=copy_PinNumberEnd ;copy_PinNumber++ )
	{
		/* Switching on the port number */
		switch (copy_u8PortNumber)
		{
			case GPIO_PORTA:
							if (copy_u8Value==High)
							{
								GPIOA ->GPIO_ODR |= (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else if (copy_u8Value==Low)
							{
								GPIOA ->GPIO_ODR &=~( 1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else
							{
								LocalErrorStatus= NotOk ;
							}
							break;
			case GPIO_PORTB:
							if (copy_u8Value==High)
							{
								GPIOB ->GPIO_ODR |= (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else if (copy_u8Value==Low)
							{
								GPIOB ->GPIO_ODR &=~ (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else
							{
								LocalErrorStatus= NotOk ;
							}
							break;
			case GPIO_PORTC:
							if (copy_u8Value==High)
							{
								GPIOC ->GPIO_ODR |= (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else if (copy_u8Value==Low)
							{
								GPIOC ->GPIO_ODR &=~ (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else
							{
								LocalErrorStatus= NotOk ;
							}
							break;
			default:
				LocalErrorStatus= NotOk ;
				break;
		}
	}
	return LocalErrorStatus;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/*Function: GPIO_AtomicSet				                          						      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Set the GPIO pin output value using atomic access                        */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
void GPIO_AtomicSet(u8 copy_PinNumber, u8 copy_u8PortNumber)
{
		/**************************************************************************************/
		/**************************************************************************************/
		/*									Inputs Validation								  */
		if ( (copy_PinNumber > 15) )
		{
			return ;
		}

		/**************************************************************************************/
		/**************************************************************************************/
		/* Switching on the port number */
		switch (copy_u8PortNumber)
		{
			case GPIO_PORTA:
							GPIOA->GPIO_BSRR = 1<<copy_PinNumber;
							break;
			case GPIO_PORTB:
							GPIOB->GPIO_BSRR = 1<<copy_PinNumber;
							break;
			case GPIO_PORTC:
							GPIOC->GPIO_BSRR = 1<<copy_PinNumber;
							break;
			default:

				break;
		}
		return ;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/*Function: GPIO_AtomicReset				                          					      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Reset the GPIO pin output value using atomic access                      */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
void GPIO_AtomicReset(u8 copy_PinNumber, u8 copy_u8PortNumber)
{
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	if ((copy_PinNumber < 0) || (copy_PinNumber > 15) )
	{
		return ;
	}

	/**************************************************************************************/
	/**************************************************************************************/
	/* Switching on the port number */
	switch (copy_u8PortNumber)
	{
		case GPIO_PORTA:
						GPIOA->GPIO_BRR = 1<<copy_PinNumber;
						break;
		case GPIO_PORTB:
						GPIOB->GPIO_BRR = 1<<copy_PinNumber;
						break;
		case GPIO_PORTC:
						GPIOC->GPIO_BRR = 1<<copy_PinNumber;
						break;
		default:

			break;
	}
	return ;
}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/*Function: GPIO_vidLockPin  				                          					      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function lock or unlock the GPIO pin from being configured                        */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Statues GPIO_Lock, GPIO_Unlock                                                       */
void GPIO_vidLockPin (u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8Statue)
{
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	if ((copy_PinNumber < 0) || (copy_PinNumber > 15) )
	{
		return ;
	}

	/**************************************************************************************/
	/**************************************************************************************/
	/* Switching on the port number */
	switch (copy_u8PortNumber)
	{
		case GPIO_PORTA:
						/* Sequence for the LCKK bit */
						SET_BIT(GPIOA->GPIO_LCKR,LCKK);
						CLR_BIT(GPIOA->GPIO_LCKR,LCKK);
						SET_BIT(GPIOA->GPIO_LCKR,LCKK);
						if( ~ GET_BIT(GPIOA->GPIO_LCKR,LCKK) )
						{
							/*Switching on lock or unlock*/
							switch (copy_u8Statue)
							{
							    /*Lock Case*/
								case GPIO_Lock:
									    SET_BIT(GPIOA->GPIO_LCKR,copy_PinNumber);
										break;
							    /*Unlock Case*/
								case GPIO_Unlock:
									    CLR_BIT(GPIOA->GPIO_LCKR,copy_PinNumber);
										break;
								default:
									break;
							}
							/* Sequence for the LCKK bit */
							SET_BIT(GPIOA->GPIO_LCKR,LCKK);
							CLR_BIT(GPIOA->GPIO_LCKR,LCKK);
							SET_BIT(GPIOA->GPIO_LCKR,LCKK);
						}
						break;
		case GPIO_PORTB:
					    /* Sequence for the LCKK bit */
						SET_BIT(GPIOB->GPIO_LCKR,LCKK);
						CLR_BIT(GPIOB->GPIO_LCKR,LCKK);
						SET_BIT(GPIOB->GPIO_LCKR,LCKK);
						if( ~ GET_BIT(GPIOB->GPIO_LCKR,LCKK) )
						{
							switch (copy_u8Statue)
							{
								case GPIO_Lock:
										SET_BIT(GPIOB->GPIO_LCKR,copy_PinNumber);
										break;
								case GPIO_Unlock:
										CLR_BIT(GPIOB->GPIO_LCKR,copy_PinNumber);
										break;
								default:
									break;
							}
						    /* Sequence for the LCKK bit */
							SET_BIT(GPIOB->GPIO_LCKR,LCKK);
							CLR_BIT(GPIOB->GPIO_LCKR,LCKK);
							SET_BIT(GPIOB->GPIO_LCKR,LCKK);
						}
						break;
		case GPIO_PORTC:
		    			/* Sequence for the LCKK bit */
						SET_BIT(GPIOC->GPIO_LCKR,LCKK);
						CLR_BIT(GPIOC->GPIO_LCKR,LCKK);
						SET_BIT(GPIOC->GPIO_LCKR,LCKK);
						if( ~ GET_BIT(GPIOC->GPIO_LCKR,LCKK) )
						{
							switch (copy_u8Statue)
							{
								case GPIO_Lock:
										SET_BIT(GPIOC->GPIO_LCKR,copy_PinNumber);
										break;
								case GPIO_Unlock:
										CLR_BIT(GPIOC->GPIO_LCKR,copy_PinNumber);
										break;
								default:
									break;
							}
						    /* Sequence for the LCKK bit */
							SET_BIT(GPIOC->GPIO_LCKR,LCKK);
							CLR_BIT(GPIOC->GPIO_LCKR,LCKK);
							SET_BIT(GPIOC->GPIO_LCKR,LCKK);
						}
						break;
		default:
				break;
	}

}
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/*Function: GPIO_ErrorStatusSetPortDiffValues			                          			  */
/*I/P Parameters: copy_PinNumber copy_PinNumberEnd   copy_u8PortNumber	copy_u8Value		  */
/*Returns:it returns ErrorStatus		                            				          */
/*Desc:This Function Set the GPIO port output value					                          */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Value High or Low																	  */
ErrorStatus GPIO_ErrorStatusSetPortDiffValues (u8 copy_PinNumber,u8 copy_PinNumberEnd, u8 copy_u8PortNumber, u16 copy_u8Value)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	u8 Local_u8Counter=0;
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	if ( (copy_PinNumber > 15) || (copy_PinNumberEnd > 15) || (copy_PinNumberEnd < copy_PinNumber))
	{
		return OutOfRange;
	}

	/**************************************************************************************/
	/**************************************************************************************/
	for ( ; copy_PinNumber<=copy_PinNumberEnd ;copy_PinNumber++ )
	{
		/* Switching on the port number */
		switch (copy_u8PortNumber)
		{
			case GPIO_PORTA:
							if (GET_BIT(copy_u8Value,Local_u8Counter)==High)
							{
								GPIOA ->GPIO_ODR |= (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else if (GET_BIT(copy_u8Value,Local_u8Counter)==Low)
							{
								GPIOA ->GPIO_ODR &=~ (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else
							{
								LocalErrorStatus= NotOk ;
							}
							break;
			case GPIO_PORTB:
							if (GET_BIT(copy_u8Value,Local_u8Counter)==High)
							{
								GPIOB ->GPIO_ODR |= (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else if (GET_BIT(copy_u8Value,Local_u8Counter)==Low)
							{
								GPIOB ->GPIO_ODR &=~ (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else
							{
								LocalErrorStatus= NotOk ;
							}
							break;
			case GPIO_PORTC:
							if (GET_BIT(copy_u8Value,Local_u8Counter)==High)
							{
								GPIOC ->GPIO_ODR |= (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else if (GET_BIT(copy_u8Value,Local_u8Counter)==Low)
							{
								GPIOC ->GPIO_ODR &=~ (1 << copy_PinNumber);
								LocalErrorStatus= OK ;
							}
							else
							{
								LocalErrorStatus= NotOk ;
							}
							break;
			default:
				LocalErrorStatus= NotOk ;
				break;
		}
		Local_u8Counter++;
	}
	return LocalErrorStatus;
}




