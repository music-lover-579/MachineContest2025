#include "Controller.h"

void MoveWheels(PS2X& ps2x) {
	// Read joystick values and center them to -128 to 127 range
	int leftX = ps2x.Analog(PSS_LX) - 127;
	int leftY = -ps2x.Analog(PSS_LY) + 128; // Invert Y
	int rightX = ps2x.Analog(PSS_RX) - 127;

	if (leftX == 128) leftX = 127;
	if (leftY == 128) leftY = 127;
	if (rightX == 128) rightX = 127;

	if (abs(rightX) > DEADZONE) { // rotation
		SetMotorSpeed(MotorSpeed{
			.LF = rightX,
			.RF = -rightX,
			.LB = rightX,
			.RB = -rightX
		});
	} else if (abs(leftX) > DEADZONE || abs(leftY) > DEADZONE) { // translation
		SetMotorSpeed(MotorSpeed{
			.LF = leftY / 2 + leftX / 2,
			.RF = leftY / 2 - leftX / 2,
			.LB = leftY / 2 - leftX / 2,
			.RB = leftY / 2 + leftX / 2
		});
	} else { // stop
		SetMotorSpeed(MotorSpeed{
			.LF = 0,
			.RF = 0,
			.LB = 0,
			.RB = 0
		});
	}
}

void MoveArm(PS2X& ps2x, Arm& arm) {
	// read the button values
	Byte status = 0;
	if (ps2x.Button(BOTTOM_SERVO_DOWN)) status |= BOTTOM_SERVO_CHANGE;
	else if (ps2x.Button(BOTTOM_SERVO_UP)) status |= BOTTOM_SERVO_CHANGE | BOTTOM_SERVO_DIRECTION_IS_UP;
	if (ps2x.Button(MIDDLE_SERVO_DOWN)) status |= MIDDLE_SERVO_CHANGE;
	else if (ps2x.Button(MIDDLE_SERVO_UP)) status |= MIDDLE_SERVO_CHANGE | MIDDLE_SERVO_DIRECTION_IS_UP;
	if (ps2x.ButtonPressed(PAW_SERVO_CLOSE)) status |= PAW_SERVO_CHANGE;
	else if (ps2x.Button(PAW_SERVO_OPEN)) status |= PAW_SERVO_CHANGE | PAW_SERVO_DIRECTION_IS_OPEN;

	// increment the servo angle based on the button status
	IncrementServoAngle(arm, status);
}

void MoveStepper(PS2X& ps2x) {
	// read the button values
	if (ps2x.Button(STEPPER_UP)) MoveStepper(UP);
	else if (ps2x.Button(STEPPER_DOWN)) MoveStepper(DOWN);
}

void CompleteAction(PS2X& ps2x, Arm& arm) {
	// TODO: Implement the complete action logic
}