#ifndef _STEPMOTOR_H
#define _STEPMOTOR_H
#include "arduino.h"
class Stepmotor{
    private:
        double angle;
        double target;
        double unit;
        int speed;
        bool direction;
        bool moving;
    public:
    //constructor and destructor
        Stepmotor();
        ~Stepmotor();
    //basic
        double getAngle();
        void setAngle(double);
        double getTarget();
        void setTarget(double);
        double getUnit();
        void setUnit(double);
        int getSpeed();
        void setSpeed(int);
        void setDirection(bool);
        void setMoving(bool);
    //directive
        void moveUnit();
        void takeAction();
        void start(bool);
        void stop();
};
#endif