
// PID constants
float kP = 1.0;  // Proportional constant
float kI = 0.1;  // Integral constant
float kD = 0.2;  // Derivative constant

// Variables for PID control
float setpoint = 0;  // Desired position
float error = 0;
float integral = 0;
float derivative = 0;
float lastError = 0;
int output = 0;

// Function to set the arm's target position
void setArmSetpoint(float target) {
  setpoint = target;
}

// Function to update the arm's position and apply PID control
void updateArm() {
  // Read the current position from the potentiometer
  float currentPosition = SensorValue[potentiometer];

  // Calculate the error
  error = setpoint - currentPosition;

  // Calculate the integral and derivative terms
  integral += error;
  derivative = error - lastError;

  // Calculate the output using PID control
  output = kP * error + kI * integral + kD * derivative;

  // Apply the output to the arm motor
  motor[armMotor] = output;

  // Update the last error
  lastError = error;
}

// Function to stop the arm motor
void stopArm() {
  motor[armMotor] = 0;
}
