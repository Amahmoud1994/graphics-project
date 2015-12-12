#include "utils.h"
#include "road.h"

void Road::draw(){
  if(!this->visible) {
    return;
  }
  glPushMatrix();
  glColor3f(0.3f,0.3f,0.3f);
  glTranslatef(0,-0.05f,this->zCoordinate);

  //ground
  glPushMatrix();
  glScalef(3.5f,0.1f,15);
  glutSolidCube(1);
  glPopMatrix();

  //white lines
  drawWhiteLine(5);
  drawWhiteLine(0);
  drawWhiteLine(-5);

  glPopMatrix();
}

void Road::update(){
  this->zCoordinate += carSpeed;
}

void Road::drawWhiteLine(float zCoordinate){
    glPushMatrix();
    glTranslatef(0,0.01,zCoordinate);
    glColor3f(1,1,1);
    glScalef(0.2,0.1,3);
    glutSolidCube(1);
    glPopMatrix();
}
