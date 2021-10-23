#include "vex.h" //CHECK
using namespace vex;
//DATE: 10/18
//TIME: 1:35 PM

void pre_auton(void) {
  vexcodeInit();
}

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
  // scrapautoblue();
  // scrapautored();
}

// Booleans
bool mogoMacroBool = false;
bool mogoManualBool = false;
bool mogoIsDown = false;
bool driveLock = false;

int mogoCurve(double velocity) {
  while (true) {
    double dist = mogo.rotation(vex::rotationUnits::deg);
    if (dist < 400) {
      mogo.spin(vex::directionType::fwd,
                velocity * (20 + (50 * ((1900 + dist) / 600))),
                vex::velocityUnits::pct);
    } else {
      mogo.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
  }
  return 1;
}

int driveFwd() {
  while (true) {
    fl.spin(vex::directionType::fwd,
            -Controller1.Axis3.value() - (Controller1.Axis1.value() * .5),
            vex::velocityUnits::pct);
    bl.spin(vex::directionType::rev,
            Controller1.Axis3.value() + (Controller1.Axis1.value() * .5),
            vex::velocityUnits::pct);
    fr.spin(vex::directionType::fwd,
            Controller1.Axis3.value() - (Controller1.Axis1.value() * .5),
            vex::velocityUnits::pct);
    br.spin(vex::directionType::rev,
            -Controller1.Axis3.value() + (Controller1.Axis1.value() * .5),
            vex::velocityUnits::pct);
  }
  return 1;
}

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

void switchDriveLock()
{
  Controller1.rumble("-");
  if(driveLock)
    driveLock = false;
  else if(driveLock == false)
    driveLock = true;
}

void usercontrol(void) {
  while (1) {
    task::stop(drivePID);
    enableDrivePID = false;
    if(driveLock == false)
    {
      fl.setBrake(brakeType::coast);
      bl.setBrake(brakeType::coast);
      fr.setBrake(brakeType::coast);
      br.setBrake(brakeType::coast);
    }
    else if(driveLock == true)
    {
      fl.setBrake(brakeType::brake);
      bl.setBrake(brakeType::brake);
      fr.setBrake(brakeType::brake);
      br.setBrake(brakeType::brake);
    }
    Controller1.ButtonLeft.pressed(switchDriveLock);

    task a(driveFwd);
    
    // mogoMacros
    Controller1.ButtonB.pressed(startMogoMacro);

    // lift
    if (Controller1.ButtonR1.pressing()) {
      lift.spin(directionType::fwd, 100, velocityUnits::pct);
    } else if (Controller1.ButtonR2.pressing()) {
      lift.spin(directionType::fwd, -100, velocityUnits::pct);
    } else {
      lift.stop();
      lift.setBrake(brakeType::hold);
    }

    // tail
    if (Controller1.ButtonUp.pressing()) {
      tail.spin(directionType::fwd, -30, velocityUnits::pct);
    } else if (Controller1.ButtonDown.pressing()) {
      tail.spin(directionType::fwd, 30, velocityUnits::pct);
    } else {
      tail.stop();
      tail.setBrake(brakeType::hold);
    }

    // arm
    if (Controller1.ButtonL2.pressing()) {
      arm.spin(directionType::fwd, 100, velocityUnits::pct);
    } else if (Controller1.ButtonL1.pressing()) {
      arm.spin(directionType::fwd, -100, velocityUnits::pct);
    } else {
      arm.stop();
      arm.setBrake(brakeType::hold);
    }

}
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}