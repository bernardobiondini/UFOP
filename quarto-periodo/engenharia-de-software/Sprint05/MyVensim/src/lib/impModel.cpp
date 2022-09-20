/**
 * @file impModel.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "../include/impModel.hpp"

vector<Model*> ImpModel::models;

/**
 * @brief ImpModel Default Constructor.
 * 
 * Attributes a empty string to the name
 */
ImpModel::ImpModel(){
    name = "";
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
        flows.push_back(*iterador);
    }

    /**
     * @brief put all the systems of copy model into this object
     */
    for(auto iterador = copy.systems.begin(); iterador != copy.systems.end(); iterador++){
        systems.push_back(*iterador);
    }
    name = copy.getName(); /*!< This name receive the copy name */
}

/**
 * @brief ImpModel Destructor.
 * 
 * Clear the vectors
 */
ImpModel::~ImpModel(){

    for(auto iterator = systems.begin(); iterator != systems.end(); iterator++){
        delete *iterator;
    }

    for(auto iterator = flows.begin(); iterator != flows.end(); iterator++){
        delete *iterator;
    }

    // for(auto iterator = models.begin(); iterator != models.end(); iterator++){
    //     delete *iterator;
    // }

    flows.clear();
    systems.clear();
    models.clear();
}

/**
 * @brief ImpModel Get Name Method.
 * 
 * Returns the model's name
 * @return string 
 */
string ImpModel::getName()const{
    return name;
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
void ImpModel::setName(string name_){
    name = name_;
}

/**
 * @brief ImpModel Add Method.
 * 
 * This method uses Overloading concept, wether the parameter is a System or a Flow
 * @param System push a System into the System vector
 */
void ImpModel::add(System *system){
    systems.push_back(system);
}

/**
 * @brief ImpModel Add Method.
 * 
 * This method uses Overloading concept, wether the parameter is a Flow or a System
 * @param System push a Flow into the Flow vector
 */
void ImpModel::add(Flow *flow){
    flows.push_back(flow);
}

/**
 * @brief ImpModel Execute Method.
 * @warning Execute method is the main method of Model,responsible
 * for controlling the flow and the results of Model's dynamics
 * @param initial_time 
 * @param final_time 
 * @param incr how much the program will increment, simulates time
 */
void ImpModel::run(double initial_time, double final_time, int incr){

    System *source;
    System *target;

    vector <double> v;
    int j = 0;

    for (double i = initial_time; i < final_time; i += incr){

        for (Flow* f : flows) {
            v.push_back(f->execute()); /*!< Make a vector of returned flows execute method value */
        }
        j = 0;

        for (Flow* f : flows) {

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
    
    name = model.getName(); /*!< Name of the object receive the parameter object name */

    // clear flows
    flows.clear(); /*!< clear the vector of flows */

    // clear systems
    systems.clear(); /*!< clear the vector of systems */
    
    /**
     * @brief put all the flows of copy model into this object
     */
    for(auto iterador = model.flows.begin(); iterador != model.flows.end(); iterador++){
        flows.push_back(*iterador);
    }

    /**
     * @brief put all the systems of copy model into this object
     */
    for(auto iterador = model.systems.begin(); iterador != model.systems.end(); iterador++){
        systems.push_back(*iterador);
    }

    return *this;

}

/**
 * @brief ImpModel CreateSystem Method
 * 
 * Instance a System with attributes passed by the method
 * @param name 
 * @param value 
 * @return System* 
 */
System* ImpModel::createSystem(string name_, double value_){
    System* system = new ImpSystem(name_, value_); /*!< Instance system */

    add(system); /*! Add system to system vector*/

    return system;
}

/**
* @brief CreateModel
* 
* Calls CreateModel Method
* @param name 
* @return Model* pointer to the model created
*/
Model* Model::createModel() {
    return ImpModel::createModel();
}

/**
 * @brief ImpSsytem CreateModel Method 
 * 
 * 
 * Instance a ImpModel object and add it to the vector of models
 * @param name 
 * @return Model* pointer to the model created
 */
Model* ImpModel::createModel() {
    Model* model = new ImpModel();
    ImpModel::models.push_back(model);

    return model;
}