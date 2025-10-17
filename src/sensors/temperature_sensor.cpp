#include "sensor_base.h"
#include <string>
#include <cstdlib>

class TemperatureSensor : public Sensor {
public:
    std::string readData() override {
        // Randomly generature a temperature reading from 20-29 degrees Celsius
        int temp = 20 + rand() % 10;
        return "Temperature " + std::to_string(temp) + " °C";
    }
};