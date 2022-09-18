#include <Arduino.h>

// Using led1 pin 13 which is the PB5 in port B
#define led1 B00100000
// Using led2 pin 12 which is the PB4 in port B
#define led2 PB4

void blink_led_using_bitwise(int ms);
void blink_led_using_bit_shift(int ms);
void setup() {
  
  // Define led1 PB5 is the output which equal to the led pin13
  DDRB = led1;  
  
  // or we can write using Bit shifting

  //DDRB |= (1 << PB5);
  
  // Define port B output 
  PORTB = 0; // = B00000000
}

void loop() {
  // put your main code here, to run repeatedly:
blink_led_using_bitwise(100);
blink_led_using_bit_shift(200);

}

// blink led every ms using bitwise operator
void blink_led_using_bitwise(int ms){

  PORTB |= led1; //set port B to 0000000 | 00100000 = 00100000
  _delay_ms(ms); // delay ms
  PORTB &= ~led1; // set port B to 0010000 & 11011111 = 00000000 (~00100000 = 11011111)
  _delay_ms(ms); // delay ms

  /*
  '''

  or we can write using xor (^)

  ''' 
  */
  

  // PORTB ^= led; 
  // _delay_ms(ms);

  /*
  First loop:
  Port B is equal to 00000000 ^ 00100000 = 00100000
  Second loop:
  Port B is equal to 00100000 ^ 00100000 = 00000000
  */
  
}

void blink_led_using_bit_shift(int ms){

  PORTB |= (1 << led2); // (1 << 4) = 0B00010000
  _delay_ms(ms);
  PORTB &= ~(1 << led2);
  _delay_ms(ms);

}