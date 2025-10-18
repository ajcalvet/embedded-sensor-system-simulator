# Compilers
CXX = g++			# Use g++ for C++ files
CC = gcc			# Use gcc for C files

# Compiler options
CXXFLAGS = -std=c++17 -Wall -Iinclude -Isrc/scheduler -Isrc/sensors -Isrc/logger
CFLAGS = -Wall -Iinclude -Isrc/scheduler

# Output folder (program saved as build/simulator)
BUILD_DIR = build
TARGET = $(BUILD_DIR)/simulator

# Source files
SRC_C = $(wildcard src/scheduler/*.c)
SRC_CPP = $(wildcard src/*.cpp src/sensors/*.cpp src/logger/*.cpp)

# Object files
OBJ_C = $(patsubst src/scheduler/%.c,$(BUILD_DIR)/scheduler/%.o,$(SRC_C))
OBJ_CPP = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(filter-out src/sensors/%.cpp src/logger/%.cpp,$(wildcard src/*.cpp)))
OBJ_CPP += $(patsubst src/sensors/%.cpp,$(BUILD_DIR)/sensors/%.o,$(wildcard src/sensors/*.cpp))
OBJ_CPP += $(patsubst src/logger/%.cpp,$(BUILD_DIR)/logger/%.o,$(wildcard src/logger/*.cpp))
OBJ = $(OBJ_C) $(OBJ_CPP)

# Ensure all build subdirectories exist
DIRS = $(BUILD_DIR) $(BUILD_DIR)/scheduler $(BUILD_DIR)/sensors $(BUILD_DIR)/logger

# Build the program
all: $(DIRS) $(TARGET)

$(DIRS):
	@mkdir -p $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rules for compiling C files
$(BUILD_DIR)/scheduler/%.o: src/scheduler/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rules for compiling C++ files
$(BUILD_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/sensors/%.o: src/sensors/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/logger/%.o: src/logger/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Delete build folder and object files
clean:
	rm -rf $(BUILD_DIR)

# To build and run
run: all
	./$(TARGET)