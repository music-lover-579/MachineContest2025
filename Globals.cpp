#include "Globals.h"

void InitPins() {
	// Motor pins
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

	// Servo pins
	pinMode(BOTTOM_SERVO_PIN, OUTPUT);
	pinMode(MIDDLE_SERVO_PIN, OUTPUT);
	pinMode(PAW_SERVO_PIN, OUTPUT);

	// Stepper motor pins
	pinMode(STEPPER_DIRECTION_PIN, OUTPUT);
	pinMode(STEPPER_STEP_PIN, OUTPUT);
	pinMode(STEPPER_ENABLE_PIN, OUTPUT);
}