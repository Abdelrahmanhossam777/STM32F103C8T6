/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SPI DRIVER                       */
/*   DATE        : 16 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_SPI_conf_H
#define _MCAL_SPI_conf_H


#define Slave_Select  PIN0,GPIO_PORTA


/******************************************************/
/* Bit 15 BIDIMODE: Bidirectional data mode enable    */
/* 0: 2-line unidirectional data mode selected        */
/* 1: 1-line bidirectional data mode selected         */
/******************************************************/
#define BIDIMODE     0
/******************************************************/

/*******************************************************/
/* Bit 14 BIDIOE: Output enable in bidirectional mode  */
/* This bit combined with the BIDImode bit selects the */
/* direction of transfer in bidirectional mode         */
/* 0: Output disabled (receive-only mode)              */
/* 1: Output enabled (transmit-only mode)              */
/*******************************************************/
#define BIDIOE     0
/*******************************************************/


/*******************************************************/
/* Bit 14 CRCEN: Hardware CRC calculation enable       */
/* 0: CRC calculation disabled			               */
/* 1: CRC calculation enabled			               */
/*******************************************************/
#define CRCEN     0
/******************************************************/


/*******************************************************/
/* Bit 12 CRCNEXT: CRC transfer next				   */
/* 0: Data phase (no CRC phase)                        */
/* 1: Next transfer is CRC (CRC phase)                 */
/*******************************************************/
#define CRCNEXT     0
/******************************************************/


/**********************************************************************/
/* Bit 11 DFF: Data frame format									  */
/* 0: 8-bit data frame format is selected for transmission/reception  */
/* 1: 16-bit data frame format is selected for transmission/reception */
/**********************************************************************/
#define DFF     0
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
#define RXONLY     0
/**********************************************************************/

/**********************************************************************/
/* Bit 9 SSM: Software slave management								  */
/* When the SSM bit is set, the NSS pin input is replaced with the    */
/* value from the SSI bit.											  */
/* 0: Software slave management disabled							  */
/* 1: Software slave management enabled								  */
/**********************************************************************/
#define SSM     1
/**********************************************************************/

/**********************************************************************/
/* Bit 8 SSI: Internal slave select                                   */
/* This bit has an effect only when the SSM bit is set. The value of  */
/* this bit is forced onto the                                        */
/* NSS pin and the IO value of the NSS pin is ignored.                */
/**********************************************************************/
#define SSI     1
/**********************************************************************/

/**********************************************************************/
/* Bit 7 LSBFIRST: Frame format										  */
/* 0: MSB transmitted first											  */
/* 1: LSB transmitted first											  */
/* Note: This bit should not be changed when communication is ongoing.*/
/**********************************************************************/
#define LSBFIRST     0
/**********************************************************************/

/**********************************************************************/
/* Bit 6 SPE: SPI enable											  */
/* 0: Peripheral disabled											  */
/* 1: Peripheral enabled											  */
/**********************************************************************/
#define SPE     1
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
#define BR2     0
#define BR1     0
#define BR0     0
/**********************************************************************/

/**********************************************************************/
/* Bit 2 MSTR: Master selection										  */
/* 0: Slave configuration											  */
/* 1: Master configuration											  */
/**********************************************************************/
#define MSTR     1
/**********************************************************************/

/**********************************************************************/
/* Bit1 CPOL: Clock polarity										  */
/* 0: CK to 0 when idle												  */
/* 1: CK to 1 when idle												  */
/**********************************************************************/
#define CPOL     1
/**********************************************************************/

/**********************************************************************/
/* Bit 0 CPHA: Clock phase											  */
/* 0: The first clock transition is the first data capture edge		  */
/* 1: The second clock transition is the first data capture edge      */
/**********************************************************************/
#define CPHA     1
/**********************************************************************/



#endif /* _MCAL_SPI_conf_H */
