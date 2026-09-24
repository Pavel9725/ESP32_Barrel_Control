#include "Motor.h"


Motor::Motor(int pin1, int pin2)
{
    _pin1 = pin1;
    _pin2 = pin2;
}

void Motor::init()
{
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    stop();
}

void Motor::open()
{
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
}

void Motor::close()
{
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
}

void Motor::stop()
{
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
}