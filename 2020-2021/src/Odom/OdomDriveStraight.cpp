#include "vex.h"
using namespace vex;

void OdomDriveForwards(int x, int y)
{
  if(!OdomIsLookingAt(x, y, theta1))
  {
    OdomPointTurnLookAt(x, y);
  }
  //calculate distance between current postion and the xy input (distance formula)
  //use that positon for a pid loop
}

void OdomDriveBackwards(int x, int y)
{
  
}