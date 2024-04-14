#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int pitch=0;
int roll=0;

unsigned long past_time=0;

void setup()
{
  Serial.begin(9600);
  
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    delay(500);
  }
}
 

void loop()
{  
    if(millis()-past_time>=100)
  {
    
  Vector normAccel = mpu.readNormalizeAccel();
  pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
  roll = ((atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI);

  pitch=map(pitch,-180,180,0,1023);
  roll=map(roll,-180,180,0,1023);
  
  trama(pitch,roll);
  
  past_time=millis();
  }

}

void trama(int value1, int value2){
  
  if(value1 > 252 && value1 < 292 && value2 > 980 && value2 < 1020)
  {
    Serial.println("Estatico");
  }
  if(value1 > 452 && value1 < 492 && value2 > 1010 && value2 < 1040)
  {
    Serial.println("Frente");
  }
  if(value1 > 400 && value1 < 450 && value2 > 750 && value2 < 800)
  {
    Serial.println("Derecha");
  }

  if(value1 > 400 && value1 < 450 && value2 > 200 && value2 < 260)
  {
    Serial.println("Izquierda");
  }
 
}
