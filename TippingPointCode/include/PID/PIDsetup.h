extern double kP;
extern double kI;
extern double kD;
extern double turnkP;
extern double turnkI;
extern double turnkD;
extern int maxTurnIntegral; // These cap the integrals
extern int maxIntegral;
extern int integralBound; //If error is outside the bounds, then apply the integral. This is a buffer with +-integralBound degrees

//Autonomous Settings
extern int desiredValue;
extern int desiredTurnValue;

extern int error; //SensorValue - DesiredValue : Position
extern int prevError; //Position 20 miliseconds ago
extern int derivative; // error - prevError : Speed
extern int totalError; //totalError = totalError + error

extern int turnError; //SensorValue - DesiredValue : Position
extern int turnPrevError; //Position 20 miliseconds ago
extern int turnDerivative; // error - prevError : Speed
extern int turnTotalError; //totalError = totalError + error

extern bool resetDriveSensors;

//Variables modified for use
extern bool enableDrivePID;

//Pasted from a C++ resource
extern double signnum_c(double x);

extern int drivePID();