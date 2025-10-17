#ifndef SENSOR_BASE_H
#define SENSOR_BASE_H

#include <string>

class Sensor {
public:
    virtual ~Sensor() = default;            // Destructor
    virtual std::string readData() = 0;     // Returns a string representing the sensor reading
};

#endif // SENSOR_BASE_H