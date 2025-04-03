/*
 * This header defines global constants and methods.
 */

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

// PS2X controller pins
#define PS2X_CLK_PIN  46
#define PS2X_CS_PIN  48
#define PS2X_CMD_PIN  50
#define PS2X_DAT_PIN  52
#define pressures false
#define rumble false

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

// Global methods
void InitPins(); // Initialize all the pins used in the program, except for the PS2 controller

#endif // _GLOBALS_H_