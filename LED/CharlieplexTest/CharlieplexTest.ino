
#define HIZ_PIN (2)
uint8_t display[5] = {0, 0, 0, 0, 0};
char buff[10];

void setup() {
  Serial.begin(115200);
}

void loop() {
  // manual stepping
  if (Serial.available()) {
    Serial.read();


    display[0]++;
    for(int i = 0; i < 4; i++){
      if(display[i] > HIZ_PIN){
        display[i+1]++;
        display[i] = 0;
      }
    }
    if(display[4] > HIZ_PIN){
      display[4] = 0;
    }
    sprintf(buff, "%c%c%c%c%c\n", translateState(display[4]),
                                  translateState(display[3]),
                                  translateState(display[2]),
                                  translateState(display[1]),
                                  translateState(display[0]));
    Serial.print(buff);

    for (int i = 4; i <= 8; i++) {
      pinMode(i, INPUT);
      digitalWrite(i, LOW);
    }

    uint8_t pin = 4;
    for (int i = 0; i < 6; i++, pin++) {
      if(display[i] == HIZ_PIN){
        continue;
      }
      pinMode(pin, OUTPUT);
      digitalWrite(pin, display[i]);
    }
  }
}

char translateState(int state){
  if(state == LOW){
    return 'L';
  }
  else if(state == HIGH){
    return 'H';
  }
  else if(state == HIZ_PIN){
    return 'Z';
  }
  else{
    return 'E';
  }
}
