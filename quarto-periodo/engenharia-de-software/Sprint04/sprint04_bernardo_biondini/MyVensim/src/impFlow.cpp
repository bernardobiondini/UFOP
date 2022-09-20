/**
 * @file impFlow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "impFlow.hpp"

/**
 * @brief ImpFlow Default Constructor a new ImpFlow:: ImpFlow object.
 * 
 * Following the Canonical Class Form 
 */
ImpFlow::ImpFlow(){
    this->name = "";
}

/**
 * @brief ImpFlow Copy Constructor a new ImpFlow:: ImpFlow object
 * 
 * Following the Canonical Class Form 
 * @param copy make a copy of another flow
 */
ImpFlow::ImpFlow(ImpFlow &copy){
    this->name = copy.getName(); /*!< This name receive the copy name */
    this->source = copy.getSource(); /*!< This system source receive the copy system source */
    this->target = copy.getTarget(); /*!< This system target receive the copy system target */
}

/**
 * @brief ImpFlow Constructor parameters of string, System and System. a new ImpFlow:: ImpFlow object
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name 
 * @param source 
 * @param target 
 */
ImpFlow::ImpFlow(string name, System *source, System *target): 
    name(name), source(source), target(target){}

/**
 * @brief ImpFlow Get Name Method.
 * 
 * Returns the flow's name
 * @return string
 */
string ImpFlow::getName()const{
    return this->name;
}

/**
 * @brief ImpFlow Get Source Method.
 * 
 * Returns the source system of the flow
 * @return System* 
 */
System* ImpFlow::getSource()const{
    return this->source;
}

/**
 * @brief ImpFlow Get Target Method.
 * 
 * Returns the target system of the flow
 * @return System* 
 */
System* ImpFlow::getTarget()const{
    return this->target;
}

/** 
 * @brief ImpFlow Set Name Method.
 * 
 * Receive a string as a parameter and attributes it to flow's name
 * @param name name of the flow
 */
void ImpFlow::setName(string name){
    this->name = name;
}

/**
 * @brief ImpFlow Set Source System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's source
 * @param source input system of the flow
 */
void ImpFlow::setSource(System* source){
    this->source = source;
}

/**
 * @brief ImpFlow Set Target System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's target
 * @param target output system of the flow
 */
void ImpFlow::setTarget(System* target){
    this->target = target;
}

/** 
 * @brief ImpFlow Conect Method.
 * 
 * Receive two Systems as parameters and attributes it to flow's source and flowś target
 * @param source input system of the flow
 * @param target output system of the flow
 */
void ImpFlow::conect(System *source, System *target){
    this->source = source; /*!< This system source receive the system source passe by parameter */
    this->target = target; /*!< This system target receive the system target passe by parameter */
}

/**
 * @brief ImpFlow Assignment operator.
 * 
 * Following the Canonical Class Form 
 * @param flow
 * @return ImpFlow& a copy of a flow
 */
ImpFlow& ImpFlow::operator=(ImpFlow& flow){
    if(this == &flow) /*!< Verify if they are alredy the same */
    {
        return *this; /*!< In case they are the same, just return this */
    }
    
    this->name = flow.getName(); /*!< Name of the object receive the parameter object name */
    this->source = flow.getSource(); /*!< This system source receive the source parameter */
    this->target = flow.getTarget(); /*!< This system target receive the target parameter */

    return *this;
}

/**
 * @brief Exponential Constructor parameters of string, System and System
 * 
 * All of the attributes will receive its values from the parameters
 * @param name 
 * @param source 
 * @param target
 */
Exponential::Exponential(string name, System* source, System* target)
                        : ImpFlow(name, source, target){}

/**
 * @brief Exponential Overriding Execute Method.
 * 
 * Returns the value of source system multiplied by 0.01
 * @return double 
 */
double Exponential::execute() const { 
    return 0.01 * this->source->getValue();
}

/**
 * @brief Logistical Constructor parameters of string, System and System
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name 
 * @param source 
 * @param target
 */
Logistical::Logistical(string name, System* source, System* target)
    : ImpFlow(name, source, target){}

/**
 * @brief Logistical Overriding Execute Method.
 * 
 * Returns the value of target system multiplied by (1 - (target system value / 70))
 * @return double 
 */
double Logistical::execute() const {
    return 0.01 * this->target->getValue() * (1 - (this->target->getValue() / POP_MAX));
}

/**
 * @brief Complex Constructor parameters of string, System and System
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name 
 * @param source 
 * @param target
 */
Complex::Complex(string name, System *source, System *target)
    : ImpFlow (name, source, target){}

/**
 * @brief Complex Overriding Execute Method.
 * 
 * Returns the value of source system multiplied by 0.01
 * @return double 
 */
double Complex::execute() const {
    return 0.01 * this->source->getValue();
}
