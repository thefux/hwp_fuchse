#define PIN_10 10
#define PIN_11 11

bool forward = true;

void setMotorSpeed(bool forward);

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_10, OUTPUT);
  pinMode(PIN_11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  setMotorSpeed(forward);
  delay(2000);
  
  setMotorSpeed(!forward);
  delay(2000);

}

void setMotorSpeed(bool forward) {
  if (forward == true) {
       digitalWrite(PIN_10, HIGH);
       digitalWrite(PIN_11, LOW);
  } else {
      digitalWrite(PIN_11, HIGH);
      digitalWrite(PIN_10, LOW);
  }
  
}

