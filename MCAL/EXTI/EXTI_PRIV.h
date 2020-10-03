/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 30 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXTI_PRIV_H
#define __EXTI_PRIV_H


/******************************************************/
/* Description : Definitions for EXTI Base Address    */
/******************************************************/
#define EXTI ((volatile EXTI_R*) 0x40010400)

/************************************************************/
/* Description :  EXTI Registers mapping using structure    */
/************************************************************/
typedef struct
{
	/*Interrupt mask register (EXTI_IMR)*/
	volatile u32 EXTI_IMR;
	/*Event mask register (EXTI_EMR)*/
	volatile u32 EXTI_EMR ;
	/*Rising trigger selection register (EXTI_RTSR)*/
	volatile u32 EXTI_RTSR ;
	/*Falling trigger selection register (EXTI_FTSR)*/
	volatile u32 EXTI_FTSR ;
	/*Software interrupt event register (EXTI_SWIER)*/
	volatile u32 EXTI_SWIER ;
	/*Pending register (EXTI_PR)*/
	volatile u32 EXTI_PR ;
}EXTI_R;

/************************************************************/
/* Description :  EXTI Sense modes definitions  		    */
/************************************************************/
#define FALLING_EDGE  1
#define RISING_EDGE   3
#define ON_CHANGE     5

/************************************************************/
/* Description :  EXTI Registers mapping using structure    */
/************************************************************/
#define EXTI_LINE0   0
#define EXTI_LINE1   1
#define EXTI_LINE2   2
#define EXTI_LINE3   3
#define EXTI_LINE4   4
#define EXTI_LINE5   5
#define EXTI_LINE6   6
#define EXTI_LINE7   7
#define EXTI_LINE8   8
#define EXTI_LINE9   9
#define EXTI_LINE10  10
#define EXTI_LINE11  11
#define EXTI_LINE12  12
#define EXTI_LINE13  13
#define EXTI_LINE14  14
#define EXTI_LINE15  15



static void  ( *ptr_CallBack [16] ) (void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
											NULL,NULL,NULL,NULL,NULL,NULL,NULL};//NULL;

#define CLR_Pending(INT_Line)  SET_BIT(EXTI->EXTI_PR,INT_Line)
#endif /* __EXTI_PRIV_H */
