#include "motion_sensor.h"
#include <string>
#include <cstdlib>

std::string MotionSensor::readData() {
    // If motion detected, motion persists for a few ticks
    if (cooldown > 0) {
        cooldown -= 1;
        return "Motion detected";
    }
    // Detect motion 20% of the time on average
    if (rand() % 5 == 0) {
        cooldown = 3;
        return "Motion detected";
    }
    return "No motion detected";
}