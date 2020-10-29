/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SYSTICK DRIVER                   */
/*   DATE        : 27 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTICK_PRIV_H
#define __SYSTICK_PRIV_H



/******************************************************/
/* Description : Definitions for SYSTICK Base Address */
/******************************************************/
#define SYSTICK ((volatile Systick_R*) 0xE000E010)

/******************************************************/
/* Define a macro for Single Time Event 			  */
/******************************************************/
#define     SYSTICK_SINGLE_INTERVAL    0

/******************************************************/
/* Define a macro for Periodic Events 				  */
/******************************************************/
#define     SYSTICK_PERIOD_INTERVAL    1


/******************************************************/
/* Define Variable for interval mode 				  */
/******************************************************/
static u8 SYSTICK_u8ModeOfInterval;

/******************************************************/
/* Define Callback Global Variable 					  */
/******************************************************/
static void(*SYSTICK_CallBack)(void);

/************************************************************/
/* Description : SYSTICK Registers mapping using structure  */
/************************************************************/
typedef struct
{
	/*SysTick control and status register (STK_CTRL)*/
	volatile u32 STK_CTRL;
	/*SysTick reload value register (STK_LOAD)*/
	volatile u32 STK_LOAD;
	/*SysTick current value register (STK_VAL)*/
	volatile u32 STK_VAL;
	/*SysTick calibration value register (STK_CALIB)*/
	volatile u32 STK_CALIB;
}Systick_R;

#endif /* __SYSTICK_PRIV_H */
