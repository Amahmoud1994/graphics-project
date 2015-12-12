#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stddef.h>
#include "math.h"

#include "car.h"
#include "road.h"

using namespace std;
void timer(int);
void keyboardHandler(unsigned char, int, int);
void mouseRotation();

Car* car = new Car();
Road* road = new Road(-5.0f);

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
	if (Buttons[0])
	{
		rotx += (float) 0.2f * diffy;
		roty += (float) 0.2f * diffx;
	}
}

void mouse(int b, int s, int x, int y) {
  lastx = x;
	lasty = y;

	switch (b) {
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

void render(void) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        mouseRotation();
        road->update();
        road->draw();
        car->draw();
        drawAxes();
        glPopMatrix();
        glutSwapBuffers();
}

void timer(int t) {

        glutPostRedisplay();
        glutTimerFunc(FPS, timer, 0);
}

void keyboardHandler(unsigned char key, int x, int y){

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

        glEnable(GL_DEPTH_TEST);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, 800 / 600, 0.1f, 300.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        initLighting();

        glutMainLoop();

        return 0;
}
