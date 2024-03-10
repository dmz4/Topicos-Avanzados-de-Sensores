#include "Adafruit_VL53L0X.h"
#include<Stepper.h>

int pasosPorVuelta=2048;
int cont=0;
Stepper motor(pasosPorVuelta,8,10,9,11);

int an=0;
int an_1=0;
float alpha=0.25;
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(9600);
  motor.setSpeed(10);
  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  //Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    //Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}


void loop() {
  
  VL53L0X_RangingMeasurementData_t measure;
    
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  
    if (measure.RangeStatus != 4) { 
    
    an=(alpha)*(measure.RangeMilliMeter)+(1-alpha)*an_1;
    an_1=an;
    Serial.print(String(cont));
    Serial.print(",");
    Serial.println(String(an));
    motor.step(-pasosPorVuelta/360);
    cont=cont+1;
    if(cont == 360){
      cont=0;
      }
    } 
  D
  
    
 
}