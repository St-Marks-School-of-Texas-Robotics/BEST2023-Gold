#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           rightMotor,    tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	//int q = 0;
	while(true){

		motor[rightMotor] = vexRT[Ch3]+vexRT[Ch1];
		motor[leftMotor] = vexRT[Ch3]-vexRT[Ch1];

	}




}
