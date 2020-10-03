/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : IR DRIVER                        */
/*   DATE        : 4 SEP 2020                       */
/*   VERSION     : V01                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_IR_PRIV_H_
#define HAL_IR_PRIV_H_

volatile u8 Global_u8StartFlag=0;
volatile u32 Global_u32FrameData [50];
volatile u8  Global_u8Counter=0;
volatile u8 Global_u8Data =0;

#define  EQ       7
#define  VolUp    9
#define  VolDn    21
#define  USD      13
#define  RPT      25
#define  Power    69
#define  Mute     71
#define  Play     68
#define  Previous 64
#define  Next     67
#define  Mode     70
#define  B0       22
#define  B1       12
#define  B2		  24
#define  B3		  94
#define  B4  	  8
#define  B5    	  28
#define  B6		  90
#define  B7   	  66
#define  B8		  82
#define  B9		  74

#endif
