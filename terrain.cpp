#include "terrain.h"

void Terrain::draw(){
  if(!this->visible) {
    return;
  }

	drawLanes();

	glPushMatrix();
  glTranslatef(xCoordinate, yCoordinate, zCoordinate);
  glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.1,0.1,0.1);

	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,pathWidth);
	glVertex3f(pathLength,0.0f,pathWidth);
	glVertex3f(pathLength,0.0f,0.0f);

	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(pathLength,0.0f,0.0f);
	glVertex3f(pathLength,pathThickness,0.0f);
	glVertex3f(0.0f,pathThickness,0.0f);

	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,pathWidth);
	glVertex3f(0.0f,pathThickness,pathWidth);
	glVertex3f(0.0f,pathThickness,0.0f);

	glVertex3f(pathLength,0.0f,0.0f);
	glVertex3f(pathLength,0.0f,pathWidth);
	glVertex3f(pathLength,pathThickness,pathWidth);
	glVertex3f(pathLength,pathThickness,0.0f);

	glVertex3f(0.0f,0.0f,pathWidth);
	glVertex3f(pathLength,0.0f,pathWidth);
	glVertex3f(pathLength,pathThickness,pathWidth);
	glVertex3f(0.0f,pathThickness,pathWidth);

	glVertex3f(0.0f,pathThickness,0.0f);
	glVertex3f(0.0f,pathThickness,pathWidth);
	glVertex3f(pathLength,pathThickness,pathWidth);
	glVertex3f(pathLength,pathThickness,0.0f);

	glEnd();
  glPopMatrix ();

	glPopMatrix ();
}

void Terrain::drawLanes() {
  glPushMatrix();

  glBegin(GL_QUADS);
  glColor3f(1,1,1);
  glVertex3f(lineOrgPos*1.0,0.0f,lineOrgPos*1.0);
  glVertex3f(lineOrgPos*1.0,0.0f,pathLinesWidth+5);
  glVertex3f(5+pathLinesLength,0.0f,pathLinesWidth+5);
  glVertex3f(5+pathLinesLength,0.0f,lineOrgPos*1.0);
  glEnd();

  glPopMatrix ();
}

void Terrain::update(){
}
