/**
  @example Pin-Analog.ino
  @file Pin-Analog.ino
  @author Alec Fenichel
  @brief Read analog pins
*/

#include <Pin.h>  // Include Pin Library

Pin myPin0 = Pin(A0);  // Create Pin object for analog pin labelled A0 on any of the supported boards
Pin myPin1 = Pin(17);  // Create Pin object for analog pin labelled A3 on the Arduino Uno (Pin(17) = Pin(A3) for the Arduino Uno)

/**
  Called at start
 */
void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud

  myPin0.setInput();  // Set Pin to input mode
  myPin1.setInput();  // Set Pin to input mode
}

/**
  Called continously after setup
 */
void loop() {

  // Read the analog value of the Pins
  Serial.println("A0 value: " + String(myPin0.getAnalogValue()));
  Serial.println("17 value: " + String(myPin1.getAnalogValue()));

  delay(500);  // Wait 500 milliseconds
}
