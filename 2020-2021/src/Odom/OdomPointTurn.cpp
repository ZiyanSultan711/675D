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

void OdomPointTurnLookAt(float x2, float y2)
{
  float Angle = 0;
  float x1 = d1[0][0];
  float y1 = d1[0][1];

  if(y1 > y2)
  {
    Angle = 180;
  }

  Angle += atan( (x2 - x1) / (y2 - y1));

  OdomPointTurn(Angle);
}