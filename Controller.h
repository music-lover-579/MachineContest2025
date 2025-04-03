/*
 * This header contains functions that convert the PS2X controller input into actions 
 */

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "PS2X_lib.h"
#include "Globals.h"
#include "Movements.h"

void MoveWheels(PS2X& ps2x); // Move the four mecanum wheels based on the controller input

#endif // _CONTROLLER_H_