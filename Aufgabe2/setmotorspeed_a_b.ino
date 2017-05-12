#define A_Backwards 10
#define A_Forward 11
#define B_Forward  6
#define B_Backwards  9



bool forward = true;
uint8_t spd = 50;
bool motor = false;

void setMotorSpeed(bool forward);

void setup() {
  // put your setup code here, to run once:
  pinMode(A_Forward, OUTPUT);
  pinMode(A_Backwards, OUTPUT);
  pinMode(B_Forward, OUTPUT);
  pinMode(B_Backwards, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  setMotorSpeed(forward, spd, motor);
  delay(2000);


}

void setMotorSpeed(bool forward, uint8_t spd, bool motor){
  if (motor){
     if (forward == true) {
       analogWrite(A_Forward, spd);
       analogWrite(A_Backwards, 0);
     } else {
      analogWrite(A_Backwards, spd);
      analogWrite(A_Forward, 0);
     }
  }else{
    if (forward == true) {
       analogWrite(B_Forward, spd);
       analogWrite(B_Backwards, 0);
     } else {
      analogWrite(B_Backwards, spd);
      analogWrite(B_Forward, 0);
     }
  
  }
}

void driveForward(){
  
}


