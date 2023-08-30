#pragma config(Motor,  port5,           servoMotor,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)
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


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  while(true)
  {
    motor[servoMotor] = -127;       // Set 'servoMotor' to position -127 (negative end of range)
    wait1Msec(500);                 // Wait for 0.5 seconds (gives time for the servo to move)

    for(int i=-117; i<128; i+=10)     /* Starting 'i' at -117, and incrementing by 10, */
    {                                 /* continue while 'i' is less than 0. */
      motor[servoMotor] = i;          // Set 'servoMotor' to position 'i'.
      wait1Msec(250);                 // Wait for 0.25 seconds (gives time for the servo to move)
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
