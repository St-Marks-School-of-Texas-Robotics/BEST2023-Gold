#pragma config(Sensor, dgtl1,  irReceive1,     sensorDigitalIn)
#pragma config(Sensor, dgtl2,  irReceive2,     sensorDigitalIn)
#pragma config(Motor,  port2,           motor1,        tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{


	while(true){
		if (irReceive1 == false){
			motor[motor1] = 127;
		}

	}


}
