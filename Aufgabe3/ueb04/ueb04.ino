void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  
  time_measure();
  timer2();
}

void loop() {
    
}
void timer2() {
  
  // disable interrupts
  cli();
  
  // reset control registers
  TCCR2A = 0;     
  TCCR2B = 0;    
  
  // set clock prescaler: 256
  TCCR2B |= (1 << CS22);
  TCCR2B |= (1 << CS20);
  
  // set mode (CTC)
  TCCR2A |= (1 << WGM21);
        
  // set the output compare register (maximum value for now)
  OCR2A = 255;
  
  // enable interrupt
  TIMSK2 |= (1 << OCIE2A);
    
  sei();  
}

// Aufabe 4
void timer2(void) {
  
  // disable all interrupts
  cli();
  
  // reset control registers
  TCCR2A = 0;     
  TCCR2B = 0;    
  
  // set clock prescaler: 64
  TCCR2B |= (1 << CS22);
  // set mode (CTC)
  TCCR2A |= (1 << WGM21);
    
  // set output compare register A
  OCR2A = 255;
    
  // enable interrupt
  TIMSK2 |= (1 << OCIE2A);    
  
  // eable all interrupts
  sei();
  
}
// Aufgabe 1
void setPin12(boolean high){
  if (high) {
    PORTB |= (1 << 4);
  }
  else {
    PORTB &= ~(1 << 4);
  }
}


// Aufgabe 2
void setPin12Asm(boolean high){
  if (high) {
    asm volatile (
    "sbi %0, %1\n\t" // 2 clocks
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB4));
  }
  else {
    asm volatile (
    "cbi %0, %1\n\t" // 2 clocks
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB4));
  }
 
}

// Aufgabe 3
void time_measure(void) {
  
  
  uint8_t tStart = millis();
  uint8_t tPinFunction = 0;
  
  for (int i = 0; i != 10000; i++) {
    setPin12(true);
    setPin12(false);
    // ownToggleAsm_off();
  }
  tPinFunction = millis() - tStart;
  
  uint8_t tAsmFunction = 0;
  
  for (int i = 0; i != 10000; i++) {
    setPin12Asm(true);
    setPin12Asm(false);
  }
  
  Serial.println("setPin12 function");
  Serial.print("measured time ");
  Serial.println(tPinFunction);
  
  Serial.println("setPin12Asm function");
  Serial.print("measured time ");
  Serial.println(tAsmFunction);
  
  
}




