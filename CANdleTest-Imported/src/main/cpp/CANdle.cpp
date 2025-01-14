//local
#include "CANdle.h"

CANdle::CANdle()
{
    r = 255;
    g = 0;
    b = 0;

    ctre::phoenix::led::CANdleConfiguration config;
    config.stripType = ctre::phoenix::led::LEDStripType::RGB; // set the strip type to RGB
    config.brightnessScalar = 0.5; // dim the LEDs to half brightness
    candle.ConfigAllSettings(config);
}

void CANdle::stepLEDs()
{
    candle.SetLEDs(r, g, b); // set the CANdle LEDs to white
}