#define A_Backwards 10
#define A_Forward 11
#define B_Forward  6
#define B_Backwards  9

#include <LiquidCrystal.h> 
/* Connections:
 R/S : Pin 2
 R/W : not connected
 E   : Pin 3
 DB4 : Pin 4
 DB5 : Pin 5
 DB6 : Pin 7
 DB7 : Pin 8
*/
// define the LCD screen
LiquidCrystal lcd(2, 3, 4, 5, 7, 8);

bool forward = true;
uint8_t spd = 80;
bool motor = false;
int speed = 150;
int time = 2000;
int curve = 45;
int x = 0;
int y = 0;
int z = 0;
int analogValue;
float v=331.5+0.6*20;

void setMotorSpeed(bool forward);
void drivForward(int speed, int time);
void driveForward(uint32_t time, uint8_t spd);
void muster1(void);
void muster2(void);
void muster3(void);
void muster4(void);
void setup() {
  // put your setup code here, to run once:
  pinMode(A_Forward, OUTPUT);
  pinMode(A_Backwards, OUTPUT);
  pinMode(B_Forward, OUTPUT);
  pinMode(B_Backwards, OUTPUT);
  lcd.begin(20, 4);
  // lcd.print("tehfux");
}

void loop() {


  
  // uint16_t dis = meassureDistance(12);
  // analogValue = analogRead(A0);
  // setMotorSpeed(false, 100, true);


  /*
   * Aufgabe 3: vorwärts fahren und dann stoppen
   */
  // driveForward(1000, 70);
  // while(1) {}
/*
    if (analogValue > 850)
    lcd.print(" * "); 
  else if (analogValue > 700)
    // Taster 5
    muster4();
  else if (analogValue > 600)
    // Taste 4
    muster3();
  else if (analogValue > 350)
    // Taste 3
    driveUs();
  else if (analogValue > 150)
    // Taste 2
    muster2();
  else if (analogValue >= 0)
    // Taste 1
    muster1();
  else
    lcd.print(" * ");
*/
  lcd.setCursor(0, 0);
  int d = meassureDistance(12);

  setMotorSpeed(true, spd, true);
  setMotorSpeed(true, spd, false);
  if (d < 20) {
    setMotorSpeed(true, spd, true);
    setMotorSpeed(false, spd, false);
  }
  
  lcd.print(d, DEC);
 

}


/*
 * Aufgabe 1 mit der Erweiterung für Aufgabe 2.
 */
void setMotorSpeed(bool forward, uint8_t spd, bool motorA){
  if (motorA){
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

/*
 * Aufgabe 3: Roboter soll geradaus fahren
 */
void driveForward(uint32_t time, int speed) {
 
  setMotorSpeed(true, spd, true);
  setMotorSpeed(true, spd, false);
  delay(time);
  setMotorSpeed(true, 0, true);
  setMotorSpeed(true, 0, false);
 
} 

/*
 * Aufgabe 4: man hätte hier ein funcktion schreiben können, hatten wir aber nicht.
 */
 
void driveCurve(int speed, int time, int curve){
  if (curve == 0){
    analogWrite(A_Forward, speed);
    analogWrite(B_Forward, speed);
  }
  if (curve < -45) {
    analogWrite(B_Forward,speed);
    analogWrite(A_Backwards,speed * curve/-90);
  }
  if (-45 <= curve < 0) {
    analogWrite(B_Forward,speed);
    analogWrite(A_Forward,speed * (45+curve)/45);
  }
  if (0 < curve < 45) {
    analogWrite(A_Forward,speed);
    analogWrite(B_Forward,speed * (45-curve)/45);
  }
  if (curve > 45) {
    analogWrite(A_Forward,speed);
    analogWrite(B_Backwards,speed * curve/90);
  }
  
  delay(time);
  analogWrite(A_Forward, LOW);
  analogWrite(B_Forward, LOW);
    
}
/*
 * Muster1: kreis fahren.
 */
void muster1(void) {
  driveCurve(200, 6000, 40);
}
void muster2(void) {
  driveForward(3000, 150);
  driveCurve(70, 1400, -90);
  driveForward(3000, 150);
  driveCurve(70, 1400, -90);
  driveForward(3000, 150);
  driveCurve(70, 1400, -90);
  driveForward(3000, 150);
  driveCurve(70, 1400, -90);
}

int16_t meassureDistance(uint8_t pin) {
 
  // set pin as output
  pinMode(pin, OUTPUT);
  
  // write pulse
  digitalWrite(pin, LOW);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  
  // set pin as input
  pinMode(pin, INPUT);
  // store time for timeout detection
  uint32_t tStart = micros();
  
  uint32_t tDif = 0;
  
  // loop with timeout
  while( (tDif = micros() - tStart) < 30000 && digitalRead(pin) == LOW) {
  }
}


float meassureDistance(int pin){
 // Sendet Schallimpuls
 pinMode(pin, OUTPUT); 
 digitalWrite(pin, LOW);
 delayMicroseconds(3); 
 digitalWrite(pin, HIGH);
 delayMicroseconds(5); 
 digitalWrite(pin, LOW);
 // Lauscht auf Echo
 pinMode(pin, INPUT);
 float tUs = pulseIn(pin, HIGH); // microseconds 5
 float t = tUs / 1000.0 / 1000.0 / 2; // s 6
 float d = t*v; // m 7
 return d*100; // cm
}


