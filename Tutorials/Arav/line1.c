#pragma config(Sensor, dgtl1,  irLeft,         sensorDigitalIn)
#pragma config(Sensor, dgtl2,  irRight,        sensorDigitalIn)
#pragma config(Motor,  port2,           leftDrive,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           rightDrive,    tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

clearTimer(T1);
clearTimer(T2);

	while(true){


		clearDebugStream();
	writeDebugStream("%d", SensorValue[irLeft]);
	// 40 , 45
	if (SensorValue[irLeft] == 0) { // left over white
		motor[leftDrive] = 15;
		motor[rightDrive] = 75 + 150 * (time1[T1]/1000);

		clearTimer(T2);
	} else {
		motor[leftDrive] = 38 + 25 * (time1[T2]/1000);
		motor[rightDrive] = 32;

		clearTimer(T1);
	}



	}




}
