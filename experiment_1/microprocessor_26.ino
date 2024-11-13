void setup() {
  for (int i = 8; i < 11; i++) {
    pinMode(i, OUTPUT);
    }
}

void loop() {
  digitalWrite(9, HIGH);  // full speed forward
  digitalWrite(8, LOW);
  analogWrite(10, HIGH);
  delay(1000);

  digitalWrite(9, LOW); // full speed backward
  digitalWrite(8, HIGH);
  analogWrite(10, i);
  delay(1000);

  for (int i=0; i<256; i++) {  // increased speed forward
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  analogWrite(10, i);
  delay(20);
  }
  delay(50);

  for (int i=0; i<256; i++) { // increased speed backward
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  analogWrite(10, i);
  delay(20);
  }
  delay(50);
}