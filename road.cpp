#include "utils.h"
#include "road.h"

void Road::draw(){
  if(!this->visible) {
    return;
  }
  glPushMatrix();
  glColor3f(0.3f,0.3f,0.3f);
  glTranslatef(0,-0.05f,this->zCoordinate);
  glScalef(3.5f,0.1f,15);
  glutSolidCube(1);
  glPopMatrix();
}

void Road::update(){
  this->zCoordinate += carSpeed;
}
