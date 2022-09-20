/**
 * @file flow.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 * 
 */
#ifndef flow_hpp
#define flow_hpp

#include "system.hpp"

using namespace std;

/** 
 * @brief Flow Class.
 * 
 * Responsible for applying some method under the value of the source system
 * so the target system can receive the returned value.
 */
class Flow{
    protected:
        string name; /*!< Flow name */
        System* source; /*!< Source system */
        System* target; /*!< Target System */
    
    public:
        /**
         * @brief Flow Default Constructor.
         * 
         * Following the Canonical Class Form 
         */
        Flow();

        /** 
         * @brief Flow Copy Constructor.
         * 
         * Following the Canonical Class Form 
         * @param copy make a copy of another flow
         */
        Flow(Flow &copy);

        /** 
         * @brief Flow Constructor parameters of string, System and System.
         * 
         * All of the attributes will receive its values frm the parameters
         * @param name name of the flow
         * @param source input system of the flow
         * @param target output system of the flow
         */
        Flow(string name, System* source, System* target);

        /** 
         * @brief Virtual Flow Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~Flow(){}

        /** 
         * @brief Flow Get Name Method.
         * 
         * Returns the flow's name
         * @return string
         */
        string getName() const;

        /** 
         * @brief Flow Get Source Method.
         * 
         * Returns the source system of the flow
         * @return System
         */
        System* getSource() const;

        /** 
         * @brief Flow Get Target Method.
         * 
         * Returns the target system of the flow
         * @return System
         */
        System* getTarget()const;

        /** 
         * @brief Flow Set Name Method.
         * 
         * Receive a string as a parameter and attributes it to flow's name
         * @param name name of the flow
         */
        void setName(string name);

        /**
         * @brief Flow Set Source System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's source
         * @param source input system of the flow
         */
        void setSource(System* source);

        /**
         * @brief Flow Set Target System Method.
         * 
         * Receive a System as a parameter and attributes it to flow's target
         * @param target output system of the flow
         */
        void setTarget(System* target);

        /** 
         * @brief Flow Conect Method.
         * 
         * Receive two Systems as parameters and attributes it to flow's source and flowś target
         * @param source input system of the flow
         * @param target output system of the flow
         */
        void conect(System *, System *);

        /** 
         * @brief Virtual Flow Execute Method.
         * 
         * This method will be implemented by class's children. It's responsible for 
         * return the value which the target system will receive considering the value that 
         * the source contains
         * @return double is going to be used to modify a value
         */
        virtual double execute() const = 0;

        /**
         * @brief Flow Assignment operator.
         * 
         * Following the Canonical Class Form 
         * @param flow
         * @return Flow& a copy of a flow
         */
        Flow& operator=(Flow &flow);
};

#endif