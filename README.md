Arduino Pin Library
===
An easy to use Arduino library for fast and simultaneous operations to Arduino I/O pins. Supports Arduino AVR boards natively and custom boards by manually defining register addresses. Complete documentation can be found [here](https://pin.fenichelar.com). Source code can be found [here](https://github.com/fenichelar/Pin). Common uses are listed below.

## Background
Background information about how direct port manipulation works can be found [here](https://www.arduino.cc/en/Reference/PortManipulation).

## Advantages
 - Much faster than built in digital functions
 - Easier to read than direct port manipulation
 - Allows for simultaneous operations on multiple pins
 - Portable across all Arduino AVR boards
 - Supports custom boards (`Pin.getAnalogValue()` and `Pin.setDutyCycle(int value)` not supported)

## Benchmarks
Simple benchmark programs were created to compare this library to both the built in Arduino functions and direct port manipulation. The three benchmark programs are included in the `examples/Benchmarks` directory. Each program switches pin 13 between HIGH and LOW as quickly as possible. The program flash memory usage and the frequency of the generated square wave are used for comparison. Results:

|                              | Filename                          | Flash Memory Usage | Output Frequency   |
| ---------------------------- | --------------------------------- | ------------------ | ------------------ |
| **Arduino**                  | `Arduino-Benchmark.ino`           | 1,354 bytes        | 64.91 kHz          |
| **Pin Library**              | `Pin-Library-Benchmark.ino`       | 1,164 bytes        | 532.3 kHz          |
| **Direct Port Manipulation** | `Port-Manipulation-Benchmark.ino` | 648 bytes          | 2661 kHz           |

## Install
Install from the Arduino Library Manager or download the latest release [here](https://github.com/fenichelar/Pin/releases/latest).

Import Pin Library
------
~~~~~~~~~~~~~{.cpp}
#include <Pin.h>
~~~~~~~~~~~~~

## Create Pin Object
Single Pin
~~~~~~~~~~~~~{.cpp}
Pin myPin = Pin(5);
~~~~~~~~~~~~~
Array of Pins
~~~~~~~~~~~~~{.cpp}
Pin myPins[] = {6,7};
~~~~~~~~~~~~~

## Use as Input
Set mode to input
~~~~~~~~~~~~~{.cpp}
myPin.setInput();
~~~~~~~~~~~~~
Enable pullup resistor
~~~~~~~~~~~~~{.cpp}
myPin.setPullupOn();
~~~~~~~~~~~~~
Disable pullup resistor
~~~~~~~~~~~~~{.cpp}
myPin.setPullupOff();
~~~~~~~~~~~~~

## Use as Output
Set mode to output
~~~~~~~~~~~~~{.cpp}
myPin.setOutput();
~~~~~~~~~~~~~
Set HIGH
~~~~~~~~~~~~~{.cpp}
myPin.setHigh();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPin = HIGH;
~~~~~~~~~~~~~
Set LOW
~~~~~~~~~~~~~{.cpp}
myPin.setLow();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPin = LOW;
~~~~~~~~~~~~~

## PWM
Set duty cycle to ~50% (not every Pin supports PWM)
~~~~~~~~~~~~~{.cpp}
myPin.setDutyCycle(127);
~~~~~~~~~~~~~

## Get Pin Info
Get mode (INPUT/OUTPUT)
~~~~~~~~~~~~~{.cpp}
myPin.getMode();
~~~~~~~~~~~~~
Get state (HIGH/LOW)
~~~~~~~~~~~~~{.cpp}
myPin.getState();
~~~~~~~~~~~~~
Get value (HIGH/LOW)
~~~~~~~~~~~~~{.cpp}
myPin.getValue();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPin == HIGH;
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPin == LOW;
~~~~~~~~~~~~~
Get analog value (0-1023)
~~~~~~~~~~~~~{.cpp}
myPin.getAnalogValue();
~~~~~~~~~~~~~

## Toggle
Toggle mode (OUTPUT -> INPUT, INPUT -> OUTPUT)
~~~~~~~~~~~~~{.cpp}
myPin.toggleMode();
~~~~~~~~~~~~~
Toggle state (HIGH -> LOW, LOW -> HIGH)
~~~~~~~~~~~~~{.cpp}
myPin.toggleState();
~~~~~~~~~~~~~

## RC Timer

Special function specifically for timing using series resistor-capacitor circuits. Used to get analog information on digital pins. Connect the pin between the variable resistor (force sensitive resistor, photoresistor, etc.) and the capacitor. The function will charge the capacitor through the resistor and count down the timer until it is charged (50% voltage is considered charged). The function returns the value remaining on the counter when the pin state went to HIGH or 0 if the counter reached 0. The higher the resistance, the longer the capacitor will take to charge. Longer charge times mean the counter will be decremented more resulting in a lower value returned. Therefore, higher resistance -> lower value returned, lower resistance -> higher value returned. Finally, the capacitor is discharged to allow the function to be called again.

Decrement a counter starting at 255 until the pin goes HIGH or the counter reaches 0
~~~~~~~~~~~~~{.cpp}
myPin.setLow();
myPin.rcTimer(255);
~~~~~~~~~~~~~

## Simultaneous Operations on Multiple Pins

All Pins in array must use the same DDR, PORT, and PIN registers. Look at the Arduino documentation for your board to determine what registers each pin uses. Because this library is built for speed, the Pin Group is not automatically checked to be valid for simultaneous operations. An invalid array will produce unexpected results without error, therefore it is highly recommended that the array be validated using the `isValid()` function during setup.

Import Pin Library with support for simultaneous operations
~~~~~~~~~~~~~{.cpp}
#include <Pin.h>
#include <PinGroup.h>
~~~~~~~~~~~~~
Create array of Pins for simultaneous operations
~~~~~~~~~~~~~{.cpp}
Pin myPins[] = {Pin(2),Pin(3),Pin(5)};
PinGroup myPinGroup = PinGroup(myPins);
~~~~~~~~~~~~~
Check to ensure each Pin in PinGroup use the same registers
~~~~~~~~~~~~~{.cpp}
myPinGroup.isValid();
~~~~~~~~~~~~~
Simultaneously set mode for each Pin in PinGroup to INPUT
~~~~~~~~~~~~~{.cpp}
myPinGroup.setInput();
~~~~~~~~~~~~~
Simultaneously set mode for each Pin in PinGroup to OUTPUT
~~~~~~~~~~~~~{.cpp}
myPinGroup.setOutput();
~~~~~~~~~~~~~
Simultaneously set state each Pin in PinGroup to HIGH
~~~~~~~~~~~~~{.cpp}
myPinGroup.setHigh();
~~~~~~~~~~~~~
Simultaneously set state each Pin in PinGroup to LOW
~~~~~~~~~~~~~{.cpp}
myPinGroup.setLow();
~~~~~~~~~~~~~
Simultaneously check if each Pin in PinGroup is HIGH
~~~~~~~~~~~~~{.cpp}
myPinGroup.getValue() == HIGH;
~~~~~~~~~~~~~
Simultaneously check if each Pin in PinGroup is LOW
~~~~~~~~~~~~~{.cpp}
myPinGroup.getValue() == LOW;
~~~~~~~~~~~~~
Simultaneously set each Pin in PinGroup to its opposite mode
~~~~~~~~~~~~~{.cpp}
myPinGroup.toggleMode();
~~~~~~~~~~~~~
Simultaneously set each Pin in PinGroup to its opposite state
~~~~~~~~~~~~~{.cpp}
myPinGroup.toggleState();
~~~~~~~~~~~~~
