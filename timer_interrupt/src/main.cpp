#include <Arduino.h>

const int led1 = PB3;
const int led2 = PB4;
const int led3 = PB5;
// counter and compare value

const uint16_t count_n1 = 0;
const uint16_t comp_n1 = 18750;




void setup() {
  // put your setup code here, to run once:
  DDRB = 0;
  DDRB |= B00111000; // set output PB3, PB4 and PB5
  DDRD = 0;
  DDRD |= B00000100; // set output PD2 
  // Timer 0
  /*
  Generate a 10KHz frequency using Timer 0
  Prescaler 64
  (16*10^6) / 256 = 62500 / 10000 =25
  */
  // Reset Timer0 control Reg A
  
  TCCR0A = 0;

  // Set prescaler 

  TCCR0B = 0;
  TCCR0B |= B00000011; // set prescaler of 64

  // Counting and compare

  TCNT0 = 0;
  OCR0A = 124;

  // Enable Timer0 compare interrupt

  TIMSK0 = B00000010;

  // Timer 1

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
  TCNT1 = count_n1;
  
  // Enable Timer1 compare interrupt using A and B vector
  // TIMSK1 = (1 << OCIE1A);
  TIMSK1 = B00000110;

  
}

void loop() {
  /*
  Generate 500ms using timer interrupt

  (16*10^6MHz)/256 =  62500 * 0.5 = 31250

  */
  // put your main code here, to run repeatedly:
  OCR1A = 31250;
  OCR1B = 31250; 
}

ISR(TIMER0_COMPA_vect){ // Timer 0 interrupt 10KHz compare A vector 
  TCNT0 = count_n1;
  PORTB ^= (1 << led2); // Toggle led PB4 every 5KHz
}

ISR(TIMER1_COMPA_vect){ // Timer 1 interrupt compare A vector 
  //Reset Timer1 and set compare value 
  TCNT1 = count_n1;
  PORTB ^= (1 << led1); // Toggle led pin PB3 every 1 second

}

ISR(TIMER1_COMPB_vect){ // Timer 1 interrupt compare B vector 
  TCNT1 = count_n1;
  PORTD ^= (1 << PD2); // Toggle led pin PD2 every 1 second
}