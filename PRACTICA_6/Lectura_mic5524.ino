void setup() {
  Serial.begin(9600);
  pinMode(OUTPUT,2);
  Serial.println("Comunicación serial inicializada");
}

void loop() {
  digitalWrite(LOW,2);
  float readed = analogRead(A0);
  Serial.println(readed);
  delay(100);
}
