// yutong zhang
// yutongz@cca.edu

int LED = 11;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  // calculate the resistence of the LDR
  float readVoltage = analogRead(A0);
  float v2 = (readVoltage / 1024) * 5;
  Serial.println(v2);

  // turn off the LED when the shadow falls on the LDR
  if(v2 <= 1.5) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
  
  delay(100);
}
