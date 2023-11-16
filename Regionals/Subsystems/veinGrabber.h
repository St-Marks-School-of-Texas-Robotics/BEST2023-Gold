
// Constants for servo positions
const int OPEN_JOINTL = -90;  // The open position for the claw
const int CLOSE_JOINTL = 100; // The closed position for the claw

const int OPEN_JOINTR = 107;  // The open position for the claw
const int CLOSE_JOINTR = -113; // The closed position for the claw

const int OPEN_CLAWL = 122;  // The open position for the claw
const int CLOSE_CLAWL = -123; // The closed position for the claw

const int OPEN_CLAWR = -120;  // The open position for the claw
const int CLOSE_CLAWR = 123; // The closed position for the claw

// Function to open both pairs of servos
void openJoint() {
  motor[leftJoint] = OPEN_JOINTL;
  motor[rightJoint] = OPEN_JOINTR;
}


void closeJoint() {
  motor[leftJoint] = CLOSE_JOINTL;
  motor[rightJoint] = CLOSE_JOINTR;
}

// Function to close both pairs of servos
void openClaw() {
  motor[leftClaw] = OPEN_CLAWL;
  motor[rightClaw] = OPEN_CLAWR;
}


void closeClaw() {
  motor[leftClaw] = CLOSE_CLAWL;
  motor[rightClaw] = CLOSE_CLAWR;
}
