/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : NVIC DRIVER                      */
/*   DATE        : 19 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef MCAL_NVIC_PRIV_H_
#define MCAL_NVIC_PRIV_H_


/* Window Watchdog Interrupt */
#define WWDG            0
/*PVD through EXTI Line detection Interrupt */
#define PVD    		    1
/* Tamper Interrupt*/
#define TAMPER 		    2
/* RTC global interrupt */
#define RTC    		    3
/* Flash global interrupt*/
#define FLASH  		    4
/* RCC global interrupt */
#define RCC_NVIC             5
/* EXTI Line0 interrupt */
#define EXTI0  		    6
/* EXTI Line1 interrupt */
#define EXTI1  		    7
/* EXTI Line2 interrupt */
#define EXTI2  		    8
/* EXTI Line3 interrupt */
#define EXTI3           9
/* EXTI Line4 interrupt */
#define EXTI4           10
/* DMA1 Channel1 global interrupt */
#define  DMA1_Channel1  11
/* DMA1 Channel2 global interrupt */
#define  DMA1_Channel2  12
/* DMA1 Channel3 global interrupt */
#define  DMA1_Channel3  13
/* DMA1 Channel4 global interrupt */
#define  DMA1_Channel4  14
/* DMA1 Channel5 global interrupt */
#define  DMA1_Channel5  15
/* DMA1 Channel6 global interrupt */
#define  DMA1_Channel6  16
/* DMA1 Channel7 global interrupt */
#define  DMA1_Channel7  17
/* ADC1 and ADC2 global interrupt */
#define ADC1_2          18
/* USB High Priority or CAN TX interrupts*/
#define USB_HP_CAN_TX   19
/*USB Low Priority or CAN RX0 interrupts*/
#define USB_LP_CAN_RX0  20
/* CAN RX1 interrupt */
#define CAN_RX1         21
/* CAN SCE interrupt */
#define CAN_SCE         22
/* EXTI Line[9:5] interrupts */
#define EXTI9_5         23
/* TIM1 Break interrupt */
#define TIM1_BRK	    24
/* TIM1 Update interrupt */
#define TIM1_UP         25
/* TIM1 Trigger and Commutation interrupts */
#define TIM1_TRG_COM    26
/* TIM1 Capture Compare interrupt */
#define TIM1_CC         27
/* TIM2 global interrupt */
#define TIM2		    28
/* TIM2 global interrupt */
#define TIM3		    29
/* TIM2 global interrupt */
#define TIM4		    30
/* I2C1 event interrupt */
#define I2C1_EV 	    31
/* I2C1 error interrupt */
#define I2C1_ER         32
/* I2C2 event interrupt */
#define I2C2_EV         33
/* I2C2 error interrupt */
#define I2C2_ER		    34
/* SPI1 global interrupt */
#define SPI1_INT	    35
/* SPI2 global interrupt */
#define SPI2_INT	    36
/* USART1 global interrupt */
#define USART1_INT      37
/* USART2 global interrupt */
#define USART2_INT      38
/* USART3 global interrupt */
#define USART3_INT      39
/* EXTI Line[15:10] interrupts */
#define  EXTI15_10	    40
/* RTC alarm through EXTI line interrupt */
#define RTCAlarm        41
/* USB wakeup from suspend through EXTI line interrupt */
#define USBWakeup       42
/* TIM8 Break interrupt */
#define TIM8_BRK        43
/* TIM8 Update interrupt */
#define TIM8_UP		    44
/* TIM8 Trigger and Commutation interrupts */
#define TIM8_TRG_COM    45
/* TIM8 Capture Compare interrupt */
#define TIM8_CC         46
/* ADC3 global interrupt */
#define ADC3		    47
/* FSMC global interrupt */
#define FSMC            48
/* SDIO global interrupt */
#define SDIO		    49
/* TIM5 global interrupt */
#define TIM5		    50
/* SPI3 global interrupt */
#define SPI3            51
/* UART4 global interrupt */
#define  UART4		    52
/* UART5 global interrupt */
#define  UART5		    53
/* TIM6 global interrupt */
#define TIM6            54
/* TIM7 global interrupt */
#define TIM7            55
/* DMA2 Channel1 global interrupt  */
#define DMA2_Channel1   56
/* DMA2 Channel2 global interrupt  */
#define DMA2_Channel2   57
/* DMA2 Channel3 global interrupt  */
#define DMA2_Channel3   58
/* DMA2 Channel4 and DMA2 Channel5 global interrupts */
#define DMA2_Channel4_5 59



/**************************************************/
/* Description : Definitions for NVIC Base Address*/
/**************************************************************/
//#define NVIC ((volatile NVIC_t*) 0xE000E100)
/*Interrupt set-enable registers (NVIC_ISERx)     3 Registers */
#define NVIC_ISER ((u32 *) 0xE000E100)
/*Interrupt clear-enable registers (NVIC_ICERx)   3 Registers */
#define NVIC_ICER ((u32 *) (0xE000E100 + 0x080))
/*Interrupt set-pending registers (NVIC_ISPRx)    3 Registers */
#define NVIC_ISPR ((u32 *) (0xE000E100 + 0x100))
/*Interrupt clear-pending registers (NVIC_ICPRx)  3 Registers */
#define NVIC_ICPR ((u32 *) (0xE000E100 + 0x180))
/*Interrupt active bit registers (NVIC_IABRx)     3 Registers */
#define NVIC_IABR ((u32 *) (0xE000E100 + 0x200))
/* interrupt Priority Registers (NVIC_IPRx)      20 Registers */
#define NVIC_IPR  ((u8 *)  (0xE000E100 + 0x300))
/*Application interrupt and reset control register (SCB_AIRCR)*/
#define SCB_AIRCR *((volatile u32 *) (0xE000ED00+0x0C))
/**************************************************************/


/***************************************************************************************************************************//****************/
/*             |            Interrupt priority level value, PRI_N[7:4] N            |                     |                *//****************/
/*  PRIGROUP   |     Binary point     |   Group priority bits  | Sub-priority bits  |   Group priorities  | sub priorities *//****************/
/**************|********************************************************************|***************************************//****************/
/*  0b011      |       0bxxxx		  *	         [7:4]		   *	     none       |          16               none       *//*  0x05FA0300  */
/*  0b100      |       0bxxxy         *          [7:5]         *          [4]       |          8                  2        *//*  0x05FA0400  */
/*  0b101      |       0bxxyy         *          [7:6]         *         [5:4]      |          4				  4        *//*  0x05FA0500  */
/*  0b110      |       0bxyyy         *           [7]          *         [6:4]      |          2                  8        *//*  0x05FA0600  */
/*  0b111      |       0byyyy         *          none          *         [7:4]      |         none                16       *//*  0x05FA0700  */
/***************************************************************************************************************************//****************/
/*This is to Adjust the group priority and sub priority in SCB_AIRCR                                                                         */
#define PriorityOption  0x05FA0500


/* End of the file guard */
#endif /* MCAL_NVIC_PRIV_H_ */
