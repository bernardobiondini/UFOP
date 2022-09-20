/**
 * @file system.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#include "system.hpp"

/**
 * @brief System Default Constructor.
 * 
 * Following the Canonical Class Form 
 */
System::System(){
    this->name = "";
    this->value = 0.0;
}

/**
 * @brief System Copy Constructor.
 * 
 * Following the Canonical Class Form 
 * @param copy
 */
System::System(System &copy){
    this->name = copy.getName(); /*!< This name receive the copy name */
    this->value = copy.getValue(); /*!< This value receive the copy value */
}

/**
 * @brief System Constructor parameters of string and double.
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name
 * @param value
 */
System::System(string name, double value): name(name), value(value) {}

/**
 * @brief System Get Name Method.
 * 
 * Returns the System's name
 * @return string 
 */
string System::getName()const{
    return this->name;
}

/**
 * @brief System Get Value Method.
 * 
 * Returns the System's value 
 * @return double 
 */
double System::getValue()const{
    return this->value;
}

/**
 * @brief System Set Name Method.
 * 
 * Receives a string name and attributes it to System's name
 * @param name description
 */
void System::setName(string name){
    this->name = name;
}

/**
 * @brief System Set Value Method.
 * 
 * Receives a double value and attributes it to System's value
 * @param value 
 */
void System::setValue(double value){
    this->value = value;
}

/**
 * @brief System Assignment Operator.
 * 
 * Following the Canonical Class Form
 * @param system
 * @return System& 
 */
System& System::operator=(System& system){
    if(this == &system) /*!< Verify if they are alredy the same */
    {
        return *this; /*!< In case they are the same, just return this */
    }
    
    this->name = system.getName(); /*!< Name of the object receive the parameter object name */
    this->value = system.getValue(); /*!< Value of the object receive the parameter object value */

    return *this; /*!< Return this object with new attributes */
}