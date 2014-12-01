/*
  uno.h - Pin mappings for Arduino Uno.
  Author: Alec Fenichel
*/


#ifndef Uno_H
#define Uno_H

#define ANALOGOFFSET 14

struct pinMapping pinMappings[] = {
// Digital
{&PIND,&PORTD,&DDRD,1<<0},
{&PIND,&PORTD,&DDRD,1<<1},
{&PIND,&PORTD,&DDRD,1<<2},
{&PIND,&PORTD,&DDRD,1<<3},
{&PIND,&PORTD,&DDRD,1<<4},
{&PIND,&PORTD,&DDRD,1<<5},
{&PIND,&PORTD,&DDRD,1<<6},
{&PIND,&PORTD,&DDRD,1<<7},
{&PINB,&PORTB,&DDRB,1<<0},
{&PINB,&PORTB,&DDRB,1<<1},
{&PINB,&PORTB,&DDRB,1<<2},
{&PINB,&PORTB,&DDRB,1<<3},
{&PINB,&PORTB,&DDRB,1<<4},
{&PINB,&PORTB,&DDRB,1<<5},
// Analog
{&PINC,&PORTC,&DDRC,1<<0},
{&PINC,&PORTC,&DDRC,1<<1},
{&PINC,&PORTC,&DDRC,1<<2},
{&PINC,&PORTC,&DDRC,1<<3},
{&PINC,&PORTC,&DDRC,1<<4},
{&PINC,&PORTC,&DDRC,1<<5}
};

#endif