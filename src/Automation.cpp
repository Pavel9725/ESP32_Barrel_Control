#include "Automation.h"

Automation::Automation(Motor& motor, Sensors& sensors)
    : _motor(motor), _sensors(sensors)
{
    _motor = motor;
    _sensors = sensors;

    _currentState = STATE_IDLE;
    _statusMsg = "System is idle";
    _motorStartTime = 0;
    _waterConfirmTime = 0;
}

void Automation::init()
{
    pinMode(PIN_LED_STATUS_OK, OUTPUT);
    pinMode(PIN_LED_STATUS_ERROR, OUTPUT);
    _currentState = STATE_IDLE;
    _statusMsg = "System is idle";
}

void Automation::tick()
{
    switch (_currentState) {
        case STATE_IDLE:
            if(_sensors.isBtnStartPressed())
            {
                _motor.open();
                _motorStartTime = millis();
                _currentState = STATE_OPENING;
                _statusMsg = "Opening valve";
            }
            break;

        case STATE_OPENING:
            if(millis() - _motorStartTime > MOTOR_MOVE_TIME_MS)
            {
                _motor.stop();
                _currentState = STATE_OPEN;
                _statusMsg = "Valve is open, filling...";
            }
            break;

            case STATE_OPEN:
                if(_sensors.isWaterFull())
                {
                    _waterConfirmTime = millis();
                    _currentState = STATE_WATER_CONFIRM;
                    _statusMsg = "Water detected, confirming...";
                }
                break;

            case STATE_WATER_CONFIRM:
                if(!_sensors.isWaterFull())
                {
                    _currentState = STATE_OPEN;
                    _statusMsg = "False trigger, keep filling...";
                } else if(millis() - _waterConfirmTime > WATER_CONFIRM_MS)
                {
                    _motor.close();
                    _motorStartTime = millis();
                    _currentState = STATE_CLOSING;
                    _statusMsg = "Confirmed full, closing...";
                }
                break;

            case STATE_CLOSING:
                if(millis() - _motorStartTime > MOTOR_MOVE_TIME_MS)
                {
                    _motor.stop();
                    _currentState = STATE_CLOSE;
                    _statusMsg = "Barrel is full. Done.";
                }
                break;

            case STATE_CLOSE:
                if(_sensors.isBtnStartPressed() && !_sensors.isWaterFull())
                {
                    _currentState = STATE_IDLE;
                    _statusMsg = "Ready for next cycle";
                }
                break;
            
            case STATE_ERROR:
                break;
            }
}

String Automation::getStatusMsg() { return _statusMsg; }

String Automation::getStateName()
{
    switch (_currentState) {
    case STATE_IDLE:
        return "STATE_IDLE";
    case STATE_OPENING:
        return "STATE_OPENING";
    case STATE_OPEN:
        return "STATE_OPEN";
    case STATE_WATER_CONFIRM:
        return "STATE_WATER_CONFIRM";
    case STATE_CLOSING:
        return "STATE_CLOSING";
    case STATE_CLOSE:
        return "STATE_CLOSE";
    case STATE_ERROR:
        return "STATE_ERROR";
    }
    return "IDLE";
}