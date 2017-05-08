// LED - test : Blinking with 1Hz frequency
// LED is connected to Pin 10
// global variables
// int ledPin = 10;
bool led_check = true;
int ledPin1 = 10;
int ledPin2 = 11;

// initialization
void setup(){
  // set ledPin as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}


void loop(){

 /* enable the LED
   digitalWrite(ledPin, HIGH);
   wait for 500ms
   delay(500);
   disable the LED
   digitalWrite(ledPin, LOW);
   wait for 500ms
   delay(500);
  */
  
  
  if (led_check) {
    digitalWrite(ledPin1, HIGH);
    delay(1000);
    digitalWrite(ledPin1, LOW);
    led_check = false;
  } else {
    digitalWrite(ledPin2, HIGH);
    delay(1000);
    digitalWrite(ledPin2, LOW);
    led_check = true;
  }
   
}
