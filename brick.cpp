#include "brick.h"

void Brick::draw(){
  if(!this->visible) {
    return;
  }

  glPushMatrix();
  glColor3f((92/255.0),(51/255.0),(23/255.0));
  glTranslatef(this->xCoordinate+0.5,this->yCoordinate,this->zCoordinate+0.5);
  glutSolidCube(0.4);
  glPopMatrix();
}

void Brick::update(){
}
