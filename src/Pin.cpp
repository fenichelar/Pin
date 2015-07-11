/**
	@file Pin.cpp
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast access to Arduino I/O pins using port manipulation
 */


#include "Pin.h"


/**
	Struct for storing register addresses and offset
 */
struct pinMapping {
	volatile uint8_t* pin;  ///< Address of the PIN register, used to read pin if the pin is set as an input
	volatile uint8_t* port;  ///< Address of the PORT register, used to set output if the pin is set as an output or set pull-up resistor if the pin is set as an input
	volatile uint8_t* ddr;  ///< Address of the DDR register, used to define data direction
	const uint8_t offset;  ///< Bit mask for specific pin inside register
};


// Arduino Mega
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	#include "boards/mega.h"  ///< Include the pin mappings for the Arduino Mega
#endif

// Arduino Uno
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
	#include "boards/uno.h"  ///< Include the pin mappings for the Arduino Uno
#endif

// Arduino Leonardo
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
	#include "boards/leonardo.h"  ///< Include the pin mappings for the Arduino Leonardo
#endif


// ################################# Constructors #################################

/**
	Basic constructor

	@param number pin number written on board if digital, then the first analog pin is at the index after the last digital pin
 */
Pin::Pin(uint8_t number) {
	init(number);
}

/**
	Easier constructor

	@param number pin number written on board
	@param analog true if pin is analog, false if pin is digital
 */
Pin::Pin(uint8_t number, bool analog) {
	if (analog) {
		init(number + ANALOGOFFSET);
	} else {
		init(number);
	}
}

/**
	Construct a pin, not called by user, use wrapper constructors above

	@param number pin number written on board if digital, then the first analog pin is at the index after the last digital pin
 */
void Pin::init(uint8_t number) {
	_number = number;
	_offset = pinMappings[_number].offset;
	_PIN = pinMappings[_number].pin;
	_PORT = pinMappings[_number].port;
	_DDR = pinMappings[_number].ddr;
}


// ################################# Getters #################################

/**
	Get the pin number

	@return pin number
 */
uint8_t Pin::getNumber() {
	return _number;
}

/**
	Get the pin offset

	@return pin offset
 */
uint8_t Pin::getOffset() {
	return _offset;
}

/**
	Get a pointer to the PIN register

	@return pointer to the PIN register
 */
volatile uint8_t* Pin::getPIN() {
	return _PIN;
}

/**
	Get a pointer to the PORT register

	@return pointer to the PORT register
 */
volatile uint8_t* Pin::getPORT() {
	return _PORT;
}

/**
	Get a pointer to the DDR register

	@return pointer to the DDR register
 */
volatile uint8_t* Pin::getDDR() {
	return _DDR;
}

/**
	Get the mode of the pin from the DDR register

	@return mode of the pin (OUTPUT, INPUT)
 */
uint8_t Pin::getMode() {
	if (DDR_ON) {
		return OUTPUT;
	} else {
		return INPUT;
	}
}

/**
	Get the state of the pin from the PORT register

	@return state of the pin (HIGH, LOW)
 */
uint8_t Pin::getState() {
	if (PORT_ON) {
		return HIGH;
	} else {
		return LOW;
	}
}

/**
	Get the value of the pin from the PIN register

	@return value of the pin (HIGH, LOW)
 */
uint8_t Pin::getValue() {
	if (PIN_ON) {
		return HIGH;
	} else {
		return LOW;
	}
}


// ################################# Setters #################################

// #################### Generic ####################

/**
	Set the pin mode and pin state

	@param mode the mode of the pin (OUTPUT, INPUT)
	@param state the state of the pin (HIGH, LOW)

	@return true if pin successfully updated, false otherwise
 */
bool Pin::set(uint8_t mode, uint8_t state) {
	return (setMode(mode) && setState(state));
}

/**
	Set the pin mode

	@param mode the mode of the pin (OUTPUT, INPUT)

	@return true if pin successfully updated, false otherwise
 */
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

/**
	Set the pin state

	@param state the state of the pin (HIGH, LOW)

	@return true if pin successfully updated, false otherwise
 */
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

/**
	Set the pin mode to input
 */
void Pin::setInput() {
	DDR_LOW;
}

/**
	Set the pin pullup resistor to on
 */
void Pin::setPullupOn() {
	PORT_HIGH;
}

/**
	Set the pin pullup resistor to off
 */
void Pin::setPullupOff() {
	PORT_LOW;
}

/**
	Set the pin mode to input and the pin pullup resistor to on
 */
void Pin::setInputPullupOn() {
	DDR_LOW;
	PORT_HIGH;
}

/**
	Set the pin mode to input and the pin pullup resistor to off
 */
void Pin::setInputPullupOff() {
	DDR_LOW;
	PORT_LOW;
}

// #################### Output ####################

/**
	Set the pin mode to output
 */
void Pin::setOutput() {
	DDR_HIGH;
}

/**
	Set the pin output to HIGH
 */
void Pin::setHigh() {
	PORT_HIGH;
}

/**
	Set the pin output to LOW
 */
void Pin::setLow() {
	PORT_LOW;
}

/**
	Set the pin mode to output and the pin output to HIGH
 */
void Pin::setOutputHigh() {
	DDR_HIGH;
	PORT_HIGH;
}

/**
	Set the pin mode to output and the pin output to LOW
 */
void Pin::setOutputLow() {
	DDR_HIGH;
	PORT_LOW;
}

// #################### Toggle ####################

/**
	Toggle the pin mode (OUTPUT -> INPUT, INPUT -> OUTPUT)
 */
void Pin::toggleMode() {
	if (DDR_ON) {
		DDR_LOW;
	} else {
		DDR_HIGH;
	}
}

/**
	Toggle the pin state (HIGH -> LOW, LOW -> HIGH)
 */
void Pin::toggleState() {
	if (PORT_ON) {
		PORT_LOW;
	} else {
		PORT_HIGH;
	}
}
