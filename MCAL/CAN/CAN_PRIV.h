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
#ifndef _MCAL_CAN_PRIV_H
#define _MCAL_CAN_PRIV_H

/****************************************************************/
/* CAN pointer to structure with Base Address of CAN Peripheral */
#define CAN ((volatile CAN_t *) 0x40006400)
/****************************************************************/

/****************************************/
/* Reset value for Registers            */
#define Reset_Value 0X0000
/****************************************/

/****************************************/
/* Time Out For Loops		            */
#define TimeOut  5000
/****************************************/

/****************************************/
/* enable and Disable Values for bits   */
#define Enable  1
#define Disable 0
/****************************************/

/****************************************/
/* Definition of the Messages Format    */
#define CAN_MSG_Standard_Format   0
#define CAN_MSG_Extended_Format   1
/****************************************/

/****************************************/
/* Ready and not ready Macros */
/****************************************/
#define CAN_Rdy     1
#define CAN_NotRdy  0
/****************************************/
/****************************************/
/* Definition of the Messages Format    */
#define CAN_MSG_DataFrame    0
#define CAN_MSG_RemoteFram   1
/****************************************/

/*****************************************************/
/* shift to write Data in the Mailbox Data registers */
/*****************************************************/
/* Byte 0 Shift 									 */
#define CAN_DATA_BYTE0_Shift  0
/* Byte 1 Shift 									 */
#define CAN_DATA_BYTE1_Shift  8
/* Byte 2 Shift 									 */
#define CAN_DATA_BYTE2_Shift  16
/* Byte 3 Shift 									 */
#define CAN_DATA_BYTE3_Shift  24
/*****************************************************/

/********************************/
/* Transmit mailbox 0,1,2 empty */
#define CAN_TSR_TME0	26
#define CAN_TSR_TME1	27
#define CAN_TSR_TME2	28
#define MailBox_Shift   26
/********************************/

/********************************/
/* Baudrate for the CAN */
/********************************/
#define CAN_BaudRate 0x00050000
//#define CAN_BaudRate 	0x00060004
/********************************/

/*************************************************/
/* Definition of the Data Length Code Reset Mask */
#define CAN_TIDR_DLC_ResetMask 0b1111
/*************************************************/

/*************************************************/
/* Definition of the Extended Format Mask        */
#define CAN_Extended_formatMask ((u32)0x0003FFFF)
/* Definition of the Standerd Format Mask        */
#define CAN_Standard_formatMask ((u32)0x000007FF)
/* Definition of the Data length code Mask       */
#define CAN_DLC_MASK ((u8)0x0000000F)
/* Definition of the DATA mask */
#define CAN_DATA_MASK (u8)0x000000FF
/*************************************************/

/*************************************************/
/* ID shift for the Extended Format 			 */
#define CAN_FIFO_EID_Shift	3
/* ID shift for the Standerd Format 			 */
#define CAN_FIFO_SID_Shift	21
/*************************************************/

/**********************************************/
/* 				MCR BITS Mapping 			  */
/**********************************************/
/* Initialization request */
#define CAN_MCR_INRQ_Bit  0
/* Automatic bus-off management */
#define CAN_MCR_ABOM_Bit  6
/*Transmit FIFO priority*/
#define CAN_MCR_TXFP_BIt  2
/*Receive FIFO locked mode*/
#define CAN_MCR_RFLM_Bit  3
/* No automatic retransmission */
#define CAN_MCR_NART_Bit  4
/*Sleep mode request*/
#define CAN_MCR_SLEEP_BIT 1
/*Time triggered communication mode*/
#define CAN_MCR_TTCM_Bit  7
/*Automatic wakeup mode*/
#define CAN_MCR_AWUM_Bit  5
/*Debug freeze*/
#define CAN_MCR_DBFG_Bit   16

/**********************************************/
/* 				MSR BITS Mapping 			  */
/**********************************************/
/*Initialization acknowledge*/
#define CAN_MSR_INAK_Bit  0
/*Sleep acknowledge*/
#define CAN_MSR_SLAK_Bit  1
/*Wakeup interrupt*/
#define CAN_MSR_WKUI_Bit  3
/*Transmit mode*/
#define CAN_MSR_TXM_Bit  8
/*Receive mode*/
#define CAN_MSR_RXM_Bit  9
/*CAN Rx signal*/
#define CAN_MSR_RX_Bit  11


/**********************************************/
/* 				TSR BITS Mapping 			  */
/**********************************************/
/*Request completed mailbox 0*/
#define CAN_TSR_RQCP0_Bit   0
/*Transmission OK of mailbox 0*/
#define CAN_TSR_TXOK0_Bit   1
/*Arbitration lost for mailbox 0*/
#define CAN_TSR_ALST0_Bit   2
/*Transmission error of mailbox 0*/
#define CAN_TSR_TERR0_Bit   3
/*Abort request for mailbox 0*/
#define CAN_TSR_ABRQ0_Bit   7
/*Request completed mailbox 1*/
#define CAN_TSR_RQCP1_Bit   8
/*Transmission OK of mailbox 1*/
#define CAN_TSR_TXOK1_Bit   9
/*Arbitration lost for mailbox 1*/
#define CAN_TSR_ALST1_Bit   10
/*Transmission error of mailbox 1*/
#define CAN_TSR_TERR1_Bit   11
/*Abort request for mailbox 1*/
#define CAN_TSR_ABRQ1_Bit   15
/*Request completed mailbox 2*/
#define CAN_TSR_RQCP2_Bit   16
/*Transmission OK of mailbox 2*/
#define CAN_TSR_TXOK2_Bit   17
/*Arbitration lost for mailbox 2*/
#define CAN_TSR_ALST2_Bit   18
/*Transmission error of mailbox 2*/
#define CAN_TSR_TERR2_Bit   19
/*Abort request for mailbox 2*/
#define CAN_TSR_ABRQ2_Bit   23
/*Transmit mailbox 0 empty*/
#define CAN_TSR_TME0_Bit    26
/*Transmit mailbox 1 empty*/
#define CAN_TSR_TME1_Bit    27
/*Transmit mailbox 2 empty*/
#define CAN_TSR_TME2_Bit    28

/**********************************************/
/* 				IER BITS Mapping 			  */
/**********************************************/
/* FIFO message pending interrupt enable      */
#define CAN_IER_FMPIE0_Bit 1
/* Transmit mailbox empty interrupt enable    */
#define CAN_IER_TMEIE_Bit  0
/**********************************************/

/**********************************************/
/* 				TIR BITS Mapping 			  */
/**********************************************/
/* IDE: Identifier extension 				  */
#define CAN_TIR_IDE_Bit    2
/* RTR: Remote transmission request 		  */
#define CAN_TIR_RTR_Bit    1
/* TXRQ: Transmit mailbox request 			  */
#define CAN_TIR_TXRQ_Bit   0
/* Extended ID Start Bit 					  */
#define CAN_TIR_Extended_StartBit   3
/* Standard ID Start Bit 					  */
#define CAN_TIR_Standard_StartBit   21
/*********************************************/

/**********************************************/
/* 				FIFO BITS Mapping 			  */
/**********************************************/
/*Identifier extension Bit					  */
#define CAN_RIR_RTR_Bit  1
/*Remote transmission request Bit			  */
#define CAN_RIR_IDE_Bit  1
/**********************************************/

/**********************************************/
/* 				RF0R BITS Mapping 			  */
/**********************************************/
/* Release FIFO 0 output mailbox              */
#define CAN_RF0R_RFOM0  5
#define CAN_RF0R_FMP00  0
#define CAN_RF0R_FMP01  1

/**********************************************/
/* 				RF1R BITS Mapping 			  */
/**********************************************/
/* Release FIFO 0 output mailbox              */
#define CAN_RF1R_RFOM1  5
#define CAN_RF1R_FMP10  0
#define CAN_RF1R_FMP11  1


/**********************************************/

/**********************************************/
/* 				BTR BITS Mapping 			  */
/**********************************************/
#define CAN_BTR_LBKM_BIT    30
#define CAN_BTR_SILM_BIT    31
/**********************************************/

/**********************************************/
/* 				FMR BITS Mapping 			  */
/**********************************************/
#define CAN_FMR_FINIT_BIT   0
/**********************************************/

/***************************************************************************/
/*				Tx MailBox Structure for register Description			   */
/***************************************************************************/
typedef struct
{
  /* CAN TX mailbox identifier register (CAN_TIxR) (x=0..2) */
  volatile u32 TIR;
  /* CAN mailbox data length control and time stamp register (CAN_TDTxR) (x=0..2) */
  volatile u32 TDTR;
  /* CAN mailbox data low register (CAN_TDLxR) (x=0..2) */
  volatile u32 TDLR;
  /* CAN mailbox data high register (CAN_THLxR) (x=0..2) */
  volatile u32 TDHR;
} CAN_TxMailBox;
/***************************************************************************/

/***************************************************************************/
/*			  FIFO MailBox Structure for register Description			   */
/***************************************************************************/
typedef struct
{
  /* CAN receive FIFO mailbox identifier register (CAN_RIxR) (x=0..1) */
  volatile u32 RIR;
  /* CAN receive FIFO mailbox data length control and time stamp register (CAN_RDTxR) (x=0..1) */
  volatile u32 RDTR;
  /* CAN receive FIFO mailbox data low register (CAN_RDLxR) (x=0..1) */
  volatile u32 RDLR;
  /* CAN receive FIFO mailbox data high register (CAN_RDHxR) (x=0..1) */
  volatile u32 RDHR;
} CAN_FIFOMailBox;
/***************************************************************************/

/***************************************************************************/
/*			 Filter Registers Structure for register Description		   */
/***************************************************************************/
typedef struct
{
  volatile u32 FR1;
  volatile u32 FR2;
} CAN_FilterRegister;


typedef struct {

	/* CAN master control register (CAN_MCR) */
	volatile u32 MCR;
    /* CAN master status register (CAN_MSR) */
	volatile u32 MSR;
	/* CAN transmit status register (CAN_TSR) */
	volatile u32 TSR;
	/* CAN receive FIFO 0 register (CAN_RF0R) */
	volatile u32 RF0R;
	/* CAN receive FIFO 1 register (CAN_RF0R) */
	volatile u32 RF1R;
	/* CAN interrupt enable register (CAN_IER) */
	volatile u32 IER;
   /* CAN error status register (CAN_ESR) */
	volatile u32 ESR;
	/* CAN bit timing register (CAN_BTR) */
	volatile u32 BTR;
	/* Reserved Space in memory */
	u32 RESERVED0 [88];
	/* 3 Tx MailBoxes definition from another structure */
	CAN_TxMailBox TxMailBox[3];
	/* 2 Rx FIFO MailBoxes definition from another structure */
	CAN_FIFOMailBox RxFIFOMailBox [2];
	/* Reserved Space in memory */
	u32 RESERVED1 [12];
	/* CAN filter master register (CAN_FMR) */
	volatile u32 FMR;
    /* CAN filter mode register (CAN_FM1R) */
	volatile u32 FM1R;
	/* Reserved Space in memory */
	u32  RESERVED2;
	/* CAN filter scale register (CAN_FS1R) */
    volatile u32 FS1R;
    /* Reserved Space in memory */
    u32  RESERVED3;
    /* CAN filter FIFO assignment register (CAN_FFA1R) */
    volatile u32 FFA1R;
    /* Reserved Space in memory */
    u32  RESERVED4;
    /* CAN filter activation register (CAN_FA1R) */
    volatile u32 FA1R;
    /* Reserved Space in memory */
    u32  RESERVED5[8];
    /* 28 Filter definition from another structure */
    CAN_FilterRegister Filter[28];

}CAN_t;
/***************************************************************************/

/*****************************/
/* LIST and MASK Modes Setup */
#define Mask_mode   0
#define List_mode   1
/*****************************/

/*************************************/
/* Filter Single(32) or Dual(2*16)   */
#define Dual_scale_configuration   0
#define Single_scale_configuration 1
/*************************************/

/*************************************/
/* Filter Assign To FIFO0 or FIFO1   */
#define Filter_FIFO0 0
#define Filter_FIFO1 1
/*************************************/

/*************************************/
/*			   Filters 				 */
/*************************************/
#define Filter0		0
#define Filter1		1
#define Filter2		2
#define Filter3		3
#define Filter4		4
#define Filter5		5
#define Filter6		6
#define Filter7		7
#define Filter8		8
#define Filter9		9
#define Filter10	10
#define Filter11	11
#define Filter12	12
#define Filter13	13
#define Filter14	14
#define Filter15	15
#define Filter16	16
#define Filter17	17
#define Filter18	18
#define Filter19	19
#define Filter20	20
#define Filter21	21
#define Filter22	22
#define Filter23	23
#define Filter24	24
#define Filter25	25
#define Filter26	26
#define Filter27	27
/*************************************/

/********************************************************************************/
/*								Private Functions								*/
/********************************************************************************/

/********************************************************************************/
/*Function: CAN_voidFiltersInit						                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns nothing                       							    */
/*Desc:This Function Initialize all the CAN Filters         		            */
/********************************************************************************/
static void CAN_voidFiltersInit(void);
/********************************************************************************/

/********************************************************************************/
/*Function: CAN_u32FiltersEnable					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to the Enabled Filters  		            */
/********************************************************************************/
static u32 CAN_u32FiltersEnable(void);
/********************************************************************************/

/********************************************************************************/
/*Function: CAN_u32FiltersMode     					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to Filters modes list or mask            */
/********************************************************************************/
static u32 CAN_u32FiltersMode(void);
/********************************************************************************/

/********************************************************************************/
/*Function: CAN_u32FiltersMode     					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to Filters modes list or mask            */
/********************************************************************************/
static u32 CAN_u32FiltersConf(void);
/********************************************************************************/

/********************************************************************************/
/*Function: CAN_u32FiltersAssign   					                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns u32 Variable                  							    */
/*Desc:This Function returns the value to Filters ssigned to FIFO 0 or 1        */
/********************************************************************************/
static u32 CAN_u32FiltersAssign(void);
/********************************************************************************/

/********************************************************************************/
/*Function: CAN_voidSetIDs							                           	*/
/*I/P Parameters: void															*/
/*Returns:it returns nothing                       							    */
/*Desc:This Function set the IDs For Each Filter in the CAN  		            */
/********************************************************************************/
static void CAN_voidSetIDs(void);

/********************************************************************************************/
/*Function: CAN_voidSetup							                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function setup the CAN Registers	     					                     */
/********************************************************************************************/
static void CAN_voidSetup(void);

/*********************************************************************************************/
/*Function: CAN_voidMode							                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function setup the CAN Mode Test Mode or Not     			                     */
/*********************************************************************************************/
static void CAN_voidMode(void);

/*********************************************************************************************/
/*Function: CAN_voidInitializationMode				                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function allows CAN to Enter Initialization Mode   			                     */
/*********************************************************************************************/
static void CAN_voidInitializationMode(void);

/*********************************************************************************************/
/*Function: CAN_voidInitializationMode				                            			 */
/*I/P Parameters: void																		 */
/*Returns:it returns nothing	                            							     */
/*Desc:This Function allows CAN to Enter Normal Mode		   			                     */
/*********************************************************************************************/
static void CAN_voidStart(void);
/********************************************************************************/



#endif
