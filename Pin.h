/*
  Pin.h - Library for pins.
  Author: Alec Fenichel
*/


#ifndef Pin_H
#define Pin_H

#include "Arduino.h"

class Pin {
	public:
		// #################### Constructors ####################
		Pin(uint8_t number);
		Pin(uint8_t number, bool analog);
		
		// #################### Getters ####################
		uint8_t getNumber();
		uint8_t getOffset();
		volatile uint8_t* getPIN();
		volatile uint8_t* getPORT();
		volatile uint8_t* getDDR();
		uint8_t getMode();
		uint8_t getState();
		uint8_t getValue();
		
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
		// Constructor
		void init(uint8_t number);
		// Variables
		uint8_t _number;
		uint8_t _offset;
		volatile uint8_t* _PIN;
		volatile uint8_t* _PORT;
		volatile uint8_t* _DDR;
};

#endif
