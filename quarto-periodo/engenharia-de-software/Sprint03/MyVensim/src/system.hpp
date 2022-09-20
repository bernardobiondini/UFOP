/**
 * @file system.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 * 
 */
#ifndef system_hpp
#define system_hpp

#include <iostream>
#include <string>

using namespace std;

/** 
 * @brief System Class.
 * 
 * Represents a set of System(s) and/or Flow(s). It's responsible for execution and for set
 * up the operation and workflow of values.
 */
class System{
    protected:
        string name; /*!< System's name */
        double value; /*!< Value of System */
    public:
        /**
         * @brief System Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        System();

        /**
         * @brief System Copy Constructor.
         * 
         * Following the Canonical Class Form 
         * @param copy
         */
        System(System &copy);

        /**
         * @brief System Constructor parameters of string and double.
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name
         * @param value
         */
        System(string name, double value);

        /**
         * @brief Virtual System Destructor.
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
        string getName() const;

        /**
         * @brief System Get Value Method.
         * 
         * Returns the System's value 
         * @return double 
         */
        double getValue() const;

        /**
         * @brief System Set Name Method.
         * 
         * Receives a string name and attributes it to System's name
         * @param name description
         */
        void setName(string name);

        /**
         * @brief System Set Value Method.
         * 
         * Receives a double value and attributes it to System's value
         * @param value 
         */
        void setValue(double value);

        /**
         * @brief System Assignment Operator.
         * 
         * Following the Canonical Class Form
         * @param system
         * @return System& 
         */
        System& operator=(System &system);
};

#endif