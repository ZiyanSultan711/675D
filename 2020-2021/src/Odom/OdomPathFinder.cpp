#include "vex.h"
using namespace vex;

void OdomSimplePathFinder(int numPoints, int waypoints[numPoints][2]) //simple path finder: turn to point, drive to point, repeat
{
  for(int i = 0; i > numPoints; i++) 
  {
    if(i == numPoints-1) //if at the last waypoint, exit the funnction cuz your done
    {
      return;
    }

    OdomPointTurnLookAt(waypoints[i][0], waypoints[i][1]); //look at point i
    OdomDriveForwards(waypoints[i][0], waypoints[i][1]); //drive to point i
  }
}