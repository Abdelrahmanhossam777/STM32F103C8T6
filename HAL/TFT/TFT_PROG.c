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
#include "../include/HAL/TFT/TFT_INT.h"
#include "../include/HAL/TFT/TFT_PRIV.h"
#include "../include/HAL/TFT/TFT_CONF.h"

static void TFT_voidWriteCommand (u8 copy_u8Command)
{
	u8 local_u8ecieved;
	/*set TFT_A0 to low*/
	GPIO_ErrorStatusSetPinValue(TFT_A0,Low);
	/* send Command over SPI */
	SPI1_voidTransceiverSYNC(copy_u8Command,& local_u8ecieved);
}

static void TFT_voidWriteData (u8 copy_u8Data)
{
	u8 local_u8ecieved;
	/*set TFT_A0 to High*/
	GPIO_ErrorStatusSetPinValue(TFT_A0,High);
	/* send Data over SPI */
	SPI1_voidTransceiverSYNC(copy_u8Data,& local_u8ecieved);
}

void TFT_voidInitPins(void)
{
	GPIO_ErrorStatusSetPinMode(TFT_RST,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(TFT_A0,Output2_PushPull);
	GPIO_ErrorStatusSetPinMode(TFT_CLK,Output10_AFPushPull);
	GPIO_ErrorStatusSetPinMode(TFT_Data,Output10_AFPushPull);
}
void TFT_voidinit(void)
{
	/* Reset Valued to init the TFT */
	GPIO_ErrorStatusSetPinValue(TFT_RST,High);
	SYSTICK_voidSetBusyWait(100);
	GPIO_ErrorStatusSetPinValue(TFT_RST,Low);
	SYSTICK_voidSetBusyWait(1);
	GPIO_ErrorStatusSetPinValue(TFT_RST,High);
	SYSTICK_voidSetBusyWait(100);
	GPIO_ErrorStatusSetPinValue(TFT_RST,Low);
	SYSTICK_voidSetBusyWait(100);
	GPIO_ErrorStatusSetPinValue(TFT_RST,High);
	SYSTICK_voidSetBusyWait(120000);

	TFT_voidWriteCommand(0x11);
	SYSTICK_voidSetBusyWait(150000);
	TFT_voidWriteCommand(0x3A);
	TFT_voidWriteData(0x05);
	TFT_voidWriteCommand(0x29);
	TFT_voidWriteCommand(0x36);//Remap TFT addresses ( x = 0 , y = 0 Start From The Left Top Of The TFT ) mn 8er el command da kan x = 0 , y = 0 kan bad2a mn ta7t 3la el yemen
	TFT_voidWriteData( 0xC0 );

}
void TFT_voidDisplayImage (const u16 * copy_u16Image)
{
	u16 local_u16counter;
	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);

	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);

	/* RAM Write */
	TFT_voidWriteCommand(0x2C);
	for (local_u16counter=0; local_u16counter<20480; local_u16counter++)
	{
		/* write the High byte */
		TFT_voidWriteData(copy_u16Image[local_u16counter]>>8);
		/* write the low byte */
		TFT_voidWriteData(copy_u16Image[local_u16counter]& 0xFF);
	}

}




void TFT_voidDisplayColor (const u16  copy_u16Color)
{
	u16 local_u16counter;
	u8  local_u8Color;
	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);

	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);

	/* RAM Write */
	TFT_voidWriteCommand(0x2C);
	for (local_u16counter=0; local_u16counter<20480; local_u16counter++)
	{
		/* write the High byte */
		TFT_voidWriteData(copy_u16Color>>8);
		/* write the low byte */
		TFT_voidWriteData(copy_u16Color& 0xFF);
	}

}

void TFT_voidDrawRectangle (u8 copy_u8X1, u8 copy_u8X2, u8 copy_u8Y1, u8 copy_u8Y2, const u16  copy_u16Color)
{
	u16 local_u16counter;
	u16 local_u16Size=(copy_u8X2-copy_u8X1)*(copy_u8Y2-copy_u8Y1);
	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8X1);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8X2);

	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8Y1);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8Y2);

	/* RAM Write */
	TFT_voidWriteCommand(0x2C);
	for (local_u16counter=0; local_u16counter<local_u16Size; local_u16counter++)
	{
		/* write the High byte */
		TFT_voidWriteData(copy_u16Color>>8);
		/* write the low byte */
		TFT_voidWriteData(copy_u16Color& 0xFF);
	}

}

void TFT_voidDrawChar (u8 copy_u8X1, u8 copy_u8Y1, const u16  copy_u16Color, const u8 * ptr )
{
	u16 local_u16counter;
	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8X1);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8X1+4);

	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8Y1);
	TFT_voidWriteData(0);
	TFT_voidWriteData(copy_u8Y1+6);

	/* RAM Write */
	TFT_voidWriteCommand(0x2C);
	for (local_u16counter=0; local_u16counter<35; local_u16counter++)
	{

			if (ptr[local_u16counter]==0)
			{
				/* write the High byte */
				TFT_voidWriteData((0x0000)>>8);
				/* write the low byte */
				TFT_voidWriteData((0x000)& 0xFF);
			}
			else
			{
				/* write the High byte */
				TFT_voidWriteData(copy_u16Color>>8);
				/* write the low byte */
				TFT_voidWriteData(copy_u16Color& 0xFF);}
		}


}





void HTFT_voidDisplayChar(u8 * Cop_u8Char , u8 Copy_Xaxis , u8 Copy_Yaxis , u16 Copy_u16Color){

	u8 LOC_u8Mask = 0x01  ;
	u16 LOC_u8Pixel       ;
	u8 LOC_u8DataMasked   ;

	for(u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 5 ; LOC_u8Iterator1++ ){



		for(u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < 7 ; LOC_u8Iterator2++ ){

			TFT_voidWriteCommand(0x2A);

			TFT_voidWriteData( 0 );
			TFT_voidWriteData( Copy_Xaxis +  LOC_u8Iterator1 );
			TFT_voidWriteData( 0 );
			TFT_voidWriteData( Copy_Xaxis +  LOC_u8Iterator1 );

			TFT_voidWriteCommand(0x2B);

			TFT_voidWriteData( 0 );
			TFT_voidWriteData( Copy_Yaxis +  LOC_u8Iterator2 );
			TFT_voidWriteData( 0 );
			TFT_voidWriteData( Copy_Yaxis +  LOC_u8Iterator2 );

			TFT_voidWriteCommand(0x2C);

			LOC_u8DataMasked = Cop_u8Char[ LOC_u8Iterator1 ] & LOC_u8Mask ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x0000        ; }
			else                         { LOC_u8Pixel = Copy_u16Color ; }

			TFT_voidWriteData ( LOC_u8Pixel >> 8   ); // write hi byte
			TFT_voidWriteData ( LOC_u8Pixel & 0xFF ); // write lo byte

			LOC_u8Mask <<= 1 ;


		}

		LOC_u8Mask = 0x01 ;

	}


}
