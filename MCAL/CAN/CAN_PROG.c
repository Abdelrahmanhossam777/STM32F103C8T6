/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : CAN DRIVER                       */
/*   DATE        : 3 OCT 2020                       */
/*   VERSION     : V02                              */
/****************************************************/

/**************************************************************************************/
/* LOG:																				  */
/*	VERSION 		AUTHOR			DATE				DESCRIPTION 				  */
/* 	  01	 Abdelrahman Hossam  22 SEP, 2020		  Initial creation 				  */
/*------------------------------------------------------------------------------------*/
/*    02	 Abdullah Mustafa	 03 OCT, 2020		 - Adding the receive API		  */
/*------------------------------------------------------------------------------------*/
/**************************************************************************************/



#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include"../include/MCAL/CAN/CAN_INIT.h"
#include"../include/MCAL/CAN/CAN_CONF.h"
#include"../include/MCAL/CAN/CAN_PRIV.h"
#include"../include/MCAL/RCC/RCC_INT.h"
#include"../include/MCAL/RCC/RCC_PRIV.h"
#include"../include/MCAL/NVIC/NVIC_PRIV.h"
#include"../include/MCAL/NVIC/NVIC_INT.h"
#include"../include/MCAL/UART/UART_INT.h"
#include"../include/MCAL/UART/UART_PRIV.h"
#include"../include/MCAL/UART/UART_CONF.h"



CAN_Msg       CAN_TxMsg[Number_of_TxMessages];      // CAN message for sending
CAN_Msg       CAN_RxMsg[Number_of_RxMessages];      // CAN message for receiving
 u8  		  CAN_TxRdy[3]; 					     // CAN HW ready to transmit a message
 u8		      CAN_RxRd[2];    						 // CAN HW received a message

 /********************************************************************************************/
 /*Function: CAN_voidInit							                            			 */
 /*I/P Parameters: void																		 */
 /*Returns:it returns nothing	                            							     */
 /*Desc:This Function initialize the CAN		     					                     */
 /********************************************************************************************/
void CAN_voidInit(void)
{
	/* Enable the clock for the CAN Peripheral */
	RCC_vidSetPeripheralclock(APB1,CAN1EN,ON);

	/*********************************************/
	/* need to make AFIO for the pins p8,9       */
	/*********************************************/

	GPIO_ErrorStatusSetPinMode(PIN12,GPIO_PORTA,Output2_AFPushPull);
	GPIO_ErrorStatusSetPinMode(PIN11,GPIO_PORTA,Input_Floating);

	/* Enable the NVIC for the TX and RX */
//	NVIC_ErrorStatusEnable(USB_HP_CAN_TX);
//	NVIC_ErrorStatusEnable(USB_LP_CAN_RX0);



	 /* BaudRate = 1 Mbps */
	 CAN->BTR= CAN_BaudRate;

	 /* The Re-transmition on
	 * Enter the initialization mode
	 * Set automatic bus-off management
	 * Set transmit FIFO priority driven by the request order
	 * Receive FIFO not locked on overrun
	 * Out of Sleep mode request
	 * Time triggered communication mode off
	 * The Sleep mode is left on software request.
	 * CAN reception/transmission frozen during debug. */
    CAN->MCR = (   ( CAN_MCR_NART << CAN_MCR_NART_Bit ) | ( CAN_MCR_ABOM << CAN_MCR_ABOM_Bit )
    		    | ( CAN_MCR_RFLM << CAN_MCR_RFLM_Bit ) | ( CAN_MCR_TTCM << CAN_MCR_TTCM_Bit )
				| ( CAN_MCR_TXFP << CAN_MCR_TXFP_BIt ) | ( CAN_MCR_AWUM << CAN_MCR_AWUM_Bit ) | ( CAN_MCR_DBFG << CAN_MCR_DBFG_Bit   ) );

    SET_BIT(CAN->MCR,CAN_MCR_INRQ_Bit);
    CLR_BIT(CAN->MCR,CAN_MCR_SLEEP_BIT);
    /* wait till the INAK is cleared and also the SLAK*/
      while ((GET_BIT(CAN->MSR,CAN_MSR_INAK_Bit)) && (GET_BIT(CAN->MSR,CAN_MSR_SLAK_Bit)));

      CLR_BIT(CAN->MCR,CAN_MCR_INRQ_Bit);
     while ((GET_BIT(CAN->MSR,CAN_MSR_INAK_Bit)) || (GET_BIT(CAN->MSR,CAN_MSR_SLAK_Bit)));
    /* Enable the Empty mailbox interrupt & FIFO message pending interrupt enable */
   // CAN->IER= ( ( CAN_IER_TMEIE << CAN_IER_TMEIE_Bit ) | ( CAN_IER_FMPIE0 << CAN_IER_FMPIE0_Bit ) ) ;

}


/********************************************************************************************/
/*Function: CAN_voidSendMessage						                            			*/
/*I/P Parameters: CAN_Msg *msg																*/
/*Returns:it returns nothing	                            							    */
/*Desc:This Function Sends a message throw the CAN 					                        */
/********************************************************************************************/
void CAN_voidSendMessage (CAN_Msg *msg)
{
	if ( CAN_u8CheckReady(msg->MailBoxNum) )
	{

		/* Reset the value of DLC bits */
		( CAN->TxMailBox[(msg->MailBoxNum-MailBox_Shift)].TDTR ) &= ~ (CAN_TIDR_DLC_ResetMask) ;

		/* Set the Data Length Code Value */
		( CAN->TxMailBox[(msg->MailBoxNum-MailBox_Shift)].TDTR ) |=  (msg->Len) ;

		/* Check on the ID format Standard or Extended */
		/* Standard Format Execution program */
		if(msg->Format == CAN_MSG_Standard_Format)
		{
			   /* configure TIR for the required mail box
			   * Set the ID
			   * Set the Frame Remote Transmission Request
			   * Set the Standard Frame Format
			   */
			  CAN->TxMailBox[(msg->MailBoxNum-MailBox_Shift)].TIR =
				  (  (msg->ID << CAN_TIR_Standard_StartBit) | (CAN_MSG_Standard_Format << CAN_TIR_IDE_Bit)
				   | (msg->Type << CAN_TIR_RTR_Bit));
		}
		/* Extended Format Execution program */
		else
		{
			   /* configure TIR for the required mail box
			   * Set the ID
			   * Set the Frame Remote Transmission Request
			   * Set the Extended Frame Format
			   */
			  CAN->TxMailBox[(msg->MailBoxNum-MailBox_Shift)].TIR=
				  (  (msg->ID << CAN_TIR_Standard_StartBit) | (CAN_MSG_Extended_Format << CAN_TIR_IDE_Bit)
				   | (msg->Type << CAN_TIR_RTR_Bit));
		}

		/* Data Input in the Low Data Register */
		CAN->TxMailBox[((msg->MailBoxNum)-MailBox_Shift)].TDLR = ( (msg->Data[0] << CAN_DATA_BYTE0_Shift)
				 	 	 	 	 	 	 	 	 	 	 	 	 | (msg->Data[1] << CAN_DATA_BYTE1_Shift)
																 | (msg->Data[2] << CAN_DATA_BYTE2_Shift)
																 | (msg->Data[3] << CAN_DATA_BYTE3_Shift) );
		/* Data Input in the High Data Register */
		CAN->TxMailBox[((msg->MailBoxNum)-MailBox_Shift)].TDHR = ( (msg->Data[4] << CAN_DATA_BYTE0_Shift)
						 	 	 	 	 	 	 	 	 	 	 | (msg->Data[5] << CAN_DATA_BYTE1_Shift)
																 | (msg->Data[6] << CAN_DATA_BYTE2_Shift)
																 | (msg->Data[7] << CAN_DATA_BYTE3_Shift) );

		/* Transmit MailBox Request (Send Message) */
		SET_BIT(CAN->TxMailBox[((msg->MailBoxNum)-MailBox_Shift)].TIR ,CAN_TIR_TXRQ_Bit);
		while((GET_BIT(CAN->TSR,1) == 0) && (GET_BIT(CAN->TSR,0) == 0));
		//if (GET_BIT(CAN->TSR,2)==1)
		//	 GPIO_ErrorStatusSetPinValue(PIN1,GPIO_PORTA,High);
		//if (GET_BIT(CAN->TSR,1)==0)
		//	 GPIO_ErrorStatusSetPinValue(PIN2,GPIO_PORTA,High);
		//if (GET_BIT(CAN->TSR,3)==0)
		//	 GPIO_ErrorStatusSetPinValue(PIN3,GPIO_PORTA,High);
		//if (GET_BIT(CAN->TSR,0)==0)
		//	 GPIO_ErrorStatusSetPinValue(PIN4,GPIO_PORTA,High);
		//while (GET_BIT(CAN->TxMailBox[((msg->MailBoxNum)-MailBox_Shift)].TIR ,CAN_TIR_TXRQ_Bit)==1);
		//while(GET_BIT(CAN->TSR, 0 ) != 1);
		//GPIO_ErrorStatusSetPinValue(PIN0,GPIO_PORTA,High);
	}
	else
	{
		//Do Nothing
	}

}

/********************************************************************************************/
/*Function: CAN_voidReadMessage						                            			*/
/*I/P Parameters: CAN_Msg *msg																*/
/*Returns:it returns nothing	                            							    */
/*Desc:This Function Receives a message throw the CAN 				                        */
/********************************************************************************************/
void CAN_voidReadMessage(CAN_Msg *msg)
{
	if (GET_BIT(CAN->RxFIFOMailBox[0].RIR,CAN_RIR_IDE_Bit)==0)
	{
		/* Standard Format Assign to the message */
		msg->Format= CAN_MSG_Standard_Format;
		/* Assign ID to the Message ID */
		msg->ID=CAN_Standard_formatMask & (CAN->RxFIFOMailBox[0].RIR >> CAN_FIFO_SID_Shift);
	}
	else
	{
		/* Extended Format Assign to the message */
		msg->Format= CAN_MSG_Extended_Format;
		/* Assign ID to the Message ID */
		msg->ID=CAN_Extended_formatMask & (CAN->RxFIFOMailBox[0].RIR >> CAN_FIFO_EID_Shift);
	}

	/* Assign the message type if DATA or REQUEST */
	msg->Type=GET_BIT(CAN->RxFIFOMailBox[0].RIR,CAN_RIR_RTR_Bit);
	/* Assign the Data Size */
	msg->Len=CAN_DLC_MASK & (CAN->RxFIFOMailBox[0].RDTR);

	/* Assigning the Low Register Data in the Data Array */
	msg->Data[0]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDLR >>CAN_DATA_BYTE0_Shift);
	msg->Data[1]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDLR >>CAN_DATA_BYTE1_Shift);
	msg->Data[2]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDLR >>CAN_DATA_BYTE2_Shift);
	msg->Data[3]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDLR >>CAN_DATA_BYTE3_Shift);
	/* Assigning the High Register Data in the Data Array */
	msg->Data[4]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDHR >>CAN_DATA_BYTE0_Shift);
	msg->Data[5]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDHR >>CAN_DATA_BYTE1_Shift);
	msg->Data[6]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDHR >>CAN_DATA_BYTE2_Shift);
	msg->Data[7]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[0].RDHR >>CAN_DATA_BYTE3_Shift);

	/* Release the FIFO Mailbox */
	SET_BIT(CAN->RF0R,CAN_RF0R_RFOM0);
}

/********************************************************************************************/
/*Function: CAN_u8CheckReady						                            			*/
/*I/P Parameters: u8 copy_u8MailBoxNum														*/
/*Returns:it returns u8 value	                            							    */
/*Desc:This Function checks on the mailbox ready to transmit or not                         */
/********************************************************************************************/
/* Number of Mailbox            :- CAN_TSR_TME0	- CAN_TSR_TME1 - CAN_TSR_TME2				*/
/********************************************************************************************/
u8 CAN_u8CheckReady(u8 copy_u8MailBoxNum)
{
	/* Set the Ready Transmission to Ready */
	CAN_TxRdy[(copy_u8MailBoxNum-MailBox_Shift)]= CAN_Rdy;
	/* Local Counter for Time Run out Error */
	u16 local_u16Counter=0;
	/* Pull on the Flag  */
	while(GET_BIT(CAN->TSR,copy_u8MailBoxNum)==0)
	{
		/* Update the Local Counter */
		local_u16Counter++;
		/* Check on the value of the Local Counter */
		if (local_u16Counter == 5000)
		{
			/* If Time Ran out the Ready Transmission will be not Ready */
			CAN_TxRdy[(copy_u8MailBoxNum-MailBox_Shift)]= CAN_NotRdy;
			/* break the loop because of infinity loop */
			break;
		}
	}
	/* Return the Call to the caller Function */
	return CAN_TxRdy[(copy_u8MailBoxNum-MailBox_Shift)];
}


/********************************************************************************************/
/*Function: CAN_voidCreateMessage					                            			*/
/*I/P Parameters: u32 copy_u32ID, f64 copy_f64Data, u8 copy_u8Length, u8 copy_u8Format,     */
/*		          u8 copy_u8Type, u8 copy_u8Mailbox, CAN_Msg *msg)            			    */
/*Returns:it returns nothing	                            							    */
/*Desc:This Function Create a message to be sent					                        */
/********************************************************************************************/
/* ID                           :- 29 bit identifier										*/
/* Data field                   :- up to 64 Bit Data										*/
/* Length of data field in bytes:- From  0  to  8											*/
/* Format                       :- CAN_MSG_Standard_Format - CAN_MSG_Extended_Format		*/
/* Data Type                    :- CAN_MSG_DataFrame - CAN_MSG_RemoteFram					*/
/* Number of Mailbox            :- CAN_TSR_TME0	- CAN_TSR_TME1 - CAN_TSR_TME2				*/
/********************************************************************************************/
void CAN_voidCreateMessage (u32 copy_u32ID, u32 copy_u32LowData, u32 copy_u32HighData, u8 copy_u8Length, u8 copy_u8Format,
		                     u8 copy_u8Type, u8 copy_u8Mailbox, CAN_Msg *msg)
{
	/* Assigning The ID in the Structure */
	msg->ID         = copy_u32ID;
	/* Assigning The Data Length Code in the Structure */
	msg->Len        = copy_u8Length;
	/* Assigning The Format Standard or Extended in the Structure */
	msg->Format     = copy_u8Format;
	/* Assigning The Type of message in the Structure */
	msg->Type       = copy_u8Type;
	/* Assigning The Mailbox number in the Structure */
	msg->MailBoxNum = copy_u8Mailbox;
	/********************************************************/
	/* Assigning The Data number in the Structure           */
	/********************************************************/
	/* Data Byte Number 1 Assign in the data array          */
	msg->Data[0]=(copy_u32LowData >>  CAN_DATA_BYTE0_Shift);
	/* Data Byte Number 2 Assign in the data array          */
	msg->Data[1]=(copy_u32LowData >>  CAN_DATA_BYTE1_Shift);
	/* Data Byte Number 3 Assign in the data array          */
	msg->Data[2]=(copy_u32LowData >>  CAN_DATA_BYTE2_Shift);
	/* Data Byte Number 4 Assign in the data array          */
	msg->Data[3]=(copy_u32LowData >>  CAN_DATA_BYTE3_Shift);
	/* Data Byte Number 5 Assign in the data array          */
	msg->Data[4]=(copy_u32HighData >> CAN_DATA_BYTE0_Shift);
	/* Data Byte Number 6 Assign in the data array          */
	msg->Data[5]=(copy_u32HighData >> CAN_DATA_BYTE1_Shift);
	/* Data Byte Number 7 Assign in the data array          */
	msg->Data[6]=(copy_u32HighData >> CAN_DATA_BYTE2_Shift);
	/* Data Byte Number 8 Assign in the data array          */
	msg->Data[7]=(copy_u32HighData >> CAN_DATA_BYTE3_Shift);
	/********************************************************/
}

	

/********************************************************************************************/
/*Function: CAN_voidReceive							                            			*/
/*I/P Parameters: u8 * copy_u8Data, void (*Copy_PvoidCallbackFunction)(void)				*/
/*Returns:it returns nothing	                            							    */
/*Desc:This Function Recevie The Message And Store It In An Address Of A Variable			*/
/********************************************************************************************/
/*u8 value=0;
void CAN_voidReceive(void)
{
	volatile u8  Copy_u8Data=0;
	/* Decaler a local variable to store the filter match index */
	//volatile u8 Local_u8FilterMatchIndex = 0;
	/* Decaler a local variable to store the filter match index */
//	volatile u8 Local_u8DLC = 0;
	/* Check if the FIFO is empty or holding a message*/
	/*if((GET_BIT(CAN -> RF0R,CAN_RF0R_FMP00) != 0) || ( GET_BIT(CAN -> RF0R,CAN_RF0R_FMP01) != 0 ))
	{
		/* Getting the low bytes From Low Data Register*/
		// Copy_u8Data = (u8)(CAN->RxFIFOMailBox[0].RDLR);
	//	 value=Copy_u8Data;
		 /* Getting the Filter Match Index (FMI) */
		/*Local_u8FilterMatchIndex = (u8)((CAN->RxFIFOMailBox[0].RDTR) >> 8);
		/* Getting the DLC of the received data  */
		/*Local_u8DLC = (u8)(CAN->RxFIFOMailBox[0].RDTR);
		/* Check for the DLC, it is 0 in case of frame request */
	/*	if(Local_u8DLC !=0)
		{
			/* Exectue the callback function */
		/*	  if (Copy_u8Data==255)
			  GPIO_ErrorStatusSetPinValue(PIN0,GPIO_PORTA,High);
		}
		else
		{
			/* Do something if the received frame is a request frame */
		/*}
	}
	else
	{
		/*Do something if the FIFO is not empty and full of messages*/
	/*}

	LCD_void4bitDisplayNumber(Copy_u8Data);
	/* Release FIFO Register for the next message */
	/*SET_BIT(CAN->RF0R,CAN_RF0R_RFOM0);
}
*/

void MCAN_voidReceiveData(volatile u32 * Copy_pu32Data)
{
	/* To enter the normal mode*/
	/*CLR_BIT(CAN->MCR,0);		// Clear initialization bit
	CLR_BIT(CAN->MCR,1);		// Clear sleep bit*/
	u16 ID=0;
	SET_BIT(CAN->FM1R,0);		// FMB0 is set to be List Mode
	SET_BIT(CAN->FS1R,0);		// FSC0 is set to be 32-bit
	CAN->FFA1R=0;
	SET_BIT(CAN->Filter[0].FR1,0);		// Set ID mode because we expected the id of msg = 1
	SET_BIT(CAN->FA1R,0);		// Active filter 0
	CLR_BIT(CAN->FMR,0);
	/*Check if the node still in initialization mode or Sleep mode or left it*/
	while((GET_BIT(CAN->MSR,0)) && (GET_BIT(CAN->MSR,1)));
	if(GET_BIT(CAN->RF0R,0) !=0)
	{
		* Copy_pu32Data =(u16) ((CAN->RxFIFOMailBox[0].RIR)>>21);
						/* ((GET_BIT(CAN->RxFIFOMailBox[0].RDLR,0)<<0) |
						  (GET_BIT(CAN->RxFIFOMailBox[0].RDLR,1)<<1) |
						  (GET_BIT(CAN->RxFIFOMailBox[0].RDLR,2)<<2) |
						  (GET_BIT(CAN->RxFIFOMailBox[0].RDLR,3)<<3) |
						  (GET_BIT(CAN->RxFIFOMailBox[0].RDLR,4)<<4) |
						  (GET_BIT(CAN->RxFIFOMailBox[0].RDLR,5)<<5) |
						  (GET_BIT(CAN->RxFIFOMailBox[0].RDLR,6)<<6) |
						  (GET_BIT(CAN->RxFIFOMailBox[0].RDLR,7)<<7) );*/
		SET_BIT(CAN->RF0R,5);			// RFOM0 is set to release the mailbox
//		ID =
	}

//	ID = (u16) ((CAN->RxFIFOMailBox[0].RIR)>>21);
}
