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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_CAN_INT_H
#define _MCAL_CAN_INT_H

/****************************/
/* A CAN Message Parameters */
/****************************/
typedef struct  {
  u32  ID;                 // 29 bit identifier
  u8   Data[8];            // Data field
  u8   Len;                // Length of data field in bytes          ---options From  0  to  8
  u8   Format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER   ---options CAN_MSG_Standard_Format - CAN_MSG_Extended_Format
  u8   Type;               // 0 - DATA FRAME, 1 - REMOTE FRAME       ---options CAN_MSG_DataFrame - CAN_MSG_RemoteFram
  u8   MailBoxNum;         // Number of Mailbox to send message with ---options CAN_TSR_TME0	- CAN_TSR_TME1 - CAN_TSR_TME2
} CAN_Msg;


extern u8  			 CAN_TxRdy[3];   // CAN HW ready to transmit a message
extern u8		     CAN_RxRd[2];    // CAN HW received a message
/***************************************************************************/



/*********************************************************************************************/
/*Function: CAN_voidInitialization  				                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function allows CAN to work with all the needed setups		                     */
/*********************************************************************************************/
void CAN_voidInit();

/********************************************************************************************/
/*Function: CAN_voidSendMessage						                            			*/
/*I/P Parameters: CAN_Msg *msg																*/
/*Returns:it returns nothing	                            							    */
/*Desc:This Function Sends a message throw the CAN 					                        */
/********************************************************************************************/
void CAN_voidSendMessage (CAN_Msg *msg);

/********************************************************************************************/
/*Function: CAN_voidReadMessage						                            			*/
/*I/P Parameters: CAN_Msg *msg																*/
/*Returns:it returns nothing	                            							    */
/*Desc:This Function Receives a message throw the CAN 				                        */
/********************************************************************************************/
void CAN_voidReadMessage(CAN_Msg *msg, u8 Copy_u8FIFONumber);


/********************************************************************************************/
/*Function: CAN_u8CheckReady						                            			*/
/*I/P Parameters: u8 copy_u8MailBoxNum														*/
/*Returns:it returns u8 value	                            							    */
/*Desc:This Function checks on the mailbox ready to transmit or not                         */
/********************************************************************************************/
/* Number of Mailbox            :- CAN_TSR_TME0	- CAN_TSR_TME1 - CAN_TSR_TME2				*/
/********************************************************************************************/
u8 CAN_u8CheckReady(u8 copy_u8MailBoxNum);


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
		                     u8 copy_u8Type, u8 copy_u8Mailbox, CAN_Msg *msg);

/********************************************************************************************/
/*Function: CAN_voidPendingMSG						                            		    */
/*I/P Parameters: void																	    */
/*Returns:it returns nothing	                            							    */
/*Desc:This Function reads number of pending MSG    					                    */
/********************************************************************************************/
void CAN_voidPendingMSG(void);

/********************************************************************************************/
/*Function: CAN_voidReceive							                            			*/
/*I/P Parameters: u8 * copy_u8Data, void (*Copy_PvoidCallbackFunction)(void)				*/
/*Returns:it returns nothing	                            							    */
/*Desc:This Function Receive The Message And Store It In An Address Of A Variable			*/
/********************************************************************************************/
//void CAN_voidReceive(void);
void MCAN_voidReceiveData(volatile u32 * Copy_pu32Data);


#endif
