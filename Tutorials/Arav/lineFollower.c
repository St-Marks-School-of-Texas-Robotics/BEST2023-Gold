#pragma config(Sensor, dgtl1,  irLeft,         sensorDigitalIn)
#pragma config(Sensor, dgtl2,  irRight,        sensorDigitalIn)
#pragma config(Motor,  port2,           leftDrive,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{


	while(true){

	if (SensorValue[irLeft] == 1) { // left over black
		motor[leftDrive] = 60;
		motor[rightDrive] = 75;
	} else if (SensorValue[irRight] == 1) { // right over black
		motor[leftDrive] = 75;
		motor[rightDrive] = 60;
	} else {
		motor[leftDrive] = 75;
		motor[rightDrive] = 75;
	}





	}



}
