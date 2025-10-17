#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"

void scheduler_init();
void scheduler_add_task(Task* task);
void scheduler_run();

#endif // SCHEDULER_H