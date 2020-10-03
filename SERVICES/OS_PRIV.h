/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : OS DRIVER                        */
/*   DATE        : 4 SEP 2020                       */
/*   VERSION     : V01                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef SERVICES_OS_PRIV_H_
#define SERVICES_OS_PRIV_H_

/********************************/
/* Task Status Definition 		*/
/********************************/
#define	TASK_SUSPENDED	1
#define	TASK_READY		2

/************************************************/
/* Definition of the new type which called Task */
/************************************************/
typedef struct
{
 	u16 priodicity;
 	void (*Fptr) (void);
 	u8 FirstDelay;
 	u8 Status;
}Task;




/************************************/
/* Array of the new variable task   */
/************************************/
static Task OS_Tasks [NumberOfTasks]={NULL};

/***************************************************************************************************/
/*Function: Scheduler		                            			                     		   */
/*I/P Parameters: Void																			   */
/*Returns:it returns void                                				  						   */
/*Desc:This Function Schedules the tasks of the OS						         	          	   */
/***************************************************************************************************/
void Scheduler (void);

#endif
