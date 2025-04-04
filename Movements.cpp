#include "Movements.h"

void SetMotorSpeed(const MotorSpeed& speed) {
	// Set the speed of each motor
	if (speed.LF & 0x80) { // speed is negative
		digitalWrite(LF_IN1_PIN, HIGH);
		digitalWrite(LF_IN2_PIN, LOW);
	} else {
		digitalWrite(LF_IN1_PIN, LOW);
		digitalWrite(LF_IN2_PIN, HIGH);
	}
	analogWrite(LF_PWM_PIN, (speed.LF & 0x7F) << 1); // Mask the speed to 8 bits

	if (speed.RF & 0x80) { // speed is negative
		digitalWrite(RF_IN1_PIN, HIGH);
		digitalWrite(RF_IN2_PIN, LOW);
	} else {
		digitalWrite(RF_IN1_PIN, LOW);
		digitalWrite(RF_IN2_PIN, HIGH);
	}
	analogWrite(RF_PWM_PIN, (speed.RF & 0x7F) << 1); // Mask the speed to 8 bits

	if (speed.LB & 0x80) { // speed is negative
		digitalWrite(LB_IN1_PIN, HIGH);
		digitalWrite(LB_IN2_PIN, LOW);
	} else {
		digitalWrite(LB_IN1_PIN, LOW);
		digitalWrite(LB_IN2_PIN, HIGH);
	}
	analogWrite(LB_PWM_PIN, (speed.LB & 0x7F) << 1); // Mask the speed to 8 bits

	if (speed.RB & 0x80) { // speed is negative
		digitalWrite(RB_IN1_PIN, HIGH);
		digitalWrite(RB_IN2_PIN, LOW);
	} else {
		digitalWrite(RB_IN1_PIN, LOW);
		digitalWrite(RB_IN2_PIN, HIGH);
	}
	analogWrite(RB_PWM_PIN, (speed.RB & 0x7F) << 1); // Mask the speed to 8 bits
}

void IncrementServoAngle(const byte& status) {
	
}

void SetServoAngle(const ServoAngle& angle) {
	
}

void MoveStepper(bool direction) {
	// Set the direction of the stepper motor
	digitalWrite(STEPPER_DIRECTION_PIN, direction == UP ? HIGH : LOW);
	
	// Enable the stepper motor
	digitalWrite(STEPPER_ENABLE_PIN, HIGH);
	
	// Step the motor
	for (int i = 0; i < STEPPER_STEPS_PER_REVOLUTION; i++) {
		digitalWrite(STEPPER_STEP_PIN, HIGH);
		delayMicroseconds(STEPPER_STEP_DELAY); // Adjust the delay for speed
		digitalWrite(STEPPER_STEP_PIN, LOW);
		delayMicroseconds(STEPPER_STEP_DELAY); // Adjust the delay for speed
	}
	
	// Disable the stepper motor
	digitalWrite(STEPPER_ENABLE_PIN, LOW);
}