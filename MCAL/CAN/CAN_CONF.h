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
#ifndef _MCAL_CAN_CONF_H
#define _MCAL_CAN_CONF_H

/********************************************************************/
/*						  GPIO Pins For CAN							*/
/********************************************************************/
#define Can_Tx PIN12,GPIO_PORTA   //GPIO Tx Pin for Can
#define Can_Rx PIN11,GPIO_PORTA   //GPIO Rx Pin for Can
/********************************************************************/

/********************************************************************/
/* 			  			 MCR BITS Mapping 	    				    */
/********************************************************************/
#define CAN_MCR_INRQ      1  // Initialization request
#define CAN_MCR_ABOM  	  0  // Automatic bus-off management
#define CAN_MCR_TXFP	  0  // Transmit FIFO priority
#define CAN_MCR_RFLM      0  // Receive FIFO locked mode
#define CAN_MCR_NART      1  // No automatic retransmission
#define CAN_MCR_SLEEP     0  // Sleep mode request
#define CAN_MCR_TTCM	  0  // Time triggered communication mode
#define CAN_MCR_AWUM      0  // Automatic wake-up mode
#define CAN_MCR_DBFG      0  // Debug freeze
/********************************************************************/

/********************************************************************/
/* 						  IER BITS Mapping 					        */
/********************************************************************/
#define CAN_IER_FMPIE0     1 // FIFO message pending interrupt enable
#define CAN_IER_TMEIE      1 // Transmit mailbox empty interrupt enable
/********************************************************************/

/********************************************************************/
/* Number of messages to be sent or received                        */
/********************************************************************/
#define Number_of_TxMessages 2
#define Number_of_RxMessages 2
/********************************************************************/

/****************************************************************************************/
extern CAN_Msg       CAN_TxMsg[Number_of_TxMessages];      // CAN message for sending
extern CAN_Msg       CAN_RxMsg[Number_of_RxMessages];      // CAN message for receiving
/****************************************************************************************/

CAN_Msg       CAN_TxMsg[Number_of_TxMessages];      // CAN message for sending
CAN_Msg       CAN_RxMsg[Number_of_RxMessages];      // CAN message for receiving
 u8  		  CAN_TxRdy[3]; 					    // CAN HW ready to transmit a message
 u8		      CAN_RxRd[2];    						// CAN HW received a message

 /********************************************************************/
/* Interrupt Configuration to Enable or Disable it                   */
/* -Enable			-Disable						                 */
#define Interrupt_Enable  Disable
 /********************************************************************/

 /********************************************************************/
/* Test mode Configuration to Enable or Disable it  				 */
/* -Enable			-Disable										 */
#define Test_Mode         Disable
 /********************************************************************/

/**************************************************************/
/* Filter Configuration  							          */
/**************************************************************/
/* FilterX_Enable             -Enable       -Disable	  	  */
/**************************************************************/
/* FilterX_Mode               -List_mode    -Mask_mode		  */
/**************************************************************/
/* FilterX_Conf												  */
/* -Dual_scale_configuration    							  */
/* -Single_scale_configuration  							  */
/**************************************************************/
/* FilterX_Assign             -Filter_FIFO0  -Filter_FIFO1	  */
/**************************************************************/
/* FilterX_ID1 - FilterX_ID2   ---> Set The Filters IDs       */
/**************************************************************/
#define Filter0_Enable    Disable
#define Filter0_Mode      List_mode
#define Filter0_Conf      Single_scale_configuration
#define Filter0_Assign    Filter_FIFO0
#define Filter0_ID1       (10 << 21)
#define Filter0_ID2       (10 << 21)
/**************************************************************/
#define Filter1_Enable    Disable
#define Filter1_Mode      List_mode
#define Filter1_Conf      Single_scale_configuration
#define Filter1_Assign    Filter_FIFO1
#define Filter1_ID1       (100 << 21)
#define Filter1_ID2       (100 << 21)
/**************************************************************/
#define Filter2_Enable    Disable
#define Filter2_Mode      List_mode
#define Filter2_Conf      Single_scale_configuration
#define Filter2_Assign    Filter_FIFO0
#define Filter2_ID1       (10 << 21)
#define Filter2_ID2       (10 << 21)
/**************************************************************/
#define Filter3_Enable    Disable
#define Filter3_Mode      List_mode
#define Filter3_Conf      Single_scale_configuration
#define Filter3_Assign    Filter_FIFO0
#define Filter3_ID1       (10 << 21)
#define Filter3_ID2       (10 << 21)
/**************************************************************/
#define Filter4_Enable    Disable
#define Filter4_Mode      List_mode
#define Filter4_Conf      Single_scale_configuration
#define Filter4_Assign    Filter_FIFO0
#define Filter4_ID1       (10 << 21)
#define Filter4_ID2       (10 << 21)
/**************************************************************/
#define Filter5_Enable    Disable
#define Filter5_Mode      List_mode
#define Filter5_Conf      Single_scale_configuration
#define Filter5_Assign    Filter_FIFO0
#define Filter5_ID1       (10 << 21)
#define Filter5_ID2       (10 << 21)
/**************************************************************/
#define Filter6_Enable    Disable
#define Filter6_Mode      List_mode
#define Filter6_Conf      Single_scale_configuration
#define Filter6_Assign    Filter_FIFO0
#define Filter6_ID1       (10 << 21)
#define Filter6_ID2       (10 << 21)
/**************************************************************/
#define Filter7_Enable    Disable
#define Filter7_Mode      List_mode
#define Filter7_Conf      Single_scale_configuration
#define Filter7_Assign    Filter_FIFO0
#define Filter7_ID1       (10 << 21)
#define Filter7_ID2       (10 << 21)
/**************************************************************/
#define Filter8_Enable    Disable
#define Filter8_Mode      List_mode
#define Filter8_Conf      Single_scale_configuration
#define Filter8_Assign    Filter_FIFO0
#define Filter8_ID1       (10 << 21)
#define Filter8_ID2       (10 << 21)
/**************************************************************/
#define Filter9_Enable    Disable
#define Filter9_Mode      List_mode
#define Filter9_Conf      Single_scale_configuration
#define Filter9_Assign    Filter_FIFO0
#define Filter9_ID1       (10 << 21)
#define Filter9_ID2       (10 << 21)
/**************************************************************/
#define Filter10_Enable   Disable
#define Filter10_Mode     List_mode
#define Filter10_Conf     Single_scale_configuration
#define Filter10_Assign   Filter_FIFO0
#define Filter10_ID1      (10 << 21)
#define Filter10_ID2      (10 << 21)
/**************************************************************/
#define Filter11_Enable   Disable
#define Filter11_Mode     List_mode
#define Filter11_Conf     Single_scale_configuration
#define Filter11_Assign   Filter_FIFO0
#define Filter11_ID1      (10 << 21)
#define Filter11_ID2      (10 << 21)
/**************************************************************/
#define Filter12_Enable   Disable
#define Filter12_Mode     List_mode
#define Filter12_Conf     Single_scale_configuration
#define Filter12_Assign   Filter_FIFO0
#define Filter12_ID1      (10 << 21)
#define Filter12_ID2      (10 << 21)
/**************************************************************/
#define Filter13_Enable   Disable
#define Filter13_Mode     List_mode
#define Filter13_Conf     Single_scale_configuration
#define Filter13_Assign   Filter_FIFO0
#define Filter13_ID1      (10 << 21)
#define Filter13_ID2      (10 << 21)
/**************************************************************/
#define Filter14_Enable   Disable
#define Filter14_Mode     List_mode
#define Filter14_Conf     Single_scale_configuration
#define Filter14_Assign   Filter_FIFO0
#define Filter14_ID1      (10 << 21)
#define Filter14_ID2      (10 << 21)
/**************************************************************/
#define Filter15_Enable   Disable
#define Filter15_Mode     List_mode
#define Filter15_Conf     Single_scale_configuration
#define Filter15_Assign   Filter_FIFO0
#define Filter15_ID1      (10 << 21)
#define Filter15_ID2      (10 << 21)
/**************************************************************/
#define Filter16_Enable   Disable
#define Filter16_Mode     List_mode
#define Filter16_Conf     Single_scale_configuration
#define Filter16_Assign   Filter_FIFO0
#define Filter16_ID1      (10 << 21)
#define Filter16_ID2      (10 << 21)
/**************************************************************/
#define Filter17_Enable   Disable
#define Filter17_Mode     List_mode
#define Filter17_Conf     Single_scale_configuration
#define Filter17_Assign   Filter_FIFO0
#define Filter17_ID1      (10 << 21)
#define Filter17_ID2      (10 << 21)
/**************************************************************/
#define Filter18_Enable   Disable
#define Filter18_Mode     List_mode
#define Filter18_Conf     Single_scale_configuration
#define Filter18_Assign   Filter_FIFO0
#define Filter18_ID1      (10 << 21)
#define Filter18_ID2      (10 << 21)
/**************************************************************/
#define Filter19_Enable   Disable
#define Filter19_Mode     List_mode
#define Filter19_Conf     Single_scale_configuration
#define Filter19_Assign   Filter_FIFO0
#define Filter19_ID1      (10 << 21)
#define Filter19_ID2      (10 << 21)
/**************************************************************/
#define Filter20_Enable   Disable
#define Filter20_Mode     List_mode
#define Filter20_Conf     Single_scale_configuration
#define Filter20_Assign   Filter_FIFO0
#define Filter20_ID1      (10 << 21)
#define Filter20_ID2      (10 << 21)
/**************************************************************/
#define Filter21_Enable   Disable
#define Filter21_Mode     List_mode
#define Filter21_Conf     Single_scale_configuration
#define Filter21_Assign   Filter_FIFO0
#define Filter21_ID1      (10 << 21)
#define Filter21_ID2      (10 << 21)
/**************************************************************/
#define Filter22_Enable   Disable
#define Filter22_Mode     List_mode
#define Filter22_Conf     Single_scale_configuration
#define Filter22_Assign   Filter_FIFO0
#define Filter22_ID1      (10 << 21)
#define Filter22_ID2      (10 << 21)
/**************************************************************/
#define Filter23_Enable   Disable
#define Filter23_Mode     List_mode
#define Filter23_Conf     Single_scale_configuration
#define Filter23_Assign   Filter_FIFO0
#define Filter23_ID1      (10 << 21)
#define Filter23_ID2      (10 << 21)
/**************************************************************/
#define Filter24_Enable   Disable
#define Filter24_Mode     List_mode
#define Filter24_Conf     Single_scale_configuration
#define Filter24_Assign   Filter_FIFO0
#define Filter24_ID1      (10 << 21)
#define Filter24_ID2      (10 << 21)v
/**************************************************************/
#define Filter25_Enable   Disable
#define Filter25_Mode     List_mode
#define Filter25_Conf     Single_scale_configuration
#define Filter25_Assign   Filter_FIFO0
#define Filter25_ID1      (10 << 21)
#define Filter25_ID2      (10 << 21)
/**************************************************************/
#define Filter26_Enable   Disable
#define Filter26_Mode     List_mode
#define Filter26_Conf     Single_scale_configuration
#define Filter26_Assign   Filter_FIFO0
#define Filter26_ID1      (10 << 21)
#define Filter26_ID2      (10 << 21)
/**************************************************************/
#define Filter27_Enable   Disable
#define Filter27_Mode     List_mode
#define Filter27_Conf     Single_scale_configuration
#define Filter27_Assign   Filter_FIFO0
#define Filter27_ID1      (10 << 21)
#define Filter27_ID2      (10 << 21)
/**************************************************************/

#endif
