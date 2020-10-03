/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : 7Segmant                         */
/*   DATE        : 14 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/* File Guard */
#ifndef SEGMANT_INT_H_
#define SEGMANT_INT_H_


/******************************************************************************/
/*                Function: SevenSegmant_voidIntialization                    */
/*                I/P Parameters: u8 copy_u8SegmantType                       */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Initialize the Seven Segment                  */
/******************************************************************************/
void SevenSegmantPORT_voidIntialization (u8 copy_u8SegmantType);


/******************************************************************************/
/*                  Function: SevenSegmant_voidDisplayNum                     */
/*     	 I/P Parameters: u8 copy_u8SegmantType & u8 copy_u8Number             */
/*                     Returns:it returns no thing                            */
/*        	 Desc:This Function Display on the Seven Segment                  */
/******************************************************************************/
void SevenSegmantPORT_voidDisplayNum (u8 copy_u8SegmantType,u8 copy_u8Number);




#endif /* SEGMANT_PRIV_H_ */
