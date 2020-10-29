/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : LIB		                        */
/*   DATE        : 22 JUL 2020                      */
/*   VERSION     : V01                              */
/****************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LIB_H
#define __LIB_H
#include "STD_TYPES.h"
/**************************************************/
/*Description: Definitions for Error Status       */
/**************************************************/
typedef u8 ErrorStatus;
#define NotOk      0
#define OK         1
#define OutOfRange 2


/**************************************************/
/* Description : Definitions for On & Off States  */
/**************************************************/
#define ON  1
#define OFF 0

/**************************************************/
/* Description : Definitions for High & Low States*/
/**************************************************/
#define High  1
#define Low   0

#define NULL  (void * )0

//#define NULL 0
#endif /* __LIB_H */
