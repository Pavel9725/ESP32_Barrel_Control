#pragma once

#include <Arduino.h>

class Sensors {
private:
    int _pinSensorWater;
    int _pinBtnStart;
public:
    //Constructor for 
    Sensors(int sensor_water, int btn_start);

    void init();

    bool isWaterFull();
    bool isBtnStartPressed();
};