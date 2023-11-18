
// Function to implement arcade drive
void arcadeDrive(int yJoystick, int xJoystick, int slow) {

	int leftMotorSpeed = yJoystick + xJoystick;
  int rightMotorSpeed = yJoystick - xJoystick;

	if (slow == 1) {
		motor[leftDrive] = 0.4 * leftMotorSpeed;
  	motor[rightDrive] = 0.4 * rightMotorSpeed;
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




void lineFollowingRight(bool stopBtn) {
    while (!stopBtn) { // Assuming stopBtn represents a button press
        if (SensorValue[irLeft] == 0) {
            // Left over white
            motor[leftDrive] = -29 - 900 * (time1[T1] / 1000);
            motor[rightDrive] = 85 + 1400 * (time1[T1] / 1000);
        } else if (SensorValue[irRight] == 0) {
            // Right over white
            motor[leftDrive] = 55 + 1000 * (time1[T1] / 1000);
            motor[rightDrive] = -15;
        } else {
            // Neither left nor right over white
            motor[leftDrive] = 53;
            motor[rightDrive] = 56;
            clearTimer(T1);
        }
        // Read stop button state here and update stopBtn variable accordingly
        // Example: stopBtn = (VexRT[Btn8U] == 1);  // Assuming Btn8U is the stop button
        stopBtn = (vexRT[Btn7D] == 1);
    }
    stopDrivetrain();
}

void lineFollowingLeft(bool stopBtn) {
    while (!stopBtn) { // Assuming stopBtn represents a button press
        if (SensorValue[irLeft] == 0) {
            // Left over white
            motor[leftDrive] = -19;
            motor[rightDrive] = 78 + 1400 * (time1[T1] / 1000);
        } else if (SensorValue[irRight] == 0) {
            // Right over white
            motor[leftDrive] = 55 + 200 * (time1[T1] / 1000);
            motor[rightDrive] = -15;
        } else {
            // Neither left nor right over white
            motor[leftDrive] = 61;
            motor[rightDrive] = 58;
            clearTimer(T1);
        }
        // Read stop button state here and update stopBtn variable accordingly
        // Example: stopBtn = (VexRT[Btn8U] == 1);  // Assuming Btn8U is the stop button
        stopBtn = (vexRT[Btn7D] == 1);
    }
    stopDrivetrain();
}
