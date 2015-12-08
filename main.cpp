#include <GL/glut.h>
#include <iostream>
#include <string>
#include <sstream>
#include "math.h"

#include "variables.h"
#include "car.h"
#include "utils.h"

using namespace std;

void drawPathLines();
void drawPath();
void drawAxes();
void timer(int);
void keyboardHandler(unsigned char, int, int);
void drawBitmapText(string, float, float, float);

const int FPS = 33;

bool paused = false;
bool gameOver = false;
bool cinematic = false;

Car* car = new Car(0);

void motion(int x, int y)
{
	int diffx = x - lastx;
	int diffy = y - lasty;
	lastx = x;
	lasty = y;
	if (Buttons[0])
	{
		rotx += (float) 0.5f * diffy;
		roty += (float) 0.5f * diffx;
	}
}

void Mouse(int b, int s, int x, int y)
{
  lastx = x;
	lasty = y;
	switch (b)
	{
	case GLUT_LEFT_BUTTON:
		Buttons[0] = ((GLUT_DOWN == s) ? 1 : 0);
		break;
	case GLUT_MIDDLE_BUTTON:
		Buttons[1] = ((GLUT_DOWN == s) ? 1 : 0);
		break;
	case GLUT_RIGHT_BUTTON:
		Buttons[2] = ((GLUT_DOWN == s) ? 1 : 0);
		break;
	default:
		break;
	}
}

void timer(int t)
{
  if(!paused) {

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

        glPushMatrix();
        glTranslatef(0, 0, 0);
	      glRotatef(rotx, 1, 0, 0);
	      glRotatef(roty, 0, 1, 0);
	      glRotatef(rotz, 0, 0, 1);
        drawAxes();
				drawPathLines();
				drawPath();
        glPushMatrix();
        glScaled(2,2,2);
        car->draw();
        glPopMatrix();
        glPopMatrix();

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

void drawPath(void)
{
	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0,0,0); // x axis is red.
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,pathWidth);
	glVertex3f(pathLength,0.0f,pathWidth);
	glVertex3f(pathLength,0.0f,0.0f);
	glEnd();

	glPopMatrix ();

}

void drawPathLines(void)
{
	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1,1,1); // x axis is red.
	glVertex3f(lineOrgPos*1.0,0.0f,lineOrgPos*1.0);
	glVertex3f(lineOrgPos*1.0,0.0f,pathLinesWidth+5);
	glVertex3f(5+pathLinesLength,0.0f,pathLinesWidth+5);
	glVertex3f(5+pathLinesLength,0.0f,lineOrgPos*1.0);
	glEnd();

	glPopMatrix ();

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

}

int main(int argc, char** argv) {
        glutInit(&argc, argv);

        glutInitWindowSize(800, 600);
        glutInitWindowPosition(150, 150);

        glutCreateWindow("Graphics Project");
        glutDisplayFunc(render);
        glutTimerFunc(0, timer, 0);
        glutMouseFunc(Mouse);
	      glutMotionFunc(motion);
        glutKeyboardFunc(keyboardHandler);

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

        glEnable(GL_DEPTH_TEST);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, 800 / 600, 0.1f, 300.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(15.0f, 15.0f, 15.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

      //  initLighting();

        glutMainLoop();

        return 0;
}
