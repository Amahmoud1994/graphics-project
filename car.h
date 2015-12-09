#ifndef Car_H
#define  Car_H

#include <GL/glut.h>
#include <iostream>
#include "drawable.h"
#include "utils.h"

class Car : public Drawable {
private:
        void drawWheel();
        float angle;
public:
        int health;
        bool visible;
        Car(float zCoordinate){
                this->xCoordinate=carPosition;
                this->yCoordinate=0.3;
                this->zCoordinate=zCoordinate;
                this->health = 3;
                this->angle=0;
                this->visible = true;
        }
        Car(){
                this->xCoordinate=carPosition;
                this->yCoordinate=0.8;
                this->zCoordinate=0;
                this->health = 3;
                this->angle=0;
                this->visible = false;
        }
        virtual void draw();
        virtual void update();
};
#endif
