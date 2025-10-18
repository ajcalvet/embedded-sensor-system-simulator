#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include <vector>
#include <string>

class DataLogger {
public:
    // filename: path to CSV file
    // overwrite: if true, clears the file and writes headers at start
    DataLogger(const std::string& filename, bool overwrite = false);
    
    ~DataLogger();

    // Log a single row of data
    // Each string in the vector corresponds to a column
    void logToCSV(const std::vector<int>& row);

private:
    std::string filename_;       // CSV filename
};

#endif // DATA_LOGGER_H