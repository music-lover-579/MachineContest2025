#include "Controller.h"

void MoveWheels(PS2X& ps2x) {
  // Move the wheels based on the PS2 controller input
  if (ps2x.ButtonPressed(PSB_PAD_UP)) {
		Serial.println("Moving forward");
	} else if (ps2x.ButtonPressed(PSB_PAD_DOWN)) {
		Serial.println("Moving backward");
	} else if (ps2x.ButtonPressed(PSB_PAD_LEFT)) {
		Serial.println("Turning left");
	} else if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) {
		Serial.println("Turning right");
	} else {
		Serial.println("Stopping");
	}
}