#define ledPin_red 12
#define ledPin_yellow 11
#define ledPin_green 10 

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin_red, OUTPUT);
  pinMode(ledPin_yellow, OUTPUT);
  pinMode(ledPin_green, OUTPUT);

}

void loop() {
/* Aufgabe 3 */
   digitalWrite(ledPin_red, HIGH);
   delay(4000);
   digitalWrite(ledPin_yellow, HIGH);
   delay(1000);
   digitalWrite(ledPin_red, LOW);
   digitalWrite(ledPin_yellow, LOW);
   digitalWrite(ledPin_green, HIGH);
   delay(3000);
   digitalWrite(ledPin_green, LOW);
   digitalWrite(ledPin_yellow, HIGH);
   delay(1000);   
   digitalWrite(ledPin_yellow, LOW);
}
