// display test: write some data to the lcd

/* Connections:
 R/S : Pin 3
 R/W : not connected
 E   : Pin 4
 DB4 : Pin 6
 DB5 : Pin 7
 DB6 : Pin 8
 DB7 : Pin 9
*/
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
  lcd.begin(20, 4); 
  lcd.print("system ready");

  pinMode(ledPin_red, OUTPUT);
  pinMode(ledPin_yellow, OUTPUT);
  pinMode(ledPin_green, OUTPUT);
}


void loop()
{
  analogValue = analogRead(A0);

  /*
  // Aufgabe 5
  // cursor wird aud Null initialisiert also nulte Postion.
  // und die eingelesene analog Wert am ende ausgedruckt.
  lcd.setCursor(0, 0);
  lcd.print("Analog 0: ");
  lcd.print(analogValue);  
   */

  // Aufgabe 6
  // springen einer neuer Zeile.
  lcd.setCursor(0, 1);
  lcd.print("BUTTON: ");
  // lcd.print(analogValue);

  // wenn man den Knopf nicht drückt
  // wird immer ein "*" im display gezeichet.
  // auf dem Board sind die Buttons durch S* bezeichnet.
  if (analogValue > 850)
    lcd.print(" * "); 
  else if (analogValue > 700)
    lcd.print("S5");()
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
    */




    
   lcd.setCursor(0, 3);
   digitalWrite(ledPin_red, HIGH);
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


/* Usefull LCD functions:
set the current write position of the lcd to specific line and row:
  lcd.setCursor(row, line);  

write onto lcd, starting at current position:
  lcd.print("abc");

clear the lcd (this writes " " into all positions and is therefore slow):
If only specific areas should be cleared use a mix of setCursor and print(" ") instead
  lcd.clear();
*/
