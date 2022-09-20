/**
 * @file impSystem.cpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#include "../include/impSystem.hpp"

/**
 * @brief SystemBody Default Constructor.
 * 
 * Following the Canonical Class Form 
 */
SystemBody::SystemBody(){
    name = "";
    value = 0.0;
}

/**
 * @brief SystemBody Copy Constructor.
 * 
 * Following the Canonical Class Form 
 * @param copy
 */
// SystemBody::SystemBody(SystemBody &copy){
//     name = copy.getName(); /*!< This name receive the copy name */
//     value = copy.getValue(); /*!< This value receive the copy value */
// }

/**
 * @brief SystemBody Constructor parameters of string and double.
 * 
 * All of the attributes will receive its values frm the parameters
 * @param name
 * @param value
 */
SystemBody::SystemBody(string name, double value): name(name), value(value) {}

/**
 * @brief SystemBody Get Name Method.
 * 
 * Returns the System's name
 * @return string 
 */
string SystemBody::getName()const{
    return name;
}

/**
 * @brief SystemBody Get Value Method.
 * 
 * Returns the System's value 
 * @return double 
 */
double SystemBody::getValue()const{
    return value;
}

/**
 * @brief SystemBody Set Name Method.
 * 
 * Receives a string name and attributes it to System's name
 * @param name description
 */
void SystemBody::setName(string name){
    name = name;
}

/**
 * @brief SystemBody Set Value Method.
 * 
 * Receives a double value and attributes it to System's value
 * @param value 
 */
void SystemBody::setValue(double value){
    value = value;
}

/**
 * @brief SystemBody Assignment Operator.
 * 
 * Following the Canonical Class Form
 * @param system
 * @return SystemBody& 
 */
// SystemBody& SystemBody::operator=(SystemBody &system){
//     if(this == &system) /*!< Verify if they are alredy the same */
//     {
//         return *this; /*!< In case they are the same, just return this */
//     }
    
//     name = system.getName(); /*!< Name of the object receive the parameter object name */
//     value = system.getValue(); /*!< Value of the object receive the parameter object value */

//     return *this; /*!< Return this object with new attributes */
// }