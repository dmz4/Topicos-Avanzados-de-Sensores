#include <Wire.h>
#include <Adafruit_MPL3115A2.h>
#include <AHT20.h>

#define pinLM35 0

AHT20 aht20; // Instanciamos el objeto del tipo ATH20
Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2(); // Instanciamos el objeto del tipo Adafruit_MLP3115A2


void setup() {
  Serial.begin(9600);
  //Serial.println("Comunicación serial inicializada");
}

void loop() {
  if(! baro.begin()) {
    Serial.println("Couldnt find sensor");
  }
  if(aht20.begin() == false){
    Serial.println("AHT20 not detected. Please check wiring. Freezing.");
  }
  float altm = baro.getAltitude();
  float tempC = baro.getTemperature();
  float tempC_aht20 = aht20.getTemperature();
  float humidity_aht20 = aht20.getHumidity();
  float tempC1LM35 = analogRead(pinLM35);
  float tempCLM35 = (5.0*tempC1LM35*100.0)/1024.0;
  Serial.print(tempCLM35);
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempC_aht20, 2);
  Serial.print(",");
  Serial.println(humidity_aht20, 2);
  delay(100);
}
