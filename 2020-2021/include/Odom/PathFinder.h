
extern void OdomSimplePathFinder(int numPoints, int waypoints[numPoints][2]); //simple path finder: turn to point, drive to point, repeat
extern void OdomCurvePath(int numPoints, int waypoints[numPoints][2]); //given a set of points, splines will be made to turn the points into a curve
extern void OdomSeekPoint(float x, float y, float maxSpeed, float maxForce); //seek and find a point-- this is to to be called repeatitly

extern float normalizeVectorX(float vector[1][2]);
extern float normalizeVectorY(float vector[1][2]);
extern float getVectorMagnitude(float vector[1][2]);
extern float perpendicularVector(float a[1][2], float b[1][2]);