/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SYSTICK DRIVER                   */
/*   DATE        : 29 AGU 2020                      */
/*   VERSION     : V02                              */
/****************************************************/

/****************************************/
/* 			     Directives 			*/
/****************************************/
#include "../include/LIB/LIB.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/SYSTICK/SYSTICK_INT.h"
#include "../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include "../include/MCAL/SYSTICK/SYSTICK_PRIV.h"

/******************************************************************************/
/*Function: SYSTICk_ErrorStatusConfig                          				  */
/*I/P Parameters: no thing		            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function control SYSTICK Timer depend on pre-configurations	      */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusConfig ()
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/* Enable The SYSTICK Timer Interrupt */
	#if (SYSTICK_TickInt==1)
			SET_BIT(SYSTICK->STK_CTRL, SYSTICK_TickIntBit);
	/* Disable The SYSTICK Timer Interrupt */
    #else
			CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_TickIntBit);
	#endif

	#if (SYSTICK_ClockSource==1)
			/* The SYSTICK Timer Clock Source is AHB */
			SET_BIT(SYSTICK->STK_CTRL, SYSTICK_ClockSourceBit);
			LocalErrorStatus= OK;

	#else
			/* The SYSTICK Timer Clock Source is AHB/8 */
			CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_ClockSourceBit);
			LocalErrorStatus= OK;
    #endif
    /*Pre-Load setting during initialization */
    #if(PreloadEnable)
		    SYSTICK->STK_LOAD=Preload_Value;
    #endif

	return LocalErrorStatus;
}


/******************************************************************************/
/*Function: SYSTICk_ErrorStatusEnable                     					  */
/*I/P Parameters: void			            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function enables the SYSTICK Timer						          */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusEnable ()
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/* Enable The SYSTICK Timer */
	SET_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);
	LocalErrorStatus=OK;
	return LocalErrorStatus;
}

/******************************************************************************/
/*Function: SYSTICk_ErrorStatusDisable                     					  */
/*I/P Parameters: void			            								  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function disables the SYSTICK Timer						          */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusDisable ()
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/* Disable The SYSTICK Timer */
	CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);
	LocalErrorStatus=OK;
	return LocalErrorStatus;
}
/******************************************************************************/
/*Function: SYSTICk_ErrorStatusPreLoad                          			  */
/*I/P Parameters: copy_u32PreloadValue		            					  */
/*Returns:it returns Error Status                            				  */
/*Desc:This Function control SYSTICK Timer Preload						      */
/******************************************************************************/
ErrorStatus SYSTICk_ErrorStatusPreLoad (u32 copy_u32PreloadValue)
{
	ErrorStatus LocalErrorStatus= NotOk ;
	/*IF required immediately update the value register*/
    #if (Preload_Immediate)

		SYSTICK->STK_LOAD=copy_u32PreloadValue;
		SYSTICK->STK_VAL =Preload_Value;
		LocalErrorStatus=OK;

	/*After this iteration required to change the pre-load value*/
   #else
	{
		SYSTICK->STK_LOAD=copy_u32PreloadValue;
		LocalErrorStatus=OK;
	}
   #endif
	return LocalErrorStatus;
}


/******************************************************************************/
/*Function: delay_ms					                          			  */
/*I/P Parameters: copy_u32Time				            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:This Function makes a delay for number of m sec up to 16 sec		      */
/******************************************************************************/
void delay_ms (u32 copy_u32Time)
{
	/* Calculation of the pre load value to count specific number of m sec */
	u32 local_u32preLoad = 16777216 * (1-((copy_u32Time*1000)/16777216));

	/* Update the Load registers with number of m sec i want to count */
	SYSTICK->STK_LOAD=local_u32preLoad;
	SYSTICK->STK_VAL =Preload_Value;

	/* Enable the Timer */
	SET_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

	/* Polling on the flag of the timer */
	while (GET_BIT(SYSTICK->STK_CTRL,16)==0);

	/* Disable the counter */
	CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

	/* update the pre-load value with 0 */
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL =0;
}

/******************************************************************************/
/*Function: SYSTICK_voidSetBusyWait		                          			  */
/*I/P Parameters: copy_u32Ticks				            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes a delay for number of ticks(This holds the processor)		      */
/******************************************************************************/
void SYSTICK_voidSetBusyWait (u32 copy_u32Ticks)
{
	/* Update the Load registers with number of Ticks or counts */
	SYSTICK->STK_LOAD=copy_u32Ticks;
	SYSTICK->STK_VAL =Preload_Value;

	/* Enable the Timer */
	SET_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

	/* Polling on the flag of the timer */
	while (GET_BIT(SYSTICK->STK_CTRL,16)==0);

	/* Disable the counter */
	CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

	/* update the pre-load value with 0 */
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL =0;
}

/******************************************************************************/
/*Function: SYSTICK_voidSetIntervalSingle	                       			  */
/*I/P Parameters: copy_u32Ticks				            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes Async function fires an interrupt after specific time once	      */
/******************************************************************************/
void SYSTICK_voidSetIntervalSingle  ( u32 copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Disable the counter */
	CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);
	SYSTICK->STK_VAL =0;
	/* Update the Load registers with number of Ticks or counts */
	SYSTICK->STK_LOAD=copy_u32Ticks;


	/* Enable the Timer */
	SET_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

	/* Save CallBack */
	SYSTICK_CallBack = Copy_ptr;
	/* Set Mode to Single */
	SYSTICK_u8ModeOfInterval = SYSTICK_SINGLE_INTERVAL;

	/* Enable the interrupt */
	SET_BIT(SYSTICK->STK_CTRL, SYSTICK_TickIntBit);
}

/******************************************************************************/
/*Function: SYSTICK_voidSetIntervalPeriodic	                       			  */
/*I/P Parameters: copy_u32Ticks				            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes Async function fires an interrupt after specific time 		      */
/******************************************************************************/
void SYSTICK_voidSetIntervalPeriodic  ( u32 copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Update the Load registers with number of Ticks or counts */
	SYSTICK->STK_LOAD=copy_u32Ticks;

	/* Enable the Timer */
	SET_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

	/* Save CallBack */
	SYSTICK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	SYSTICK_u8ModeOfInterval = SYSTICK_PERIOD_INTERVAL;

	/* Enable the Interrupt */
	SET_BIT(SYSTICK->STK_CTRL, SYSTICK_TickIntBit);
}

/******************************************************************************/
/*Function: SYSTICK_voidStopInterval		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns nothing	                            				  */
/*Desc:Makes This function stops the periodic events of the SYSTICK timer     */
/******************************************************************************/
void SYSTICK_voidStopInterval(void)
{
	/* Disable the Interrupt */
	CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_TickIntBit);

	/* Disable the Timer */
	CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

	/* update the pre-load value with 0 */
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL =0;
}

/******************************************************************************/
/*Function: SYSTICK_u32GetElapsedTime		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns u32		                            				  */
/*Desc:Makes This function Get the Elapsed Time from the start of the Timer   */
/******************************************************************************/
u32  SYSTICK_u32GetElapsedTime(void)
{
	/* Local variable to get the elapsed time in it */
	u32 Local_u32ElapsedTime;

	/*Reading the elapsed time form SYSTICK registers*/
	Local_u32ElapsedTime = SYSTICK->STK_LOAD - SYSTICK-> STK_VAL ;

	/*Returning the Control to the caller function with the elapsed time*/
	return Local_u32ElapsedTime;
}

/******************************************************************************/
/*Function: SYSTICK_u32GetRemainingTime		                       			  */
/*I/P Parameters: void						            					  */
/*Returns:it returns u32		                            				  */
/*Desc:Makes This function Get the remaining Time for the Timer to overflow   */
/******************************************************************************/
u32  SYSTICK_u32GetRemainingTime(void)
{
	/* Local variable to get the remaining time in it */
	u32 Local_u32RemainTime;

	/*Reading the remaining time form SYSTICK registers*/
	Local_u32RemainTime = SYSTICK-> STK_VAL ;

	/*Returning the Control to the caller function with the remaining time*/
	return Local_u32RemainTime;
}

/* The ISR for the SYSTICK peripheral */
void SysTick_Handler (void)
{
	/* Local Variable to clear the flag with it */
	u8 Local_u8Temporary;

	if (SYSTICK_u8ModeOfInterval == SYSTICK_SINGLE_INTERVAL)
	{
		/* Disable the Interrupt */
		CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_TickIntBit);

		/* Disable the Timer */
		CLR_BIT(SYSTICK->STK_CTRL, SYSTICK_EnableBit);

		/* update the pre-load value with 0 */
		SYSTICK->STK_LOAD=0;
		SYSTICK->STK_VAL =0;
	}

	/* Callback notification */
	SYSTICK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(SYSTICK->STK_CTRL,SYSTICK_CountFlagBit);
}
