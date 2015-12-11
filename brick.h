#ifndef Brick_H
#define  Brick_H

#include "drawable.h"
#include "utils.h"
#include <GL/glut.h>

class Brick : public Drawable {
public:
  bool visible;

  Brick(float xCoordinate, float zCoordinate) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = ABOVE_TERRAIN_LEVEL;
    this->zCoordinate = zCoordinate;
    this->visible     = true;
  }

  virtual void draw();
  virtual void update();
};
#endif
