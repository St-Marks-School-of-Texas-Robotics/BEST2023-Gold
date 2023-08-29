#pragma config(Motor,  port8,           motor1,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           servo,         tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                        - VEX Servo Sweep -                                         *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program simply sweeps the servo from one end to the other, hitting all points in range.      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  You may need to change the wait times used to achieve a 90 degree turn.  Experiment to      *|
|*        find the perfect values and your robot should end facing the same direction it started.     *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor  - Port 2     rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor  - Port 3     leftMotor           VEX 3-wire module     Left side motor                   *|
\*-----------------------------------------------------------------------------------------------4246-*/



// Arav
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{

  while(true)
  {
  	// when setting a servo or motor range is [-127,+127]

    motor[servo] = -127;       // Set 'servoMotor' to position -127 (negative end of range)
    wait1Msec(500);            // Wait for 0.5 seconds (gives time for the servo to move)

    motor[motor1] = 127;       // Set 'servoMotor' to position -127 (negative end of range)

    int power = vexRT[Ch3];
    int button = vexRT[Btn5U];
  }

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++