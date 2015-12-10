#include "cone.h"
#include <GL/glut.h>

void Cone::draw(){

        if(!this->visible) {
                return;
        }
        glPushMatrix();
      	glColor3f(0.4,0,1);
        glTranslatef(this->xCoordinate,this->yCoordinate,this->zCoordinate);
      	glRotatef(-90,1,0,0);
      	glutSolidCone(0.2, 0.5, 10, 8);
      	glPopMatrix();

}

void Cone::update(){
}
