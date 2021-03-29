#include "vex.h"
using namespace vex;

void pre_auton(void) 
{
  vexcodeInit();
  Inert = vex::inertial(vex::PORT21);
  Inert.calibrate();
  // waits for the Inertial Sensor to calibrate
  while (Inert.isCalibrating()) {
    wait(100, msec);
  }
}

void autonomous(void) 
{
/*
  task StartDrivePID(drivePID);
  enableDrivePID = true;
  resetDriveSensors = true;
  desiredVal = 0;
  turnDesiredVal = 98;
  resetDriveSensors = true;
*/

  topAuton();
  //botAuton();
  //skillAuton();
}

void usercontrol(void) 
{
  enableDrivePID = false;
  enableTurnRightPID = false;
  while (1) 
  {
    LB.spin(vex::directionType::fwd, -Controller1.Axis3.value() - (Controller1.Axis1.value() * .5), vex::velocityUnits::pct);
    RB.spin(vex::directionType::rev, -Controller1.Axis3.value() + (Controller1.Axis1.value() * .5), vex::velocityUnits::pct);
    LF.spin(vex::directionType::fwd, -Controller1.Axis3.value() - (Controller1.Axis1.value() * .5), vex::velocityUnits::pct);
    RF.spin(vex::directionType::rev, -Controller1.Axis3.value() + (Controller1.Axis1.value() * .5), vex::velocityUnits::pct); //drive code (turning is slowed to .7 cuz i suck but ishaan is good)
    
  if (Controller1.ButtonL1.pressing())
  {
    top.spin(vex::directionType::fwd, 97, velocityUnits::pct);
  }
  else if (Controller1.ButtonL2.pressing())
  {
    top.spin(vex::directionType::rev, 100, velocityUnits::pct);
  }
  else 
  {
    top.stop();
    top.setBrake(brakeType::coast);
  } // this makes left triggers control the top roller only. i never really used this but it was there just incase
  

  if (Controller1.ButtonX.pressing())//this entire section seems complicated but its simple. x and a controlled both top and bottom. i used most frequently to score because that worked the best
  {
    top.spin(vex::directionType::fwd, 97, velocityUnits::pct);
    bot.spin(vex::directionType::fwd, 100, velocityUnits::pct);
  }
  else if (Controller1.ButtonB.pressing())
  {
    top.spin(vex::directionType::rev, 100, velocityUnits::pct);
    bot.spin(vex::directionType::rev, 100, velocityUnits::pct);
  }
  else if (Controller1.ButtonR1.pressing()) //right triggers controlled intake. weird thing about the intake is that it worked best when intakes AND bottom rollers run at the same time
  {
    leftintake.spin(vex::directionType::fwd, 70, velocityUnits::pct);
    rightintake.spin(vex::directionType::fwd, 70, velocityUnits::pct);
    bot.spin(vex::directionType::fwd, 100, velocityUnits::pct);

  }
  else if (Controller1.ButtonR2.pressing())
  {
    leftintake.spin(vex::directionType::rev, 70, velocityUnits::pct);
    rightintake.spin(vex::directionType::rev, 70, velocityUnits::pct);
    bot.spin(vex::directionType::rev, 100, velocityUnits::pct);

  }
  else 
  {
    leftintake.stop();
    rightintake.stop();
    bot.stop();
    leftintake.setBrake(brakeType::coast);
    rightintake.setBrake(brakeType::coast);
  }

    wait(20, msec); 
  }
}


int main() 
{
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}