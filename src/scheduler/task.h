#ifndef TASK_H
#define TASK_H

typedef void (*TaskFunction)();

typedef struct {
    TaskFunction function;      // A function that is run to perform the task
    int interval_ms;            // The interval in miliseconds between successive runs
    int last_run;               // Timestamp of last execution of the task 
} Task;

#endif // TASK_H