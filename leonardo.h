/*
  leonardo.h - Pin mappings for Arduino Leonardo.
  Author: Alec Fenichel
*/


#ifndef Leonardo_H
#define Leonardo_H

#define ANALOGOFFSET 14

struct pinMapping pinMappings[] = {
// Digital
{&PIND,&PORTD,&DDRD,1<<2},
{&PIND,&PORTD,&DDRD,1<<3},
{&PIND,&PORTD,&DDRD,1<<1},
{&PIND,&PORTD,&DDRD,1<<0},
{&PIND,&PORTD,&DDRD,1<<4},
{&PINC,&PORTC,&DDRC,1<<6},
{&PIND,&PORTD,&DDRD,1<<7},
{&PINE,&PORTE,&DDRE,1<<6},
{&PINB,&PORTB,&DDRB,1<<4},
{&PINB,&PORTB,&DDRB,1<<5},
{&PINB,&PORTB,&DDRB,1<<6},
{&PINB,&PORTB,&DDRB,1<<7},
{&PIND,&PORTD,&DDRD,1<<6},
{&PINC,&PORTC,&DDRC,1<<7},
// Analog
{&PINF,&PORTF,&DDRF,1<<7},
{&PINF,&PORTF,&DDRF,1<<6},
{&PINF,&PORTF,&DDRF,1<<5},
{&PINF,&PORTF,&DDRF,1<<4},
{&PINF,&PORTF,&DDRF,1<<1},
{&PINF,&PORTF,&DDRF,1<<0},
};

#endif