#include "SerialFlush.h"

#if defined(SERIALPORT_AVAILABLE_SerialFlush)
void SerialFlushClass::flushSerial(uint32_t BaudRate) {
  uint32_t TimePerByte = 10000000UL;
  if (BaudRate > 115200UL) {
    TimePerByte = 5;
  }
  else {
    uint8_t factor = 105;
    TimePerByte /= BaudRate;
    TimePerByte *= factor;
    TimePerByte /= 100;
  }
  while (true) {
    if (Serial.available() > 0) {
      byte dummy = Serial.read();
      while (Serial.available() > 0) { // flush additional bytes from serial buffer if present
        dummy = Serial.read();
      }
      if (TimePerByte <= 16383) {
        delayMicroseconds(TimePerByte); // delay in case another byte may be received via the serial port
      }
      else { // deal with delayMicroseconds limitation
        unsigned long DelayTime = TimePerByte;
        DelayTime /= 1000;
        if (DelayTime > 0) {
          delay(DelayTime);
        }
        DelayTime = TimePerByte;
        DelayTime %= 1000;
        if (DelayTime > 0) {
          delayMicroseconds(DelayTime);
        }
      }
    }
    else {
      break;
    }
  }
}
#endif

#if defined(AUXSERIALPORT_1_AVAILABLE_SerialFlush)
void SerialFlushClass::flushSerial1(uint32_t BaudRate) {
  uint32_t TimePerByte = 10000000UL;
  if (BaudRate > 115200UL) {
    TimePerByte = 5;
  }
  else {
    uint8_t factor = 105;
    TimePerByte /= BaudRate;
    TimePerByte *= factor;
    TimePerByte /= 100;
  }
  while (true) {
    if (Serial1.available() > 0) {
      byte dummy = Serial1.read();
      while (Serial1.available() > 0) { // flush additional bytes from serial buffer if present
        dummy = Serial1.read();
      }
      if (TimePerByte <= 16383) {
        delayMicroseconds(TimePerByte); // delay in case another byte may be received via the serial port
      }
      else { // deal with delayMicroseconds limitation
        unsigned long DelayTime = TimePerByte;
        DelayTime /= 1000;
        if (DelayTime > 0) {
          delay(DelayTime);
        }
        DelayTime = TimePerByte;
        DelayTime %= 1000;
        if (DelayTime > 0) {
          delayMicroseconds(DelayTime);
        }
      }
    }
    else {
      break;
    }
  }
}
#endif

#if defined(AUXSERIALPORT_2_AVAILABLE_SerialFlush) 
void SerialFlushClass::flushSerial2(uint32_t BaudRate) {
  uint32_t TimePerByte = 10000000UL;
  if (BaudRate > 115200UL) {
    TimePerByte = 5;
  }
  else {
    uint8_t factor = 105;
    TimePerByte /= BaudRate;
    TimePerByte *= factor;
    TimePerByte /= 100;
  }
  while (true) {
    if (Serial2.available() > 0) {
      byte dummy = Serial2.read();
      while (Serial2.available() > 0) { // flush additional bytes from serial buffer if present
        dummy = Serial2.read();
      }
      if (TimePerByte <= 16383) {
        delayMicroseconds(TimePerByte); // delay in case another byte may be received via the serial port
      }
      else { // deal with delayMicroseconds limitation
        unsigned long DelayTime = TimePerByte;
        DelayTime /= 1000;
        if (DelayTime > 0) {
          delay(DelayTime);
        }
        DelayTime = TimePerByte;
        DelayTime %= 1000;
        if (DelayTime > 0) {
          delayMicroseconds(DelayTime);
        }
      }
    }
    else {
      break;
    }
  }
}
#endif

#if defined(AUXSERIALPORT_3_AVAILABLE_SerialFlush)
void SerialFlushClass::flushSerial3(uint32_t BaudRate) {
  uint32_t TimePerByte = 10000000UL;
  if (BaudRate > 115200UL) {
    TimePerByte = 5;
  }
  else {
    uint8_t factor = 105;
    TimePerByte /= BaudRate;
    TimePerByte *= factor;
    TimePerByte /= 100;
  }
  while (true) {
    if (Serial3.available() > 0) {
      byte dummy = Serial3.read();
      while (Serial3.available() > 0) { // flush additional bytes from serial buffer if present
        dummy = Serial3.read();
      }
      if (TimePerByte <= 16383) {
        delayMicroseconds(TimePerByte); // delay in case another byte may be received via the serial port
      }
      else { // deal with delayMicroseconds limitation
        unsigned long DelayTime = TimePerByte;
        DelayTime /= 1000;
        if (DelayTime > 0) {
          delay(DelayTime);
        }
        DelayTime = TimePerByte;
        DelayTime %= 1000;
        if (DelayTime > 0) {
          delayMicroseconds(DelayTime);
        }
      }
    }
    else {
      break;
    }
  }
}
#endif

#if defined(USBSERIALPORT_AVAILABLE_SerialFlush)
void SerialFlushClass::flushSerialUSB(uint32_t BaudRate) {
  uint32_t TimePerByte = 10000000UL;
  if (BaudRate > 115200UL) {
    TimePerByte = 5;
  }
  else {
    uint8_t factor = 105;
    TimePerByte /= BaudRate;
    TimePerByte *= factor;
    TimePerByte /= 100;
  }
  while (true) {
    if (SerialUSB.available() > 0) {
      byte dummy = SerialUSB.read();
      while (SerialUSB.available() > 0) { // flush additional bytes from serial buffer if present
        dummy = SerialUSB.read();
      }
      if (TimePerByte <= 16383) {
        delayMicroseconds(TimePerByte); // delay in case another byte may be received via the serial port
      }
      else { // deal with delayMicroseconds limitation
        unsigned long DelayTime = TimePerByte;
        DelayTime /= 1000;
        if (DelayTime > 0) {
          delay(DelayTime);
        }
        DelayTime = TimePerByte;
        DelayTime %= 1000;
        if (DelayTime > 0) {
          delayMicroseconds(DelayTime);
        }
      }
    }
    else {
      break;
    }
  }
}
#endif

#if defined(WIRE_AVAILABLE_SerialFlush)
  uint32_t TimePerByte = 10000000UL;
  if (BaudRate > 115200UL) {
    TimePerByte = 5;
  }
  else {
    uint8_t factor = 105;
    TimePerByte /= BaudRate;
    TimePerByte *= factor;
    TimePerByte /= 100;
  }
  while (true) {
    if (Wire.available() > 0) {
      byte dummy = Wire.read();
      while (Wire.available() > 0) { // flush additional bytes from serial buffer if present
        dummy = Wire.read();
      }
      if (TimePerByte <= 16383) {
        delayMicroseconds(TimePerByte); // delay in case another byte may be received via the serial port
      }
      else { // deal with delayMicroseconds limitation
        unsigned long DelayTime = TimePerByte;
        DelayTime /= 1000;
        if (DelayTime > 0) {
          delay(DelayTime);
        }
        DelayTime = TimePerByte;
        DelayTime %= 1000;
        if (DelayTime > 0) {
          delayMicroseconds(DelayTime);
        }
      }
    }
    else {
      break;
    }
  }
#endif

SerialFlushClass SerialFlush;