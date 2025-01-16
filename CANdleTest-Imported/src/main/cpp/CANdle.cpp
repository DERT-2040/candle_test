//local
#include "CANdle.h"

CANdle::CANdle()
{
    r = 0;
    g = 0;
    b = 255;

    ctre::phoenix::led::CANdleConfiguration config;
    config.stripType = ctre::phoenix::led::LEDStripType::RGB; // set the strip type to RGB
    config.brightnessScalar = 0.5; // dim the LEDs to half brightness
    candle.ConfigAllSettings(config);
}

void CANdle::stepLEDs()
{
    r = r+1;
    r %= 256;
    candle.SetLEDs(r, g, b); // set the CANdle LEDs to white
}

void CANdle::startLED()
{
    std::cout << candle.GetMaxSimultaneousAnimationCount();
    candle.Animate(larson, 0);
}

void CANdle::endLED()
{
    candle.ClearAnimation(0);
}