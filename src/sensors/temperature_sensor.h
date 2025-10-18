#pragma once
#include "sensor_base.h"

class TemperatureSensor : public Sensor {
public:
    std::string readData() override;
};