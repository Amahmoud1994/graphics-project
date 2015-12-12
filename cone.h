#ifndef Cone_H
#define  Cone_H

#include "drawable.h"
#include "utils.h"
#include <GL/glut.h>

class Cone : public Drawable {
public:

  Cone(float xCoordinate, float zCoordinate) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = ABOVE_TERRAIN_LEVEL;
    this->zCoordinate = zCoordinate;
    this->visible     = true;
  }

  virtual void draw();
  virtual void update();
};
#endif
