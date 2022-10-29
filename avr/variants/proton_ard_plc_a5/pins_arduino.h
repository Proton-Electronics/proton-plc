/*
  pins_arduino.h - Pin definition functions for Proton Arduino PLC A5
  Part of Arduino - http://www.arduino.cc/ and Proton Electronics

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define PIN_WIRE_SDA PIN_A4			/* A4 */
#define PIN_WIRE_SCL PIN_A5			/* A5 */

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/* TOP */
static const uint8_t D1 = 6;		/* D6 */
static const uint8_t D2 = 7;		/* D7 */
static const uint8_t D3 = 8;		/* D8 */
static const uint8_t D4 = 9;		/* D9 */
static const uint8_t D5 = 12;		/* D12 */
static const uint8_t D6 = 13;		/* D13 */

static const uint8_t A1 = PIN_A7;	/* A7 */
static const uint8_t A2 = PIN_A6;	/* A6 */
static const uint8_t A3 = PIN_A1;	/* A1 */
static const uint8_t A4 = PIN_A0;	/* A0 */

/* BUTTOM */
static const uint8_t AO1 = 10;		/* D10 */
static const uint8_t AO2 = 11;		/* D11 */

static const uint8_t REL1 = PIN_A2; /* A2 */
static const uint8_t REL2 = 5;		/* D5 */
static const uint8_t REL3 = 4;		/* D4 */
static const uint8_t REL4 = 3;		/* D3 */
static const uint8_t REL5 = 2;		/* D2 */

#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
