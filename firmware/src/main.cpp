#include <Arduino.h>
#include <Wire.h>
#include <BH1750.h>
#include <math.h>

float isoCorrection(float ev, float iso);
float timeValue(float aperture, float isoEV);
BH1750 lm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(9,8);

  lm.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire);
  Serial.println(F("BH1750 Test"));
}

void loop() {
  // put your main code here, to run repeatedly:
  float lux = lm.readLightLevel();
  float ev = log2(lux/2.5);
  //log_2 (lux/2.5)
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  Serial.print("EV: ");
  Serial.print(ev);
  Serial.println(" ev");
  delay(1000);
}

float isoCorrection(float ev, float iso){
  return (ev + log2((iso/100)));
}