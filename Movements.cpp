#include "Movements.h"

void SetMotorSpeed(const MotorSpeed& speed) {
	// Set the speed of each motor
	if (speed.LF & 0x80) { // speed is negative
		digitalWrite(LF_IN1_PIN, LOW);
		digitalWrite(LF_IN2_PIN, HIGH);
	} else {
		digitalWrite(LF_IN1_PIN, HIGH);
		digitalWrite(LF_IN2_PIN, LOW);
	}
	analogWrite(LF_PWM_PIN, abs(speed.LF) * 2); // Mask the speed to 8 bits

	if (speed.RF & 0x80) { // speed is negative
		digitalWrite(RF_IN1_PIN, LOW);
		digitalWrite(RF_IN2_PIN, HIGH);
	} else {
		digitalWrite(RF_IN1_PIN, HIGH);
		digitalWrite(RF_IN2_PIN, LOW);
	}
	analogWrite(RF_PWM_PIN, abs(speed.RF) * 2); // Mask the speed to 8 bits

	if (speed.LB & 0x80) { // speed is negative
		digitalWrite(LB_IN1_PIN, LOW);
		digitalWrite(LB_IN2_PIN, HIGH);
	} else {
		digitalWrite(LB_IN1_PIN, HIGH);
		digitalWrite(LB_IN2_PIN, LOW);
	}
	analogWrite(LB_PWM_PIN, abs(speed.LB) * 2); // Mask the speed to 8 bits

	if (speed.RB & 0x80) { // speed is negative
		digitalWrite(RB_IN1_PIN, LOW);
		digitalWrite(RB_IN2_PIN, HIGH);
	} else {
		digitalWrite(RB_IN1_PIN, HIGH);
		digitalWrite(RB_IN2_PIN, LOW);
	}
	analogWrite(RB_PWM_PIN, abs(speed.RB) * 2); // Mask the speed to 8 bits
}

void IncrementServoAngle(Arm& arm, const UByte& status) {
	arm.bottom.write(arm.bottom.read() + ((status & BOTTOM_SERVO_CHANGE) ? (status & BOTTOM_SERVO_DIRECTION_IS_UP ? 1 : -1) : 0));
	arm.middle.write(arm.middle.read() + ((status & MIDDLE_SERVO_CHANGE) ? (status & MIDDLE_SERVO_DIRECTION_IS_UP ? 1 : -1) : 0));
	arm.paw.write(arm.paw.read() + ((status & PAW_SERVO_CHANGE) ? (status & PAW_SERVO_DIRECTION_IS_OPEN ? 1 : -1) : 0));
}

void SetServoAngle(Arm& arm, const ServoAngle& angle) {
	arm.bottom.write(angle.BOTTOM);
	arm.middle.write(angle.MIDDLE);
	arm.paw.writeMicroseconds(angle.PAW);
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