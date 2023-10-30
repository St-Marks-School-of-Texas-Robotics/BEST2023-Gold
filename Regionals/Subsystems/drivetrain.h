
// Function to implement arcade drive
void arcadeDrive(int yJoystick, int xJoystick, int slow) {

	int leftMotorSpeed = yJoystick + xJoystick;
  int rightMotorSpeed = yJoystick - xJoystick;

	if (slow == 1) {
		motor[leftMotor] = 0.3 * leftMotorSpeed;
  	motor[rightMotor] = 0.3 * rightMotorSpeed;
	} else {
		motor[leftMotor] = leftMotorSpeed;
  	motor[rightMotor] = rightMotorSpeed;
	}



}

// Function to stop the drivetrain
void stopDrivetrain() {
  motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}
