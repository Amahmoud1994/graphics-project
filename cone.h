#ifndef Cone_H
#define  Cone_H

#include "drawable.h"
#include "utils.h"
#include <GL/glut.h>

class Cone : public Drawable {
public:
  int index;
  float initialZCoordinate;
  

  Cone(int index,float xCoordinate, float zCoordinate,float width) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = ABOVE_TERRAIN_LEVEL;
    this->zCoordinate = this->initialZCoordinate = zCoordinate;
    this->width = width;
    this->index;
    this->visible = true;
  }

  virtual void draw();
  virtual void update();
};
#endif
