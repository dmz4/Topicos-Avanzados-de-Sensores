/*************************************************************************/
 /* Código para sensor de presión barométrica MPL3115A2
  *  
  *            |                |
  *            |                |
  *            |                |
  *            |                |
  *            |  Arduino Uno   |
  *            |                |
  *            |             A4 | <---- SDA 
  *            |             A5 | <---- SCL
  *            |             5V | <---- Vin
  *            |            GND | <---- GND
  *            |                |
  *            |                |
  * Este código implementa la librería de Adafruit MPL3115A2 v1.0.0 y           
  * utilizó el IDE de arduino 1.8.8
  */
/*************************************************************************/

#include <Wire.h>
#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

int h_r = 22;           // Este valor varia constantemente y se tiene que revisar y cambiar cada que se utilice el sensor.
float v = 3.39;         // Este valor es el valor promedio en m/s sacado de la página https://power.larc.nasa.gov
float r = 1.0;              // Radio del área de la base circular en m.             
const float npi = 3.1416;
 void setup() {
  Serial.begin(9600);
}

void loop() {
  if (! baro.begin()) {
    Serial.println("No se encontró al sensor");
    return;
  }
  float pascals = baro.getPressure();
  float hPa = pascals*0.01;
  float altm = baro.getAltitude();
  float tempC = baro.getTemperature();
  float exponente = 0.061*tempC;
  float densi = ((0.34848*hPa)-(0.009*h_r*exp(exponente)))/(273.15 + tempC);
  float k = 0.5*npi*densi*v*v*v*r*r;

  Serial.print(k);
  Serial.println(" J");

}
