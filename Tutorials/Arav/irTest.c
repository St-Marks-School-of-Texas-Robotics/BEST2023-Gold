#pragma config(Sensor, dgtl1,  irReceive1,     sensorDigitalIn)
#pragma config(Sensor, dgtl10, irReceive2,     sensorDigitalIn)
#pragma config(Motor,  port2,           motor1,        tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{


	while(true){

		clearDebugStream();

		//writeDebugStream("%d", SensorValue[irReceive1]);
		writeDebugStreamLine("%d", SensorValue[irReceive1]);
		writeDebugStreamLine("%d", SensorValue[irReceive2]);


	}



}
