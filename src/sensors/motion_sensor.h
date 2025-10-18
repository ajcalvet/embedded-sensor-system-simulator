#pragma once
#include "sensor_base.h"

class MotionSensor : public Sensor {
public:
    std::string readData() override;
};