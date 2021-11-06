#include "vex.h"
using namespace vex;

void skillAuton(void) {
  mogo.startRotateTo( 1150, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  desiredVal = -250; 
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
  turnSlow = 0.575;
  turnDesiredVal = -260;
  task::sleep(1800);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  resetDriveSensors = true;
  driveSlow = 0.7;
  desiredVal = 1000;
  task::sleep(1450);
  armStartRotate(1, 115, 100);
  task::sleep(140);
  liftGroup.rotateFor(fwd, 20, degrees, 40, velocityUnits::pct);
  task::sleep(400);
  changePIDVal(true, true, false);
  
  resetDriveSensors = true;
  desiredVal = 700;
  task::sleep(700);
  task::sleep(620);
  desiredVal = 0;
  
  resetDriveSensors = true;
  turnSlow = 0.9;
  turnDesiredVal = -87;
  task::sleep(950);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  liftGroup.rotateTo(820, rotationUnits::deg, 60, velocityUnits::pct, false);
  task::sleep(1000);
  
  resetDriveSensors = true;
  desiredVal = 680;
  task::sleep(1350);
  desiredVal = 0;

  liftGroup.rotateTo(500, rotationUnits::deg, 50, velocityUnits::pct);
  task::sleep(100);

  liftGroup.rotateTo(570, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(600);

  resetDriveSensors = true;
  turnDesiredVal = 35;
  task::sleep(1100);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = 65;
  task::sleep(500);
  desiredVal = 0;
  
  armStartRotate(-1, 130, 100);
  task::sleep(290);

  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = -155;
  task::sleep(1100);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow  = 0.6;
  turnDesiredVal = 288;
  task::sleep(2000);
  liftGroup.rotateTo(-15, rotationUnits::deg, 60, velocityUnits::pct, false);
  task::sleep(600);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  mogo.startRotateTo( 1150, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(1000);

  changePIDVal(false, false, false);

  resetDriveSensors = true;
  driveSlow = 0.5;
  desiredVal = 654;
  task::sleep(1575);
  armStartRotate(1, 140, 100);
  task::sleep(220);
  liftGroup.rotateFor(fwd, 20, degrees, 40, velocityUnits::pct, false);
  task::sleep(100);
  driveSlow = 1.0;
  changePIDVal(true, false, false);

  resetDriveSensors = true;
  desiredVal = -173;
  task::sleep(1080);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -111;
  task::sleep(1200);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  driveSlow = 0.85;
  desiredVal = -2500;
  task::sleep(3400);
  driveSlow = 1.0;
  
  resetDriveSensors = true;
  desiredVal = 530;
  task::sleep(600);
  liftGroup.rotateTo(700, rotationUnits::deg, 30, velocityUnits::pct, false);
  task::sleep(700);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.8;
  turnDesiredVal = 250;
  task::sleep(1300);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  resetDriveSensors = true;
  desiredVal = 375;
  task::sleep(1200);

  liftGroup.rotateTo(580, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(600);

  armStartRotate(-1, 130, 100);
  task::sleep(300);

  resetDriveSensors = true;
  desiredVal = -100;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -140;
  task::sleep(1200);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = -730;
  task::sleep(1200);
  liftGroup.rotateTo(-15, rotationUnits::deg, 60, velocityUnits::pct, false);

  mogo.startRotateTo(0, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(900);

  resetDriveSensors = true;
  desiredVal = 380;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -242;
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
  driveSlow = 0.75;
  desiredVal = 805; 
  armStartRotate(-1, 300, 75);
  task::sleep(1185);

  resetDriveSensors = true;
  desiredVal = 100;
  task::sleep(115);

  armStartRotate(1, 105, 100);
  task::sleep(220);
  driveSlow = 1;

  resetDriveSensors = true;
  desiredVal = -540;
  task::sleep(900);
  armStartRotate(-1, 150, 75);
  task::sleep(220);

  resetDriveSensors = true;
  desiredVal = -140;
  task::sleep(700);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -356;
  task::sleep(700);
  mogo.startRotateFor(directionType::fwd, 1150, rotationUnits::deg, 100, velocityUnits::pct);
  task::sleep(250);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = -1050;
  task::sleep(1425);
  mogo.startRotateFor(directionType::rev, 400, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(400);

  resetDriveSensors = true;
  desiredVal = 750;
  task::sleep(1000);

  mogo.startRotateFor(directionType::fwd, 400, rotationUnits::deg, 60, velocityUnits::pct);
  mogoIsDown = true;

}

void rightRingtwoMogo (void){
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
  driveSlow = 1.0;

  mogo.startRotateTo(400, degrees, 80, velocityUnits::pct);
  task::sleep(350);

  resetDriveSensors = true;
  desiredVal = 300;
  task::sleep(850);
  desiredVal = 0;

  resetDriveSensors = true;
  turnSlow = 0.9;
  turnDesiredVal = 205;
  task::sleep(900);
  turnDesiredVal = 0;
  turnSlow = 1.0;

  mogo.startRotateTo(1150, degrees, 80, velocityUnits::pct);
  task::sleep(300);

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
  task::sleep(850);
  driveSlow = 1.0;
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -100;
  task::sleep(900);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  desiredVal = -780;
  task::sleep(1500);
  desiredVal = 0;

  mogo.startRotateFor(directionType::rev, 400, rotationUnits::deg, 75, velocityUnits::pct);
  task::sleep(500);

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
  desiredVal = 843; //tune
  armStartRotate(-1, 300, 75);
  task::sleep(825);
  driveSlow = 0.5;
  task::sleep(475); // tune
  armStartRotate(1, 115, 100);
  task::sleep(220);
  driveSlow = 1;

  resetDriveSensors = true;
  desiredVal = -600;
  task::sleep(900);
  armStartRotate(-1, 150, 75);
  task::sleep(220);
}

void leftRingMogo (void){
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  resetDriveSensors = true;
  desiredVal = -100;
  task::sleep(600);

  mogo.startRotateTo(500, degrees, 80, velocityUnits::pct);
  task::sleep(300);

  mogo.startRotateTo(0, degrees, 100, velocityUnits::pct);
  task::sleep(250);

  resetDriveSensors = true;
  desiredVal = 200;
  task::sleep(700);
  desiredVal = 0;

  resetDriveSensors = true;
  turnDesiredVal = -247;
  task::sleep(950);
  turnDesiredVal = 0;

  resetDriveSensors = true;
  driveSlow = 0.58;
  desiredVal = 972; //tune
  armStartRotate(-1, 300, 75);
  task::sleep(1025);
  task::sleep(400); // tune
  armStartRotate(1, 115, 100);
  task::sleep(220);
  driveSlow = 1;

  resetDriveSensors = true;
  desiredVal = -600;
  task::sleep(900);
  armStartRotate(-1, 150, 75);
  task::sleep(220);
}