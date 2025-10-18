#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"

#ifdef __cplusplus
extern "C" {
#endif

void scheduler_init();
void scheduler_add_task(Task* task);
void scheduler_run();

#ifdef __cplusplus
}
#endif

#endif // SCHEDULER_H