#pragma once

#include <Arduino.h>

class Sensors
{
  private:
    uint8_t _pinSensorWater;        // D7 — water level sensor (Hofer)
    uint8_t _pinLimitOpen;          // D6 — limit switch "open"  (INPUT_PULLUP)
    uint8_t _pinLimitClose;         // D0 — limit switch "close" (INPUT + ext 10k)
    uint8_t _pinBtnStartPressed;    // D5 — start button (INPUT_PULLUP)
  public:
    Sensors(uint8_t pinSensorWater, uint8_t pinLimitOpen, uint8_t pinLimitClose, uint8_t pinBtnStartPressed);

    void init();                // configure pinMode for all inputs
  
    bool isWaterFull();         // true = water reached sensor
    bool isLimitOpen();         // true = valve fully open
    bool isLimitClose();        // true = valve fully closed
    bool isBtnStartPressed();   // true = start button pressed
};