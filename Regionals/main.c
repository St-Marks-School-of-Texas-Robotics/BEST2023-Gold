#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)


#include "Subsystems/drivetrain.h"

task main()
{
  while (true)
  {
    arcadeDrive(vexRT[Ch3], vexRT[Ch1], vexRT[Btn5U]);
  }
}
