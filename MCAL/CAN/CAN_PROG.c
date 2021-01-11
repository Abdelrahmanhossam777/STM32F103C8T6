/****************************************************************************************
* ! Title : CAN_program
* ! File Name : CAN_program.c
* ! Description : This file has the definition of the CAN functions and
* the usage of the global variables.
* ! Compiler : GNU ARM Cross Compiler
* ! Target : STM32F103xxxx Micro-controller
****************************************************************************************/
/****************************************************************************************
* LOG :
* VERSION    AUTHOR              DATE              DESCRIPTION
* v1.0       Abdelrahman Hossam  22 SEP,2020       - Initial creation
* v2.0       Abdullah Mustafa    03 OCT,2020       - Adding the receive API
* v3.0       Abdelrahman Hossam  11 JAN,2021	   - Add Filters Configurations
****************************************************************************************/


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/GPIO/GPIO_INT.h"
#include "../include/MCAL/GPIO/GPIO_PRIV.h"
#include "../include/MCAL/CAN/CAN_INIT.h"
#include "../include/MCAL/CAN/CAN_CONF.h"
#include "../include/MCAL/CAN/CAN_PRIV.h"
#include "../include/MCAL/RCC/RCC_INT.h"
#include "../include/MCAL/RCC/RCC_PRIV.h"
#include "../include/MCAL/NVIC/NVIC_PRIV.h"
#include "../include/MCAL/NVIC/NVIC_INT.h"
#include "../include/MCAL/UART/UART_INT.h"
#include "../include/MCAL/UART/UART_PRIV.h"
#include "../include/MCAL/UART/UART_CONF.h"



/*********************************************************************************************/
/*Function: CAN_voidInitialization  				                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function allows CAN to work with all the needed setups		                     */
/*********************************************************************************************/
void CAN_voidInit()
{
	CAN_voidSetup();               // Setup the CAN Registers with Configurations
	CAN_voidInitializationMode();  // Leave the Sleep mode and Enter The Initialization Mode
	CAN_voidMode();			       // Initialize the Mode to enter Test-Mode or not
	CAN_voidFiltersInit();         // Initialize The Filters
	CAN_voidStart();		       // Leave the Initialization Mode and Enter The Normal Mode
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
		CAN->TxMailBox[((msg->MailBoxNum)-MailBox_Shift)].TIR = 0;
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
				   | (msg->Type << CAN_TIR_RTR_Bit		  ));
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
void CAN_voidReadMessage(CAN_Msg *msg, u8 Copy_u8FIFONumber)
{
	/* Input Validation */
	if (Copy_u8FIFONumber > 1)
	{
		return;
	}

	if (GET_BIT(CAN->RxFIFOMailBox[Copy_u8FIFONumber].RIR,CAN_RIR_IDE_Bit)==0)
	{
		/* Standard Format Assign to the message */
		msg->Format= CAN_MSG_Standard_Format;
		/* Assign ID to the Message ID */
		msg->ID=CAN_Standard_formatMask & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RIR >> CAN_FIFO_SID_Shift);
	}
	else
	{
		/* Extended Format Assign to the message */
		msg->Format= CAN_MSG_Extended_Format;
		/* Assign ID to the Message ID */
		msg->ID=CAN_Extended_formatMask & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RIR >> CAN_FIFO_EID_Shift);
	}

	/* Assign the message type if DATA or REQUEST */
	msg->Type=GET_BIT(CAN->RxFIFOMailBox[Copy_u8FIFONumber].RIR,CAN_RIR_RTR_Bit);
	/* Assign the Data Size */
	msg->Len=CAN_DLC_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDTR);

	/* Assigning the Low Register Data in the Data Array */
	msg->Data[0]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDLR >>CAN_DATA_BYTE0_Shift);
	msg->Data[1]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDLR >>CAN_DATA_BYTE1_Shift);
	msg->Data[2]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDLR >>CAN_DATA_BYTE2_Shift);
	msg->Data[3]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDLR >>CAN_DATA_BYTE3_Shift);
	/* Assigning the High Register Data in the Data Array */
	msg->Data[4]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDHR >>CAN_DATA_BYTE0_Shift);
	msg->Data[5]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDHR >>CAN_DATA_BYTE1_Shift);
	msg->Data[6]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDHR >>CAN_DATA_BYTE2_Shift);
	msg->Data[7]= CAN_DATA_MASK & (CAN->RxFIFOMailBox[Copy_u8FIFONumber].RDHR >>CAN_DATA_BYTE3_Shift);

	/* Release the FIFO Mailbox */
	if (Copy_u8FIFONumber==0)
	{
		SET_BIT(CAN->RF0R,CAN_RF0R_RFOM0); //Release FIFO 0
	}
	else if (Copy_u8FIFONumber==1)
	{
		SET_BIT(CAN->RF1R,CAN_RF1R_RFOM1); //Release FIFO 1
	}
}

/********************************************************************************************/
/*Function: CAN_voidPendingMSG						                            		    */
/*I/P Parameters: void																	    */
/*Returns:it returns nothing	                            							    */
/*Desc:This Function reads number of pending MSG    					                    */
/********************************************************************************************/
void CAN_voidPendingMSG(void)
{

	CAN_RxRd[0]=(CAN->RF0R & 0x0003); // Number of pending MSGs in FIFO 0
	CAN_RxRd[1]=(CAN->RF1R & 0x0003); // Number of pending MSGs in FIFO 1
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

	CAN_TxRdy[(copy_u8MailBoxNum-MailBox_Shift)]= CAN_Rdy; // Set the Ready Transmission to Ready
	u16 local_u16Counter=0; 							   // Local Counter for Time Run out Error
    while(GET_BIT(CAN->TSR,copy_u8MailBoxNum)==0)          // Pull on the Flag
	{
		local_u16Counter++;                                // Update the Local Counter
		if (local_u16Counter == TimeOut)	 			   // Check on the value of the Local Counter
		{
			/* If Time Ran out the Ready Transmission will be not Ready */
			CAN_TxRdy[(copy_u8MailBoxNum-MailBox_Shift)]= CAN_NotRdy;
			break;                                         // break the loops because of infinity loop
		}
	}
	return CAN_TxRdy[(copy_u8MailBoxNum-MailBox_Shift)];   // Return the Call to the caller Function
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
/*Function: CAN_voidSetup							                            		    */
/*I/P Parameters: void																	    */
/*Returns:it returns nothing	                            							    */
/*Desc:This Function setup the CAN Registers	     					                    */
/********************************************************************************************/
static void CAN_voidSetup(void)
{

	RCC_vidSetPeripheralclock(APB1,CAN1EN,ON); // Enable the clock for the CAN Peripheral
	/*********************************************/
	/* need to make AFIO for the pins p8,9       */
	/*********************************************/
	GPIO_ErrorStatusSetPinMode(Can_Tx,Output2_AFPushPull);  //Set TX pin to Alternative Function Pushpull
	GPIO_ErrorStatusSetPinMode(Can_Rx,Input_Floating);      //Set RX pin to Input Floating

	/* Interrupt Enable For the Can */
	#if (Interrupt_Enable==Enable)
		/* Enable the NVIC for the TX and RX */
		NVIC_ErrorStatusEnable(USB_HP_CAN_TX);
		NVIC_ErrorStatusEnable(USB_LP_CAN_RX0);
	#endif

	 /* The Re-transmition on
	 * Enter the initialization mode
	 * Set automatic bus-off management
	 * Set transmit FIFO priority driven by the request order
	 * Receive FIFO not locked on overrun
	 * Out of Sleep mode request
	 * Time triggered communication mode off
	 * The Sleep mode is left on software request.
	 * CAN reception/transmission frozen during debug. */
   CAN->MCR = (  ( CAN_MCR_NART << CAN_MCR_NART_Bit )  | ( CAN_MCR_ABOM << CAN_MCR_ABOM_Bit )
   		    | ( CAN_MCR_RFLM << CAN_MCR_RFLM_Bit )  | ( CAN_MCR_TTCM << CAN_MCR_TTCM_Bit )
				| ( CAN_MCR_TXFP << CAN_MCR_TXFP_BIt )  | ( CAN_MCR_AWUM << CAN_MCR_AWUM_Bit ) | ( CAN_MCR_DBFG << CAN_MCR_DBFG_Bit   ) );


   /* Enable the Empty mailbox interrupt & FIFO message pending interrupt enable */
  // CAN->IER= ( ( CAN_IER_TMEIE << CAN_IER_TMEIE_Bit ) | ( CAN_IER_FMPIE0 << CAN_IER_FMPIE0_Bit ) ) ;

}

/*********************************************************************************************/
/*Function: CAN_voidMode							                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function setup the CAN Mode Test Mode or Not     			                     */
/*********************************************************************************************/
static void CAN_voidMode(void)
{
	/* Test Mode Configuration */
	#if(Test_Mode==Disable)                     // Test mode Is Disabled
		{
			CAN->BTR= CAN_BaudRate; 			// BaudRate = 1 Mbps
			CLR_BIT(CAN->BTR,CAN_BTR_LBKM_BIT); // Loop Back Mode Disable
			CLR_BIT(CAN->BTR,CAN_BTR_SILM_BIT); // Silent Mode Disable
		}
  #elif (Test_Mode==Enable)					// Test mode Is Enabled
		{
			CAN->BTR= CAN_BaudRate; 			// BaudRate = 1 Mbps
			SET_BIT(CAN->BTR,CAN_BTR_LBKM_BIT); // Loop Back Mode Enable
			SET_BIT(CAN->BTR,CAN_BTR_SILM_BIT); // Silent Mode Enable
		}
   #endif

}

/*********************************************************************************************/
/*Function: CAN_voidInitializationMode				                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function allows CAN to Enter Initialization Mode   			                     */
/*********************************************************************************************/
static void CAN_voidInitializationMode(void)
{
	   /* Initialization Mode Entry */
	    SET_BIT(CAN->MCR,CAN_MCR_INRQ_Bit);  // Initialization Mode Request
	    CLR_BIT(CAN->MCR,CAN_MCR_SLEEP_BIT); // Leave Sleep Mode Request

	    // wait till the INAK is cleared and also the SLAK
	    while ((GET_BIT(CAN->MSR,CAN_MSR_INAK_Bit)) && (GET_BIT(CAN->MSR,CAN_MSR_SLAK_Bit)));
}

/*********************************************************************************************/
/*Function: CAN_voidInitializationMode				                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function allows CAN to Enter Normal Mode		   			                     */
/*********************************************************************************************/
static void CAN_voidStart(void)
{
   /* Normal Mode Entry */
   CLR_BIT(CAN->MCR,CAN_MCR_INRQ_Bit); // Leave Initialization Mode Request
   while ((GET_BIT(CAN->MSR,CAN_MSR_INAK_Bit)) && (GET_BIT(CAN->MSR,CAN_MSR_SLAK_Bit))); //wait ACK for Normal Mode

}

/********************************************************************************/
/*Function: CAN_voidFiltersInit						                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns nothing                       							    */
/*Desc:This Function Initialize all the CAN Filters         		            */
/********************************************************************************/
static void CAN_voidFiltersInit(void)
{
	SET_BIT(CAN->FMR,CAN_FMR_FINIT_BIT);	// SET bit FINIT to initialize the filter
	CAN->FA1R=Reset_Value;					// inactive All filters
	CAN->FM1R=CAN_u32FiltersMode();         // Set the Filters Mode
	CAN->FS1R=CAN_u32FiltersConf();         // Set the Filters 32 or 2*16 registers
	CAN->FFA1R=CAN_u32FiltersAssign();      // Set the assign of each filter to One of the FIFOs (1 or 2)
	CAN_voidSetIDs();                       // Set the IDs to the Filters
	CAN->FA1R=CAN_u32FiltersEnable();       // Enable The Filters
	CLR_BIT(CAN->FMR,CAN_FMR_FINIT_BIT);	// CLEAR bit FINIT to Activate the filter
}

/********************************************************************************/
/*Function: CAN_u32FiltersEnable					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to the Enabled Filters  		            */
/********************************************************************************/
static u32 CAN_u32FiltersEnable(void)
{
	u32 Local_u32Value=0;   //Local Variable For Data Read
	/*Assemble Filters Values*/
	Local_u32Value =((Filter27_Enable<<Filter27)| (Filter26_Enable<<Filter26)| (Filter25_Enable<<Filter25)|
					 (Filter24_Enable<<Filter24)| (Filter23_Enable<<Filter23)| (Filter23_Enable<<Filter23)|
					 (Filter22_Enable<<Filter22)| (Filter21_Enable<<Filter21)| (Filter20_Enable<<Filter20)|
					 (Filter19_Enable<<Filter19)| (Filter18_Enable<<Filter18)| (Filter17_Enable<<Filter17)|
					 (Filter16_Enable<<Filter16)| (Filter15_Enable<<Filter15)| (Filter14_Enable<<Filter14)|
					 (Filter13_Enable<<Filter13)| (Filter12_Enable<<Filter12)| (Filter11_Enable<<Filter11)|
					 (Filter10_Enable<<Filter10)| (Filter9_Enable<<Filter9  )| (Filter8_Enable<<Filter8  )|
					 (Filter7_Enable<<Filter7  )| (Filter6_Enable<<Filter6  )| (Filter5_Enable<<Filter5  )|
					 (Filter4_Enable<<Filter4  )| (Filter3_Enable<<Filter3  )| (Filter2_Enable<<Filter2  )|
					 (Filter1_Enable<<Filter1  )| (Filter0_Enable<<Filter0  ));
	return Local_u32Value;  // Returning the control to the caller function
}
/********************************************************************************/
/*Function: CAN_u32FiltersMode     					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to Filters modes list or mask            */
/********************************************************************************/
static u32 CAN_u32FiltersMode(void)
{
	u32 Local_u32Value=0;  //Local Variable For Data Read
	/*Assemble Filters Values*/
	Local_u32Value =((Filter27_Mode<<Filter27)| (Filter26_Mode<<Filter26)| (Filter25_Mode<<Filter25)|
					 (Filter24_Mode<<Filter24)| (Filter23_Mode<<Filter23)| (Filter23_Mode<<Filter23)|
					 (Filter22_Mode<<Filter22)| (Filter21_Mode<<Filter21)| (Filter20_Mode<<Filter20)|
					 (Filter19_Mode<<Filter19)| (Filter18_Mode<<Filter18)| (Filter17_Mode<<Filter17)|
					 (Filter16_Mode<<Filter16)| (Filter15_Mode<<Filter15)| (Filter14_Mode<<Filter14)|
					 (Filter13_Mode<<Filter13)| (Filter12_Mode<<Filter12)| (Filter11_Mode<<Filter11)|
					 (Filter10_Mode<<Filter10)| (Filter9_Mode<<Filter9  )| (Filter8_Mode<<Filter8  )|
					 (Filter7_Mode<<Filter7  )| (Filter6_Mode<<Filter6  )| (Filter5_Mode<<Filter5  )|
					 (Filter4_Mode<<Filter4  )| (Filter3_Mode<<Filter3  )| (Filter2_Mode<<Filter2  )|
					 (Filter1_Mode<<Filter1  )| (Filter0_Mode<<Filter0  ));
	return Local_u32Value;  // Returning the control to the caller function
}
/********************************************************************************/
/*Function: CAN_u32FiltersConf     					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to Filters Conf Single or Dual Registers */
/********************************************************************************/
static u32 CAN_u32FiltersConf(void)
{
	u32 Local_u32Value=0;   //Local Variable For Data Read
	/*Assemble Filters Values*/
	Local_u32Value =((Filter27_Conf<<Filter27)| (Filter26_Conf<<Filter26)| (Filter25_Conf<<Filter25)|
					 (Filter24_Conf<<Filter24)| (Filter23_Conf<<Filter23)| (Filter23_Conf<<Filter23)|
					 (Filter22_Conf<<Filter22)| (Filter21_Conf<<Filter21)| (Filter20_Conf<<Filter20)|
					 (Filter19_Conf<<Filter19)| (Filter18_Conf<<Filter18)| (Filter17_Conf<<Filter17)|
					 (Filter16_Conf<<Filter16)| (Filter15_Conf<<Filter15)| (Filter14_Conf<<Filter14)|
					 (Filter13_Conf<<Filter13)| (Filter12_Conf<<Filter12)| (Filter11_Conf<<Filter11)|
					 (Filter10_Conf<<Filter10)| (Filter9_Conf<<Filter9  )| (Filter8_Conf<<Filter8  )|
					 (Filter7_Conf<<Filter7  )| (Filter6_Conf<<Filter6  )| (Filter5_Conf<<Filter5  )|
					 (Filter4_Conf<<Filter4  )| (Filter3_Conf<<Filter3  )| (Filter2_Conf<<Filter2  )|
					 (Filter1_Conf<<Filter1  )| (Filter0_Conf<<Filter0  ));
	return Local_u32Value;  // Returning the control to the caller function
}
/********************************************************************************/
/*Function: CAN_u32FiltersAssign   					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to Filters ssigned to FIFO 0 or 1        */
/********************************************************************************/
static u32 CAN_u32FiltersAssign(void)
{
	u32 Local_u32Value=0;   //Local Variable For Data Read
	/*Assemble Filters Values*/
	Local_u32Value =((Filter27_Assign<<Filter27)| (Filter26_Assign<<Filter26)| (Filter25_Assign<<Filter25)|
					 (Filter24_Assign<<Filter24)| (Filter23_Assign<<Filter23)| (Filter23_Assign<<Filter23)|
					 (Filter22_Assign<<Filter22)| (Filter21_Assign<<Filter21)| (Filter20_Assign<<Filter20)|
					 (Filter19_Assign<<Filter19)| (Filter18_Assign<<Filter18)| (Filter17_Assign<<Filter17)|
					 (Filter16_Assign<<Filter16)| (Filter15_Assign<<Filter15)| (Filter14_Assign<<Filter14)|
					 (Filter13_Assign<<Filter13)| (Filter12_Assign<<Filter12)| (Filter11_Assign<<Filter11)|
					 (Filter10_Assign<<Filter10)| (Filter9_Assign<<Filter9  )| (Filter8_Assign<<Filter8  )|
					 (Filter7_Assign<<Filter7  )| (Filter6_Assign<<Filter6  )| (Filter5_Assign<<Filter5  )|
					 (Filter4_Assign<<Filter4  )| (Filter3_Assign<<Filter3  )| (Filter2_Assign<<Filter2  )|
					 (Filter1_Assign<<Filter1  )| (Filter0_Assign<<Filter0  ));
	return Local_u32Value;  // Returning the control to the caller function
}
/********************************************************************************/
/*Function: CAN_voidSetIDs							                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns nothing                       							    */
/*Desc:This Function set the IDs For Each Filter in the CAN  		            */
/********************************************************************************/
static void CAN_voidSetIDs(void)
{
   #if (Filter0_Enable==Enable)
   {
	 CAN->Filter[Filter0].FR1=Filter0_ID1;  // Assign ID 1 For Filter 0
	 CAN->Filter[Filter0].FR2=Filter0_ID2;  // Assign ID 2 For Filter 0
   }
   #endif
   #if (Filter1_Enable==Enable)
   {
	 CAN->Filter[Filter1].FR1=Filter1_ID1;  // Assign ID 1 For Filter 1
	 CAN->Filter[Filter1].FR2=Filter1_ID2;  // Assign ID 2 For Filter 1
   }
   #endif
      #if (Filter2_Enable==Enable)
   {
	 CAN->Filter[Filter2].FR1=Filter2_ID1;  // Assign ID 1 For Filter 2
	 CAN->Filter[Filter2].FR2=Filter2_ID2;  // Assign ID 2 For Filter 2
   }
   #endif
      #if (Filter3_Enable==Enable)
   {
	 CAN->Filter[Filter3].FR1=Filter3_ID1;  // Assign ID 1 For Filter 3
	 CAN->Filter[Filter3].FR2=Filter3_ID2;  // Assign ID 2 For Filter 3
   }
   #endif
      #if (Filter4_Enable==Enable)
   {
	 CAN->Filter[Filter4].FR1=Filter4_ID1;  // Assign ID 1 For Filter 4
	 CAN->Filter[Filter4].FR2=Filter4_ID2;  // Assign ID 2 For Filter 4
   }
   #endif
      #if (Filter5_Enable==Enable)
   {
	 CAN->Filter[Filter5].FR1=Filter5_ID1;   // Assign ID 1 For Filter 5
	 CAN->Filter[Filter5].FR2=Filter5_ID2;   // Assign ID 2 For Filter 5
   }
   #endif
      #if (Filter6_Enable==Enable)
   {
	 CAN->Filter[Filter6].FR1=Filter6_ID1;   // Assign ID 1 For Filter 6
	 CAN->Filter[Filter6].FR2=Filter6_ID2;   // Assign ID 2 For Filter 6
   }
   #endif
      #if (Filter7_Enable==Enable)
   {
	 CAN->Filter[Filter7].FR1=Filter7_ID1;   // Assign ID 1 For Filter 7
	 CAN->Filter[Filter7].FR2=Filter7_ID2;   // Assign ID 2 For Filter 7
   }
   #endif
      #if (Filter8_Enable==Enable)
   {
	 CAN->Filter[Filter8].FR1=Filter8_ID1;   // Assign ID 1 For Filter 8
	 CAN->Filter[Filter8].FR2=Filter8_ID2;   // Assign ID 2 For Filter 8
   }
   #endif
      #if (Filter9_Enable==Enable)
   {
	 CAN->Filter[Filter9].FR1=Filter9_ID1;   // Assign ID 1 For Filter 9
	 CAN->Filter[Filter9].FR2=Filter9_ID2;   // Assign ID 2 For Filter 9
   }
   #endif
      #if (Filter10_Enable==Enable)
   {
	 CAN->Filter[Filter10].FR1=Filter10_ID1;  // Assign ID 1 For Filter 10
	 CAN->Filter[Filter10].FR2=Filter10_ID2;  // Assign ID 2 For Filter 10
   }
   #endif
      #if (Filter11_Enable==Enable)
   {
	 CAN->Filter[Filter11].FR1=Filter11_ID1;  // Assign ID 1 For Filter 11
	 CAN->Filter[Filter11].FR2=Filter11_ID2;  // Assign ID 2 For Filter 11
   }
   #endif
      #if (Filter12_Enable==Enable)
   {
	 CAN->Filter[Filter12].FR1=Filter12_ID1;  // Assign ID 1 For Filter 12
	 CAN->Filter[Filter12].FR2=Filter12_ID2;  // Assign ID 2 For Filter 12
   }
   #endif
      #if (Filter13_Enable==Enable)
   {
	 CAN->Filter[Filter13].FR1=Filter13_ID1;  // Assign ID 1 For Filter 13
	 CAN->Filter[Filter13].FR2=Filter13_ID2;  // Assign ID 2 For Filter 13
   }
   #endif
      #if (Filter14_Enable==Enable)
   {
	 CAN->Filter[Filter14].FR1=Filter14_ID1;  // Assign ID 1 For Filter 14
	 CAN->Filter[Filter14].FR2=Filter14_ID2;  // Assign ID 2 For Filter 14
   }
   #endif
      #if (Filter15_Enable==Enable)
   {
	 CAN->Filter[Filter15].FR1=Filter15_ID1;  // Assign ID 1 For Filter 15
	 CAN->Filter[Filter15].FR2=Filter15_ID2;  // Assign ID 2 For Filter 15
   }
   #endif
      #if (Filter16_Enable==Enable)
   {
	 CAN->Filter[Filter16].FR1=Filter16_ID1;  // Assign ID 1 For Filter 16
	 CAN->Filter[Filter16].FR2=Filter16_ID2;  // Assign ID 2 For Filter 16
   }
   #endif
      #if (Filter17_Enable==Enable)
   {
	 CAN->Filter[Filter17].FR1=Filter17_ID1; // Assign ID 1 For Filter 17
	 CAN->Filter[Filter17].FR2=Filter17_ID2; // Assign ID 2 For Filter 17
   }
   #endif
      #if (Filter18_Enable==Enable)
   {
	 CAN->Filter[Filter18].FR1=Filter18_ID1; // Assign ID 1 For Filter 18
	 CAN->Filter[Filter18].FR2=Filter18_ID2; // Assign ID 2 For Filter 18
   }
   #endif
      #if (Filter19_Enable==Enable)
   {
	 CAN->Filter[Filter19].FR1=Filter19_ID1;  // Assign ID 1 For Filter 19
	 CAN->Filter[Filter19].FR2=Filter19_ID2;  // Assign ID 2 For Filter 19
   }
   #endif
       #if (Filter20_Enable==Enable)
   {
	 CAN->Filter[Filter20].FR1=Filter20_ID1; // Assign ID 1 For Filter 20
	 CAN->Filter[Filter20].FR2=Filter20_ID2; // Assign ID 2 For Filter 20
   }
   #endif
       #if (Filter21_Enable==Enable)
   {
	 CAN->Filter[Filter21].FR1=Filter21_ID1;  // Assign ID 1 For Filter 21
	 CAN->Filter[Filter21].FR2=Filter21_ID2;  // Assign ID 2 For Filter 21
   }
   #endif
       #if (Filter22_Enable==Enable)
   {
	 CAN->Filter[Filter22].FR1=Filter22_ID1;  // Assign ID 1 For Filter 22
	 CAN->Filter[Filter22].FR2=Filter22_ID2;  // Assign ID 2 For Filter 22
   }
   #endif
       #if (Filter23_Enable==Enable)
   {
	 CAN->Filter[Filter23].FR1=Filter23_ID1;  // Assign ID 1 For Filter 23
	 CAN->Filter[Filter23].FR2=Filter23_ID2;  // Assign ID 2 For Filter 23
   }
   #endif
       #if (Filter24_Enable==Enable)
   {
	 CAN->Filter[Filter24].FR1=Filter24_ID1;   // Assign ID 1 For Filter 24
	 CAN->Filter[Filter24].FR2=Filter24_ID2;   // Assign ID 2 For Filter 24
   }
   #endif
       #if (Filter25_Enable==Enable)
   {
	 CAN->Filter[Filter25].FR1=Filter25_ID1;  // Assign ID 1 For Filter 25
	 CAN->Filter[Filter25].FR2=Filter25_ID2;  // Assign ID 2 For Filter 25
   }
   #endif
       #if (Filter26_Enable==Enable)
   {
	 CAN->Filter[Filter26].FR1=Filter26_ID1;  // Assign ID 1 For Filter 26
	 CAN->Filter[Filter26].FR2=Filter26_ID2;  // Assign ID 2 For Filter 26
   }
   #endif
       #if (Filter27_Enable==Enable)
   {
	 CAN->Filter[Filter27].FR1=Filter27_ID1;  // Assign ID 1 For Filter 27
	 CAN->Filter[Filter27].FR2=Filter27_ID2;  // Assign ID 2 For Filter 27
   }
   #endif
}


