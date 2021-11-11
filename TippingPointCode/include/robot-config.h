using namespace vex;

extern brain myBrain;

extern competition Competition;
extern controller Controller1;
extern motor fl;
extern motor bl;
extern motor fr;
extern motor br;
extern motor lift;
extern motor lift2;
extern motor mogo;
extern motor arm;
extern inertial InertLeft;
extern inertial InertRight;
extern rotation liftPot;
extern rotation mogoPot;
extern motor_group liftGroup;
extern limit limitFront;
extern limit limitBack;

extern bool mogoIsDown;
extern double mogoBottomPos;
extern double mogoTopPos;

extern double driveCurve(double input);

void vexcodeInit(void);
