/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <math.h>
#include <cmath>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#include "Odom/OdomSetup.h"
#include "Odom/OdomPointTurn.h"
#include "Odom/OdomPathFinder.h"
#include "Odom/OdomDriveStraight.h"

#include "AutoRecorder/AutoRecorder.h"
#include "AutoRecorder/RecordedAutos.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)