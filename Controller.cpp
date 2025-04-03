#include "Controller.h"

void MoveWheels(PS2X& ps2x) {
  // read the joystick values
	byte leftX = ps2x.Analog(PSS_LX) - 0x80; // center the joystick
	byte leftY = ps2x.Analog(PSS_LY) - 0x80; // center the joystick
	byte rightX = ps2x.Analog(PSS_RX) - 0x80; // center the joystick

	// set the speed for each mecanum wheel
	SetMotorSpeedLF(leftY + leftX + rightX);
	SetMotorSpeedRF(leftY - leftX - rightX);
	SetMotorSpeedLB(leftY - leftX + rightX);
	SetMotorSpeedRB(leftY + leftX - rightX);
}