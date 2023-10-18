#pragma config(Sensor, in2,    potentiometer,  sensorAnalog)
#pragma config(Motor,  port2,           armMotor,      tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Constants for PID control
const float kP = 0.5; // Proportional constant
const float kI = 0.0; // Integral constant
const float kD = 0.0; // Derivative constant

int targetPosition = 0; // Set your desired arm position
int error = 0;
int integral = 0;
int derivative = 0;
int lastError = 0;

task main()
{
    while (true)
    {
        // Read the potentiometer value
        int currentPosition = SensorValue[potentiometer];

        clearDebugStream();
        writeDebugStreamLine("Potentiometer Value: %d", currentPosition);

        // Calculate the error
        error = targetPosition - currentPosition;

        // Calculate the integral term (optional)
        integral += error;

        // Calculate the derivative term (optional)
        derivative = error - lastError;

        // Calculate the motor power using PID control
        int motorPower = (kP * error) + (kI * integral) + (kD * derivative);

        // Apply the motor power with a cap to prevent excessive speed
        if (motorPower > 127)
            motorPower = 127;
        if (motorPower < -127)
            motorPower = -127;

        //motor[armMotor] = motorPower;

        // Update the last error
        lastError = error;

        // Optional: Add a condition to break out of the loop when you reach the target position
        if (abs(error) < 10) // Adjust the threshold as needed
        {
            motor[armMotor] = 0;
            //break;
        }

        // Allow some time for the loop to run (adjust as needed)
        //wait1Msec(20);

    }
}
