/**
  @example Pin-Library-Benchmark.ino
  @file Pin-Library-Benchmark.ino
  @author Alec Fenichel
  @brief Test Pin Library I/O performance
*/

#include <Pin.h>  // Include Pin Library

Pin myPin = Pin(13);  // Create Pin object for digital pin labelled 13 on any of the supported boards

/**
  Called at start
 */
void setup() {
  myPin.setOutput();  // Set Pin to output
}

/**
  Called continously after setup
 */
void loop() {
  while(true) {
    myPin.setHigh();  // Set Pin to output HIGH
    myPin.setLow();  // Set Pin to output LOW
  }
}
