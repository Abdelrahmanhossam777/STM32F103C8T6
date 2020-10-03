/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : GPIO DRIVER                      */
/*   DATE        : 22 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_PRIV_H
#define __GPIO_PRIV_H

#define GPIO_ResetMask (0b1111)
/**************************************************/
/* Description : Definitions for GPIO Base Address */
/**************************************************/
#define GPIOA ((volatile GPIOX*) 0x40010800)
#define GPIOB ((volatile GPIOX*) 0x40010C00)
#define GPIOC ((volatile GPIOX*) 0x40011000)

/********************************************************/
/* Description : GPIO Registers mapping using structure */
/********************************************************/
typedef struct
{
	/*Port configuration register low*/
	volatile u32 GPIO_CRL;
	/*Port configuration register high*/
	volatile u32 GPIO_CRH;
	/*Port input data register*/
	volatile u32 GPIO_IDR;
	/*Port output data register*/
	volatile u32 GPIO_ODR;
	/*Port bit set/reset register*/
	volatile u32 GPIO_BSRR;
	/*Port bit reset register*/
	volatile u32 GPIO_BRR;
	/*Port configuration lock register*/
	volatile u32 GPIO_LCKR;
}GPIOX;

/********************************************************/
/* Description : GPIO PINS Definition					*/
/********************************************************/
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8
#define PIN9  9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

#define LCKK         16
#define GPIO_Lock    1
#define GPIO_Unlock  0

#define GPIO_PORTA 1
#define GPIO_PORTB 2
#define GPIO_PORTC 3

/********************************************************/
/* Description : GPIO Direction Modes Definition		*/
/********************************************************/
#define Input        0
#define Output_10MHz 1
#define Output_2MHz  2
#define Output_50MHz 3

/********************************************************/
/* Description : GPIO Input Modes Definition     		*/
/********************************************************/
#define Analog         0
#define Floating_Input 1
#define Pull_Input     2

/********************************************************/
/* Description : GPIO Output Modes Definition     		*/
/********************************************************/
#define General_PushPull  0
#define General_OpenDrain 1
#define AF_PushPull       2
#define AF_OpenDrain      3

/*****************************************/
/* 			    Input Modes				 */
/*****************************************/
#define Input_Analog      0b0000
#define Input_Floating    0b0100
#define Input_Pull        0b1000

/*****************************************/
/* 			    Output Modes			 */
/*****************************************/
#define Output10_PushPull    0b0001
#define Output10_OpenDrain   0b0101
#define Output10_AFPushPull  0b1001
#define Output10_AFOpenDrain 0b1101

#define Output2_PushPull     0b0010
#define Output2_OpenDrain    0b0110
#define Output2_AFPushPull   0b1010
#define Output2_AFOpenDrain  0b1110

#define Output50_PushPull    0b0011
#define Output50_OpenDrain   0b0111
#define Output50_AFPushPull  0b1011
#define Output50_AFOpenDrain 0b1111


#define IOPA       1<<2
#define IOPB       1<<3
#define IOPC       1<<4
#define IOPD       1<<5

typedef u8 ErrorStatus;

#endif /* __GPIO_PRIV_H */
