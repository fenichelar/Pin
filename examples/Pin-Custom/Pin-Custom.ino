/**
  @example Pin-Custom.ino
  @file Pin-Custom.ino
  @author Alec Fenichel
  @brief Quickly toggling a custom Pins output
*/

#include <Pin.h>  // Include Pin Library

Pin myPin = Pin(13, 1<<7, TIMER0A, &PINB, &PORTB, &DDRB);  // Create Pin object for digital pin labelled 13 on Arduino Mega, getAnalogValue() and setDutyCycle(int value) not supported

/**
  Called at start
 */
void setup() {
  myPin.setOutput();  // Set Pin to output mode
  myPin.setHigh();  // Set Pin to output high
}

/**
  Called continously after setup
 */
void loop() {
  myPin.toggleState();  // Set Pin to output the opposite of the previous output (HIGH -> LOW, LOW -> HIGH)

  delay(200);  // Wait 200 milliseconds
}
