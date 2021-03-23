#include "vex.h"
using namespace vex;

competition Competition;
controller Controller1 = vex::controller();
motor top = vex::motor(vex::PORT12, false); //600 rpm
motor bot = vex::motor(vex::PORT3, false); //600 rpm
motor leftintake = vex::motor(vex::PORT14, true); //600 rpm
motor rightintake = vex::motor(vex::PORT13, false); //600 rpm
inertial Inert = vex::inertial(vex::PORT10);

motor LB = vex::motor(vex::PORT17), LF = vex::motor(vex::PORT16);
motor RB = vex::motor(vex::PORT20), RF = vex::motor(vex::PORT18);

void pre_auton(void) 
{
  vexcodeInit();
}


// PID CONTROLLER //

// Settings
double kP = 0.35;
double kI = 0.0;
double kD = 0.15;

double kPT = 0.1;
double kIT = 0.0;
double kDT = 0.0;

// Auton Settings
int desiredVal = 200;
int turnRightDesiredVal = 0;
int turnLeftDesiredVal = 0;

int error; // Sensor Value - Desired Value  : Positional Value
int prevError = 0; // Position 10ms Ago
int derivative; // Difference between Error and Previous Error  : Calculates Speed
int totalError = 0; // totalError = totalError + error

int errorT; // Sensor Value - Desired Value  : Positional Value
int prevErrorT = 0; // Position 20ms Ago
int derivativeT; // Difference between Error and Previous Error  : Calculates Speed
int totalErrorT = 0; // totalError = totalError + error

// Variables Modified for Use
bool enableDrivePID = false;
bool enableTurnRightPID = false;
bool enableTurnPID = false;
bool resetDriveSensors = false;

int drivePID()
{
  while(enableDrivePID)
  {
    if(resetDriveSensors)
    {
      resetDriveSensors = false;

      LF.setPosition(0, degrees);
      RF.setPosition(0, degrees);
      RB.setPosition(0, degrees);
      LB.setPosition(0, degrees);
    }

    
    int LFPos = LF.position(degrees);
    int RFPos = RF.position(degrees);
    int LBPos = RF.position(degrees);
    int RBPos = RF.position(degrees);
    
    // Lateral Movement PID
    int LeftMotorAverage = (LFPos + LBPos)/2;
    int RightMotorAverage = (RFPos + RBPos)/2;
    int averagePosition = (LeftMotorAverage + RightMotorAverage)/2;

    // Potential
    error = averagePosition - desiredVal;

    // Derivative
    derivative = error - prevError;

    // Integral
    totalError += error;

    double lateralMotorPower = (error * kP) + (derivative * kD) + (totalError * kI);

    /*//Turning Movement PID
    int LeftMotorAverageT = (LFPos + LBPos)/2;
    int RightMotorAverageT = (RFPos + RBPos)/2;
    int turnDiff = (LeftMotorAverageT - RightMotorAverageT);

    // Potential
    errorT = turnDiff - turnDesiredVal;

    // Derivative
    derivativeT = errorT - prevErrorT;

    // Integral
    totalErrorT += errorT;

    double turnMotorPower = (errorT * kPT) + (derivativeT * kDT) + (totalErrorT * kIT);
    */
    
    LB.spin(vex::directionType::fwd, (lateralMotorPower), vex::velocityUnits::pct);
    RB.spin(vex::directionType::rev, (lateralMotorPower), vex::velocityUnits::pct);
    LF.spin(vex::directionType::fwd, (lateralMotorPower), vex::velocityUnits::pct);
    RF.spin(vex::directionType::rev, (lateralMotorPower), vex::velocityUnits::pct);

    // Code
    prevError = error;
    task::sleep(10);
  }

  return 1;
}

/*
int turnRightPID()
{
  while(enableTurnRightPID)
  {
    if(resetDriveSensors)
    {
      resetDriveSensors = false;

      LF.setPosition(0, degrees);
      RF.setPosition(0, degrees);
      RB.setPosition(0, degrees);
      LB.setPosition(0, degrees);
    }

    
    //int LFPos = LF.position(degrees);
    int RFPos = RF.position(degrees);
    //int LBPos = RF.position(degrees);
    int RBPos = RF.position(degrees);
    
    // Lateral Movement PID
    //int LeftMotorAverage = (LFPos + LBPos)/2;
    int RightMotorAverage = (RFPos + RBPos)/2;
    int averagePosition = RightMotorAverage;

    // Potential
    error = turnRightDesiredVal-averagePosition;

    // Derivative
    derivative = error - prevError;

    // Integral
    totalError += error;

    double lateralMotorPower = (error * kPT) + (derivative * kDT) + (totalError * kIT);

    Turning Movement PID
    int LeftMotorAverageT = (LFPos + LBPos)/2;
    int RightMotorAverageT = (RFPos + RBPos)/2;
    int turnDiff = (LeftMotorAverageT - RightMotorAverageT);

    // Potential
    errorT = turnDiff - turnDesiredVal;

    // Derivative
    derivativeT = errorT - prevErrorT;

    // Integral
    totalErrorT += errorT;

    double turnMotorPower = (errorT * kPT) + (derivativeT * kDT) + (totalErrorT * kIT);
    
    //LB.spin(vex::directionType::fwd, (lateralMotorPower), vex::velocityUnits::pct);
    RB.spin(vex::directionType::rev, turnRightDesiredVal, vex::velocityUnits::pct);
    //LF.spin(vex::directionType::fwd, (lateralMotorPower), vex::velocityUnits::pct);
    RF.spin(vex::directionType::rev, turnRightDesiredVal, vex::velocityUnits::pct);

    // Code
    prevError = error;
    task::sleep(10);
  }

  return 1;
}
*/

int pointTurnFunction(double direction, double degrees,
               double v) { // function to perform a decelerated point turn based
                           // on the inertial sensor
  double x = Inert.rotation(deg) + (direction * degrees);
  double y = Inert.rotation(deg);
  while (enableTurnPID) {
    errorT = y - x;
    derivativeT = errorT - prevErrorT;
    totalErrorT += errorT;
    v = (errorT * kPT + derivativeT * kDT + totalErrorT * kIT);

    y = Inert.rotation(deg);
    LB.spin(directionType::fwd, v, pct);
    RB.spin(directionType::rev, v, pct);
    LF.spin(directionType::fwd, v, pct);
    RF.spin(directionType::rev, v, pct);
    
    prevErrorT = errorT;
    task::sleep(10);
  }
  LB.stop(brakeType::hold);
  RB.stop(brakeType::hold);
  LF.stop(brakeType::hold);
  RF.stop(brakeType::hold);
  return 1;
}


////////////////////


void oneballauto(double distance, double velocity)
{
  LB.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  LF.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RB.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RF.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct); //drive fwd

  vex::task::sleep(1500);
  top.startRotateFor(750, rotationUnits::deg, 100, vex::velocityUnits::pct);
  bot.startRotateFor(750, rotationUnits::deg, 100, vex::velocityUnits::pct); //run the top and bot roller to score ball
  leftintake.startRotateFor(1750, rotationUnits::deg, 70, velocityUnits::pct); //intake descores 2 balls from the goal
  rightintake.startRotateFor(1750, rotationUnits::deg, 70, velocityUnits::pct);

  vex::task::sleep(1000);
  LB.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct); //drive back
  LF.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RB.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RF.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);

  
}

void LRTauto(void)
{
  int x = 175;
  LB.startRotateFor(x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  LF.startRotateFor(x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);//bwd
  vex::task::sleep(775);

  x = 90;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);//turn right
  vex::task::sleep(800);

  x = 315;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  leftintake.startRotateFor(570, rotationUnits::deg, 50, velocityUnits::pct);
  rightintake.startRotateFor(570, rotationUnits::deg, 50, velocityUnits::pct);
  top.startRotateFor(1600, rotationUnits::deg, 100, vex::velocityUnits::pct); //fwd intake drive
  vex::task::sleep(775);

  bot.startRotateFor(300, rotationUnits::deg, 100, vex::velocityUnits::pct); //score
  LB.stop(brakeType::coast);
  LF.stop(brakeType::coast);
  RB.stop(brakeType::coast);
  RF.stop(brakeType::coast);
  vex::task::sleep(500);

  x = 1160;
  LB.startRotateFor(x+260, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  LF.startRotateFor(x+260, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 80, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 80, vex::velocityUnits::pct); //curve turn
  vex::task::sleep(2650);

  x = 450;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 37, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 37, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 43, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 43, vex::velocityUnits::pct);
  top.startRotateFor(1500, rotationUnits::deg, 100, vex::velocityUnits::pct); //fwd
  vex::task::sleep(500);

  bot.startRotateFor(500, rotationUnits::deg, 100, vex::velocityUnits::pct); //score
  vex::task::sleep(700);

  x = 175;
  LB.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  LF.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct); //bwd
  vex::task::sleep(800);

  x = -220;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct); //turn
  vex::task::sleep(775);

  x = 840;
  LB.startRotateFor(-x - 150, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  LF.startRotateFor(-x - 150, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 55, vex::velocityUnits::pct); //curve 2
  vex::task::sleep(1700);

  x = 400;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  leftintake.startRotateFor(700, rotationUnits::deg, 70, velocityUnits::pct);
  rightintake.startRotateFor(700, rotationUnits::deg, 70, velocityUnits::pct);
  top.startRotateFor(2000, rotationUnits::deg, 100, vex::velocityUnits::pct);
  bot.startRotateFor(2000, rotationUnits::deg, 100, vex::velocityUnits::pct);
  vex::task::sleep(1650);


  leftintake.startRotateFor(-800, rotationUnits::deg, 70, velocityUnits::pct);
  rightintake.startRotateFor(-800, rotationUnits::deg, 70, velocityUnits::pct);
  LB.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  LF.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  vex::task::sleep(1500);

}

void autonomous(void) 
{
  //oneballauto(300, 50);
  //LRTauto();
  
  task StartDrivePID(drivePID);
  task StartTurnRightPID(turnRightPID);
  enableDrivePID = true;
  enableTurnRightPID = false;

  resetDriveSensors = true;
  desiredVal = 400;
  resetDriveSensors = true;
  //turnRightDesiredVal = 100;
  task::sleep(1000);

  /*
  resetDriveSensors = true;
  desiredVal = -100;
  turnDesiredVal = 100;
  resetDriveSensors = true;
  task::sleep(500);
  desiredVal = 100;
  resetDriveSensors = true;
  desiredVal = -200;
  turnDesiredVal = 200;
  resetDriveSensors = true;
  task::sleep(500);

  desiredVal = -600;
  turnDesiredVal = -200;
  resetDriveSensors = true;
  task::sleep(500);
  desiredVal = 200;
  resetDriveSensors = true;
  task::sleep(500);
  desiredVal = -500;
  resetDriveSensors = true;
  task::sleep(500);
  desiredVal = 500;
  turnDesiredVal = -200;
  resetDriveSensors = true;
  task::sleep(500);

  turnDesiredVal = 100;
  desiredVal = 100;
  resetDriveSensors = true;
  task::sleep(500);
  desiredVal = -200;
  resetDriveSensors = true;
  task::sleep(500);
  */
}


void usercontrol(void) 
{
  enableDrivePID = false;
  enableTurnRightPID = false;
  while (1) 
  {
    LB.spin(vex::directionType::fwd, -Controller1.Axis3.value() - (Controller1.Axis1.value() * .65), vex::velocityUnits::pct);
    RB.spin(vex::directionType::rev, -Controller1.Axis3.value() + (Controller1.Axis1.value() * .65), vex::velocityUnits::pct);
    LF.spin(vex::directionType::fwd, -Controller1.Axis3.value() - (Controller1.Axis1.value() * .65), vex::velocityUnits::pct);
    RF.spin(vex::directionType::rev, -Controller1.Axis3.value() + (Controller1.Axis1.value() * .65), vex::velocityUnits::pct); //drive code (turning is slowed to .7 cuz i suck but ishaan is good)
    
  if (Controller1.ButtonL1.pressing())
  {
    top.spin(vex::directionType::fwd, 97, velocityUnits::pct);
  }
  else if (Controller1.ButtonL2.pressing())
  {
    top.spin(vex::directionType::rev, 100, velocityUnits::pct);
  }
  else 
  {
    top.stop();
    top.setBrake(brakeType::coast);
  } // this makes left triggers control the top roller only. i never really used this but it was there just incase
  

  if (Controller1.ButtonX.pressing())//this entire section seems complicated but its simple. x and a controlled both top and bottom. i used most frequently to score because that worked the best
  {
    top.spin(vex::directionType::fwd, 97, velocityUnits::pct);
    bot.spin(vex::directionType::fwd, 100, velocityUnits::pct);
  }
  else if (Controller1.ButtonB.pressing())
  {
    top.spin(vex::directionType::rev, 100, velocityUnits::pct);
    bot.spin(vex::directionType::rev, 100, velocityUnits::pct);
  }
  else if (Controller1.ButtonR1.pressing()) //right triggers controlled intake. weird thing about the intake is that it worked best when intakes AND bottom rollers run at the same time
  {
    leftintake.spin(vex::directionType::fwd, 70, velocityUnits::pct);
    rightintake.spin(vex::directionType::fwd, 70, velocityUnits::pct);
    bot.spin(vex::directionType::fwd, 100, velocityUnits::pct);

  }
  else if (Controller1.ButtonR2.pressing())
  {
    leftintake.spin(vex::directionType::rev, 70, velocityUnits::pct);
    rightintake.spin(vex::directionType::rev, 70, velocityUnits::pct);
    bot.spin(vex::directionType::rev, 100, velocityUnits::pct);

  }
  else 
  {
    leftintake.stop();
    rightintake.stop();
    bot.stop();
    leftintake.setBrake(brakeType::coast);
    rightintake.setBrake(brakeType::coast);
  }

    wait(20, msec); 
  }
}


int main() 
{
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}