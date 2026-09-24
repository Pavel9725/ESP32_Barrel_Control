#pragma once

#include <Arduino.h>

class Sensors {
private:
    int _pinSensorWater;
    int _pinLimitOpen;
    int _pinLimitClose;
    int _pinBtnStart;
public:
    //Constructor for 
    Sensors(int sensor_water, int lim_open, int lim_close, int btn_start);

    void init();

    bool isWaterFull();
    bool isLimitOpen();
    bool isLimitClouse();
    bool isBtnStartPressed();
};