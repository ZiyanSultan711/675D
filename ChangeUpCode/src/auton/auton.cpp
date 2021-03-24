#include "vex.h"
using namespace vex;



void topAuton(void)
{
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  //STARTING FROM TOP OF THE FIELD AUTONOMOUS CODE WITH SELF CORRECTING PID LOOP
  resetDriveSensors = true; // GOES BACKWARD 120 ROTATIONS
  desiredVal = -120;
  task::sleep(1100);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS ABOUT 45 DEGREES
  turnDesiredVal = -95;
  task::sleep(800);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES FORWARD AND INTAKES THE BALL
  desiredVal = 100;
  startIntake(800, 75);
  task::sleep(1100);

  resetDriveSensors = true; // SCORES A BALL AND DRIVES BACKWARD
  shoot(1000, 100);
  task::sleep(500);
  desiredVal = -75;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS TO FACE WALL
  turnDesiredVal = -98;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES BACKWARD TO THE MIDDLE GOAL POST AND FEEDS THE BALL TO THE TOP
  desiredVal = -520;
  feed(1000, 75);
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // PERFECT 90 DEGREE TURN
  turnDesiredVal = 198;
  task::sleep(1100);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES FORWARD AND SCORES THE BALL
  desiredVal = 75;
  shoot(1000, 100);
  task::sleep(1000);
  
  resetDriveSensors = true; // GOES STRAIGHT BACKWARD TO SCORE THE CENTER POST BALL
  desiredVal = -500;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS TO FACE THE CORNER POST *untuned*
  turnDesiredVal = 98;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // DRIVES FORWARD TO THE CENTER POST, INTAKES THE BALL, AND SCORES IT *untuned*
  desiredVal = 800;
  startIntake(1000, 300);
  shoot(600, 75);
  task::sleep(2000);
}

void botAuton(void)
{
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  //STARTING FROM BOTTOM OF THE FIELD AUTONOMOUS CODE WITH SELF CORRECTING PID LOOP
  resetDriveSensors = true; // GOES BACKWARD 120 ROTATIONS
  desiredVal = -120;
  task::sleep(1100);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS ABOUT 45 DEGREES
  turnDesiredVal = 95;
  task::sleep(800);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES FORWARD AND INTAKES THE BALL
  desiredVal = 100;
  startIntake(800, 75);
  task::sleep(1100);

  resetDriveSensors = true; // SCORES A BALL AND DRIVES BACKWARD
  shoot(1000, 100);
  task::sleep(500);
  desiredVal = -75;
  task::sleep(1000);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS TO FACE WALL
  turnDesiredVal = 98;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES BACKWARD TO THE MIDDLE GOAL POST AND FEEDS THE BALL TO THE TOP
  desiredVal = -520;
  feed(1000, 75);
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // PERFECT 90 DEGREE TURN
  turnDesiredVal = -198;
  task::sleep(1100);
  turnDesiredVal = 0;

  resetDriveSensors = true; // GOES FORWARD AND SCORES THE BALL
  desiredVal = 75;
  shoot(1000, 100);
  task::sleep(1000);
  
  resetDriveSensors = true; // GOES STRAIGHT BACKWARD TO SCORE THE CENTER POST BALL
  desiredVal = -500;
  task::sleep(1200);
  desiredVal = 0;

  resetDriveSensors = true; // TURNS TO FACE THE CORNER POST *untuned*
  turnDesiredVal = -98;
  task::sleep(1000);
  turnDesiredVal = 0;

  resetDriveSensors = true; // DRIVES FORWARD TO THE CENTER POST, INTAKES THE BALL, AND SCORES IT *untuned*
  desiredVal = 800;
  startIntake(1000, 300);
  shoot(600, 75);
  task::sleep(2000);
}

void skillAuton(void)
{
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