/**
	@file PinGroup.cpp
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast and simultaneous operations to Arduino I/O pins using port manipulation
 */


#include "PinGroup.h"


// ################################# Getters #################################

/**
	Get the pin numbers

	@return array of pin numbers
 */
uint8_t* PinGroup::getNumbers() {
	return _numbers;
}

/**
	Get the pin offset

	@return pin offset
 */
uint8_t PinGroup::getOffset() {
	return _offset;
}

/**
	Get a pointer to the PIN register

	@return pointer to the PIN register
 */
volatile uint8_t* PinGroup::getPIN() {
	return _PIN;
}

/**
	Get a pointer to the PORT register

	@return pointer to the PORT register
 */
volatile uint8_t* PinGroup::getPORT() {
	return _PORT;
}

/**
	Get a pointer to the DDR register

	@return pointer to the DDR register
 */
volatile uint8_t* PinGroup::getDDR() {
	return _DDR;
}

/**
	Get the mode of the pin from the DDR register

	@return mode of the pin (OUTPUT, INPUT, -1)
 */
uint8_t PinGroup::getMode() {
	if (DDR_ON == _offset) {
		return HIGH;
	} else if (DDR_OFF == ~_offset) {
		return LOW;
	} else {
		return -1;
	}
}

/**
	Get the state of the pin from the PORT register

	@return state of the pin (HIGH, LOW, -1)
 */
uint8_t PinGroup::getState() {
	if (PORT_ON == _offset) {
		return HIGH;
	} else if (PORT_OFF == ~_offset) {
		return LOW;
	} else {
		return -1;
	}
}

/**
	Get the value of the pin from the PIN register

	@return value of the pin (HIGH, LOW, -1)
 */
uint8_t PinGroup::getValue() {
	if (PIN_ON == _offset) {
		return HIGH;
	} else if (PIN_OFF == ~_offset) {
		return LOW;
	} else {
		return -1;
	}
}

/**
	Check the group to ensure all pins use the same registers

	@return true if the pins in the group all use the same registers, false otherwise
 */
bool PinGroup::isValid() {
	return _valid;
}


// ################################# Setters #################################

// #################### Generic ####################

/**
	Set the pin mode and pin state

	@param mode the mode of the pin (OUTPUT, INPUT)
	@param state the state of the pin (HIGH, LOW)

	@return true if pin successfully updated, false otherwise
 */
bool PinGroup::set(uint8_t mode, uint8_t state) {
	return (setMode(mode) && setState(state));
}

/**
	Set the pin mode

	@param mode the mode of the pin (OUTPUT, INPUT)

	@return true if pin successfully updated, false otherwise
 */
bool PinGroup::setMode(uint8_t mode) {
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
bool PinGroup::setState(uint8_t state) {
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
void PinGroup::setInput() {
	DDR_LOW;
}

/**
	Set the pin pullup resistor to on
 */
void PinGroup::setPullupOn() {
	PORT_HIGH;
}

/**
	Set the pin pullup resistor to off
 */
void PinGroup::setPullupOff() {
	PORT_LOW;
}

/**
	Set the pin mode to input and the pin pullup resistor to on
 */
void PinGroup::setInputPullupOn() {
	DDR_LOW;
	PORT_HIGH;
}

/**
	Set the pin mode to input and the pin pullup resistor to off
 */
void PinGroup::setInputPullupOff() {
	DDR_LOW;
	PORT_LOW;
}

// #################### Output ####################

/**
	Set the pin mode to output
 */
void PinGroup::setOutput() {
	DDR_HIGH;
}

/**
	Set the pin output to HIGH
 */
void PinGroup::setHigh() {
	PORT_HIGH;
}

/**
	Set the pin output to LOW
 */
void PinGroup::setLow() {
	PORT_LOW;
}

/**
	Set the pin mode to output and the pin output to HIGH
 */
void PinGroup::setOutputHigh() {
	DDR_HIGH;
	PORT_HIGH;
}

/**
	Set the pin mode to output and the pin output to LOW
 */
void PinGroup::setOutputLow() {
	DDR_HIGH;
	PORT_LOW;
}

// #################### Toggle ####################

/**
	Toggle the pin mode (OUTPUT -> INPUT, INPUT -> OUTPUT)
 */
void PinGroup::toggleMode() {
	DDR_TOGGLE;
}

/**
	Toggle the pin state (HIGH -> LOW, LOW -> HIGH)
 */
void PinGroup::toggleState() {
	PORT_TOGGLE;
}
