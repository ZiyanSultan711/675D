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

void OdomCurvePath(int numPoints, int waypoints[numPoints][2]) //given a set of points, splines will be made to turn the points into a curve
{
  std::vector<double> X_points; //vector list of x points
  std::vector<double> Y_points; //vector list of y poi nts

  bool swapped = false; //is the list swapped? this is needed because the set_points only takes input in order

  if(waypoints[0][0] > waypoints[1][0]) //if the first x point is larger than the second, then the list is swapped
  {
    swapped = true;
  }

  for (int i = 0; i < numPoints; i++)
  {
    if(!swapped) //if not swapped, then add x and y from input 2d array into vector list
    {
      X_points.push_back(waypoints[i][0]);
      Y_points.push_back(waypoints[i][1]);
    }
    else if(swapped) //is the list is swapped, do the same thing but backwards
    {
      X_points.push_back(waypoints[numPoints-1-i][0]);
      Y_points.push_back(waypoints[numPoints-1-i][1]);
    }
  }
  calc::spline path; //create a path object
  path.set_points(X_points, Y_points); //set the points, and create the path. input the x and y points into the natural spline calculator
  /*

  now, the path is created as a function
  the fuction can be called through path(x). this will return a double of the y position
  this function can be used to follow through the path

  example:

  double point = path(1);  this is the interpolated value at 1.5

  */
}