#pragma config(Sensor, in1,    potentiometer,  sensorAnalog)
#pragma config(Sensor, dgtl1,  irLeft,         sensorDigitalIn)
#pragma config(Sensor, dgtl2,  irRight,        sensorDigitalIn)
#pragma config(Motor,  port2,           leftDrive,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftArm,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           leftJoint,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           leftClaw,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           rightClaw,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           rightJoint,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           rightArm,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           rightDrive,    tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Subsystems/arm.h"
#include "Subsystems/veinGrabber.h"
#include "Subsystems/drivetrain.h"

task main()
{
	bool initial = true;

	bool clawToggle = true;
	bool curClaw = false;
	bool prevClaw = false;

	bool leftToggle = false;
	bool rightToggle = false;
	bool leftClosed = false;
	bool rightClosed = false;
	bool prevLeft = false;
	bool prevRight = false;


	closeClaw();
	closeJoint();

  while (true)
  {

  	if (vexRT[Btn8U]) { // Vein Score
      setArmSetpoint(1000);
      clearTimer(T2);
      closeJoint();
      closeClaw();
      initial = false;
    } else if (vexRT[Btn8L]) { // Vein Pickup
      setArmSetpoint(850);
      clearTimer(T2);
      openJoint();
      openClaw();
      clawToggle = false;
      initial = false;
    }

   if (((time1[T2] / 1000) > 120) || initial) {
   	stopArm();
   } else {
   	updateArm(vexRT[Btn6U], vexRT[Btn6D]); // Update the arm position using the PID controller
   }




		// Left Claw Toggle
		prevLeft = leftClosed;
    if (vexRT[Btn7D]) {
    	leftClosed = true;
    } else {
    	leftClosed = false;
    }

    // Rising edge detector
		if (leftClosed && !prevLeft) {
		    // This will set intakeToggle to true if it was previously false
		    // and intakeToggle to false if it was previously true,
		    // providing a toggling behavior.
		    leftToggle = !leftToggle;

		    // Using the toggle variable to control the robot.
				if (leftToggle) {
				    closeLeftClaw();
				}
				else {
				    openLeftClaw();
				}
		}




		// Right Claw Toggle
		prevRight = rightClosed;
    if (vexRT[Btn8D]) {
    	rightClosed = true;
    } else {
    	rightClosed = false;
    }

    // Rising edge detector
		if (rightClosed && !prevRight) {
		    // This will set intakeToggle to true if it was previously false
		    // and intakeToggle to false if it was previously true,
		    // providing a toggling behavior.
		    rightToggle = !rightToggle;

		    // Using the toggle variable to control the robot.
				if (rightToggle) {
				    closeRightClaw();
				}
				else {
				    openRightClaw();
				}
		}






		   // Both Claw Toggle
   prevClaw = curClaw;
    if (vexRT[Btn8R]) {
    	curClaw = true;
    } else {
    	curClaw = false;
    }

    // Rising edge detector
		if (curClaw && !prevClaw) {
		    // This will set intakeToggle to true if it was previously false
		    // and intakeToggle to false if it was previously true,
		    // providing a toggling behavior.


				clawToggle = !clawToggle;


				// Using the toggle variable to control the robot.
				if (clawToggle) {
				    closeClaw();
				    leftToggle = true;
				    rightToggle = true;
				}
				else {
				    openClaw();
				    leftToggle = false;
				    rightToggle = false;
				}

		}



















  	// Drive

    arcadeDrive(vexRT[Ch3], vexRT[Ch1], vexRT[Btn5U]);


    if (vexRT[Btn7L]) {   // Left Auto
    	closeClaw();
    	clawToggle = true;
    	closeJoint();
    	setArmSetpoint(900);
    	lineFollowingLeft(vexRT[Btn7D]);
    } else if (vexRT[Btn7R]) {   // Right Auto
    	closeClaw();
    	clawToggle = true;
    	closeJoint();
    	setArmSetpoint(900);
    	lineFollowingRight(vexRT[Btn7D]);
    } else if (vexRT[Btn7U]) {    // Reliable Auto
    	closeClaw();
    	clawToggle = true;
    	closeJoint();
    	setArmSetpoint(900);
    	lineFollowingSlow(vexRT[Btn7D]);
    }



  }
}
