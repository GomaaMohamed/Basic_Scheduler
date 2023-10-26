/*****************************************************************************
* @file:    OS_program.c
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 19 Oct 2023 12:12:09 +0300
* @brief:   Basic Scheduler.
******************************************************************************/

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"

/* ==================================================================== */
/* ================= Public Functions Implementation ================== */
/* ==================================================================== */

// Function to create a task
void OS_createTask(u8 TaskId,u16 TaskPeriodicity,u16 FirstDelay,void (*ptrTask)(void))
{
	// Validate input parameters
	ASSERT(ptrTask != NULL);

	// Set task parameters
	Tasks[TaskId].TaskPeriodicity = TaskPeriodicity;
	Tasks[TaskId].TaskHandler = ptrTask;
	Tasks[TaskId].FirstDelay = FirstDelay;
	Tasks[TaskId].TaskState = TASK_READY;
}

// Function to suspend a task
void OS_suspendTask(u8 TaskId)
{
	Tasks[TaskId].TaskState=TASK_SUSPENDED;
}

// Function to resume a task
void OS_resumeTask(u8 TaskId)
{
	Tasks[TaskId].TaskState=TASK_READY;
}

// Function to delete a task
void OS_deleteTask(u8 TaskId)
{
	Tasks[TaskId].TaskHandler=NULL;
}

// Function to start scheduler
void OS_startScheduler(void)
{
	STK_init();

	// when HSE=8Mhz , sytem tick is 1ms
	STK_setPeriodicInterval(1000 , Scheduler);

}
/* ==================================================================== */
/* ================ Private Functions Implementation ================== */
/* ==================================================================== */

// Function to do the scheduling mechanism
static void Scheduler(void)
{
	// Loop on all tasks
	for(u8 taskcounter = 0; taskcounter<NUMBER_OF_TASKS; taskcounter++)
	{
		// chack that task isn't deleted or suspended 
		if((Tasks[taskcounter].TaskHandler != NULL) && (Tasks[taskcounter].TaskState == TASK_READY) )
		{
			// Check until the first delay equal to zero
			if(Tasks[taskcounter].FirstDelay == 0)
			{
				// Use first delay as a task counter
				Tasks[taskcounter].FirstDelay=Tasks[taskcounter].TaskPeriodicity-1;
				// Invoke the task function
				Tasks[taskcounter].TaskHandler();
			}
			else
			{
				// Decrement the first delay
				Tasks[taskcounter].FirstDelay--;
			}
		}
			else
			{
				// Do nothing
			}
	}
}
