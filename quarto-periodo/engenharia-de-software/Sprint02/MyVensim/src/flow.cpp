#include "flow.hpp"

Flow::Flow(){
    this->name = "";
}

Flow::Flow(string name, System *source, System *target): 
    name(name), source(source), target(target){}

Flow::Flow(Flow &copia){
    this->name = copia.getName();
    this->source = copia.getSource();
    this->target = copia.getTarget();
}

string Flow::getName()const{
    return this->name;
}
System* Flow::getSource()const{
    return this->source;
}
System* Flow::getTarget()const{
    return this->target;
}

void Flow::setName(string name){
    this->name = name;
}
void Flow::setSource(System* novo){
    this->source = novo;
}
void Flow::setTarget(System* novo){
    this->target = novo;
}

void Flow::conect(System *source, System *target){
    this->source = source;
    this->target = target;
}

Flow& Flow::operator=(Flow& flow){
    if(this == &flow){
        return *this;
    }
    
    this->name = flow.getName();
    this->source = flow.getSource();
    this->target = flow.getTarget();

    return *this;
}