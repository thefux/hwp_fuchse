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

// globale Variable

volatile uint32_t tCount = 0;           // Aufgabe 6       

// Aufgabe 7
volatile uint32_t index = 0;            
volatile uint32_t sCount = 0;        
uint32_t duration[10] = {500, 700, 900, 1200, 1400, 1750, 2017, 2150, 2300, 2500};

// Aufgabe 8
uint32_t frequency[10] = {100, 201, 417, 700, 831, 1001, 1324, 1594, 1851, 2000};


void setup() {


  // use pin 11, 12 as output
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  
  // setup the serial port
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("the value of tCount : ");
  Serial.println(tCount);
  delay(1000);
}

/*
 * Aufgabe 5:     OCR2A: entpricht "timer2 output compare register A"  
 *                und mit seinem Wert die freqienz kontrollieren können
 *                hier benutzen wir folgende Formel
 *             
 *                clock_frequenz des boards / ( OCR2A_WERT * 256) = freq
 *                dh.
 *                
 *                OCR2A = clock_frequenz des boards / ( freq * 256)
 */
void set_timer_freq(int freq){
    cli();
    TCCR2A = 0;
    TCCR2B = 0;
    TCCR2B |= (1 << CS22);
    TCCR2B |= (1 << CS20);
    TCCR2A |= (1 << WGM21);

    uint32_t var = 80000000;        // frequency
    uint32_t tmp;
    
    tmp = var / (freq * 255);

    
    if (tmp > 255) {              // Werte größer als 255, werden kein Sinn machen.
      return 0;
    } else {
      OCR2A = tmp;
    }
    
     
    TIMSK2 |= (1 << OCIE2A);
    sei();
     
}


/*
 * Aufgabe 4:  hier benutzen wir folgende Formel
 *             
 *             clock_frequenz des boards / ( 
 */
void set_timer_freq(void){
    cli();
    TCCR2A = 0;
    TCCR2B = 0;
    
    TCCR2B |= (1 << CS22);
    TCCR2B |= (1 << CS20);

    
    TCCR2A |= (1 << WGM21);
   
    OCR2A = 255;       
    TIMSK2 |= (1 << OCIE2A);
    sei();
     
}


/*
 * Aufgabe 6: ISR:  Wenn tCount >= sCount wird index inkrementiert und sCount = tCount + durationr[index]
 *            Beachten Sie dabei, dass index maximal den Wert 9 haben darf bevor er wieder auf 0 gesetzt
 *            werden muss. Toggeln Sie außerdem Pin 11 jedes mal wenn sich der index ändert
 */
ISR(TIMER1_COMPA_vect) {

  tCount++;

  if (tCount >= sCount) {
    index++;

    if (index == 9) {
      index = 0;
    }

    sCount = tCount + duration[index];
  }
  PINB ^= (1 << 3);

  // Funktion Aufgabe 5
  set_timer_freq(frequency[index]);
}

/*
 * Aufgabe 4: ISR
 */
ISR(TIMER2_COMPA_vect) {
  // toggle pin
  PINB ^= (1 << 4);
}

