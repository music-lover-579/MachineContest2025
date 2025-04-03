#include "Movements.h"

void SetMotorSpeedLF(const byte& speed) {
	if (speed & 0x80) { // speed value is negative
		digitalWrite(LF_IN1_PIN, HIGH);
		digitalWrite(LF_IN2_PIN, LOW);
	} else {
		digitalWrite(LF_IN1_PIN, LOW);
		digitalWrite(LF_IN2_PIN, HIGH);
	}
	analogWrite(LF_PWM_PIN, 2 * (speed & 0x7F));
}

void SetMotorSpeedRF(const byte& speed) {
	if (speed & 0x80) { // speed value is negative
		digitalWrite(RF_IN1_PIN, HIGH);
		digitalWrite(RF_IN2_PIN, LOW);
	} else {
		digitalWrite(RF_IN1_PIN, LOW);
		digitalWrite(RF_IN2_PIN, HIGH);
	}
	analogWrite(RF_PWM_PIN, 2 * (speed & 0x7F));
}

void SetMotorSpeedLB(const byte& speed) {
	if (speed & 0x80) { // speed value is negative
		digitalWrite(LB_IN1_PIN, HIGH);
		digitalWrite(LB_IN2_PIN, LOW);
	} else {
		digitalWrite(LB_IN1_PIN, LOW);
		digitalWrite(LB_IN2_PIN, HIGH);
	}
	analogWrite(LB_PWM_PIN, 2 * (speed & 0x7F));
}

void SetMotorSpeedRB(const byte& speed) {
	if (speed & 0x80) { // speed value is negative
		digitalWrite(RB_IN1_PIN, HIGH);
		digitalWrite(RB_IN2_PIN, LOW);
	} else {
		digitalWrite(RB_IN1_PIN, LOW);
		digitalWrite(RB_IN2_PIN, HIGH);
	}
	analogWrite(RB_PWM_PIN, 2 * (speed & 0x7F));
}