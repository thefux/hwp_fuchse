# define PIN_10 10
# define SERIAL_COMPOSEED 9600

void setup() {
  Serial.begin(SERIAL_COMPOSEED);
  // put your setup code here, to run once:
  pinMode(PIN_10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PIN_10, HIGH);
  delay(250);
  digitalWrite(PIN_10, LOW);
  delay(500);

  
}
