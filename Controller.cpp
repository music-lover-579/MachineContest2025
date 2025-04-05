#include "Controller.h"

void MoveWheels(PS2X& ps2x) {
	// read the joystick values
	byte leftX = ps2x.Analog(PSS_LX) ^ 0x80; // center the joystick
	byte leftY = ps2x.Analog(PSS_LY) ^ 0x80; // center the joystick
	byte rightX = ps2x.Analog(PSS_RX) ^ 0x80; // center the joystick

	// TODO: change this value according to test results
	const float k = 0.2f;

	// set the speed for each mecanum wheel
	SetMotorSpeed(MotorSpeed{
		.LF = (byte)((leftY - leftX - k * rightX) / (k + 2.0f)),
		.RF = (byte)((leftY + leftX + k * rightX) / (k + 2.0f)),
		.LB = (byte)((leftY + leftX - k * rightX) / (k + 2.0f)),
		.RB = (byte)((leftY - leftX + k * rightX) / (k + 2.0f))
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