/****************************************************/
/* 				Library Directives 					*/
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/FBEC/FPEC_interface.h"
#include "../include/MCAL/FBEC/FPEC_private.h"
#include "../include/MCAL/FBEC/FPEC_config.h"


//void MFPEC_voidInit(void)
//{
//	MRCC_voidChangeSystemClock(MRCC_HSI);
//}

void MFPEC_voidEraseAppArea(void)
{
	u8 i;

	/*	HSI Must be enabled and selected	*/

	for (i = MFPEC_SIZE_BL; i < MFPEC_SIZE_FLASH; i++)
	{
		MFPEC_voidFlashPageErase(i);
	}
}

void MFPEC_voidFlashPageErase(u8 Copy_u8PageNumber)
{
	/* Wait Busy Flag */
	while (GET_BIT(MFPEC->SR,0) == 1);

	/* Check if MFPEC is locked or not */
	if ( GET_BIT(MFPEC->CR,7) == 1)
	{
		MFPEC -> KEYR = 0x45670123;
		MFPEC -> KEYR = 0xCDEF89AB;
	}

	/* Page Erase Operation */
	SET_BIT(MFPEC->CR,1);

	/* Write Page address */
	MFPEC -> AR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000 ;

	/* Start operation */
	SET_BIT(MFPEC->CR,6);

	/* Wait Busy Flag */
	while (GET_BIT(MFPEC->SR,0) == 1);

	/* EOP */
	SET_BIT(MFPEC->SR,5);
	CLR_BIT(MFPEC->CR,1);
}

void MFPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length)
{
	u8 i;
	volatile u16 Temp;

	while (GET_BIT(MFPEC->SR,0) == 1);

	/* Check if MFPEC is locked or not */
	if ( /* MFPEC_CR->BitAccess.LOCK == 1 */ GET_BIT(MFPEC->CR,7) == 1 )
	{
		MFPEC -> KEYR = 0x45670123;
		MFPEC -> KEYR = 0xCDEF89AB;
	}


	for (i = 0; i< Copy_u8Length; i++)
	{
		/* Write Flash Programming */
		SET_BIT(MFPEC->CR,0);

		/* Half word operation */

		Temp = Copy_u16Data[i];
		*((volatile u16*)Copy_u32Address) = Copy_u16Data[i];
		Copy_u32Address += 2 ;

		/* Wait Busy Flag */
//		while (GET_BIT(MFPEC->SR,0) == 1);

		/* EOP */
		SET_BIT(MFPEC->SR,5);
		CLR_BIT(MFPEC->CR,0);
	}

}


