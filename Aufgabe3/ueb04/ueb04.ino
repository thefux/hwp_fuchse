
uint8_t counter = 0;
uint8_t start = 0;
uint8_t finish = 0;
void setup() {
  
  pinMode(12, OUTPUT);
  
}

void loop() {
    
  set_timer_freq(247);
  
}

void setPin12(boolean high){
  if (high) {
    PORTB |= (1 << 4);
  }
  else {
    PORTB &= ~(1 << 4);
  }
}

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



void set_timer_freq(int freq){
    cli();
    TCCR2A = 0;
    TCCR2B = 0;
    TCCR2B |= (1 << CS22);
    TCCR2B |= (1 << CS20);
    TCCR2A |= (1 << WGM21);
    OCR2A = 625000/(freq*2);
    TIMSK2 |= (1 << OCIE2A);
    sei();
     
}

ISR(TIMER2_COMPA_vect) {
  // toggle pin
  PINB ^= (1 << 4);
}



