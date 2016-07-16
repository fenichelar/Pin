/**
  @file Pin-Analog.ino
  @author Alec Fenichel
  @brief Pin analog example
  @details Use analog pins with the Pin Library
*/

#include <Pin.h>  // Include Pin Library

Pin myPin0 = Pin(A0);  // Create Pin object for analog pin labelled A0 on any of the supported boards
Pin myPin1 = Pin(17);  // Create Pin object for analog pin labelled A3 on the Arduino Uno (Pin(17) = Pin(A3) for the Arduino Uno)

/**
  Called at start
 */
void setup() {
  Serial.begin(9600);

  myPin0.setInput();  // Set Pin to input mode
  myPin1.setInput();  // Set Pin to input mode
}

/**
  Called continously after setup
 */
void loop() {

  // Read the analog value of the Pins
  Serial.print("A0 value: ");
  Serial.println(myPin0.getAnalogValue());
  Serial.print("17 value: ");
  Serial.println(myPin1.getAnalogValue());

  delay(500);  // Wait 500 milliseconds
}
