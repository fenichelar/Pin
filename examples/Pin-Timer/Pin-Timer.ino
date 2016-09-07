/**
  @example Pin-Timer.ino
  @file Pin-Timer.ino
  @author Alec Fenichel
  @brief Use an RC circuit with a digital Pin to get analog values
*/

#include <Pin.h>  // Include Pin Library

Pin myPin = Pin(13);  // Create Pin object for digital pin labelled 13 on any of the supported boards

/**
  Called at start
 */
void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud
  myPin.setLow();  // Set Pin state to LOW to disable the pullup resistor and make sure the pin is driven to low at the end of the the rcTimer function, THIS IS VERY IMPORTANT
}

/**
  Called continously after setup
 */
void loop() {
  delay(500);  // Wait 500 milliseconds

  // If a force sensitve resistor is used with a capacitor, the more force applied to the fsr (lower resistance), the faster the capactor will charge resulting in a number closer to the inital value
  Serial.println(String(myPin.rcTimer(255)));  // Print the value remaining on the timer when the pin went HIGH
}
