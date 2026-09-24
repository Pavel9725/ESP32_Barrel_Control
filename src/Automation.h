#pragma once

#include <Arduino.h>
#include "Sensors.h"
#include "Motor.h"
#include "config.h"

enum State {
    STATE_IDLE,                     //Waiting for start
    STATE_OPENING,                  //Opening valve
    STATE_OPEN,                     //Valve is open
    STATE_CLOSING,                  //Closing valve
    STATE_CLOSE,                    //Valve is closed
    STATE_ERROR                     //Error
};

class Automation {
private:
    Motor& _motor;
    Sensors& _sensors;
    State _currentState;
    String _statusMsg;
    unsigned long _motorStartTime;
    void updateIndicators();
public:
    Automation(Motor& motor, Sensors& sensors);

    void init();

    void tick();

    String getStatusMsg();
    String getStateName();
};