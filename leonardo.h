/*
  leonardo.h - Pin mappings for Arduino Leonardo.
  Author: Alec Fenichel
*/


#ifndef Leonardo_H
#define Leonardo_H

#define ANALOGOFFSET 0

struct pinMapping pinMappings[] = {
// Digital
{&PINA,&PORTA,&DDRA,1<<0},
// Analog
{&PINA,&PORTA,&DDRA,1<<0}
};

#endif