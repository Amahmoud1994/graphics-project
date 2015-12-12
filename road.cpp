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
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
      glBindTexture(GL_TEXTURE_2D,asphaltTexture);
      glNormal3f(0.0f,1.0f,0.0f);  // Top
      glTexCoord2f(1.0, 0.0);
      glVertex3f( -0.5f, 0.5f,0.5f);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(0.5f, 0.5f,0.5f);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(0.5f, 0.5f, -0.5f);
      glTexCoord2f(0.0, 0.0);
      glVertex3f( -0.5, 0.5f, -0.5f);

      glNormal3f(0.0f,-1.0f,0.0f);
      glVertex3f( -0.5f, -0.5f,0.5f); // Bottom
      glVertex3f(0.5f, -0.5f,0.5f);
      glVertex3f(0.5f, -0.5f, -0.5f);
      glVertex3f( -0.5, -0.5f, -0.5f);

      glNormal3f(1.0f,0.0f,0.0f);
      glVertex3f(0.5f, -0.5f,0.5f); // Right
      glVertex3f(0.5f, -0.5f,-0.5f);
      glVertex3f(0.5f, 0.5f, -0.5f);
      glVertex3f(0.5,  0.5f, 0.5f);

      glNormal3f(-1.0f,0.0f,0.0f);
      glVertex3f(-0.5f, -0.5f,0.5f); // Left
      glVertex3f(-0.5f, -0.5f,-0.5f);
      glVertex3f(-0.5f, 0.5f, -0.5f);
      glVertex3f(-0.5,  0.5f, 0.5f);

      glNormal3f(0.0f,0.0f,-1.0f);
      glVertex3f(-0.5f, -0.5f, -0.5f); // Back
      glVertex3f(0.5f, -0.5f,-0.5f);
      glVertex3f(0.5f, 0.5f, -0.5f);
      glVertex3f(-0.5,  0.5f, -0.5f);

      glNormal3f(0.0f,0.0f,1.0f);
      glVertex3f(-0.5f, -0.5f, 0.5f); // Front
      glVertex3f(0.5f, -0.5f,0.5f);
      glVertex3f(0.5f, 0.5f, 0.5f);
      glVertex3f(-0.5,  0.5f, 0.5f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
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
