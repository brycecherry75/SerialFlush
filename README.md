#SerialFlush Library#

SerialFlush is a discrete library for flushing the contents of a given serial port including I2C (Wire) - SPI does not use the available() function unlike I2C and therefore does not use a buffer.

Revisions
1.0.0	First release

USAGE:
(flushSerial/flushSerial(1/2/3/USB)/flushWire)(BaudRate) - BaudRate determines if more than one flush is required which checks if at least one byte has been received after the previous flush

Serial(1/2/3) is only supported on Mega/Due and derivatives and SerialUSB is only supported on Due and derivatives.

## Issues

Arduino HardwareSerial.h and when included, Wire.h libraries consumes program memory and global registers even when flushSerial/flushWire functions are not used; until the Wire and Serial libraries are rewritten to not use any program storage and global registers if this library is included and unused, comment out the WIRE_ENABLED (already done here) and/or SERIAL_ENABLED #define lines in SerialFlush.h if not using such functions to save resources.