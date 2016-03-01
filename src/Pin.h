/**
	@file Pin.h
	@author Alec Fenichel
	@brief Arduino Pin library
	@details Arduino library for fast access to Arduino I/O pins using port manipulation
 */

#pragma once

#include "Arduino.h"

// ################################# Defines #################################

#define DDR_HIGH  (*_DDR  |=  _offset)  ///< Set the DDR register to HIGH for the pin
#define DDR_LOW   (*_DDR  &= ~_offset)  ///< Set the DDR register to LOW  for the pin

#define PORT_HIGH (*_PORT |=  _offset)  ///< Set the PORT register to HIGH for the pin
#define PORT_LOW  (*_PORT &= ~_offset)  ///< Set the PORT register to LOW  for the pin

#define DDR_ON    (*_DDR  &   _offset)  ///< Get the DDR  register for the pin (HIGH, LOW)
#define PORT_ON   (*_PORT &   _offset)  ///< Get the PORT register for the pin (HIGH, LOW)
#define PIN_ON    (*_PIN  &   _offset)  ///< Get the PIN  register for the pin (HIGH, LOW)

#define REGA &PINA, &PORTA, &DDRA  			///< The PIN, PORT, and DDR addresses of the A registers
#define REGB &PINB, &PORTB, &DDRB  			///< The PIN, PORT, and DDR addresses of the B registers
#define REGC &PINC, &PORTC, &DDRC  			///< The PIN, PORT, and DDR addresses of the C registers
#define REGD &PIND, &PORTD, &DDRD  			///< The PIN, PORT, and DDR addresses of the D registers
#define REGE &PINE, &PORTE, &DDRE  			///< The PIN, PORT, and DDR addresses of the E registers
#define REGF &PINF, &PORTF, &DDRF  			///< The PIN, PORT, and DDR addresses of the F registers
#define REGG &PING, &PORTG, &DDRG  			///< The PIN, PORT, and DDR addresses of the G registers
#define REGH &PINH, &PORTH, &DDRH  			///< The PIN, PORT, and DDR addresses of the H registers
#define REGI &PINI, &PORTI, &DDRI 			///< The PIN, PORT, and DDR addresses of the I registers
#define REGJ &PINJ, &PORTJ, &DDRJ  			///< The PIN, PORT, and DDR addresses of the J registers
#define REGK &PINK, &PORTK, &DDRK 			///< The PIN, PORT, and DDR addresses of the K registers
#define REGL &PINL, &PORTL, &DDRL 			///< The PIN, PORT, and DDR addresses of the L registers


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
		volatile
		uint8_t * getPIN(),
						* getPORT(),
						* getDDR();
		uint8_t 	getMode(),
							getState(),
							getValue(),
							getNumber(),
							getOffset();
		float 		getDuty();

		// #################### Setters ####################

		  // Generic
		bool set(uint8_t mode, uint8_t state),
				 setMode(uint8_t),
				 setState(uint8_t);
		void setDuty(float),  					// 0 ⇢ 1 (% of PWMRANGE)
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
		// Constructor
		void init(uint8_t number);
		// Variables
		float 		_duty = -1.0;
		uint8_t   _number,
							_offset;
		volatile
		uint8_t * _PIN,
				    * _PORT,
						* _DDR;
};
