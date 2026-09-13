# Health Monitoring System

An ESP32-based health monitoring device that tracks body temperature and heart rate (BPM), displaying live readings on an LCD and Serial Monitor.

## Components Used
- ESP32 development board
- DS18B20 Temperature Sensor (OneWire)
- Heart Rate Pulse Sensor (digital)
- 16x2 LCD (parallel interface)

## How It Works
- A DS18B20 sensor reads temperature over the OneWire protocol.
- A pulse sensor detects heartbeats via digital input; beats are counted and converted to BPM every 5 seconds.
- Both readings are displayed on a 16x2 LCD and printed to the Serial Monitor, updated every 5 seconds.

## Protocols/Concepts Used
- OneWire communication (DS18B20 temperature sensor)
- Digital pulse detection and BPM calculation
- Parallel LCD interfacing (LiquidCrystal library)
- Timing-based updates using `millis()`

## Code
See `health_monitoring.ino` for the full sketch.
