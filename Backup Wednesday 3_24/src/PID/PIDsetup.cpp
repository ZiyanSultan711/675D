#include "vex.h"
using namespace vex;

// PID CONTROLLER //

// Settings
double kP = 0.45;
double kI = 0.0;
double kD = 0.15;

double kPT = 0.5;
double kIT = 0.0;
double kDT = 0.35;

// Auton Settings
int desiredVal = 0;
int turnRightDesiredVal = 0;
int turnLeftDesiredVal = 0;
int turnDesiredVal = 0;

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

float driveSlow = 1.0;
float turnSlow = 0.8;

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

    if(desiredVal != 0 && turnDesiredVal == 0)
    {
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


      LB.spin(vex::directionType::fwd, (lateralMotorPower)*driveSlow, vex::velocityUnits::pct);
      RB.spin(vex::directionType::rev, (lateralMotorPower)*driveSlow, vex::velocityUnits::pct);
      LF.spin(vex::directionType::fwd, (lateralMotorPower)*driveSlow, vex::velocityUnits::pct);
      RF.spin(vex::directionType::rev, (lateralMotorPower)*driveSlow, vex::velocityUnits::pct);

      // Code
      prevError = error;
      task::sleep(10);
    }
    
    else if (desiredVal == 0 && turnDesiredVal != 0) 
    {
      // Turn Movement PID
      int LeftMotorAverage = (LFPos + LBPos)/2;
      int RightMotorAverage = (RFPos + RBPos)/2;
      int turnDiff = (LeftMotorAverage + RightMotorAverage)/2;

      // Potential
      errorT = turnDiff - turnDesiredVal;

      // Derivative
      derivativeT = errorT - prevErrorT;

      // Integral
      totalErrorT += errorT;

      double turnMotorPower = (errorT * kPT) + (derivativeT * kDT) + (totalErrorT * kIT);

      LB.spin(vex::directionType::rev, (turnMotorPower)*turnSlow, vex::velocityUnits::pct);
      RB.spin(vex::directionType::rev, (turnMotorPower)*turnSlow, vex::velocityUnits::pct);
      LF.spin(vex::directionType::rev, (turnMotorPower)*turnSlow, vex::velocityUnits::pct);
      RF.spin(vex::directionType::rev, (turnMotorPower)*turnSlow, vex::velocityUnits::pct);

      // Code
      prevErrorT = errorT;
      task::sleep(10);
    }
    
    else if(desiredVal == 0 && turnDesiredVal == 0)
    {
      LF.setBrake(brakeType::hold);
      LB.setBrake(brakeType::hold);
      RF.setBrake(brakeType::hold);
      RB.setBrake(brakeType::hold);
    }
    
  }

  return 1;
}


int turnPID()
{
  while(enableTurnPID)
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
    int turnDiff = (LeftMotorAverage + RightMotorAverage)/2;

    // Potential
    errorT = turnDiff - turnDesiredVal;

    // Derivative
    derivativeT = errorT - prevErrorT;

    // Integral
    totalErrorT += errorT;

    double turnMotorPower = (errorT * kPT) + (derivativeT * kDT) + (totalErrorT * kIT);

    float x = 0.6;
    LB.spin(vex::directionType::rev, (turnMotorPower)*x, vex::velocityUnits::pct);
    RB.spin(vex::directionType::rev, (turnMotorPower)*x, vex::velocityUnits::pct);
    LF.spin(vex::directionType::rev, (turnMotorPower)*x, vex::velocityUnits::pct);
    RF.spin(vex::directionType::rev, (turnMotorPower)*x, vex::velocityUnits::pct);

    // Code
    prevErrorT = errorT;
    task::sleep(10);
  }

  return 1;
}

int pointTurn2(double direction, double degrees, double v) { // function to perform a decelerated point turn based
                                                             // on the inertial sensor
  double kP = 0.4;
  double kI = 0.01;
  double kD = 1.4;
  int error;
  int prevError = 0;
  int derivative;
  int totalError = 0;
  double x = Inert.rotation(deg) + (direction * degrees);
  double y = Inert.rotation(deg);
  while (v > 0.01) {
    error = y - x;
    derivative = error - prevError;
    totalError += error;
    v = (error * kP + derivative * kD + totalError * kI);

    y = Inert.rotation(deg);
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print(x);
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print(y);
    LB.spin(directionType::fwd, v, pct);
    RB.spin(directionType::fwd, v, pct);
    LF.spin(directionType::fwd, v, pct);
    RF.spin(directionType::fwd, v, pct);
    task::sleep(40);
    prevError = error;
  }
  LB.stop(brakeType::hold);
  RB.stop(brakeType::hold);
  LF.stop(brakeType::hold);
  RF.stop(brakeType::hold);
  Controller1.Screen.print("stop");
  return 0;
}

////////////////////