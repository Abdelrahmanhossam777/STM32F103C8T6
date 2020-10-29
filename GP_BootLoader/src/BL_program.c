/****************************************************/
/* 				Library Directives 					*/
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/FBEC/FPEC_interface.h"

#include "../include/MCAL/BL/BL_interface.h"
#include "../include/MCAL/BL/BL_private.h"
#include "../include/MCAL/BL/BL_config.h"


u16 Data[100] = {0};
u32 Address= BL_START_ADDRESS;
/*	A function used to convert from ASCII to Hexadecimal	*/
static u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Result;
	/*	Check if the entered ASCII is from 0 to 9*/
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Result = Copy_u8Asci - 48;
	}
	/*	Else it will be all other characters (From A to Z)*/
	else
	{
		Result = Copy_u8Asci - 55;
	}

	return Result;
}


void MBL_voidParseData(volatile u8* Copy_u8BufData)
{
	u8 DigitLow,DigitHigh,CC,i;
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	u8 DataCounter = 0;
	u8 Local_u8DataParsingResult = 0;
	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_u8BufData[1]);	// Get the second digit in the record
	DigitLow  = AsciToHex (Copy_u8BufData[2]);	// Get the third digit in the record
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	DataDigit0 = AsciToHex (Copy_u8BufData[3]);	// Get the first digit of the address
	DataDigit1 = AsciToHex (Copy_u8BufData[4]);	// Get the second digit of the address
	DataDigit2 = AsciToHex (Copy_u8BufData[5]);	// Get the third digit of the address
	DataDigit3 = AsciToHex (Copy_u8BufData[6]);	// Get the forth digit of the address

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);

	for (i=0;i<CC/2; i++)
	{
		DataDigit0 = AsciToHex (Copy_u8BufData[4*i+9 ]);
		DataDigit1 = AsciToHex (Copy_u8BufData[4*i+10]);
		DataDigit2 = AsciToHex (Copy_u8BufData[4*i+11]);
		DataDigit3 = AsciToHex (Copy_u8BufData[4*i+12]);

		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		DataCounter++;
	}

//	if(CheckSum(Copy_u8BufData) == 1)
//	{
//		Local_u8DataParsingResult =	1 ;
		MFPEC_voidFlashWrite(Address,Data,CC/2);
//	}
//	else
//	{
//		Local_u8DataParsingResult = 0;
//	}
}
//
void MBL_voidParseUpperAddress(u8* Copy_u8BufData)
{
////	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
////
////	/* Get Address */
////	DataDigit0 = AsciToHex (Copy_u8BufData[3]);
////	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
////	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
////	DataDigit3 = AsciToHex (Copy_u8BufData[6]);
////
////	/* Clear Low Part of Address */
////	Address = Address & (u32)0x0000FFFF;
////	Address = Address | (u32)((u32)(DataDigit3 << 28) | (u32)(DataDigit2 << 24) | (u32)(DataDigit1 << 20) | (u32)(DataDigit0 << 16));
}

void MBL_voidParseRecord(volatile u8 * Copy_u8BufData)
{
	switch (Copy_u8BufData[8])
	{
	case '0': MBL_voidParseData(Copy_u8BufData); break;
	case '4': MBL_voidParseUpperAddress(Copy_u8BufData); break;
	}
}



static u8 CheckSum(u32 * Copy_pu32Data)
{
    u8 BoolFlag = 0;
	u8 DigitLow,DigitHigh,CC,i;
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	u8 DataCounter = 0;
    u8 DataCal[100];
    u8 AddCal[2];
    u8 Result;
    u8 CheckSum;
	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_pu32Data[1]);	// Get the second digit in the record
	DigitLow  = AsciToHex (Copy_pu32Data[2]);	// Get the third digit in the record
	CC        = (DigitHigh<<4) | DigitLow ;
    Result = CC;
	/* Get Address */
	DataDigit0 = AsciToHex (Copy_pu32Data[3]);	// Get the first digit of the address
	DataDigit1 = AsciToHex (Copy_pu32Data[4]);	// Get the second digit of the address
    AddCal[0] = (DataDigit0 <<4) | DataDigit1;
	DataDigit2 = AsciToHex (Copy_pu32Data[5]);	// Get the third digit of the address
	DataDigit3 = AsciToHex (Copy_pu32Data[6]);	// Get the forth digit of the address
    AddCal[1] = (DataDigit2 <<4) | (DataDigit3);
    Result +=AddCal[0] + AddCal[1];

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);

	for (i=0;i<CC; i++)
	{
		DataDigit0 = AsciToHex (Copy_pu32Data[2*i+9 ]);
		DataDigit1 = AsciToHex (Copy_pu32Data[2*i+10]);
        DataCal[i] = (DataDigit0 <<4) | DataDigit1;
        Result += DataCal[i];
	}

    Result = ~Result;
    Result += 1;

    CheckSum = (Copy_pu32Data[30] << 4) | (Copy_pu32Data[31]);
    if(Result == CheckSum)
    {
        BoolFlag = 1;
    }
    else
    {
        /* Do nothing */
    }

    return BoolFlag;
}

