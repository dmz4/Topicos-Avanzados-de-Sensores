#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
int contador = 0;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(GPSBaud);
  ss.begin(GPSBaud);
}

void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(",");
    Serial.print(gps.location.lng(), 6);
    delay(60000);
  }
  else
  {
    Serial.print("INVALID");
    Serial.print(",");
    Serial.print("INVALID");
  }


  Serial.println();
}
