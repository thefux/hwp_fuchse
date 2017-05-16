#define A_backword 10 // mit A1 verbunden 
#define A_forward 11 // mit A2 verbunden
#define B_forward 6 // mit B1 verbunden
#define B_backward 9 // mit B2 verbunde

bool forward = true;
bool back;
void setMotorSpeed(bool forward);
void driveForward(int32_t t_time, uint8_t spd);
void setMotorSpeed(bool forward, uint8_t spd, bool motor_t);


void setup() {
  // put your setup code here, to run once:
  pinMode(A_backword, OUTPUT);
  pinMode(A_forward, OUTPUT);
  pinMode(B_forward, OUTPUT);
  pinMode(B_backward, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  /* setMotorSpeed(forward);
  delay(2000);
  
  setMotorSpeed(!forward);
  delay(2000);
*/
    while () {
      driveForward(1000, 100);
      break;
    }
    
}
// Aufgabe 1
void setMotorSpeed(bool forward) {
  if (forward == true) {
       digitalWrite(A_backword, HIGH);
       digitalWrite(A_forward, LOW);
  } else {
      digitalWrite(A_forward, HIGH);
      digitalWrite(A_backword, LOW);
  }
}

  // Aufgabe 2
  void setMotorSpeed(bool forward, uint8_t spd) {
  if (forward == true) {
       analogWrite(A_backword, spd);
       analogWrite(A_forward, 0);
  } else {
      analogWrite(A_forward, spd);
      analogWrite(A_backword, 0);
  }
  }
  // Aufgabe 3
  void setMotorSpeed(bool forward, uint8_t spd, bool motor_t) {
  if (forward == true) {
       analogWrite(A_backword, spd);
       analogWrite(A_forward, 0);
  } else {
      analogWrite(A_forward, spd);
      analogWrite(A_backword, 0);
  }
  }
  void driveForward(int32_t t_time, uint8_t spd) {
    analogWrite(A_forward, spd);
    analogWrite(B_forward, spd);
    delay(t_time);
        
  }

