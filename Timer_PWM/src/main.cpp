#include <Arduino.h>
#include <avr/interrupt.h>
float duty = 0;
void setup() {
  // put your setup code here, to run once:

  DDRD |= (1 << PD6); // PD6 as output

  //Fast PWM with TOP at 0xFF with non-inverted mode
  
  TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
  
  //OCR0=256D/100−1
  // Dytycycle 50% -> 256*50/100 -1 = 127
  OCR0A = 127;
  
  // Generate frquency 1KHz
  // set prescaler 64 
  // frequency = Fcpu/256*64 = 976.5625
  TCCR0B = (1 << CS01) | (1 << CS00);
 
}

void loop() {
  // put your main code here, to run repeatedly:

  
}



