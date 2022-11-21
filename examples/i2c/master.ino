// Arduino master sketch

#include <Wire.h>

byte i2c_rcv; // data received from I2C bus

void setup()
{
  Wire.begin(); // join I2C bus as Master
}

void loop()
{
  for (byte i = 0; i < 25; i++)
  {
    Serial.print(i);
    Serial.print(" > ");
    Serial.println(dataSend(slaveAddr, i));
  }

  delay(3000);
}

// send data function to the slave
int dataSend(int slaveAddr, int Data)
{
  Wire.beginTransmission(Addr); // informs the bus that we will be sending data to slave device
  Wire.write(Data);             // send data
  Wire.endTransmission();       // informs the bus and the slave device that we have finished sending data
  Wire.requestFrom(Addr, 1);    // request data from slave
  if (Wire.available())         // read response from slave
  {
    return Wire.read();
  }
  return false;
}
