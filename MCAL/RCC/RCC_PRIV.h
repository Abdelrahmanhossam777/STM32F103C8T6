/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : RCC DRIVER                       */
/*   DATE        : 15 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_RCC_PRIV_H
#define _MCAL_RCC_PRIV_H

/**************************************************/
/* Description : Definitions for On & Off States  */
/**************************************************/
#define ON  1
#define OFF 0

/**************************************************/
/* Description : Definitions for RCC Base Address */
/**************************************************/
#define RCC ((volatile RCC_t*) 0x40021000)

/**************************************************/
/* Description : Definitions for Sources of clock */
/**************************************************/
#define HSI 0
#define HSE 1
#define PLL 2

/**************************************************/
/* Description : Definitions for Sources of clock */
/**************************************************/
#define HSI_Enable 0
#define HSE_Enable (1<16)
#define PLL_Enable 16777216

/**************************************************/
/*Description: Definitions for Sources bits reset */
/**************************************************/
#define SW_Resetmask (~0x3)

/**************************************************/
/*Description: Definitions for Peripheral Buses   */
/**************************************************/
#define AHB  0
#define APB1 1
#define APB2 2

/**************************************************/
/*Description: Definitions for Peripheral         */
/**************************************************/
/**************************************************/
/********************AHB***************************/
#define ETHMACRXEN 1<<16
#define ETHMACTXEN 1<<15
#define ETHMACEN   1<<14
#define OTGFSEN    1<<12
#define CRCEN      1<<6
#define FLITFEN    1<<4
#define SRAMEN     1<<2
#define DMA2EN     1<<1
#define DMA1EN     1<<0
/**************************************************/
/********************ABP1**************************/
#define DACEN      1<<29
#define PWREN      1<<28
#define BKPEN      1<<27
#define CAN2EN     1<<26
#define CAN1EN     1<<25
#define I2C2EN     1<<22
#define I2C1EN     1<<21
#define UART5EN    1<<20
#define UART4EN    1<<19
#define USART3EN   1<<18
#define UART2EN    1<<17
#define SPI3EN     1<<15
#define SPI2EN     1<<14
#define WWDGEN     1<<11
#define TIM7EN     1<<5
#define TIM6EN     1<<4
#define TIM5EN     1<<3
#define TIM4EN     1<<2
#define TIM3EN     1<<1
#define TIM2EN     1<<0
/**************************************************/
/********************ABP2**************************/
#define AFIOEN     1<<0
#define IOPA       1<<2
#define IOPB       1<<3
#define IOPC       1<<4
#define IOPD       1<<5
#define SPI1EN     1<<12
#define USARTEN    1<<14

/********************************************************/
/* Description : RCC Registers mapping using structure  */
/********************************************************/
typedef struct
{
  /*Clock control register (RCC_CR)*/
  u32 RCC_CR;
  /*Clock configuration register (RCC_CFGR)*/
  u32 RCC_CFGR;
  /*Clock interrupt register (RCC_CIR)*/
  u32 RCC_CIR;
  /*APB2 peripheral reset register (RCC_APB2RSTR)*/
  u32 RCC_APB2RSTR;
  /*APB1 peripheral reset register (RCC_APB1RSTR)*/
  u32 RCC_APB1RSTR;
  /*AHB Peripheral Clock enable register (RCC_AHBENR)*/
  u32 RCC_AHBENR;
  /*APB2 peripheral clock enable register (RCC_APB2ENR)*/
  u32 RCC_APB2ENR;
  /*APB1 peripheral clock enable register (RCC_APB1ENR)*/
  u32 RCC_APB1ENR;
  /*Backup domain control register (RCC_BDCR)*/
  u32 RCC_BDCR;
  /*Control/status register (RCC_CSR)*/
  u32 RCC_CSR;
  /*AHB peripheral clock reset register (RCC_AHBRSTR)*/
  u32 RCC_AHBSTR;
  /*Clock configuration register2 (RCC_CFGR2)*/
  u32 RCC_CFGR2;
}RCC_t;


/**************************************************/
/*Description: Definitions for Error Status   */
/**************************************************/
#define NotOk  0
#define OK 1
#define OutOfRange 2

#endif /* __RCC_PRIV_H */
