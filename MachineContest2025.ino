/*
 * Main program for our machine
 * 
 * This project uses the PS2X_lib library (GPLv3) by Bill Porter
 * See: https://github.com/madsci1016/Arduino-PS2X
 */

#include <Arduino.h>
#include "Globals.h"
#include "Controller.h"

PS2X ps2x; // Create PS2 Controller Class
Arm arm; // Create Arm Class

void setup() {
	// Initializations
	InitWheels();
	InitArm(arm);
	InitStepper();
	ps2x.config_gamepad(PS2X_CLK_PIN, PS2X_CMD_PIN, PS2X_CS_PIN, PS2X_DAT_PIN, pressures, rumble);

	delay(1000); // Wait for initialization to finish
}

void loop() {
	ps2x.read_gamepad(); // Read the gamepad values
	
	MoveWheels(ps2x); // Move the mecanum wheels based on the controller input
	MoveArm(ps2x, arm); // Move the servos based on the controller input
	MoveStepper(ps2x); // Move the stepper motor based on the controller input

	CompleteAction(ps2x, arm); // Complete the designated actions based on the controller input
	
	delay(20); // Small delay
}