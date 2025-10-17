# Embedded Sensor System Simulator

A hybrid C/C++ project that simulates an embedded system managing multiple sensors through a cooperative scheduler.

## Components
- **C scheduler** — handles periodic task execution
- **C++ sensors** — simulate data streams (temperature, motion)
- **Fusion module** — aggregates and interprets sensor data
- **Main loop** — integrates C scheduler and C++ modules

## Build and Run

```
make
./build/simulator
```