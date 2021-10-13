#include "vex.h" //CHECK
using namespace vex;

void pre_auton(void) {
  vexcodeInit();
  Inert = vex::inertial(vex::PORT21);
  Inert.calibrate();
  // waits for the Inertial Sensor to calibrate
  while (Inert.isCalibrating()) {
    wait(100, msec);
  }
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

  // topAuton();
  // botAuton();
  // skillAuton();
}

bool mogoMacro = false;

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


int mogoTailMacro() {
  while(true)
  {
    mogo.startRotateTo(-500, rotationUnits::deg, 70, velocityUnits::pct);
    tail.rotateTo(20, rotationUnits::deg, 20, velocityUnits::pct);
    mogoMacro = false;
  }
  return 1;
}

void usercontrol(void) {
  while (1) {
    task a(driveFwd);

    bool mogoMacro = false;

    if(Controller1.ButtonRight.pressing())
    {
      mogoMacro = true;
    }

    if(mogoMacro == true)
    {
      task b(mogoTailMacro);
    }
    
    
    // mogo
    if (Controller1.ButtonB.pressing()) {
      // mogoCurve(1);
      mogo.spin(vex::directionType::fwd, 70, vex::velocityUnits::pct);
    }

    else if (Controller1.ButtonX.pressing()) {
      // mogoCurve(-1);
      mogo.spin(vex::directionType::fwd, -70, vex::velocityUnits::pct);
    } else {
      mogo.stop();
      mogo.setBrake(brakeType::hold);
    }

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

    // drive hold button
    if (Controller1.ButtonLeft.pressing()) {
      fl.stop();
      fl.setBrake(brakeType::hold);

      bl.stop();
      bl.setBrake(brakeType::hold);

      fr.stop();
      fr.setBrake(brakeType::hold);

      br.stop();
      br.setBrake(brakeType::hold);
    }

    wait(20, msec);
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