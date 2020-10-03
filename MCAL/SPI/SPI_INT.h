/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SPI DRIVER                       */
/*   DATE        : 16 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_SPI_INT_H
#define _MCAL_SPI_INT_H

void SPI1_voidInit(void);

void SPI1_voidTransceiver (u8 copy_u8Data, u8* copy_u8RecivedData);

void SPI1_voidSetCallBack (void (*ptr) (u8));

void SPI1_voidTransceiverASYNC (u8 copy_u8Data, void (*Callback) (u8));
#endif /* _MCAL_SPI_INT_H */
