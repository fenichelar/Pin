/**
	@file Pin.h
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast access to Arduino I/O pins using port manipulation
 */

#pragma once

class Pin {
	public:
		// #################### Constructor ####################
		Pin(uint8_t number, bool analog = false);

		// #################### Getters ####################
		volatile uint8_t
      * getPIN(),
      * getPORT(),
      * getDDR();
    uint8_t
      getNumber(),
      getOffset(),
      getTimer(),
      getMode(),
      getState(),
      getValue();

		// #################### Setters ####################
		// Generic
		bool      set(uint8_t mode, uint8_t state);
		bool  setMode(uint8_t);
		bool setState(uint8_t);

	  void
      // Input
      setInput(),
      setPullupOn(),
      setPullupOff(),
      setInputPullupOn(),
      setInputPullupOff(),
      // Output
      setOutput(),
      setHigh(),
      setLow(),
      setOutputHigh(),
      setOutputLow(),
      // Toggle
      toggleMode(),
      toggleState();

	private:

		void init(uint8_t number);  ///< Constructor helper/initializer

    // #################### VARIABLES ####################

		uint8_t
      _number,
      _offset,
      _timer;
    volatile uint8_t
      * _PIN,
      * _PORT,
      * _DDR;
};

// ################################# Definitions #################################

#define DDR_HIGH (*_DDR |=  _offset)    ///< Set the DDR register to HIGH for the pin
#define DDR_LOW  (*_DDR &= ~_offset)    ///< Set the DDR register to LOW for the pin

#define PORT_HIGH (*_PORT |=  _offset)  ///< Set the PORT register to HIGH for the pin
#define PORT_LOW  (*_PORT &= ~_offset)  ///< Set the PORT register to LOW for the pin

#define  DDR_ON (*_DDR  & _offset)      ///< Get the DDR register for the pin (HIGH, LOW)
#define PORT_ON (*_PORT & _offset)      ///< Get the PORT register for the pin (HIGH, LOW)
#define  PIN_ON (*_PIN  & _offset)      ///< Get the PIN register for the pin (HIGH, LOW)

