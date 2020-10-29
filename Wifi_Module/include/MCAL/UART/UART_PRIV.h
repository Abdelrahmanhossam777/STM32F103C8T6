/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : UART DRIVER                      */
/*   DATE        : 20 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_UART_PRIV_H
#define _MCAL_UART_PRIV_H


typedef struct
{
	/* Status register (USART_SR) */
	volatile u32 USART_SR;
    /* Data register (USART_DR) */
	volatile u32 USART_DR;
    /* Baud rate register (USART_BRR) */
	volatile u32 USART_BRR;
	/* Control register 1 (USART_CR1) */
	volatile u32 USART_CR1;
	/* Control register 2 (USART_CR2) */
	volatile u32 USART_CR2;
	/* Control register 3 (USART_CR3) */
	volatile u32 USART_CR3;
    /* Guard time and prescaler register (USART_GTPR) */
	volatile u32 USART_GTPR;
}USART_t;

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}USART_Register;


#define 	USART1 		((USART_Register *) 0x40013800)
/*************************************************************************************************/
/*Bit 13 UE: USART enable																		 */
/*When this bit is cleared the USART prescaler and outputs are stopped and the end of the current*/
/*byte transfer in order to reduce power consumption. This bit is set and cleared by software.	 */
/*0: USART prescaler and outputs disabled														 */
/*1: USART enabled																				 */
/*************************************************************************************************/
#define UE_Bit 13
/************************************************************************************************/

/***********************************************************************************************/
/*Bit 12 M: Word length																		   */
/*This bit determines the word length. It is set or cleared by software.					   */
/*0: 1 Start bit, 8 Data bits, n Stop bit													   */
/*1: 1 Start bit, 9 Data bits, n Stop bit													   */
/*Note: The M bit must not be modified during a data transfer (both transmission and reception)*/
/***********************************************************************************************/
#define M_Bit 12
/***********************************************************************************************/

/**********************************************************************************************/
/*Bit 11 WAKE: Wakeup method																  */
/*This bit determines the USART wakeup method, it is set or cleared by software.		      */
/*0: Idle Line																				  */
/*1: Address Mark																			  */
/**********************************************************************************************/
#define WAKE_Bit 11
/**********************************************************************************************/

/****************************************************************************************************/
/*Bit 10 PCE: Parity control enable																	*/
/*This bit selects the hardware parity control (generation and detection). When the parity			*/
/*control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit  */
/*if M=0) and parity is checked on the received data. This bit is set and cleared by software.      */
/*Once it is set, PCE is active after the current byte (in reception and in transmission).			*/
/*0: Parity control disabled																		*/
/*1: Parity control enabled																			*/
/****************************************************************************************************/
#define PCE_Bit 10
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 9 PS: Parity selection																	    */
/*This bit selects the odd or even parity when the parity generation/detection is enabled (PCE      */
/*bit set). It is set and cleared by software. The parity will be selected after the current byte.  */
/*0: Even parity																					*/
/*1: Odd parity																						*/
/****************************************************************************************************/
#define PS_Bit 9
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 8 PEIE: PE interrupt enable																	*/
/*This bit is set and cleared by software.														    */
/*0: Interrupt is inhibited																			*/
/*1: A USART interrupt is generated whenever PE=1 in the USART_SR register							*/
/****************************************************************************************************/
#define PEIE_Bit 8
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 7 TXEIE: TXE interrupt enable																	*/
/*This bit is set and cleared by software.															*/
/*0: Interrupt is inhibited																		    */
/*1: A USART interrupt is generated whenever TXE=1 in the USART_SR register							*/
/****************************************************************************************************/
#define TXEIE_Bit 7
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 6 TCIE: Transmission complete interrupt enable												*/
/*This bit is set and cleared by software.															*/
/*0: Interrupt is inhibited																			*/
/*1: A USART interrupt is generated whenever TC=1 in the USART_SR register							*/
/****************************************************************************************************/
#define TCIE_Bit 6
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 5 RXNEIE: RXNE interrupt enable																*/
/*This bit is set and cleared by software.															*/
/*0: Interrupt is inhibited																			*/
/*1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register				*/
/****************************************************************************************************/
#define RXNEIE_Bit 5
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 4 IDLEIE: IDLE interrupt enable																*/
/*This bit is set and cleared by software.														    */
/*0: Interrupt is inhibited																			*/
/*1: A USART interrupt is generated whenever IDLE=1 in the USART_SR register						*/
/****************************************************************************************************/
#define IDLEIE_Bit 4
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 3 TE: Transmitter enable																		*/
/*This bit enables the transmitter. It is set and cleared by software.								*/
/*0: Transmitter is disabled																		*/
/*1: Transmitter is enabled																			*/
/*Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble	*/
/*(idle line) after the current word, except in Smartcard mode.										*/
/*2: When TE is set there is a 1 bit-time delay before the transmission starts.						*/
/****************************************************************************************************/
#define TE_Bit 3
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 2 RE: Receiver enable																			*/
/*This bit enables the receiver. It is set and cleared by software.									*/
/*0: Receiver is disabled																			*/
/*1: Receiver is enabled and begins searching for a start bit										*/
/****************************************************************************************************/
#define RE_Bit 2
/****************************************************************************************************/


/****************************************************************************************************/
/*Bit 1 RWU: Receiver wakeup																		*/
/*This bit determines if the USART is in mute mode or not. It is set and cleared by software and	*/
/*can be cleared by hardware when a wakeup sequence is recognized.									*/
/*0: Receiver in active mode																		*/
/*1: Receiver in mute mode																			*/
/*Note: 1: Before selecting Mute mode (by setting the RWU bit) the USART must first receive a		*/
/*data byte, otherwise it cannot function in Mute mode with wakeup by Idle line detection.			*/
/*2: In Address Mark Detection wakeup configuration (WAKE bit=1) the RWU bit cannot					*/
/*be modified by software while the RXNE bit is set.												*/
/****************************************************************************************************/
#define RWU_Bit 1
/****************************************************************************************************/

/****************************************************************************************************/
/*Bit 0 SBK: Send break																				*/
/*This bit set is used to send break characters. It can be set and cleared by software. It should	*/
/*be set by software, and will be reset by hardware during the stop bit of break.					*/
/*0: No break character is transmitted																*/
/*1: Break character will be transmitted															*/
/****************************************************************************************************/
#define SBK_Bit 0
/****************************************************************************************************/


#endif
