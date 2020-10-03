/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : CAN DRIVER                       */
/*   DATE        : 22 SEP 2020                      */
/*   VERSION     : V01                              */
/****************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_CAN_CONF_H
#define _MCAL_CAN_CONF_H

/* Initialization request */
#define CAN_MCR_INRQ      1
/* Automatic bus-off management */
#define CAN_MCR_ABOM  1
/*Transmit FIFO priority*/
#define CAN_MCR_TXFP	  1
/*Receive FIFO locked mode*/
#define CAN_MCR_RFLM      0
/* No automatic retransmission */
#define CAN_MCR_NART      0
/*Sleep mode request*/
#define CAN_MCR_SLEEP     0
/*Time triggered communication mode*/
#define CAN_MCR_TTCM	  0
/*Automatic wakeup mode*/
#define CAN_MCR_AWUM      0
/*Debug freeze*/
#define CAN_MCR_DBFG       0



/* FIFO message pending interrupt enable */
#define CAN_IER_FMPIE0     1
/* Transmit mailbox empty interrupt enable */
#define CAN_IER_TMEIE      1

/**********************************************/
/* Number of messages to be sent or received  */
/**********************************************/
#define Number_of_TxMessages 2
#define Number_of_RxMessages 2
/***************************************************************************/
extern CAN_Msg       CAN_TxMsg[Number_of_TxMessages];      // CAN message for sending
extern CAN_Msg       CAN_RxMsg[Number_of_RxMessages];      // CAN message for receiving
/***************************************************************************/
#endif
