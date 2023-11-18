#pragma config(Sensor, in1,    potentiometer,  sensorAnalog)
#pragma config(Sensor, dgtl2,  irLeft,         sensorDigitalIn)
#pragma config(Sensor, dgtl1,  irRight,        sensorDigitalIn)
#pragma config(Motor,  port2,           leftDrive,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           leftJoint,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           armMotor,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           leftClaw,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           rightClaw,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           rightJoint,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           rightDrive,    tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Subsystems/drivetrain.h"
#include "Subsystems/arm.h"
#include "Subsystems/veinGrabber.h"

task main()
{
	bool initial = true;

	bool clawToggle = false;
	bool curClaw = false;
	bool prevClaw = false;

	bool dualToggle = true;
	bool curDual = false;
	bool prevDual = false;

  while (true)
  {

  	if (vexRT[Btn8R]) { // Vein Score
      setArmSetpoint(1300);
      clearTimer(T2);
      closeJoint();
      initial = false;
    } else if (vexRT[Btn8D]) { // Vein Pickup
      setArmSetpoint(795);
      clearTimer(T2);
      openJoint();
      clawToggle = false;
      initial = false;
    } else if (vexRT[Btn8U]) { // High Artery
      setArmSetpoint(1800);
      clearTimer(T2);
      initial = false;
    } else if (vexRT[Btn8L]) { // Low Artery
      setArmSetpoint(750);
      clearTimer(T2);
      initial = false;
    }

   if (((time1[T2] / 1000) > 120) || initial) {
   	stopArm();
   } else {
   	updateArm(vexRT[Btn6U], vexRT[Btn6D]); // Update the arm position using the PID controller
   }





   prevClaw = curClaw;
    if (vexRT[Btn5D]) {
    	curClaw = true;
    } else {
    	curClaw = false;
    }


    // CLAW
    // Rising edge detector
		if (curClaw && !prevClaw) {
		    // This will set intakeToggle to true if it was previously false
		    // and intakeToggle to false if it was previously true,
		    // providing a toggling behavior.
		    clawToggle = !clawToggle;
		}

		// Using the toggle variable to control the robot.
		if (clawToggle) {
		    closeClaw();
		}
		else {
		    openClaw();
		}


  	// Drive

		prevDual = curDual;
    if (vexRT[Btn7U]) {
    	curDual = true;
    } else {
    	curDual = false;
    }

    if (curDual && !prevDual) {
		    // This will set intakeToggle to true if it was previously false
		    // and intakeToggle to false if it was previously true,
		    // providing a toggling behavior.
		    dualToggle = !dualToggle;
		}

    if (dualToggle) {
    	arcadeDrive(vexRT[Ch3], vexRT[Ch1], vexRT[Btn5U]);
    } else {
    	arcadeDrive(vexRT[Ch3], vexRT[Ch4], vexRT[Btn5U]);
    }


    if (vexRT[Btn7L]) {
    	closeClaw();
    	clawToggle = true;
    	closeJoint();
    	setArmSetpoint(900);
    	lineFollowingLeft(vexRT[Btn7D]);
    } else if (vexRT[Btn7R]) {
    	closeClaw();
    	clawToggle = true;
    	closeJoint();
    	setArmSetpoint(900);
    	lineFollowingRight(vexRT[Btn7D]);
    }



  }
}
