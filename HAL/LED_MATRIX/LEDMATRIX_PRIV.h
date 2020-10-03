/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : Led Matrix DRIVER                */
/*   DATE        : 30 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _HAL_LED_MATRIX_PRIV_H
#define _HAL_LED_MATRIX_PRIV_H


void DisplayNextColumn(void);
void SetRowsValue  (u8 Copy_u8Value);
void ActivateColumn(u8 Copy_u8Col);


#endif
