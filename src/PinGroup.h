/**
	@file PinGroup.h
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast and simultaneous operations to Arduino I/O pins using port manipulation
 */


#include "Pin.h"

#pragma once


/**
	Class for fast simultaneous operations on Arduino I/O pins using port manipulation

	@author Alec Fenichel
 */
class PinGroup {
	public:
		// #################### Constructors ####################
		template<size_t N>
		PinGroup(Pin (&pins)[N]) {
			_offset = pins[0].getOffset();
			_PIN = pins[0].getPIN();
			_PORT = pins[0].getPORT();
			_DDR = pins[0].getDDR();
			_numbers[0] = pins[0].getNumber();
			_valid = true;

			for (int i = 1; i < N; i++) {
				if (_DDR != pins[i].getDDR()) {
					_valid = false;
				}
				_offset |= pins[i].getOffset();
				_numbers[i] = pins[i].getNumber();
			}
		}

		// #################### Getters ####################
		uint8_t* getNumbers();
		uint8_t getOffset();
		volatile uint8_t* getPIN();
		volatile uint8_t* getPORT();
		volatile uint8_t* getDDR();
		uint8_t getMode();
		uint8_t getState();
		uint8_t getValue();
		bool isValid();

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
		// Toggle
		void toggleMode();
		void toggleState();

	private:
		// Variables
		uint8_t _numbers[8];
		uint8_t _offset;
		bool _valid;
		volatile uint8_t* _PIN;
		volatile uint8_t* _PORT;
		volatile uint8_t* _DDR;
};
