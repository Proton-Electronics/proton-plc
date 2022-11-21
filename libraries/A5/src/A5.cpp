/*
  TwoWire.cpp - TWI/I2C library for Wiring & Arduino
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
  Modified 2017 by Chuck Todd (ctodd@cableone.net) to correct Unconfigured Slave Mode reboot
  Modified 2020 by Greyson Christoforo (grey@christoforo.net) to implement timeouts
*/

#include "A5.h"
//#include "Arduino.h”

Proton_Arduino_PLC::Proton_Arduino_PLC()
{

  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  pinMode(AO1, OUTPUT);
  pinMode(AO2, OUTPUT);

  pinMode(REL1, OUTPUT);
  pinMode(REL2, OUTPUT);
  pinMode(REL3, OUTPUT);
  pinMode(REL4, OUTPUT);
  pinMode(REL5, OUTPUT);

  Serial.begin(115200);
}

int Proton_Arduino_PLC::d1(void)
{
  return digitalRead(D1);
}
int Proton_Arduino_PLC::d2(void)
{
  return digitalRead(D2);
}
int Proton_Arduino_PLC::d3(void)
{
  return digitalRead(D3);
}
int Proton_Arduino_PLC::d4(void)
{
  return digitalRead(D4);
}
int Proton_Arduino_PLC::d5(void)
{
  return digitalRead(D5);
}
int Proton_Arduino_PLC::d6(void)
{
  return digitalRead(D6);
}
int Proton_Arduino_PLC::a1(void)
{
  return analogRead(A1);
}
int Proton_Arduino_PLC::a2(void)
{
  return analogRead(A2);
}
int Proton_Arduino_PLC::a3(void)
{
  return analogRead(A3);
}
int Proton_Arduino_PLC::a4(void)
{
  return analogRead(A4);
}

void Proton_Arduino_PLC::rel1(int ON_OFF)
{
  digitalWrite(REL1, ON_OFF);
}
void Proton_Arduino_PLC::rel2(int ON_OFF)
{
  digitalWrite(REL2, ON_OFF);
}
void Proton_Arduino_PLC::rel3(int ON_OFF)
{
  digitalWrite(REL3, ON_OFF);
}
void Proton_Arduino_PLC::rel4(int ON_OFF)
{
  digitalWrite(REL4, ON_OFF);
}
void Proton_Arduino_PLC::rel5(int ON_OFF)
{
  digitalWrite(REL5, ON_OFF);
}

int Proton_Arduino_PLC::read(int D1_D6_A1_A4_AO1_AO2)
{
  if (D1_D6_A1_A4_AO1_AO2 == D1 || D1_D6_A1_A4_AO1_AO2 == D2 || D1_D6_A1_A4_AO1_AO2 == D3 || D1_D6_A1_A4_AO1_AO2 == D4 || D1_D6_A1_A4_AO1_AO2 == D5 || D1_D6_A1_A4_AO1_AO2 == D6)
    return digitalRead(D1_D6_A1_A4_AO1_AO2);

  else if (D1_D6_A1_A4_AO1_AO2 == A1 || D1_D6_A1_A4_AO1_AO2 == A2 || D1_D6_A1_A4_AO1_AO2 == A3 || D1_D6_A1_A4_AO1_AO2 == A4)
    return analogRead(D1_D6_A1_A4_AO1_AO2);

  else if (D1_D6_A1_A4_AO1_AO2 == AO1)
    return _AO1;

  else if (D1_D6_A1_A4_AO1_AO2 == AO2)
    return _AO2;

  else
    return false;
}
void Proton_Arduino_PLC::write(int AO1_AO2, int Value)
{
  if (AO1_AO2 == AO1 || AO1_AO2 == AO2)
    analogWrite(AO1_AO2, Value);

  if (AO1_AO2 == AO1)
    _AO1 = Value;
  else if (AO1_AO2 == AO2)
    _AO2 = Value;
}

void Proton_Arduino_PLC::on(int REL1_REL5)
{
  digitalWrite(REL1_REL5, HIGH);
}
void Proton_Arduino_PLC::off(int REL1_REL5)
{
  digitalWrite(REL1_REL5, LOW);
}