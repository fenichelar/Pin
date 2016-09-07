/**
  @example Pin-Array.ino
  @file Pin-Array.ino
  @author Alec Fenichel
  @brief Quickly switch an array of Pins output between low and high
*/

#include <Pin.h>  // Include Pin Library

Pin myPins[] = {2,3,4,5,6,7,8,9};  // Create array of Pin objects for digital pins labelled 2-9 on any of the supported boards
int myPinsSize = sizeof(myPins) / sizeof(Pin); // Store the length of the array of Pins

/**
  Called at start
 */
void setup() {
  for (int i = 0; i < myPinsSize; i++) {  // Iterate over array of Pins
    myPins[i].setOutput();  // Set Pin to output
  }
}

/**
  Called continously after setup
 */
void loop() {
  for (int i = 0; i < myPinsSize; i++) {  // Iterate over array of Pins
    myPins[i].setLow();  // Set Pin to low
  }

  delay(200);  // Wait 200 milliseconds

  for (int i = 0; i < myPinsSize; i++) {  // Iterate over array of Pins
    myPins[i].setHigh();  // Set Pin to high
  }

  delay(200);  // Wait 200 milliseconds

}
