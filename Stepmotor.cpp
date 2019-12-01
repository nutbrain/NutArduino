#include "Stepmotor.h"
//constructor and destructor
Stepmotor::Stepmotor()
{
    this->angle = 0;
    this->target = 0;
    this->unit = 0.01;
    this->direction = true;
    this->speed = 1;
    this->moving = false;
}
//basic
double Stepmotor::getAngle()
{
    return this->angle;
}
void Stepmotor::setAngle(double a)
{
    this->angle = a;
}
double Stepmotor::getTarget()
{
    return this->target;
}
void Stepmotor::setTarget(double t)
{
    this->target = t;
}
double Stepmotor::getUnit()
{
    return this->unit;
}
void Stepmotor::setUnit(double u)
{
    this->unit = abs(u);
}
int Stepmotor::getSpeed()
{
    return this->speed;
}
void Stepmotor::setSpeed(int s)
{
    this->speed = s;
}
void Stepmotor::setDirection(bool d)
{
    this->direction = d;
}
void Stepmotor::setMoving(bool m)
{
    this->moving = m;
}

//directive
void Stepmotor::moveUnit()
{
    this->angle += this->direction ? this->unit : -this->unit;
    //do specific movement
    delay(10);
}
void Stepmotor::takeAction()
{
    if (this->moving)
    {
        this->moveUnit();
    }
    else if (abs(this->target-this->angle)>=this->unit*0.6){
        this->direction=this->target>this->angle;
        this->moveUnit();
    }
}
void Stepmotor::start(bool direction){
    this->setDirection(direction);
    this->setMoving(true);
}
void Stepmotor::stop(){
    this->setMoving(false);
    this->setTarget(this->getAngle());
}