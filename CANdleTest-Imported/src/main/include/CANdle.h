#pragma once
//crte
#include <ctre/phoenix/led/CANdle.h>
class CANdle
{
public:
    CANdle();
    void stepLEDs();
private:
    int CANdleID = 1;
    ctre::phoenix::led::CANdle candle {CANdleID, "rio"};
    int r = 255, g = 255, b = 255;
};