
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
