/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : OS DRIVER                        */
/*   DATE        : 4 SEP 2020                       */
/*   VERSION     : V01                              */
/****************************************************/


/*****************************/
/*        FILE GUARD         */
/*****************************/
#ifndef SERVICES_OS_INT_H_
#define SERVICES_OS_INT_H_

/***************************************************************************************************/
/*Function: OS_voidCreateTask                           			                     		   */
/*I/P Parameters:u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr) (void), u8 copy_u8FirstDelay    */
/*Returns:it returns void                                				  						   */
/*Desc:This Function Creates a new task with all the needed parameters          	          	   */
/***************************************************************************************************/
void OS_voidCreateTask (u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr) (void), u8 copy_u8FirstDelay);

/***************************************************************************************************/
/*Function: OS_voidStart                                			                     		   */
/*I/P Parameters:void																		       */
/*Returns:it returns void                                				  						   */
/*Desc:This Function starts the os scheduler							         	          	   */
/***************************************************************************************************/
void OS_voidStart(void);

/***************************************************************************************************/
/*Function: OS_voidSuspendTask                            			                     		   */
/*I/P Parameters:void																		       */
/*Returns:it returns void                                				  						   */
/*Desc:This Function sets the state of the task to be suspended			         	          	   */
/***************************************************************************************************/
void OS_voidSuspendTask(u8 Copy_u8TaskID);

/***************************************************************************************************/
/*Function: OS_voidResumeTask                            			                     		   */
/*I/P Parameters: Copy_u8TaskID																	   */
/*Returns:it returns void                                				  						   */
/*Desc:This Function sets the state of the task to be ready  			         	          	   */
/***************************************************************************************************/
void OS_voidResumeTask(u8 Copy_u8TaskID);

/***************************************************************************************************/
/*Function: OS_voidDeleteTask                            			                     		   */
/*I/P Parameters: Copy_u8TaskID																	   */
/*Returns:it returns void                                				  						   */
/*Desc:This Function deletes a task from our os							         	          	   */
/***************************************************************************************************/
void OS_voidDeleteTask(u8 Copy_u8TaskID);

#endif
