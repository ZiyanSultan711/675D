#include "vex.h"
using namespace vex;


void armRotate(int direction, int distance, int velocity)
{
  arm.rotateFor(directionType::fwd, direction*distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

void armStartRotate(int direction, int distance, int velocity)
{
  arm.startRotateFor(directionType::fwd, direction*distance, rotationUnits::deg, velocity, velocityUnits::pct);
}

