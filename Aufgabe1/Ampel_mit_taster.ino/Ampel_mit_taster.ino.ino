/* authors:
*
*
*  Abderrahmen Rakez
*  Ferdinand Biermann
*  Tilman Rosenlicht
*  Tobias Schaetzle
*
*
*
*/



/*
*
*  display test: write some data to the lcd
*/

/* Connections:
 R/S : Pin 3
 R/W : not connected
 E   : Pin 4
 DB4 : Pin 6
 DB5 : Pin 7
 DB6 : Pin 8
 DB7 : Pin 9
*/
#define ton 13
#define ledPin_red 12
#define ledPin_yellow 11
#define ledPin_green 10 
// include LCD functions:
#include <LiquidCrystal.h> 

// define the LCD screen
LiquidCrystal lcd(3, 4, 6, 7, 8, 9);

// global variable, stores the result from analog pin
int analogValue;

void setup()
{
  Serial.begin(9600);
  // LCD has 4 lines with 20 chars
  /*
   * Aufgabe 4
   * sollten die nächsten zwei Zeilen reichen, um die Aufgabe 
   * zu lösen.
   */
  lcd.begin(20, 4); 
  lcd.print("system ready");

  pinMode(ledPin_red, OUTPUT);
  pinMode(ledPin_yellow, OUTPUT);
  pinMode(ledPin_green, OUTPUT);
}


void loop()
{

  /*
   * Analog Wert wird in diesem Schritt in der Variable
   * analogValue gespeichert.
   */
  analogValue = analogRead(A0);

  /*
   * Aufgabe 5
   * cursor wird aud Null initialisiert also erste Postion.
   * erste Position heisst: Zeile 0 und Spalte "0 bis 20"
   * um den eingelesenen analog Wert am ende auszudrücken.
   */
  lcd.setCursor(0, 0);
  lcd.print("Analog 0: ");
  lcd.print(analogValue);  
  

  /*
   * Aufgabe 6
   * springen in eine neue Zeile über dem LCD, 
   * und schreibe den Wert, den der Button zurückgibt.
   */
  lcd.setCursor(0, 1);
  lcd.print("BUTTON: ");
  /*
   * wenn man keinen der Knöpfe drückt
   * wird immer ein "*" im display ausgegeben.
   * auf dem Board sind die Buttons durch S* bezeichnet.
   */
    if (analogValue > 850)
    lcd.print(" * "); 
  else if (analogValue > 700)
    lcd.print("S5");
  else if (analogValue > 600)
    lcd.print("S4");
  else if (analogValue > 350)
    lcd.print("S3");
  else if (analogValue > 150)
    lcd.print("S2");
  else if (analogValue >= 0)
    lcd.print("S1");
  else
    lcd.print(" * ");

   /*
    * Aufgabe 7 und Aufganbe 9 
    * wir haben hier versucht alle Aufgabe in dem Display zu zeigen.
    * also auf die 3. Zeile(vorletzte) des LCDs werden die Ampelzustände gezeigt.
    * 
    */
   lcd.setCursor(0, 2);
   digitalWrite(ledPin_red, HIGH); 
   
   
    /*
    * Ton Ausgabe red LED mot 100 Hz.
    */
   tone(13, 100, 4000);
   
   
   lcd.print("red");
   delay(4000);
   lcd.clear();
   lcd.setCursor(0, 3);
   digitalWrite(ledPin_yellow, HIGH);
   lcd.print("red   yellow");
   delay(1000);
   digitalWrite(ledPin_red, LOW);
   digitalWrite(ledPin_yellow, LOW);
   lcd.clear();   
   lcd.setCursor(0, 3); 
   digitalWrite(ledPin_green, HIGH);
   
   
   /*
    * Ton Ausgabe für green LED mit 400 Hz.
    */
   tone(13, 400, 3000);
   
   
   lcd.print("green");
   delay(3000);
   digitalWrite(ledPin_green, LOW);
   lcd.clear();
   lcd.setCursor(0, 3);
   digitalWrite(ledPin_yellow, HIGH);
   lcd.print("yellow");   
   delay(1000);
   digitalWrite(ledPin_yellow, LOW);
   lcd.clear(); 
  // wait for 100 ms (reduces display flickering)
  delay(100);
 
} 
  /* Aufgabe 8
   *  hier wird der Ampelzustand "rot" nur dann verlassen und 
   *  das Programm  weiter laufen, wenn
   *  die Taste "S1" gedrückt wird. 
   *  
  if (analogValue > 850) {
    lcd.print(" * "); 
    digitalWrite(ledPin_red, HIGH);
  } else if (analogValue > 700) {
    lcd.print("S5");
     digitalWrite(ledPin_red, HIGH);
  } else if (analogValue > 600) {
    lcd.print("S4");
    digitalWrite(ledPin_red, HIGH);
  } else if (analogValue > 350) {
    lcd.print("S3");
    digitalWrite(ledPin_red, HIGH);
  } else if (analogValue > 150) {
    lcd.print("S2");
    digitalWrite(ledPin_red, HIGH);
  } else if (analogValue >= 0) {
    lcd.print("S1");
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
  } else
    lcd.print(" * ");
  */


/* Usefull LCD functions:
set the current write position of the lcd to specific line and row:
  lcd.setCursor(row, line);  

write onto lcd, starting at current position:
  lcd.print("abc");

clear the lcd (this writes " " into all positions and is therefore slow):
If only specific areas should be cleared use a mix of setCursor and print(" ") instead
  lcd.clear();
*/
