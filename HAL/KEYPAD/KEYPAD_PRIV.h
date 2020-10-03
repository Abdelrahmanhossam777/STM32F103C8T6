/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : KB DRIVER                        */
/*   DATE        : 15 AGU 2020                      */
/*   VERSION     : V02                              */
/****************************************************/

/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_KEYPAD_KDB_PRIV_H_
#define HAL_KEYPAD_KDB_PRIV_H_


/********************** 			 Macros            *********************/
/* ROWS AND COLUMNS NUMBER */
#define KBD_ROW_NUM    4
#define KBD_COL_NUM    4

/* Hardware port that keyDIO_PINd is attached to */
#define KBD_PORT_HW   GPIO_PORTB

/* Rows and Columns PINS  */
#define KBD_ROW_0     PIN8
#define KBD_ROW_1     PIN9
#define KBD_ROW_2     PIN10
#define KBD_ROW_3     PIN11

#define KBD_COL_0     PIN12
#define KBD_COL_1     PIN13
#define KBD_COL_2     PIN14
#define KBD_COL_3     PIN15



/* Pressed and released values */
#define KBD_KEY_PRESSED   0
#define KBD_KEY_RELEASED  1

/*********************************************************************************************************************************/


#endif /* HAL_KEYPAD_KDB_PRIV_H_ */
