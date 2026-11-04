ESP32-Based Self-Balancing Robot

<div align="center">

🤖 SELF-BALANCING ROBOT

ESP32 | MPU6050 | A4988 | NEMA 16

Design and Development of a Low-Power ESP32-Based Self-Balancing Robot

</div>

⸻

📌 Project Overview

This project focuses on designing and developing a two-wheeled self-balancing robot using an ESP32 microcontroller.

The robot uses an MPU6050 inertial measurement unit (IMU) to measure its orientation and angular velocity. The ESP32 processes the sensor information and calculates motor commands using a closed-loop PID control system.

Two NEMA 16 stepper motors, controlled through A4988 stepper motor drivers, provide movement to maintain the robot’s balance.

🎯 Project Objectives

* Develop a two-wheel self-balancing robotic platform.
* Implement real-time tilt measurement using MPU6050.
* Develop PID-based closed-loop control.
* Control two stepper motors using ESP32.
* Explore wireless robot monitoring and control.
* Develop forward, backward, left and right movement capabilities.

🛠️ Hardware Components

Component	Quantity	Function
ESP32	1	Main controller
MPU6050	1	Gyroscope and accelerometer
A4988 Driver	2	Stepper motor control
NEMA 16 Stepper Motor	2	Left and right wheel drive
12V Power Supply	1	Motor power
Robot Chassis	1	Mechanical structure
Wheels	2	Locomotion

⚙️ System Architecture

1. MPU6050 measures acceleration and angular velocity.
2. ESP32 reads sensor data through I2C communication.
3. Sensor fusion estimates the robot’s tilt angle.
4. PID controller calculates the required correction.
5. ESP32 generates STEP and DIR signals.
6. A4988 drivers control the left and right stepper motors.
7. Motor movement helps correct the robot’s tilt.

🔌 Communication Interfaces

Interface	Connection
I2C	ESP32 ↔ MPU6050
Digital GPIO	ESP32 ↔ A4988
STEP / DIR	ESP32 ↔ Motor drivers
Power	External motor supply

🧠 Control Algorithm

The robot uses a closed-loop feedback control approach.

1. Sensor Measurement

The MPU6050 provides:

* Accelerometer readings
* Gyroscope readings
* Angular velocity

2. Sensor Fusion

A complementary filter can combine accelerometer and gyroscope data to estimate the robot’s tilt angle.

3. PID Control

The PID controller calculates motor correction using:

PID = Kp × Error + Ki × Integral + Kd × Derivative

Where:

* Kp = Proportional gain
* Ki = Integral gain
* Kd = Derivative gain
* Error = Difference between target and measured tilt angle

4. Motor Control

The ESP32 generates step and direction signals for both A4988 drivers.

📂 Project Structure

ESP32-Self-Balancing-Robot/
│
├── README.md
│
├── Code/
│   ├── main.ino
│   ├── mpu6050.ino
│   ├── pid_controller.ino
│   └── motor_control.ino
│
├── Circuit/
│   └── wiring_diagram.png
│
├── Images/
│   └── robot_prototype.jpg
│
└── Documentation/
    ├── components.md
    └── working_principle.md

🔬 Engineering Considerations

* Sensor calibration is essential for accurate angle estimation.
* PID gains require experimental tuning.
* Both motors must be synchronized.
* Motor driver current limits must match the motor specifications.
* The ESP32 and motor drivers must share a common ground.
* A suitable power supply and thermal management are important.

🚀 Future Development

* Wireless control interface.
* Improved PID tuning.
* Real-time sensor monitoring.
* Directional movement control.
* Improved mechanical stability.
* Performance testing and optimization.

👨‍💻 Developer

Mohammed Arshan M

B.E. Mechatronics Engineering

Interests: Robotics | Embedded Systems | Electric Vehicles | Industrial Automation

⸻

<div align="center">

ENGINEERING IDEAS INTO REAL-WORLD SOLUTIONS.

</div>