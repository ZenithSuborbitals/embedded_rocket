#include <Wire.h>
#include <Adafruit_MPL3115A2.h>
#include <ADC.h>

#include "pins.h"


bool run_altimeter = false;

ADC *adc = new ADC();

Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

double map_to_g_range(int value) {
  return (value - 32768)/65536.0 * 200;
}

void setup() {
  //analogReference(EXTERNAL);
  init_pins();

  adc->setResolution(16);
  adc->setAveraging(16);
  adc->setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED_16BITS);

  Serial.begin(9600);
  Serial.println("Started");


}

void loop() {

  digitalWrite(BUZZER_PIN, HIGH);
  delay(300);
  digitalWrite(BUZZER_PIN, LOW);
  delay(100);

  int x = adc->analogRead(X_ACCEL_PIN);
  int y = adc->analogRead(Y_ACCEL_PIN);
  int z = adc->analogRead(Z_ACCEL_PIN);

  Serial.println(map_to_g_range(x));
  Serial.println(map_to_g_range(y));
  Serial.println(map_to_g_range(z));
  Serial.println("\n\n");

  delay(1000);

  if (run_altimeter) {
    if (! baro.begin()) {
      Serial.println("Couldnt find sensor");
      return;
    }

    float pascals = baro.getPressure();
    Serial.print(pascals); Serial.println(" Pascals");

    float altm = baro.getAltitude();
    Serial.print(altm); Serial.println(" meters");

    float tempC = baro.getTemperature();
    Serial.print(tempC); Serial.println("*C");

    delay(50);
  }

}
