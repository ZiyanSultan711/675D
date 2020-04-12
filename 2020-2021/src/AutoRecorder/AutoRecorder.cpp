#include "vex.h"
using namespace vex;
using namespace std;

task AutonRecorder;
bool recording = false;

int record() //MAIN recording TASK. this will run continiously while recording is true
{
  uint8_t blank[2] = " ";
  SDcard.savefile("auto.txt", blank, 2);
  string M1;
  string M2;
  string M3;
  string M4;
  ostringstream M1_;
  ostringstream M2_;
  ostringstream M3_;
  ostringstream M4_;
  float M1speed;
  float M2speed;
  float M3speed;
  float M4speed;
  while(recording)
  {
    M1speed = frontLeft.velocity(rpm);
    M2speed = backLeft.velocity(rpm);
    M3speed = frontRight.velocity(rpm);
    M4speed = backRight.velocity(rpm);
    M1_ << "frontLeft.setVelocity("<< M1speed << ", velocityUnity::rpm);";
    M2_ << "backLeft.setVelocity("<< M2speed << ", velocityUnity::rpm);";
    M3_ << "frontRight.setVelocity("<< M3speed << ", velocityUnity::rpm);";
    M4_ << "backRight.setVelocity("<< M4speed << ", velocityUnity::rpm);";
    M1.append(M1_.str());
    M2.append(M2_.str());
    M3.append(M3_.str());
    M4.append(M4_.str());
    uint8_t M1string[M1.length()];
    uint8_t M2string[M2.length()];
    uint8_t M3string[M3.length()];
    uint8_t M4string[M4.length()];
    for(int i = 0; i < M1.length(); i++)
    {
      M1string[i] = M1[i];
    }
    
    for(int i = 0; i < M2.length(); i++)
    {
      M2string[i] = M2[i];
    }

    for(int i = 0; i < M3.length(); i++)
    {
      M3string[i] = M3[i];
    }

    for(int i = 0; i < M4.length(); i++)
    {
      M4string[i] = M4[i];
    }
    SDcard.appendfile("auto.txt", M1string, M1.length());
    SDcard.appendfile("auto.txt", M2string, M2.length());
    SDcard.appendfile("auto.txt", M3string, M3.length());
    SDcard.appendfile("auto.txt", M4string, M4.length());
    task::sleep(20);
  }
  return 1;
}

void StartRecordingAuto() //event to start recording. Starts the task
{
  recording = true;
  AutonRecorder = task(record);
}

void StopRecordingAuto() // event to stop recording auto. stops the task
{
  recording = false;
  task::stop(AutonRecorder);
}

void AutonRecordButtonEvent() // event for the button. this is called when the button is pressed, and deals with chosing to start or stop the event
{
  if(recording)
    StopRecordingAuto();
  else if(!recording)
    StartRecordingAuto();
}