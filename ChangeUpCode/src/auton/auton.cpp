#include "vex.h"
using namespace vex;



void topAuton(void)
{
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  //STARTING FROM TOP OF THE FIELD AUTONOMOUS CODE WITH SELF CORRECTING PID LOOP
  resetDriveSensors = true; // GOES BACKWARD 120 ROTATIONS
  desiredVal = -120;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS ABOUT 45 DEGREES
  turnDesiredVal = -95;
  task::sleep(700);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES FORWARD AND INTAKES THE BALL
  desiredVal = 95;
  startIntake(400, 68);
  task::sleep(800);

  resetDriveSensors = true; // SCORES A BALL AND DRIVES BACKWARD
  fastShoot(1000, 100);
  task::sleep(1000);
  desiredVal = -60;
  task::sleep(800);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS TO FACE WALL
  turnSlow = 0.75;
  turnDesiredVal = -93;
  task::sleep(900);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES BACKWARD TO THE MIDDLE GOAL POST AND FEEDS THE BALL TO THE TOP
  desiredVal = -515;
  feed(1000, 75);
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // PERFECT 90 DEGREE TURN
  turnSlow = 0.7;
  turnDesiredVal = 198;
  task::sleep(1000);
  turnDesiredVal = 0;
  turnSlow = 0.85;

  resetDriveSensors = true; // GOES FORWARD AND SCORES THE BALL
  desiredVal = 100;
  shoot(800, 100);
  task::sleep(1000);

  resetDriveSensors = true; // GOES BACKWARD
  driveSlow = 0.7;
  desiredVal = -110;
  task::sleep(1000);
  driveSlow = 1.0;
  desiredVal = 0;
  
  resetDriveSensors = true; // PERFECT 90 DEGREE TURN
  turnSlow = 0.7;
  turnDesiredVal = 200;
  task::sleep(1000);
  turnDesiredVal = 0;
  turnSlow = 0.85;

  resetDriveSensors = true; // GOES FORWARD TO THE END GOAL POST AND SCORES THE BALL TO THE TOP
  desiredVal = 540;
  feed(1000, 75);
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS YO FACE GOAL
  turnSlow = 0.7;
  turnDesiredVal = -75;
  task::sleep(800);
  turnDesiredVal = 0;
  turnSlow = 0.85;

  resetDriveSensors = true; // GOES FORWARD AND INTAKES THE BALL
  desiredVal = 125;
  startIntake(1000, 90);
  task::sleep(1200);

  resetDriveSensors = true; // SCORES A BALL AND DRIVES BACKWARD
  fastShoot(2000, 100);
  task::sleep(1000);
  desiredVal = -85;
  task::sleep(1000);
  desiredVal = 0;
}

void botAuton(void)
{
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  //STARTING FROM TOP OF THE FIELD AUTONOMOUS CODE WITH SELF CORRECTING PID LOOP
  resetDriveSensors = true; // GOES BACKWARD 120 ROTATIONS
  desiredVal = -120;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS ABOUT 45 DEGREES
  turnDesiredVal = 95;
  task::sleep(700);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES FORWARD AND INTAKES THE BALL
  desiredVal = 95;
  startIntake(400, 68);
  task::sleep(800);

  resetDriveSensors = true; // SCORES A BALL AND DRIVES BACKWARD
  fastShoot(1000, 100);
  task::sleep(1000);
  desiredVal = -60;
  task::sleep(800);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS TO FACE WALL
  turnSlow = 0.75;
  turnDesiredVal = 93;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES BACKWARD TO THE MIDDLE GOAL POST AND FEEDS THE BALL TO THE TOP
  desiredVal = -515;
  feed(1000, 75);
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // PERFECT 90 DEGREE TURN
  turnSlow = 0.7;
  turnDesiredVal = -198;
  task::sleep(1100);
  turnDesiredVal = 0;
  turnSlow = 0.85;

  resetDriveSensors = true; // GOES FORWARD AND SCORES THE BALL
  desiredVal = 100;
  shoot(1000, 100);
  task::sleep(1200);

  resetDriveSensors = true; // GOES BACKWARD
  driveSlow = 0.7;
  desiredVal = -110;
  task::sleep(1000);
  driveSlow = 1.0;
  desiredVal = 0;
  
  resetDriveSensors = true; // PERFECT 90 DEGREE TURN
  turnSlow = 0.7;
  turnDesiredVal = -200;
  task::sleep(1000);
  turnDesiredVal = 0;
  turnSlow = 0.85;

  resetDriveSensors = true; // GOES FORWARD TO THE END GOAL POST AND SCORES THE BALL TO THE TOP
  desiredVal = 540;
  feed(1000, 75);
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS ABOUT 45 DEGREES
  turnSlow = 0.7;
  turnDesiredVal = 80;
  task::sleep(800);
  turnDesiredVal = 0;
  turnSlow = 0.85;

  resetDriveSensors = true; // GOES FORWARD AND INTAKES THE BALL
  desiredVal = 125;
  startIntake(1000, 90);
  task::sleep(1200);

  resetDriveSensors = true; // SCORES A BALL AND DRIVES BACKWARD
  fastShoot(2000, 100);
  task::sleep(1000);
  desiredVal = -85;
  task::sleep(1000);
  desiredVal = 0;
}

void skillAuton(void)
{
  // skills auto starts top left, goes down, then right
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  driveSlow = 0.6;
  turnSlow = 0.6;

  //////////////////// A ////////////////////
  resetDriveSensors = true; // starts top left, goes fwd
  desiredVal = 270;
  startIntake(500, 60);
  task::sleep(1400);
  desiredVal = 0;

  resetDriveSensors = true; //135 degree turn left
  turnDesiredVal = 310;
  task::sleep(1000);
  turnDesiredVal = 0;
  
  resetDriveSensors = true; // go fwd to goal
  desiredVal = 290;
  task::sleep(1500);
  shoot(1000, 100);
  driveSlow = 0.3;
  task::sleep(800);
  desiredVal = -30;
  task::sleep(1000);
  desiredVal = 0;
  driveSlow = 0.6;

  ////////////////////// D //////////////////
  resetDriveSensors = true; //45 degree turn right
  turnDesiredVal = -100;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; //back up to next goal
  desiredVal = -505;
  feed(1000, 70);
  task::sleep(1500);
  desiredVal = 0;

  resetDriveSensors = true; // 90 degree turn left
  turnDesiredVal = 198;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES FORWARD AND SCORES THE BALL
  desiredVal = 120;
  task::sleep(400);
  shoot(800, 100);
  task::sleep(1000);
  
  resetDriveSensors = true; // comes back
  desiredVal = -110;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true; // 90 degree turn left
  turnDesiredVal = 210;
  task::sleep(1100);
  turnDesiredVal = 0;

  //////////////////// G ////////////////////
  resetDriveSensors = true; //drive up to next goal and intake ball
  driveSlow = 0.3;
  desiredVal = 590;
  feed(2000, 45);
  task::sleep(2500);
  driveSlow = 0.6;
  desiredVal = 0;

  resetDriveSensors = true; //45 degree turn right
  turnDesiredVal = -95;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // go fwd to goal
  desiredVal = 185;
  task::sleep(1000);
  fastShoot(1000, 100);
  task::sleep(750);

  resetDriveSensors = true; //back away from goal
  desiredVal = -140;
  task::sleep(1000);
  desiredVal = 0;

  ////////////////////// H //////////////////
  resetDriveSensors = true; //135 degree turn right
  turnDesiredVal = -305;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // go back and allign with wall
  desiredVal = -280;
  task::sleep(1400);
  desiredVal = 0;

  resetDriveSensors = true; //drive fwd away from wall
  desiredVal = 215;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true; // 90 degree turn right
  turnDesiredVal = -185;
  task::sleep(1100);
  turnDesiredVal = 0;

  resetDriveSensors = true; // go forward and intake ball
  driveSlow = 0.4;
  desiredVal = 540;
  task::sleep(800);
  feed(2000, 60);
  task::sleep(1200);
  driveSlow = 0.6;
  desiredVal = 0;

  resetDriveSensors = true; // 90 degree turn right
  turnDesiredVal = -195;
  task::sleep(1100);
  turnDesiredVal = 0;

  resetDriveSensors = true; // go fwd to goal
  desiredVal = 90;
  task::sleep(800);
  shoot(500, 100);
  task::sleep(400);

  resetDriveSensors = true; // back away from the goal
  desiredVal = -90;
  task::sleep(1600);
  desiredVal = 0;

  ////////////////// I //////////////
  resetDriveSensors = true; // turn left to face ball
  turnDesiredVal = 245;
  task::sleep(1400);
  turnDesiredVal = 0;

  resetDriveSensors = true; // go fwd and intake ball
  desiredVal = 440;
  task::sleep(500);
  feed(2000, 60);
  task::sleep(1600);
  desiredVal = 0;

  resetDriveSensors = true; //  turn right to face goal
  turnDesiredVal = -137;
  task::sleep(1100);
  turnDesiredVal = 0;

  resetDriveSensors = true; // go fwd
  desiredVal = 280;
  task::sleep(1600);
  shoot(500, 100);
  task::sleep(800);

  resetDriveSensors = true; // go back and stop
  desiredVal = -100;
  task::sleep(1600);

}

///////////////////////////////

void oneballauto(double distance, double velocity)
{
  LB.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  LF.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RB.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RF.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct); //drive fwd

  vex::task::sleep(1500);
  top.startRotateFor(750, rotationUnits::deg, 100, vex::velocityUnits::pct);
  bot.startRotateFor(750, rotationUnits::deg, 100, vex::velocityUnits::pct); //run the top and bot roller to score ball
  leftintake.startRotateFor(1750, rotationUnits::deg, 70, velocityUnits::pct); //intake descores 2 balls from the goal
  rightintake.startRotateFor(1750, rotationUnits::deg, 70, velocityUnits::pct);

  vex::task::sleep(1000);
  LB.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct); //drive back
  LF.startRotateFor(-distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RB.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);
  RF.startRotateFor(distance, vex::rotationUnits::deg, velocity, vex::velocityUnits::pct);

  
}

void LRTauto(void)
{
  int x = 175;
  LB.startRotateFor(x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  LF.startRotateFor(x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);//bwd
  vex::task::sleep(775);

  x = 90;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);//turn right
  vex::task::sleep(800);

  x = 315;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  leftintake.startRotateFor(570, rotationUnits::deg, 50, velocityUnits::pct);
  rightintake.startRotateFor(570, rotationUnits::deg, 50, velocityUnits::pct);
  top.startRotateFor(1600, rotationUnits::deg, 100, vex::velocityUnits::pct); //fwd intake drive
  vex::task::sleep(775);

  bot.startRotateFor(300, rotationUnits::deg, 100, vex::velocityUnits::pct); //score
  LB.stop(brakeType::coast);
  LF.stop(brakeType::coast);
  RB.stop(brakeType::coast);
  RF.stop(brakeType::coast);
  vex::task::sleep(500);

  x = 1160;
  LB.startRotateFor(x+260, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  LF.startRotateFor(x+260, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 80, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 80, vex::velocityUnits::pct); //curve turn
  vex::task::sleep(2650);

  x = 450;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 37, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 37, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 43, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 43, vex::velocityUnits::pct);
  top.startRotateFor(1500, rotationUnits::deg, 100, vex::velocityUnits::pct); //fwd
  vex::task::sleep(500);

  bot.startRotateFor(500, rotationUnits::deg, 100, vex::velocityUnits::pct); //score
  vex::task::sleep(700);

  x = 175;
  LB.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  LF.startRotateFor(x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct); //bwd
  vex::task::sleep(800);

  x = -220;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 40, vex::velocityUnits::pct); //turn
  vex::task::sleep(775);

  x = 840;
  LB.startRotateFor(-x - 150, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  LF.startRotateFor(-x - 150, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 55, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 55, vex::velocityUnits::pct); //curve 2
  vex::task::sleep(1700);

  x = 400;
  LB.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  LF.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RB.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RF.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  leftintake.startRotateFor(700, rotationUnits::deg, 70, velocityUnits::pct);
  rightintake.startRotateFor(700, rotationUnits::deg, 70, velocityUnits::pct);
  top.startRotateFor(2000, rotationUnits::deg, 100, vex::velocityUnits::pct);
  bot.startRotateFor(2000, rotationUnits::deg, 100, vex::velocityUnits::pct);
  vex::task::sleep(1650);


  leftintake.startRotateFor(-800, rotationUnits::deg, 70, velocityUnits::pct);
  rightintake.startRotateFor(-800, rotationUnits::deg, 70, velocityUnits::pct);
  LB.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  LF.startRotateFor(x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RB.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  RF.startRotateFor(-x, vex::rotationUnits::deg, 45, vex::velocityUnits::pct);
  vex::task::sleep(1500);

}