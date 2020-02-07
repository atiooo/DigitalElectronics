// yutong zhang
// yutongz@cca.edu

int LED = 11;
int brightness = 255;
int fadeAmount = 5;

int absFadeAmount = 5;

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);

}

void loop() {
  // calculate the resistence of the LDR
  float readVoltage = analogRead(A0);
  float v2 = (readVoltage / 1024) * 5;
  Serial.println(v2);

  // set the brightness of pin 11
  analogWrite(11, brightness);

  
  // set the fade amount
  if(brightness <= 0) {
    fadeAmount = -absFadeAmount;
  } else if (brightness >= 255) {
    fadeAmount = absFadeAmount;
  }

  // start fading when shadow on
  if(v2 <= 2.3) {
    brightness = brightness - fadeAmount;
  }
  Serial.println(brightness);
  
  delay(50);
}
