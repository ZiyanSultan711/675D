#include "vex.h"
using namespace vex;

// PID CONTROLLER //

// Settings
double kP = 0.45;
double kI = 0.0;
double kD = 0.15;

double kPT = 0.4;
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

////////////////////