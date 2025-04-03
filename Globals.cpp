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
}