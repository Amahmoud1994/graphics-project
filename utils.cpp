#include "utils.h"

unsigned char Buttons[3] = { 0 };
float rotx = 0;
float roty = 0;
float rotz = 0;
int lastx = 0;
int lasty = 0;

int keyToNumeric(unsigned char key) {
  switch (key) {
  case NUM_1:
    return 1;
  case NUM_2:
    return 2;
  case NUM_3:
    return 3;
  case NUM_4:
    return 4;
  case NUM_5:
    return 5;
  case NUM_6:
    return 6;
  case NUM_7:
    return 7;
case NUM_8:
    return 8;
  case NUM_9:
    return 9;
  default:
    return -1;
  }
}

int generateRandom(int min,int max){
  return int(min + (rand() % (int)(max - min + 1)));
}

void drawAxes() {
  glPushMatrix();

  glLineWidth(2.0);

  glBegin(GL_LINES);
  glColor3f(1,0,0); // x axis is red.
  glVertex3f(0.0f,0.0f,0.0f);
  glVertex3f(500.0f,0.0f,0.0f);
  glColor3f(0,1,0); // y axis is green.
  glVertex3f(0.0f,0.0f,0.0f);
  glVertex3f(0.0f,500.0f,0.0f);
  glColor3f(0,0,1); // z axis is blue.
  glVertex3f(0.0f,0.0f,0.0f);
  glVertex3f(0.0f,0.0f,500.0f);
  glEnd();

  glPopMatrix ();
}

void drawBitmapText(string text, float x, float y, float z) {
  glDisable(GL_TEXTURE_2D);
  glMatrixMode( GL_PROJECTION );
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, 800, 0.0, 600);
  glMatrixMode( GL_MODELVIEW );
  glPushMatrix();
  glLoadIdentity();

  glDisable( GL_DEPTH_TEST );
  glDisable(GL_LIGHTING);

  glColor3f(1.0, 0.0, 0.0);
  glRasterPos2i(x*50, y*50);

  for (unsigned int i = 0; i < text.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
  }

  glEnable( GL_DEPTH_TEST );
  glEnable(GL_LIGHTING);
  glMatrixMode( GL_PROJECTION );
  glPopMatrix();
  glMatrixMode( GL_MODELVIEW );
  glPopMatrix();
}

void initLighting(){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_SMOOTH);
        glShadeModel(GL_SMOOTH);
}
