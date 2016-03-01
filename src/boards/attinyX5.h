/**
	@file attinyX5.h
	@author Alexc Gray
	@brief attinyX5 pin mappings
 */

#pragma once

#define ANALOGOFFSET 3  // Where, in this struct, is the index of the first analog pin?

/**
	Pin mappings for the attinyX5 MCU/IC
	@note All the pins on the tiny 25/45/85 are within Register B!
 */

struct pinMapping pinMappings[] =
{
	{REGB,1<<0}, 	// Digital
	{REGB,1<<1},

	{REGB,1<<2}, 	// Analog
	{REGB,1<<3},
	{REGB,1<<4},
};

