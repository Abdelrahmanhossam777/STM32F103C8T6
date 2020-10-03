/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : Led LEDMATrix DRIVER                */
/*   DATE        : 30 AGU 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _HAL_LED_LEDMATRIX_CONF_H
#define _HAL_LED_LEDMATRIX_CONF_H

/****************************************/
/* Configuration of LED Matrix Rows		*/
/****************************************/
#define LEDMAT_ROW_0      PIN1,GPIO_PORTA
#define LEDMAT_ROW_1      PIN2,GPIO_PORTA
#define LEDMAT_ROW_2      PIN3,GPIO_PORTA
#define LEDMAT_ROW_3      PIN4,GPIO_PORTA
#define LEDMAT_ROW_4      PIN5,GPIO_PORTA
#define LEDMAT_ROW_5      PIN6,GPIO_PORTA
#define LEDMAT_ROW_6      PIN7,GPIO_PORTA
#define LEDMAT_ROW_7      PIN8,GPIO_PORTA


/****************************************/
/* Configuration of LED Matrix Columns	*/
/****************************************/
#define LEDMAT_COL_0      PIN0,GPIO_PORTB
#define LEDMAT_COL_1      PIN1,GPIO_PORTB
#define LEDMAT_COL_2      PIN5,GPIO_PORTB
#define LEDMAT_COL_3      PIN6,GPIO_PORTB
#define LEDMAT_COL_4      PIN7,GPIO_PORTB
#define LEDMAT_COL_5      PIN8,GPIO_PORTB
#define LEDMAT_COL_6      PIN9,GPIO_PORTB
#define LEDMAT_COL_7      PIN10,GPIO_PORTB


#endif
