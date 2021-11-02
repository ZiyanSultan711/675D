#include "vex.h" //CHECK
using namespace vex;
//DATE: 11/02/21
//TIME: 4:50 PM


// variables
bool mogoIsDown = false;
bool driveLock = false;
bool liftManual = true;

double opControlDriveSlow = 0.8;

double liftBottomPos = 0;
double liftTopPos = -840;
double mogoBottomPos = 0;
double mogoTopPos = 120;

motor_group liftGroup(lift, lift2);

void pre_auton(void) {
  vexcodeInit();
  fl.setBrake(brakeType::coast);
  bl.setBrake(brakeType::coast);
  fr.setBrake(brakeType::coast);
  mogo.setBrake(brakeType::coast);
  lift.setBrake(brakeType::hold);
  lift2.setBrake(brakeType::hold);
  arm.setBrake(brakeType::hold);

  while( InertLeft.isCalibrating() )
  { wait(10,msec); }
  while( InertRight.isCalibrating() )
  { wait(10,msec); }

  Controller1.rumble("-");
}


void autonomous(void) {
  topAuton();
  // botAuton();
  // skillAuton();
  // scrapautoblue();
  // scrapautored();
}


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
            -Controller1.Axis3.value() - (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
    bl.spin(vex::directionType::rev,
            Controller1.Axis3.value() + (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
    fr.spin(vex::directionType::fwd,
            Controller1.Axis3.value() - (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
    br.spin(vex::directionType::rev,
            -Controller1.Axis3.value() + (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
  }
  task::sleep(100);
  return 1;
}

// Macro Tasks
int mogoMacro() {
  if(mogoIsDown == false)
  {
    mogo.rotateTo(1150, rotationUnits::deg, 100, velocityUnits::pct);
    mogoIsDown = true;
  }
  else if(mogoIsDown == true)
  {
    mogo.rotateTo(-15, rotationUnits::deg, 100, velocityUnits::pct);
    mogoIsDown = false;
  }
  task::sleep(100);
  return 1;
}

int liftMacro(){
  liftManual = false;
  while (lift.rotation(deg) > 0 )
  {
    liftGroup.spin(directionType::fwd, -100, velocityUnits::pct);
  }
  //lift.startRotateTo(0, rotationUnits::deg, -100, velocityUnits::pct);
  //liftGroup.rotateTo(-10, rotationUnits::deg, -100, velocityUnits::pct);
  liftManual = true;
  task::sleep(100);
  return 1;
}

// Functions that start the task
void startMogoMacro()
{
  task b(mogoMacro);
}

void startLiftMacro()
{
  task lift(liftMacro);
  Controller1.rumble("-");
}

void switchDriveLock()
{
  if(driveLock)
  {
    driveLock = false;
    Controller1.rumble("-");
  }
    
  else if(driveLock == false)
  {
    driveLock = true;
    Controller1.rumble("--");
  }
    
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
      task::sleep(100);
    }
    else if(driveLock == true)
    {
      fl.setBrake(brakeType::hold);
      bl.setBrake(brakeType::hold);
      fr.setBrake(brakeType::hold);
      br.setBrake(brakeType::hold);
      task::sleep(100);
    }
    Controller1.ButtonY.pressed(switchDriveLock);
    Controller1.ButtonB.pressed(startMogoMacro);
    Controller1.ButtonA.pressed(startLiftMacro);

    task a(driveFwd);
    
    // mogoMacros

    // lift
    if(liftManual == true)
    {
      if (Controller1.ButtonR1.pressing()) {
        lift.spin(directionType::fwd, 100, velocityUnits::pct);
        lift2.spin(directionType::fwd, 100, velocityUnits::pct);
      } else if (Controller1.ButtonR2.pressing()) {
        lift.spin(directionType::fwd, -90, velocityUnits::pct);
        lift2.spin(directionType::fwd, -90, velocityUnits::pct);
      } else {
        lift.stop();
        lift2.stop();
        lift.setBrake(brakeType::hold);
        lift2.setBrake(brakeType::hold);
      }
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

    task::sleep(100);

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