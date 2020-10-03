/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : RCC DRIVER                       */
/*   DATE        : 15 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/****************************************/
/* 			     Directives 			*/
/****************************************/
#include "../include/LIB/LIB.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/RCC/RCC_CONF.h"
#include "../include/MCAL/RCC/RCC_INT.h"
#include "../include/MCAL/RCC/RCC_PRIV.h"
// ----------------------------------------------------------------------------
//
// Standalone STM32F1 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

/*int
main(int argc, char* argv[])
{
  // At this stage the system clock should have already been configured
  // at high speed.

  // Infinite loop
  while (1)
    {
       // Add your code here.
    }
}*/

/******************************************************************************/
/*Function: RCC_vidSetClkSource                          					  */
/*I/P Parameters: copy_u32Source            								  */
/*Returns:it returns Error Status                              				  */
/*Desc:This Function Set the Clock source for my micro-controller	          */
/******************************************************************************/
ErrorStatus RCC_vidSetClkSource (u32 copy_u32Source)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/* Switching on the clock sources */
  switch (copy_u32Source) {
	/*IF the clock source is HSI the bits 0,1 are cleared */
	/* then updated with the corresponding value of HSI   */
    case HSI:
				RCC ->RCC_CFGR &= SW_Resetmask;
				RCC ->RCC_CFGR |= copy_u32Source;
				LocalErrorStatus= OK ;
				break;
	/*IF the clock source is HSE the bits 0,1 are cleared */
	/* then updated with the corresponding value of HSE   */
	case HSE:
			    RCC ->RCC_CFGR &= SW_Resetmask;
				RCC ->RCC_CFGR |= copy_u32Source;
				LocalErrorStatus= OK ;
				break;
	/*IF the clock source is PLL the bits 0,1 are cleared */
	/* then updated with the corresponding value of PLL   */
	case PLL:
				RCC ->RCC_CFGR &= SW_Resetmask;
				RCC ->RCC_CFGR |= copy_u32Source;
				LocalErrorStatus= OK ;
				break;
	default:
		LocalErrorStatus= OutOfRange ;
		break;
}
  	  return LocalErrorStatus;
}

/******************************************************************************/
/*Function: RCC_vidSetPeripheralclock                     					  */
/*I/P Parameters: copy_u8Bus , copy_u32peripheral , copy_u8State  			  */
/*Returns:it returns Error Status                              				  */
/*Desc:This Function to enable the clock for a peripheral 	         	      */
/******************************************************************************/
ErrorStatus RCC_vidSetPeripheralclock (u8 copy_u8Bus, u32 copy_u32peripheral, u8 copy_u8State)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/* Switching on buses of peripherals (AHB, APB1, APB2) */
	switch (copy_u8Bus)
	{
	    /* The AHB Bus is Chosen */
		case AHB:
			      /* checking on the state of the peripheral */
				  if (copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_AHBENR |= copy_u32peripheral;
					  LocalErrorStatus= OK ;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_AHBENR &= ~copy_u32peripheral;
					  LocalErrorStatus= OK ;
				  }
				  break;
		/* The APB1 Bus is Chosen */
		case APB1:
			      /* checking on the state of the peripheral */
				  if (copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_APB1ENR |= copy_u32peripheral;
					  LocalErrorStatus= OK ;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_APB1ENR &= ~copy_u32peripheral;
					  LocalErrorStatus= OK ;
				  }
				  break;
		/* The APB2 Bus is Chosen */
		case APB2:
				  /* checking on the state of the peripheral */
				  if (copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_APB2ENR |= copy_u32peripheral;
					  LocalErrorStatus= OK ;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_APB2ENR &= ~copy_u32peripheral;
					  LocalErrorStatus= OK ;
				  }
				  break;
		default:
			LocalErrorStatus= OutOfRange ;
			break;
	}
	return LocalErrorStatus;
}


/******************************************************************************/
/*Function: RCC_vidSetClkStatus                     						  */
/*I/P Parameters: copy_u32Source , copy_u8State  							  */
/*Returns:it returns Error Status                                				  */
/*Desc:This Function to enable or disable the clock Source	        	      */
/******************************************************************************/
ErrorStatus RCC_vidSetClkStatus (u32 copy_u32Source, u8 copy_u8State)
{
	ErrorStatus LocalErrorStatus=NotOk ;
	/* Switching on the clock sources (HSI, HSE, PLL) */
	switch (copy_u32Source) {
		case HSI_Enable:
			             /* checking on the state of the peripheral */
						 if (copy_u8State==ON)
					     {
						  /* Setting the HSI on bit with one to enable it */
						  RCC ->RCC_CR |= copy_u32Source;
						  LocalErrorStatus= OK ;
						 }
						 else
						 {
						  /* Setting the HSI bit with zero to disable it */
						  RCC ->RCC_CR &= ~copy_u32Source;
						  LocalErrorStatus= OK ;
						 }
						 break;
		case HSE_Enable:
			             /* checking on the state of the peripheral */
						 if (copy_u8State==ON)
					     {
						  /* Setting the HSE on bit with one to enable it */
						  RCC ->RCC_CR |= copy_u32Source;
						  LocalErrorStatus= OK ;
						 }
						 else
						 {
						  /* Setting the HSE bit with zero to disable it */
						  RCC ->RCC_CR &= ~copy_u32Source;
						  LocalErrorStatus= OK ;
						 }
						 break;
		case PLL_Enable:
			             /* checking on the state of the peripheral */
						 if (copy_u8State==ON)
					     {
						  /* Setting the PLL on bit with one to enable it */
						  RCC ->RCC_CR |= copy_u32Source;
						  LocalErrorStatus= OK ;
						 }
						 else
						 {
						  /* Setting the PLL bit with zero to disable it */
						  RCC ->RCC_CR &= ~copy_u32Source;
						  LocalErrorStatus= OK ;
						 }
						 break;
		default:
			LocalErrorStatus= OutOfRange ;
			break;
	}
	return LocalErrorStatus;
}

/******************************************************************************/
/*Function: RCC_vidClkInit		                     						  */
/*I/P Parameters: nothing						 							  */
/*Returns:it returns Error Status                              				  */
/*Desc:This Function to enable The Clock due to pre-configurations	   	      */
/******************************************************************************/
ErrorStatus RCC_vidClkInit(void)
{
	ErrorStatus LocalErrorStatus= NotOk;
  #if ClkSource == HSE
	/*HSE ON*/
	LocalErrorStatus=RCC_vidSetClkStatus(HSE_Enable,ON);
	/*pull on Flag to check on the HSE if ready or not*/
	while(((RCC ->RCC_CR>>17)& 0x00000001)!=1);
	LocalErrorStatus=RCC_vidSetClkSource(HSE);
	/*PLL OFF*/
	LocalErrorStatus=RCC_vidSetClkStatus(PLL_Enable,OFF);

  #endif

  #if ClkSource == HSI
	/*HSI ON*/
	LocalErrorStatus= RCC_vidSetClkStatus(HSI_Enable,ON);
	/*pull on Flag to check on the HSE if ready or not*/
	while(((RCC ->RCC_CR>>1)& 0x00000001)!=1);
	LocalErrorStatus= RCC_vidSetClkSource(HSI);
	/*PLL OFF*/
	LocalErrorStatus= RCC_vidSetClkStatus(PLL_Enable,OFF);
	/*HSE OFF*/
	LocalErrorStatus= RCC_vidSetClkStatus(HSE_Enable,OFF);
  #endif

  #if ClkSource == PLL

	switch (PLL_Source) {
		case HSE_Src:
			           /*Switch to HSI*/
					   LocalErrorStatus= RCC_vidSetClkSource(HSE);
					   /*PLL OFF*/
					   LocalErrorStatus= RCC_vidSetClkStatus(PLL_Enable,OFF);
					   /* Setting The prescaler of the PLL */
					   RCC ->RCC_CFGR &= Prescaler_ResetMask;
					   RCC ->RCC_CFGR |= PLL_Prescaler;
					   /*Setting the Division Factor*/
					   RCC ->RCC_CFGR2 &= divisionfactor_ResetMask;
					   RCC ->RCC_CFGR2 |= inputDivisionFactor;
					   /* Setting the source to HSI */
					   RCC ->RCC_CFGR |= (Src_bit);
					   /*PLL ON*/
					   LocalErrorStatus= RCC_vidSetClkStatus(PLL_Enable,ON);
					   /*pull on Flag to check on the HSE if ready or not*/
					   while(((RCC ->RCC_CR>>25)& 0x00000001)!=1);
					   /*Switch to PLL*/
					   LocalErrorStatus= RCC_vidSetClkSource(PLL);
					    break;
		case HSI_Src:
						/*HSI ON*/
			            LocalErrorStatus= RCC_vidSetClkStatus(HSI_Enable,ON);
						/*pull on Flag to check on the HSE if ready or not*/
						while(((RCC ->RCC_CR>>1)& 0x00000001)!=1);
						/*Switch to HSI*/
						LocalErrorStatus= RCC_vidSetClkSource(HSI);
						/*PLL OFF*/
						LocalErrorStatus= RCC_vidSetClkStatus(PLL_Enable,OFF);
						/*HSE OFF*/
						LocalErrorStatus= RCC_vidSetClkStatus(HSE_Enable,OFF);
						/* Setting The prescaler of the PLL */
						RCC ->RCC_CFGR &= Prescaler_ResetMask;
						RCC ->RCC_CFGR |= PLL_Prescaler;
						/* Setting the source to HSI/2 */
						RCC ->RCC_CFGR &= ~(Src_bit);
						/*PLL ON*/
						LocalErrorStatus= RCC_vidSetClkStatus(PLL_Enable,ON);
						/*pull on Flag to check on the HSE if ready or not*/
						while(((RCC ->RCC_CR>>25)& 0x00000001)!=1);
						/*Switch to PLL*/
						LocalErrorStatus= RCC_vidSetClkSource(PLL);
						break;
		default:
			LocalErrorStatus= OutOfRange;
			break;
	}
  #endif

return LocalErrorStatus;
}


// ----------------------------------------------------------------------------
