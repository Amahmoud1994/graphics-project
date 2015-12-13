#include "cone.h"
#include "math.h"
#include "utils.h"

void Cone::draw(){
  if(!this->visible) {
    return;
  }
  glPushMatrix();
  glScalef(0.2,1,0.2);
  float radius=1;
  float r=1;
  float h=1;
 glEnable(GL_TEXTURE_2D);
 glBindTexture(GL_TEXTURE_2D, coneTexture);
  float t,s;
  //The i controlles how many layers will we draw
  // so it will take a lot of processing so we will increament the t & s by 1/2 i
  float i=0.05;

  for(s=0.0;s<1.0;s+=(i/2))
  {
      for(t=0.0;t<=1.0;t+=(i/2))
      {
        glPushMatrix();
        glColor3f(1.0f,1.0f,1.0f);
          float r=((h-t)/h)*radius;
          glBegin(GL_POLYGON);
          glTexCoord2f(s,t);
          glVertex3f(r*i,t,r*i);
          glTexCoord2f(s+i,t);
          glVertex3f(r*cos(2*M_PI*(s+i)),t,r*sin(2*M_PI*(s+i)));
          glTexCoord2f(s+i,t+i);
          glVertex3f(r*cos(2*M_PI*(s+i)),(t+i),r*sin(2*M_PI*(s+i)));
          glTexCoord2f(s,t+i);
          glVertex3f(r*cos(2*M_PI*s),(t+i),r*sin(2*M_PI*s));
          glEnd();
          glPopMatrix();

      }
  }

  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void Cone::update(){
  xCoordinate += CAMERA_SPEED;
}
