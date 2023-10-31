
// Function to implement arcade drive
void arcadeDrive(int yJoystick, int xJoystick, int slow) {

	int leftMotorSpeed = yJoystick + xJoystick;
  int rightMotorSpeed = yJoystick - xJoystick;

	if (slow == 1) {
		motor[leftDrive] = 0.3 * leftMotorSpeed;
  	motor[rightDrive] = 0.3 * rightMotorSpeed;
	} else {
		motor[leftDrive] = leftMotorSpeed;
  	motor[rightDrive] = rightMotorSpeed;
	}

}


// Function to stop the drivetrain
void stopDrivetrain() {
  motor[leftDrive] = 0;
  motor[rightDrive] = 0;
}




// Function to implement arcade drive
void lineFollowing(int stopBtn) {

	while (stopBtn != 1) {

				if (SensorValue[irLeft] == 0) // left over white
		    {
		        motor[leftDrive] = -15;
		        motor[rightDrive] = 75 + 500 * (time1[T1] / 1000);
		    }
		    else if (SensorValue[irRight] == 0) // right over white
		    {
		        motor[leftDrive] = 85 + 900 * (time1[T1] / 1000);
		        motor[rightDrive] = -15;
		    }
		    else
		    {
		        motor[leftDrive] = 65;
		        motor[rightDrive] = 65;
		        clearTimer(T1);
		    }
	}

	stopDrivetrain();
}
