#include "sensor_base.h"
#include <iostream>
#include <vector>

void fuseSensorData(const std::vector<Sensor*>& sensors) {
    std::cout << "[Fusion] Fusing sensor data...\n";
    for (auto* sensor : sensors) {
        std::cout << "  - " << sensor->readData() << "\n";
    }
}