/**
  @file Pin-Analog.ino
  @author Alec Fenichel
  @brief Pin analog example
  @details Use analog pins with the Pin library
*/

#include <Pin.h>  // Include Pin library

Pin myPin0 = Pin(0, true);  // Create Pin object for analog pin labelled 0 on any of the supported boards
Pin myPin1 = Pin(2, true);  // Create Pin object for analog pin labelled 2 on any of the supported boards
Pin myPin2 = Pin(17);  // Create Pin object for analog pin labelled 3 on the Arduino Uno (Pin(17) = Pin(3, true) for the Arduino Uno)

/**
  Called at start
 */
void setup() {
  myPin0.setOutput();  // Set Pin to output mode
  myPin1.setOutput();  // Set Pin to output mode
  myPin2.setInput();  // Set Pin to input mode
}

/**
  Called continously after setup
 */
void loop() {
}
