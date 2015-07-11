Arduino Pin Library
===
An easy to use Arduino library for fast digital I/O using port manipulation. Capable of simultaneous operations on multiple Pins. Supports Arduino Mega, Arduino Uno, and Arduino Leonardo. Complete documentation can be found [here](https://fenichelar.github.io/Pin). Common uses are listed below.

## Install
Install from the Arduino Library Manager or download the latest release [here](https://github.com/fenichelar/Pin/releases/latest).

## Import Pin Library
```C
#include <Pin.h>
```

## Create Pin Object
Single Pin
```C
Pin myPin = Pin(5);
```
Array of Pins
```C
Pin myPins[] = {6,7};
```

## Use as Input
Set mode to input
```C
myPin.setInput();
```
Enable/disable pullup resistor
```C
myPin.setPullupOn();
```
```C
myPin.setPullupOff();
```

## Use as Output
Set mode to output
```C
myPin.setOutput();
```
Set HIGH/LOW
```C
myPin.setHigh();
```
```C
myPin.setLow();
```

## Get Pin Info
Get mode (INPUT/OUTPUT)
```C
myPin.getMode();
```
Get state (HIGH/LOW)
```C
myPin.getState();
```
Get value (HIGH/LOW)
```C
myPin.getValue();
```

## Toggle
Toggle mode (OUTPUT -> INPUT, INPUT -> OUTPUT)
```C
myPin.toggleMode();
```
Toggle state (HIGH -> LOW, LOW -> HIGH)
```C
myPin.toggleState();
```

## Simultaneous Operations on Multiple Pins

For advanced users only! All Pins in array must use the same DDR and PORT registers. Look at the coresponding file in the boards directory to determine what register each pin uses.

Import Pin Library with support for simultaneous operations
```C
#include <PinGroup.h>
```
Create array of Pins for simultaneous operations
```C
Pin myPinsGroup[] = {0,1,2};
```
Simultaneously set mode for array of Pins to input
```C
setInput(myPinsGroup);
```
Simultaneously set mode for array of Pins to output
```C
setOutput(myPinsGroup);
```

