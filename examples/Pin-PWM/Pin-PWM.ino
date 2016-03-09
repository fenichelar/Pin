/**
  @file Pin-PWM.ino
  @author Alec Fenichel
  @brief Pin PWM example
  @details Use PWM with the Pin library
*/

#include <Pin.h>  // Include Pin library

Pin myPin = Pin(5);  // Create Pin object for digital pin labelled 5 on any of the supported boards

/**
  Called at start
 */
void setup() {
  myPin.setOutput();  // Set Pin to output mode
  // The Pin must support PWM
  myPin.setDutyCycle(127);  // Set Pin duty cycle to 127 (~50%)
}

/**
  Called continously after setup
 */
void loop() {
}
