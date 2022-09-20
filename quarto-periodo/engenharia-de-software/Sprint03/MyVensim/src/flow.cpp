/**
 * @file flow.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "flow.hpp"

/**
 * @brief Flow Default Constructor a new Flow:: Flow object.
 * 
 * Following the Canonical Class Form 
 */
Flow::Flow(){
    this->name = "";
}

/**
 * @brief Flow Copy Constructor a new Flow:: Flow object
 * 
 * Following the Canonical Class Form 
 * @param copy make a copy of another flow
 */
Flow::Flow(Flow &copy){
    this->name = copy.getName(); /*!< This name receive the copy name */
    this->source = copy.getSource(); /*!< This system source receive the copy system source */
    this->target = copy.getTarget(); /*!< This system target receive the copy system target */
}

/**
 * @brief Flow Constructor parameters of string, System and System. a new Flow:: Flow object
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name 
 * @param source 
 * @param target 
 */
Flow::Flow(string name, System *source, System *target): 
    name(name), source(source), target(target){}

/**
 * @brief Flow Get Name Method.
 * 
 * Returns the flow's name
 * @return string
 */
string Flow::getName()const{
    return this->name;
}

/**
 * @brief Flow Get Source Method.
 * 
 * Returns the source system of the flow
 * @return System* 
 */
System* Flow::getSource()const{
    return this->source;
}

/**
 * @brief Flow Get Target Method.
 * 
 * Returns the target system of the flow
 * @return System* 
 */
System* Flow::getTarget()const{
    return this->target;
}

/** 
 * @brief Flow Set Name Method.
 * 
 * Receive a string as a parameter and attributes it to flow's name
 * @param name name of the flow
 */
void Flow::setName(string name){
    this->name = name;
}

/**
 * @brief Flow Set Source System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's source
 * @param source input system of the flow
 */
void Flow::setSource(System* source){
    this->source = source;
}

/**
 * @brief Flow Set Target System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's target
 * @param target output system of the flow
 */
void Flow::setTarget(System* target){
    this->target = target;
}

/** 
 * @brief Flow Conect Method.
 * 
 * Receive two Systems as parameters and attributes it to flow's source and flowś target
 * @param source input system of the flow
 * @param target output system of the flow
 */
void Flow::conect(System *source, System *target){
    this->source = source; /*!< This system source receive the system source passe by parameter */
    this->target = target; /*!< This system target receive the system target passe by parameter */
}

/**
 * @brief Flow Assignment operator.
 * 
 * Following the Canonical Class Form 
 * @param flow
 * @return Flow& a copy of a flow
 */
Flow& Flow::operator=(Flow& flow){
    if(this == &flow) /*!< Verify if they are alredy the same */
    {
        return *this; /*!< In case they are the same, just return this */
    }
    
    this->name = flow.getName(); /*!< Name of the object receive the parameter object name */
    this->source = flow.getSource(); /*!< This system source receive the source parameter */
    this->target = flow.getTarget(); /*!< This system target receive the target parameter */

    return *this;
}