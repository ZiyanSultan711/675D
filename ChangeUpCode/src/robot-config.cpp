#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

competition Competition;
controller Controller1 = vex::controller();
motor top = vex::motor(vex::PORT12, false); //600 rpm
motor bot = vex::motor(vex::PORT3, false); //600 rpm
motor leftintake = vex::motor(vex::PORT14, true); //600 rpm
motor rightintake = vex::motor(vex::PORT13, false); //600 rpm
inertial Inert = vex::inertial(vex::PORT21);

motor LB = vex::motor(vex::PORT17);
motor LF = vex::motor(vex::PORT16);
motor RB = vex::motor(vex::PORT20);
motor RF = vex::motor(vex::PORT18);


void vexcodeInit(void) {
  // Nothing to initialize
}