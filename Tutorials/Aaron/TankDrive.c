#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           servoMotor,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;

	while(true){
		float forwardStick = vexRT[Ch3];
		float sideStick = vexRT[Ch4];
		float leftPower = vexRT[Ch3]-vexRT[Ch4];
		float rightPower = vexRT[Ch3]+vexRT[Ch4];
		float max = abs(forwardStick) + abs(sideStick);
		float denominator;
		if(max > 127){
			denominator = max;
		} else {
			denominator = 127;
		}
		motor[leftMotor] = leftPower / denominator * 127;
		motor[rightMotor] = rightPower / denominator * 127;
		int upperButtonPosition = vexRT[Btn6U];
		int lowerButtonPosition = vexRT[Btn6D];
		if(upperButtonPosition == 1){
			motor[servoMotor] = 127;
		}
		if(lowerButtonPosition == 1){
			motor[servoMotor] = -127;
		}
	}




}
