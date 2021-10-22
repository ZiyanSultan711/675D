#include "vex.h"
using namespace vex;

void topAuton(void) {
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  desiredValue = 300;
  desiredTurnValue = 600;
  task::sleep(1000);
}

void botAuton(void) {}

void skillAuton(void) {}

void scrapauto(void)
{
  arm.rotateFor(directionType::fwd, -120, rotationUnits::deg, 100, velocityUnits::pct);
  arm.startRotateFor(directionType::fwd, 560, rotationUnits::deg, 75, velocityUnits::pct);
  lift.startRotateFor(directionType::fwd, -20, rotationUnits::deg, 75, velocityUnits::pct);
  startDriveFwd(790, 60);
  arm.startRotateFor(directionType::fwd, 170, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(640);
  startDriveFwd(-550, 50);
  arm.rotateFor(directionType::fwd, -160, rotationUnits::deg, 100, velocityUnits::pct);
  startDriveFwd(-100, 40);
  arm.startRotateFor(directionType::fwd, 160, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(20);
  mogo.startRotateTo(1150, rotationUnits::deg, 100, velocityUnits::pct);
  startDriveTurn(-300, 40);
  task::sleep(20);
  startDriveFwd(-340, 50);
  mogo.rotateTo(0, rotationUnits::deg, -100, velocityUnits::pct);
}