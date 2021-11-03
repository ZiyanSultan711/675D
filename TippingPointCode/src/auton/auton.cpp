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
  desiredVal = -280;
  armStartRotate(-1, 550, 75);
  task::sleep(1300);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.7;
  turnDesiredVal = 205;
  task::sleep(1300);
  turnSlow = 1;
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = 1000;
  armStartRotate(1, 500, 75);
  task::sleep(1500);

  resetDriveSensors = true;
  desiredVal = 105;
  lift.startRotateFor(directionType::rev, 40, rotationUnits::deg, 50, velocityUnits::pct);
  task::sleep(1300);

  armRotate(1, 150, 75);
  task::sleep(1000);

  resetDriveSensors = true;
  desiredVal = -800;
  task::sleep(1300);

  armRotate(-1, 150, 75);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -150;
  task::sleep(750);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = 215;
  task::sleep(2000);

}

void botAuton(void) {
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  turnAngleVal = 90;
  turnDesiredVal = 1;
  task::sleep(2000);
  turnDesiredVal = 0;
  turnAngleVal = 0;
}

void skillAuton(void) {}

void scrapAutoRight(void)
{
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  driveSlow = 0.85;
  desiredVal = 804; 
  armStartRotate(-1, 300, 75);
  liftGroup.spinFor(directionType::fwd, -20, deg);
  task::sleep(1550);
  armStartRotate(1, 100, 100);
  task::sleep(300);
  driveSlow = 1.0;

  resetDriveSensors = true;
  desiredVal = -700;
  task::sleep(2000);
}

void scrapAutoLeft(void)
{
  
}