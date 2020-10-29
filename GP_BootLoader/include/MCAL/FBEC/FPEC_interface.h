#ifndef	FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

//void MFPEC_voidInit					(void);
void MFPEC_voidEraseAppArea			(void);
void MFPEC_voidFlashPageErase		(u8 Copy_u8PageNumber);
void MFPEC_voidFlashWrite			(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);



#endif
