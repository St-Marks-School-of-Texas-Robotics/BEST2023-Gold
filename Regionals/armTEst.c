#pragma config(Motor,  port6,           leftJoint,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           leftClaw,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           rightClaw,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           rightJoint,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Subsystems/veinGrabber.h"

task main()
{
	bool clawToggle = false;
	int prevClaw = false;


  while (true)
  {

  	if (vexRT[Btn8U]) { // Vein Score
      closeJoint();
    } else if (vexRT[Btn8L]) { // Vein Pickup
      openJoint();
      //openClaw();
    }

/*
    // CLAW
    // Rising edge detector
		if (vexRT[Btn5D] && !prevClaw) {
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

    prevClaw = vexRT[Btn5D];

*/

  }
}
