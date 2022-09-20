/**
 * @file impSystem.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#ifndef impSystem_hpp
#define impSystem_hpp

#include "system.hpp"

using namespace std;

/** 
 * @brief ImpSystem Class.
 * 
 */
class ImpSystem: public System{
    protected:
        string name; /*!< System's name */
        double value; /*!< Value of System */
    public:
        /**
         * @brief ImpSystem Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        ImpSystem();

        /**
         * @brief ImpSystem Copy Constructor.
         * 
         * Following the Canonical Class Form 
         * @param copy
         */
        ImpSystem(ImpSystem &copy);

        /**
         * @brief ImpSystem Constructor parameters of string and double.
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name
         * @param value
         */
        ImpSystem(string name, double value);

        /**
         * @brief Virtual ImpSystem Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~ImpSystem(){}

        /**
         * @brief ImpSystem Get Name Method.
         * 
         * Returns the System's name
         * @return string 
         */
        string getName() const;

        /**
         * @brief ImpSystem Get Value Method.
         * 
         * Returns the System's value 
         * @return double 
         */
        double getValue() const;

        /**
         * @brief ImpSystem Set Name Method.
         * 
         * Receives a string name and attributes it to System's name
         * @param name description
         */
        void setName(string name);

        /**
         * @brief ImpSystem Set Value Method.
         * 
         * Receives a double value and attributes it to System's value
         * @param value 
         */
        void setValue(double value);

        /**
         * @brief ImpSystem Assignment Operator.
         * 
         * Following the Canonical Class Form
         * @param system
         * @return ImpSystem& 
         */
        ImpSystem& operator=(ImpSystem &system);
};

#endif