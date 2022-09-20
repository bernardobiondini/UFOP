/**
 * @file impFlow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "../include/impFlow.hpp"

/**
 * @brief ImpFlow Default Constructor a new ImpFlow:: ImpFlow object.
 * 
 * Following the Canonical Class Form 
 */
ImpFlow::ImpFlow(){
    name = "";
}

/**
 * @brief ImpFlow Copy Constructor a new ImpFlow:: ImpFlow object
 * 
 * Following the Canonical Class Form 
 * @param copy make a copy of another flow
 */
ImpFlow::ImpFlow(ImpFlow &copy){
    name = copy.getName(); /*!< This name receive the copy name */
    source = copy.getSource(); /*!< This system source receive the copy system source */
    target = copy.getTarget(); /*!< This system target receive the copy system target */
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
    return name;
}

/**
 * @brief ImpFlow Get Source Method.
 * 
 * Returns the source system of the flow
 * @return System* 
 */
System* ImpFlow::getSource()const{
    return source;
}

/**
 * @brief ImpFlow Get Target Method.
 * 
 * Returns the target system of the flow
 * @return System* 
 */
System* ImpFlow::getTarget()const{
    return target;
}

/** 
 * @brief ImpFlow Set Name Method.
 * 
 * Receive a string as a parameter and attributes it to flow's name
 * @param name name of the flow
 */
void ImpFlow::setName(string name_){
    name = name_;
}

/**
 * @brief ImpFlow Set Source System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's source
 * @param source input system of the flow
 */
void ImpFlow::setSource(System* source_){
    source = source_;
}

/**
 * @brief ImpFlow Set Target System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's target
 * @param target output system of the flow
 */
void ImpFlow::setTarget(System* target_){
    target = target_;
}

/** 
 * @brief ImpFlow Conect Method.
 * 
 * Receive two Systems as parameters and attributes it to flow's source and flowś target
 * @param source input system of the flow
 * @param target output system of the flow
 */
void ImpFlow::conect(System *source_, System *target_){
    source = source_; /*!< This system source receive the system source passe by parameter */
    target = target_; /*!< This system target receive the system target passe by parameter */
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
    
    name = flow.getName(); /*!< Name of the object receive the parameter object name */
    source = flow.getSource(); /*!< This system source receive the source parameter */
    target = flow.getTarget(); /*!< This system target receive the target parameter */

    return *this;
}