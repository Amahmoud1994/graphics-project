#include "car.h"
#include "utils.h"
#include "math.h"

void Car::draw(){
  if(!this->visible) {
    return;
  }

  glPushMatrix();
  glTranslatef(0.0f,0,1.5f);
  // Start wheels
  glPushMatrix();
  glTranslatef(this->xCoordinate, 0.05, this->zCoordinate+0.1);
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glTranslatef(0.1f,-0.2f,-0.4f);
  glBindTexture( GL_TEXTURE_2D, tireTexture );
  drawWheel();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.2f,-0.2f,-0.4f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture( GL_TEXTURE_2D, tireTexture );
  drawWheel();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.2f,-0.2f,0.05f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture( GL_TEXTURE_2D, tireTexture );
  drawWheel();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.1f,-0.2f,0.05f);
  glEnable(GL_TEXTURE_2D);
  glBindTexture( GL_TEXTURE_2D, tireTexture );
  drawWheel();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
  // End Wheels
  glPopMatrix();


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


  //First part of the Cabout
  glPushMatrix();
  glTranslatef(this->xCoordinate-0.1,this->yCoordinate-0.05,this->zCoordinate-0.3);
  glScalef(0.2*1.2,0.2,0.2);
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

//Second Part of the Cabout
  glPushMatrix();
  glTranslatef(this->xCoordinate+0.1,this->yCoordinate-0.05,this->zCoordinate-0.3);
  glScalef(0.2*1.2,0.2,0.2);
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

  glPopMatrix();
}

void Car::update(){
  this->zCoordinate += carSpeed;
}

void Car::drawWheel()
{
    const double PI = 3.14159;

    /* top triangle */
    double i, resolution  = 0.1;
    double height = 1;
    double radius = 0.5;

    glPushMatrix();
    glTranslatef(0.15,0.25,0);
    glScalef(0.2,0.2,0.2);
    glRotatef(90,0,0,1);

    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(0, height, 0);  /* center */
        for (i = 2 * PI; i >= 0; i -= resolution)

        {
            glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
            glVertex3f(radius * cos(i), height, radius * sin(i));
        }
        /* close the loop back to 0 degrees */
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(radius, height, 0);
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(0, 0, 0);  /* center */
        for (i = 0; i <= 2 * PI; i += resolution)
        {
            glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
            glVertex3f(radius * cos(i), 0, radius * sin(i));
        }
    glEnd();

    /* middle tube */
    glBegin(GL_QUAD_STRIP);
        for (i = 0; i <= 2 * PI; i += resolution)
        {
            const float tc = ( i / (float)( 2 * PI ) );
            glTexCoord2f( tc, 0.0 );
            glVertex3f(radius * cos(i), 0, radius * sin(i));
            glTexCoord2f( tc, 1.0 );
            glVertex3f(radius * cos(i), height, radius * sin(i));
        }
        /* close the loop back to zero degrees */
        glTexCoord2f( 0.0, 0.0 );
        glVertex3f(radius, 0, 0);
        glTexCoord2f( 0.0, 1.0 );
        glVertex3f(radius, height, 0);
    glEnd();

    glPopMatrix();
}
