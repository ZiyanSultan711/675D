#include "main.h"

const int DRIVE_SPEED = 122; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries ot heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

///
// Constants
///

// Reset all constants to default (what's in setup.hpp is default)
void
reset_constants() {
  reset_slew_min_power();
  reset_slew_distance();
  reset_fw_drive_constants();
  reset_bw_drive_constants();
  reset_turn_constants();
  reset_turn_i_constants();
  reset_swing_constants();
}

// Functions to change constants
// (if the robot has different weight to it, sometimes we need to change constants)

void
one_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}

void
two_mogo_constants() {
  set_slew_min_power(80, 80);
  set_slew_distance(7, 7);
  set_fw_drive_constants(0.45, 5);
  set_bw_drive_constants(0.375, 4);
  set_turn_constants(5, 0.003, 35);
  set_turn_i_constants(15, 30);
  set_swing_constants(12, 35);
}


void
example_auto() {
  // All drive movements use the "set_drive_pid" function
  // the first parameter is the type of motion (drive, turn, r_swing, l_swing)

  // drive example
  // The second parameter is target inches
  // The third parameter is max speed the robot will drive at
  // The fourth parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();

  set_drive_pid(drive, -12, DRIVE_SPEED);
  wait_drive();

  // turn example
  // The second parameter is target degrees
  // The third parameter is max speed the robot will drive at


  set_drive_pid(turn, 90, TURN_SPEED);
  wait_drive();

  set_drive_pid(turn, 45, TURN_SPEED);
  wait_drive();

  // Wait Until and Changing Max Speed
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 12 inches, the robot will travel the remaining distance at a max speed of 40
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_until(12);
  set_max_speed(40); // After driving 12 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  wait_drive();

  // swing example
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive

  set_drive_pid(l_swing, 45, SWING_SPEED);
  wait_drive();

  set_drive_pid(r_swing, 0, SWING_SPEED);
  wait_drive();
}

////
// R: 2M + Match Loads
////
void
auto_1(){
  pros::Task start_timer(check_for_time);

  start_flipout();

  set_drive_pid(drive, 42, DRIVE_SPEED); //fwd towards yellow mogo
  wait_until(41);
  claw_close();

  wait_drive();

  set_drive_pid(drive, -43, DRIVE_SPEED); //drives bwd with mogo
  wait_until(-21);
  claw_open(); //drops off mogo in zone

  wait_drive(); //continues driving bwd

  set_drive_pid(turn, -35, TURN_SPEED); //turns to face middle yellow mogo
  wait_drive();

  set_drive_pid(drive, 55, DRIVE_SPEED); //drives fwd to middle yellow mogo
  wait_drive();

  claw_close(); //grabs middle yellow mogo

  set_drive_pid(drive, -40, DRIVE_SPEED); //drives bwd holding middle yellow mogo
  wait_drive();

  claw_open();

  set_drive_pid(drive, -14, DRIVE_SPEED); //drives bwd
  wait_drive();

  set_drive_pid(turn, -138, TURN_SPEED); //turns to line up with alliance mogo
  start_mogo_down(200); //mogo tilter begins to come down
  wait_drive();

  set_drive_pid(drive, -22, DRIVE_SPEED); //drives bwd into alliance mogo
  wait_until(-16);
  set_max_speed(80); //lowers speed when close to mogo in order to lock mogo properly

  wait_drive();

  start_lift_to(400, -120); //lift comes up for match loads
  mogo_mid(200); //mogo is picked up

  start_intake(550); //intake starts running

  set_drive_pid(drive, 18, DRIVE_SPEED); //drives fwd to start match loads
  wait_drive();

  while(!is_time_up){ //match load process. continues until 12 seconds then exists loop
    if(!is_time_up){
      set_drive_pid(drive, -8, DRIVE_SPEED);
      wait_drive();
    }
    if(!is_time_up){
      set_drive_pid(drive, 8, DRIVE_SPEED);
      wait_drive();
    }
  }

  stop_intake();
  mogo_down(45);
  mogo_is_down = true;
  mogo_is_sensed = true;
}

////
// L: 1M + Match Loads
////
void
auto_2(){

  set_heading_constants(8, 20);
  set_slew_min_power(100, 100);
  set_slew_distance(6, 6);
  set_drive_pid(drive, 24, DRIVE_SPEED, true);
  wait_drive();


  set_drive_pid(drive, -24, DRIVE_SPEED, true);
  wait_drive();

  set_heading_constants(8, 24);
  set_drive_pid(drive, 24, DRIVE_SPEED);
  wait_drive();


  set_drive_pid(drive, -24, DRIVE_SPEED);
  wait_drive();
}

////
// R: 1M + Match Load (not letting go of mogo)
////
void
auto_3(){

}

////
// R: 1M + fielding (not letting go of mogo)
////
void
auto_4(){

}

////
// R: 1M (mid) + Match Load
////
void
auto_5(){

}

////
// R: 1M (mid)(fake) + Match Load
////
void
auto_6(){

}

////
// R:
////
void
auto_7(){

}

////
//
////
void
auto_8(){

}

////
// SKILLS AUTO TEMP
////
void
auto_9(){
  start_flipout();

  set_drive_pid(drive, -70, 100);
  wait_drive();

  set_drive_pid(drive, 50, 100);
  wait_drive();

  set_drive_pid(turn, 90, 80);
  wait_drive();

  mogo_down(100);

  set_drive_pid(drive, -14, 60);
  wait_drive();

  mogo_mid(75);

  set_drive_pid(drive, -10, 70);
  wait_drive();

  set_drive_pid(drive, 24, 70);
  wait_drive();

  set_drive_pid(turn, 0, 60);
  start_lift_to(400, 100);
  wait_drive();

  start_intake(500);

  set_drive_pid(drive, 30, 40);
  wait_drive();

  set_drive_pid(drive, -12, 40);
  wait_drive();

  set_drive_pid(drive, 12, 40);
  wait_drive();

  set_drive_pid(drive, -12, 40);
  wait_drive();

  set_drive_pid(drive, 12, 40);
  wait_drive();

  stop_intake();

  set_drive_pid(drive, -12, 60);
  wait_drive();

  start_lift_to(0, 100);

  set_drive_pid(turn, 140, 80);
  wait_drive();



}

////
//
////
void
auto_10(){

}
