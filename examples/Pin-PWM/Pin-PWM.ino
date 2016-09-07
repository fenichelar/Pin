/**
  @example Pin-PWM.ino
  @file Pin-PWM.ino
  @author Alec Fenichel
  @brief Use PWM
*/

#include <Pin.h>  // Include Pin Library

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
