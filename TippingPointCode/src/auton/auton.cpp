#include "vex.h"
using namespace vex;

void skillAuton(void) {
  lift.resetPosition();
  lift2.resetPosition();

  mogo.startRotateTo( 1150, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  desiredVal = -251; 
  armStartRotate(-1, 300, 75);
  task::sleep(750);

  mogo.startRotateTo( 0, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(800);
  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = 100;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.7;
  turnDesiredVal = -260;
  task::sleep(1600);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  resetDriveSensors = true;
  driveSlow = 0.7;
  desiredVal = 1000;
  task::sleep(1450);
  armStartRotate(1, 115, 100);
  task::sleep(250);
  liftGroup.rotateFor(fwd, 50, degrees, 40, velocityUnits::pct);
  task::sleep(400);
  changePIDVal(true, true, false);
  
  resetDriveSensors = true;
  desiredVal = 700;
  task::sleep(700);
  task::sleep(680);
  desiredVal = 0;
  
  resetDriveSensors = true;
  turnSlow = 0.7;
  turnDesiredVal = -87;
  task::sleep(1300);
  turnSlow = 1.0;

  liftGroup.rotateTo(820, rotationUnits::deg, 70, velocityUnits::pct);
  task::sleep(300);

  turnDesiredVal = 0;
  
  resetDriveSensors = true;
  driveSlow = 0.7;
  desiredVal = 685;
  task::sleep(1350);
  driveSlow = 1.0;

  liftGroup.rotateTo(510, rotationUnits::deg, 50, velocityUnits::pct);
  task::sleep(100);

  liftGroup.rotateTo(570, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(600);

  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = 32;
  task::sleep(1100);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = 105;
  task::sleep(500);
  
  armStartRotate(-1, 130, 100);
  task::sleep(290);

  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = -135;
  task::sleep(1100);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow  = 0.75;
  turnDesiredVal = 312; /////////////////////////////////////////////////////////////////////////////
  task::sleep(2000);
  liftGroup.rotateTo(-15, rotationUnits::deg, 60, velocityUnits::pct, false);
  task::sleep(600);
  turnSlow = 1.0;

  mogo.startRotateTo( 1140, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  turnDesiredVal = 0;

  changePIDVal(false, false, false);

  resetDriveSensors = true;
  driveSlow = 0.5;
  desiredVal = 695;
  task::sleep(1575);

  resetDriveSensors = true;
  desiredVal = 175;
  task::sleep(600);

  armStartRotate(1, 145, 100);
  task::sleep(250);
  liftGroup.rotateFor(fwd, 60, degrees, 40, velocityUnits::pct, false);
  task::sleep(100);
  driveSlow = 1.0;
  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = -205;
  task::sleep(1080);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -115;
  task::sleep(1200);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  driveSlow = 0.85;
  desiredVal = -2500;
  task::sleep(3600);
  driveSlow = 1.0;
  
  resetDriveSensors = true;
  desiredVal = 530;
  task::sleep(1300);

  liftGroup.rotateTo(700, rotationUnits::deg, 60, velocityUnits::pct);
  task::sleep(400);

  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.6;
  turnDesiredVal = 250;
  task::sleep(1500);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  resetDriveSensors = true;
  desiredVal = 390;
  task::sleep(1200);

  liftGroup.rotateTo(580, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(600);

  armStartRotate(-1, 130, 100);
  task::sleep(300);

  resetDriveSensors = true;
  desiredVal = -60;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -128;
  task::sleep(1400);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = -780;
  task::sleep(1500);
  liftGroup.rotateTo(-15, rotationUnits::deg, 60, velocityUnits::pct, false);

  mogo.startRotateTo(0, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1200);

  resetDriveSensors = true;
  desiredVal = 360;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -226;
  task::sleep(1200);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = 1500;
  task::sleep(4000);


  enableDrivePID = false;

}

void rightTwoMogoElim(void){
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  driveSlow = 0.70;
  desiredVal = 898; 
  armStartRotate(-1, 300, 75);
  task::sleep(1180);

  armStartRotate(1, 105, 100);
  task::sleep(180);
  driveSlow = 1;

  resetDriveSensors = true;
  desiredVal = -540;
  task::sleep(900);
  armStartRotate(-1, 150, 75);
  task::sleep(180);

  resetDriveSensors = true;
  desiredVal = -140;
  task::sleep(630);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -346;
  task::sleep(700);
  mogo.startRotateFor(directionType::fwd, 1150, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(140);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = -1050;
  task::sleep(1375);
  mogo.startRotateFor(directionType::rev, 400, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(325);

  resetDriveSensors = true;
  desiredVal = 750;
  task::sleep(1000);

  mogo.startRotateFor(directionType::fwd, 390, rotationUnits::deg, 55, velocityUnits::pct);
  mogoIsDown = true;
  task::sleep(1700);

  resetDriveSensors = true;
  desiredVal = 500;
  task::sleep(750);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -210;
  task::sleep(680);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = -410;
  task::sleep(700);

  mogo.startRotateTo(0, rotationUnits::deg, 100, velocityUnits::pct);
  mogoIsDown = false;
  task::sleep(400);

  resetDriveSensors = true;
  desiredVal = 400;
  task::sleep(700);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -309;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = 250;
  task::sleep(700);

}

void rightRingtwoMogo (void){
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  changePIDVal(false, false, false);

  resetDriveSensors = true;
  turnSlow = 0.48;
  turnDesiredVal = -120;
  task::sleep(920);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  resetDriveSensors = true;
  driveSlow = 0.6;
  desiredVal = -440;
  task::sleep(950);
  driveSlow = 1.0;

  mogo.startRotateTo(400, degrees, 80, velocityUnits::pct);
  task::sleep(290);

  resetDriveSensors = true;
  desiredVal = 310;
  task::sleep(800);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.9;
  turnDesiredVal = 205;
  task::sleep(900);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  mogo.startRotateTo(1150, degrees, 100, velocityUnits::pct);
  task::sleep(50);

  resetDriveSensors = true;
  desiredVal = -1220;
  task::sleep(1400);
  desiredVal = 0;

  mogo.startRotateFor(directionType::rev, 400, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(600);

  resetDriveSensors = true;
  desiredVal = 680;
  task::sleep(1200);

  mogo.startRotateFor(directionType::fwd, 400, rotationUnits::deg, 60, velocityUnits::pct);
  mogoIsDown = true;
  task::sleep(1325);

  resetDriveSensors = true;
  driveSlow = 0.7;
  desiredVal = 320;
  task::sleep(800);
  driveSlow = 1.0;
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -100;
  task::sleep(600);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = -780;
  task::sleep(1000);
  desiredVal = 0;

  mogo.startRotateFor(directionType::rev, 400, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(250);

  resetDriveSensors = true;
  desiredVal = 750;
  task::sleep(1000);

  mogo.startRotateFor(directionType::fwd, 400, rotationUnits::deg, 60, velocityUnits::pct);
  mogoIsDown = true;

}

void rightRingOneMogo (void){
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  changePIDVal(false, false, false);

  resetDriveSensors = true;
  turnSlow = 0.5;
  turnDesiredVal = -120;
  task::sleep(920);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  resetDriveSensors = true;
  driveSlow = 0.6;
  desiredVal = -430;
  task::sleep(1000);
  driveSlow = 0.8;

  mogo.startRotateTo(400, degrees, 80, velocityUnits::pct);
  task::sleep(350);

  resetDriveSensors = true;
  desiredVal = 300;
  task::sleep(850);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.7;
  turnDesiredVal = 205;
  task::sleep(1000);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  mogo.startRotateTo(1150, degrees, 80, velocityUnits::pct);
  task::sleep(400);

  resetDriveSensors = true;
  desiredVal = -1220;
  task::sleep(1400);
  desiredVal = 0;

  mogo.startRotateFor(directionType::rev, 400, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(600);

  resetDriveSensors = true;
  desiredVal = 700;
  task::sleep(1500);

  mogo.startRotateFor(directionType::fwd, 400, rotationUnits::deg, 60, velocityUnits::pct);
  mogoIsDown = true;
  task::sleep(1500);
}

void leftMogo (void){
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  desiredVal = 862; //tune
  armStartRotate(-1, 300, 75);
  task::sleep(825);
  driveSlow = 0.5;
  task::sleep(360); // tune
  armStartRotate(1, 115, 100);
  task::sleep(180);
  driveSlow = 1;

  resetDriveSensors = true;
  desiredVal = -600;
  task::sleep(1000);
}

void leftRingMogo (void){
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  desiredVal = -100;
  task::sleep(350);

  mogo.startRotateTo(500, degrees, 100, velocityUnits::pct);
  task::sleep(300);

  mogo.startRotateTo(0, degrees, 100, velocityUnits::pct);
  task::sleep(300);

  resetDriveSensors = true;
  desiredVal = 200;
  task::sleep(700);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -247;
  task::sleep(1050);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  driveSlow = 0.58;
  desiredVal = 972; //tune
  armStartRotate(-1, 300, 75);
  task::sleep(1300);
  armStartRotate(1, 115, 100);
  task::sleep(180);
  driveSlow = 1;

  resetDriveSensors = true;
  desiredVal = -600;
  task::sleep(900);
  armStartRotate(-1, 150, 75);
  task::sleep(220);
}

void tuningAuto (void){
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  changePIDVal(false, false, false);

  task::sleep(5000);

  resetDriveSensors = true;
  turnDesiredVal = 1;
  turnAngleVal = 90;
  task::sleep(1420);

}