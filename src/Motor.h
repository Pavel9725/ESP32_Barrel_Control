#pragma once

#include <Arduino.h>
#include <Servo.h>

class Motor
{
  private:
      uint8_t _pinServo;             // servo signal pin
      Servo _myServo;            // servo object
  public:
    Motor(uint8_t pinServo);         // constructor
    
    void open();                 // open valve  
    void close();                // close valve
    void stop();                 // detach — cut power to servo
};