#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 baro;

const int analogPin = A0;
int value;      //variable que almacena la lectura analógica raw
int position;   //posicion del potenciometro en tanto por ciento

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
value = analogRead(analogPin);       // realizar la lectura analógica raw
  position = map(value, 0, 1023, 0, 154);  // convertir a porcentaje

  //...hacer lo que se quiera, con el valor de posición medido

  float pressure = baro.getPressure();
  float altitude = baro.getAltitude();
  float temperature = baro.getTemperature();
// position=temperature;   //quitar el comentario para que funcione con la temperatura medida
  if (position>=0 && position<12.89){
Serial.print("Etapa Emergencia: "); Serial.print(position);
  }else if (position>12.89 && position<64.41){
Serial.print("Etapa Formacion de guias: "); Serial.print(position);
  }else if (position>64.41 && position<91.33){
Serial.print("Etapa Floracion: "); Serial.print(position);
  }else if (position>91.33 && position<99.31){
Serial.print("Formacion de vaina: "); Serial.print(position);
  }else if (position>99.31 && position<112.77){
Serial.print("Etapa Llenado de vainas: "); Serial.print(position);
  }else if (position>112.77 && position<=154){
Serial.print("Etapa Maduracion: "); Serial.print(position);
  }

  Serial.println("\n-----------------");
  Serial.print("pressure = "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("altitude = "); Serial.print(altitude); Serial.println(" m");
  Serial.print("temperature = "); Serial.print(temperature); Serial.println(" C");
  
  delay(250);
}