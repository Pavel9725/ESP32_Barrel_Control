#pragma once

// SETTING FOR WI-FI ANF NTP SERVER CONFIGURATION
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
#define NTP_SERVER "pool.ntp.org"
#define TIME_ZONE "NOVT-7" // UTC +7


// SETTINGS FOR SERVO CONTROL
#define SERVO_PIN               5        //Servo pin
#define PIN_LED_STATUS_OK       4        //LED STATUS OK
#define PIN_LED_STATUS_ERROR    0        //LED STATUS ERROR

//SETTINGS FOR SENSORS
#define PIN_SENSOR_WATER  14                 //Sensor water level HOFER
#define PIN_BTN_START     12                 //Button start


//SECURITY SETTINGS
#define SERVO_ANGLE_OPEN  90                 //Angle for open
#define SERVO_ANGLE_CLOSE 0                  //Angle for close
#define MOTOR_MOVE_TIME_MS   1500            //time 2s for move tap
#define MAX_LOG_RECORDS     50              //history sms

#define WATER_CONFIRM_MS        10000        //time 10s for confirm water
