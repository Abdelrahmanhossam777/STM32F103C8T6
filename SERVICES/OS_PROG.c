/****************************************************/
/* 				Library Directives 					*/
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* 			      OS Directives 					*/
/****************************************************/
#include "../include/SERVICES/OS_INT.h"
#include "../include/SERVICES/OS_CONF.h"
#include "../include/SERVICES/OS_PRIV.h"


/****************************************************/
/* 				 SYSTICK Directives 				*/
/****************************************************/
#include"../include/MCAL/SYSTICK/SYSTICK_CONF.h"
#include"../include/MCAL/SYSTICK/SYSTICK_PRIV.h"
#include"../include/MCAL/SYSTICK/SYSTICK_INT.h"

volatile u16 TickCounts=0;




/***************************************************************************************************/
/*Function: OS_voidCreateTask                           			                     		   */
/*I/P Parameters:u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr) (void), u8 copy_u8FirstDelay    */
/*Returns:it returns void                                				  						   */
/*Desc:This Function Creates a new task with all the needed parameters          	          	   */
/***************************************************************************************************/
void OS_voidCreateTask (u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr) (void), u8 copy_u8FirstDelay)
{
  	OS_Tasks[copy_u8ID].priodicity = copy_u16Priodicity;
  	OS_Tasks[copy_u8ID].Fptr = ptr;
  	OS_Tasks[copy_u8ID].FirstDelay=copy_u8FirstDelay;
  	OS_Tasks[copy_u8ID].Status=TASK_READY;
}

/***************************************************************************************************/
/*Function: OS_voidStart                                			                     		   */
/*I/P Parameters:void																		       */
/*Returns:it returns void                                				  						   */
/*Desc:This Function starts the os scheduler							         	          	   */
/***************************************************************************************************/
void OS_voidStart(void)
{
	/* SYSTICK Timer Configuration  */
	SYSTICk_ErrorStatusConfig();
    SYSTICK_voidSetIntervalPeriodic(1000,Scheduler);
}

/***************************************************************************************************/
/*Function: OS_voidSuspendTask                            			                     		   */
/*I/P Parameters:void																		       */
/*Returns:it returns void                                				  						   */
/*Desc:This Function sets the state of the task to be suspended			         	          	   */
/***************************************************************************************************/
void OS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].Status=TASK_SUSPENDED;
}

/***************************************************************************************************/
/*Function: OS_voidResumeTask                            			                     		   */
/*I/P Parameters: Copy_u8TaskID																	   */
/*Returns:it returns void                                				  						   */
/*Desc:This Function sets the state of the task to be ready  			         	          	   */
/***************************************************************************************************/
void OS_voidResumeTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].Status=TASK_READY;
}

/***************************************************************************************************/
/*Function: OS_voidDeleteTask                            			                     		   */
/*I/P Parameters: Copy_u8TaskID																	   */
/*Returns:it returns void                                				  						   */
/*Desc:This Function deletes a task from our os							         	          	   */
/***************************************************************************************************/
void OS_voidDeleteTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].Fptr = NULL;
}

/***************************************************************************************************/
/*Function: Scheduler		                            			                     		   */
/*I/P Parameters: Void																			   */
/*Returns:it returns void                                				  						   */
/*Desc:This Function Schedules the tasks of the OS						         	          	   */
/***************************************************************************************************/
void Scheduler (void)
{
	//static u16 Local_u16TickCounter=0;
		u8 Local_u8TaskCounter;

	for (Local_u8TaskCounter=0; Local_u8TaskCounter < NumberOfTasks; Local_u8TaskCounter++)
	{
		/*check that task isn't deleted or suspended */
		if((OS_Tasks[Local_u8TaskCounter].Fptr)==NULL  && OS_Tasks[Local_u8TaskCounter].Status== TASK_READY)
		{
			/*Check until the first delay equal to zero*/
			if (OS_Tasks[Local_u8TaskCounter].FirstDelay==0)
			{
				OS_Tasks[Local_u8TaskCounter].FirstDelay=OS_Tasks[Local_u8TaskCounter].priodicity-1;
				/*Invoke the task function*/
				OS_Tasks[Local_u8TaskCounter].Fptr();
			}
			else
			{
				/* Decrement the first delay */
				OS_Tasks[Local_u8TaskCounter].FirstDelay--;
			}
		}
		else
		{
			/* Do Nothing */
		}
	}

}


