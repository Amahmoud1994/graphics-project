#ifndef Cone_H
#define  Cone_H

#include "drawable.h"

class Cone : public Drawable {
private:
        float angle;
public:
        bool visible;

        Cone(float xCoordinate, float zCoordinate){
                this->xCoordinate = xCoordinate;
                this->yCoordinate = 0.3;
                this->zCoordinate = zCoordinate;
                this->angle       = 0;
                this->visible     = true;
        }

        Cone(){
                this->xCoordinate = -2;
                this->yCoordinate = 0;
                this->zCoordinate = 1;
                this->angle       = 0;
                this->visible     = false;
        }

        virtual void draw();
        virtual void update();
};
#endif
