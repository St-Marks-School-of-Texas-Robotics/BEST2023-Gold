
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




void lineFollowingLeft(bool stopBtn) {
    while (!stopBtn) { // Assuming stopBtn represents a button press
        if (SensorValue[irLeft] == 0) {
            // Left over white
            motor[leftDrive] = -5;
            motor[rightDrive] = 55 + 1000 * (time1[T1] / 1000);
        } else if (SensorValue[irRight] == 0) {
            // Right over white
            motor[leftDrive] = 65 + 1200 * (time1[T1] / 1000);
            motor[rightDrive] = -5;
        } else {
            // Neither left nor right over white
            motor[leftDrive] = 95;
            motor[rightDrive] = 95;
            clearTimer(T1);
        }
        // Read stop button state here and update stopBtn variable accordingly
        // Example: stopBtn = (VexRT[Btn8U] == 1);  // Assuming Btn8U is the stop button
        stopBtn = (vexRT[Btn7D] == 1);
    }
    stopDrivetrain();
}

void lineFollowingRight(bool stopBtn) {
    while (!stopBtn) { // Assuming stopBtn represents a button press
        if (SensorValue[irLeft] == 0) {
            // Left over white
            motor[leftDrive] = -5;
            motor[rightDrive] = 70 + 1200 * (time1[T1] / 1000);
        } else if (SensorValue[irRight] == 0) {
            // Right over white
            motor[leftDrive] = 55 + 1000 * (time1[T1] / 1000);
            motor[rightDrive] = -5;
        } else {
            // Neither left nor right over white
            motor[leftDrive] = 95;
            motor[rightDrive] = 95;
            clearTimer(T1);
        }
        // Read stop button state here and update stopBtn variable accordingly
        // Example: stopBtn = (VexRT[Btn8U] == 1);  // Assuming Btn8U is the stop button
        stopBtn = (vexRT[Btn7D] == 1);
    }
    stopDrivetrain();
}
