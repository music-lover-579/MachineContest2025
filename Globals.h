/*
 * This header defines global constants, structures, and methods.
 */

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <Arduino.h>
#include <Servo.h>

// 1-bit data types
typedef unsigned char ubyte;
typedef signed char byte;

// PS2X controller pins
#define PS2X_CLK_PIN  46
#define PS2X_CS_PIN  48
#define PS2X_CMD_PIN  50
#define PS2X_DAT_PIN  52
#define pressures false
#define rumble false

// PS2X controller buttons mapping
#define BOTTOM_SERVO_DOWN PSB_PAD_DOWN
#define BOTTOM_SERVO_UP PSB_PAD_UP
#define MIDDLE_SERVO_DOWN PSB_PAD_RIGHT
#define MIDDLE_SERVO_UP PSB_PAD_LEFT
#define PAW_SERVO_CLOSE PSB_PINK
#define PAW_SERVO_OPEN PSB_RED
#define STEPPER_UP PSB_GREEN
#define STEPPER_DOWN PSB_BLUE
// TODO: Add more buttons for advanced movements

// Wheel motor pins
#define LF_IN1_PIN 32
#define LF_IN2_PIN 33
#define RF_IN1_PIN 34
#define RF_IN2_PIN 35
#define LB_IN1_PIN 36
#define LB_IN2_PIN 37
#define RB_IN1_PIN 38
#define RB_IN2_PIN 39
#define LF_PWM_PIN 2
#define RF_PWM_PIN 3
#define LB_PWM_PIN 4
#define RB_PWM_PIN 5

// Servo pins
#define BOTTOM_SERVO_PIN 8
#define MIDDLE_SERVO_PIN 9
#define PAW_SERVO_PIN 10

// Servo angles
// TODO: Replace with actual values
#define BOTTOM_SERVO_MIN 10
#define BOTTOM_SERVO_MAX 130
#define MIDDLE_SERVO_MIN 30
#define MIDDLE_SERVO_MAX 130
#define PAW_SERVO_MIN 0
#define PAW_SERVO_MAX 180
#define BOTTOM_SERVO_INITIAL 90
#define MIDDLE_SERVO_INITIAL 90
#define PAW_SERVO_MIN_INITIAL 0

// Servo status bitmask
#define BOTTOM_SERVO_CHANGE 0x01
#define BOTTOM_SERVO_DIRECTION_IS_UP 0x02
#define MIDDLE_SERVO_CHANGE 0x04
#define MIDDLE_SERVO_DIRECTION_IS_UP 0x08
#define PAW_SERVO_CHANGE 0x10
#define PAW_SERVO_DIRECTION_IS_OPEN 0x20

// Stepper motor pins
#define STEPPER_DIRECTION_PIN 24
#define STEPPER_STEP_PIN 22
#define STEPPER_ENABLE_PIN 26

// Stepper motor steps
#define STEPPER_STEPS_PER_REVOLUTION 36000 // Number of steps per revolution
#define STEPPER_STEP_DELAY 1000 // Delay between steps in microseconds
#define UP true
#define DOWN false

// Motor speed structure
struct MotorSpeed {
  byte LF;
  byte RF;
  byte LB;
  byte RB;
};

// Servo angle structure
struct ServoAngle {
	ubyte BOTTOM;
	ubyte MIDDLE;
	ubyte PAW;
};

// Arm structure
struct Arm {
  Servo bottom;
  Servo middle;
  Servo paw;
};

// Global methods
void InitWheels(); // Initialize the mecanum wheels
void InitArm(Arm& arm); // Initialize the servos
void InitStepper(); // Initialize the stepper motor

#endif // _GLOBALS_H_