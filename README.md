ESP32 SELF-BALANCING ROBOT

Embedded Systems | Robotics | Motion Control | PID Control

<p align="center">
  <img src="https://img.shields.io/badge/Platform-ESP32-black?style=for-the-badge&logo=espressif" />
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus" />
  <img src="https://img.shields.io/badge/Sensor-MPU6050-purple?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Status-Development-orange?style=for-the-badge" />
</p>

⸻

Overview

A two-wheeled self-balancing robot developed using an ESP32 microcontroller, MPU6050 inertial measurement sensor, and stepper motor control system.

The project explores real-time motion sensing, feedback control, embedded programming, and robotic stability.

System Architecture

       MPU6050
           |
           | I2C
           |
         ESP32
           |
      PID Controller
           |
      STEP / DIR
        /     \
   A4988     A4988
     |          |
 NEMA 16    NEMA 16
   LEFT       RIGHT

Hardware Components

Component	Quantity
ESP32 Development Board	1
MPU6050 Sensor	1
A4988 Stepper Driver	2
NEMA 16 Stepper Motor	2
Motor Power Supply	1

Software & Technologies

* Arduino IDE
* C/C++
* ESP32 Programming
* I2C Communication
* MPU6050 Sensor Integration
* Complementary Filter
* PID Control
* Stepper Motor Control

Control Method

The MPU6050 measures acceleration and angular velocity.

The ESP32 processes sensor data using a complementary filter to estimate tilt angle.

A PID controller calculates the corrective output required to control the two stepper motors.

Repository Structure

ESP32-Self-Balancing-Robot/
│
├── main.ino
├── README.md
├── components.md
├── wiring.md
├── LICECE
├── .gitignore
│
├── docs/
│   └── project-overview.md
│
├── images/
│   └── README.md
│
├── src/
│   └── README.md
│
└── assets/
    └── README.md

Development Goals

* Real-time tilt detection
* Closed-loop balancing control
* Stable stepper motor operation
* Wireless robot control
* Improved response and stability

Current Development Status

Hardware integration and firmware development are ongoing.

Future Improvements

* Wireless mobile control
* Improved sensor filtering
* PID parameter optimization
* Robot movement in multiple directions
* Mechanical and electrical optimization

⸻

<p align="center">
  <b>Designed & Developed by Mohammed Arshan M</b>
  <br>
  Mechatronics Engineering | Robotics | Embedded Systems
</p>