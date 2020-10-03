/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : 7Segmant                         */
/*   DATE        : 14 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************/
/* 			     Directives 			*/
/****************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include"../include/MCAL/RCC/RCC_INT.h"
#include"../include/MCAL/RCC/RCC_PRIV.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"c
#include "../include/HAL/SEGMANT/Segmant_INT.h"
#include "../include/HAL/SEGMANT/Segmant_PRIV.h"


/******************************************************************************/
/*                Function: SevenSegmant_voidIntialization                    */
/*                I/P Parameters: u8 copy_u8SegmantType                       */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Initialize the Seven Segment                  */
/******************************************************************************/
void SevenSegmantPORT_voidIntialization (u8 copy_u8SegmantType)
{
	/* Setting the port to output */
	GPIO_ErrorStatusSetPortMode(PIN0,PIN7,SevenSegmant_Port,Output2_PushPull);
	/* turning all the segmants on based on the typr of the Seven Segmant */
	if (copy_u8SegmantType == SevenSegmant_Cathode)
	GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10111111);

	else if (copy_u8SegmantType == SevenSegmant_Anode)
	GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11000000);
}


/******************************************************************************/
/*                  Function: SevenSegmant_voidDisplayNum                     */
/*     	 I/P Parameters: u8 copy_u8SegmantType & u8 copy_u8Number             */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Display on the Seven Segment                  */
/******************************************************************************/
void SevenSegmantPORT_voidDisplayNum (u8 copy_u8SegmantType,u8 copy_u8Number)
{
	if (copy_u8SegmantType == SevenSegmant_Cathode)
		{
			switch (copy_u8Number)
			{
			  case 0 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10111111);
				  	  break;
			  case 1 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10000110);
				   	  break;
			  case 2 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11011011);
				  	  break;
			  case 3 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11001111);
			  	  	  break;
			  case 4 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11100110);
			  	  	  break;
			  case 5 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11101101);
			  	  	  break;
			  case 6 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11111101);
			  	  	  break;
			  case 7 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10000111);
			  	  	  break;
			  case 8 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11111111);
			  	  	  break;
			  case 9 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11101111);
			  	  	  break;
			  default:
				  	  break;
			}
		}
	/***************************************************************************************************/
	/***************************************************************************************************/
	/***************************************************************************************************/
		else if (copy_u8SegmantType == SevenSegmant_Anode)
		{
			switch (copy_u8Number)
			{
			  case 0 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11000000);
				  	  break;
			  case 1 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11111001);
				   	  break;
			  case 2 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,(~(0b11011011)));
				  	  break;
			  case 3 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10110000);
			  	  	  break;
			  case 4 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10011001);
			  	  	  break;
			  case 5 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10010010);
			  	  	  break;
			  case 6 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10000010);
			  	  	  break;
			  case 7 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b11111000);
			  	  	  break;
			  case 8 :
				  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10000000);
			  	  	  break;
			  case 9 :
			  	  	  GPIO_ErrorStatusSetPortDiffValues(PIN0,PIN7,SevenSegmant_Port,0b10010000);
			  	  	  break;
			  default:
			  		  break;
			}
		}
	}

