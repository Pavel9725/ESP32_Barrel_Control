#pragma once

#include <Arduino.h>

class Motor {
private:
    int _pin1;
    int _pin2;
public:
    Motor(int pin1, int pin2);      //Constructor for motor

    void init();                    //Initialization for motor
    

    void open();                    //
    void close();
    void stop();
};