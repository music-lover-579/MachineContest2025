/*
 * This header contains methods that realize abstract movements of the robot.
 */

#ifndef _MOVEMENTS_H_
#define _MOVEMENTS_H_

#include "Globals.h"

// Motor speed setting, range -128 ~ 127
void SetMotorSpeedLF(const byte& speed);
void SetMotorSpeedRF(const byte& speed);
void SetMotorSpeedLB(const byte& speed);
void SetMotorSpeedRB(const byte& speed);

#endif // _MOVEMENTS_H_