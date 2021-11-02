// PID CONTROLLER //

// Settings
extern double kP;
extern double kI;
extern double kD;

extern double kPT;
extern double kIT;
extern double kDT;

// Auton Settings
extern int desiredVal;
extern int turnRightDesiredVal;
extern int turnLeftDesiredVal;
extern int turnDesiredVal;

extern int error;      // Sensor Value - Desired Value  : Positional Value
extern int prevError;  // Position 10ms Ago
extern int derivative; // Difference between Error and Previous Error  :
                       // Calculates Speed
extern int totalError; // totalError = totalError + error

extern int errorT;      // Sensor Value - Desired Value  : Positional Value
extern int prevErrorT;  // Position 20ms Ago
extern int derivativeT; // Difference between Error and Previous Error  :
                        // Calculates Speed
extern int totalErrorT; // totalError = totalError + error

// Variables Modified for Use
extern bool enableDrivePID;
extern bool enableTurnRightPID;
extern bool enableTurnPID;
extern bool resetDriveSensors;

extern float driveSlow;
extern float turnSlow;

extern int drivePID();
extern int turnPID();

extern int inertVal;

////////////////////