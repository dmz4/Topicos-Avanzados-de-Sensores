#include <SoftwareSerial.h>

#define TxInGPS 3
#define RxInGPS 4

SoftwareSerial gps(RxInGPS,TxInGPS);

char dato=' ';

void setup()
{
 Serial.begin(115200);            
 gps.begin(9600); 
}


void loop()
{
  if(gps.available())
  {
      dato=gps.read();
      Serial.print(dato); 
  }
}
