/**
  @file Pin-Analog.ino
  @author Alec Fenichel
  @brief Pin analog example
  @details Use analog pins with the Pin library
*/

#include <Pin.h>  // Include Pin library

Pin myPin0 = Pin(0, true);  // Create Pin object for analog pin labelled A0 on any of the supported boards
Pin myPin1 = Pin(17);  // Create Pin object for analog pin labelled A3 on the Arduino Uno (Pin(17) = Pin(3, true) for the Arduino Uno)

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

  Serial.println("AA value: " + myPin0.getAnalogValue()); // Read the analog value of the pin
  Serial.println("A3 value: " + myPin1.getAnalogValue()); // Read the analog value of the pin

  delay(200);  // Wait 200 milliseconds
}
