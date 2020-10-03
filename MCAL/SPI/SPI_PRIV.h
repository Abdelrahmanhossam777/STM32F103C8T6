/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SPI DRIVER                       */
/*   DATE        : 16 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_SPI_PRIV_H
#define _MCAL_SPI_PRIV_H

/********************************************************/
/* Description : Definitions for SPI 1 & 2 Base Address */
/********************************************************/
#define SPI1 ((volatile SPI_t*) 0x40013000)
#define SPI2 ((volatile SPI_t*) 0x40003800)


typedef struct
{
	/* SPI control register 1 (SPI_CR1) */
	volatile u32 SPI_CR1;
    /* SPI control register 2 (SPI_CR2) */
	volatile u32 SPI_CR2;
    /* SPI status register (SPI_SR) */
	volatile u32 SPI_SR;
	/* SPI data register (SPI_DR) */
	volatile u32 SPI_DR;
	/* SPI CRC polynomial register (SPI_CRCPR) */
	volatile u32 SPI_CRCPR;
	/* SPI RX CRC register (SPI_RXCRCR) */
	volatile u32 SPI_RXCRCR;
    /* SPI TX CRC register (SPI_TXCRCR) */
	volatile u32 SPI_TXCRCR;
	/* SPI_I2S configuration register (SPI_I2SCFGR) */
	volatile u32 SPI_I2SCFGR;
	/* SPI_I2S prescaler register (SPI_I2SPR) */
	volatile u32 SPI_I2SPR;

}SPI_t;

/******************************************************/
/* Bit 15 BIDIMODE: Bidirectional data mode enable    */
/* 0: 2-line unidirectional data mode selected        */
/* 1: 1-line bidirectional data mode selected         */
/******************************************************/
#define BIDIMODE_bit 15
/******************************************************/

/*******************************************************/
/* Bit 14 BIDIOE: Output enable in bidirectional mode  */
/* This bit combined with the BIDImode bit selects the */
/* direction of transfer in bidirectional mode         */
/* 0: Output disabled (receive-only mode)              */
/* 1: Output enabled (transmit-only mode)              */
/*******************************************************/
#define BIDIOE_bit 14
/*******************************************************/


/*******************************************************/
/* Bit 14 CRCEN: Hardware CRC calculation enable       */
/* 0: CRC calculation disabled			               */
/* 1: CRC calculation enabled			               */
/*******************************************************/
#define CRCEN_bit 13
/******************************************************/


/*******************************************************/
/* Bit 12 CRCNEXT: CRC transfer next				   */
/* 0: Data phase (no CRC phase)                        */
/* 1: Next transfer is CRC (CRC phase)                 */
/*******************************************************/
#define CRCNEXT_bit 12
/******************************************************/


/**********************************************************************/
/* Bit 11 DFF: Data frame format									  */
/* 0: 8-bit data frame format is selected for transmission/reception  */
/* 1: 16-bit data frame format is selected for transmission/reception */
/**********************************************************************/
#define DFF_bit 11
/**********************************************************************/

/**********************************************************************/
/* Bit 10 RXONLY: Receive only										  */
/* This bit combined with the BIDImode bit selects the direction of   */
/* transfer in 2-line                                                 */
/* unidirectional mode. This bit is also useful in a multislave system*/
/* in which this particular                                           */
/* slave is not accessed, the output from the accessed slave 		  */
/* is not corrupted.												  */
/* 0: Full duplex (Transmit and receive)                              */
/* 1: Output disabled (Receive-only mode)                             */
/**********************************************************************/
#define RXONLY_bit 10
/**********************************************************************/

/**********************************************************************/
/* Bit 9 SSM: Software slave management								  */
/* When the SSM bit is set, the NSS pin input is replaced with the    */
/* value from the SSI bit.											  */
/* 0: Software slave management disabled							  */
/* 1: Software slave management enabled								  */
/**********************************************************************/
#define SSM_bit 9
/**********************************************************************/

/**********************************************************************/
/* Bit 8 SSI: Internal slave select                                   */
/* This bit has an effect only when the SSM bit is set. The value of  */
/* this bit is forced onto the                                        */
/* NSS pin and the IO value of the NSS pin is ignored.                */
/**********************************************************************/
#define SSI_bit 8
/**********************************************************************/

/**********************************************************************/
/* Bit 7 LSBFIRST: Frame format										  */
/* 0: MSB transmitted first											  */
/* 1: LSB transmitted first											  */
/* Note: This bit should not be changed when communication is ongoing.*/
/**********************************************************************/
#define LSBFIRST_bit 7
/**********************************************************************/

/**********************************************************************/
/* Bit 6 SPE: SPI enable											  */
/* 0: Peripheral disabled											  */
/* 1: Peripheral enabled											  */
/**********************************************************************/
#define SPE_bit 6
/**********************************************************************/

/**********************************************************************/
/* Bits 5:3 BR[2:0]: Baud rate control								  */
/* 000: fPCLK/2														  */
/* 001: fPCLK/4														  */
/* 010: fPCLK/8														  */
/* 011: fPCLK/16													  */
/* 100: fPCLK/32													  */
/* 101: fPCLK/64													  */
/* 110: fPCLK/128													  */
/* 111: fPCLK/256													  */
/**********************************************************************/
#define BR2_bit 5
#define BR1_bit 4
#define BR0_bit 3
/**********************************************************************/

/**********************************************************************/
/* Bit 2 MSTR: Master selection										  */
/* 0: Slave configuration											  */
/* 1: Master configuration											  */
/**********************************************************************/
#define MSTR_bit 2
/**********************************************************************/

/**********************************************************************/
/* Bit1 CPOL: Clock polarity										  */
/* 0: CK to 0 when idle												  */
/* 1: CK to 1 when idle												  */
/**********************************************************************/
#define CPOL_bit 1
/**********************************************************************/

/**********************************************************************/
/* Bit 0 CPHA: Clock phase											  */
/* 0: The first clock transition is the first data capture edge		  */
/* 1: The second clock transition is the first data capture edge      */
/**********************************************************************/
#define CPHA_bit 0
/**********************************************************************/


#define BusyFlag 7


//static void  ( *ptr_CallBack ) (u8)= NULL;

#endif /* _MCAL_SPI_PRIV_H */
