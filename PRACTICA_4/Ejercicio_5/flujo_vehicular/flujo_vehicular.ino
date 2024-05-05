#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 baro;
int contador = 0;
int flag = 0;
int old = 0;

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
  float pressure = baro.getPressure();

  Serial.println("-----------------");
  Serial.print("Presion = "); Serial.print(pressure*100); Serial.print(" Pa");
  if(pressure*100 > 76790)
  {
    flag = 1;
  }
  else
  {
    flag = 0;
  }
  
  if(flag == 1 && old == 0)
  {
    contador = contador + 1;
    Serial.print("Persona: ");
    Serial.print(contador);
  }
  old = flag;
  
}
