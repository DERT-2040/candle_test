#pragma once

//local
#include "lib/include/Component.h"
#include "include/Constants.h"
//crte
#include <ctre/phoenix/led/CANdle.h>
//Simulink
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"

class CANdle : public Component
{
public:
    CANdle();
    /**
     * Runs before the step function is called in the main loop
     */
    void PreStepCallback();

    /**
     * Runs after the step function is called in the main loop
     */
    void PostStepCallback();
    
    /**
     * Puts values to the SmartDashboard via the SD Callbacks function
     */
    void SmartDashboardCallback();
    
    /**
     * Callback that triggers when the game state of the robot changes
     */
    void GameStateChangeCallback();
    
    void SetLEDs();
    /*
     * X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
     * X X X X                 Class Specific Methods                  X X X X
     * X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
     */
private:
    /**
     * Pigeon 2 IMU from CRTE
    */
    //ctre::phoenix6::hardware::Pigeon2 m_Pigeon2{kCAndle::k_Pigeon2_Device_ID, static_cast<std::string>(kIMU::k_Pigeon2_Device_Name)};
    ctre::phoenix::led::CANdle m_candle {CANdleID, "uno"};
    ctre::phoenix::led::CANdleConfiguration config;
    int m_r, m_g, m_b;
};

constexpr int CANdleID = 1;
