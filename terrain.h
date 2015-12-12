#ifndef Terrain_H
#define  Terrain_H

#include "drawable.h"
#include "utils.h"
#include <GL/glut.h>

class Terrain : public Drawable {
private:
  float angle;
  void drawLanes();
public:
  float pathWidth;
  float pathLength;
  float pathThickness;
  float pathLinesWidth;
  float pathLinesLength;
  int lineOrgPos;

  Terrain() {
    xCoordinate = -25;
    yCoordinate = 0;
    zCoordinate = -25;

    pathWidth = 50.0f;
    pathLength = 50.0f;
    pathThickness = -1.0f;
    pathLinesWidth = 2.0f;
    pathLinesLength = 5.0f;
    lineOrgPos = 5;
    visible = true;
  }

  virtual void draw();
  virtual void update();
};
#endif
