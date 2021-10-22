double kP;
double kI;
double kD;
double turnkP;
double turnkI;
double turnkD;
int maxTurnIntegral; // These cap the integrals
int maxIntegral;
int integralBound; //If error is outside the bounds, then apply the integral. This is a buffer with +-integralBound degrees

//Autonomous Settings
int desiredValue;
int desiredTurnValue;

int error; //SensorValue - DesiredValue : Position
int prevError; //Position 20 miliseconds ago
int derivative; // error - prevError : Speed
int totalError; //totalError = totalError + error

int turnError; //SensorValue - DesiredValue : Position
int turnPrevError; //Position 20 miliseconds ago
int turnDerivative; // error - prevError : Speed
int turnTotalError; //totalError = totalError + error

bool resetDriveSensors;

//Variables modified for use
bool enableDrivePID;

//Pasted from a C++ resource
double signnum_c(double x);

int drivePID();