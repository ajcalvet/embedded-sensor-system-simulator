#include "scheduler.h"
#include "task.h"
#include "motion_sensor.h"
#include "temperature_sensor.h"
#include "fusion_module.h"
#include "data_logger.h"
#include <vector>
#include <iostream>
#include <chrono>

// Sensors
static TemperatureSensor temp_sensor;
static MotionSensor motion_sensor;
static std::vector<Sensor*> sensors = {&temp_sensor, &motion_sensor};

// Logger
DataLogger logger("logs/data.csv", true);  // true = overwrite CSV on start

// Start time for timestamps
// auto program_start = std::chrono::steady_clock::now();
//void logTaskExecution(const std::string& taskName) {
//    auto now = std::chrono::steady_clock::now();
//    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - program_start).count();
//    std::cout << taskName << " executed!\n";
//}

// Task functions
void read_temperature_sensor() {
    std::cout << "\t\t[Temp Task]\t" << temp_sensor.readData() << "\n";
}

void read_motion_sensor() {
    std::cout << "\t\t[Motion Task]\t" << motion_sensor.readData() << "\n";

}

void run_fusion_module() {
    auto readings = fuseSensorData(sensors);
    std::cout << "\t\t[Fusion Task]\tSensor readings:\n";
    for (const auto& reading : readings) {
        std::cout << "\t\t\t\t- " << reading << "\n";
    }
    // Log readings to CVS file
    auto readings_numerical = getSensorDataNumerical(sensors);
    logger.logToCSV(readings_numerical);
}

int main() {
    scheduler_init();

    Task temp_task   = {read_temperature_sensor, 1000, 0, "Temperature Reading"}; // Report temp every 1 s
    Task motion_task = {read_motion_sensor,       500, 0, "Motion Detection"};    // Report motion every 500 ms
    Task fusion_task = {run_fusion_module,       2000, 0, "Fusion Module"};       // Combine temp + motion every 2 s
    
    scheduler_add_task(&temp_task);
    scheduler_add_task(&motion_task);
    scheduler_add_task(&fusion_task);

    // Loop forever
    scheduler_run();
    return 0;
}