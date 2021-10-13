#include "vex.h"
using namespace vex;



void topAuton(void)
{
  task StartDrivePID(drivePID);
  enableDrivePID = true;

  //STARTING FROM TOP OF THE FIELD AUTONOMOUS CODE WITH SELF CORRECTING PID LOOP
  resetDriveSensors = true;
  desiredVal = 200;
  task::sleep(1000);
  desiredVal = 0;

}

void botAuton(void)
{
  
}

void skillAuton(void)
{

}