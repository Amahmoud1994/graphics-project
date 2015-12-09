#ifndef Brick_H
#define  Brick_H

#include "drawable.h"

class Brick : public Drawable {
private:
        float angle;
public:
        bool visible;

        Brick(float xCoordinate, float zCoordinate){
                this->xCoordinate = xCoordinate;
                this->yCoordinate = 0.3;
                this->zCoordinate = zCoordinate;
                this->angle       = 0;
                this->visible     = true;
        }

        Brick(){
                this->xCoordinate = 1;
                this->yCoordinate = 0.8;
                this->zCoordinate = 0;
                this->angle       = 0;
                this->visible     = false;
        }

        virtual void draw();
        virtual void update();
};
#endif
