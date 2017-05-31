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

// local variable

uint8_t counter = 0;
uint8_t start = 0;
uint8_t finish = 0;


/*
 * setup function
 */
void setup() {

  
  Serial.begin(9600);         // begin serial connection
  time_measure();     // die ergebnisse der time_measure function werden
                                      // in dem "Serieller Monitor" gedrÃ¼ckt

  pinMode(13, OUTPUT);        // Pin setzen
  pinMode(12, OUTPUT);
  
}


/*
 * loop function
 */
void loop() {
      
}

/*
 * Aufgabe 1: Mittels setPin12 function wird direkt in das 
 * ensprechende Register geschrieben.
 */
void setPin12(boolean high){
  if (high) {
    PORTB |= (1 << 4);
  }
  else {
    PORTB &= ~(1 << 4);
  }
}


/*
 * Aufgabe 2: Die Aufgabe 1 wird in Assembly Code umgeschrieben
 */
void setPin12Asm(boolean high){
  if (high) {
    asm volatile (
    "sbi %0, %1 \n" // 2 clocks
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB4));
  }
  else {
    asm volatile (
    "cbi %0, %1 \n" // 2 clocks
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB4));
  }
 
}

/*
 * Aufgabe 3: Verglecihen welche der Funktionen ist schneller 
 * Die Ergebnisse zeogen, dass die ASM Funktion schneller als die NON_ASM
 */
void time_measure(void) {
  
  
  uint32_t tStart = millis();         // start Zeit

  uint32_t tDif_non_asm = 0;
  for (int i = 0; i != 100000; i++) {
    setPin12(true);
    setPin12(false);
  }
  
  tDif_non_asm = millis() - tStart;     // Zeit Ausgabe fÃ¼r die NON_ASM Funktion
  
  
  uint32_t tDif_asm = 0;
  for (int i = 0; i != 100000; i++) {
    setPin12Asm(true);
    setPin12Asm(false);
  }

  tDif_asm = millis() - tStart;       // Zeit Ausgabe fÃ¼r die ASM Funktion
  
  
  Serial.println("time needed");
  Serial.print("setPin12 function : ");
  Serial.println(tDif_non_asm);

  Serial.print("setPin12Asm function : ");
  Serial.println(tDif_asm);
}

