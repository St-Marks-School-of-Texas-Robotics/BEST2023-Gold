
const float kP = 2; // Proportional constant
const float kF = 20; // Proportional constant


int setpoint = 870;

// Function to set the arm's target position
void setArmSetpoint(float target) {
  setpoint = target;
}

// Function to update the arm's position and apply PID control
void updateArm(int up, int down) {
  // Read the current position from the potentiometer
  int currentPosition = SensorValue[potentiometer];
  clearDebugStream();
  writeDebugStreamLine("Potentiometer Value: %d", currentPosition);

  float ticksPerDegree = 4096 / 300;

  float theta = (currentPosition - 870) / ticksPerDegree; // angle from horizontal

  float ff = kF * cosDegrees(theta);

  // Calculate the error
  float error = setpoint - currentPosition;

  // Calculate the output using PID control
  float output = kP * error + ff;

  // Apply the output to the arm motor

  if (up == 1) {
  	motor[leftArm] = 127;
  	motor[rightArm] = 127;
  	setpoint = currentPosition;
  	clearTimer(T2);
  } else if (down == 1) {
  	motor[leftArm] = -50;
  	motor[rightArm] = -50;
  	setpoint = currentPosition;
  	clearTimer(T2);
  } else {
  	motor[leftArm] = output;
  	motor[rightArm] = output;
  }



}

// Function to stop the arm motor
void nudgeUp() {
  setpoint += 2;
}

// Function to stop the arm motor
void nudgeDown() {
  setpoint -= 2;
}


// Function to stop the arm motor
void stopArm() {
  motor[leftArm] = 0;
  motor[rightArm] = 0;
}
