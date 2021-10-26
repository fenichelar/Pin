/**
  Test port manipulation I/O performance

  @file Port-Manipulation-Benchmark.ino
  @author Alec Fenichel
*/

/**
  Called at start
 */
void setup() {
  DDRB |= B10000000;  // Set Pin 13 on Arduino Mega to output mode
}

/**
  Called continously after setup
 */
void loop() {
  while(true) {
    PORTB |= B10000000;  // Set Pin 13 on Arduino Mega to output HIGH
    PORTB &= B01111111;  // Set Pin 13 on Arduino Mega to output LOW
  }
}
