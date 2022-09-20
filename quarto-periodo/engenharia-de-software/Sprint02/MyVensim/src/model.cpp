#include "model.hpp"

Model::Model(){
    this->name = "";
}
  
Model::~Model(){
    this->flows.clear();
    this->systems.clear();
}

Model::Model(Model &copia){
    this->flows = copia.getFlows();
    this->systems = copia.getSystems();
    this->name = copia.getName();
}
        
vector<System*>& Model::getSystems(){
    return this->systems;
}
vector<Flow*>& Model::getFlows(){
    return this->flows;
}
string Model::getName()const{
    return this->name;
}

void Model::setFlows(vector<Flow*> novoFlows){
    this->flows = novoFlows;
}
void Model::setSystems(vector<System*> novoSystems){
    this->systems = novoSystems;
}

void Model::add(System *sis){
    this->systems.push_back(sis);
}
void Model::add(Flow *flow){
    this->flows.push_back(flow);
}

void Model::execute(double initial_time, double final_time, int incr){

    System *source;
    System *target;

    vector <double> v;
    int j = 0;

    for (double i = initial_time; i < final_time; i += incr){

        for (Flow* f : this->getFlows()) {
            v.push_back(f->execute());
        }
        j = 0;

        for (Flow* f : this->getFlows()) {

            source = f->getSource();
            source->setValue(source->getValue() - v[j]);

            target = f->getTarget();
            target->setValue(target->getValue() + v[j]);

            j++;
        }

        v.clear();
    }
}


Model& Model::operator=(Model& model){

    if(this == &model){
        return *this;
    }
    
    this->name = model.getName();

    // clear flows
    this->flows.clear();

    // clear systems
    this->systems.clear();
    
    // flows
    for(auto iterador = model.getFlows().begin(); iterador != model.getFlows().end(); iterador++){
        this->flows.push_back(*iterador);
    }

    // systems
    for(auto iterador = model.getSystems().begin(); iterador != model.getSystems().end(); iterador++){
        this->systems.push_back(*iterador);
    }

    return *this;
}