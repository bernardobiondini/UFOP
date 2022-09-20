#include "system.hpp"

System::System(){
    this->name = "";
    this->value = 0.0;
}

System::System(System &copia){
    this->name = copia.getName();
    this->value = copia.getValue();
}

System::System(string name, double value): name(name), value(value) {}

string System::getName()const{
    return this->name;
}
double System::getValue()const{
    return this->value;
}

void System::setName(string name){
    this->name = name;
}
void System::setValue(double value){
    this->value = value;
}

System& System::operator=(System& system){
    if(this == &system){
        return *this;
    }
    
    this->name = system.getName();
    this->value = system.getValue();

    return *this;
}