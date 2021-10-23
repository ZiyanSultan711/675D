#include "vex.h"
using namespace vex;

void topAuton(void) {
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  // STARTING FROM TOP OF THE FIELD AUTONOMOUS CODE WITH SELF CORRECTING PID
  // LOOP
  resetDriveSensors = true;
  desiredVal = 450;
  task::sleep(750);
  armStartRotate(1, 300, 75);
  task::sleep(1300);

  resetDriveSensors = true;
  desiredVal = -275;
  armStartRotate(-1, 550, 75);
  task::sleep(1300);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.7;
  turnDesiredVal = 195;
  task::sleep(1300);
  turnSlow = 1;
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = 1125;
  armStartRotate(1, 500, 75);
  lift.startRotateFor(directionType::rev, 50, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1500);

  armRotate(1, 200, 75);
  task::sleep(1300);

}

void botAuton(void) {}

void skillAuton(void) {}

void scrapautoblue(void)
{
  arm.rotateFor(directionType::fwd, -100, rotationUnits::deg, 100, velocityUnits::pct);
  arm.startRotateFor(directionType::fwd, 500, rotationUnits::deg, 75, velocityUnits::pct);
  lift.startRotateFor(directionType::fwd, -20, rotationUnits::deg, 75, velocityUnits::pct);
  startDriveFwd(800, 60);
  arm.startRotateFor(directionType::fwd, 160, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(640);
  startDriveFwd(-550, 50);
  arm.rotateFor(directionType::fwd, -160, rotationUnits::deg, 100, velocityUnits::pct);
  startDriveFwd(-100, 40);
  arm.startRotateFor(directionType::fwd, 160, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(20);
  mogo.startRotateTo(1150, rotationUnits::deg, 100, velocityUnits::pct);
  startDriveTurn(300, 40);
  task::sleep(20);
  startDriveFwd(-380, 50);
  mogo.rotateTo(0, rotationUnits::deg, -100, velocityUnits::pct);
}

void scrapautored(void)
{
  arm.rotateFor(directionType::fwd, -100, rotationUnits::deg, 100, velocityUnits::pct);
  arm.startRotateFor(directionType::fwd, 500, rotationUnits::deg, 75, velocityUnits::pct);
  lift.startRotateFor(directionType::fwd, -20, rotationUnits::deg, 75, velocityUnits::pct);
  startDriveFwd(800, 60);
  arm.startRotateFor(directionType::fwd, 160, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(640);
  startDriveFwd(-550, 50);
  arm.rotateFor(directionType::fwd, -160, rotationUnits::deg, 100, velocityUnits::pct);
  startDriveFwd(-100, 40);
  arm.startRotateFor(directionType::fwd, 160, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(20);
  mogo.startRotateTo(1150, rotationUnits::deg, 100, velocityUnits::pct);
  startDriveTurn(-300, 40);
  task::sleep(20);
  startDriveFwd(-380, 50);
  mogo.rotateTo(0, rotationUnits::deg, -100, velocityUnits::pct);
}