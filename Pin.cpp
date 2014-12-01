/*
  Pin.cpp - Library for pins.
  Author: Alec Fenichel
*/


// ################################# Includes #################################

#include "Pin.h"


// ################################# Defines #################################

#define DDR_HIGH (*_DDR |= _offset)
#define DDR_LOW (*_DDR &= ~_offset)

#define PORT_HIGH (*_PORT |= _offset)
#define PORT_LOW (*_PORT &= ~_offset)

#define DDR_ON (*_DDR & _offset)
#define PORT_ON (*_PORT & _offset)
#define PIN_ON (*_PIN & _offset)

#define REGA &PINA,&PORTA,&DDRA
#define REGB &PINB,&PORTB,&DDRB
#define REGC &PINC,&PORTC,&DDRC
#define REGD &PIND,&PORTD,&DDRD
#define REGE &PINE,&PORTE,&DDRE
#define REGF &PINF,&PORTF,&DDRF
#define REGG &PING,&PORTG,&DDRG
#define REGH &PINH,&PORTH,&DDRH
#define REGI &PINI,&PORTI,&DDRI
#define REGJ &PINJ,&PORTJ,&DDRJ
#define REGK &PINK,&PORTK,&DDRK
#define REGL &PINL,&PORTL,&DDRL


// ################################# Declarations/Initializations #################################

struct pinMapping {
	volatile uint8_t* pin;
	volatile uint8_t* port;
	volatile uint8_t* ddr;
	const uint8_t offset;
};

// Arduino Mega
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	#include "mega.h"
#endif

// Arduino Uno
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
	#include "uno.h"
#endif

// Arduino Leonardo
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
	#include "leonardo.h"
#endif


// ################################# Constructors #################################

// Basic constructor
// Inputs: uint8_t number - pin number written on board if digital, then the first analog pin is at the index after the last digital pin
// Outputs: none
Pin::Pin(uint8_t number) {
	init(number);
}

// Easier constructor
// Inputs: uint8_t number - pin number written on board, bool analog - true if pin is analog, false if pin is digital
// Outputs: none
Pin::Pin(uint8_t number, bool analog) {
	if (analog) {
		init(number + ANALOGOFFSET);
	} else {
		init(number);
	}
}

// Function to construct pin, not called by user, use wrapper constructors above
// Inputs: uint8_t number - pin number written on board if digital, then the first analog pin is at the index after the last digital pin
// Outputs: none
void Pin::init(uint8_t number) {
	_number = number;
	_offset = pinMappings[_number].offset;
	_PIN = pinMappings[_number].pin;
	_PORT = pinMappings[_number].port;
	_DDR = pinMappings[_number].ddr;
}


// ################################# Getters #################################

// Function to get the pin number
// Inputs: none
// Outputs: uint8_t - pin number
uint8_t Pin::getNumber() {
	return _number;
}

// Function to get the pin offset
// Inputs: none
// Outputs: uint8_t - pin offset
uint8_t Pin::getOffset() {
	return _offset;
}

// Function to get a pointer to the PIN register
// Inputs: none
// Outputs: volatile uint8_t* - pointer to the PIN register
volatile uint8_t* Pin::getPIN() {
	return _PIN;
}

// Function to get a pointer to the PORT register
// Inputs: none
// Outputs: volatile uint8_t* - pointer to the PORT register
volatile uint8_t* Pin::getPORT() {
	return _PORT;
}

// Function to get a pointer to the DDR register
// Inputs: none
// Outputs: volatile uint8_t* - pointer to the DDR register
volatile uint8_t* Pin::getDDR() {
	return _DDR;
}

// Function to get the mode of the pin from the DDR register
// Inputs: none
// Outputs: uint8_t - mode of the pin (OUTPUT, INPUT)
uint8_t Pin::getMode() {
	if DDR_ON {
		return OUTPUT;
	} else {
		return INPUT;
	}
}

// Function to get the state of the pin from the PORT register
// Inputs: none
// Outputs: uint8_t - state of the pin (HIGH, LOW)
uint8_t Pin::getState() {
	if PORT_ON {
		return HIGH;
	} else {
		return LOW;
	}
}

// Function to get the value of the pin from the PIN register
// Inputs: none
// Outputs: uint8_t - value of the pin (HIGH, LOW)
uint8_t Pin::getValue() {
	if PIN_ON {
		return HIGH;
	} else {
		return LOW;
	}
}


// ################################# Setters #################################

// #################### Generic ####################

// Function to set the pin mode and pin state
// Inputs: uint8_t mode - the mode of the pin (OUTPUT, INPUT), uint8_t state - the state of the pin (HIGH, LOW)
// Outputs: bool - true if pin successfully updated, false otherwise
bool Pin::set(uint8_t mode, uint8_t state) {
	return (setMode(mode) && setState(state));
}

// Function to set the pin mode
// Inputs: uint8_t mode - the mode of the pin (OUTPUT, INPUT)
// Outputs: bool - true if pin successfully updated, false otherwise
bool Pin::setMode(uint8_t mode) {
	if (mode == INPUT) {
		DDR_LOW;
	} else if (mode == OUTPUT) {
		DDR_HIGH;
	} else {
		return false;
	}
	
	return true;
}

// Function to set the pin state
// Inputs: uint8_t state - the state of the pin (HIGH, LOW)
// Outputs: bool - true if pin successfully updated, false otherwise
bool Pin::setState(uint8_t state) {
	if (state == LOW) {
		PORT_LOW;
	} else if (state == HIGH) {
		PORT_HIGH;
	} else {
		return false;
	}
	
	return true;
}

// #################### Input ####################

// Function to set the pin mode to input
// Inputs: none
// Outputs: none
void Pin::setInput() {
	DDR_LOW;
}

// Function to set the pin pullup resistor to on
// Inputs: none
// Outputs: none
void Pin::setPullupOn() {
	PORT_HIGH;
}

// Function to set the pin pullup resistor to off
// Inputs: none
// Outputs: none
void Pin::setPullupOff() {
	PORT_LOW;
}

// Function to set the pin mode to input and the pin pullup resistor to on
// Inputs: none
// Outputs: none
void Pin::setInputPullupOn() {
	DDR_LOW;
	PORT_HIGH;
}

// Function to set the pin mode to input and the pin pullup resistor to off
// Inputs: none
// Outputs: none
void Pin::setInputPullupOff() {
	DDR_LOW;
	PORT_LOW;
}

// #################### Output ####################

// Function to set the pin mode to output
// Inputs: none
// Outputs: none
void Pin::setOutput() {
	DDR_HIGH;
}

// Function to set the pin output to HIGH
// Inputs: none
// Outputs: none
void Pin::setHigh() {
	PORT_HIGH;
}

// Function to set the pin output to LOW
// Inputs: none
// Outputs: none
void Pin::setLow() {
	PORT_LOW;
}

// Function to set the pin mode to output and the pin output to HIGH
// Inputs: none
// Outputs: none
void Pin::setOutputHigh() {
	DDR_HIGH;
	PORT_HIGH;
}

// Function to set the pin mode to output and the pin output to LOW
// Inputs: none
// Outputs: none
void Pin::setOutputLow() {
	DDR_HIGH;
	PORT_LOW;
}

// #################### Toggle ####################

// Function to toggle the pin mode (OUTPUT -> INPUT, INPUT -> OUTPUT)
// Inputs: none
// Outputs: none
void Pin::toggleMode() {
	if DDR_ON {
		DDR_LOW;
	} else {
		DDR_HIGH;
	}
}

// Function to toggle the pin mode (HIGH -> LOW, LOW -> HIGH)
// Inputs: none
// Outputs: none
void Pin::toggleState() {
	if PORT_ON {
		PORT_LOW;
	} else {
		PORT_HIGH;
	}
}