/*
  uno.h - Pin mappings for Arduino Uno.
  Author: Alec Fenichel
*/


#ifndef Uno_H
#define Uno_H

#define ANALOGOFFSET 0

struct pinMapping pinMappings[] = {
// Digital
{&PINA,&PORTA,&DDRA,1<<0},
// Analog
{&PINA,&PORTA,&DDRA,1<<0}
};

#endif