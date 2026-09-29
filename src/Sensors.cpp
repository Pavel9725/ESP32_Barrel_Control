#include "Sensors.h"

// ------------------------------------------------------------
//  Constructor
// ------------------------------------------------------------
Sensors::Sensors(uint8_t pinSensorWater, uint8_t pinLimitOpen, uint8_t pinLimitClose, uint8_t pinBtnStartPressed)
{
  _pinSensorWater = pinSensorWater;
  _pinLimitOpen = pinLimitOpen;
  _pinLimitClose = pinLimitClose;
  _pinBtnStartPressed = pinBtnStartPressed;
}

// ------------------------------------------------------------
//  Init pins — configure pull-ups, pinLimitClose - external pullup 3v3.
// ------------------------------------------------------------
void Sensors::init()
{
  pinMode(_pinSensorWater, INPUT_PULLUP);
  pinMode(_pinLimitOpen, INPUT_PULLUP);
  pinMode(_pinLimitClose, INPUT);
  pinMode(_pinBtnStartPressed, INPUT_PULLUP);
}

// ------------------------------------------------------------
//  Water level: opens when water reaches sensor
//  true = water full
// ------------------------------------------------------------
bool Sensors::isWaterFull()
{
  return digitalRead(_pinSensorWater) == HIGH;
}

// ------------------------------------------------------------
//  Limit switch "open": LOW when pressed
//  true = valve fully open
// ------------------------------------------------------------
bool Sensors::isLimitOpen()
{
  return digitalRead(_pinLimitOpen) == LOW;
}

// ------------------------------------------------------------
//  Limit switch "close": LOW when pressed
//  true = valve fully closed
// ------------------------------------------------------------
bool Sensors::isLimitClose()
{
  return digitalRead(_pinLimitClose) == LOW;
}

// ------------------------------------------------------------
//  Start button: LOW when pressed
//  true = button pressed
// ------------------------------------------------------------
bool Sensors::isBtnStartPressed()
{
  return digitalRead(_pinBtnStartPressed) == LOW;
}