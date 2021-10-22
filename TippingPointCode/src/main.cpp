#include "vex.h"      //CHECK
using namespace vex;

void pre_auton(void) 
{
  vexcodeInit();
  Inert = vex::inertial(vex::PORT21);
  Inert.calibrate();
  // waits for the Inertial Sensor to calibrate
  while (Inert.isCalibrating()) {
    wait(100, msec);
  }
}

<<<<<<< HEAD
void autonomous(void) {
  /*
    task StartDrivePID(drivePID);
    enableDrivePID = true;
    resetDriveSensors = true;
    desiredVal = 0;
    turnDesiredVal = 98;
    resetDriveSensors = true;
  */

  topAuton();
  // botAuton();
  // skillAuton();
=======
void autonomous(void) 
{
/*
  task StartDrivePID(drivePID);
  enableDrivePID = true;
  resetDriveSensors = true;
  desiredVal = 0;
  turnDesiredVal = 98;
  resetDriveSensors = true;
*/

  //topAuton();
  //botAuton();
  //skillAuton();
>>>>>>> parent of 13b35a9 (start of macro)
}

// Booleans
bool mogoMacroBool = false;
bool mogoManualBool = false;
bool mogoIsDown = false;

int mogoCurve(double velocity) {
  while (true) {
    double dist = mogo.rotation(vex::rotationUnits::deg);
    if (dist < 400) {
      mogo.spin(vex::directionType::fwd, velocity*(20 + (50 * ((1900 + dist) / 600))),
                vex::velocityUnits::pct);
    } else {
      mogo.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
  }
  return 1;
}

void usercontrol(void) 
{
  enableDrivePID = false;
  enableTurnRightPID = false;
  while (1) 
  {
    fl.spin(vex::directionType::fwd, -Controller1.Axis3.value() - (Controller1.Axis1.value() * .5), vex::velocityUnits::pct);
    bl.spin(vex::directionType::rev, Controller1.Axis3.value() + (Controller1.Axis1.value() * .5), vex::velocityUnits::pct);
    fr.spin(vex::directionType::fwd, Controller1.Axis3.value() - (Controller1.Axis1.value() * .5), vex::velocityUnits::pct);
    br.spin(vex::directionType::rev, -Controller1.Axis3.value() + (Controller1.Axis1.value() * .5), vex::velocityUnits::pct); //drive code (turning is slowed to .7 cuz i suck but ishaan is good)

//mogo 
  if (Controller1.ButtonB.pressing())
  {
    //mogoCurve(1);
    mogo.spin(vex::directionType::fwd, 70, vex::velocityUnits::pct);
  }

<<<<<<< HEAD
// Macro Tasks
int mogoMacro() {
  if(mogoIsDown == false)
  {
    mogo.rotateTo(1150, rotationUnits::deg, 100, velocityUnits::pct);
    mogoMacroBool = false;
    mogoIsDown = true;
  }
  else if(mogoIsDown == true)
  {
    mogo.rotateTo(-15, rotationUnits::deg, 100, velocityUnits::pct);
    mogoMacroBool = false;
    mogoIsDown = false;
  }
  return 1;
}

int mogoManual()
{
  mogo.spin(directionType::fwd, -100, velocityUnits::pct);
  mogoManualBool = true;
  return 1;
}

// Functions that start the task
void startMogoMacro()
{
  mogoMacroBool = true;
  task::stop(mogoManual);
  task b(mogoMacro);
}

void startMogoManual()
{
  mogoManualBool = true;
  task::stop(mogoMacro);
  task c(mogoManual);
}

void usercontrol(void) {
  while (1) {
      fl.setBrake(brakeType::hold);
      bl.setBrake(brakeType::hold);
      fr.setBrake(brakeType::hold);
      br.setBrake(brakeType::hold);

    task a(driveFwd);
    
    // mogoMacros
    Controller1.ButtonB.pressed(startMogoMacro);
    //Controller1.ButtonX.pressed(startMogoManual);

    // mogo Manual
    /*if (Controller1.ButtonX.pressing() && Controller1.ButtonUp.pressing()) {
      // mogoCurve(-1);
      task::stop(mogoMacro);
      mogo.spin(vex::directionType::fwd, -100, vex::velocityUnits::pct);
    } else if(mogoMacroBool == false && !(Controller1.ButtonX.pressing() && Controller1.ButtonUp.pressing())) {
      mogo.stop();
      mogo.setBrake(brakeType::hold);
    }*/
=======
  else if (Controller1.ButtonX.pressing()) {
    //mogoCurve(-1);
    mogo.spin(vex::directionType::fwd, -70, vex::velocityUnits::pct);
  }
  else
  {
    mogo.stop();
    mogo.setBrake(brakeType::hold);
  }

//lift
  if (Controller1.ButtonR1.pressing())
  {
    lift.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  else if(Controller1.ButtonR2.pressing())
  {
    lift.spin(directionType::fwd, -100, velocityUnits::pct);
  }
  else {
    lift.stop();
    lift.setBrake(brakeType::hold);
  }
>>>>>>> parent of 13b35a9 (start of macro)

  //tail
  if (Controller1.ButtonUp.pressing()) {
    tail.spin(directionType::fwd, -30, velocityUnits::pct);
  }
  else if (Controller1.ButtonDown.pressing()) {
    tail.spin(directionType::fwd, 30, velocityUnits::pct);
  }
  else
  {
    tail.stop();
    tail.setBrake(brakeType::hold);
  }

  //arm
  if (Controller1.ButtonL2.pressing()) {
    arm.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  else if (Controller1.ButtonL1.pressing()) {
    arm.spin(directionType::fwd, -100, velocityUnits::pct);
  }
  else
  {
    arm.stop();
    arm.setBrake(brakeType::hold);
  }

  //drive hold button
  if(Controller1.ButtonLeft.pressing())
  {
    fl.stop();
    fl.setBrake(brakeType::hold);

<<<<<<< HEAD
}
=======
    bl.stop();
    bl.setBrake(brakeType::hold);

    fr.stop();
    fr.setBrake(brakeType::hold);

    br.stop();
    br.setBrake(brakeType::hold);
  }

  

    wait(20, msec); 
  }
>>>>>>> parent of 13b35a9 (start of macro)
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