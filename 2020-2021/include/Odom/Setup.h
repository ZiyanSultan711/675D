//static variables
extern float sL; //distance from center to left sensor wheel -- inches
extern float sR; //distance from center to right sensor wheel -- inches
extern float sS; //distance from center to back sensor wheel -- inches

extern float wheelRad; //radius of tracking wheel -- inches
extern float wheelDiameter; //diameter of tracking wheel -- inches

extern float start_encoderL;
extern float start_encoderR; //starting encoder values (at last reset) -- never changed

extern float thetaR; //starting global orientation (at last reset) -- RADIAN

extern float dR [1][2]; //global position vector at last reset



//encoder and distance variables
extern float old_encoderL;
extern float old_encoderR;
extern float old_encoderS; //previous encoder values -- updated at the end of ever frame

extern float encoderL;
extern float encoderR;
extern float encoderS; //encoder values for each values -- updated every frame

extern float delta_encoderL;
extern float delta_encoderR;
extern float delta_encoderS; // change in encoder values -- updated every frame

extern float delta_L;
extern float delta_R;
extern float delta_S; // change in encoder values converted into inches -- updated every frame

extern float total_delta_encoderL;
extern float total_delta_encoderR; //total change in encoder value -- updated every frarea

extern float delta_Lr;
extern float delta_Rr; //total change in distance -- updated every frame


//vector and displacement variables
extern float d1 [1][2]; //absolute position
extern float dO [1][2]; //previous global position vector
extern float delta_d [1][2]; //global offset
extern float delta_dL [1][2]; //local offset


//orientation variables
extern float theta1; //absolute orientation - RADIAN
extern float thetaO; //previous global orientation - RADIAN
extern float thetaM; //average orientation 
extern float delta_theta; //change in orintation - RADIAN


//general odom functions
extern float GetDistanceFromAngle(float Angle); //function that returns distance traveled when given change of angle
extern void UpdateEncodersAndDistances(); //function that updates all values and distances relating to encoders
extern void UpdateOdom(); //general odom update function