Arduino Pin Library
===
An easy to use Arduino library for fast digital I/O using port manipulation. Capable of simultaneous operations on multiple Pins. Supports Arduino Mega, Arduino Uno, and Arduino Leonardo. Complete documentation can be found [here](https://pin.fenichelar.com). Source code can be found [here](https://github.com/fenichelar/Pin). Common uses are listed below.

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

All Pins in array must use the same DDR, PORT, and PIN registers. Look at the Arduino documentation for your board to determine what registers each pin uses. Because this library is built for speed, the array of pins is not automatically checked to be valid for simultaneous operations. An invalid array will produce unexpected results without error, therefore it is highly recommended that the array be validated using the `checkPinGroup()` function during setup.

Import Pin library with support for simultaneous operations
~~~~~~~~~~~~~{.cpp}
#include <Pin.h>
#include <PinGroup.h>
~~~~~~~~~~~~~
Create array of Pins for simultaneous operations
~~~~~~~~~~~~~{.cpp}
Pin myPinGroup[] = {2,3,5};
~~~~~~~~~~~~~
Check to ensure all pins in array of pins use the same registers
~~~~~~~~~~~~~{.cpp}
checkPinGroup(myPinGroup) == true
~~~~~~~~~~~~~
Simultaneously set mode for array of Pins to input
~~~~~~~~~~~~~{.cpp}
setInput(myPinGroup);
~~~~~~~~~~~~~
Simultaneously set mode for array of Pins to output
~~~~~~~~~~~~~{.cpp}
setOutput(myPinGroup);
~~~~~~~~~~~~~
Simultaneously check if array of Pins are all HIGH
~~~~~~~~~~~~~{.cpp}
getValue(myPinGroup) == HIGH
~~~~~~~~~~~~~
Simultaneously check if array of Pins are all LOW
~~~~~~~~~~~~~{.cpp}
getValue(myPinGroup) == LOW
~~~~~~~~~~~~~
