#define A_Backwards 10
#define A_Forward 11
#define B_Forward  6
#define B_Backwards  9



bool forward = true;
uint8_t spd = 50;
bool motor = false;
int speed = 150;
int time = 2000;
int curve = -30;

void setMotorSpeed(bool forward);
void drivForward(int speed, int time);

void setup() {
  // put your setup code here, to run once:
  pinMode(A_Forward, OUTPUT);
  pinMode(A_Backwards, OUTPUT);
  pinMode(B_Forward, OUTPUT);
  pinMode(B_Backwards, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  driveCurve(speed, time, curve);
  //setMotorSpeed(forward, spd, motor);
  


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

void driveForward(int speed, int time){
  analogWrite(A_Forward, speed);
  analogWrite(B_Forward, speed);
  delay(time);
  analogWrite(A_Forward, LOW);
  analogWrite(B_Forward, LOW);
}

void driveCurve(int speed, int time, int curve){
  if (curve == 0){
    analogWrite(A_Forward, speed);
    analogWrite(B_Forward, speed);
  }
  if (curve < -45){
    analogWrite(B_Forward,speed);
    analogWrite(A_Backwards,speed * curve/90);
  }
  if (curve < 0 && curve >= -45){
    analogWrite(B_Forward,speed);
    analogWrite(A_Forward,speed * (45+curve)/45);
  }
  if (curve <= 45 && curve > 0){
    analogWrite(A_Forward,speed);
    analogWrite(B_Forward,speed * (45-curve)/45);
  }
  if (curve > 45){
    analogWrite(A_Forward,speed);
    analogWrite(B_Backwards,speed * curve/90);
  }
  delay(time);
  analogWrite(A_Forward, LOW);
  analogWrite(B_Forward, LOW);
    
}


