/**
  @file Pin-Array.ino
  @author Alec Fenichel
  @brief Pin array example
  @details Quickly switch an array of Pins between outputs and inputs
*/

#include <Pin.h>  // Include Pin library

Pin myPins[] = {2,3,4,5,6,7,8,9}; // Create array of Pin objects for digital pins labelled 2-9 on any of the supported boards
int myPinsSize = sizeof(myPins) / sizeof(Pin); // Store the length of the array of Pins

/**
  Called at start
 */
void setup() {
  myPins.setOutput();
}

/**
  Called continously after setup
 */
void loop() {

  myPins.toggleState();
  for (int i = 0; i < myPinsSize; i++) {  // Iterate over array of Pins
    myPins[i].toggleState();  // Set Pin to output low
  }

  delay(200);  // Wait 200 milliseconds

  for (int i = 0; i < myPinsSize; i++) {  // Iterate over array of Pins
    myPins[i].setInput();  // Set Pin to input mode
  }

  delay(200);  // Wait 200 milliseconds

}
