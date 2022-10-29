# PROTON Arduino PLC

## A5

* Microcontroller: ATmega328
* Atmel Clock Speed: 16 MHz
* RTC
* 1x serial Interface
* 1x I2C Interface
* Input current Max. 8A
* 4x Relays Outputs – 230V / 6A
* 2x Analog/Digital Inputs
* 6x Digital Inputs

## Installation guide

### General requirements

* PC with Arduino IDE (1.6.4 or newer) (Windows, Linux, MAC)
* Internet connection

### Arduino A5 PLC hardware definition

* Navigate to File–>Preferences
* Copy-paste the following link to the Additional Boards Manager URLs: https://raw.githubusercontent.com/Proton-Electronics/proton-plc/main/package_ProtonArdPlc_index.json
* Press OK button
* Then navigate to Tools–>Board: “Foo“–>Boards Manager
* In the Boards Manager type SPECTRA into the filter text box and search for SPECTRA ARDUINO PLC boards
* When found, select the latest version and install it. The installation process should be fully automated
* When finished - check in Tools–>Board: “Foo“–> menu that you can see the SPECTRA Ard PLC A10 w/ ATmega328 boards there
