#pragma once

#ifndef BatteryInterface_h
#define BatteryInterface_h

#include <Arduino.h>

#include "configs.h"
#include "Adafruit_MAX1704X.h"
#include <XPowersLib.h> // added this for battery management
#include <Wire.h>

#define IP5306_ADDR 0x75
#define MAX17048_ADDR 0x36
#define SY6970_ADDR 0x6A // from xpowers lib

class BatteryInterface {
  private:
    uint32_t initTime = 0;
    Adafruit_MAX17048 maxlipo;
    //static PowersSY6970 PMU;
    
  public:
    int8_t battery_level = 0;
    int8_t old_level = 0;
    bool i2c_supported = false;
    bool has_max17048 = false;
    bool has_ip5306 = false;
    bool has_sy6970 = false;
    
    BatteryInterface();
    
    void RunSetup();
    void main(uint32_t currentTime);
    int8_t getBatteryLevel();
};

#endif
