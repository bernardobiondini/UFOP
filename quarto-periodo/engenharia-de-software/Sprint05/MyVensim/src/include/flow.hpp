/**
 * @file flow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */
#ifndef flow_hpp
#define flow_hpp

#include "system.hpp"

using namespace std;

/**
 * @brief Flow Interface
 * 
 * Responsible for define the Flow structure, its methods but not the implementation
 */
class Flow{
    public:
        /**
         * @brief Flow Destructor
         * 
         */
        virtual ~Flow(){}

        /** 
         * @brief Flow Get Name Method.
         * 
         * Returns the flow's name
         * @return string
         */
        virtual string getName() const = 0;
        /** 
         * @brief Flow Get Source Method.
         * 
         * Returns the source system of the flow
         * @return System
         */
        virtual System* getSource() const = 0;
        /** 
         * @brief Flow Get Target Method.
         * 
         * Returns the target system of the flow
         * @return System
         */
        virtual System* getTarget()const = 0;
        
        /** 
         * @brief Flow Set Name Method.
         * 
         * Receive a string as a parameter and attributes it to flow's name
         * @param name name of the flow
         */
        virtual void setName(string name) = 0;
        /**
         * @brief Flow Set Source System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's source
         * @param source input system of the flow
         */
        virtual void setSource(System* source) = 0;
        /**
         * @brief Flow Set Target System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's target
         * @param target output system of the flow
         */
        virtual void setTarget(System* target) = 0;

        /** 
         * @brief Flow Conect Method.
         * 
         * Receive two Systems as parameters and attributes it to flow's source and flowś target
         * @param source input system of the flow
         * @param target output system of the flow
         */
        virtual void conect(System *, System *) = 0;
        
        /** 
         * @brief Virtual Flow Execute Method.
         * 
         * This method will be implemented by class's children. It's responsible for 
         * return the value which the target system will receive considering the value that 
         * the source contains
         * @return double is going to be used to modify a value
         */
        virtual double execute() const = 0;
};

#endif