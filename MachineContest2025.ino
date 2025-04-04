/*
 * Main program for our machine
 */

#include "Globals.h"
#include "Controller.h"

PS2X ps2x; // create PS2 Controller Class

void setup() {
	InitPins();
	ps2x.config_gamepad(PS2X_CLK_PIN, PS2X_CMD_PIN, PS2X_CS_PIN, PS2X_DAT_PIN, pressures, rumble);
}

void loop() {
	ps2x.read_gamepad(); // read the gamepad values
	
	MoveWheels(ps2x); // move the mecanum wheels based on the controller input
	MoveServo(ps2x); // move the servos based on the controller input
	MoveStepper(ps2x); // move the stepper motor based on the controller input
	
	delay(20); // small delay
}