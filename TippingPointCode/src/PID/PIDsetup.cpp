#include "vex.h"
using namespace vex;

// PID CONTROLLER //

// Settings
double kP = 0.55;
double kI = 0.0;
double kD = 0.2;

//0.55, 0.1

double kPT = 0.45;
double kIT = 0.0;
double kDT = 0.4;
// Auton Settings
int desiredVal = 0;
int turnRightDesiredVal = 0;
int turnLeftDesiredVal = 0;
int turnDesiredVal = 0;
int turnAngleVal = 0;

int error;          // Sensor Value - Desired Value  : Positional Value
int prevError = 0;  // Position 10ms Ago
int derivative;     // Difference between Error and Previous Error  : Calculates
                    // Speed
int totalError = 0; // totalError = totalError + error

int errorT;         // Sensor Value - Desired Value  : Positional Value
int prevErrorT = 0; // Position 20ms Ago
int derivativeT;    // Difference between Error and Previous Error  : Calculates
                    // Speed
int totalErrorT = 0; // totalError = totalError + error

// Variables Modified for Use
bool enableDrivePID = false;
bool enableTurnRightPID = false;
bool enableTurnPID = false;
bool resetDriveSensors = false;

float driveSlow = 1;
float turnSlow = 0.8;

int drivePID() {
  while (enableDrivePID) {
    if (resetDriveSensors) {
      resetDriveSensors = false;

      fl.setPosition(0, degrees);
      fr.setPosition(0, degrees);
      br.setPosition(0, degrees);
      bl.setPosition(0, degrees);
    }

    int LFPos = fl.position(degrees);
    int RFPos = fr.position(degrees);
    int LBPos = bl.position(degrees);
    int RBPos = br.position(degrees);

    if (desiredVal != 0 && turnDesiredVal == 0) {
      // Lateral Movement PID
      int LeftMotorAverage = (LFPos + LBPos) / 2;
      int RightMotorAverage = (RFPos + RBPos) / 2;
      int averagePosition = (RightMotorAverage - LeftMotorAverage) / 2;

      // Potential
      error = averagePosition - desiredVal;

      // Derivative
      derivative = error - prevError;

      // Integral
      totalError += error;

      double lateralMotorPower =
          ((error * kP) + (derivative * kD) + (totalError * kI))/12;

      bl.spin(vex::directionType::fwd, (lateralMotorPower)*driveSlow,
              vex::voltageUnits::volt);
      br.spin(vex::directionType::rev, (lateralMotorPower)*driveSlow,
              vex::voltageUnits::volt);
      fl.spin(vex::directionType::fwd, (lateralMotorPower)*driveSlow,
              vex::voltageUnits::volt);
      fr.spin(vex::directionType::rev, (lateralMotorPower)*driveSlow,
              vex::voltageUnits::volt);

      // Code
      prevError = error;
      task::sleep(10);
    }

    else if (desiredVal == 0 && turnDesiredVal != 0) {
      // Turn Movement PID
      // int LeftMotorAverage = (LFPos + LBPos) / 2;
      // int RightMotorAverage = (RFPos + RBPos) / 2;

      int turnDiff = (LFPos + RFPos) / 2;

      // int turnDiff = (InertLeft.angle(deg) + InertRight.angle(deg)) / 2;
      // Controller1.Screen.clearScreen();
      // Controller1.Screen.setCursor(1, 1);
      // Controller1.Screen.print(InertLeft.rotation(deg));
      // Controller1.Screen.setCursor(2, 2);
      // Controller1.Screen.print(InertRight.rotation(deg));
      // Controller1.Screen.setCursor(3, 3);
      // Controller1.Screen.print(turnDiff);

      // Potential
      // errorT = -turnDiff + turnAngleVal;
      errorT = turnDiff - turnDesiredVal;

      // Derivative
      derivativeT = errorT - prevErrorT;

      // Integral
      totalErrorT += errorT;

      double turnMotorPower =
          (errorT * kPT) + (derivativeT * kDT) + (totalErrorT * kIT);

      bl.spin(vex::directionType::rev, (turnMotorPower)*turnSlow,
              vex::velocityUnits::pct);
      br.spin(vex::directionType::rev, (turnMotorPower)*turnSlow,
              vex::velocityUnits::pct);
      fl.spin(vex::directionType::rev, (turnMotorPower)*turnSlow,
              vex::velocityUnits::pct);
      fr.spin(vex::directionType::rev, (turnMotorPower)*turnSlow,
              vex::velocityUnits::pct);

      // Code
      prevErrorT = errorT;
      task::sleep(10);
    }

    else if (desiredVal == 0 && turnDesiredVal == 0) {
      fl.setBrake(brakeType::hold);
      bl.setBrake(brakeType::hold);
      fr.setBrake(brakeType::hold);
      br.setBrake(brakeType::hold);
    }
  }

  return 1;
}

/*
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

    double turnMotorPower = (errorT * kPT) + (derivativeT * kDT) + (totalErrorT
* kIT);

    float x = 0.6;
    LB.spin(vex::directionType::rev, (turnMotorPower)*x,
vex::velocityUnits::pct); RB.spin(vex::directionType::rev, (turnMotorPower)*x,
vex::velocityUnits::pct); LF.spin(vex::directionType::rev, (turnMotorPower)*x,
vex::velocityUnits::pct); RF.spin(vex::directionType::rev, (turnMotorPower)*x,
vex::velocityUnits::pct);

    // Code
    prevErrorT = errorT;
    task::sleep(10);
  }

  return 1;
}
*/
////////////////////