/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : RCC DRIVER                       */
/*   DATE        : 15 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_RCC_conf_H
#define _MCAL_RCC_conf_H

/* This refers to the current clock required to work on       */
/* Options Available for the system clock ( HSE , HSI , PLL ) */
#define ClkSource HSE

/*This will refer to the PLL input clock source*/
/* Options Available for the system clock ( HSE_Src , HSI_Src , HSI2_Src ) */
#define PLL_Source HSE_Src

#define HSE_Src   0
#define HSI_Src   1

/*PLL Source bit value for masking  */
#define Src_bit  32768


/***************************************************************************
Bits 3:0
0000: PREDIV1 input clock not divided
0001: PREDIV1 input clock divided by 2
0010: PREDIV1 input clock divided by 3
0011: PREDIV1 input clock divided by 4
0100: PREDIV1 input clock divided by 5
0101: PREDIV1 input clock divided by 6
0110: PREDIV1 input clock divided by 7
0111: PREDIV1 input clock divided by 8
1000: PREDIV1 input clock divided by 9
1001: PREDIV1 input clock divided by 10
1010: PREDIV1 input clock divided by 11
1011: PREDIV1 input clock divided by 12
1100: PREDIV1 input clock divided by 13
1101: PREDIV1 input clock divided by 14
1110: PREDIV1 input clock divided by 15
1111: PREDIV1 input clock divided by 16
 *****************************************************************************/
#define inputDivisionFactor 0
#define divisionfactor_ResetMask (~0x8)

/***************************************************************************
Bits 21:18
000x: Reserved
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
10xx: Reserved
1100: Reserved
1101: PLL input clock x 6.5
111x: Reserved
Caution: The PLL output frequency must not exceed 72 MHz
*****************************************************************************/
/* X 4 */
#define PLL_Prescaler 524288
#define Prescaler_ResetMask (~0x780000)

#endif /* __RCC_conf_H */
