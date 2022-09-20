/**
 * @file impFlow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "../include/impFlow.hpp"

/**
 * @brief FlowBody Default Constructor a new FlowBody:: FlowBody object.
 * 
 * Following the Canonical Class Form 
 */
FlowBody::FlowBody(){
    name = "";
}

/**
 * @brief FlowBody Copy Constructor a new FlowBody:: FlowBody object
 * 
 * Following the Canonical Class Form 
 * @param copy make a copy of another flow
 */
// FlowBody::FlowBody(FlowBody &copy){
//     name = copy.getName(); /*!< This name receive the copy name */
//     source = copy.getSource(); /*!< This system source receive the copy system source */
//     target = copy.getTarget(); /*!< This system target receive the copy system target */
// }

/**
 * @brief FlowBody Constructor parameters of string, System and System. a new FlowBody:: FlowBody object
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name 
 * @param source 
 * @param target 
 */
FlowBody::FlowBody(string name, System *source, System *target): 
    name(name), source(source), target(target){}

/**
 * @brief FlowBody Get Name Method.
 * 
 * Returns the flow's name
 * @return string
 */
string FlowBody::getName()const{
    return name;
}

/**
 * @brief FlowBody Get Source Method.
 * 
 * Returns the source system of the flow
 * @return System* 
 */
System* FlowBody::getSource()const{
    return source;
}

/**
 * @brief FlowBody Get Target Method.
 * 
 * Returns the target system of the flow
 * @return System* 
 */
System* FlowBody::getTarget()const{
    return target;
}

/** 
 * @brief FlowBody Set Name Method.
 * 
 * Receive a string as a parameter and attributes it to flow's name
 * @param name name of the flow
 */
void FlowBody::setName(string name_){
    name = name_;
}

/**
 * @brief FlowBody Set Source System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's source
 * @param source input system of the flow
 */
void FlowBody::setSource(System* source_){
    source = source_;
}

/**
 * @brief FlowBody Set Target System Method.
 * 
 * Receive a System as a parameter and attributes it to flow's target
 * @param target output system of the flow
 */
void FlowBody::setTarget(System* target_){
    target = target_;
}

/** 
 * @brief FlowBody Conect Method.
 * 
 * Receive two Systems as parameters and attributes it to flow's source and flowś target
 * @param source input system of the flow
 * @param target output system of the flow
 */
void FlowBody::conect(System *source_, System *target_){
    source = source_; /*!< This system source receive the system source passe by parameter */
    target = target_; /*!< This system target receive the system target passe by parameter */
}

/**
 * @brief FlowBody Assignment operator.
 * 
 * Following the Canonical Class Form 
 * @param flow
 * @return FlowBody& a copy of a flow
 */
// FlowBody& FlowBody::operator=(FlowBody& flow){
//     if(this == &flow) /*!< Verify if they are alredy the same */
//     {
//         return *this; /*!< In case they are the same, just return this */
//     }
    
//     name = flow.getName(); /*!< Name of the object receive the parameter object name */
//     source = flow.getSource(); /*!< This system source receive the source parameter */
//     target = flow.getTarget(); /*!< This system target receive the target parameter */

//     return *this;
// }