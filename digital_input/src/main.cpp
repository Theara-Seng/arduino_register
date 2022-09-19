#include <Arduino.h>
#define led B00100000 //led pin 5 port B PB5
#define button B00000100 // button pin 2 port D PD2
// Note* 1 in button is just indicated, PD2 need to be 0 to define as input

void setup() {
  // put your setup code here, to run once:
  DDRB = 0;
  DDRD = 0;
  DDRB |= led;
  DDRD &= button; // 00000000 & 00000100 = 00000000
}

void loop() {
  // put your main code here, to run repeatedly:
/*

Using pull up resistance with the button, it mean that when it is not press
, it is high->1. When it is pressed, it is low->0

*/


if (!(1 << PD2 & PIND)){
    /*

    (1 << PD2) = 00000100
    PIND = 11111111
    => (1 << PD2) & PIND = 00000100-> PD2 is high
    => by setting !, so when it is low -> do something

    */
    
    PORTB |= B00100000; // PB5 is 1

}

else{

    PORTB &= !B00100000; // PB5 is 0
    
}


 
}