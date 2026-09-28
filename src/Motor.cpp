#include "Motor.h"
#include "config.h"


Motor::Motor(int servoPin)
{
    _servoPin = servoPin;
}

void Motor::init()
{
    _myServo.attach(_servoPin);
    _myServo.write(SERVO_ANGLE_CLOSE);
    delay(500);
    _myServo.detach();
    
}

void Motor::open()
{
    _myServo.attach(_servoPin);
    _myServo.write(SERVO_ANGLE_OPEN);
}

void Motor::close()
{
    _myServo.attach(_servoPin);
    _myServo.write(SERVO_ANGLE_CLOSE);
}

void Motor::stop()
{
    _myServo.detach();
}