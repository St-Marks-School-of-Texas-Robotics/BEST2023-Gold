
const float kP = 1.3; // Proportional constant
const float kF = 30; // Proportional constant


int setpoint = 1250;

// Function to set the arm's target position
void setArmSetpoint(float target) {
  setpoint = target;
}

// Function to update the arm's position and apply PID control
void updateArm() {
  // Read the current position from the potentiometer
  int currentPosition = SensorValue[potentiometer];
  float ticksPerDegree = 4096 / 300;

  float theta = (currentPosition - 1250) / ticksPerDegree; // angle from horizontal

  float ff = kF * cosDegrees(theta);

  // Calculate the error
  float error = setpoint - currentPosition;

  // Calculate the output using PID control
  float output = kP * error + ff;

  // Apply the output to the arm motor
  motor[armMotor] = output;

}

// Function to stop the arm motor
void nudgeUp() {
  setpoint += 2;
}

// Function to stop the arm motor
void nudgeDown() {
  setpoint -= 2;
}
