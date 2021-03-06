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
#include "cone.h"

using namespace std;
void timer(int);
void keyboardHandler(unsigned char, int, int);
void mouseRotation();
void Switch_Key(int, int, int);
void initRoad();
void displayTime();
void initBricks();
void drawRoad();
void drawBricks();
void drawGrassWorld();
void drawSkymap();

Car* car = new Car();
float angleRotY=0.0;
float angleRotX=0.0;
int farestRoad = 0;
Road* roads[NUM_OF_ROADS];
Brick* bricks[NUM_OF_BRICKS];
Cone* cones[NUM_OF_BRICKS];

void initRoad(){

        float pos = (NUM_OF_ROADS/2.0)*15;
        for(int i=0; i<NUM_OF_ROADS; i++) {
                roads[i] = new Road(pos);
                pos-=15;
        }

}

void initBricks(){
  float pos = -(NUM_OF_ROADS/2.0)*50;
  float xCoordinates[3] = {1,0,-1};
  for(int i=0;i<NUM_OF_BRICKS;i++){
    bricks[i] = new Brick(i,xCoordinates[i%3],pos,1);
    pos+=30;
  }
}

void drawRoad(){

for(int i=0;i<NUM_OF_ROADS;i++){
    if(!pause)
      roads[i]->update();
    roads[i]->draw();
  }
  if(roads[farestRoad]->zCoordinate>=(NUM_OF_ROADS/2.0)*15){
    int nextIndex = (farestRoad+NUM_OF_ROADS-1)%NUM_OF_ROADS;
    roads[farestRoad]->zCoordinate = roads[nextIndex]->zCoordinate-15;
    farestRoad = (farestRoad+1)%NUM_OF_ROADS;
    if(farestRoad<0)
      farestRoad = NUM_OF_ROADS-1;
  }
}

void drawBricks(){
  for(int i=0;i<NUM_OF_BRICKS;i++){
    if(!pause){
      bricks[i]->update();
    }
    bricks[i]->draw();
  }
}

void checkCollisions(){
  for(int i=0;i<NUM_OF_BRICKS;i++){
      if(fabs(bricks[i]->zCoordinate-car->zCoordinate)<=carSpeed-0.3){
        if(fabs(bricks[i]->xCoordinate-car->xCoordinate)<=0.6){
            gameOver = true;
        }
      }
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
        if(pause){
          roty += (float) 0.2f * diffx;
          rotx += (float) 0.2f * diffy;
        }else{
            if(gameOver)
                return;
            if(diffx<0&&car->xCoordinate > -1.500)
              car->xCoordinate-=0.03;

            if(diffx>0&&car->xCoordinate < 1.500)
              car->xCoordinate+=0.03;
        }
        lastx = x;
        lasty = y;
}

void mouse(int b, int s, int x, int y) {
        lastx = x;
        lasty = y;
}

void render(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glRotatef(angleRotY,0,1,0);
        glRotatef(angleRotX,1,0,0);
        glPushMatrix();
        mouseRotation();
        drawRoad();
        drawBricks();
        drawSkymap();
        drawGrassWorld();
        if(gameOver)
        {
          car->update();
          drawBitmapText("You Lost!! Good Luck Next Time",1,9,1);
          drawBitmapText("Press r to restart",1,8.5,1);

        }
        car->draw();
        displayTime();
        glPopMatrix();
        glPopMatrix();
        glutSwapBuffers();
}

void timer(int t) {
    if(!pause && !gameOver)
        gameTimer+=0.05;
    if(int(gameTimer) % 40 ==0)
    {
      carSpeed+=0.005;
    }
    glutPostRedisplay();
    checkCollisions();
    glutTimerFunc(FPS, timer, 0);
}

void keyboardHandler(unsigned char key, int x, int y) {
    switch (key) {
      case 'p':  pause = !pause;break;
      case 'g':  gameOver = true;break;
      case 'r':  if(pause)break;gameOver = false;car->zCoordinate = 0;carSpeed = 0.5f;gameTimer=0;gameScore=4;break;
      case 'd':  if(car->xCoordinate < 1.5)car->xCoordinate+=0.03;break;
      case 'a':  if(car->xCoordinate > -1.5)car->xCoordinate-=0.03;break;
      case 27 :  exit(0);
    }
}

void Switch_Key(int key, int x, int y)
{
  switch (key) {
    case GLUT_KEY_UP:if(angleRotX<40)angleRotX++;break;
    case GLUT_KEY_DOWN:if(angleRotX>-15)angleRotX--;break;
    case GLUT_KEY_LEFT:angleRotY++;break;
    case GLUT_KEY_RIGHT:angleRotY--;break;
  }
}
void displayTime()
{

  drawBitmapText("Time :",1,11,1);
  int number=gameTimer;
  stringstream strs;
  strs << number;
  string temp_str = strs.str();
  char* char_type = (char*) temp_str.c_str();
  drawBitmapText(char_type,2.1,11,1);
}
void drawSkymap() {
        glPushMatrix();
        glScalef(200.0f,200.0f,200.0f);
        glTranslatef(0.0,0.499,0.0);
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f,1.0f,1.0f);
        glBindTexture(GL_TEXTURE_2D,skybox);

        glDisable(GL_LIGHTING);

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
        glTexCoord2f(1.0, 0.0); glVertex3f(0.5f, -0.5f,0.5f); // Right
        glTexCoord2f(1.0, 1.0); glVertex3f(0.5f, -0.5f,-0.5f);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.5f, 0.5f, -0.5f);
        glTexCoord2f(0.0, 0.0); glVertex3f(0.5,  0.5f, 0.5f);

        glNormal3f(-1.0f,0.0f,0.0f);
        glTexCoord2f(1.0, 0.0); glVertex3f(-0.5f, -0.5f,0.5f); // Left
        glTexCoord2f(1.0, 1.0); glVertex3f(-0.5f, -0.5f,-0.5f);
        glTexCoord2f(1.0, 0.0); glVertex3f(-0.5f, 0.5f, -0.5f);
        glTexCoord2f(0.0, 0.0); glVertex3f(-0.5,  0.5f, 0.5f);

        glNormal3f(0.0f,0.0f,-1.0f);
        glTexCoord2f(1.0, 0.0); glVertex3f(-0.5f, -0.5f, -0.5f); // Back
        glTexCoord2f(1.0, 1.0); glVertex3f(0.5f, -0.5f,-0.5f);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.5f, 0.5f, -0.5f);
        glTexCoord2f(0.0, 0.0); glVertex3f(-0.5,  0.5f, -0.5f);

        glNormal3f(0.0f,0.0f,1.0f);
        glTexCoord2f(1.0, 0.0); glVertex3f(-0.5f, -0.5f, 0.5f); // Front
        glTexCoord2f(1.0, 1.0); glVertex3f(0.5f, -0.5f,0.5f);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.5f, 0.5f, 0.5f);
        glTexCoord2f(0.0, 0.0); glVertex3f(-0.5,  0.5f, 0.5f);

        glEnd();
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);
        glPopMatrix();
}

void drawGrassWorld() {

        glPushMatrix();
        glScalef(200.0f,1.0f,200.0f);
        glTranslatef(0.0,0.42f,0.0f);
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f,1.0f,1.0f);
        glBindTexture(GL_TEXTURE_2D,grassTexture);

        glDisable(GL_LIGHTING);

        glBegin(GL_QUADS);
        glNormal3f(0.0f,-1.0f,0.0f);
        glTexCoord2f(1.0, 0.0); glVertex3f( -0.5f, -0.5f,0.5f);   // Bottom
        glTexCoord2f(1.0, 1.0); glVertex3f(0.5f, -0.5f,0.5f);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.5f, -0.5f, -0.5f);
        glTexCoord2f(0.0, 0.0); glVertex3f( -0.5, -0.5f, -0.5f);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);
        glPopMatrix();
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
        glutSpecialFunc(Switch_Key);

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
        initBricks();
        initLighting();


        glutMainLoop();

        return 0;
}
