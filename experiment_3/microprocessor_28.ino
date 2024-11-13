int power = 0;

void setup() {
  for (int i = 8; i < 11; i++) {
    pinMode(i, OUTPUT);
    }
}

void loop() {
  power = analogRead(A3);
  int hashVal = map(power, 0, 1023, 0, 255);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  analogWrite(10, hashVal);
  delay(100);
}