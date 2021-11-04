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
  desiredVal = 0;
  turnDesiredVal = 400;
  task::sleep(2000);
}

void skillAuton(void) {}

void scrapAutoRight(void)
{
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  driveSlow = 0.9;
  desiredVal = 804; 
  armStartRotate(-1, 300, 75);
  task::sleep(1350);
  armStartRotate(1, 105, 100);
  task::sleep(290);
  driveSlow = 1.0;

  resetDriveSensors = true;
  desiredVal = -540;
  task::sleep(1300);
  armStartRotate(-1, 150, 75);
  task::sleep(500);

  resetDriveSensors = true;
  desiredVal = -140;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -350;
  task::sleep(1500);
  turnDesiredVal = 0;
  mogo.startRotateFor(directionType::fwd, 1150, rotationUnits::deg, 100, velocityUnits::pct);

  resetDriveSensors = true;
  desiredVal = -800;
  task::sleep(1500);

  resetDriveSensors = true;
  desiredVal = -250;
  task::sleep(1000);
  mogo.startRotateFor(directionType::rev, 400, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(800);

  resetDriveSensors = true;
  desiredVal = 1000;
  task::sleep(1500);

  mogo.startRotateFor(directionType::fwd, 400, rotationUnits::deg, 60, velocityUnits::pct);


}

void scrapAutoLeft(void)
{
  
}