#include "Movements.h"

void SetMotorSpeed(const MotorSpeed& speed) {
	// Set the speed of each motor
	if (speed.LF & 0x80) { // Speed is negative
		digitalWrite(LF_IN1_PIN, LOW);
		digitalWrite(LF_IN2_PIN, HIGH);
	} else {
		digitalWrite(LF_IN1_PIN, HIGH);
		digitalWrite(LF_IN2_PIN, LOW);
	}
	analogWrite(LF_PWM_PIN, abs(speed.LF) * 2); // Multiply by 2 to convert to 8-bit PWM

	if (speed.RF & 0x80) { // Speed is negative
		digitalWrite(RF_IN1_PIN, LOW);
		digitalWrite(RF_IN2_PIN, HIGH);
	} else {
		digitalWrite(RF_IN1_PIN, HIGH);
		digitalWrite(RF_IN2_PIN, LOW);
	}
	analogWrite(RF_PWM_PIN, abs(speed.RF) * 2); // Multiply by 2 to convert to 8-bit PWM

	if (speed.LB & 0x80) { // Speed is negative
		digitalWrite(LB_IN1_PIN, LOW);
		digitalWrite(LB_IN2_PIN, HIGH);
	} else {
		digitalWrite(LB_IN1_PIN, HIGH);
		digitalWrite(LB_IN2_PIN, LOW);
	}
	analogWrite(LB_PWM_PIN, abs(speed.LB) * 2); // Multiply by 2 to convert to 8-bit PWM

	if (speed.RB & 0x80) { // Speed is negative
		digitalWrite(RB_IN1_PIN, LOW);
		digitalWrite(RB_IN2_PIN, HIGH);
	} else {
		digitalWrite(RB_IN1_PIN, HIGH);
		digitalWrite(RB_IN2_PIN, LOW);
	}
	analogWrite(RB_PWM_PIN, abs(speed.RB) * 2); // Multiply by 2 to convert to 8-bit PWM
}

void IncrementServoAngle(Arm& arm, const UByte& status) {
	int angle;

	if (status & BOTTOM_SERVO_CHANGE) { // Bottom servo moving
		angle = arm.bottom.read() + ((status & BOTTOM_SERVO_DIRECTION_IS_UP) ? -1 : 1);
		arm.bottom.write(TRUNCATE(angle, BOTTOM_SERVO_MIN, BOTTOM_SERVO_MAX));
	}
	if (status & MIDDLE_SERVO_CHANGE) { // Middle servo moving
		angle = arm.middle.read() + ((status & MIDDLE_SERVO_DIRECTION_IS_UP) ? 1 : -1);
		arm.middle.write(TRUNCATE(angle, MIDDLE_SERVO_MIN, MIDDLE_SERVO_MAX));
	}
	if (status & PAW_SERVO_CHANGE) { // Paw servo moving
		angle = arm.paw.read() + ((status & PAW_SERVO_DIRECTION_IS_OPEN) ? 5 : -1); // Open is faster to increase efficiency, while close is slower to ensure a tight grip
		arm.paw.write(TRUNCATE(angle, PAW_SERVO_MIN, PAW_SERVO_MAX));
	}
}

void SetServoAngle(Arm& arm, const ServoAngle& angle) {
	arm.bottom.write(TRUNCATE(angle.BOTTOM, BOTTOM_SERVO_MIN, BOTTOM_SERVO_MAX));
	arm.middle.write(TRUNCATE(angle.MIDDLE, MIDDLE_SERVO_MIN, MIDDLE_SERVO_MAX));
	arm.paw.write(TRUNCATE(angle.PAW, PAW_SERVO_MIN, PAW_SERVO_MAX));
}

void MoveStepper(bool direction) {
	// Set the direction of the stepper motor
	digitalWrite(STEPPER_DIRECTION_PIN, direction == UP ? HIGH : LOW);
	
	// Step the motor
	for (int i = 0; i < STEPPER_STEPS_PER_REVOLUTION; ++i) {
		digitalWrite(STEPPER_STEP_PIN, HIGH);
		delayMicroseconds(STEPPER_STEP_DELAY); // Adjust the delay for speed
		digitalWrite(STEPPER_STEP_PIN, LOW);
		delayMicroseconds(STEPPER_STEP_DELAY); // Adjust the delay for speed
	}
	
}