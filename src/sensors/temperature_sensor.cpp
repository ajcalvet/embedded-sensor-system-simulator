#include "temperature_sensor.h"
#include <string>
#include <cstdlib>

std::string TemperatureSensor::readData() {
    // Randomly generature a temperature reading from 20-29 degrees Celsius
    int temp = 20 + rand() % 10;
    return "Temperature " + std::to_string(temp) + " °C";
}