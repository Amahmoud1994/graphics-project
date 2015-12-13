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
  glScalef(0.2,1,0.2);
  float radius=1;
  float r=1;
  float h=1;
//  glEnable(GL_TEXTURE_2D);
//  glBindTexture(GL_TEXTURE_2D, brickTexture);
  float t,s;
  float i=0.05;

  for(s=0.0;s<1.0;s+=i)
  {
      for(t=0.0;t<=1.0;t+=i)
      {
        glPushMatrix();
      //  glScalef(3.5f,0.1f,15);
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f,1.0f,1.0f);
        glBindTexture(GL_TEXTURE_2D,coneTexture);
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

// glEnable(GL_CULL_FACE);
//   GLfloat gAngle = 0.0;
//   GLUquadricObj *IDquadric;
// IDquadric=gluNewQuadric();
// gluQuadricNormals(IDquadric, GLU_SMOOTH);
// gluQuadricTexture(IDquadric, GL_TRUE);
//
//   glBindTexture ( GL_TEXTURE_2D, brickTexture);
//   glPushMatrix();
//     glTranslatef(0,1,0);
//     glRotatef(145,1.,0.,1.);
//      glRotatef(90,0,1,0);
//     gluCylinder(IDquadric,1.0f,0.0f,1.0f,10,10);
//   glPopMatrix();
}

void Cone::update(){
  xCoordinate += CAMERA_SPEED;
}
