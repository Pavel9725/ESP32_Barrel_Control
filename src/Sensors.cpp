#include "Sensors.h"

Sensors::Sensors(int sensor_water, int lim_open, int lim_close, int btn_start)
{
    _pinSensorWater = sensor_water;
    _pinLimitOpen = lim_open;
    _pinLimitClose = lim_close;
    _pinBtnStart = btn_start;
}

void Sensors::init()
{
    pinMode(_pinSensorWater, INPUT_PULLUP);
    pinMode(_pinLimitOpen, INPUT_PULLUP);
    pinMode(_pinLimitClose, INPUT_PULLUP);
    pinMode(_pinBtnStart, INPUT_PULLUP);
}

bool Sensors::isWaterFull()
{
    return digitalRead(_pinSensorWater) == LOW;
}

bool Sensors::isLimitOpen()
{
    return digitalRead(_pinLimitOpen) == LOW;
}

bool Sensors::isLimitClouse()
{
    return digitalRead(_pinLimitClose) == LOW;
}

bool Sensors::isBtnStartPressed()
{
    return digitalRead(_pinBtnStart) == LOW;
}