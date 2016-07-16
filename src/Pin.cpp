/**
	@file Pin.cpp
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast and simultaneous operations to Arduino I/O pins using port manipulation
 */


#include "Pin.h"


// ################################# Constructors #################################

/**
	Arduino supported board constructor

	@param number pin number written on board
 */
Pin::Pin(uint8_t number) {
	_number = number;
	_offset = digitalPinToBitMask(_number);
	_timer = digitalPinToTimer(_number);
	_PIN = portInputRegister(digitalPinToPort(_number));
	_PORT = portOutputRegister(digitalPinToPort(_number));
	_DDR = portModeRegister(digitalPinToPort(_number));
}

/**
	Custom board constructor

	getAnalogValue() and setDutyCycle(int value) not supported

	@param number pin number written on board
	@param offset bit mask used to access pin in registers
	@param timer timer for pin
	@param PIN input register for pin
	@param PORT data register for pin
	@param DDR data direction register for pin
 */
Pin::Pin(uint8_t number, uint8_t offset, uint8_t timer, volatile uint8_t* PIN, volatile uint8_t* PORT, volatile uint8_t* DDR) {
	_number = number;
	_offset = offset;
	_timer = timer;
	_PIN = PIN;
	_PORT = PORT;
	_DDR = DDR;
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
	Get the pin timer

	@return pin timer
 */
uint8_t Pin::getTimer() {
	return _timer;
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

/**
	Get the analog value of the pin

	@return analog value of the pin (0-1023)
 */
uint16_t Pin::getAnalogValue() {
	return analogRead(_number);
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

/**
	Set the PWM duty cycle

	@param value the duty cycle (0-255)
 */
void Pin::setDutyCycle(int value) {
	analogWrite(_number,value);
}

// #################### Toggle ####################

/**
	Toggle the pin mode (OUTPUT -> INPUT, INPUT -> OUTPUT)
 */
void Pin::toggleMode() {
	DDR_TOGGLE;
}

/**
	Toggle the pin state (HIGH -> LOW, LOW -> HIGH)
 */
void Pin::toggleState() {
	PORT_TOGGLE;
}
