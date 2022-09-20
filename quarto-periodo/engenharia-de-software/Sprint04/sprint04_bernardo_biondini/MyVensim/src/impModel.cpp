/**
 * @file impModel.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "impModel.hpp"

/**
 * @brief ImpModel Default Constructor.
 * 
 * Attributes a empty string to the name
 */
ImpModel::ImpModel(){
    this->name = "";
}

/**
 * @brief ImpModel Copy Constructor.
 * 
 * All of the attributes will receive its values from the copy attributes
 * @param copy make a copy of another model
 */
ImpModel::ImpModel(ImpModel &copy){
    /**
     * @brief put all the flows of copy model into this object
     */
    for(auto iterador = copy.flows.begin(); iterador != copy.flows.end(); iterador++){
        this->flows.push_back(*iterador);
    }

    /**
     * @brief put all the systems of copy model into this object
     */
    for(auto iterador = copy.systems.begin(); iterador != copy.systems.end(); iterador++){
        this->systems.push_back(*iterador);
    }
    this->name = copy.getName(); /*!< This name receive the copy name */
}

/**
 * @brief ImpModel Destructor.
 * 
 * Clear the vectors
 */
ImpModel::~ImpModel(){
    this->flows.clear();
    this->systems.clear();
}

/**
 * @brief ImpModel Get Name Method.
 * 
 * Returns the model's name
 * @return string 
 */
string ImpModel::getName()const{
    return this->name;
}
/**
 * @brief ImpModel GetBeginSystems Method
 * 
 * Return the begin of the System vector
 * @return ImpModel::systemIterator 
 */
ImpModel::systemIterator ImpModel::getBeginSystems( void ){return systems.begin();}
/**
 * @brief ImpModel GetEndSystems Method
 * 
 * Return the end of the System vector
 * @return ImpModel::systemIterator 
 */
ImpModel::systemIterator ImpModel::getEndSystems( void ){return systems.end();}
/**
 * @brief ImpModel GetBeginFlows Method
 * 
 * Return the begin of the Flow vector
 * @return ImpModel::flowIterator 
 */
ImpModel::flowIterator ImpModel::getBeginFlows( void ){return flows.begin();} 
/**
 * @brief ImpModel GetEndFlows Method
 * 
 * Return the end of the Flow vector
 * @return ImpModel::flowIterator 
 */
ImpModel::flowIterator ImpModel::getEndFlows( void ){return flows.end();}  
    
/** 
 * @brief ImpModel Set Name Method.
 * 
 * Receive a string as a parameter and attributes it to model's name
 * @param name name of the model
 */
void ImpModel::setName(string name){
    this->name = name;
}

/**
 * @brief ImpModel Add Method.
 * 
 * This method uses Overloading concept, wether the parameter is a System or a Flow
 * @param System push a System into the System vector
 */
void ImpModel::add(System *system){
    this->systems.push_back(system);
}

/**
 * @brief ImpModel Add Method.
 * 
 * This method uses Overloading concept, wether the parameter is a Flow or a System
 * @param System push a Flow into the Flow vector
 */
void ImpModel::add(Flow *flow){
    this->flows.push_back(flow);
}

/**
 * @brief ImpModel Execute Method.
 * @warning Execute method is the main method of Model,responsible
 * for controlling the flow and the results of Model's dynamics
 * @param initial_time 
 * @param final_time 
 * @param incr how much the program will increment, simulates time
 */
void ImpModel::execute(double initial_time, double final_time, int incr){

    System *source;
    System *target;

    vector <double> v;
    int j = 0;

    for (double i = initial_time; i < final_time; i += incr){

        for (Flow* f : this->flows) {
            v.push_back(f->execute()); /*!< Make a vector of returned flows execute method value */
        }
        j = 0;

        for (Flow* f : this->flows) {

            source = f->getSource();
            source->setValue(source->getValue() - v[j]); /*!< remove the value vector value from the source value */

            target = f->getTarget();
            target->setValue(target->getValue() + v[j]); /*!< add the value vector from to target value */

            j++;
        }

        v.clear();
    }
}

/**
 * @brief ImpModel Assignment Operator.
 * 
 * Following the Canonical Class Form
 * @param model
 * @return ImpModel& 
 */
ImpModel& ImpModel::operator=(ImpModel& model){

    if(this == &model) /*!< Verify if they are alredy the same */
    {
        return *this; /*!< In case they are the same, just return this */
    }
    
    this->name = model.getName(); /*!< Name of the object receive the parameter object name */

    // clear flows
    this->flows.clear(); /*!< clear the vector of flows */

    // clear systems
    this->systems.clear(); /*!< clear the vector of systems */
    
    /**
     * @brief put all the flows of copy model into this object
     */
    for(auto iterador = model.flows.begin(); iterador != model.flows.end(); iterador++){
        this->flows.push_back(*iterador);
    }

    /**
     * @brief put all the systems of copy model into this object
     */
    for(auto iterador = model.systems.begin(); iterador != model.systems.end(); iterador++){
        this->systems.push_back(*iterador);
    }

    return *this;

}