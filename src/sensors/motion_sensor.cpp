#include "sensor_base.h"
#include <string>
#include <cstdlib>

class MotionSensor : public Sensor {
public:
    std::string readData() override {
        // Detect motion half the time on average
        bool motion = rand() % 2;
        return motion ? "Motion detected" : "No motion detected";
    }
};