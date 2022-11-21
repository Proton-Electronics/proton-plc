// Arduino master sketch

#include <Wire.h>

#define i2c_addr 0x08

byte i2c_rcv;     // data received from I2C bus
byte i2c_adr_reg; // address register

void setup()
{
  Wire.begin(i2c_addr);        // join I2C bus as Slave with address 0x08
  Wire.onReceive(dataReceive); // register an event handler for received data
  Wire.onRequest(dataRequest); // register an event handler for data requests
}

void loop()
{
}

// received data handler function
void dataReceive(int howMany)
{
  while (Wire.available()) // read all bytes received
  {
    i2c_adr_reg = Wire.read();
  }
}

// requests data handler function
void dataRequest()
{
  if (i2c_adr_reg >= 0 && i2c_adr_reg <= 21)
  {
    Wire.write(digitalRead(i2c_adr_reg)); // read pin 0..21
  }
  else if (i2c_adr_reg >= 36 && i2c_adr_reg <= 53)
  {
    i2c_adr_reg -= 36;
    digitalWrite(i2c_adr_reg, !digitalRead(i2c_adr_reg)); // toggle pin 0..21
    Wire.write(0);
  }
  else
  {
    Wire.write(0);
  }
}