/**
	@file Pin.h
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast access to Arduino I/O pins using port manipulation
 */


#include "Arduino.h"


#ifndef Pin_H
#define Pin_H


// ################################# Defines #################################

#define DDR_HIGH (*_DDR |= _offset)  ///< Set the DDR register to HIGH for the pin
#define DDR_LOW (*_DDR &= ~_offset)  ///< Set the DDR register to LOW for the pin

#define PORT_HIGH (*_PORT |= _offset)  ///< Set the PORT register to HIGH for the pin
#define PORT_LOW (*_PORT &= ~_offset)  ///< Set the PORT register to LOW for the pin

#define DDR_ON (*_DDR & _offset)  ///< Get the DDR register for the pin (HIGH, LOW)
#define PORT_ON (*_PORT & _offset)  ///< Get the PORT register for the pin (HIGH, LOW)
#define PIN_ON (*_PIN & _offset)  ///< Get the PIN register for the pin (HIGH, LOW)

#define REGA &PINA,&PORTA,&DDRA  ///< The PIN, PORT, and DDR addresses of the A registers
#define REGB &PINB,&PORTB,&DDRB  ///< The PIN, PORT, and DDR addresses of the B registers
#define REGC &PINC,&PORTC,&DDRC  ///< The PIN, PORT, and DDR addresses of the C registers
#define REGD &PIND,&PORTD,&DDRD  ///< The PIN, PORT, and DDR addresses of the D registers
#define REGE &PINE,&PORTE,&DDRE  ///< The PIN, PORT, and DDR addresses of the E registers
#define REGF &PINF,&PORTF,&DDRF  ///< The PIN, PORT, and DDR addresses of the F registers
#define REGG &PING,&PORTG,&DDRG  ///< The PIN, PORT, and DDR addresses of the G registers
#define REGH &PINH,&PORTH,&DDRH  ///< The PIN, PORT, and DDR addresses of the H registers
#define REGI &PINI,&PORTI,&DDRI  ///< The PIN, PORT, and DDR addresses of the I registers
#define REGJ &PINJ,&PORTJ,&DDRJ  ///< The PIN, PORT, and DDR addresses of the J registers
#define REGK &PINK,&PORTK,&DDRK  ///< The PIN, PORT, and DDR addresses of the K registers
#define REGL &PINL,&PORTL,&DDRL  ///< The PIN, PORT, and DDR addresses of the L registers


/**
	Class for fast access to Arduino I/O pins using port manipulation

	@author Alec Fenichel
 */
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
