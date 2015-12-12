#include "brick.h"
#include "utils.h"

void Brick::draw(){
  if(!this->visible) {
    return;
  }

  //brick
  glPushMatrix();
  glTranslatef(0,0.25,this->zCoordinate);
  glScalef(this->width,0.5,0.1);
  glEnable(GL_TEXTURE_2D);
  glColor3f(1.0f,1.0f,1.0f);
  glBindTexture(GL_TEXTURE_2D,brickTexture);
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

}

void Brick::update(){
  zCoordinate += carSpeed;
}
