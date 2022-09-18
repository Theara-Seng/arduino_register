#include <Arduino.h>
const int led = PB5;
const int led2 = PB4;
// counter and compare value

const uint16_t t1_load = 0;
const uint16_t t1_comp = 18750;
const uint16_t t2_load = 0;
const uint16_t t2_comp = 31250;



void setup() {
  // put your setup code here, to run once:
  DDRB = 0;
  DDRB |= B00110000;

  // Reset Timer1 control Reg A
  TCCR1A = 0;

  // Set prescaler 256
  /*
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);
  */
  TCCR1B = 0;
  TCCR1B |= B00000100;


  // Enable Timer1 compare interrupt
  // TIMSK1 = (1 << OCIE1A);
  TIMSK1 = B00000100;
}

void loop() {
  // put your main code here, to run repeatedly:
}
ISR(TIMER1_COMPA_vect){
    //Reset Timer1 and set compare value 
  TCNT1 = t1_load;
  OCR1A = t1_comp;
  PORTB ^= (1<<led);
}
ISR(TIMER1_COMPB_vect){
  TCNT1 = t2_load;
  OCR1A = t2_comp;
  PORTB ^= (1<<led2);
}