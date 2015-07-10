/**
	@file leonardo.h
	@author Alec Fenichel
	@brief Arduino Leonardo pin mappings
 */


#ifndef Leonardo_H
#define Leonardo_H

#define ANALOGOFFSET 14  ///< Index analog pins begin with in array

/**
	Pin mappings for the Arduino board
 */
struct pinMapping pinMappings[] = {
// Digital
{REGD,1<<2},
{REGD,1<<3},
{REGD,1<<1},
{REGD,1<<0},
{REGD,1<<4},
{REGC,1<<6},
{REGD,1<<7},
{REGE,1<<6},
{REGB,1<<4},
{REGB,1<<5},
{REGB,1<<6},
{REGB,1<<7},
{REGD,1<<6},
{REGC,1<<7},
// Analog
{REGF,1<<7},
{REGF,1<<6},
{REGF,1<<5},
{REGF,1<<4},
{REGF,1<<1},
{REGF,1<<0}
};

#endif
