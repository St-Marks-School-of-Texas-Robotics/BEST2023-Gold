
const float kP = 10; // Proportional constant
const float kF = 34; // Proportional constant


int setpoint;

// Function to set the arm's target position
void setArmSetpoint(float target) {
  setpoint = target;
}

// Function to update the arm's position and apply PID control
void updateArm() {
  // Read the current position from the potentiometer
  int currentPosition = SensorValue[potentiometer];
  float ticksPerDegree = 4096 / 300;

  float theta = (currentPosition - 2770) / ticksPerDegree;

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
  setpoint += 5;
}

// Function to stop the arm motor
void nudgeDown() {
  setpoint -= 5;
}
