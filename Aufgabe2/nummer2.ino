#define PIN_10 10
#define PIN_11 11



bool forward = true;
uint8_t spd = 50;

void setMotorSpeed(bool forward);

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_10, OUTPUT);
  pinMode(PIN_11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  setMotorSpeed(forward, spd);
  delay(2000);


}

void setMotorSpeed(bool forward, uint8_t spd) {
  if (forward == true) {
       analogWrite(PIN_10, spd);
       analogWrite(PIN_11, 0);
  } else {
      analogWrite(PIN_11, spd);
      analogWrite(PIN_10, 0);
  }
  
}


