// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <Libraries.hpp>

#include <SwerveDrive.hpp>

using namespace std;

/*
The class for the robot
*/
class Robot : public frc::TimedRobot {
  public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void TestInit() override;
    void TestPeriodic() override;
    
  private:
    frc::SendableChooser<string> m_chooser;
    const string kAutoNameDefault = "Default";
    const string kAutoNameCustom = "My Auto";
    string m_autoSelected;
};