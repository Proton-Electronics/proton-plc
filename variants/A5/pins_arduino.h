/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

// API compatibility

#ifndef _PINS_ARDUINO_PLC_A5_
#define _PINS_ARDUINO_PLC_A5_

#include <avr/pgmspace.h>

#define _ON		HIGH
#define _OFF	LOW

#define PIN_WIRE_SDA 18		    	/* A4 PC4 18 */
#define PIN_WIRE_SCL 19   		  /* A5 PC5 19 */

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/* TOP */
static const uint8_t D1 = 6;		/* D6 PD6 */
static const uint8_t D2 = 7;		/* D7 PD7 */
static const uint8_t D3 = 8;		/* D8 PB0 */
static const uint8_t D4 = 9;		/* D9 PB1 */
static const uint8_t D5 = 12;		/* D12 PB4 */
static const uint8_t D6 = 13;		/* D13 PB5 */

static const uint8_t A1 = 21;	  /* A7 21 */
static const uint8_t A2 = 20;	  /* A6 20 */
static const uint8_t A3 = 15;	  /* A1 15 */
static const uint8_t A4 = 14;	  /* A0 14 */

/* BUTTOM */
static const uint8_t AO1 = 10;	/* D10 */
static const uint8_t AO2 = 11;	/* D11 */

static const uint8_t REL1 = 16; /* A2 16*/
static const uint8_t REL2 = 5;  /* D5 */
static const uint8_t REL3 = 4;  /* D4 */
static const uint8_t REL4 = 3;  /* D3 */
static const uint8_t REL5 = 2;  /* D2 */

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD, /* PD0  0 */
	PD, /* PD1  1 */
	PD, /* PD2  2 */
	PD, /* PD3  3 */
	PD, /* PD4  4 */
	PD, /* PD5  5 */
	PD, /* PD6  6 */
	PD, /* PD7  7 */
	PB, /* PB0  8 */
	PB, /* PB1  9 */
	PB, /* PB2  10 */
	PB, /* PB3  11 */
	PB, /* PB4  12 */
	PB, /* PB5  13 */
	PC, /* PC0  14 Analog A0 */
	PC, /* PC1  15 Analog A1 */
	PC, /* PC2  16 Analog A2 */
	PC, /* PC3  17 Analog A3 */
	PC, /* PC4  18 Analog A4 */
	PC, /* PC5  19 Analog A5 */
	PC, /* PC6  20 Analog A6 */
	PC, /* PC7  21 Analog A7 */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), /* 0, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 8, port B */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(0), /* 14, port C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, /* 0 - port D */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER2B,
	NOT_ON_TIMER,
	TIMER0B,
	TIMER0A,
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 8 - port B */
	TIMER1A,
	TIMER1B,
	TIMER2A,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 14 - port C */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#endif

#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif