#include "Controller.h"

void MoveWheels(PS2X& ps2x) {
	// read the joystick values
	byte leftX = ps2x.Analog(PSS_LX) ^ 0x80; // center the joystick
	byte leftY = ps2x.Analog(PSS_LY) ^ 0x80; // center the joystick
	byte rightX = ps2x.Analog(PSS_RX) ^ 0x80; // center the joystick

	// set the speed for each mecanum wheel
	// TODO: Implement the speed calculation based on the joystick values
	SetMotorSpeed(MotorSpeed{
		.LF = byte(leftY + leftX + rightX),
		.RF = byte(leftY - leftX - rightX),
		.LB = byte(leftY - leftX + rightX),
		.RB = byte(leftY + leftX - rightX)
	});
}

void MoveArm(PS2X& ps2x, Arm& arm) {
	// read the button values
	byte status = 0;
	if (ps2x.ButtonPressed(BOTTOM_SERVO_DOWN)) status |= BOTTOM_SERVO_CHANGE;
	else if (ps2x.ButtonPressed(BOTTOM_SERVO_UP)) status |= BOTTOM_SERVO_CHANGE | BOTTOM_SERVO_DIRECTION_IS_UP;
	if (ps2x.ButtonPressed(MIDDLE_SERVO_DOWN)) status |= MIDDLE_SERVO_CHANGE;
	else if (ps2x.ButtonPressed(MIDDLE_SERVO_UP)) status |= MIDDLE_SERVO_CHANGE | MIDDLE_SERVO_DIRECTION_IS_UP;
	if (ps2x.ButtonPressed(PAW_SERVO_CLOSE)) status |= PAW_SERVO_CHANGE;
	else if (ps2x.ButtonPressed(PAW_SERVO_OPEN)) status |= PAW_SERVO_CHANGE | PAW_SERVO_DIRECTION_IS_OPEN;

	// increment the servo angle based on the button status
	IncrementServoAngle(arm, status);
}

void MoveStepper(PS2X& ps2x) {
	// read the button values
	if (ps2x.ButtonPressed(STEPPER_UP)) MoveStepper(UP);
	else if (ps2x.ButtonPressed(STEPPER_DOWN)) MoveStepper(DOWN);
}

void CompleteAction(PS2X& ps2x, Arm& arm) {
	// TODO: Implement the complete action logic
}