// ServoToggleFunction.c

void toggleServo(int port, int startPos, int endPos, bool &servoState, TVexJoysticks toggleButton)
{
    if (vexRT[toggleButton])
    {
        if (!servoState)
        {
            motor[port] = endPos;
            servoState = true;
        }
        else
        {
            motor[port] = startPos;
            servoState = false;
        }
    }
}

void moveServo(int servoPort, int targetPosition, TVexJoysticks button) {
    // Check if the button is pressed
    if (vexRT[button] == 1) {
        // Set the servo to the target position
        motor[servoPort] = targetPosition;
    }
}
