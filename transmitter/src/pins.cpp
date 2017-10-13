#include <Arduino.h>
#include "pins.h"

void init_pins(void) {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(X_ACCEL_PIN, INPUT);
  pinMode(Y_ACCEL_PIN, INPUT);
  pinMode(Z_ACCEL_PIN, INPUT);
}
