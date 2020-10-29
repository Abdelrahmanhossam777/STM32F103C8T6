#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

#define UNLOCK_KEY1			(0x45670123)
#define UNLOCK_KEY2			(0xCDEF89AB)

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
}MFPEC_TYPE;

#define MFPEC ((MFPEC_TYPE*)0x40022000)


#endif
