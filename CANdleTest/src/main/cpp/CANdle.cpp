//local
#include "include/CANdle.h"
#include "ctre/phoenix/led/LarsonAnimation.h"
int previousnumber = 0;
private Animation m_toAnimate = null;
void CANdle::PreStepCallback()
{    m_r = 255;
    m_g = 255;
    m_b = 255;
}

void CANdle::PostStepCallback(int animnum)
{
     if(animnum != previousnumber){
        if(m_toAnimate != NULL) delete m_toAnimate;
        previousnumber = animnum;
        if(animnum == 0){
        m_toAnimate = new LarsonAnimation(0, 255, 46, 0, 1, LedCount, LarsonAnimation::BounceMode::Front, 3);
        } else if (animnum == 1){
            m_toAnimate = new FireAnimation(0.5, 0.7, LedCount, 0.7, 0.5);
        } else if (animnum == 2){
            m_toAnimate = new ColorFlowAnimation(128, 20, 70, 0, 0.7, LedCount, ColorFlowAnimation::Direction::Forward);
        } else if (animnum == 3){
            m_toAnimate = new RgbFadeAnimation(0.7, 0.4, LedCount);
        }
         
     }
}

void CANdle::SmartDashboardCallback()
{

}

void CANdle::GameStateChangeCallback()
{

}
void SetLEDs(int m_r, int m_g, int m_b, std::function<double()> r, std::function<double()> b, std::function<double()> g)
{
    m_r = r() * 150;
    m_b = b() * 200;
    m_g = g() * 250;
}

CANdle::CANdle() {

    /*
    ChangeAnimation(AnimationTypes::SetAll);
    CANdleConfiguration configAll {};
    configAll.statusLedOffWhenActive = true;
    configAll.disableWhenLOS = false;
    configAll.stripType = LEDStripType::GRB;
    configAll.brightnessScalar = 0.1;
    configAll.vBatOutputMode = VBatOutputMode::Modulated;
    m_candle.ConfigAllSettings(configAll, 100);
    */
}