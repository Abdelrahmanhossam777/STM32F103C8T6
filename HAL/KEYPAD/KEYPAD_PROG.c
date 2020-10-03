/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : KB DRIVER                        */
/*   DATE        : 19 FEB 2020                      */
/*   VERSION     : V02                              */
/****************************************************/

/*********************************************************************************************************************************/

#include "../include/LIB/LIB.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include"../include/MCAL/RCC/RCC_INT.h"
#include"../include/MCAL/RCC/RCC_PRIV.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include "../include/HAL/KEYPAD/KEYPAD_INT.h"
#include "../include/HAL/KEYPAD/KEYPAD_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_INT.h"

/*********************************************************************************************************************************/
/*Global Array to define the Keypad rows connected to which micro pins */
u8 KBD_u8Rows[KBD_ROW_NUM] = {PIN8, PIN9, PIN10, PIN11};

/*Global Array to define the Keypad Columns connected to which micro pins */
u8 KBD_u8Cols[KBD_COL_NUM] = {PIN12, PIN13, PIN14,PIN15};

/*Global Array to define what each key in the key pad refers to */
u8 KBD_u8Keys[KBD_ROW_NUM][KBD_COL_NUM] = {
	                                    	{ 1, 2, 3},
				                        	{ 4, 5, 6},
				                        	{ 7, 8, 9},
											{ 0, 0, 0}
                                          };
/*********************************************************************************************************************************/
/* Initialization to set the keypad pins and ports */
 void KBD_voidInitialization (void)
{
	/* This instruction is to set half of pins to be input ant the other half to be output */
	GPIO_ErrorStatusSetPortMode(PIN8,PIN11,KBD_PORT_HW,Input_Pull);
	GPIO_ErrorStatusSetPortMode(PIN12,PIN15,KBD_PORT_HW,Output2_PushPull);
	/* This instruction is to out high on the pins which are o/p and to switch the pull up resistors on for the i/p pins  */
	GPIO_ErrorStatusSetPortValue(PIN8,PIN15,KBD_PORT_HW,High);
}


 u8 KBD_u8GetKeyPressed (void)
{
	/* Local Variable to detect the Row index */
	u8 Local_u8RowIndex;
	/* Local Variable to detect the Column index */
	u8 Local_u8ColumnIndex;
	/* To save the value which confirms if the key is pressed or not */
	u8 Local_u8val;

	while (1)
	{

		/* The first for loop is to check on each column individually to set it as 0 */
		for (u8 i=0 ; i < KBD_COL_NUM ; i++)
			{
					/* activate only one column, then read all rows  */
					GPIO_ErrorStatusSetPinValue(KBD_u8Cols[i],KBD_PORT_HW,Low);
					/* Store the column index which is the counter of the for loop */
					Local_u8ColumnIndex=i;

					/* The second for loop is to check on each row to confirm if it is the one or not */
					for(u8 j=0; j<KBD_ROW_NUM; j++)
					{
						/* Get the value of the row to check if it is pressed or not */
						Local_u8val = GPIO_u8GetPin(KBD_u8Rows[j],KBD_PORT_HW);
						/*This delay is to fix The bouncing Effect  */
						//delay_ms(20);
						SYSTICK_voidSetBusyWait(20000);
						/* Get the value again to make sure it is right after avoiding The Debouncing Effect  */
						Local_u8val = GPIO_u8GetPin(KBD_u8Rows[j],KBD_PORT_HW);
						/* Store the row index which is the counter of the for loop */
						Local_u8RowIndex = j;

						/* Check if the key is pressed or not by getting the pin value of the row */
						if (Local_u8val==KBD_KEY_PRESSED)
						{
							/* Return a value from the global array  */
							return KBD_u8Keys[Local_u8RowIndex][Local_u8ColumnIndex];
						}
					}

					/* Deactivate the column again, to activate another column in the next iteration  */
					GPIO_ErrorStatusSetPinValue(KBD_u8Cols[i],KBD_PORT_HW,High);

			}
	}
}

/*********************************************************************************************************************************/

