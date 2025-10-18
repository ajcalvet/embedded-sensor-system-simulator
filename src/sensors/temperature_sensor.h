#pragma once
#include "sensor_base.h"

class TemperatureSensor : public Sensor {
    int temp = 25;                          // Start temperature near 25 degrees Celsius
public:
    std::string readData() override;
    int         getNumerical() override;
};