
uint8_t counter = 0;
uint8_t start = 0;
uint8_t finish = 0;
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
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
  OCR2A = 156;
    
  // enable interrupt
  TIMSK2 |= (1 << OCIE2A);    
  
  // eable all interrupts
  sei();
}

void loop() {
  start = millis();
  while (counter < 1000){
      setPin12(true);
      setPin12(false);
      counter++;
  }
  finish = millis() - start;
  Serial.println(finish);
  counter = 0;
  
  
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
    "start:"
    "sbi %0, %1\n\t" // 2 clocks
    "cbi %0, %1\n\t" // 2 clocks
    "rjmp start\n\t" // 2 clocks
    :: "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB4));
  }
  else {
    asm volatile (
    "start:"
    "sbi %0, %1\n\t" // 2 clocks
    "cbi %0, %1\n\t" // 2 clocks
    "rjmp start\n\t" // 2 clocks
    :: "O" (_SFR_IO_ADDR(PORTB)), "O" (PORTB4));
  }
 
}





