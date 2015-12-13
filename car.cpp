#include "car.h"

void Car::draw(){
  if(!this->visible) {
    return;
  }
  glPushMatrix();
  glTranslatef(0.0f,0,1.5f);
  //glRotatef(-90,0,1,0);
  // Start wheels
  glPushMatrix();
  glTranslatef(0.1f,-0.2f,-0.4f);
  drawWheel();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.2f,-0.2f,-0.4f);
  drawWheel();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.2f,-0.2f,0.05f);
  drawWheel();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.1f,-0.2f,0.05f);
  drawWheel();
  glPopMatrix();
  // End Wheels

  //Body
  glPushMatrix(); // The cubic body
  glColor3f((92/255.0),(51/255.0),(23/255.0));
  glTranslatef(this->xCoordinate,this->yCoordinate+0.05,this->zCoordinate);
  glutSolidCube(0.44);
  glPopMatrix();

  //Cabout


  glPushMatrix(); // The cubic body
  glColor3f((92/255.0),(51/255.0),(23/255.0));
  glTranslatef(this->xCoordinate-0.1,this->yCoordinate-0.05,this->zCoordinate-0.3);
  glScalef(1.2,1,1);
  glutSolidCube(0.2);
  glPopMatrix();
  glPushMatrix(); // The cubic body
  glColor3f((92/255.0),(51/255.0),(23/255.0));
  glTranslatef(this->xCoordinate+0.1,this->yCoordinate-0.05,this->zCoordinate-0.3);
  glScalef(1.2,1,1);
  glutSolidCube(0.2);
  glPopMatrix();

  glPopMatrix();
}

void Car::update(){
  this->zCoordinate += carSpeed;
}

void Car::drawWheel(){
  GLUquadricObj* q = gluNewQuadric();
  glPushMatrix();
  glColor3f(0,0,0);
  glTranslatef(this->xCoordinate, this->yCoordinate, this->zCoordinate+0.1);
  glRotatef(angle,0,1,0);
  gluDisk(q, 0.0f, 0.1, 15, 1);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0,0,0);
  glTranslatef(this->xCoordinate, this->yCoordinate, this->zCoordinate+0.1);
  glRotatef(angle,0,1,0);
  gluCylinder(q,0.1,0.1,0.1,15,15);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0,0,0);
  glTranslatef(this->xCoordinate, this->yCoordinate, this->zCoordinate+0.1);
  glRotatef(angle,0,1,0);
  gluDisk(q, 0.0f, 0.1, 15, 1);
  glPopMatrix();
}
