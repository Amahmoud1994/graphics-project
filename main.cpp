#include <GL/glut.h>
#include <sstream>
#include "math.h"

#include "utils.h"
#include "terrain.h"
#include "car.h"
#include "brick.h"
#include "cone.h"

Terrain *terrain = new Terrain();
Car* car = new Car();
Brick *brick1 = new Brick(-1, 1.2);
Brick *brick2 = new Brick(-5, 0);
Cone *cone1 = new Cone(-2,1);

void render(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(20.0, 4.0, 0.0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
  glTranslatef(0, 0, 0);
  glRotatef(rotx, 1, 0, 0);
  glRotatef(roty, 0, 1, 0);
  glRotatef(rotz, 0, 0, 1);

  // Drawings Axes
  drawAxes();

  // Terrain
  terrain->draw();

  // Objects: car and obstacles
  glScaled(2,2,2);
  car->draw();
  brick1->draw();
  brick2->draw();
  cone1->draw();

  glutSwapBuffers();
}

void update() {
}

void timer(int t)
{

  glutPostRedisplay();
  glutTimerFunc(FPS, timer, 0);

}

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

void keyboardHandler(unsigned char key, int x, int y) {
}

void Mouse(int b, int s, int x, int y) {
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

int main(int argc, char** argv) {
  glutInit(&argc, argv);

  glutInitWindowSize(800, 600);
  glutInitWindowPosition(150, 150);

  glutCreateWindow("Race the Moon");
  glutDisplayFunc(render);
  glutIdleFunc(update);
  glutTimerFunc(0, timer, 0);
  glutMotionFunc(motion);
  glutKeyboardFunc(keyboardHandler);
  glutMouseFunc(Mouse);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, 800 / 600, 0.1f, 300.0f);

  glutMainLoop();

  return 0;
}
