/*****************************************************************************
* @file:    OS_private.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Wed, 19 Oct 2023 12:12:09 +0300
* @brief:   Basic Scheduler.
******************************************************************************/
#ifndef _OS_PRIVATE_H
#define _OS_PRIVATE_H

/* ==================================================================== */
/* ======================= Private Data Types ========================= */
/* ==================================================================== */

typedef struct
{
	u16 TaskPeriodicity;
	u16	FirstDelay;
	u8  TaskState;
	void (*TaskHandler)(void);
}Task_type;


/* ==================================================================== */
/* =================== Private Variables and Macros =================== */
/* ==================================================================== */

/* Private configurations */
#define	  TASK_SUSPENDED  1
#define	  TASK_READY	  2

/* Tasks buffer */
static Task_type Tasks[NUMBER_OF_TASKS] = {0};


/* ==================================================================== */
/* ==================== Private Functions Declaration ================= */
/* ==================================================================== */

/* Scheduler */
static void Scheduler(void);


#endif