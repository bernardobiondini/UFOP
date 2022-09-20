/**
 * @file impSystem.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#include "impSystem.hpp"

/**
 * @brief ImpSystem Default Constructor.
 * 
 * Following the Canonical Class Form 
 */
ImpSystem::ImpSystem(){
    this->name = "";
    this->value = 0.0;
}

/**
 * @brief ImpSystem Copy Constructor.
 * 
 * Following the Canonical Class Form 
 * @param copy
 */
ImpSystem::ImpSystem(ImpSystem &copy){
    this->name = copy.getName(); /*!< This name receive the copy name */
    this->value = copy.getValue(); /*!< This value receive the copy value */
}

/**
 * @brief ImpSystem Constructor parameters of string and double.
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name
 * @param value
 */
ImpSystem::ImpSystem(string name, double value): name(name), value(value) {}

/**
 * @brief ImpSystem Get Name Method.
 * 
 * Returns the System's name
 * @return string 
 */
string ImpSystem::getName()const{
    return this->name;
}

/**
 * @brief ImpSystem Get Value Method.
 * 
 * Returns the System's value 
 * @return double 
 */
double ImpSystem::getValue()const{
    return this->value;
}

/**
 * @brief ImpSystem Set Name Method.
 * 
 * Receives a string name and attributes it to System's name
 * @param name description
 */
void ImpSystem::setName(string name){
    this->name = name;
}

/**
 * @brief ImpSystem Set Value Method.
 * 
 * Receives a double value and attributes it to System's value
 * @param value 
 */
void ImpSystem::setValue(double value){
    this->value = value;
}

/**
 * @brief ImpSystem Assignment Operator.
 * 
 * Following the Canonical Class Form
 * @param system
 * @return ImpSystem& 
 */
ImpSystem& ImpSystem::operator=(ImpSystem &system){
    if(this == &system) /*!< Verify if they are alredy the same */
    {
        return *this; /*!< In case they are the same, just return this */
    }
    
    this->name = system.getName(); /*!< Name of the object receive the parameter object name */
    this->value = system.getValue(); /*!< Value of the object receive the parameter object value */

    return *this; /*!< Return this object with new attributes */
}