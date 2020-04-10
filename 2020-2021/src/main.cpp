#include "vex.h"
#include <vex_triport.h>
using namespace vex;

/* 
you need to define these variables before starting
- wheel radius (wheelRad)
- starting global orientation (thetaR)
  - this is a x,y offset from a corner or something
  - if set as 0, then local position equals global position
- starting global position xy (dR)
  - the angle which the robot starts at


most important variables
- absolute global position(d1)
- absolute global orientation(theta1)
*/

void pre_auton(void) 
{
  vexcodeInit();
}
void autonomous(void) 
{
  
}
void usercontrol(void) 
{
  while (1) 
  {
    UpdateOdom();
    wait(20, msec);
  }
}
int main() 
{
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) 
  {
    wait(100, msec);
  }
}