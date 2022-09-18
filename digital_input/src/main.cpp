#include <Arduino.h>
#define led B00100000 //led pin 5 port B PB5
#define button B00000100 // button pin 2 port D PD2

void setup() {
  // put your setup code here, to run once:
  DDRB = 0;
  DDRD = 0;
  DDRB |= led;
  // DDRD &= button;
}

void loop() {
  // put your main code here, to run repeatedly:

if (!(1 << PD2 & PIND)){

    PORTB |= B00100000;

}

else{

    PORTB &= !B00100000;
}


 
}