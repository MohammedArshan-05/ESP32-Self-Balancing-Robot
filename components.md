Hardware Components

Main Controller

* ESP32 Development Board

Sensors

* MPU6050 6-Axis Accelerometer and Gyroscope

Motor Control

* 2 × A4988 Stepper Motor Drivers
* 2 × NEMA 16 Stepper Motors

Power Supply

* 12V DC Motor Power Supply
* Suitable regulated power supply for the ESP32

System Overview

The ESP32 acts as the central controller. The MPU6050 provides orientation and motion data, while the A4988 drivers control the left and right stepper motors.

Control architecture:

MPU6050 → ESP32 → A4988 Drivers → NEMA 16 Motors

Note: Exact motor current ratings and power specifications will be added after component verification.