#include "Motor.h"
#include "config.h"

// ------------------------------------------------------------
//  Constructor
// ------------------------------------------------------------
Motor::Motor(uint8_t pinServo)
{
    _pinServo = pinServo;
}

// ------------------------------------------------------------
//  Open valve
// ------------------------------------------------------------
void Motor::open()
{
    _myServo.attach(_pinServo);
    _myServo.write(SERVO_ANGLE_OPEN);
}

// ------------------------------------------------------------
//  Close valve
// ------------------------------------------------------------
void Motor::close()
{
    _myServo.attach(_pinServo);
    _myServo.write(SERVO_ANGLE_CLOSE);
}

// ------------------------------------------------------------
//  Detach servo (cut power, no holding torque)
// ------------------------------------------------------------
void Motor::stop()
{
    _myServo.detach();
}