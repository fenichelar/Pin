/**
  @file Pin-Group.ino
  @author Alec Fenichel
  @brief Pin group example
  @details Simultaneously switch an array of multiple Pins between outputs and inputs
*/

#include <PinGroup.h>  // Include Pin library group functions

// The Pins used in this array must all be on the same DDR and PORT registers
// Look at the coresponding file in the boards directory to determine what register each pin is on
Pin myPinGroup[] = {2,3,4,5};  // Create array of Pin objects for digital pins labelled 2,3,5 on the Arduino Uno or Mega (not valid for Leonardo)

/**
  Called at start
 */
void setup() {
  Serial.begin(9600);

  // Check to ensure all pins in array use the same registers
  if (checkPinGroup(myPinGroup) == true)
    Serial.println("All Pins in array use the same registers.");
  else  // Infinite loop
    while(1) Serial.println("Pins in array do not use the same registers!");
}

/**
  Called continously after setup
 */
void loop() {

  setOutputLow(myPinGroup);   // Simultaneously set Pin group to output low
  delay(300);

  toggleState(myPinGroup);    // Simultaneously toggle Pin Group.
  delay(500);

  setInput(myPinGroup);       // Simultaneously set Pin Group to input mode
  setLow(myPinGroup);         // Simultaneously set Pin Group LOW
  delay(200);

  // Simultaneously read Pin Group value
  getValue(myPinGroup) == HIGH  ? Serial.println("All Pins in array are HIGH.") :
  getValue(myPinGroup) == LOW   ? Serial.println("All Pins in array are LOW.")
                                : Serial.println("Pins in array are not the same value.");

  delay(200);
}
