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

Pin::Pin(uint8_t number) {
	init(number);
}

Pin::Pin(uint8_t number, bool analog) {
	if (analog) {
		init(number + ANALOGOFFSET);
	} else {
		init(number);
	}
}

void Pin::init(uint8_t number) {
	_number = number;
	_offset = pinMappings[_number].offset;
	_PIN = pinMappings[_number].pin;
	_PORT = pinMappings[_number].port;
	_DDR = pinMappings[_number].ddr;
}


// ################################# Getters #################################

uint8_t Pin::getNumber() {
	return _number;
}

uint8_t Pin::getOffset() {
	return _offset;
}

volatile uint8_t* Pin::getPIN() {
	return _PIN;
}

volatile uint8_t* Pin::getPORT() {
	return _PORT;
}

volatile uint8_t* Pin::getDDR() {
	return _DDR;
}

uint8_t Pin::getMode() {
	if DDR_ON {
		return OUTPUT;
	} else {
		return INPUT;
	}
}

uint8_t Pin::getState() {
	if PORT_ON {
		return HIGH;
	} else {
		return LOW;
	}
}

uint8_t Pin::getValue() {
	if PIN_ON {
		return HIGH;
	} else {
		return LOW;
	}
}


// ################################# Setters #################################

// #################### Generic ####################

bool Pin::set(uint8_t mode, uint8_t state) {
	return (setMode(mode) && setState(state));
}

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

void Pin::setInput() {
	DDR_LOW;
}

void Pin::setPullupOn() {
	PORT_HIGH;
}

void Pin::setPullupOff() {
	PORT_LOW;
}

void Pin::setInputPullupOn() {
	DDR_LOW;
	PORT_HIGH;
}

void Pin::setInputPullupOff() {
	DDR_LOW;
	PORT_LOW;
}

// #################### Output ####################

void Pin::setOutput() {
	DDR_HIGH;
}

void Pin::setHigh() {
	PORT_HIGH;
}

void Pin::setLow() {
	PORT_LOW;
}

void Pin::setOutputHigh() {
	DDR_HIGH;
	PORT_HIGH;
}

void Pin::setOutputLow() {
	DDR_HIGH;
	PORT_LOW;
}

// #################### Toggle ####################

void Pin::toggleMode() {
	if DDR_ON {
		DDR_LOW;
	} else {
		DDR_HIGH;
	}
}

void Pin::toggleState() {
	if PORT_ON {
		PORT_LOW;
	} else {
		PORT_HIGH;
	}
}