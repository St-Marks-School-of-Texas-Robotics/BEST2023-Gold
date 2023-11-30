
// Function to implement arcade drive
void arcadeDrive(int yJoystick, int xJoystick, int slow) {

/*
	float yValue = (yJoystick / 127.0) * (abs(yJoystick) / 127) * 127;
	float xValue = (xJoystick / 127.0) * (abs(xJoystick) / 127) * 127;
*/
	float yValue = yJoystick;
	float xValue = xJoystick;


	float leftMotorSpeed;
  float rightMotorSpeed;

	if (slow == 1) {
		leftMotorSpeed = 0.4* yValue + 0.3* xValue;
		rightMotorSpeed = 0.4* yValue - 0.3* xValue;
	} else {
		leftMotorSpeed = 0.98*yValue + xValue;
		rightMotorSpeed = yValue - xValue;
	}

	motor[leftDrive] = leftMotorSpeed;
  motor[rightDrive] = rightMotorSpeed;

}


// Function to stop the drivetrain
void stopDrivetrain() {
  motor[leftDrive] = 0;
  motor[rightDrive] = 0;
}




void lineFollowingRight(bool stopBtn) {
    while (!stopBtn) { // Assuming stopBtn represents a button press

    		updateArm(0,0); // Update the arm position using the PID controller

        if (SensorValue[irLeft] == 0) {
            // Left over white
            motor[leftDrive] = 20 + 1800 * (time1[T1] / 1000);
            motor[rightDrive] = -50 - 2500 * (time1[T1] / 1000);
        } else if (SensorValue[irRight] == 0) {
            // Right over white
            motor[leftDrive] = -43 - 750 * (time1[T1] / 1000);
            motor[rightDrive] = 13 + 1000 * (time1[T1] / 1000);
        } else {
            // Neither left nor right over white
            motor[leftDrive] = -46;
            motor[rightDrive] = -47;
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

    		updateArm(0,0); // Update the arm position using the PID controller

        if (SensorValue[irLeft] == 0) {
            // Left over white
            motor[leftDrive] = 18;
            motor[rightDrive] = -55 - 400 * (time1[T1] / 1000);
        } else if (SensorValue[irRight] == 0) {
            // Right over white
            motor[leftDrive] = -60 - 1400 * (time1[T1] / 1000);
            motor[rightDrive] = 20 + 800 * (time1[T1] / 1000);
        } else {
            // Neither left nor right over white
            motor[leftDrive] = -115;
            motor[rightDrive] = -127;
            clearTimer(T1);
        }
        // Read stop button state here and update stopBtn variable accordingly
        // Example: stopBtn = (VexRT[Btn8U] == 1);  // Assuming Btn8U is the stop button
        stopBtn = (vexRT[Btn7D] == 1);
    }
    stopDrivetrain();
}


void lineFollowingSlow(bool stopBtn) {
    while (!stopBtn) { // Assuming stopBtn represents a button press

    		updateArm(0,0); // Update the arm position using the PID controller

        if (SensorValue[irLeft] == 0) {
            // Left over white
            motor[leftDrive] = 20 + 1500 * (time1[T1] / 1000);
            motor[rightDrive] = -50 - 2200 * (time1[T1] / 1000);
        } else if (SensorValue[irRight] == 0) {
            // Right over white
            motor[leftDrive] = -43 - 600 * (time1[T1] / 1000);
            motor[rightDrive] = 13 + 900 * (time1[T1] / 1000);
        } else {
            // Neither left nor right over white
            motor[leftDrive] = -39;
            motor[rightDrive] = -38;
            clearTimer(T1);
        }
        // Read stop button state here and update stopBtn variable accordingly
        // Example: stopBtn = (VexRT[Btn8U] == 1);  // Assuming Btn8U is the stop button
        stopBtn = (vexRT[Btn7D] == 1);
    }
    stopDrivetrain();
}
