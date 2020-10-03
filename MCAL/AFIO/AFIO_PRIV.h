/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : AFIO DRIVER                      */
/*   DATE        : 22 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_AFIO_PRIV_H
#define _MCAL_AFIO_PRIV_H

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_t;

/* Define a pointer to structure which points to the base address of AFIO register */
#define AFIO ((volatile AFIO_t *) 0x40010000)



#endif
