#include <GL/glut.h>
#include <iostream>
#include "car.h"
#include "utils.h"
using namespace std;

void Car::draw(){

        if(!this->visible) {
                return;
        }

        // Start wheels

        glPushMatrix();
        glTranslatef(0.6f,-0.2f,0.1f);
        drawWheel();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.3f,-0.2f,0.1f);
        drawWheel();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.3f,-0.2f,0.6f);
        drawWheel();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.6f,-0.2f,0.6f);
        drawWheel();
        glPopMatrix();

        // End Wheels

        //Body
        glPushMatrix(); // The cubic body
        glColor3f((92/255.0),(51/255.0),(23/255.0));
        glTranslatef(this->xCoordinate+0.5,this->yCoordinate,this->zCoordinate+0.5);
        glutSolidCube(0.4);
        glPopMatrix();

        //Cabout
        glPushMatrix(); // The cubic body
        glColor3f((92/255.0),(51/255.0),(23/255.0));
        glTranslatef(this->xCoordinate+0.25,this->yCoordinate-0.05,this->zCoordinate+0.4);
        glutSolidCube(0.2);
        glPopMatrix();
        glPushMatrix(); // The cubic body
        glColor3f((92/255.0),(51/255.0),(23/255.0));
        glTranslatef(this->xCoordinate+0.25,this->yCoordinate-0.05,this->zCoordinate+0.6);
        glutSolidCube(0.2);
        glPopMatrix();

}

void Car::update(){
        this->xCoordinate -= 0.01;
        this->angle += 5;
}

void Car::drawWheel(){

        GLUquadricObj* q = gluNewQuadric();
        glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(this->xCoordinate, this->yCoordinate, this->zCoordinate+0.1);
        glRotatef(180, 1,0,0);
        glRotatef(angle,0,0,1);
        gluDisk(q, 0.0f, 0.1, 15, 1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(this->xCoordinate, this->yCoordinate, this->zCoordinate+0.1);
        glRotatef(angle,0,0,1);
        gluCylinder(q,0.1,0.1,0.1,15,15);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(this->xCoordinate, this->yCoordinate, this->zCoordinate+0.2);
        glRotatef(180, 1,0,0);
        glRotatef(angle,0,0,1);
        gluDisk(q, 0.0f, 0.1, 15, 1);
        glPopMatrix();

}
