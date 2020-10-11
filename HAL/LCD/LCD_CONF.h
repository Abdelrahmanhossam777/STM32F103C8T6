/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : LCD DRIVER                       */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/
/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef HAL_LCD_CONF_H_
#define HAL_LCD_CONF_H_

/*********************************************/
/*         control pins configuration 		 */
/*********************************************/
#define LCD_u8RS    PIN0,GPIO_PORTA
#define LCD_u8RW	PIN1,GPIO_PORTA
#define LCD_u8EN	PIN2,GPIO_PORTA

/*********************************************/
/*          Data Pins configuration 		 */
/*********************************************/
#define LCD_u8DATA_0    PIN3,GPIO_PORTA
#define LCD_u8DATA_1	PIN4,GPIO_PORTA
#define LCD_u8DATA_2	PIN5,GPIO_PORTA
#define LCD_u8DATA_3	PIN6,GPIO_PORTA
#define LCD_u8DATA_4	PIN7,GPIO_PORTA
#define LCD_u8DATA_5	PIN8,GPIO_PORTA
#define LCD_u8DATA_6	PIN9,GPIO_PORTA
#define LCD_u8DATA_7	PIN10,GPIO_PORTA

#define LCD_Data_PORT   GPIO_PORTA
#define LCD_CNT_PORT    DIO_PORTD

/****************************/
/*    END OF FILE GUARD     */
/****************************/
#endif /* HAL_LCD_CONF_H_ */
