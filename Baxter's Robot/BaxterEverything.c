#pragma config(Sensor, in1, potentiometer, sensorAnalog)
#pragma config(Motor, port9, armMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Sensor, dgtl3, irLeft, sensorDigitalIn)
#pragma config(Sensor, dgtl2, irRight, sensorDigitalIn)
#pragma config(Motor, port2, leftDrive, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor, port3, rightDrive, tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard!!*//

bool lineFollowingEnabled = false; // Flag to control line following mode

task main()
{
    const float kF = 34; // Proportional constant
    clearTimer(T1);

    while (true)
    {
        // Check if a joystick button is pressed to enable line following
        if (vexRT[Btn8U] == 1) // Use Btn8U as the start button (you can change this)
        {
            lineFollowingEnabled = true;
            clearTimer(T1);
        }

        // Check if a joystick button is pressed to disable line following
        if (vexRT[Btn8D] == 1) // Use Btn8D as the stop button (you can change this)
        {
            lineFollowingEnabled = false;
            motor[leftDrive] = 0; // Stop left motor
            motor[rightDrive] = 0; // Stop right motor
        }

        if (lineFollowingEnabled)
        {
            if (SensorValue[irLeft] == 0) // left over white
            {
                motor[leftDrive] = -15;
                motor[rightDrive] = 75 + 500 * (time1[T1] / 1000);
            }
            else if (SensorValue[irRight] == 0) // right over white
            {
                motor[leftDrive] = 85 + 900 * (time1[T1] / 1000);
                motor[rightDrive] = -15;
            }
            else
            {
                motor[leftDrive] = 80;
                motor[rightDrive] = 80;
                clearTimer(T1);
            }
        }
        else
        {
            // Manual driving mode
            // You can add your manual control code here using other joystick buttons and axes

            float leftPower = vexRT[Ch3] + vexRT[Ch1];
            float rightPower = vexRT[Ch3] - vexRT[Ch1];

            // Slow mode
            if (vexRT[Btn5U])
            {
                motor[leftDrive] = 0.3 * leftPower;
                motor[rightDrive] = 0.3 * rightPower;
            }
            else
            {
                motor[leftDrive] = leftPower;
                motor[rightDrive] = rightPower;
            }

            // Arm code
            int currentPosition = SensorValue[potentiometer];
            float ticksPerDegree = 4096 / 300;
            clearDebugStream();
            writeDebugStreamLine("Potentiometer Value: %d", currentPosition);
            float theta = (currentPosition - 2770) / ticksPerDegree;
            writeDebugStreamLine("theta: %.6f", theta);
            float ff = kF * cosDegrees(theta);
            writeDebugStreamLine("Feedforward Value: %.6f", ff);

            // Read the joystick's vertical axis value.
            int armValue;

            if (vexRT[Btn6U])
            {
                armValue = 70;
            }
            else if (vexRT[Btn6D])
            {
                armValue = -70;
            }
            else
            {
                armValue = 0;
            }

            int motorPower = armValue + ff;
            writeDebugStreamLine("Motor Power: %.6f", motorPower);
            motor[armMotor] = motorPower;
        }
    }
}
