/**
  @example Pin-Group.ino
  @file Pin-Group.ino
  @author Alec Fenichel
  @brief Simultaneously toggle a Pin Groups output
*/

#include <Pin.h>  // Include Pin Library
#include <PinGroup.h>  // Include Pin Library with support for simultaneous operations

Pin myPins[] = {Pin(2),Pin(3),Pin(5)}; // Create array of Pin objects for digital pins labelled 2,3,5 on the Arduino Uno

// The Pins used in this array must use the same DDR, PORT, and PIN registers
// Look at the Arduino documentation for your board to determine what registers each pin uses
PinGroup myPinGroup = PinGroup(myPins);  // Create a Pin Group

/**
  Called at start
 */
void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud

  // Check to ensure all Pins in the Pin Group use the same registers
  if(myPinGroup.isValid()) {
    Serial.println("Pin Group is valid.");
  } else {
    Serial.println("Pin Group is not valid!");
    while(1) {}  // Infinite loop
  }

  myPinGroup.setOutput();  // Simultaneously set all Pins in the Pin Group to output

  // Set the Pins in the Pin Group output to different values
  myPins[0].setLow();
  myPins[1].setHigh();
  myPins[2].setLow();
}

/**
  Called continously after setup
 */
void loop() {
  myPinGroup.toggleState();  // Simultaneously set each Pin in Pin Group to its opposite state

  delay(200);  // Wait 200 milliseconds

}
