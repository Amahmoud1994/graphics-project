#include <GL/glut.h>
#include <iostream>
#include <string>
#include <sstream>
#include "math.h"


#include "attacker.h"
#include "camera.h"

using namespace std;

void drawAxes();
void timer(int);
void keyboardHandler(unsigned char, int, int);
void drawBitmapText(string, float, float, float);

const int FPS = 33;

Camera* camera = new Camera(0.0,10.0,10.0,0.0,0.0,0.0);
Attacker* attacker = new Attacker();

bool paused = false;
bool gameOver = false;
bool cinematic = false;

void timer(int t)
{
  if(!paused) {

          if(cinematic) {
                  camera->setXAngle(camera->getXAngle() + 0.5);
                  camera->setYAngle(camera->getYAngle() + 0.5);
                  camera->setZAngle(camera->getZAngle() + 0.5);
          } else {
                  camera->setXAngle(0.0);
                  camera->setYAngle(0.0);
                  camera->setZAngle(0.0);
          }



                  }
  glutPostRedisplay();
  glutTimerFunc(FPS, timer, 0);

}

void initLighting(){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_SMOOTH);
        glShadeModel(GL_SMOOTH);
}

void render(void) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(!gameOver) {
                drawBitmapText("Cost of Defender --> 150 ", 0.5, 11.5, 0);
                drawBitmapText("Cost of Resource Gatherer --> 100 ", 0.5, 11.0, 0);
        }

        glutSwapBuffers();
}

void drawBitmapText(string text, float x, float y, float z)
{
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

        for (unsigned int i = 0; i < text.size(); i++)
        {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
        }

        glEnable( GL_DEPTH_TEST );
        glEnable(GL_LIGHTING);
        glMatrixMode( GL_PROJECTION );
        glPopMatrix();
        glMatrixMode( GL_MODELVIEW );
        glPopMatrix();

}

void drawAxes(void){
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
void keyboardHandler(unsigned char key, int x, int y){

        if(key == Z_KEY && !cinematic) {
                camera->setYCoordinate(camera->getYCoordinate()+0.5);
                camera->setZCoordinate(camera->getZCoordinate()+0.5);
        }
        if(key == A_KEY && !cinematic) {
                camera->setYCoordinate(camera->getYCoordinate()-0.5);
                camera->setZCoordinate(camera->getZCoordinate()-0.5);
        }
}

int main(int argc, char** argv) {
        glutInit(&argc, argv);

        glutInitWindowSize(800, 600);
        glutInitWindowPosition(150, 150);

        glutCreateWindow("Graphics Project");
        glutDisplayFunc(render);
        glutTimerFunc(0, timer, 0);
        glutKeyboardFunc(keyboardHandler);

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        glEnable(GL_DEPTH_TEST);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, 800 / 600, 0.1f, 300.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0f, 2.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        initLighting();

        glutMainLoop();

        return 0;
}
