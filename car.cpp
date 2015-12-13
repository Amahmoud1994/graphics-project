#include "car.h"
#include "utils.h"

void Car::draw(){
  if(!this->visible) {
    return;
  }
  glPushMatrix();
  glTranslatef(0.0f,0,1.5f);
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
  glPushMatrix();
  glTranslatef(this->xCoordinate,this->yCoordinate+0.05,this->zCoordinate);
  glScalef(0.44,0.44,0.44);
  glEnable(GL_TEXTURE_2D);
  glColor3f(1.0f,1.0f,1.0f);
  glBindTexture(GL_TEXTURE_2D,carBodyTexture);
  glBegin(GL_QUADS);
  glNormal3f(0.0f,1.0f,0.0f); // Top
  glTexCoord2f(1.0, 0.0);
  glVertex3f( -0.5f, 0.5f,0.5f);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(0.5f, 0.5f,0.5f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2f(0.0, 0.0);
  glVertex3f( -0.5, 0.5f, -0.5f);

  glNormal3f(1.0f,0.0f,0.0f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(0.5f, -0.5f,0.5f); // Right
  glTexCoord2f(1.0, 1.0);
  glVertex3f(0.5f, -0.5f,-0.5f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(0.5,  0.5f, 0.5f);

  glNormal3f(-1.0f,0.0f,0.0f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(-0.5f, -0.5f,0.5f); // Left
  glTexCoord2f(1.0, 1.0);
  glVertex3f(-0.5f, -0.5f,-0.5f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-0.5,  0.5f, 0.5f);

  glNormal3f(0.0f,0.0f,-1.0f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(-0.5f, -0.5f, -0.5f); // Back
  glTexCoord2f(1.0, 1.0);
  glVertex3f(0.5f, -0.5f,-0.5f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-0.5,  0.5f, -0.5f);

  glNormal3f(0.0f,0.0f,1.0f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(-0.5f, -0.5f, 0.5f); // Front
  glTexCoord2f(1.0, 1.0);
  glVertex3f(0.5f, -0.5f,0.5f);
  glTexCoord2f(1.0, 0.0);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-0.5,  0.5f, 0.5f);
  glEnd();
  glDisable(GL_TEXTURE_2D);
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
