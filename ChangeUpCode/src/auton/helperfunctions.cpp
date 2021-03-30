#include "vex.h"
using namespace vex;

void startIntake(int distance, int velocity)
{
  leftintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  rightintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void shoot(int distance, int velocity)
{
  top.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void feed(int distance, int velocity)
{
  leftintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  rightintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  bot.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void fullfeed(int distance, int velocity)
{
  leftintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  rightintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  bot.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  top.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void fastShoot(int distance, int velocity)
{
  bot.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  top.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void NONPIDdrive(int distance, int velocity)
{
  LF.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  LB.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  RF.startRotateFor(-distance, rotationUnits::deg, velocity, velocityUnits::pct);
  RB.startRotateFor(-distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void headingVal(double degrees)
{
  Inert.setHeading(degrees, rotationUnits::deg);
}