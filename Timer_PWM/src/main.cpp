#include <Arduino.h>
#include <avr/interrupt.h>
float duty1 = 50;
float duty2 = 30;
void pwm_top_oc0a(float duty);
void pwm_top_oc0a1(float duty);
void setup() {
  // put your setup code here, to run once:
  // Timer 0
  DDRD |= (1 << PD6) | (1 << PD5); // PD6 and PD5 as output

  //Fast PWM with TOP at 0xFF with non-inverted mode
  TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
  

  //OCR0=256D/100−1
  // Dytycycle 50% -> 256*50/100 -1 = 127
  OCR0A = (256*duty1/100) - 1;
  OCR0B = (256*duty2/100) - 1;
  // Generate frquency 1KHz
  // set prescaler 64 
  // frequency = Fcpu/256*64 = 976.5625
  TCCR0B = (1 << CS01) | (1 << CS00);


  // Timer 2

  DDRD |= (1 << PD3); // PD3 as output
  DDRB |= (1 << PB3); // PB3 as output

  // Fast PWM with TOP at oxFF with inverted mode
  TCCR2A |= (1 << COM2A1) | (1 << COM2A0) | (1<< COM2B0) | (1<< COM2B1) | (1 << WGM20) | (1 << WGM21);

  // Set duty cycle

  //OCR2 = 255 - 256*Duty/100
  OCR2A = 255 - 256*duty1/100;
  OCR2B = 255 - 256*duty2/100;

  // Generate Frequency at =~ 8KHz
  // set prescaler 8
  // frequency = Fcpu/256*8 = 7812.5
  TCCR2B = (1 << CS21);
} 

void loop() {
  // put your main code here, to run repeatedly:



}

