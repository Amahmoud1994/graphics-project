#include "brick.h"

void Brick::draw(){
  if(!this->visible) {
    return;
  }

  glPushMatrix();
  glColor3f((92/255.0),(51/255.0),(23/255.0));
  glTranslatef(this->xCoordinate,this->yCoordinate+0.2,this->zCoordinate);
  glutSolidCube(1);
  glPopMatrix();
}

void Brick::update(){
  zCoordinate += carSpeed;
}
