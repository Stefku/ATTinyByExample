#include <avr/io.h>

void setup() {
  DDRB = 1<<DDB4;     // define PB4 as output
  pinMode(4, OUTPUT); // define PB4 as output
}

void loop() {
  // set PB4 to logical HIGH using different notations
  // following lines until delay have same effect on PB4
  PORTB = 0b00010000; // turn on PB4, all others off
  PORTB = 1<<PB4;     // turn on PB4, all others off
  PORTB |= 1<<PB4;    // just toggle PB4 on, all others stay as they are
  digitalWrite(4, HIGH); // just toggle PB4 on, all others stay as they are
  delay(1000);
  // set PB4 to logical LOW using different notations
  // following lines until delay have same effect on PB4
  PORTB = 0;          // turn off whole PortB
  PORTB = 0b00000000; // turn off whole PortB
  PORTB &= 1<<PB4;    // just toggle PB4 off, all others stay as they are
  digitalWrite(4, LOW); // just toggle PB4 off, all others stay as they are
  delay(1000);
}
