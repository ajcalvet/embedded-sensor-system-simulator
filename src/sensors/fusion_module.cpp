#include "fusion_module.h"
#include <iostream>
#include <vector>
#include <string>

// Takes a vector of sensors and outputs a vector of their readings
std::vector<std::string> fuseSensorData(const std::vector<Sensor*>& sensors) {
    std::vector<std::string> readings;
    readings.reserve(sensors.size());

    for (auto* sensor : sensors) {
        readings.push_back(sensor->readData());
    }

    return readings;
}

// Takes a vector of sensors and outputs a vector of their last numerical readings
std::vector<int> getSensorDataNumerical(const std::vector<Sensor*>& sensors) {
    std::vector<int> readings_numerical;
    readings_numerical.reserve(sensors.size());

    for (auto* sensor : sensors) {
        readings_numerical.push_back(sensor->getNumerical());
    }

    return readings_numerical;
}