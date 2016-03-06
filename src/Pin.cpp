/**
	@file Pin.cpp
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast access to Arduino I/O pins using port manipulation
 */

#include <Arduino.h>
#include "Pin.h"

// ################################# Constructor #################################

/**
	Basic constructor
	@param number pin number written on board if digital, then the first analog pin is at the index after the last digital pin
	@param analog true if pin is analog, false if pin is digital, defaults to false
 */
Pin::Pin(uint8_t number, bool analog) {
	analog ? init(analogInputToDigitalPin(number)) : init(number);
}

/**
	Construct a pin, not called by user, use wrapper constructors above
	@param number pin number written on board if digital, then the first analog pin is at the index after the last digital pin
 */
void Pin::init(uint8_t number) {
	_number = number;
	_offset = digitalPinToBitMask(_number);
	 _timer = digitalPinToTimer(_number);
	   _PIN = portInputRegister(digitalPinToPort(_number));
	  _PORT = portOutputRegister(digitalPinToPort(_number));
	   _DDR = portModeRegister(digitalPinToPort(_number));
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
  return DDR_ON ? OUTPUT : INPUT;
}

/**
	Get the state of the pin from the PORT register
	@return state of the pin (HIGH, LOW)
 */
uint8_t Pin::getState() {
	return PORT_ON ? HIGH : LOW;
}

/**
	Get the value of the pin from the PIN register

	@return value of the pin (HIGH, LOW)
 */
uint8_t Pin::getValue() {
	return PIN_ON ? HIGH : LOW;
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
  return mode == INPUT ? DDR_LOW : mode == OUTPUT ? DDR_HIGH : false;
}

/**
	Set the pin state
	@param state the state of the pin (HIGH, LOW)
	@return true if pin successfully updated, false otherwise
 */
bool Pin::setState(uint8_t state) {
  return state == LOW ? PORT_LOW : state == HIGH ? PORT_HIGH : false;
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
  DDR_ON ? DDR_LOW : DDR_HIGH;
}

/**
	Toggle the pin state (HIGH -> LOW, LOW -> HIGH)
 */
void Pin::toggleState() {
  PORT_ON ? PORT_LOW : PORT_HIGH;
}
