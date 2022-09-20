/**
 * @file model.hpp
 * @author Bernardo Biondini
 * @date May 11, 2022
 */

#ifndef model_hpp
#define model_hpp

#include <vector>
#include <iostream>

#include "impFlow.hpp"

/**
 * @brief Model Interface
 * 
 * Responsible for define the Model structure, its methods but not the implementation
 */
class Model{
    protected:
        /**
         * @brief Model Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a System or a Flow
         * @param System push a System into the System vector
         */
        virtual void add(System *system) = 0;

        /**
         * @brief Model Add Method.
         * 
         * This method uses Overloading concept, wether the parameter is a Flow or a System
         * @param System push a Flow into the Flow vector
         */
        virtual void add(Flow *flow) = 0;
    public:
        /**
         * @brief Virtual Model Destructor.
         * 
         * Following the Canonical Class Form
         */
        virtual ~Model(){}     

        /**
         * @brief Model Get Name Method.
         * 
         * Returns the model's name
         * @return string 
         */
        virtual string getName() const = 0;

        /**
         * @brief System Iterator Typedef
         * 
         * Responsible for define a type for the Iterator
         */
        typedef vector<System *>::iterator systemIterator;

        /**
         * @brief Flow Iterator Typedef
         * 
         * Responsible for define a type for the Iterator
         */
        typedef vector<Flow *>::iterator flowIterator;

        /**
         * @brief Get the Begin Systems
         * 
         * Returns the Beginning of System's vector
         * @return systemIterator 
         */
        virtual systemIterator getBeginSystems() = 0;

        /**
         * @brief Get the End Systems
         * 
         * Returns the Ending of System's vector
         * @return systemIterator 
         */
        virtual systemIterator getEndSystems() = 0; 

        /**
         * @brief Get the Begin Flows
         * 
         * Returns the Beginning of Flow's vector
         * @return flowIterator 
         */
        virtual flowIterator getBeginFlows() = 0;

        /**
         * @brief Get the End Flows
         * 
         * Returns the Ending of Flow's vector
         * @return flowIterator 
         */
        virtual flowIterator getEndFlows() = 0; 

        /** 
         * @brief Model Set Name Method.
         * 
         * Receive a string as a parameter and attributes it to model's name
         * @param name name of the model
         */
        virtual void setName(string name) = 0;

        /**
         * @brief Model Execute Method.
         * @warning Execute method is the main method of Model,responsible
         * for controlling the flow and the results of Model's dynamics
         * @param initial_time 
         * @param final_time 
         * @param incr how much the program will increment, simulates time
         */
        virtual void run(double initial_time, double final_time, int incr) = 0;

        virtual System* createSystem(string name, double value) = 0;

        static Model* createModel();

        template<typename typeFlow>
        Flow* createFlow(string name, System* source, System* target){
            Flow* flow = new typeFlow(name, source, target);
            this->add(flow);

            return flow;
        }
};

#endif