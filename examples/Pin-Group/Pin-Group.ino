/**
  @file Pin-Group.ino
  @author Alec Fenichel
  @brief Pin group example
  @details Simultaneously switch an array of multiple Pins between outputs and inputs
*/

#include <Pin.h>  // Include Pin library
#include <PinGroup.h>  // Include Pin library group functions

// The Pins used in this array must all be on the same DDR and PORT registers
// Look at the coresponding file in the boards directory to determine what register each pin is on
Pin myPinGroup[] = {2,3,5};  // Create array of Pin objects for digital pins labelled 2,3,5 on the Arduino Uno or Mega (not valid for Leonardo)

/**
  Called at start
 */
void setup() {
  Serial.begin(9600);

  // Check to ensure all pins in array use the same registers
  if (checkPinGroup(myPinGroup) == true) {
    Serial.println("All Pins in array use the same registers.");
  } else {
    Serial.println("Pins in array do not use the same registers!");
    while(1) {}  // Infinite loop
  }
}

/**
  Called continously after setup
 */
void loop() {
  setOutputLow(myPinGroup);  // Simultaneously set array of Pins to output low

  delay(200);  // Wait 200 milliseconds

  setInput(myPinGroup);  // Simultaneously set array of Pins to input mode

  delay(200);  // Wait 200 milliseconds

  // Simultaneously read an array of Pins value
  if (getValue(myPinGroup) == HIGH) {
    Serial.println("All Pins in array are HIGH.");
  } else if (getValue(myPinGroup) == LOW) {
    Serial.println("All Pins in array are LOW.");
  } else {
    Serial.println("Pins in array are not the same value.");
  }

  delay(200);  // Wait 200 milliseconds

}
