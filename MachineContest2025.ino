/*
 * Main program for our machine
 */

#include <Arduino.h>
#include "Globals.h"
#include "Controller.h"

PS2X ps2x; // create PS2 Controller Class
Arm arm; // create Arm Class

void setup() {
	InitWheels();
	InitArm(arm);
	InitStepper();
	ps2x.config_gamepad(PS2X_CLK_PIN, PS2X_CMD_PIN, PS2X_CS_PIN, PS2X_DAT_PIN, pressures, rumble);

	delay(1000); // wait for initialization to finish
}

void loop() {
	ps2x.read_gamepad(); // read the gamepad values
	
	MoveWheels(ps2x); // move the mecanum wheels based on the controller input
	MoveArm(ps2x, arm); // move the servos based on the controller input
	MoveStepper(ps2x); // move the stepper motor based on the controller input

	CompleteAction(ps2x, arm); // complete the designated actions based on the controller input
	
	delay(20); // small delay
}