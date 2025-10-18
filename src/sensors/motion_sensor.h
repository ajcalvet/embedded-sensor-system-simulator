#pragma once
#include "sensor_base.h"

class MotionSensor : public Sensor {
    int cooldown = 0;                       // Counts down ticks until no motion
public:
    std::string readData() override;
};