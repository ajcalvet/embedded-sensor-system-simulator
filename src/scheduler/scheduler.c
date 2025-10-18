#include "scheduler.h"
#include "config.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>

static Task* tasks[MAX_TASKS];      // Array of currently scheduled tasks
static int task_count = 0;          // Number of currently scheduled tasks

// Get the current time in milliseconds
static unsigned long current_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000UL) + (tv.tv_usec / 1000UL);
}

// Initilize the scheduler
void scheduler_init() {
    task_count = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i] = NULL;
    }
    printf("[Scheduler] Initialized.\n");
}

// Add a task to the scheduler
void scheduler_add_task(Task* task) {
    if (task_count < MAX_TASKS) {
        tasks[task_count] = task;
        task_count += 1;
        printf("[Scheduler] Task added. Total: %d\n", task_count);
    } else {
        printf("[Scheduler] Scheduler full. Cannot add more tasks.");
    }
}

// Run the scheduler
void scheduler_run() {
    printf("[Scheduler] Running simulation loop...\n");

    unsigned long start_time = current_time_ms();

    while (1) {
        unsigned long now = current_time_ms();
        bool task_ran = false;
        for (int i = 0; i < task_count; i++) {
            if(tasks[i]) {
                // Check that the time interval between successive runs has elapsed for this task
                if (now - tasks[i]->last_run >= tasks[i]->interval_ms) {
                    // Print timestamped log
                    unsigned long since_start = now - start_time;
                    printf("[%06lu ms] [Scheduler] Running task #%d (%s)\n", since_start, i, tasks[i]->name);
                    // Run the task
                    tasks[i]->function();
                    tasks[i]->last_run = now;
                    task_ran = true;
                }
            }
        }
        // Sleep for SYSTEM_TICK_MS milliseconds to reduce CPU usage
        usleep(SYSTEM_TICK_MS * 1000);
        if (task_ran) printf("-------------------------------------------------\n");
    }
}