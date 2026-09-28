#include "Sensors.h"

Sensors::Sensors(int sensor_water, int btn_start)
{
    _pinSensorWater = sensor_water;

    _pinBtnStart = btn_start;
}

void Sensors::init()
{
    pinMode(_pinSensorWater, INPUT_PULLUP);
    pinMode(_pinBtnStart, INPUT_PULLUP);
}

bool Sensors::isWaterFull()
{
    return digitalRead(_pinSensorWater) == HIGH;
}

bool Sensors::isBtnStartPressed()
{
    return digitalRead(_pinBtnStart) == LOW;
}