#pragma config(Sensor, in1, potentiometer, sensorAnalog)
#pragma config(Motor, port9, armMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Sensor, dgtl3, irLeft, sensorDigitalIn)
#pragma config(Sensor, dgtl4, irRight, sensorDigitalIn)
#pragma config(Motor, port2, leftDrive, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor, port3, rightDrive, tmotorServoContinuousRotation, openLoop, reversed)

#include "Subsystems/drivetrain.h"
#include "Subsystems/arm.h"

task main()
{
  while (true)
  {
  	updateArm(); // Update the arm position using the PID controller

  	if (vexRT[Btn8U]) {
      setArmSetpoint(1500); // Vein Score
    } else if (vexRT[Btn8L]) {
      setArmSetpoint(1500); // Vein Pickup
    } else if (vexRT[Btn8R]) {
      setArmSetpoint(1500); // High Artery
    } else if (vexRT[Btn8D]) {
      setArmSetpoint(1500); // Low Artery
    } else if (vexRT[Btn6U]) {
    	nudgeUp();
    } else if (vexRT[Btn6D]) {
    	nudgeDown();
    }

  	// Drive
    arcadeDrive(vexRT[Ch3], vexRT[Ch1], vexRT[Btn5U]);




  }
}
