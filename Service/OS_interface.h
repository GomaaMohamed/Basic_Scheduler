/*****************************************************************************
* @file:    OS_interface.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 19 Oct 2023 12:12:09 +0300
* @brief:   Basic Scheduler.
******************************************************************************/
#ifndef _OS_INTERFACE_H
#define _OS_INTERFACE_H

/* ==================================================================== */
/* ==================== Public Functions Declaration ================== */
/* ==================================================================== */

/**
 * @brief---------------------> Create a task 
 * @parameter1----------------> (TaskId) id of the task to be created
 * @parameter2----------------> (TaskPeriodicity) periodicity of the task to be created
 * @parameter3----------------> (FirstDelay) first delay of the task to be created
 * @parameter4----------------> (ptrTask) pointer to the task to be created
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant
 */
void OS_createTask(u8 TaskId,u16 TaskPeriodicity,u16 FirstDelay, void (*ptrTask)(void));

/**
 * @brief---------------------> Suspend a task 
 * @parameter1----------------> (TaskId) id of the task to be suspended
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant
 */
void OS_suspendTask(u8 TaskId);

/**
 * @brief---------------------> Resume a task 
 * @parameter1----------------> (TaskId) id of the task to be resumed
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant
 */
void OS_resumeTask(u8 TaskId);

/**
 * @brief---------------------> Delete a task 
 * @parameter1----------------> (TaskId) id of the task to be deleted
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant
 */
void OS_deleteTask(u8 TaskId);

/**
 * @brief---------------------> Start scheduler
 * @param---------------------> None
 * @return--------------------> None
 * @preconditions-------------> None
 * @postconditions------------> None
 * @synchronous/asynchronous--> Synchronous
 * @reentrant/non-reentrant---> Non-Reentrant
 */
void OS_startScheduler(void);


#endif