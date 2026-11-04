Wiring and Electrical Connections

1. System Architecture

The ESP32 receives orientation data from the MPU6050 and controls two NEMA 16 stepper motors through separate A4988 drivers.

Signal flow:

MPU6050 → ESP32 → A4988 Drivers → NEMA 16 Motors

2. MPU6050 to ESP32

MPU6050 Pin	ESP32 Pin
VCC	3.3V
GND	GND
SDA	GPIO 21
SCL	GPIO 22

3. Left A4988 Driver

A4988 Pin	ESP32 / Supply
STEP	GPIO 25
DIR	GPIO 26
ENABLE	GPIO 33
VDD	3.3V
GND (logic)	Common GND
VMOT	12V motor supply
GND (motor)	Motor supply GND
1A, 1B, 2A, 2B	Left NEMA 16 motor coils

4. Right A4988 Driver

A4988 Pin	ESP32 / Supply
STEP	GPIO 27
DIR	GPIO 14
ENABLE	GPIO 33
VDD	3.3V
GND (logic)	Common GND
VMOT	12V motor supply
GND (motor)	Motor supply GND
1A, 1B, 2A, 2B	Right NEMA 16 motor coils

5. Power and Safety

* Use a suitable regulated supply for the ESP32.
* Connect all circuit grounds together.
* Install a suitable electrolytic capacitor across VMOT and motor GND near each A4988 driver.
* Set the driver current limit according to the motor’s rated phase current.
* Verify the motor coil pairs before connecting them.
* Never connect or disconnect a stepper motor while its driver is powered.
* Check the A4988 board’s voltage and current limits before operation.

6. Control Configuration

The firmware uses:

* I2C communication for MPU6050.
* STEP and DIR signals for motor control.
* A shared ENABLE signal for both motor drivers.

Note: GPIO assignments are the proposed firmware configuration. Verify the actual board connections before powering the system.