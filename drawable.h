#ifndef DRAWABLE_H
#define  DRAWABLE_H

class Drawable {
public:
  float xCoordinate,yCoordinate,zCoordinate;
  float width;
  bool visible;
  virtual void draw(){};
  virtual void update(){};
};

#endif
