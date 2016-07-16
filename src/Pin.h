/**
	@file Pin.h
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast and simultaneous operations to Arduino I/O pins using port manipulation
 */


#include "Arduino.h"


#pragma once


// ################################# Defines #################################

#define DDR_HIGH (*_DDR |= _offset)  ///< Set the DDR register to HIGH for the pin
#define DDR_TOGGLE (*_DDR ^= _offset)  ///< Set the DDR register to the inverse for the pin
#define DDR_LOW (*_DDR &= ~_offset)  ///< Set the DDR register to LOW for the pin

#define PORT_HIGH (*_PORT |= _offset)  ///< Set the PORT register to HIGH for the pin
#define PORT_TOGGLE (*_PORT ^= _offset)  ///< Set the PORT register to the inverse for the pin
#define PORT_LOW (*_PORT &= ~_offset)  ///< Set the PORT register to LOW for the pin

#define DDR_ON (*_DDR & _offset)  ///< Get the DDR register for the pin (HIGH, LOW) with other pins forced to 0
#define DDR_OFF (*_DDR | ~ _offset)  ///< Get the DDR register for the pin (HIGH, LOW) with other pins forced to 1

#define PORT_ON (*_PORT & _offset)  ///< Get the PORT register for the pin (HIGH, LOW) with other pins forced to 0
#define PORT_OFF (*_PORT | ~ _offset)  ///< Get the PORT register for the pin (HIGH, LOW) with other pins forced to 1

#define PIN_ON (*_PIN & _offset)  ///< Get the PIN register for the pin (HIGH, LOW) with other pins forced to 0
#define PIN_OFF (*_PIN | ~ _offset)  ///< Get the PIN register for the pin (HIGH, LOW) with other pins forced to 1


/**
	Class for fast access to Arduino I/O pins using port manipulation

	@author Alec Fenichel
 */
class Pin {
	public:
		// #################### Constructors ####################
		Pin(uint8_t number);
		Pin(uint8_t number, uint8_t offset, uint8_t timer, volatile uint8_t* PIN, volatile uint8_t* PORT, volatile uint8_t* DDR);

		// #################### Getters ####################
		uint8_t getNumber();
		uint8_t getOffset();
		uint8_t getTimer();
		volatile uint8_t* getPIN();
		volatile uint8_t* getPORT();
		volatile uint8_t* getDDR();
		uint8_t getMode();
		uint8_t getState();
		uint8_t getValue();
		uint16_t getAnalogValue();

		// #################### Setters ####################
		// Generic
		bool set(uint8_t mode, uint8_t state);
		bool setMode(uint8_t mode);
		bool setState(uint8_t state);
		// Input
		void setInput();
		void setPullupOn();
		void setPullupOff();
		void setInputPullupOn();
		void setInputPullupOff();
		// Output
		void setOutput();
		void setHigh();
		void setLow();
		void setOutputHigh();
		void setOutputLow();
		void setDutyCycle(int value);
		// Toggle
		void toggleMode();
		void toggleState();

	private:
		// Variables
		uint8_t _number;
		uint8_t _offset;
		uint8_t _timer;
		volatile uint8_t* _PIN;
		volatile uint8_t* _PORT;
		volatile uint8_t* _DDR;
};
