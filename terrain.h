#ifndef Terrain_H
#define  Terrain_H

#include "drawable.h"

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
  bool visible;

  Terrain() {
    pathWidth = 30.0f;
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
