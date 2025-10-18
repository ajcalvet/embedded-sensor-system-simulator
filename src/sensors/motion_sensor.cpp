#include "motion_sensor.h"
#include <string>
#include <cstdlib>

std::string MotionSensor::readData() {
    // Detect motion half the time on average
    bool motion = rand() % 2;
    return motion ? "Motion detected" : "No motion detected";
}