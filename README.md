Pin
===
An easy to use Arduino library for fast digital I/O using port manipulation. Supports Arduino Mega, Arduino Uno, and Arduino Leonardo. Complete documentation can be found [here](https://fenichelar.github.io/Pin). Common uses are listed below.

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
Set Mode to Input
```C
myPin.setInput();
```
Enable/Disable Pullup Resistor
```C
myPin.setPullupOn();
```
```C
myPin.setPullupOff();
```

## Use as Output
Set Mode to Output
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
Get Mode (INPUT/OUTPUT)
```C
myPin.getMode();
```
Get State (HIGH/LOW)
```C
myPin.getState();
```
Get Value (HIGH/LOW)
```C
myPin.getValue();
```

## Toggle
Toggle Mode (OUTPUT -> INPUT, INPUT -> OUTPUT)
```C
myPin.toggleMode();
```
Toggle State (HIGH -> LOW, LOW -> HIGH)
```C
myPin.toggleState();
```
