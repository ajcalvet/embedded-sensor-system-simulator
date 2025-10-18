#include "temperature_sensor.h"
#include <string>
#include <cstdlib>

std::string TemperatureSensor::readData() {
    // Drift temperature by +/- 1 C
    temp += (rand() % 3) - 1;
    if (temp < 18) temp = 18;
    if (temp > 32) temp = 32;
    return "Temperature " + std::to_string(temp) + " °C";
}