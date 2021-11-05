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
  turnDesiredVal = -260;
  task::sleep(2500);

  resetDriveSensors = true;
  desiredVal = 200; 
  task::sleep(1200);
  
  resetDriveSensors = true;
  turnDesiredVal = -260;
  task::sleep(2000);

  resetDriveSensors = true;
  desiredVal = 200; 
  task::sleep(1500);

  // changePIDVal(true, true, false);
  // resetDriveSensors = true;
  // turnSlow = 0.6;
  // turnDesiredVal = -260;
  // task::sleep(2000);
  // turnSlow = 1.0;

  // resetDriveSensors = true;
  // driveSlow = 0.8;
  // desiredVal = 75; 
  // task::sleep(1500);


}

void skillAuton(void) {
  mogo.startRotateTo( 1150, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  desiredVal = -250; 
  armStartRotate(-1, 300, 75);
  task::sleep(850);

  mogo.startRotateTo( 0, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);
  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = 100;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.65;
  turnDesiredVal = -260;
  task::sleep(1600);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  resetDriveSensors = true;
  driveSlow = 0.7;
  desiredVal = 1000;
  task::sleep(1550);
  armStartRotate(1, 115, 100);
  task::sleep(220);
  liftGroup.rotateFor(fwd, 20, degrees, 40, velocityUnits::pct);
  task::sleep(600);
  changePIDVal(true, true, false);
  
  resetDriveSensors = true;
  desiredVal = 700;
  task::sleep(1300);
  desiredVal = 0;
  
  resetDriveSensors = true;
  turnDesiredVal = -87;
  task::sleep(1200);
  turnDesiredVal = 0;

  liftGroup.rotateTo(820, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(1000);
  
  resetDriveSensors = true;
  desiredVal = 680;
  task::sleep(1400);
  desiredVal = 0;

  liftGroup.rotateTo(500, rotationUnits::deg, 50, velocityUnits::pct);
  task::sleep(100);

  liftGroup.rotateTo(580, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(800);

  resetDriveSensors = true;
  turnDesiredVal = 38;
  task::sleep(1000);
  turnDesiredVal = 0;
  
  armStartRotate(-1, 130, 100);
  task::sleep(290);

  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = -150;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = 280;
  task::sleep(1200);
  turnDesiredVal = 0;

  mogo.startRotateTo( 1150, rotationUnits::deg, 100, velocityUnits::pct);
  liftGroup.rotateTo(-15, rotationUnits::deg, 75, velocityUnits::pct, true);
  task::sleep(1200);

  changePIDVal(false, false, false);

  resetDriveSensors = true;
  driveSlow = 0.8;
  desiredVal = 640;
  task::sleep(1200);
  armStartRotate(1, 115, 100);
  task::sleep(200);
  driveSlow = 1.0;
  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = -175;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -112;
  task::sleep(1200);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  driveSlow = 0.85;
  desiredVal = -2500;
  task::sleep(3700);
  driveSlow = 1.0;
  
  resetDriveSensors = true;
  desiredVal = 500;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = 240;
  task::sleep(1200);
  turnDesiredVal = 0;

  liftGroup.rotateTo(700, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(1000);

  resetDriveSensors = true;
  desiredVal = 375;
  task::sleep(1200);

  liftGroup.rotateTo(580, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(800);

  armStartRotate(-1, 130, 100);
  task::sleep(300);

  resetDriveSensors = true;
  desiredVal = -80;
  task::sleep(1200);

  enableDrivePID = false;

}

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
  mogoIsDown = true;

}

void scrapAutoLeft(void)
{
  
}