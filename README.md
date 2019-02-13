# ATtiny By Example (in progress)

# Interrupts
## Interrupt at any logical change
### Triggered from external source
```
#include <avr/io.h>
#include <avr/interrupt.h>

void initInterrupt() {
  GIMSK |= 1 << INT0;       // enable INT0 interrupt
  MCUCR |= 1 << ISC00;      // configure INT0 to ..
  MCUCR &= ~(1 << ISC01);   // .. interrupt at any logical change at INT0
  sei();                    // globaly enable interrupts
}

void setup() {
  DDRB |= 1 << DDB4;     // define PB4 as output
  DDRB &= ~ (1 << DDB1); // define PB1 as input
  PORTB |= 1 << PB1;    // enable pull up resistor at PB1
  initInterrupt();
}

ISR(INT0_vect) {
  PORTB ^= (1 << PB4);   // inverse logical level at PB4 / blink
}

void loop() {
  // nop
}
```

### Triggered from internal source
```
#include <avr/io.h>
#include <avr/interrupt.h>

void initInterrupt() {
  GIMSK |= 1 << INT0;       // enable INT0 interrupt
  MCUCR |= 1 << ISC00;      // configure INT0 to ..
  MCUCR &= ~(1 << ISC01);   // .. interrupt at any logical change at INT0
  sei();                    // globaly enable interrupts
}

void setup() {
  DDRB |= 1 << DDB4;     // define PB4 as output
  DDRB |= 1 << DDB1;     // define PB1 as output
  initInterrupt();
}

ISR(INT0_vect) {
  PORTB ^= (1 << PB4);   // inverse logical level at PB4 / blink
}

void loop() {
  delay(1000); 
  PORTB ^= 1 << PB1;    // switch state at PB1
}
```

# Datasheet
Please refere to the datasheet of ATtiny13A [http://ww1.microchip.com/downloads/en/DeviceDoc/doc8126.pdf]().

# Arduino IDE

## ATTiny13
For to have ATtiny13 configure additional board manager URL [https://mcudude.github.io/MicroCore/package_MCUdude_MicroCore_index.json]().

## In-System-Programming via USBtinyISP
Via Programmer USBtinyISP
