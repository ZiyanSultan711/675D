#include "vex.h"
using namespace vex;

//turn functions
void OdomPointTurnRight(float Angle) //point turn right
{
  //pid loop to turn right until theta1 = Angle
}

void OdomPointTurnLeft(float Angle) //point turn left
{
  //pid loop to turn left until theta1 = Angle
}

void OdomPointTurn(float Angle) //determine which type of point turn -- left or right
{
  float angleToTurnTo = theta1 - Angle;
  angleToTurnTo = std::abs(angleToTurnTo);

  if(angleToTurnTo < M_PI)
  {
    OdomPointTurnLeft(Angle);
  }
  else if(angleToTurnTo > M_PI)
  {
    OdomPointTurnRight(Angle);
  }
}

void OdomPointTurnLookAt(float x, float y) // turn to look at a point on the field
{
  float Angle = 0;
  float x0 = d1[0][0];
  float y0 = d1[0][1];

  if(y0 > y)
  {
    Angle = 180;
  }

  Angle += atan( (x - x0) / (y - y0));

  OdomPointTurn(Angle);
}

bool OdomIsLookingAt(float x, float y, float currentAngle)
{
  bool isLooking = false;
  
  float Angle = 0;
  float x0 = d1[0][0];
  float y0 = d1[0][1];

  if(y0 > y)
  {
    Angle = 180;
  }

  Angle += atan( (x - x0) / (y - y0));
  

  if (currentAngle == Angle)
  {
    isLooking = true;
  }

  return isLooking;
}