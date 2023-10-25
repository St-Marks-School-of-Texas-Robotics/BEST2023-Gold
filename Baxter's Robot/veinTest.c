#pragma config(Motor,  port6,           rightClaw,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           leftClaw,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           rightJoint,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           leftJoint,     tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

    while (true)
    {
        if (vexRT[Btn5U] == 1) // close
        {
            // Set the servo positions
        	motor[leftJoint] = 100;
        	motor[rightJoint] = -90;
        }
        else if (vexRT[Btn5D] == 1) //open
        {
            motor[leftJoint] = -90;
        		motor[rightJoint] = 128;
        }

        if (vexRT[Btn6U] == 1) // close
        {
            // Set the servo positions
        	motor[leftClaw] = 128;
        	motor[rightClaw] = -100;
        }
        else if (vexRT[Btn6D] == 1) //open
        {
            motor[leftClaw] = -100;
        		motor[rightClaw] = 128;
        }


    }
}