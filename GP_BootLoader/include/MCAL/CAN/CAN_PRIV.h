/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : CAN DRIVER                       */
/*   DATE        : 22 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_CAN_PRIV_H
#define _MCAL_CAN_PRIV_H

#define CAN ((volatile CAN_t *) 0x40006400)



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
//#define CAN_BaudRate 0x00050000
#define CAN_BaudRate 	0x00060004
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

/**********************************************/
/* 				IER BITS Mapping 			  */
/**********************************************/
/* FIFO message pending interrupt enable */
#define CAN_IER_FMPIE0_Bit 1
/* Transmit mailbox empty interrupt enable */
#define CAN_IER_TMEIE_Bit  0
/**********************************************/

/**********************************************/
/* 				TIR BITS Mapping 			  */
/**********************************************/
/* IDE: Identifier extension */
#define CAN_TIR_IDE_Bit    2
/* RTR: Remote transmission request */
#define CAN_TIR_RTR_Bit    1
/* TXRQ: Transmit mailbox request */
#define CAN_TIR_TXRQ_Bit   0
/* Extended ID Start Bit */
#define CAN_TIR_Extended_StartBit   3
/* Standard ID Start Bit */
#define CAN_TIR_Standard_StartBit   21
/*********************************************/

/**********************************************/
/* 				FIFO BITS Mapping 			  */
/**********************************************/
/*Identifier extension Bit*/
#define CAN_RIR_RTR_Bit  1
/*Remote transmission request Bit*/
#define CAN_RIR_IDE_Bit  1

/**********************************************/
/* 				RF0R BITS Mapping 			  */
/**********************************************/
/* Release FIFO 0 output mailbox              */
#define CAN_RF0R_RFOM0  5
#define CAN_RF0R_FMP00  0
#define CAN_RF0R_FMP01  1
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


#endif
