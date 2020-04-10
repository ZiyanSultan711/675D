#include "vex.h"
using namespace vex;

float sL; //distance from center to left sensor wheel -- inches
float sR; //distance from center to right sensor wheel -- inches
float sS; //distance from center to back sensor wheel -- inches

float wheelRad = 2; //radius of tracking wheel -- inches
float wheelDiameter = wheelRad * 2; //diameter of tracking wheel -- inches

float start_encoderL = LeftQuad.rotation(rotationUnits::deg);
float start_encoderR = RightQuad.rotation(rotationUnits::deg); //starting encoder values (at last reset) -- never changed

float thetaR = 0; //starting global orientation (at last reset) -- RADIAN

float dR [1][2] {{0,0}}; //global position vector at last reset


//encoder and distance variables
float old_encoderL = 0;
float old_encoderR = 0;
float old_encoderS = 0; //previous encoder values -- updated at the end of ever frame

float encoderL;
float encoderR;
float encoderS; //encoder values for each values -- updated every frame

float delta_encoderL;
float delta_encoderR;
float delta_encoderS; // change in encoder values -- updated every frame

float delta_L;
float delta_R;
float delta_S; // change in encoder values converted into inches -- updated every frame

float total_delta_encoderL;
float total_delta_encoderR; //total change in encoder value -- updated every frarea

float delta_Lr;
float delta_Rr; //total change in distance -- updated every frame


//vector and displacement variables
float d1 [1][2] {}; //absolute position
float dO [1][2] { {dR[0][0], dR[0][1]} }; //previous global position vector
float delta_d [1][2] {}; //global offset
float delta_dL [1][2] {}; //local offset


//orientation variables
float theta1; //absolute orientation - RADIAN
float thetaO = thetaR; //previous global orientation - RADIAN
float thetaM; //average orientation 
float delta_theta; //change in orintation - RADIAN

//general odom functions
float GetDistanceFromAngle(float Angle) //function that returns distance traveled when given change of angle
{
  float circumference = wheelDiameter * M_PI;
  float Distance = circumference * (Angle/360);
  return Distance;
}

void UpdateEncodersAndDistances() //function that updates all values and distances relating to encoders
{
  //updating encoder values
  encoderL = LeftQuad.rotation(rotationUnits::deg);
  encoderR = RightQuad.rotation(rotationUnits::deg);
  encoderS = BackQuad.rotation(rotationUnits::deg);

  //calculating change in encoders
  delta_encoderL = encoderL - old_encoderL;
  delta_encoderR = encoderR - old_encoderR;
  delta_encoderS = encoderS - old_encoderS;

  //updating old encoder values
  old_encoderL = encoderL;
  old_encoderR = encoderR;
  old_encoderS = encoderS;

  //convering change in degrees to inches
  delta_L = GetDistanceFromAngle(delta_encoderL);
  delta_R = GetDistanceFromAngle(delta_encoderR);
  delta_S = GetDistanceFromAngle(delta_encoderS);

  //total change in encoder values
  total_delta_encoderL = encoderL - start_encoderL;
  total_delta_encoderR = encoderR - start_encoderR;

  //total change in distance of each wheel
  delta_Lr = GetDistanceFromAngle(total_delta_encoderL);
  delta_Lr = GetDistanceFromAngle(total_delta_encoderR);
}

void UpdateOdom() //general update function
{
  UpdateEncodersAndDistances();  //updating all encoder values and distance values

  //calculate new absolute orientation
  theta1 = thetaR + ((delta_Lr - delta_Rr)/(sL + sR));

  //calculate change in orientation
  delta_theta = theta1 - thetaO;

  if(delta_theta == 0) //no change in angle
  {
    delta_dL[0][0] = delta_S; //x
    delta_dL[0][1] = delta_R; //y
  }
  else //angle was changed
  {
    delta_dL[0][0] = ((delta_S/delta_theta) + sS) * 2 * sin(theta1/2);
    delta_dL[0][1] = ((delta_R/delta_theta) + sR) * 2 * sin(theta1/2);
  }

  //calculating average orientation
  thetaM = thetaO + (delta_theta/2);

  //convert local offset to polar coordinates, 
  float polar_r = sqrt((delta_dL[0][0] * delta_dL[0][0]) + (delta_dL[0][1] * delta_dL[0][1]));
  float polar_theta = atan(delta_dL[0][1]/delta_dL[0][0]);
  float polar_dL [1][2] {{polar_r, polar_theta}};

  //rotate by -avg orientation (which is the global offset)
  polar_theta = polar_theta - thetaM;
  polar_dL[0][1] = polar_theta;

  //convert back to cartiesan coordinates
  delta_d[0][0] = polar_r * cos(polar_theta);
  delta_d[0][1] = polar_r * sin(polar_theta);

  //calculate absolute position
  d1[0][0] = dO[0][0] + delta_d[0][0];
  d1[0][1] = dO[0][1] + delta_d[0][1];

  //update old position
  dO[0][0] = d1[0][0];
  dO[0][1] = d1[0][1];

  //update old orientation
  thetaO = theta1;
}
