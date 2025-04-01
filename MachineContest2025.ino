/*
 * Main program for our machine
 */

#include "Globals.h"
#include "Controller.h"

PS2X ps2x; // create PS2 Controller Class

void setup() {
  Serial.begin(9600);
  ps2x.config_gamepad(PS2X_CLK_PIN, PS2X_CMD_PIN, PS2X_CS_PIN, PS2X_DAT_PIN, pressures, rumble);
  Serial.println("Setup Completed!");
}

void loop() {
  ps2x.read_gamepad(); // read the gamepad values
  
  MoveWheels(ps2x);
  delay(20);
}