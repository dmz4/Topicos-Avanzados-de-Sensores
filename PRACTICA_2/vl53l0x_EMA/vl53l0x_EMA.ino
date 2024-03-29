#include "Adafruit_VL53L0X.h"

float a = 0.25;
float M;
float An1 = 0;
float An; 

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    M = measure.RangeMilliMeter;
    An = (a*M)+((1-a)*An1);
    Serial.print("Distancia medida (mm): ");
    Serial.print(M);
    Serial.print("  Distancia EMA (mm): ");
    Serial.println(An);
    An1 = An;
  } else {
    Serial.println(" out of range ");
  }
    
  delay(100);
}
