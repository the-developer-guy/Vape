
uint8_t display = 0;

void setup() {
  Serial.begin(115200);
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    Serial.read();
    display++;
    Serial.println(display);
    uint8_t currentDisplay = display;
    for (uint8_t pin = 4; pin <= 8; pin++) {
      if (currentDisplay & 0x01) {
        digitalWrite(pin, HIGH);
      } else {
        digitalWrite(pin, LOW);
      }
      currentDisplay >>= 1;
    }
    delay(1000);
  }
}
