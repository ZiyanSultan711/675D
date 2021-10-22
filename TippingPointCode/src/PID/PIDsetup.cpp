#include "vex.h"
using namespace vex;

// PID CONTROLLER //

//Settings
double kP = 0.0;
double kI = 0.0;
double kD = 0.0;
double turnkP = 0.0;
double turnkI = 0.0;
double turnkD = 0.0;
int maxTurnIntegral = 300; // These cap the integrals
int maxIntegral = 300;
int integralBound = 5; //If error is outside the bounds, then apply the integral. This is a buffer with +-integralBound degrees

//Autonomous Settings
int desiredValue = 200;
int desiredTurnValue = 0;

int error; //SensorValue - DesiredValue : Position
int prevError = 0; //Position 20 miliseconds ago
int derivative; // error - prevError : Speed
int totalError = 0; //totalError = totalError + error

int turnError; //SensorValue - DesiredValue : Position
int turnPrevError = 0; //Position 20 miliseconds ago
int turnDerivative; // error - prevError : Speed
int turnTotalError = 0; //totalError = totalError + error

bool resetDriveSensors = false;

//Variables modified for use
bool enableDrivePID = true;

//Pasted from a C++ resource
double signnum_c(double x) {
  if (x > 0.0) return 1.0;
  if (x < 0.0) return -1.0;
  return x;
}

int drivePID(){
  
  while(enableDrivePID){

    if (resetDriveSensors) {
      resetDriveSensors = false;
      fl.setPosition(0,degrees);
      fr.setPosition(0,degrees);
    }


    //Get the position of both motors
    int leftMotorPosition = fl.position(degrees);
    int rightMotorPosition = fr.position(degrees);

    ///////////////////////////////////////////
    //Lateral movement PID
    /////////////////////////////////////////////////////////////////////
    //Get average of the two motors
    int averagePosition = (rightMotorPosition - leftMotorPosition)/2;

    //Potential
    error = averagePosition - desiredValue;// swap ------------------------------------------------------------- 

    //Derivative
    derivative = error - prevError;

    //Integral
    if(abs(error) < integralBound){
    totalError+=error; 
    }  else {
    totalError = 0; 
    }
<<<<<<< HEAD
    //totalError += error;
=======
    
    else if (desiredVal == 0 && turnDesiredVal != 0) 
    {
      // Turn Movement PID
      //int LeftMotorAverage = (LFPos + LBPos)/2;
      //int RightMotorAverage = (RFPos + RBPos)/2;
      int turnDiff = inertVal;

      // Potential
      errorT = turnDiff - turnDesiredVal;
>>>>>>> parent of 8dac75c (small changes pt.2)

    //This would cap the integral
    totalError = abs(totalError) > maxIntegral ? signnum_c(totalError) * maxIntegral : totalError;

    double lateralMotorPower = error * kP + derivative * kD + totalError * kI;
    /////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////
    //Turning movement PID
    /////////////////////////////////////////////////////////////////////
    //Get average of the two motors
    int turnDifference = leftMotorPosition - rightMotorPosition;

    //Potential
    turnError = turnDifference - desiredTurnValue; // swap -------------------------------------------------------------

    //Derivative
    turnDerivative = turnError - turnPrevError;

    //Integral
    if(abs(error) < integralBound){
    turnTotalError+=turnError; 
    }  else {
    turnTotalError = 0; 
    }
    //turnTotalError += turnError;

    //This would cap the integral
    turnTotalError = abs(turnTotalError) > maxTurnIntegral ? signnum_c(turnTotalError) * maxTurnIntegral : turnTotalError;

    double turnMotorPower = turnError * turnkP + turnDerivative * turnkD + turnTotalError * turnkI;
    /////////////////////////////////////////////////////////////////////

    fl.spin(reverse, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    bl.spin(reverse, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    fr.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    br.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);


    

    prevError = error;
    turnPrevError = turnError;
    vex::task::sleep(20);

  }

  return 1;
}