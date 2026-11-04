
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <AccelStepper.h>
#include <math.h>

// ---------- HARDWARE PINS ----------
#define LEFT_STEP   25
#define LEFT_DIR    26
#define RIGHT_STEP  27
#define RIGHT_DIR   14
#define ENABLE_PIN  33

#define SDA_PIN     21
#define SCL_PIN     22

// ---------- MOTOR CONFIGURATION ----------
AccelStepper leftMotor(AccelStepper::DRIVER, LEFT_STEP, LEFT_DIR);
AccelStepper rightMotor(AccelStepper::DRIVER, RIGHT_STEP, RIGHT_DIR);

Adafruit_MPU6050 mpu;

// Reverse a motor direction if necessary
const int LEFT_DIRECTION = 1;
const int RIGHT_DIRECTION = -1;

// ---------- BALANCING SETTINGS ----------
float targetAngle = 0.0;
float angle = 0.0;

float Kp = 35.0;
float Ki = 0.0;
float Kd = 1.0;

float integral = 0.0;
float previousError = 0.0;

float gyroOffsetY = 0.0;

const float MAX_SPEED = 1000.0;
const float MAX_ANGLE = 35.0;

unsigned long previousTime = 0;

// ---------- SENSOR CALIBRATION ----------
void calibrateGyro() {
  Serial.println("Keep robot completely still. Calibrating...");

  float total = 0;
  const int samples = 1000;

  sensors_event_t accel, gyro, temp;

  for (int i = 0; i < samples; i++) {
    mpu.getEvent(&accel, &gyro, &temp);
    total += gyro.gyro.y;
    delay(3);
  }

  gyroOffsetY = total / samples;

  Serial.println("Gyro calibration complete.");
}

// ---------- SETUP ----------
void setup() {
  Serial.begin(115200);

  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, HIGH); // Drivers disabled initially

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!mpu.begin()) {
    Serial.println("MPU6050 not detected!");
    while (true) delay(100);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_44_HZ);

  leftMotor.setMaxSpeed(MAX_SPEED);
  rightMotor.setMaxSpeed(MAX_SPEED);

  leftMotor.setMinPulseWidth(2);
  rightMotor.setMinPulseWidth(2);

  calibrateGyro();

  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // Initial angle estimate
  angle = atan2(-accel.acceleration.x,
                 accel.acceleration.z) * 180.0 / PI;

  previousTime = micros();

  digitalWrite(ENABLE_PIN, LOW); // Enable A4988 drivers

  Serial.println("Self-balancing controller started.");
}

// ---------- MAIN CONTROL LOOP ----------
void loop() {
  unsigned long now = micros();

  float dt = (now - previousTime) / 1000000.0;

  if (dt < 0.003) return;
  previousTime = now;

  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // Accelerometer angle
  float accelAngle =
    atan2(-accel.acceleration.x,
           accel.acceleration.z) * 180.0 / PI;

  // Gyroscope angular velocity in degrees/sec
  float gyroRate =
    (gyro.gyro.y - gyroOffsetY) * 180.0 / PI;

  // Complementary filter
  angle = 0.98 * (angle + gyroRate * dt)
        + 0.02 * accelAngle;

  // Safety cutoff
  if (abs(angle) > MAX_ANGLE) {
    leftMotor.setSpeed(0);
    rightMotor.setSpeed(0);

    leftMotor.runSpeed();
    rightMotor.runSpeed();

    integral = 0;
    previousError = 0;

    Serial.println("SAFETY STOP: Robot tilted too far!");
    return;
  }

  // PID calculation
  float error = targetAngle - angle;

  integral += error * dt;
  integral = constrain(integral, -50.0, 50.0);

  float derivative = (error - previousError) / dt;

  float output =
      Kp * error
    + Ki * integral
    + Kd * derivative;

  previousError = error;

  output = constrain(output, -MAX_SPEED, MAX_SPEED);

  // Motor speed commands
  leftMotor.setSpeed(output * LEFT_DIRECTION);
  rightMotor.setSpeed(output * RIGHT_DIRECTION);

  leftMotor.runSpeed();
  rightMotor.runSpeed();

  // Debug output
  static unsigned long lastPrint = 0;

  if (millis() - lastPrint > 100) {
    lastPrint = millis();

    Serial.print("Angle: ");
    Serial.print(angle);

    Serial.print(" | PID: ");
    Serial.println(output);
  }
}
