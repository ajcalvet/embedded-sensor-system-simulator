#include "scheduler.h"
#include "task.h"
#include <iostream>
#include <chrono>

// Start time for timestamps
// auto program_start = std::chrono::steady_clock::now();

void logTaskExecution(const std::string& taskName) {
    // auto now = std::chrono::steady_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - program_start).count();
    std::cout << taskName << " executed!\n";
}

// Dummy tasks
// TO DO: Replace with real tasks
void taskA() {
    logTaskExecution("Task A");
}

void taskB() {
    logTaskExecution("Task B");
}

int main() {
    std::cout << "Starting simulator...\n";
    
    scheduler_init();
    std::cout << "Scheduler initialized...\n";

    Task t_a = {taskA, 1000, 0, "Task A"};         // Run every 1 sec
    Task t_b = {taskB, 2000, 0, "Task B"};         // Run every 2 secs
    
    scheduler_add_task(&t_a);
    scheduler_add_task(&t_b);

    std::cout << "Running the scheduler...\n";
    scheduler_run();                         // Loop forever
    return 0;
}