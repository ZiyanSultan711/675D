#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
//globals
competition Competition;
brain Brain;
brain::sdcard SDcard;

//motors
motor frontLeft = motor(vex::PORT1, false);
motor backLeft = motor(vex::PORT2, false);
motor frontRight = motor(vex::PORT3, true);
motor backRight = motor(vex::PORT4, true);

//encoders
encoder LeftQuad(Brain.ThreeWirePort.A);
encoder RightQuad(Brain.ThreeWirePort.C);
encoder BackQuad(Brain.ThreeWirePort.E);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}