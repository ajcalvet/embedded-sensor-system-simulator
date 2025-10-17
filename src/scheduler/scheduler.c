#include "scheduler.h"
#include "config.h"
#include <stdio.h>

static Task tasks[MAX_TASKS];       // Array of currently scheduled tasks
static int task_count = 0;          // Number of currently scheduled tasks

// TO DO: Initilize the scheduler
void scheduler_init() {
    task_count = 0;
    printf("[Scheduler] Initialized.\n");
}

// TO DO: Add a task to the scheduler
void scheduler_add_task(Task* task) {
    if (task_count < MAX_TASKS) {
        tasks[task_count] = *task;
        task_count += 1;
        printf("[Scheduler] Task added. Total: %d\n", task_count);
    }
}

// TO DO: Run the scheduler
void scheduler_run() {
    printf("[Scheduler] Running simulation loop...\n");
    printf("[Scheduler] (Task execution logic will be implemented later)\n");
}