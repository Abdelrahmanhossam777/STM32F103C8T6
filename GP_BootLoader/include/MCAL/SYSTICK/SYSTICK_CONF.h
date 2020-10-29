/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SYSTICK DRIVER                   */
/*   DATE        : 27 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTICK_CONF_H
#define __SYSTICK_CONF_H

/*********************************************/
/* bit0: Enable bit configuration  			 */
/*       Enable  1                 			 */
/*       Disable 0                 			 */
#define SYSTICK_Enable 	        1
#define SYSTICK_EnableBit 	    0
/*********************************************/
/* bit1: Interrupt Enable bit configuration  */
/*       Enable  1                 			 */
/*       Disable 0                 			 */
#define SYSTICK_TickInt         0
#define SYSTICK_TickIntBit      1
/*********************************************/
/* bit2: Clock Source bit configuration      */
/*       AHB   1                 			 */
/*       AHB/8 0            				 */
#define SYSTICK_ClockSource     0
#define SYSTICK_ClockSourceBit  2
/*********************************************/
/* bit16: Interrupt Flag bit configuration   */
/*Returns 1 if timer counted to 0 since last */
/* time this was read.						 */
#define SYSTICK_CountFlag       1
#define SYSTICK_CountFlagBit    16

/*Pre-Load configurations*/
#define PreloadEnable           0
#define Preload_Value           10000
#define Preload_Immediate		1



#endif /* __SYSTICK_CONF_H */
