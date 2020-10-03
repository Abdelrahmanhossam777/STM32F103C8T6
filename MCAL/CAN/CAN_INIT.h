/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : CAN DRIVER                       */
/*   DATE        : 22 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


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
  u8   MailBoxNum;         // Number of Mailbox to send message with ---options    CAN_TSR_TME0	- CAN_TSR_TME1 - CAN_TSR_TME2
} CAN_Msg;


extern u8  			 CAN_TxRdy[3];   // CAN HW ready to transmit a message
extern u8		     CAN_RxRd[2];    // CAN HW received a message
/***************************************************************************/


/********************************************************************************************/
/*Function: CAN_voidInit							                            			*/
/*I/P Parameters: void																		*/
/*Returns:it returns nothing	                            							    */
/*Desc:This Function initialize the CAN		     					                        */
/********************************************************************************************/
void CAN_voidInit(void);

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
void CAN_voidReadMessage(CAN_Msg *msg);


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


#endif
