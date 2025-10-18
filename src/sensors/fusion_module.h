#pragma once
#include "sensor_base.h"
#include <vector>
#include <string>

std::vector<std::string> fuseSensorData(const std::vector<Sensor*>& sensors);
std::vector<int> getSensorDataNumerical(const std::vector<Sensor*>& sensors);