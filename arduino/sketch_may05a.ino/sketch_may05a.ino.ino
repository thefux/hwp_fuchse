# define PIN_10 10

void setup() {
    // put your setup code here, to run once:
  pinMode(PIN_10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PIN_10, HIGH);
  delay(1000);
  digitalWrite(PIN_10, LOW);
  delay(2000);

  
}
