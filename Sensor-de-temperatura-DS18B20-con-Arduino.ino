/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
*/

#include <OneWire.h> //https://github.com/PaulStoffregen/OneWire
#include <DallasTemperature.h> //https://github.com/milesburton/Arduino-Temperature-Control-Library

const uint8_t dsPinT = 2;

OneWire wireT(dsPinT);
DallasTemperature dallasT(&wireT);

void setup() {
  dallasT.begin();
  Serial.begin(9600);
}

void loop() {
  dallasT.requestTemperatures();
  String resultSerialT = "Temperatura actual: " + String(dallasT.getTempCByIndex(0)) + " °C";
  Serial.print(resultSerialT);
  delay(200);
}
