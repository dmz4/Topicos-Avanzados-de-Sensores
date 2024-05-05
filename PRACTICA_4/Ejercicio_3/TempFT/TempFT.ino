#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 baro;
// Declaracion de variables globales
int pinLM35 = A0; // Variable del pin de entrada del sensor (A0)

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Adafruit_MPL3115A2 test!");

  if (!baro.begin()) {
    Serial.println("Could not find sensor. Check wiring.");
    while(1);
  }

  // use to set sea level pressure for current location
  // this is needed for accurate altitude measurement
  // STD SLP = 1013.26 hPa
  baro.setSeaPressure(1013.26);
}

void loop() {
  float temperature = baro.getTemperature();
  int value = analogRead(pinLM35);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  Serial.print(temperature);
  Serial.print(",");
  Serial.println(celsius); 

  //delay(1000);
}
