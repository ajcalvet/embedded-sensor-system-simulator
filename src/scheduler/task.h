#ifndef TASK_H
#define TASK_H

typedef void (*TaskFunction)();

typedef struct {
    TaskFunction  function;                 // A function that is run to perform the task
    unsigned long interval_ms;              // The interval in miliseconds between successive runs
    unsigned long last_run;                 // Timestamp of last execution of the task
    const char* name;
} Task;

#endif // TASK_H