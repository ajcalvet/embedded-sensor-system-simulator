#pragma once
#include "sensor_base.h"

class MotionSensor : public Sensor {
    int cooldown = 0;                       // Counts down ticks until no motion
    int motion   = 0;                       // 0 = no motion, 1 = motion
public:
    std::string readData() override;
    int         getNumerical() override;
};