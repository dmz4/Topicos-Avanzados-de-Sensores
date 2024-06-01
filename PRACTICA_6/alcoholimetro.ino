
void setup() {
  Serial.begin(9600);
  Serial.println("MiCS-5524 demo!");

}

void loop() {
  int reading = analogRead(A0);
  Serial.print(String(reading));
  if(reading > 100)
  {
    Serial.println(" EBRIO");
  }
  else
  {
    Serial.println(" No ebrio");

  }
  delay(100);
  
}