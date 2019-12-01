#include "utility.h"
#include "Stepmotor.h"
Stepmotor* sm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  while(!Serial);
  sm=new Stepmotor();
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(add(1,2));
  sm->takeAction();
}

void serialEvent(){
  String message=serialToString();
  int count=splitString(message,",",0);
  String* out=new String[count];
  splitString(message,",",out);
  if(out[0]=="getAngle"){
    Serial.println(sm->getAngle());
  }else if(out[0]=="setAngle"){
    double angle=out[1].toDouble();
    sm->setAngle(angle);
  }else if(out[0]=="getTarget"){
    Serial.println(sm->getTarget());
  }else if(out[0]=="setTarget"){
    double angle=out[1].toDouble();
    sm->setTarget(angle);
  }else if(out[0]=="getUnit"){
    Serial.println(sm->getUnit());
  }else if(out[0]=="setUnit"){
    double unit=out[1].toDouble();
    sm->setUnit(unit);
  }else if(out[0]=="getSpeed"){
    Serial.println(sm->getSpeed());
  }else if(out[0]=="setSpeed"){
    int speed=out[1].toInt();
    sm->setSpeed(speed);
  }else if(out[0]=="setDirection"){
    bool direction=(bool)(out[1].toInt());
    sm->setDirection(direction);
  }else if(out[0]=="setMoving"){
    bool moving=(bool)(out[1].toInt());
    sm->setMoving(moving);
  }else if(out[0]=="stop"){
    sm->stop();
  }else if(out[0]=="start"){
    bool direction=(bool)(out[1].toInt());
    sm->start(direction);
  }
}
