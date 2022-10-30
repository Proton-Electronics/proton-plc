# Proton Arduino PLC

## Proton Plc A5 

### Tech Specs

**ATmega328** Microcontroller  
- High-performance low-power 8-bit processor
- Achieve up to 16 MIPS for 16 MHz clock frequency
- 32 kB of which 2 KB used by bootloader
- 2 kB internal SRAM
- 1 kB EEPROM
- 32 x 8 General Purpose Working Registers
- Real Time Counter with Separate Oscillator
- Six PWM Channels
- Programmable Serial USART
- Master/Slave SPI Serial Interface

**Power**  
- USB C connection
- 12V-24V unregulated external power supply (Max 32V)
- Overvoltage and overcurrent protection

**Sleep Modes**  
- Idle
- ADC Noise Reduction
- Power-save
- Power-down
- Standby
- Extended Standby

**I/O**  
- 6 Digital Input 12V-24V
- 4 Analog Input 0V-10V
- 2 Analog Output
- 5 Relays Output - 230V / 5A
- 1 I2C 

## Installation guide

### General requirements

* PC with Arduino IDE (1.6.4 or newer) (Windows, Linux, MAC)
* Internet connection

### Arduino A5 PLC hardware definition

* Navigate to File–>Preferences
* Copy-paste the following link to the Additional Boards Manager URLs: `https://raw.githubusercontent.com/Proton-Electronics/proton-plc/main/package_proton_ArdPlc_index.json`
* Press OK button
* Then navigate to `Tools`–>`Board: 'xxxxxx'`–>`Boards Manager`
* In the Boards Manager type `Proton` into the filter text box and search for `Proton Arduino PLC boards`
* When found, select the latest version and install it. The installation process should be fully automated
* When finished - check in `Tools`–>`Board: 'xxxxxx'`–> menu that you can see the `Proton Ard PLC A5 w/ ATmega328` boards there
