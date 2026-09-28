#pragma once

#include <Arduino.h>
#include <Servo.h>

class Motor {
private:
    int _servoPin;
    Servo _myServo;
public:
    Motor(int servoPin);      //Constructor for motor

    void init();                    //Initialization for motor
    
    void open();                    
    void close();
    void stop();
};