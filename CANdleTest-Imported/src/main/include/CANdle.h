#pragma once
#include <iostream>
//crte
#include <ctre/phoenix/led/CANdle.h>
#include <ctre/phoenix/led/LarsonAnimation.h>
class CANdle
{
public:
    CANdle();
    void stepLEDs();
    void startLED();
    void endLED();
private:
    int CANdleID = 0;
    ctre::phoenix::led::CANdle candle {CANdleID, "rio"};
    ctre::phoenix::led::LarsonAnimation larson {0,131,0, 0, .005, 8, ctre::phoenix::led::LarsonAnimation::BounceMode::Front, 1};
    int r = 255, g = 255, b = 255;
};