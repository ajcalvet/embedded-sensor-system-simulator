
#include "data_logger.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

DataLogger::DataLogger(const std::string& filename, bool overwrite) : filename_(filename)
{
    if (overwrite) {
        std::ofstream file(filename_, std::ios::trunc);
        if (!file) {
            std::cout << "\t\t[DataLogger]\tFailed to open file for writing: " << filename_ << "\n";
            return;
        }
        // Write header row
        file << "Timestamp,Temperature,Motion\n";
    }
}

DataLogger::~DataLogger() {}

void DataLogger::logToCSV(const std::vector<int>& row) {
    std::ofstream file(filename_, std::ios::app);
    if (!file.is_open()) {
        std::cout << "\t\t[DataLogger]\tFailed to open file: " << filename_ << "\n";
        return;
    }

    // Get timestamp
    std::time_t now = std::time(nullptr);
    char timestamp[64];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    file << timestamp;

    // Write each value from the row
    for (const auto& val : row) {
        file << "," << std::to_string(val);
    }
    file << "\n";
}