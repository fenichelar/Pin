/*
  uno.h - Pin mappings for Arduino Uno.
  Author: Alec Fenichel
*/


#ifndef Uno_H
#define Uno_H

#define ANALOGOFFSET 14

struct pinMapping pinMappings[] = {
// Digital
{REGD,1<<0},
{REGD,1<<1},
{REGD,1<<2},
{REGD,1<<3},
{REGD,1<<4},
{REGD,1<<5},
{REGD,1<<6},
{REGD,1<<7},
{REGB,1<<0},
{REGB,1<<1},
{REGB,1<<2},
{REGB,1<<3},
{REGB,1<<4},
{REGB,1<<5},
// Analog
{REGC,1<<0},
{REGC,1<<1},
{REGC,1<<2},
{REGC,1<<3},
{REGC,1<<4},
{REGC,1<<5}
};

#endif
