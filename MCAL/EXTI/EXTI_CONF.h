/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 30 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXTI_CONF_H
#define __EXTI_CONF_H

/**********************************/
/* Options: 					  */
/*          EXTI_LINE0			  */
/*          EXTI_LINE1			  */
/*          EXTI_LINE2			  */
/* Pre-configuration for the line */
/**********************************/
#define EXTI_LINE  EXTI_LINE0

/**********************************/
/* Options: 					  */
/*          FALLING_EDGE		  */
/*          RISING_EDGE			  */
/*          ON_CHANGE			  */
/* Pre-configuration for the mode */
/**********************************/
#define EXTI_SenseMode  FALLING_EDGE

#define EXTI0_CallBack   0
#define EXTI1_CallBack   1
#define EXTI2_CallBack   2
#define EXTI3_CallBack   3
#define EXTI4_CallBack   4
#define EXTI5_CallBack   5
#define EXTI6_CallBack   6
#define EXTI7_CallBack   7
#define EXTI8_CallBack   8
#define EXTI9_CallBack   9
#define EXTI10_CallBack  10
#define EXTI11_CallBack  11
#define EXTI12_CallBack  12
#define EXTI13_CallBack  13
#define EXTI14_CallBack  14
#define EXTI15_CallBack  15

#endif
