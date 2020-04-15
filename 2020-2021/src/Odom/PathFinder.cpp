#include "vex.h"
using namespace vex;

void OdomSimplePathFinder(int numPoints, int waypoints[20][2]) //simple path finder: turn to point, drive to point, repeat
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

void OdomCurvePath(int numPoints, int waypoints[20][2]) //given a set of points, splines will be made to turn the points into a curve
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
  calc::spline path; //create a spline object
  path.set_points(X_points, Y_points, true); //set the points, and create the path. input the x and y points into the natural spline calculator
  /*

  now, the path is created as a function
  the fuction can be called through path(x). this will return a double of the y position
  this function can be used to follow through the path

  example:

  double point = path(1.5);  this is the interpolated value at 1.5

  */
}

void OdomSeekPoint(float x, float y, float maxSpeed, float currentSpeed, float maxForce) //seek and find a point-- this is to to be called repeatitly
{
  //speeds for inside and outside wheel pairs. they will be assigned later
  float outsideWheelSpeed = maxSpeed;
  float insideWheelSpeed;

  //speeds of left and right wheel
  float leftSideSpeed;
  float rightSideSpeed;

  float target[1][2] = {{x,y}}; // creating 2d array with the point we are looking for
  float location[1][2] = {{d1[0][0], d1[0][1]}}; //crearing 2d with our current point

  float desired[1][2] { {target[0][0] - location[0][0], target[0][1] - location[0][1]} }; //a vector that points from roboy location to target

  //normalizing the vector
  desired[0][0] = normalizeVectorX(desired);
  desired[0][1] = normalizeVectorY(desired);

  //scaling the vector to max speed
  desired[0][0] = desired[0][0] * maxSpeed;
  desired[0][1] = desired[0][1] * maxSpeed;

  float currentVelocity[1][2] = {{std::cos(theta1), std::cos(theta1)}}; //a velocity vector that points in the direction of movement

  //normalizing the vector
  currentVelocity[0][0] = normalizeVectorX(currentVelocity);
  currentVelocity[0][1] = normalizeVectorY(currentVelocity);

  //scaling velovity vector
  currentVelocity[0][0] = currentVelocity[0][0] * currentSpeed;
  currentVelocity[0][1] = currentVelocity[0][1] * currentSpeed;

  float force[1][2] = { {desired[0][0] - currentVelocity[0][0], desired[0][0] - currentVelocity[0][0]} }; //creating force vector

  if(getVectorMagnitude(force) > maxForce) //ensuring the force vector is limited at max force
  {
    force[0][0] = normalizeVectorX(force);
    force[0][1] = normalizeVectorY(force);

    force[0][0] = force[0][0] * maxForce;
    force[0][1] = force[0][1] * maxForce;

    insideWheelSpeed = maxSpeed/10;
  }
  else if(getVectorMagnitude(force) == 0) //if force is 0, then we are on path and we should drive at max speed
  {
    insideWheelSpeed = maxSpeed;
  }
  else //all other scenaries
  {
    float r = (getVectorMagnitude(force)/maxForce);
    float speedDif = maxSpeed - (maxSpeed/10);
    float addedSpeed = r*speedDif;

    insideWheelSpeed = (maxSpeed/10) + addedSpeed;
  }

  float perpendicular = perpendicularVector(desired, currentVelocity);
  if(perpendicular < 0)
  {
    rightSideSpeed = insideWheelSpeed;
    leftSideSpeed = outsideWheelSpeed;
  }
  else if(perpendicular > 0)
  {
    rightSideSpeed = outsideWheelSpeed;
    leftSideSpeed = insideWheelSpeed;
  }
  else
  {
    rightSideSpeed = maxSpeed;
    leftSideSpeed = maxSpeed;
  }
  
  /*
  * we have the right side and left side speeds now
  * now we just have to make them move :)
  */

}

float normalizeVectorX(float vector[1][2])
{
  float mag = sqrtf( (vector[0][0] * vector[0][0]) + (vector[0][1] * vector[0][1]) );
  vector[0][0] = vector[0][0]/mag;
  return vector[0][0];
}
float normalizeVectorY(float vector[1][2])
{
  float mag = sqrtf( (vector[0][0] * vector[0][0]) + (vector[0][1] * vector[0][1]) );
  vector[0][1] = vector[0][1]/mag;
  return vector[0][1];
}
float getVectorMagnitude(float vector[1][2])
{
  float mag = sqrtf( (vector[0][0] * vector[0][0]) + (vector[0][1] * vector[0][1]) );
  return mag;
}
float perpendicularVector(float a[1][2], float b[1][2])
{
  float ax = a[0][0];
  float ay = a[0][1];
  float bx = b[0][0];
  float by = b[0][1];
  float perpendicular = (-ax * by) + (ay * bx);
  return perpendicular;
}