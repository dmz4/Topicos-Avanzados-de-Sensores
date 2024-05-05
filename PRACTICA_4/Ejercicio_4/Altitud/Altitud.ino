#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 baro;


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

  float altitude = baro.getAltitude();


  Serial.println("\n-----------------");
  Serial.print("altitude = "); Serial.print(altitude); Serial.println(" m");
  delay(250);
}