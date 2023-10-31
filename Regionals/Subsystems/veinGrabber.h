
// Constants for servo positions
const int OPEN_JOINT = 127;  // The open position for the claw
const int CLOSE_JOINT = 0; // The closed position for the claw

const int OPEN_CLAW = 127;  // The open position for the claw
const int CLOSE_CLAW = 0; // The closed position for the claw

// Function to open both pairs of servos
void openJoint() {
  motor[leftJoint] = OPEN_JOINT;
  motor[rightJoint] = OPEN_JOINT;
}


void closeJoint() {
  motor[leftJoint] = CLOSE_JOINT;
  motor[rightJoint] = CLOSE_JOINT;
}

// Function to close both pairs of servos
void openClaw() {
  motor[leftJoint] = OPEN_CLAW;
  motor[rightJoint] = OPEN_CLAW;
}


void closeClaw() {
  motor[leftClaw] = CLOSE_CLAW;
  motor[rightClaw] = CLOSE_CLAW;
}


void toggleClaw(int port, int startPos, int endPos, bool &servoState, TVexJoysticks toggleButton)
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
