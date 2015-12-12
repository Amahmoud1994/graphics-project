#include <GL/glut.h>
#include <sstream>
#include "math.h"
#include <vector>

#include "utils.h"
#include "terrain.h"
#include "car.h"
#include "brick.h"
#include "cone.h"

Terrain *terrain = new Terrain();

Car* car = new Car();

vector <Brick> bricks;
vector <Cone> cones;

int TCNT = 0; // Time counter

void Switch_Key(int, int, int);
void drawTextureCube(void);

void render(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(7.0, 3.0, 0.0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
  if(!gameOver)
  {
  glRotatef(rotx, 1, 0, 0);
  glRotatef(roty, 0, 1, 0);
  glRotatef(rotz, 0, 0, 1);

  //Draw the Texturing Cube
  drawTextureCube();

  // Axes
  drawAxes();

  // Terrain
  terrain->draw();

  // Car
  car->draw();

  // Bricks
  if (!bricks.empty()) {
    for(size_t i = 0; i < bricks.size(); i++) {
      bricks[i].draw();
    }
  }

  // Cones
  if (!cones.empty()) {
    for(size_t i = 0; i < cones.size(); i++) {
      cones[i].draw();
    }
  }
}else
{
  drawBitmapText("You Lost Try Again Later", 7, 10,2);
}
  glutSwapBuffers();
}

void update() {
  terrain->update();

  if (!bricks.empty()) {
    for(size_t i = 0; i < bricks.size(); i++) {
      bricks[i].update();
    }
  }

  if (!cones.empty()) {
    for(size_t i = 0; i < cones.size(); i++) {
      cones[i].update();
    }
  }
}

void timer(int t) {
  if(TCNT == 80) {
    int brickX = generateRandom(-1, -9);
    int brickZ = generateRandom(0, 3);
    Brick *brick = new Brick(brickX, brickZ);
    bricks.push_back(*brick);

    int coneX = generateRandom(-1, -9);
    int coneZ = generateRandom(0, 3);
    Cone *cone = new Cone(coneX, coneZ);
    cones.push_back(*cone);

    TCNT = 0;
  }

  TCNT++;

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

void drawTextureCube()
{
  glPushMatrix(); // The cubic body
  glColor3f(0,0,0);
  glutWireCube(50);
  glPopMatrix();
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

void Switch_Key(int key, int x, int y)
{
  switch (key) {
    case GLUT_KEY_UP    :  if(car->xCoordinate > 0)car->xCoordinate-=0.1;break;
    case GLUT_KEY_DOWN  :  if(car->xCoordinate < terrain->pathLength)car->xCoordinate+=0.1;break;
    case GLUT_KEY_RIGHT :  if(car->zCoordinate > 0)car->zCoordinate-=0.1;break;
    default             :  if(car->zCoordinate < terrain->pathWidth)car->zCoordinate+=0.1;break;
  }
}

void decScore()
{
  gameScore--;
  if(gameScore ==0)
    gameOver=true;

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
  glutSpecialFunc(Switch_Key);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

  glEnable(GL_DEPTH_TEST);

// for the Texturing Go step by step

/**

GLuint texEarthID;

glEnable(GL_DEPTH_TEST);
glEnable(GL_TEXTURE_2D);
glEnable(GL_CULL_FACE);

loadBMP(&texEarthID, "textures/earth.bmp");

//Then when loading the object
glBindTexture(GL_TEXTURE_2D,texEarthID);

*/
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, 800 / 600, 0.1f, 300.0f);

  glutMainLoop();

  return 0;
}
