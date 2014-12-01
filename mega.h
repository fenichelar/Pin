/*
  mega.h - Pin mappings for Arduino Mega.
  Author: Alec Fenichel
*/


#ifndef Mega_H
#define Mega_H

#define ANALOGOFFSET 54

struct pinMapping pinMappings[] = {
// Digital
{REGE,1<<0},
{REGE,1<<1},
{REGE,1<<4},
{REGE,1<<5},
{REGG,1<<5},
{REGE,1<<3},
{REGH,1<<3},
{REGH,1<<4},
{REGH,1<<5},
{REGH,1<<6},
{REGB,1<<4},
{REGB,1<<5},
{REGB,1<<6},
{REGB,1<<7},
{REGJ,1<<1},
{REGJ,1<<0},
{REGH,1<<1},
{REGH,1<<0},
{REGD,1<<3},
{REGD,1<<2},
{REGD,1<<1},
{REGD,1<<0},
{REGA,1<<0},
{REGA,1<<1},
{REGA,1<<2},
{REGA,1<<3},
{REGA,1<<4},
{REGA,1<<5},
{REGA,1<<6},
{REGA,1<<7},
{REGC,1<<7},
{REGC,1<<6},
{REGC,1<<5},
{REGC,1<<4},
{REGC,1<<3},
{REGC,1<<2},
{REGC,1<<1},
{REGC,1<<0},
{REGD,1<<7},
{REGG,1<<2},
{REGG,1<<1},
{REGG,1<<0},
{REGL,1<<7},
{REGL,1<<6},
{REGL,1<<5},
{REGL,1<<4},
{REGL,1<<3},
{REGL,1<<2},
{REGL,1<<1},
{REGL,1<<0},
{REGB,1<<3},
{REGB,1<<2},
{REGB,1<<1},
{REGB,1<<0},
// Analog
{REGF,1<<0},
{REGF,1<<1},
{REGF,1<<2},
{REGF,1<<3},
{REGF,1<<4},
{REGF,1<<5},
{REGF,1<<6},
{REGF,1<<7},
{REGK,1<<0},
{REGK,1<<1},
{REGK,1<<2},
{REGK,1<<3},
{REGK,1<<4},
{REGK,1<<5},
{REGK,1<<6},
{REGK,1<<7}
};

#endif