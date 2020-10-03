/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : TFT DRIVER                       */
/*   DATE        : 22 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _HAL_TFT_INT_H
#define _HAL_TFT_INT_H

void TFT_voidinit(void);
void TFT_voidDisplayImage (const u16 * copy_u16Image);
void TFT_voidInitPins(void);

void TFT_voidDisplayColor (const u16  copy_u16Color);
void TFT_voidDrawRectangle (u8 copy_u8X1, u8 copy_u8X2, u8 copy_u8Y1, u8 copy_u8Y2, const u16  copy_u16Color);
void TFT_voidDrawChar (u8 copy_u8X1, u8 copy_u8Y1, const u16  copy_u16Color, const u8 * ptr );
void HTFT_voidDisplayChar(u8 * Cop_u8Char , u8 Copy_Xaxis , u8 Copy_Yaxis , u16 Copy_u16Color);
#endif
