#include "cone.h"
#include "math.h"
#include "utils.h"
void Cone::draw(){
  if(!this->visible) {
    return;
  }

  // glPushMatrix();
  // glColor3f(0.4,0,1);
  // glTranslatef(this->xCoordinate,this->yCoordinate,this->zCoordinate);
  // glRotatef(-90,1,0,0);
  // glutSolidCone(0.2, 0.5, 10, 8);
  // glPopMatrix();

  glPushMatrix();
  float radius=1;
  float r=1;
  float h=1;
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, brickTexture);
  float t,s;
  float i=0.05;

  for(s=0.0;s<1.0;s+=i)
  {
      for(t=0.0;t<=1.0;t+=i)
      {
          float r=((h-t)/h)*radius;
          glBegin(GL_POLYGON);
          glTexCoord2f(s,t);
          glVertex3f(r*cos(2*M_PI*s),t,r*sin(2*M_PI*s));
          glTexCoord2f(s+i,t);
          glVertex3f(r*cos(2*M_PI*(s+i)),t,r*sin(2*M_PI*(s+i)));
          glTexCoord2f(s+i,t+i);
          glVertex3f(r*cos(2*M_PI*(s+i)),(t+i),r*sin(2*M_PI*(s+i)));
          glTexCoord2f(s,t+i);
          glVertex3f(r*cos(2*M_PI*s),(t+i),r*sin(2*M_PI*s));
          glEnd();
      }

  }

  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void Cone::update(){
  xCoordinate += CAMERA_SPEED;
}
