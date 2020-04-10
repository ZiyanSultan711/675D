#include "vex.h"
using namespace vex;

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