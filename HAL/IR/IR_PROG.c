/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : RGB DRIVER                       */
/*   DATE        : 4 SEP 2020                       */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* 				Library Directives 					*/
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
/****************************************************/
/* 				  GPIO Directives 					*/
/****************************************************/
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
/****************************************************/
/* 				    IR Directives 					*/
/****************************************************/
#include"../include/HAL/IR/IR_INT.h"
#include"../include/HAL/IR/IR_CONF.h"
#include"../include/HAL/IR/IR_PRIV.h"

/****************************************************/
/* 				 Led Matrix Directives 				*/
/****************************************************/
#include"../include/HAL/RGBLed/RGB_INT.h"
#include"../include/HAL/RGBLed/RGB_CONF.h"


/******************************************************************************/
/*Function: IR_voidInit			                         					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function Set the pin to input floating 		     		          */
/******************************************************************************/
void IR_voidInit(void)
{
	GPIO_ErrorStatusSetPinMode(PIN0,GPIO_PORTA,Input_Floating);
}

/******************************************************************************/
/*Function: IR_voidTakeAction	                         					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function reads the fram and take action depending on it	          */
/******************************************************************************/
void IR_voidTakeAction(void)
{
	/* Set the data to 0 */
	Global_u8Data=0;
	/* Set the counter to 0 */
	u8 Local_u8count=0;
	/* CHeck on the start bit for validation */
	if ( (Global_u32FrameData[0] >= 10000) && (Global_u32FrameData[0] <= 14000) )
	{
		/* loop to read the bits of data in the frame */
		for (Local_u8count = 0; Local_u8count < 8; Local_u8count++)
		{
			/* check on the bit in the frame based on time to check if 1 or 0 */
			if (Global_u32FrameData[17+Local_u8count] >= 2000 && Global_u32FrameData[17+Local_u8count] <= 2300)
			{
				/* one bit */
				SET_BIT(Global_u8Data,Local_u8count);
			}
			else
			{
				/* zero bit */
				CLR_BIT(Global_u8Data,Local_u8count);
			}
		}
   }
	else
	{

	}

	/* Function to take the action depending on the pressed button */
	IR_VoidRespond(Global_u8Data);
	/* Resetting the Global Variables */
	 Global_u8StartFlag=0;
	 Global_u32FrameData [0]=0;
	 Global_u8Counter=0;
}

/******************************************************************************/
/*Function: IR_voidGetFrame		                         					  */
/*I/P Parameters: Void														  */
/*Returns:it returns Void	                                				  */
/*Desc:This Function is the EXTI callback to get the frame			          */
/******************************************************************************/
 void IR_voidGetFrame(void)
{
	 //RGB_VoidON(GREEN);
	 /* Check on the first falling edge that means the start bit */
	 if(Global_u8StartFlag==0)
	 {
		 /* Systick one interval for one second */
		 SYSTICK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		 /* Set the flag to one so that means receive the fram */
		 Global_u8StartFlag=1;
	 }
	 else
	 {
		 /* Get the time in this frame */
		 Global_u32FrameData[Global_u8Counter]=SYSTICK_u32GetElapsedTime();
		 /* Systick one interval for one second */
		 SYSTICK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		 /* Update the counter */
		 Global_u8Counter++;

	 }

}

 /*****************************************************************************/
 /*Function: IR_VoidRespond 	                         					  */
 /*I/P Parameters: copy_u8Button											  */
 /*Returns:it returns Void	                                				  */
 /*Desc:This Function to respond to the button press				          */
 /*****************************************************************************/
void IR_VoidRespond (u8 copy_u8Button)
{
 switch (copy_u8Button) {

	/* EQ button is pressed */
 	case EQ:

			    break;
    /* Volume Up Button is pressed */
	case VolUp:

			    break;
	/* Volume Down Button is pressed */
	case VolDn:

			    break;
	/* U/SD Button is pressed */
	case USD:

			    break;
    /* RPT Button is pressed */
	case RPT:

			    break;
    /* Power Button is pressed */
	case Power:

			    break;
   /* Mute Button is pressed */
	case Mute:

			    break;
   /* Play Button is pressed */
	case Play:

			    break;
   /* Previous Button is pressed */
	case Previous:

			    break;
	/* Next Button is pressed */
	case Next:

			    break;
	/* Mode Button is pressed */
	case Mode:

			    break;
	/* Button 0 Button is pressed */
	case B0:

			 	break;
	/* Button 1 Button is pressed */
	case B1:
				RGB_VoidON(RED);
			 	break;
	/* Button 2 Button is pressed */
	case B2:
			    RGB_VoidON(BLUE);
			 	break;
	/* Button 3 Button is pressed */
	case B3:
				RGB_VoidON(GREEN);
			 	break;
	/* Button 4 Button is pressed */
	case B4:

			 	break;
	/* Button 5 Button is pressed */
	case B5:

			 	break;
    /* Button 6 Button is pressed */
	case B6:

			 	break;
	/* Button 7 Button is pressed */
	case B7:

			 	break;
	/* Button 8 Button is pressed */
	case B8:

			 	break;
	/* Button 9 Button is pressed */
	case B9:

			 	break;

	default:
				break;
}


}
