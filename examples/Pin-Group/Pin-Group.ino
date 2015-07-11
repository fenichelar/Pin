/**
  @file Pin-Group.ino
  @author Alec Fenichel
  @brief Pin group example
  @details For advanced users only: simultaneously switch an array of multiple Pins between outputs and inputs
*/

#include <Pin.h>  // Include Pin library
#include <PinGroup.h>  // Include Pin library group functions

// The Pins used in this array must all be on the same DDR and PORT registers
// Look at the coresponding file in the boards directory to determine what register each pin is on
Pin myPinGroup[] = {0,1,2};  // Create array of Pin objects for digital pins labelled 0-2 on any of the supported boards

/**
  Called at start
 */
void setup() {
  Serial.begin(9600);
  
  // Check to ensure all pins in array use the same registers.
  if (checkPinGroup(myPinGroup)) {
    Serial.println("All Pins in array use the same registers.");
  } else {
    Serial.println("Pins in array do not use the same registers!");
    while(1) {}
  }
}

/**
  Called continously after setup
 */
void loop() {
  setOutputLow(myPinGroup);  // Simultaneously set array of Pins to output low
  
  delay(2);  // Wait 2 milliseconds
  
  setInput(myPinGroup);  // Simultaneously set array of Pins to input mode
  
  delay(2);  // Wait 2 milliseconds

}
