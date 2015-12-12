#ifndef Utils_H
#define Utils_H

#include <GL/glut.h>
#include <string>

using namespace std;

#define SPACEBAR 32
#define Z_KEY 122
#define A_KEY 97
#define P_KEY 112
#define D_KEY 100
#define R_KEY 114
#define C_KEY 99
#define V_KEY 118
#define ESC_KEY 27

#define NUM_1 49
#define NUM_2 50
#define NUM_3 51
#define NUM_4 52
#define NUM_5 53
#define NUM_6 54
#define NUM_7 55
#define NUM_8 56
#define NUM_9 57

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#define ABOVE_TERRAIN_LEVEL 0.3f
#define CAMERA_SPEED 0.03f

#define NUM_OF_ROADS 19

const int FPS = 30;

extern unsigned char Buttons[3];
extern int lastx;
extern int lasty;
extern int gameScore;
extern float rotx;
extern float roty;
extern float rotz;
extern float carSpeed;
extern bool gameOver;
extern GLuint asphaltTexture;
extern GLuint grassTexture;
extern GLuint brickTexture;


int keyToNumeric(unsigned char key);
int generateRandom(int min,int max);
void drawAxes();
void drawBitmapText(string text, float x, float y, float z);
void initLighting();
void loadTextures();
#endif
