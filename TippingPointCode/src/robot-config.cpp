#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

competition Competition;
controller Controller1 = vex::controller();
motor fl = vex::motor(vex::PORT18, false);   // 600 rpm
motor bl = vex::motor(vex::PORT20, false);   // 600 rpm
motor fr = vex::motor(vex::PORT13, false);   // 600 rpm
motor br = vex::motor(vex::PORT11, false);   // 600 rpm
motor lift = vex::motor(vex::PORT2, false);  // 200 rpm
motor lift2 = vex::motor(vex::PORT8, true);  // 200 rpm
motor mogo = vex::motor(vex::PORT3, false);  // 100 rpm
motor arm = vex::motor(vex::PORT9, false);   // 200 rpm
inertial InertLeft = vex::inertial(vex::PORT14);
inertial InertRight = vex::inertial(vex::PORT16);
// rotation liftPot = vex::rotation(vex::PORT7);
// rotation mogoPot = vex::rotation(vex::PORT8);

void vexcodeInit(void) {
  // Nothing to initialize
}