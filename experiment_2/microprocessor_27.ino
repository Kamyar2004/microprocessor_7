int lm35 = A0;
int led = 10;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(lm35);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100;
  if (temperature > 26) {
    digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
      }
    
    Serial.print("Temp = ");
    Serial.print(temperature);
    Serial.println(" *C");
    delay(1000);
}