/**
  Test Arduino I/O performance

  @file Arduino-Benchmark.ino
  @author Alec Fenichel
*/

#define PIN 13  // Define PIN for digital pin labelled 13 on any of the supported boards

/**
  Called at start
 */
void setup() {
  pinMode(PIN, OUTPUT);  // Set PIN to output mode
}

/**
  Called continously after setup
 */
void loop() {
  while(true) {
    digitalWrite(PIN, HIGH);  // Set PIN to output HIGH
    digitalWrite(PIN, LOW);  // Set PIN to output LOW
  }
}
