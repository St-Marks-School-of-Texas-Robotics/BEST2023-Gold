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

        // Add a slight delay to prevent rapid toggling
        wait1Msec(300);
    }
}
