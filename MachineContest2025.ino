/*
 * Main program for our machine
 */

#include "Globals.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setup Completed!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello, world!");
  delay(1000);
}