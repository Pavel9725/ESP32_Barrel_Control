#pragma once

// SETTING FOR WI-FI ANF NTP SERVER CONFIGURATION
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
#define NTP_SERVER "pool.ntp.org"
#define TIME_ZONE "NOVT-7" // UTC +7
#define TIME_Z


//SETTINGS FOR PIN ESP32
#define PIN_AIN1_BIN1  19               //Driver motor TB6612FNG AIN1 and BIN1
#define PIN_AIN2_BIN2  21               //Driver motor TB6612FNG AIN2 and BIN2

#define PIN_SENSOR_WATER  4                 //Sensor water level HOFER
#define PIN_LIMIT_OPEN  5                   //Limit switch OPEN
#define PIN_LIMIT_CLOSE  18                  //Limit switch CLOSE

#define PIN_BTN_START  13                   //Button START
#define PIN_LED_STATUS_OK  12               //LED STATUS OK
#define PIN_LED_STATUS_ERROR  15            //LED STATUS ERROR

//SECURITY SETTINGS
#define MAX_MOTOR_TIME_MS   5000            //time 5s for move tap
#define MAX_LOG_RECORDS     50              //history sms
