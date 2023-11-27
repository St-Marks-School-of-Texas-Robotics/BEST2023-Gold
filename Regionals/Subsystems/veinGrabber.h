
// Constants for servo positions
const int OPEN_JOINTL = -72;  // The open position for the claw
const int CLOSE_JOINTL = 123; // The closed position for the claw

const int OPEN_JOINTR = 82;  // The open position for the claw
const int CLOSE_JOINTR = -123; // The closed position for the claw

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
void openLeftClaw() {
  motor[leftClaw] = OPEN_CLAWL;
}
void openRightClaw() {
  motor[rightClaw] = OPEN_CLAWR;
}


void closeClaw() {
  motor[leftClaw] = CLOSE_CLAWL;
  motor[rightClaw] = CLOSE_CLAWR;
}

void closeLeftClaw() {
  motor[leftClaw] = CLOSE_CLAWL;
}

void closeRightClaw() {
  motor[rightClaw] = CLOSE_CLAWR;
}
