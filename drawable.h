#ifndef DRAWABLE_H
#define  DRAWABLE_H

class Drawable {
public:
  float xCoordinate,yCoordinate,zCoordinate;
  virtual void draw(){};
  virtual void update(){};
};

#endif
