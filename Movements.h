/*
 * This header contains methods that realize abstract movements of the robot.
 */

#ifndef _MOVEMENTS_H_
#define _MOVEMENTS_H_

#include "Globals.h"

// Basic movements
void SetMotorSpeed(const MotorSpeed& speed); // Motor speed setting, range -128 ~ 127
void IncrementServoAngle(const byte& status); // Increment the servo angle based on the button status
void SetServoAngle(const ServoAngle& angle); // Set the servo angle
void MoveStepper(bool direction); // Move the stepper motor in the specified direction

#endif // _MOVEMENTS_H_