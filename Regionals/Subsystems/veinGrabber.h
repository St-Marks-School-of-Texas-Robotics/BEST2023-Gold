
// Constants for servo positions
const int OPEN_JOINTL = -90;  // The open position for the claw
const int CLOSE_JOINTL = 100; // The closed position for the claw

const int OPEN_JOINTR = 107;  // The open position for the claw
const int CLOSE_JOINTR = -113; // The closed position for the claw

const int OPEN_CLAW = 122;  // The open position for the claw
const int CLOSE_CLAW = -123; // The closed position for the claw

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
  motor[leftJoint] = OPEN_CLAW;
  motor[rightJoint] = OPEN_CLAW;
}


void closeClaw() {
  motor[leftClaw] = CLOSE_CLAW;
  motor[rightClaw] = CLOSE_CLAW;
}
