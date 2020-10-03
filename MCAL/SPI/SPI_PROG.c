/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : SPI DRIVER                       */
/*   DATE        : 16 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/



/****************************************/
/* 			     Directives 			*/
/****************************************/
#include "../include/LIB/LIB.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/SPI/SPI_INT.h"
#include "../include/MCAL/SPI/SPI_PRIV.h"
#include "../include/MCAL/SPI/SPI_CONF.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include"../include/MCAL/RCC/RCC_INT.h"
#include"../include/MCAL/RCC/RCC_PRIV.h"

void SPI1_voidInit(void)
{
  RCC_vidSetPeripheralclock(APB2,SPI1EN,ON);
  SPI1->SPI_CR1= (  (BIDIMODE << BIDIMODE_bit)  | (BIDIOE << BIDIOE_bit) | (CRCEN << CRCEN_bit) | (CRCNEXT << CRCNEXT_bit)
		          | (DFF      << DFF_bit)       | (RXONLY << RXONLY_bit) | (SSM   << SSM_bit)   |  (SSI    << SSI_bit)
				  | (LSBFIRST << LSBFIRST_bit)  | (SPE    << SPE_bit)    | (BR2   << BR2_bit)   | (BR1     << BR1_bit)
				  | (BR0      << BR0_bit)       | (MSTR   << MSTR_bit)   | (CPOL  << CPOL_bit)  | (CPHA    << CPHA_bit)    );

}


void SPI1_voidTransceiverSYNC (u8 copy_u8Data, u8* copy_u8RecivedData)
{
	/* Activate the Slave select line */
	GPIO_ErrorStatusSetPinValue(Slave_Select,Low);

	/* Write the data to be sent in the register */
	SPI1->SPI_DR=copy_u8Data;

	/* Waiting tell the transmitting and receiving end */
	while (GET_BIT(SPI1->SPI_SR,BusyFlag)==1);

	/* Read the received Data */
	*copy_u8RecivedData=SPI1->SPI_DR;

	/* Deactivate the Slave select line */
	GPIO_ErrorStatusSetPinValue(Slave_Select,High);
}

void SPI1_voidSetCallBack (void (*ptr) (u8))
{
	//ptr_CallBack=ptr;
}

void SPI1_voidTransceiverASYNC (u8 copy_u8Data, void (*Callback) (u8))
{
	/* Activate the Slave select line */
	GPIO_ErrorStatusSetPinValue(Slave_Select,Low);

	/* Write the data to be sent in the register */
	SPI1->SPI_DR=copy_u8Data;
	/* set the callback function to the ISR Handler */
	SPI1_voidSetCallBack (Callback);

}

SPI_IRQHandler(void)
{
	//ptr_CallBack();
}


void ReadData (u8 *copy_u8RecivedData)
{
	/* Read the received Data */
	*copy_u8RecivedData=SPI1->SPI_DR;

	/* Deactivate the Slave select line */
	GPIO_ErrorStatusSetPinValue(Slave_Select,High);
}

