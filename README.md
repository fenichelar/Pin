Arduino Pin Library
===
An easy to use Arduino library for fast and simultaneous operations to Arduino I/O pins using port manipulation. Supports Arduino AVR boards natively and custom boards by manually defining register addresses. Complete documentation can be found [here](https://pin.fenichelar.com). Source code can be found [here](https://github.com/fenichelar/Pin). Common uses are listed below.

## Background
Background information about how direct port manipulation works can be found [here](https://www.arduino.cc/en/Reference/PortManipulation).

## Advantages
 - Much faster than built in digital functions
 - More portable and easier to read than direct port manipulation
 - Allows for simultaneous operations on multiple pins
 - Supports custom boards (`getAnalogValue()` and `setDutyCycle(int value)` not supported)

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
Enable/disable pullup resistor
~~~~~~~~~~~~~{.cpp}
myPin.setPullupOn();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPin.setPullupOff();
~~~~~~~~~~~~~

## Use as Output
Set mode to output
~~~~~~~~~~~~~{.cpp}
myPin.setOutput();
~~~~~~~~~~~~~
Set HIGH/LOW
~~~~~~~~~~~~~{.cpp}
myPin.setHigh();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPin.setLow();
~~~~~~~~~~~~~

## PWM
Set duty cycle to ~50% (not all pins support PWM)
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
Check to ensure all Pins in Pin Group use the same registers
~~~~~~~~~~~~~{.cpp}
myPinGroup.isValid() == true
~~~~~~~~~~~~~
Simultaneously set mode for Pin Group to input/output
~~~~~~~~~~~~~{.cpp}
myPinGroup.setInput();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPinGroup.setOutput();
~~~~~~~~~~~~~
Simultaneously set all Pins in Pin Group to HIGH/LOW
~~~~~~~~~~~~~{.cpp}
myPinGroup.setHigh();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPinGroup.setLow();
~~~~~~~~~~~~~
Simultaneously check if all Pins in Pin Group are HIGH/LOW
~~~~~~~~~~~~~{.cpp}
myPinGroup.getValue() == HIGH
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPinGroup.getValue() == LOW
~~~~~~~~~~~~~
Simultaneously set each Pin in Pin Group to its opposite mode/state
~~~~~~~~~~~~~{.cpp}
myPinGroup.toggleMode();
~~~~~~~~~~~~~
~~~~~~~~~~~~~{.cpp}
myPinGroup.toggleState();
~~~~~~~~~~~~~
