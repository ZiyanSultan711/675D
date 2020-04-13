//turn functions

extern void OdomPointTurnRight(float Angle); //point turn right

extern void OdomPointTurnLeft(float Angle); //point turn left

extern void OdomPointTurn(float Angle); //determine which type of point turn -- left or right

extern void OdomPointTurnLookAt(float x2, float y2); //turn to took at a point on the field

extern bool OdomIsLookingAt(float x, float y, float currentAngle); //check to see if u are looking at a point