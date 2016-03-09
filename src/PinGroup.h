/**
	@file PinGroup.h
	@author Alec Fenichel
	@brief Arduino Pin library group functions
	@details Arduino library for fast access to Arduino I/O pins using port manipulation with functions for simultaneous operations on multiple Pins
 */


#include "Pin.h"


#pragma once


// ################################# Defines #################################

#define DDRS_HIGH (*pins[0].getDDR() |= offset)  ///< Set the DDR register to HIGH for an array of pins
#define DDRS_LOW (*pins[0].getDDR() &= ~offset)  ///< Set the DDR register to LOW for an array of pins

#define PORTS_HIGH (*pins[0].getPORT() |= offset)  ///< Set the PORT register to HIGH for an array of pins
#define PORTS_LOW (*pins[0].getPORT() &= ~offset)  ///< Set the PORT register to LOW for an array of pins

#define PINS_ON (*pins[0].getPIN() & offset)  ///< Get the PIN register for an array of pins
#define PINS_OFF (*pins[0].getPIN() | ~offset)  ///< Get the inverse PIN register for an array of pins

#define MERGE_OFFSET(PINS,LEN) { \
	offset = (PINS)[0].getOffset(); \
	for (int i = 1; i < (LEN); i++) { \
		offset |= (PINS)[i].getOffset(); \
	} \
}  ///< Merge the offsets of multiple pins in an array


// ################################# Setters #################################

// #################### Input ####################

/**
	Set the pin mode of multiple pins to input

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setInput(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	DDRS_LOW;
}

/**
	Set the pin pullup resistor of multiple pins to on

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setPullupOn(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	PORTS_HIGH;
}

/**
	Set the pin pullup resistor of multiple pins to off

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setPullupOff(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	PORTS_LOW;
}

/**
	Set the pin mode of multiple pins to input and the pin pullup resistor to on

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setInputPullupOn(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	DDRS_LOW;
	PORTS_HIGH;
}

/**
	Set the pin mode of multiple pins to input and the pin pullup resistor to off

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setInputPullupOff(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	DDRS_LOW;
	PORTS_LOW;
}

// #################### Output ####################

/**
	Set the pin mode of multiple pins to output

	@param pins an array of pins that use the same registers
 */
template<size_t N>
 void setOutput(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	DDRS_HIGH;
 }

/**
	Set the pin output of multiple pins to HIGH

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setHigh(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	PORTS_HIGH;
}

/**
	Set the pin output of multiple pins to LOW

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setLow(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	PORTS_LOW;
}

/**
	Set the pin mode of multiple pins to output and the pin output to HIGH

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setOutputHigh(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	DDRS_HIGH;
	PORTS_HIGH;
}

/**
	Set the pin mode of multiple pins to output and the pin output to LOW

	@param pins an array of pins that use the same registers
 */
template<size_t N>
void setOutputLow(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	DDRS_HIGH;
	PORTS_LOW;
}


// ################################# Getters #################################

/**
	Get the value of multiple pins from the PIN register

	@param pins an array of pins that use the same registers

	@return HIGH if all of the pins in the array have a value of HIGH, LOW if all of the pins in the array have a value of LOW, -1 otherwise
 */
template<size_t N>
uint8_t getValue(Pin (&pins)[N]) {
	uint8_t offset;
	MERGE_OFFSET(pins,N);
	if (PINS_ON == offset) {
		return HIGH;
	} else if (PINS_OFF == ~offset) {
		return LOW;
	} else {
		return -1;
	}
}


// ################################# Checkers #################################

/**
	Check the array to ensure all pins use the same registers

	@param pins an array of pins

	@return true if the pins in the array all use the same registers, false otherwise
 */
template<size_t N>
bool checkPinGroup(Pin (&pins)[N]) {
	volatile uint8_t* ddr = pins[0].getDDR();
	for (int i = 0; i < N; i++) {
		if (pins[0].getDDR() != pins[i].getDDR()) {
			return false;
		}
	}

	return true;
}
