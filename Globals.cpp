#include "Globals.h"

void InitWheels() {
	// Set the pins for the wheels
	pinMode(LF_IN1_PIN, OUTPUT);
	pinMode(LF_IN2_PIN, OUTPUT);
	pinMode(RF_IN1_PIN, OUTPUT);
	pinMode(RF_IN2_PIN, OUTPUT);
	pinMode(LB_IN1_PIN, OUTPUT);
	pinMode(LB_IN2_PIN, OUTPUT);
	pinMode(RB_IN1_PIN, OUTPUT);
	pinMode(RB_IN2_PIN, OUTPUT);
	pinMode(LF_PWM_PIN, OUTPUT);
	pinMode(RF_PWM_PIN, OUTPUT);
	pinMode(LB_PWM_PIN, OUTPUT);
	pinMode(RB_PWM_PIN, OUTPUT);

	// Set the initial state of the wheels
	digitalWrite(LF_IN1_PIN, LOW);
	digitalWrite(LF_IN2_PIN, LOW);
	digitalWrite(RF_IN1_PIN, LOW);
	digitalWrite(RF_IN2_PIN, LOW);
	digitalWrite(LB_IN1_PIN, LOW);
	digitalWrite(LB_IN2_PIN, LOW);
	digitalWrite(RB_IN1_PIN, LOW);
	digitalWrite(RB_IN2_PIN, LOW);
}

void InitArm(Arm& arm) {
	arm.bottom.attach(BOTTOM_SERVO_PIN, BOTTOM_SERVO_MIN, BOTTOM_SERVO_MAX);
	arm.middle.attach(MIDDLE_SERVO_PIN, MIDDLE_SERVO_MIN, MIDDLE_SERVO_MAX);
	arm.paw.attach(PAW_SERVO_PIN);

	// Set initial angles
	arm.bottom.write(BOTTOM_SERVO_INITIAL);
	arm.middle.write(MIDDLE_SERVO_INITIAL);
	arm.paw.write(PAW_SERVO_MIN_INITIAL);
}

void InitStepper() {
	// Set the initial state of the stepper motor
	pinMode(STEPPER_DIRECTION_PIN, OUTPUT);
	pinMode(STEPPER_STEP_PIN, OUTPUT);
	pinMode(STEPPER_ENABLE_PIN, OUTPUT);

	digitalWrite(STEPPER_ENABLE_PIN, LOW); // Enable the stepper motor
}