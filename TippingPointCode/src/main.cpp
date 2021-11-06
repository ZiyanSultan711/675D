#include "vex.h" //CHECK
using namespace vex;
// DATE: 11/04/21
// TIME: 1:23 PM

// variables
bool mogoIsDown = false;
bool driveLock = false;
bool liftManual = true;

double opControlDriveSlow = 0.7;

double mogoBottomPos = 106;
double mogoTopPos = 5;

motor_group liftGroup(lift, lift2);

void pre_auton(void) {
  vexcodeInit();
  br.setBrake(brakeType::coast);
  fl.setBrake(brakeType::coast);
  bl.setBrake(brakeType::coast);
  fr.setBrake(brakeType::coast);
  mogo.setBrake(brakeType::hold);
  lift.setBrake(brakeType::hold);
  lift2.setBrake(brakeType::hold);
  arm.setBrake(brakeType::hold);
}

void autonomous(void) {
  // rightTwoMogoElim();
  rightRingtwoMogo();
  // rightRingOneMogo();
  // leftMogo();
  // leftRingMogo();
  // skillAuton();
}

int driveFwd(){
  fl.spin(vex::directionType::fwd,
            -Controller1.Axis3.value() -
                (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
    bl.spin(vex::directionType::rev,
            Controller1.Axis3.value() +
                (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
    fr.spin(vex::directionType::fwd,
            Controller1.Axis3.value() -
                (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
    br.spin(vex::directionType::rev,
            -Controller1.Axis3.value() +
                (Controller1.Axis1.value() * opControlDriveSlow),
            vex::velocityUnits::pct);
    
    return 1;
}

// Macro Tasks
int mogoMacro() {
  if (mogoIsDown == false) {
    // while(mogoPot.angle() < mogoBottomPos){
    //   mogo.spin(directionType::fwd, 100, velocityUnits::pct);
    //   task::sleep(20);
    // }
    // mogo.stop();
    mogo.rotateTo(1150, rotationUnits::deg, 100, velocityUnits::pct);
    mogoIsDown = true;
  } else if (mogoIsDown == true) {
    // while(mogoPot.angle() > mogoTopPos){
    //   mogo.spin(directionType::rev, 100, velocityUnits::pct);
    //   task::sleep(20);
    // }
    // mogo.stop();
    mogo.rotateTo(-15, rotationUnits::deg, 100, velocityUnits::pct);
    mogoIsDown = false;
  }
  return 1;
}

int liftMacro() {
  liftManual = false;
  while (lift.rotation(deg) > 0) {
    liftGroup.spin(directionType::fwd, -100, velocityUnits::pct);
    task::sleep(20);
  }
  liftManual = true;
  return 1;
}

// Functions that start the task
void startMogoMacro() { 
  task b(mogoMacro); 
}

void startLiftMacro() {
  task lift(liftMacro);
  Controller1.rumble("-");
}

int switchDriveLock() {
  if (driveLock) {
    driveLock = false;
    Controller1.rumble("--");
    fl.setBrake(brakeType::coast);
    bl.setBrake(brakeType::coast);
    fr.setBrake(brakeType::coast);
    br.setBrake(brakeType::coast);
  }

  else if (driveLock == false) {
    driveLock = true;
    Controller1.rumble("-");
    fl.setBrake(brakeType::hold);
    bl.setBrake(brakeType::hold);
    fr.setBrake(brakeType::hold);
    br.setBrake(brakeType::hold);
  }
  return 1;
}

void startSwitchDriveLock() { 
  task switchLock(switchDriveLock); 
}

void usercontrol(void) {
  while (1) {
    task::stop(drivePID);
    enableDrivePID = false;
    driveFwd();
    Controller1.ButtonY.pressed(startSwitchDriveLock);
    Controller1.ButtonB.pressed(startMogoMacro);
    Controller1.ButtonA.pressed(startLiftMacro);

    // lift
    if (liftManual == true) {
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

    task::sleep(20);
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