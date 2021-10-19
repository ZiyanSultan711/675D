#include "vex.h"
using namespace vex;


void startDriveFwd(double distance, double velocity)
{
  fl.startRotateFor(directionType::rev, distance, rotationUnits::deg, velocity, velocityUnits::pct);
  fr.startRotateFor(directionType::fwd, distance, rotationUnits::deg, velocity, velocityUnits::pct);
  bl.startRotateFor(directionType::rev, distance, rotationUnits::deg, velocity, velocityUnits::pct);
  br.rotateFor(directionType::fwd, distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void startDriveTurn(double distance, double velocity)
{
  fl.startRotateFor(directionType::rev, distance, rotationUnits::deg, velocity, velocityUnits::pct);
  fr.startRotateFor(directionType::rev, distance, rotationUnits::deg, velocity, velocityUnits::pct);
  bl.startRotateFor(directionType::rev, distance, rotationUnits::deg, velocity, velocityUnits::pct);
  br.rotateFor(directionType::rev, distance, rotationUnits::deg, velocity, velocityUnits::pct);
}