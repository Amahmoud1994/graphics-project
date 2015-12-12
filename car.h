#ifndef Car_H
#define  Car_H

#include "drawable.h"
#include "utils.h"
#include <GL/glut.h>

class Car : public Drawable {
private:
  float angle;
  void drawWheel();
public:
  int health;

  Car() {
    this->xCoordinate = 0;
    this->yCoordinate = ABOVE_TERRAIN_LEVEL;
    this->zCoordinate = 0;
    this->width = 1;
    this->health      = 3;
    this->angle       = 0;
    this->visible     = true;
  }

  virtual void draw();
  virtual void update();
};
#endif
