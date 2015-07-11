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
Pin myPinsGroup[] = {0,1,2};  // Create array of Pin objects for digital pins labelled 0-2 on any of the supported boards

/**
  Called at start
 */
void setup() {
}

/**
  Called continously after setup
 */
void loop() {
  setOutputLow(myPinsGroup);  // Simultaneously set array of Pins to output low
  
  delay(2);  // Wait 2 milliseconds
  
  setInput(myPinsGroup);  // Simultaneously set array of Pins to input mode
  
  delay(2);  // Wait 2 milliseconds

}
