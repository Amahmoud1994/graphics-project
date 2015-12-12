#ifndef Road_H
#define  Road_H

#include "drawable.h"
#include "utils.h"
#include <GL/glut.h>

class Road : public Drawable {
private:
  void drawWhiteLine(float);
public:

  Road(float zCoordinate) {
    this->xCoordinate = 0;
    this->yCoordinate = ABOVE_TERRAIN_LEVEL;
    this->zCoordinate = zCoordinate;
    this->visible     = true;
  }

  virtual void draw();
  virtual void update();
};
#endif
