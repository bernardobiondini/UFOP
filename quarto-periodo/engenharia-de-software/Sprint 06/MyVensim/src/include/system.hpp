/**
 * @file system.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#ifndef system_hpp
#define system_hpp

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief System Interface
 * 
 * Responsible for define the System structure, its methods but not the implementation
 */
class System{
    public:

        /**
         * @brief System Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~System(){}

        /**
         * @brief System Get Name Method.
         * 
         * Returns the System's name
         * @return string 
         */
        virtual string getName() const  = 0;

        /**
         * @brief System Get Value Method.
         * 
         * Returns the System's value 
         * @return double 
         */
        virtual double getValue() const  = 0;

        /**
         * @brief System Set Name Method.
         * 
         * Receives a string name and attributes it to System's name
         * @param name description
         */
        virtual void setName(string name) = 0;

        /**
         * @brief System Set Value Method.
         * 
         * Receives a double value and attributes it to System's value
         * @param value 
         */
        virtual void setValue(double value) = 0;
};

#endif