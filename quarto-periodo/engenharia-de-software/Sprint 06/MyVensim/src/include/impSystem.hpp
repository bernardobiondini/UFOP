/**
 * @file impSystem.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#ifndef impSystem_hpp
#define impSystem_hpp

#include "bridge.hpp"
#include "system.hpp"

using namespace std;

/** 
 * @brief ImpSystem Class.
 * 
 */
class SystemBody: public Body{
    protected:
        string name; /*!< System's name */
        double value; /*!< Value of System */

    private:

    /**
     * @brief SystemBody Copy Constructor.
     * 
     * Following the Canonical Class Form 
     * @param copy
     */
    SystemBody(SystemBody &copy);

    /**
     * @brief SystemBody Assignment Operator.
     * 
     * Following the Canonical Class Form
     * @param system
     * @return SystemBody& 
     */
    SystemBody& operator=(SystemBody &system);


    public:
        /**
         * @brief SystemBody Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        SystemBody();

        /**
         * @brief SystemBody Constructor parameters of string and double.
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name
         * @param value
         */
        SystemBody(string name, double value);

        /**
         * @brief Virtual SystemBody Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~SystemBody(){}

        /**
         * @brief SystemBody Get Name Method.
         * 
         * Returns the System's name
         * @return string 
         */
        string getName() const;

        /**
         * @brief SystemBody Get Value Method.
         * 
         * Returns the System's value 
         * @return double 
         */
        double getValue() const;

        /**
         * @brief SystemBody Set Name Method.
         * 
         * Receives a string name and attributes it to System's name
         * @param name description
         */
        void setName(string name);

        /**
         * @brief SystemBody Set Value Method.
         * 
         * Receives a double value and attributes it to System's value
         * @param value 
         */
        void setValue(double value);
};


/**
 * @brief System Handle Class
 * 
 */
class SystemHandle : public Handle<SystemBody>, public System
{
public:
    /**
     * @brief Construct a new System Handle object
     * 
     * @param name 
     * @param value 
     */
    SystemHandle(string name = "", double value = 0){
        pImpl_->setName(name);
        pImpl_->setValue(value);
    }

    /**
     * @brief Destroy the System Handle object
     * 
     */
    virtual ~SystemHandle(){};

    /**
     * @brief Set the Value object
     * 
     * @param value 
     */
    void setValue(double value) {
        pImpl_->setValue(value);
    }

    /**
     * @brief Get the Value object
     * 
     * @return double 
     */
    double getValue() const {
        return pImpl_->getValue();
    }

    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName() const{
        return pImpl_->getName();
    }

    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setName(string name){
        pImpl_->setName(name);
    }
    
};

#endif