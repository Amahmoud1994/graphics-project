#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stddef.h>
#include <stdio.h>
#include "math.h"

#include "utils.h"
#include "car.h"
#include "road.h"
#include "brick.h"

using namespace std;
void timer(int);
void keyboardHandler(unsigned char, int, int);
void mouseRotation();
void initRoad();
void drawRoad();

Car* car = new Car();
Brick* brick=new Brick( 2,2);

int farestRoad = 0;
Road* roads[NUM_OF_ROADS];

void initRoad(){
  float pos = (NUM_OF_ROADS/2.0)*15;
  for(int i=0;i<NUM_OF_ROADS;i++){
    roads[i] = new Road(pos);
    pos-=15;
  }
}

void drawRoad(){
  for(int i=0;i<NUM_OF_ROADS;i++){
    roads[i]->update();
    roads[i]->draw();
  }
  if(roads[farestRoad]->zCoordinate>=(NUM_OF_ROADS/2.0)*15){
    int nextIndex = (farestRoad+NUM_OF_ROADS-1)%NUM_OF_ROADS;
    roads[farestRoad]->zCoordinate = roads[nextIndex]->zCoordinate-14.7;
    farestRoad = (farestRoad+1)%NUM_OF_ROADS;
    if(farestRoad<0)
      farestRoad = NUM_OF_ROADS-1;
  }
}
void mouseRotation(){
        glRotatef(rotx, 1, 0, 0);
        glRotatef(roty, 0, 1, 0);
        glRotatef(rotz, 0, 0, 1);
}

void motion(int x, int y)
{
        int diffx = x - lastx;
        int diffy = y - lasty;
        lastx = x;
        lasty = y;
        roty += (float) 0.2f * diffx;
        rotx += (float) 0.2f * diffy;
}

void mouse(int b, int s, int x, int y) {
        lastx = x;
        lasty = y;
}

void render(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        mouseRotation();
        drawRoad();
        car->draw();
        brick->draw();
        drawAxes();
        glPopMatrix();
        glutSwapBuffers();
}

void timer(int t) {
        glutPostRedisplay();
        glutTimerFunc(FPS, timer, 0);
}

void keyboardHandler(unsigned char key, int x, int y) {
        switch(key)
        {
          case 'd' :if(car->zCoordinate > -(3.5/2)+0.35)car->zCoordinate-=0.1 ;break;
          case 'a' :if(car->zCoordinate < (3.5/2)-0.35)car->zCoordinate+=0.1;break;
        }
      }

int main(int argc, char** argv) {
        glutInit(&argc, argv);

        glutInitWindowSize(800, 600);
        glutInitWindowPosition(150, 150);

        glutCreateWindow("Car Crash");
        glutDisplayFunc(render);
        glutTimerFunc(0, timer, 0);
        glutMotionFunc(motion);
        glutMouseFunc(mouse);
        glutKeyboardFunc(keyboardHandler);

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        loadTextures();

        glEnable(GL_DEPTH_TEST);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, 800 / 600, 0.1f, 300.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        initRoad();
        initLighting();


        glutMainLoop();

        return 0;
}
