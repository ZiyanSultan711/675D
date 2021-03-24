#include "vex.h"
using namespace vex;

void startIntake(int distance, int velocity)
{
  leftintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  rightintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void shoot(int distance, int velocity)
{
  top.startRotateFor(distance, rotationUnits::deg, velocity, vex::velocityUnits::pct);
}

void feed(int distance, int velocity)
{
  leftintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  rightintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  bot.startRotateFor(distance, rotationUnits::deg, velocity, vex::velocityUnits::pct);
}

void fullfeed(int distance, int velocity)
{
  leftintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  rightintake.startRotateFor(distance, rotationUnits::deg, velocity, velocityUnits::pct);
  bot.startRotateFor(distance, rotationUnits::deg, velocity, vex::velocityUnits::pct);
  top.startRotateFor(distance, rotationUnits::deg, velocity, vex::velocityUnits::pct);
}