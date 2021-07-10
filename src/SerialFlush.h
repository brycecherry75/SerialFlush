#ifndef SerialFlush_h
#define SerialFlush_h

#include <Arduino.h>

// #define WIRE_ENABLED_SerialFlush // comment out if you do not use the Wire (I2C) library to reduce use of program storage and global registers - Wire library could be rewritten to not use any program storage and global registers if this library is included and unused - this does not affect SPI library for most platforms
#define SPI_ENABLED_SerialFlush
#define SERIAL_ENABLED_SerialFlush // comment out if you do not use serial communication to reduce use of program storage and global registers - HardwareSerial library could be rewritten to not use any program storage and global registers if this library is included and unused - this does not affect SPI library for most platforms
#define SERIAL_1_ENABLED_SerialFlush // comment out if you do not use serial communication to reduce use of program storage and global registers - HardwareSerial library could be rewritten to not use any program storage and global registers if this library is included and unused - this does not affect SPI library for most platforms
#define SERIAL_2_ENABLED_SerialFlush // comment out if you do not use serial communication to reduce use of program storage and global registers - HardwareSerial library could be rewritten to not use any program storage and global registers if this library is included and unused - this does not affect SPI library for most platforms
#define SERIAL_3_ENABLED_SerialFlush // comment out if you do not use serial communication to reduce use of program storage and global registers - HardwareSerial library could be rewritten to not use any program storage and global registers if this library is included and unused - this does not affect SPI library for most platforms

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega48__) || defined(__AVR_ATmega8__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAM_DUE)
#if defined(SERIAL_ENABLED_SerialFlush)
#define SERIALPORT_AVAILABLE_SerialFlush // consumes program storage and global registers even when functions covered under this definition are not used
#endif
#if defined(WIRE_ENABLED_SerialFlush)
#include <Wire.h> // consumes program storage and global registers irrespective of being used or not and even when functions covered under this definition are not used
#define WIRE_AVAILABLE_SerialFlush
#endif
#endif

#if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(ARDUINO_SAM_DUE)) // Mega and Due only
#if defined(SERIAL_1_ENABLED_SerialFlush)
#define AUXSERIALPORT_1_AVAILABLE_SerialFlush
#endif
#if defined(SERIAL_2_ENABLED_SerialFlush)
#define AUXSERIALPORT_2_AVAILABLE_SerialFlush
#endif
#if defined(SERIAL_3_ENABLED_SerialFlush)
#define AUXSERIALPORT_3_AVAILABLE_SerialFlush
#endif
#endif

#if defined(ARDUINO_SAM_DUE)
#define USBSERIALPORT_AVAILABLE_SerialFlush
#endif

class SerialFlushClass {

  public:
#if defined(SERIALPORT_AVAILABLE_SerialFlush)
    void flushSerial(uint32_t BaudRate);
#endif
#if defined(AUXSERIALPORT_1_AVAILABLE_SerialFlush)
    void flushSerial1(uint32_t BaudRate);
#endif
#if defined(AUXSERIALPORT_2_AVAILABLE_SerialFlush)
    void flushSerial2(uint32_t BaudRate);
#endif
#if defined(AUXSERIALPORT_3_AVAILABLE_SerialFlush)
    void flushSerial3(uint32_t BaudRate);
#endif
#if defined(USBSERIALPORT_AVAILABLE_SerialFlush)
    void flushSerialUSB(uint32_t BaudRate);
#endif
#if defined(WIRE_AVAILABLE_SerialFlush)
    void flushWire(uint32_t BaudRate);
#endif

};

extern SerialFlushClass SerialFlush;

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega88__) || defined(__AVR_ATmega48__) || defined(__AVR_ATmega8__) // Serial/Wire/SPI
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // Serial/Wire/SPIAux Serial x3
#elif defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega32U4__) // Serial/Wire/SPI
#elif defined(ARDUINO_SAMD_ZERO) // Serial/Wire/SPI
#elif defined(ARDUINO_SAM_DUE) // Serial/Wire/SPI/Aux Serial x3/USB Serial
#else
#error Unsupported chip, please edit SerialFlush library with corresponding supported hardware functions
#endif

#endif